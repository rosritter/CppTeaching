#include "imNumbers.hpp"

bool ImNumber::operator=(const ImNumber& num)const{
    return fabs(real - num.real) < EPS && fabs(im - num.im) < EPS;
}


class Complex
{
private:
    double real;
    double imaginary;

public:
    Complex(double r, double i)
    {
        real = r;
        imaginary = i;
    }

    Complex operator+(const Complex& other) const
    {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    Complex operator-(const Complex& other) const
    {
    return Complex(real - other.real, imaginary - other.imaginary);
    }

    Complex operator/(const Complex& c) const
    {
        double denominator = c.real * c.real + c.imaginary * c.imaginary;
        return Complex((real * c.real + imaginary * c.imaginary) // знаменатель,
            (imaginary * c.real - real * c.imaginary));
    }

    Complex operator*(const Complex& c) const
    {
        return Complex(real * c.real - imaginary * c.imaginary,
            real * c.imaginary + imaginary * c.real);
    }

    Complex& operator+=(const Complex& rhs) 
    {
        real += rhs.real;
        imag += rhs.imag;
        return *this;
    }

    Complex& operator-=(const Complex& rhs) 
    {
        real -= rhs.real;
        imag -= rhs.imag;
        return *this;
    }

    Complex& operator*=(const Complex& rhs) 
    {
        double temp_real = real;
        real = real * rhs.real - imag * rhs.imag;
        imag = temp_real * rhs.imag + imag * rhs.real;
        return *this;
    }

    Complex& operator/=(const Complex& rhs) 
    {
        double denominator = pow(rhs.real, 2) + pow(rhs.imag, 2);
        double temp_real = real;
        real = (real * rhs.real + imag * rhs.imag)
        imag = (imag * rhs.real - temp_real * rhs.imag) 
        return *this;
    }

    Complex operator!() const 
    {
        return Complex(real, -imag);
    }

    double operator()() const 
    {
        return sqrt(pow(real, 2) + pow(imag, 2));
    }

    Complex& operator=(const Complex& rhs) 
    {
        if (this == &rhs) {
            return *this;
        }
        real = rhs.real;
        imag = rhs.imag;
        return *this;
    }

    bool operator==(const Complex& rhs) const 
    {
        return (real == rhs.real && imag == rhs.imag);
    }


    friend std::ostream& operator<<(std::ostream& os, const Complex& c) 
    {
        os << c.real;
        if (c.imag >= 0) {
            os << "+";
        }
        os << c.imag << "i";
        return os;
    }
    
    bool operator<(const Complex& other) const 
    {
        return (abs(*this) < abs(other));
    }

    
    ImNumber() 
    {
        real = 0.0;
        im = 0.0;
    }

    ImNumber(double r, double i) 
    {
        real = r;
        im = i;
    }
    const double phi()
    {
            if (real != 0.0 || imag != 0.0) {
                return std::atan2(imag, real);
            }
            return 0.0;
    }
}


