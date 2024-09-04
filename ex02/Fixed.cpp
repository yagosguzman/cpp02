#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed(void) : _value(0)
{
   std::cout << "Default constructor called" << std::endl; 
}

Fixed::Fixed(const Fixed& copy)
{
   std::cout << "Copy constructor called" << std::endl;
   _value = copy.getRawBits();
}

Fixed::Fixed(const int i_value)
{
   std::cout << "Int constructor called" << std::endl;
   _value = (i_value << _fracbits);
}

Fixed::Fixed(const float f_value)
{
   std::cout << "Float constructor called" << std::endl;
   _value = roundf(f_value * (1 << _fracbits)); // Bitshifting to move the comma (same as multiplying by 2^8)
}

Fixed& Fixed::operator=(const Fixed& src)
{
   std::cout << "Copy assignment operator called" << std::endl;
   _value = src.getRawBits();
   return (*this);
}

bool Fixed::operator>(const Fixed& src) const
{
   return (this->_value > src._value);
}

bool Fixed::operator>=(const Fixed& src) const
{
   return (this->_value >= src._value);
}

bool Fixed::operator<(const Fixed& src) const
{
   return (this->_value < src._value);
}

bool Fixed::operator<=(const Fixed& src) const
{
   return (this->_value <= src._value);
}

bool Fixed::operator==(const Fixed& src) const
{
   return (this->_value == src._value);
}

bool Fixed::operator!=(const Fixed& src) const
{
   return (this->_value != src._value);
}

/*ARITHMETIC OPERATORS*/

Fixed Fixed::operator+(const Fixed& src) const
{
   return (Fixed(this->toFloat() + src.toFloat()));
}

Fixed Fixed::operator-(const Fixed& src) const
{
   return (Fixed(this->toFloat() - src.toFloat()));
}

Fixed Fixed::operator*(const Fixed& src) const
{
   return (Fixed(this->toFloat() * src.toFloat()));
}

Fixed Fixed::operator/(const Fixed& src) const
{
   if (src.getRawBits() == 0)
   {
      std::cout << "ERROR\n Division by zero" << std::endl;
      exit(EXIT_FAILURE);
   }
   return (Fixed(this->toFloat() / src.toFloat()));
}

/*INCREMENT/DECREMENT OPERATORS*/

Fixed& Fixed::operator++(void)
{
   ++this->_value;
   return (*this);
}

Fixed& Fixed::operator--(void)
{
   --this->_value;
   return (*this);
}

Fixed Fixed::operator++(int)
{
   Fixed result = *this;
   ++this->_value;
   return (result);
}

Fixed Fixed::operator--(int)
{
   Fixed result = *this;
   --this->_value;
   return (result);
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
   return (static_cast<float>(_value) / (1 << _fracbits));
}

int   Fixed::toInt(void) const
{
   return (_value >> _fracbits);
}

Fixed&   Fixed::min(Fixed& a, Fixed& b)
{
   if (a.getRawBits() < b.getRawBits())
      return (a);
   else
      return (b);
}

Fixed&   Fixed::max(Fixed& a, Fixed& b)
{
   if (a.getRawBits() > b.getRawBits())
      return (a);
   else
      return (b);
}

const Fixed&   Fixed::min(const Fixed& a, const Fixed& b)
{
   if (a.getRawBits() < b.getRawBits())
      return (a);
   else
      return (b);
}

const Fixed&	Fixed::max(const Fixed& a, const Fixed& b)
{
   if (a.getRawBits() > b.getRawBits())
      return (a);
   else
      return (b);
}

std::ostream& operator<<(std::ostream& out, const Fixed& src)
{
   out << src.toFloat();
   return (out);
}