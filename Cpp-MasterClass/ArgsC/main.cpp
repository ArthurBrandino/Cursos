#include <stdarg.h>
#include <iostream>

template<typename T>
auto accumulate(T value){
    return value;
}

template<typename T, typename... Args>
auto accumulate(T first, Args... args){
    return first + accumulate(args...);
}

int main()
{
    auto r = accumulate(10, 10, 5);
    std::cout << "Result: " << r << std::endl;
    
    system("pause");
    return 0;
}