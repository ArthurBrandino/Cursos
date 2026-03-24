#include <iostream>
#include <array>
#include <expected>

template <typename T, size_t Size>
class Array
{
    public:
        using value_type = T;
        using size_type = size_t;
        using reference = T&;
        using const_reference = const T&;
        using pointer = T*;
        Array() = default;

        template<typename ... Values>
        constexpr Array(Values ... values){
            const std::array<T, sizeof...(Values)> temp ={values...};
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

    private:
        T m_elements[Size]{};
};

template <typename T>
constexpr std::expected<typename T::value_type, std::string> max_element(const T &arr) noexcept {
    if(arr.empty()) return std::unexpected("Array is empty");

    auto graterElement = arr[0];

    for (size_t i = 1; i < arr.size(); i++)
    {
        if(arr[i] > graterElement) graterElement = arr[i];
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