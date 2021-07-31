#include <iostream>
#include <string>
#include <tuple>
auto TestFunction()
{
    return std::make_tuple("F1", 5, "F2", 7);
}

int main()
{
    auto [string1, num1, string2, num2] = TestFunction();
    std::cout << "num1: " << num1 << " string1: " << string1 << " num2: " << num2 << " string2: " << string2 <<std::endl;
    //getchar();
    return 0;
}
