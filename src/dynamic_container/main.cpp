#include "dynamic_container.hpp"

#include <string>
#include <iostream>
class A
{
public:
    A(std::string config) : m_config(config) {}
    A() {}
    virtual ~A(){}
    std::string config() {return m_config;}
protected:
    std::string m_config;
};

class B : public A
{
public:
    B(std::string config)
    {
        A::m_config = config;
    }

    std::string encode()
    {
        return m_config + m_config;
    }
};

int main(void) {

    auto vec = dynamic_container::dynamic_container_vector<A>(2);
    A a("l");
    std::cout << a.config() << std::endl; 
    vec.at(0, a);

    std::cout << vec.size() << std::endl;
    auto a2 = vec[0];
    std::cout << a2->config() << std::endl;

    B b("t");
    std::cout << b.config() << std::endl; 
    vec.at<B>(1, b);
    std::cout << vec.size() << std::endl;
    auto b2 = vec.get_as<B>(1);
    std::cout << b2->config() << std::endl;
    //auto b3 = vec[1]<B>;
    return 0;
}
