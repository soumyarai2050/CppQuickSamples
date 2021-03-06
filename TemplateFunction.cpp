#include <iostream>
#include <algorithm>

//Problem : Reverse a template type that is Iterable
//Solution
template <typename IterableType>
IterableType GenericReverse(IterableType obj)
{
    std::reverse(obj.begin(), obj.end());
    return obj;
}

//Test
template <typename ComparableType>
bool InternalValidate(ComparableType expectation, ComparableType input, const std::string &testTypeName)
{
    bool testStatus = true;
    if(expectation == GenericReverse(input))
    {
        std::cout << testTypeName << " Test - Pass\n";
        testStatus &= true;
    }
    else
    {
        std::cerr << testTypeName << " Test - Fail\n";
        testStatus &= false;
    }
    return testStatus;
}

bool Validate_GenericReverse()
{
    bool testStatus = true;
    //Sanity Test
    std::string name ("Sumit"), expected("timuS");
    std::array <const char*, 3> TestTypes =  {"Sanity", "Boundary", "Clear"};
    for (auto testType : TestTypes)
        testStatus &= InternalValidate(expected, name, testType);
    return testStatus;
}

int main()
{
    std::cout << "Validation Start\n" ;
    bool validationStatus = Validate_GenericReverse();
    std::cout << "\nOverall Validation status: " << (validationStatus?"Pass":"Fail");
    return 0;
}
