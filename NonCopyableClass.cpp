#include <iostream>
#include <algorithm>


class NonCopyable {
protected: // Non-user-instantiable (purpose is to inherit and make sub-class non-copiable
    NonCopyable() = default;
    ~NonCopyable() = default;
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;
};

class Person : public NonCopyable
{
public:
    Person(const int age, const std::string& name):age(age), name(name){}
    void Display () { std::cout << "Age: " << age << " Name: " << name << std::endl; }

protected:
    int age;
    std::string name;
};


int main()
{
    Person p1(39, "Sumit");
    p1.Display();
    Person p2(9, "Ayra");
    //p1 = p2; // use of deleted function compiler error
    p2.Display();
    return 0;
}

