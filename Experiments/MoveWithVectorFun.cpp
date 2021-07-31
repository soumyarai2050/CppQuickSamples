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
    //Person p1("Sumit");
    std::vector<Person> v1;
    //avoids jitter in performance on vector resizes (disable the line and notice the calls more than double)
    v1.reserve(7);
    //Only one move constructor with const char * as input
    v1.emplace_back("T1");
    v1.emplace_back("T2");
    v1.emplace_back("T3");
    v1.emplace_back("T4");
    v1.emplace_back("T5");
    v1.emplace_back("T6");
    std::cout << (std::find(v1.begin(), v1.end(), "T5")!=v1.end()?"Found":"NotFount");
    //Inefficient : 2 two constructors per push back
//    v1.push_back("T1");
//    v1.push_back("T2");
//    v1.push_back("T3");
//    v1.push_back("T4");

    std::vector<Person> v2;
    v2.reserve(3);
    v2.emplace_back("F1");
    v2.emplace_back("F2");
    std::cout << "Moving V2 to V1: \n";
    //No assignment
    v1 = std::move(v2);
    //v1 = v2; // assignment per field
    for(const Person &p : v1)
        std::cout << "Name: " << p.GetName() << std::endl; // No copy or assignment NRVO
    getchar();
    return 0;
}
