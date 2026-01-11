# include "Fixed.hpp"
# include <iostream>
#include <cmath>

Fixed::Fixed() : _rawBits(0) {
}

// sert a créer un obj a partir d'un autre
Fixed::Fixed(const Fixed &copy) {
    *this = copy;
}

// sert a copier un obj dans un autre deja existant
Fixed &Fixed::operator=(const Fixed &op)
{
    // le if pour eviter des a = a peut poser des problemes
    if (this != &op)
        this->_rawBits = op._rawBits;
    return *this;
}

Fixed::Fixed(const int value) {
    _rawBits = value << _fractionalBits;
}

// roundf arrondis au chiffre le plus proche
Fixed::Fixed(const float value) {
    _rawBits = roundf(value * (1 << _fractionalBits));
}

Fixed::~Fixed() {
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

bool Fixed::operator>(const Fixed &x) const {
    return this->_rawBits > x._rawBits;
}

bool Fixed::operator<(const Fixed &x) const {
    return this->_rawBits < x._rawBits;
}

bool Fixed::operator>=(const Fixed &x) const {
    return this->_rawBits >= x._rawBits;
}

bool Fixed::operator<=(const Fixed &x) const {
    return this->_rawBits <= x._rawBits;
}

bool Fixed::operator==(const Fixed &x) const {
    return this->_rawBits == x._rawBits;
}

bool Fixed::operator!=(const Fixed &x) const {
    return this->_rawBits != x._rawBits;
}

Fixed Fixed::operator+(const Fixed &x) const {
    Fixed res;
    res.setRawBits(this->_rawBits + x._rawBits);
    return res;
}

Fixed Fixed::operator-(const Fixed &x) const {
    Fixed res;
    res.setRawBits(this->_rawBits - x._rawBits);
    return res;
}

// le >> est la car this et x sont tous les deux *256
// donc y'a un *256 de trop qu'on enleve
Fixed Fixed::operator*(const Fixed &x) const {
    Fixed res;
    // long pour eviter overflow
    long tmp = (long)this->_rawBits * (long)x._rawBits;
    res.setRawBits(tmp >> _fractionalBits);
    return res;
}

// << pour ajouter un *256
Fixed Fixed::operator/(const Fixed &x) const {
    Fixed res;
    if (x._rawBits == 0) {
        std::cerr << "Error: division by zero" << std::endl;
        res.setRawBits(0);
    } else {
        res.setRawBits((this->_rawBits << _fractionalBits) / x._rawBits);
    }
    return res;
}

// ++a
Fixed &Fixed::operator++() {
    _rawBits += 1;
    return *this;
}

// a++ int sert a dif le a++ et ++a
Fixed Fixed::operator++(int) {
    Fixed res(*this);
    _rawBits += 1;
    return res;
}

// --a
Fixed &Fixed::operator--() {
    _rawBits -= 1;
    return *this;
}

// a--
Fixed Fixed::operator--(int) {
    Fixed res(*this);
    _rawBits -= 1;
    return res;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a < b)
        return a;
    return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a > b)
        return a;
    return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    return b;
}