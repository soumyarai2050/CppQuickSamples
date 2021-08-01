#include <iostream>
#include <string>
#include <tuple>
auto TestFunction()
{
    return std::make_tuple("F1", 5, "F2", 7);
}

int main()
{
    using Student = std::tuple <std::string, int, char>;
    Student s1 {"S1", 20, 'A'};
    Student s2 = std::make_tuple("S2", 22, 'B');
    //Structured Binding
    auto [string1, num1, string2, num2] = TestFunction();
    std::cout << "num1: " << num1 << " string1: " << string1 << " num2: " << num2 << " string2: " << string2 <<std::endl;
    auto [string3, num3, string4, num4] = std::make_tuple("F2", 7, "F8", 4);
    std::cout << "string3: " << string3 << " num3: " << num3 << " string4: " << string4 << " num4: " << num4 <<std::endl;
    //Error : initializer list does not work with structured binding
    //auto [string11, num13, num14] {"F2", 7, 9};
    //getchar();
    return 0;
}
