#include <iostream>
#include <algorithm>
#include <array>
template <typename T, typename U>
auto Add(T t, U u)
{
    return t+u;
};

int main()
{
    std::cout << Add(5,7.0f) << std::endl;
    std::cout << "Start\n" ;
    int i = 5;
    auto myLambda =  [&]()->float { return static_cast<float>(i++); } ;
    float f = myLambda();
    auto && arr = {1,2,3,4,5,6};
    static_assert(sizeof(arr));
    for(const auto i: arr)
    {
        std::cout << i*5 << std::endl;
    }
    std::cout << myLambda() << f << std::endl;
    return 0;
}
