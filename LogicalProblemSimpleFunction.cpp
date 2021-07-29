#include <iostream>

//Problem : Reverse a string
std::string ReverseString(const std::string &name)
{

    return std::reverse(name);
}


bool Validate_ReverseString()
{
    bool testStatus = false;
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
    std::cout << "Test Start\n" ;
    bool testResult = Validate_ReverseString();
    std::cout << "Overall Test status: " << (testResult?"Pass":"Fail");
    return 0;
}
