#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

template <typename T>
void Print(const T& objs)
{
    std::cout  << std::endl;
    for(auto obj : objs)
        std::cout << obj << " ";
}

//@@@ Add integral type check
inline bool div_by_2(int val) { return val%2 == 0; }

int main()
{
    std::array <int, 10> nums = {1, 5,8,2,8,4,1,0,9,3};
    for(auto num : nums)
        std::cout << num << " ";
    //sort
    std::sort(nums.begin(), nums.end());
    Print(nums);
    //find
    if (nums.end() != std::find(nums.cbegin(), nums.cend(), 5))
        std::cout << "found\n";
    else
        std::cout << "Not found\n";
    //fill
    std::fill(nums.begin(),nums.end(),2);
    Print(nums);
    //accumulate, multiplies
    int sum = std::accumulate(nums.begin(), nums.end(),0);
    int product = std::accumulate(nums.begin(), nums.end(),1, std::multiplies());
    std::cout << "Sum: " << sum << " Product: " << product;

    //count
    auto count1 = std::count(nums.cbegin(), nums.cend(), 0);
    std::cout << " Count: " << count1;

    nums = {1, 5,8,2,8,4,1,0,9,3};

    //count_if
    auto count2 = std::count_if(nums.cbegin(), nums.cend(),div_by_2);
    std::cout << " Count: " << count2 << std::endl;
    //Lambda expression
    auto basic_print = [](const int& val){std::cout << " " << val;};
    //for_each
    std::for_each(nums.cbegin(), nums.cend(), basic_print);
    //partial_sum
    std::partial_sum(nums.cbegin(),nums.cend(),nums.begin());
    Print(nums);
    //all_of
    auto even = [](const int& val ){return val%2;};
    bool all_even = std::all_of(nums.begin(), nums.end(),even);
    std::cout << all_even;
    //rotate
    std::rotate(nums.begin(), nums.begin()+3, nums.end());
    Print (nums);
    //std::toupper , transform
    auto UpperCase = [] (char c){return std::toupper(c);};
    std::string name1 = "Sumit";
    std::string name2 = name1;
    std::transform(name1.begin(), name1.end(), name2.begin(), UpperCase);
    std::cout << "\n Name1: " << name1 << " Name2: " << name2 << std::endl;
    //std::max std::min
    int max = std::max(1,999);
    int min = std::min({1,999,54,77,-94});
    std::cout << "Max: " << max << " Min: " << min << std::endl;
    //min_element and minmax_element (return pointer to element(s) found)
    auto min_element = std::min_element(nums.begin(),nums.end());
    //min_location (gives distance from begin - counting form 0) to the pointer element passed
    auto min_location = std::distance(nums.begin(),min_element);
    std::cout << "Min Element: " << *min_element << " Min Location: " << min_location << std::endl;
    auto [min1, max1] = std::minmax_element(nums.begin(),nums.end());
    std::cout << "Max1: " << *max1 << " Min1: " << *min1 << std::endl;
    //std::clamp (value, min, max); : clips the value to be inside the min / max limit or unchanged if already in-between

    return 0;
}
