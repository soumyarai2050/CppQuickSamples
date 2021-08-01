#include <iostream>
#include <variant>
#include<any>
#include<optional>

template <typename T>
void Print(const T& objs)
{
    std::cout  << std::endl;
    for(auto obj : objs)
        std::cout << obj << " ";
}

std::optional<std::string> Name(bool val)
{
    if (val)
        return "Sumit";
    else
        return {};
}

int main()
{
    //swap
    int a = 5, b = 6;
    std::swap(a,b);
    std::cout << "a: " << a << " b: " << b << std::endl;
    //variant , std::get
    std::variant<int, float> v1 = 5; //typesafe union (exception type: "const std::bad_variant_access& ex" thrown in error)
    std::cout << std::get<int>(v1) << " " << std::get<0>(v1) << std::endl;
    v1 = 3.14f;
    std::cout << std::get<float>(v1) << " " << std::get<1>(v1) << std::endl;
    //std::any , std::boolalpha (I/O manipulator) (or noboolalpha)
    std::any anyTypeVal = 3.14;
    std::cout << std::any_cast<double>(anyTypeVal) << std::endl;
    anyTypeVal = true;
    std::cout << std::boolalpha << std::any_cast<bool>(anyTypeVal) << std::endl;
    //std::optional
    std::cout << Name(true).value() << Name(false).value_or(" nOnE") << std::endl;

    return 0;
}
