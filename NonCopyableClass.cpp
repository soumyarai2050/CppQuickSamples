#include <iostream>
#include <algorithm>

class NonCopyable {
protected: // Non-instantiable, inherit to make sub-class non-copiable
    NonCopyable() = default;
    ~NonCopyable() = default;
public:
    //explicit copy operation inhibits implicit move methods
    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator=(const NonCopyable&) = delete;
};

class Person : public NonCopyable
{
public:
    Person(const int age, std::string&& name):age(age), name(std::move(name)){}
    friend std::ostream& operator<< (std::ostream &os, const Person& p)
    {
        os << "Age: " << p.age << " Name: " << p.name << std::endl;
        return os;
    }

protected:
    int age;
    std::string name;
};

int main()
{
    Person p1(39, "Sumit");
    std::cout << p1;
    Person p2(9, "Ayra");
    //p1 = p2; // use of deleted function compiler error
    std::cout << p2;
    return 0;
}

