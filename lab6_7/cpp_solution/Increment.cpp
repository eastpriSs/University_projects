#include <iostream>

class Integer
{
private: int value;
public: 

    // Префиксный
    Integer& operator++()
    {
        this->value += 1;
        return *this;
    }

    // Постфиксный 
    Integer operator++(int)
    {
        Integer t(*this);
        this->value += 1;
        return t;
    }

    friend std::ostream& operator<<(std::ostream&, const Integer&);
};

std::ostream& operator<<(std::ostream& os, const Integer& rhs)
{
    os << rhs.value;
    return os;
}

int main()
{
    Integer x;
    std::cout << x++;   // output 0, x.value = 1
    std::cout << '\n';
    std::cout << ++x;   // output 2, x.value = 2
}