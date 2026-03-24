#include <stdarg.h>
#include <iostream>

template<typename... Args>
auto accumulate(Args... args){
    return (args + ...);
}

int main()
{
    auto r = accumulate(10, 10, 5);
    std::cout << "Result: " << r << std::endl;
    
    system("pause");
    return 0;
}