#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
   std::cout << "Default constructor called" << std::endl; 
}

Fixed::Fixed(const Fixed& copy)
{
   std::cout << "Copy constructor called" << std::endl;
   *this = copy;
   std::cout << "Copy assignment operator called" << std::endl;
}

Fixed& Fixed::operator = (const Fixed& src)
{
   if (this != &src)
      this->_value = src.getRawBits();
   std::cout << "Copy assignment operator called" << std::endl;
   return (*this);
}

Fixed::~Fixed(void)
{
   std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
   return this->_value;
}

void Fixed::setRawBits(int const raw)
{
   this->_value = raw;
}