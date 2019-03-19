#include <memory>
#include <vector>
//#include <cstdint>

#include <stdexcept>
#include <string>
	

namespace dynamic_container
{
template<typename BaseType>
class dynamic_container_vector
{
public:
    dynamic_container_vector(size_t size) : m_internal(size)
    {
        
    }

    dynamic_container_vector() {}

    size_t size()
    {
        return m_internal.size();
    }

    void push_back(BaseType elm)
    {
        m_internal.push_back(elm);
    }

    template<typename DerivedType>
    void push_back(DerivedType elm)
    {
        m_internal.push_back((BaseType)elm);
    }
    
    BaseType& at(uint32_t i)
    {
        if (i >= m_internal.size())
        {
            throw std::out_of_range("i: " + std::to_string(i) + " is out of range");
        }
        return  m_internal.at(i); 
    }

    BaseType& operator[](uint32_t i)
    {
        return at(i); 
    }

    template<typename DerivedType>
    DerivedType& get_as(uint32_t i)
    {
        auto a = m_internal.at(i);
        return dynamic_cast<DerivedType&>(a); 
    }
    
    // template<typename DerivedType>
    // DerivedType& at(uint32_t i)
    // {
    //     if (i >= m_internal.size())
    //     {
    //         throw std::out_of_range("i: " + std::to_string(i) + " is out of range");
    //     }
    //     return static_cast<DerivedType>(*(m_internal.at(i))); // static_cast<DerivedType*>(m_internal.at(i).release());
    // }

    // template<typename DerivedType>
    // DerivedType* operator[](uint32_t i)
    // {
    //     return at<DerivedType>(i);
    // }

    

    
        
private:
    std::vector<BaseType> m_internal; 
    
};
}
