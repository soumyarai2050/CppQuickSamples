#include <iostream>
#include <algorithm>

//Problem : Reverse a string
std::string ReverseString(std::string &name)
{
    std::reverse(name.begin(),name.end());
    return name;
}


bool Validate_ReverseString()
{
    bool testStatus = true;
    //Sanity Test
    std::string name ("Sumit");
    if("timuS" == ReverseString(name))
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
    if("" == ReverseString(name))
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
    bool validationStatus = Validate_ReverseString();
    std::cout << "Overall Validation status: " << (validationStatus?"Pass":"Fail");
    return 0;
}
