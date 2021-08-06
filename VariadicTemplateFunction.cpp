
#include<iostream>

//template <typename U>
//U Add(U u)
//{
//    return u;
//};

auto Add()
{
    return 0;
};


template <typename U, typename... T>
U Add(U u, T... t)
{
    return Add(t...);
};
int main()
{
    std::cout << Add(4,5,6,7,8,9);
    return 0;
}