#include <array>
#include <expected>
#include <cstdint>

using namespace std;

constexpr uint64_t factorial(int num) noexcept{
    uint64_t result = 1;
    for(int i = num; i > 1; i--)
        result *= i;
        return result;
}

int main(){
    return factorial(5);
}