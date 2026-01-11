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

        Fixed(const int value);
        Fixed(const float value);

        int getRawBits(void) const;
        void setRawBits( int const raw );

        float toFloat(void) const;
        int toInt(void) const;

        bool operator>(const Fixed &x) const;
        bool operator<(const Fixed &x) const;
        bool operator>=(const Fixed &x) const;
        bool operator<=(const Fixed &x) const;
        bool operator==(const Fixed &x) const;
        bool operator!=(const Fixed &x) const;

        Fixed operator+(const Fixed &x) const;
        Fixed operator-(const Fixed &x) const;
        Fixed operator*(const Fixed &x) const;
        Fixed operator/(const Fixed &x) const;

        Fixed &operator++();
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);

        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &out, const Fixed &value);

#endif