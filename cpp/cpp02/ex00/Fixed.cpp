# include "Fixed.hpp"
# include <iostream>

Fixed::Fixed() : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

// sert a créer un obj a partir d'un autre
Fixed::Fixed(const Fixed &copy) {
    std::cout << "Copy constructor called" << std::endl;
    this->_rawBits = copy.getRawBits();
}

// sert a copier un obj dans un autre deja existant
Fixed &Fixed::operator=(const Fixed &op)
{
    // le if pour eviter des a = a peut poser des problemes
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &op)
        this->_rawBits = op.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}

void Fixed::setRawBits( int const raw ) {
    _rawBits = raw;
}

