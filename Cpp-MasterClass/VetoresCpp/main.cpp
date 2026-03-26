#include <iostream>
#include <array>
#include <expected>
#include <vector>


template <typename T, size_t Size>
class ArrayConstIterator {
public:
    using iterator_category = std::contiguous_iterator_tag;
    using value_type = T;
    using difference_type = std::ptrdiff_t;
    using pointer = const T*;
    using const_reference = const T&;
    using reference = T&;

    constexpr ArrayConstIterator() noexcept = default;

    constexpr explicit ArrayConstIterator(pointer ptr, size_t offset = 0) noexcept : m_ptr(ptr), m_offset(offset){

    }

    [[nodiscard]]constexpr const_reference operator*() const noexcept {
        return m_ptr[m_offset];
    }

    constexpr ArrayConstIterator& operator++() noexcept {
        ++m_offset;
        return *this;
    }

    constexpr ArrayConstIterator operator++(int) noexcept {
        ArrayConstIterator temp = *this;
        ++(*this);
        return temp;
    }

    constexpr ArrayConstIterator& operator+=(difference_type offset) noexcept {
        m_offset += offset;
        return *this;
    }

    [[nodiscard]]constexpr auto operator<=>(const ArrayConstIterator &other) const noexcept {
        return m_offset <=> other.m_offset;
    }

    [[nodiscard]]constexpr bool operator==(const ArrayConstIterator &other) const noexcept {
        return *this <=> other == 0;
    }

    constexpr ArrayConstIterator& operator--() noexcept{
        --m_offset;
        return *this;
    }

    constexpr ArrayConstIterator operator--(int) noexcept{
        ArrayConstIterator temp = *this;
        --(*this);
        return temp;
    }

    constexpr ArrayConstIterator& operator-=(difference_type offset) noexcept{
        m_offset -= offset;
        return *this;
    }

    [[nodiscard]] constexpr pointer operator->() const noexcept{
        return m_ptr + m_offset;
    }

    [[nodiscard]] constexpr bool operator!=(const ArrayConstIterator &other) const noexcept{
        return !(*this == other);
    }

    [[nodiscard]] constexpr ArrayConstIterator operator+(difference_type offset) const noexcept{
        auto temp = *this;
        temp += offset;
        return temp;
    }

    [[nodiscard]] constexpr ArrayConstIterator& operator-() noexcept{
        --m_offset;
        return *this;
    }

    [[nodiscard]] constexpr ArrayConstIterator operator-(difference_type offset) const noexcept{
        auto temp = *this;
        temp -= offset;
        return temp;
    }
    [[nodiscard]] constexpr difference_type operator-(const ArrayConstIterator& other) const noexcept{
        return m_offset - other.m_offset;
    }

protected:
    pointer m_ptr {nullptr};
    size_t m_offset {0};
};

template <typename T, size_t Size>
class Array
{
    public:
        using value_type = T;
        using size_type = size_t;
        using reference = T&;
        using const_reference = const T&;
        using pointer = T*;
        using const_iterator = ArrayConstIterator<T, Size>;
        using iterator = ArrayConstIterator<T, Size>;
        Array() = default;

        template<typename ... Values>
        constexpr Array(Values ... values){
            static_assert(sizeof...(Values) <= Size, "Too many initializers");
            static_assert((std::is_convertible_v<Values, T>&&...), "All values must be T");
            const std::array<T, sizeof...(Values)> temp ={ static_cast<float>(values)...};
            std::copy(temp.begin(), temp.end(), m_elements);
        }

        [[nodiscard]] constexpr size_type size() const noexcept{
            return Size;
        }

        constexpr bool empty() const noexcept{
            return Size == 0;
        }

        [[nodiscard]] constexpr reference operator[](size_type pos) noexcept{
            return m_elements[pos];
        }

        [[nodiscard]] constexpr const_reference operator[](size_type pos) const noexcept{
            return m_elements[pos];
        }

        const_iterator begin() const noexcept{
            return const_iterator(m_elements);
        }

        const_iterator end() const noexcept{
            return const_iterator(m_elements, Size);
        }

        iterator begin()  noexcept{
            return iterator(m_elements);
        }

        iterator end()  noexcept{
            return iterator(m_elements, Size);
        }
        
    private:
        T m_elements[Size]{};
};

template <typename T, size_t Size>
class ArrayIterator : public ArrayConstIterator<T, Size> {
public:
    using MtBase = ArrayConstIterator<T, Size>;
    using typename MyBase::iterator_category;
    using typename MyBase::value_type;
    using typename MyBase::difference_type;
    using typename MyBase::pointer;
    using typename MyBase::const_reference;
    using typename MyBase::reference;

    constexpr ArrayIterator() noexcept = default;

    constexpr explicit ArrayIterator(pointer ptr, size_t offset) noexcept : MyBase(ptr, offset) {

    }

    [[nodiscard]] constexpr reference operator*() const noexcept {
        return const_cast<reference>(MyBase::operator*());
    }

    constexpr ArrayIterator& operator++() noexcept{
        MyBase::operator++();
        return *this;
    }

    constexpr ArrayIterator operator++(int) noexcept{
        auto temp = *this;
        MyBase::operator++();
        return temp;
    }

    constexpr ArrayIterator& operator+=(difference_type offset) noexcept {
        MyBase::operator+=(offset);
        return *this;
    }

    [[nodiscard]] constexpr auto operator<=>(const ArrayIterator& other) const noexcept {
        return MyBase::operator<=>(other);
    }

    [[nodiscard]] constexpr bool operator==(const ArrayIterator& other) const noexcept {
        return MyBase::operator==(other);
    }

    constexpr ArrayIterator&  operator--() noexcept{
         MyBase::operator--();
        return *this;
    }

    constexpr ArrayIterator operator--(int) noexcept{
        auto temp = *this;
        MyBase::operator--();
        return *this;
    }

    constexpr ArrayIterator& operator-=(difference_type offset) noexcept{
        MyBase::operator-=(offset);
        return *this;
    }

    [[nodiscard]] constexpr pointer operator->() const noexcept{
        return const_cast<pointer>(MyBase::operator->());
    }

    [[nodiscard]] constexpr bool operator!=(const ArrayIterator &other) const noexcept{
        return MyBase::operator!=(other);
    }

    [[nodiscard]] constexpr ArrayIterator operator+(difference_type offset) const noexcept{
        euto tem = *this;
        temp += offset;
        return temp;
    }

    [[nodiscard]] constexpr ArrayIterator& operator-() noexcept{
        MyBase::operator--();
        return *this;
    }

    [[nodiscard]] constexpr ArrayIterator operator-(difference_type offset) const noexcept{
        auto temp = *this;
        temp -= offset;
        return temp
    }

    [[nodiscard]] constexpr difference_type operator-(const ArrayIterator& other) const noexcept{
        return MyBase::operator-(other);
    }
};


template <typename T>
constexpr std::expected<typename T::value_type, std::string> max_element(const T &arr) noexcept {
    if(arr.empty()) return std::unexpected("Array is empty");

    auto graterElement = *(arr.begin());

    for (auto it = std::next(arr.begin()); it != arr.end(); ++it)
    {
        if(*it > graterElement) graterElement = *it;
    }
    return graterElement;
}

int main(){
    Array<float, 5> ages;

    ages[0] = 12;
    ages[1] = 19;
    ages[2] = 17;
    ages[3] = 95;
    ages[4] = 52;
    if(const auto res = max_element(ages); res)
        std::cout << "Maior: " << res.value() << std::endl;
    else
        std::cout << "Error: " << res.error() << std::endl;

    

    system("pause");
    return 0;
}