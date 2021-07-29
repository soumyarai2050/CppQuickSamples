#include <iostream>
#include <algorithm>

//Problem : Reverse a template type that supports begin and end
template <typename IterableType>
IterableType GenericReverse(IterableType obj)
{
    std::reverse(obj.begin(), obj.end());
    return obj;
}

template <typename ComparabaleType>
bool InternalValidate(ComparabaleType expectation,  ComparabaleType input, const std::string &testTypeName)
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
    testStatus &= InternalValidate(expected, name, "Sanity");
    //Boundry Test
    name = "a", expected = "a";
    testStatus &= InternalValidate(expected, name, "Boundry");
    //Clear Test
    name.clear(), expected = "";
    testStatus &= InternalValidate(expected, name, "Clear");
    return testStatus;
}

int main()
{
    std::cout << "Validation Start\n" ;
    bool validationStatus = Validate_GenericReverse();
    std::cout << "Overall Validation status: " << (validationStatus?"Pass":"Fail");
    return 0;
}