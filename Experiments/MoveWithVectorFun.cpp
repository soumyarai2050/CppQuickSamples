#include <vector>
#include <iostream>
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


            Person(const char*&& name_)noexcept : name(std::move(name_))
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

        private:
            std::string name;

        };

int main()
{
    //Person p1("Sumit");
    std::vector<Person> v1;
    //v1.reserve(5);//Remove this and see the fun
    v1.push_back(std::move("T1"));
    v1.push_back(std::move("T2"));
    v1.push_back(std::move("T3"));
    v1.push_back(std::move("T4"));

    //std::vector<Person> v1{"Sumit", "Ayra"}, v2{"Amit", "Ishika"};
    //std::cout << "Moving V2 to V1: \n";
    //v1 = std::move(v2);
    //v1 = v2;
    getchar();
    return 0;
}
