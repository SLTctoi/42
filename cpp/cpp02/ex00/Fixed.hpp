#ifndef FIXED_HPP
# define FIXED_HPP

# include <string>

class Fixed {
    private:
        int              _rawBits;
        static const int _fractionalBits = 8;
    
    public:
        Fixed();
        Fixed(const Fixed &copy);
        Fixed &operator=(const Fixed &other);
        ~Fixed();

        int getRawBits(void) const;
        void setRawBits( int const raw );

};

#endif