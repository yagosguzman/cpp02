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

Fixed::Fixed(const int i_value)
{
   std::cout << "Int constructor called" << std::endl;
   _value = i_value << _fracbits;
}

Fixed::Fixed(const float f_value)
{
   std::cout << "Float constructor called" << std::endl;
   _value = f_value;
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

float Fixed::toFloat(void) const
{

}

int Fixed::toInt(void) const
{
   return (_value >> _fracbits);
}