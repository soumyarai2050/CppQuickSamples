#include <iostream>
#include <sstream>
#include <string>

class Person
        {
        public:
            Person(const Person& person_): name(person_.name)
            {
                std::cout << "Copy Create Person: " << this << " from: " << &person_ <<  " " << name << std::endl;
            }

            Person(Person&& person_)noexcept : name(std::move(person_.name))
            {
                std::cout << "Move Create Person: " << this << " from: " << &person_ <<  " " << name << std::endl;
            }


            explicit Person(const char*&& name_)noexcept : name(name_)
            {
                std::cout << "Move Init Person: " << this << " from: " << &name_ <<  " " << name << std::endl;
            }

            ~Person()
            {
                std::cout << "Destroy Person: " << this << " " << name << std::endl;
            }

            Person& operator= (Person&& person_)noexcept
            {
                if(this != &person_)
                {
                    name = std::move(person_.name);
                    std::cout << "Move Person: " << this << " from: " << &person_ << " " << name << std::endl;
                }
                return *this;
            }

            Person& operator= (const Person& person_)
            {
                if(this != &person_)
                {
                    name = person_.name;
                    std::cout << "Assign Person: " << this << " from: " << &person_ << " " << name << std::endl;
                }
                return *this;
            }

            const std::string GetName() const
            {
                return name;
            }
        private:
            std::string name;

        };

int main()
{
    std::stringstream str{"000223.txt"};
    int num1 = 0;
    std::string string1;
    str >> num1 >> string1;
    std::cout << "num1: " << num1 << " string1: " << string1 << std::endl;
    getchar();
    return 0;
}
