#include <iostream>
#include <algorithm>

//Problem : Reverse a template type that supports begin and end
template <typename IterableType>
IterableType GenericReverse(IterableType obj)
{
    std::reverse(obj.begin(), obj.end());
    return obj;
}




bool Validate_GenericReverse()
{
    bool testStatus = true;
    //Sanity Test
    std::string name ("Sumit");
    if("timuS" == GenericReverse(name))
    {
        std::cout << "Sanity Test - Pass\n";
        testStatus &= true;
    }
    else
    {
        std::cerr << "Sanity Test - Fail\n";
        testStatus &= false;
    }

    //Clear Test
    name.clear();
    if("" == GenericReverse(name))
    {
        std::cout << "Clear Test - Pass\n";
        testStatus &= true;
    }
    else
    {
        std::cout << "Clear Test - Fail\n";
        testStatus &= false;
    }
    return testStatus;
}

int main()
{
    std::cout << "Validation Start\n" ;
    bool validationStatus = Validate_GenericReverse();
    std::cout << "Overall Validation status: " << (validationStatus?"Pass":"Fail");
    return 0;
}
