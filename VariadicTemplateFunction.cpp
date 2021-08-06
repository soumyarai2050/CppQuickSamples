
#include<iostream>

//template <typename T>
//T Add(T t)
//{
//    return t;
//};

//auto Add()
//{
//    return 0;
//};

template <typename U, typename T>
auto Add(U u, T t)
{
    //std::cout << "is_floating_point_v<U>: " << std::boolalpha << std::is_floating_point_v<U> << " is_integral_v<U>: " << std::boolalpha << std::is_integral_v<U> << std::endl;
    static_assert(std::is_floating_point_v<U> || std::is_integral_v<U>, "Only integral and floating types supported");
    //std::cout << "is_floating_point_v<T>: " << std::boolalpha << std::is_floating_point_v<T> << " is_integral_v<T>: " << std::boolalpha << std::is_integral_v<T> << std::endl;
    static_assert(std::is_floating_point_v<T> || std::is_integral_v<T>, "Only integral and floating types supported");
    return (u + t);
}

template <typename U, typename... T>
auto Add(U u, T... t)
{
    //std::cout << "sizeof...(T): " << sizeof...(T) << std::endl;
    //std::cout << "is_floating_point_v<U>: " << std::boolalpha << std::is_floating_point_v<U> << " is_integral_v<U>: " << std::boolalpha << std::is_integral_v<U> << std::endl;
    static_assert(std::is_floating_point_v<U> || std::is_integral_v<U>, "Only integral and floating types supported");
    static_assert(sizeof...(T) >1, "Minimum 2 parameters required to add numbers");
    return (u + Add(t...));
}

int main()
{
    std::cout << Add(2,5.6,6,7.3,8,9) << std::endl; //graceful return type with auto
    std::cout << Add(4,'c') << std::endl; //graceful return type with auto
    return 0;
}
