
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
    return (u + t);
};

template <typename U, typename... T>
auto Add(U u, T... t)
{
    //std::cout << "sizeof...(T): " << sizeof...(T) << std::endl;
    static_assert(sizeof...(T) >1, "Minimum 2 parameters required to add numbers");
    return (u + Add(t...));
};
int main()
{
    std::cout << Add(4,5.6,6,7.3,8,9); //graceful return type with auto
    return 0;
}