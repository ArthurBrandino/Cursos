#include <iostream>

using namespace std;

template <typename T>
T maximum(T a, T b){
    return a > b ? a : b;
}


int main()
{
    float x = 11, y = 10;
    float r = maximum(x, y);
    cout << "Max: " << r << endl;

    system("pause");
    return 0;
}