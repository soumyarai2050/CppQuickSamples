#include <map>
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
    std::map<std::string, Person> m1;
    //@@@ how to avoids jitter in performance on map rerebals ?

    //Only one move constructor with const char * as input
//    m1.emplace("T1", "Name1");
//    m1.emplace("T2", "Name2");
//    m1.emplace("T3", "Name3");
//    m1.emplace("T4", "Name4");
//    m1.emplace("T5", "Name5");
//    m1.emplace("T6", "Name6");
    //Inefficient : Likely 2 two constructors per insert
    m1.insert(std::make_pair("T1", "Name1"));
    m1.insert(std::make_pair("T2", "Name2"));
    m1.insert(std::make_pair("T3", "Name3"));
    m1.insert(std::make_pair("T4", "Name4"));
    m1.insert(std::make_pair("T5", "Name5"));
    m1.insert(std::make_pair("T6", "Name6"));

//    std::vector<Person> v2;
//    v2.reserve(3);
//    v2.emplace_back("F1");
//    v2.emplace_back("F2");
//    std::cout << "Moving V2 to V1: \n";
//    //No assignment
//    v1 = std::move(v2);
//    //v1 = v2; // assignment per field
    for(const auto & [key, value] : m1)
        std::cout << "Key: " << key << " Value-Name: " << value.GetName() << std::endl; // No copy or assignment NRVO
    getchar();
    return 0;
}
