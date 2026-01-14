# include "Fixed.hpp"
# include <iostream>
#include <cmath>

Fixed::Fixed() : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

// sert a créer un obj a partir d'un autre
Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

// sert a copier un obj dans un autre deja existant
Fixed &Fixed::operator=(const Fixed &op)
{
    // le if pour eviter des a = a peut poser des problemes
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &op)
        this->_rawBits = op._rawBits;
    return *this;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called" << std::endl;
    _rawBits = value << _fractionalBits;
}

// roundf arrondis au chiffre le plus proche
Fixed::Fixed(const float value) {
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(value * (1 << _fractionalBits));
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    return _rawBits;
}

void Fixed::setRawBits( int const raw ) {
    _rawBits = raw;
}

float Fixed::toFloat(void) const {
    return (float)_rawBits / (1 << _fractionalBits);
}

int Fixed::toInt(void) const {
    return _rawBits >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &out, const Fixed &value) {
    out << value.toFloat();
    return out;
}