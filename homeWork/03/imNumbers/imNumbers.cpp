#include "imNumbers.hpp"
using namespace std;

bool ImNumber::operator=(const ImNumber& num)const
{
    return fabs(real - num.real) < EPS && fabs(im - num.im) < EPS;
}

double ImNumber::operator()() const {
    return sqrt(real * real + im * im);
}

ImNumber ImNumber::operator+(const ImNumber& rhs)const
{
    ImNumber result = *this;
    result.real += rhs.real;
    result.im += rhs.im;
    return result;
}

ImNumber ImNumber::operator-(const ImNumber& rhs)const
{
    ImNumber result = *this;
    result.real -= rhs.real;
    result.im -= rhs.im;
    return result;
}

ImNumber ImNumber::operator*(const ImNumber& rhs) const
{
    ImNumber result = *this;
    result.real = real * rhs.real - im * rhs.im;
    result.im = (real * rhs.im) + (rhs.real * im);
    return result;
}

ImNumber ImNumber::operator/(const ImNumber& other)const {
    ImNumber result = *this;
    double denominator = other.real * other.real + other.im * other.im;
    result.real = (real * other.real + im * other.im) / denominator;
    result.im = (im * other.real - real * other.im) / denominator;
    return result;
}

ImNumber ImNumber::operator+=(const ImNumber& other)
{
    real += other.real;
    im += other.im;
    return *this;
}

ImNumber ImNumber::operator-=(const ImNumber& other)
{
    real -= other.real;
    im -= other.im;
    return *this;
}

ImNumber ImNumber::operator*=(const ImNumber& other) {
    double newReal = (real * other.real) - (im * other.im);
    double newImaginary = (real * other.im) + (im * other.real);
    real = newReal;
    im = newImaginary;
    return *this;
}

ImNumber ImNumber::operator/=(const ImNumber& rhs)
{
    double denominator = (rhs.real * rhs.real) + (rhs.im * rhs.im);

    double newReal = ((real * rhs.real) + (im * rhs.im)) / denominator;
    double newImaginary = ((im * rhs.real) - (real * rhs.im)) / denominator;

    real = newReal;
    im = newImaginary;

    return *this;
}

bool ImNumber::operator==(const ImNumber& operand2) const
{
    return (real == operand2.real && im == operand2.im);
}

std::ostream& operator<<(std::ostream& os, const ImNumber& complex)
{
    os << complex.real;

    if (complex.im > 0)
        os << "+i" << complex.im;
    else if (complex.im < 0)
        os << "-i" << -complex.im;

    return os;
}