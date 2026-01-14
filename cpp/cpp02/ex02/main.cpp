# include "Fixed.hpp"
#include <iostream>

int main( void ) {
    // sujet
    std::cout << "=== Tests du sujet ===" << std::endl;
    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max( a, b ) << std::endl;

    // additionnels
    std::cout << std::endl;
    std::cout << "Comparaison :" << std::endl;
    Fixed x(10);
    Fixed y(20);
    std::cout << "x = " << x << ", y = " << y << std::endl;
    std::cout << "x > y: " << (x > y) << std::endl;
    std::cout << "x < y: " << (x < y) << std::endl;
    std::cout << "x >= y: " << (x >= y) << std::endl;
    std::cout << "x <= y: " << (x <= y) << std::endl;
    std::cout << "x == y: " << (x == y) << std::endl;
    std::cout << "x != y: " << (x != y) << std::endl;

    std::cout << std::endl;
    std::cout << "op arithmetiques :" << std::endl;
    Fixed c(10.5f);
    Fixed d(2.5f);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "c + d = " << (c + d) << std::endl;
    std::cout << "c - d = " << (c - d) << std::endl;
    std::cout << "c * d = " << (c * d) << std::endl;
    std::cout << "c / d = " << (c / d) << std::endl;

    std::cout << std::endl;
    std::cout << "decrementations :" << std::endl;
    Fixed e(5);
    std::cout << "e = " << e << std::endl;
    std::cout << "--e = " << --e << std::endl;
    std::cout << "e = " << e << std::endl;
    std::cout << "e-- = " << e-- << std::endl;
    std::cout << "e = " << e << std::endl;

    std::cout << std::endl;
    std::cout << "min/max :" << std::endl;
    Fixed f(42.42f);
    Fixed g(21.21f);
    std::cout << "f = " << f << ", g = " << g << std::endl;
    std::cout << "Fixed::min(f, g) = " << Fixed::min(f, g) << std::endl;
    std::cout << "Fixed::max(f, g) = " << Fixed::max(f, g) << std::endl;

    return 0;
}