#include <iostream>
#include <vector>
#include <algorithm>

class DefaultMethodsClass
{
public:
    //Default Constructor
    DefaultMethodsClass():intVar(5),intVector{3,4}
    {
        std::cout << "DefaultMethodsClass Constructor\n";
    }

    //Copy Constructor
    DefaultMethodsClass(const DefaultMethodsClass &obj):intVar(obj.intVar),intVector(obj.intVector)
    {
        std::cout << "DefaultMethodsClass Copy Constructor\n";
    }

    //Move Constructor
    DefaultMethodsClass(DefaultMethodsClass &&obj):intVar{exchange (obj.intVar, 0)},intVector(std::move(obj.intVector))
    {
        std::cout << "DefaultMethodsClass Copy Constructor\n";
    }

    //Assignment Operator
    //Copy Assignment Operator
    //Move Assignment Operator 
    //Destructor
private:
    int intVar;
    std::vector<int> intVector;

};

int main()
{
    DefaultMethodsClass obj1;
    DefaultMethodsClass obj2(obj1);
    return 0;
}