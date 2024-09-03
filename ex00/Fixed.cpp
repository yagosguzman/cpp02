#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{
   std::cout << "Default constructor called" << std::endl; 
}

Fixed::Fixed(const Fixed& copy)
{
   std::cout << "Copy constructor called" << std::endl;
   _value = copy.getRawBits();
}

Fixed& Fixed::operator = (const Fixed& src)
{
   std::cout << "Copy assignment operator called" << std::endl;
   _value = src.getRawBits();
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