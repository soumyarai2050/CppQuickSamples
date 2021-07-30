#include <iostream>
#include <vector>
#include <algorithm>

class DefaultMethodsClass
{
public:
    //Default Constructor
    DefaultMethodsClass():intVar(5),intVector{3,4}
    {
        std::cout << "DefaultMethodsClass Default Constructor\n";
        Display();
    }

    //Copy Constructor
    DefaultMethodsClass(const DefaultMethodsClass &obj):intVar(obj.intVar),intVector(obj.intVector)
    {
        std::cout << "DefaultMethodsClass Copy Constructor\n";
        Display();
        obj.Display();
    }

    //Move Constructor
    DefaultMethodsClass(DefaultMethodsClass&& obj):intVar{std::exchange(obj.intVar, 0)},intVector(std::move(obj.intVector))
    {
        std::cout << "DefaultMethodsClass Move Constructor\n";
        Display();
        obj.Display();
    }

    //Copy Assignment Operator
    DefaultMethodsClass& operator=(const DefaultMethodsClass& obj)
    {
        intVar = obj.intVar;
        intVector = obj.intVector;
        std::cout << "DefaultMethodsClass Copy Assignment Operator\n";
        Display();
        obj.Display();
        return *this;
    }

    //Move Assignment Operator
    DefaultMethodsClass& operator=(DefaultMethodsClass&& obj)
    {
        intVar = std::exchange(obj.intVar,0);
        intVector = std::move(obj.intVector);
        std::cout << "DefaultMethodsClass Move Assignment Operator\n";
        Display();
        obj.Display();
        return *this;
    }

    //Destructor
    virtual ~DefaultMethodsClass()
    {
        std::cout << "DefaultMethodsClass Destructor\n";
        intVector.clear();
        Display();
    }
private:
    void Display() const
    {
        std::cout << "intVar: " << intVar << " intVector: ";
        for (cItrIntVector cItr = intVector.begin(); cItr != intVector.end(); cItr++)
            std::cout << *cItr << " ";
        std::cout << std::endl;
    }
    int intVar;
    std::vector<int> intVector;
    using cItrIntVector = std::vector<int>::const_iterator;

};

int main()
{
    DefaultMethodsClass obj1;
    DefaultMethodsClass obj2(obj1);
    obj1 = obj2;
    DefaultMethodsClass obj3 = std::move(obj1);
    obj1 = std::move(obj2);

    return 0;
}