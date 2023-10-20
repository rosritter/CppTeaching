#include "imNumbers.hpp"

ImNumber ImNumber::operator+(const ImNumber& num)const {
    return ImNumber(real + num.real, im + num.im);
}
ImNumber ImNumber::operator-(const ImNumber& num)const {
    return ImNumber(real - num.real, im - num.im);
}

ImNumber ImNumber::operator*(const ImNumber& num)const {
    return ImNumber(real * num.real - im * num.im, real * num.im + num.real * im);
}
ImNumber ImNumber::operator/(const ImNumber& num)const {
    return ImNumber((real*num.real + im*num.im)/(pow(num.real,2) + pow(num.im,2)), (num.real*im - real*num.im)/(pow(num.real,2) + pow(num.im,2)));
}
ImNumber& ImNumber::operator+=(const ImNumber& num) {
    real += num.real;
    im += num.im;
    return *this;
}
ImNumber& ImNumber::operator-=(const ImNumber& num) {
    real -= num.real;
    im -= num.im;
    return *this;
}

ImNumber& ImNumber::operator*=(const ImNumber& num) {
    double realt = real, imt = im;
    real = realt * num.real - imt * num.im;
    im =  realt * num.im + num.real * imt;
    return *this;
}
ImNumber& ImNumber::operator/=(const ImNumber& num) {
    double realt = real, imt = im;
    real = (realt*num.real + imt*num.im)/(pow(num.real,2) + pow(num.im,2));
    im = (num.real*imt - realt*num.im)/(pow(num.real,2) + pow(num.im,2));
    return *this;
}
ImNumber ImNumber::operator!()const {
    return ImNumber(real, -im);
}
double ImNumber::operator()()const {
    return sqrt(pow(real,2) + pow(im,2));
}
bool ImNumber::operator==(const ImNumber& num)const {
    return real == num.real && im == num.im;
}
bool ImNumber::operator<(const ImNumber& num)const {
    ImNumber t(real, im);
    return t() < num();
}
std::ostream& operator<<(std::ostream& stream, const ImNumber num) {
    stream << num.real;
    num.im > 0 ? stream << "+i" << num.im : stream << "-i" << fabs(num.im);
    return stream;
}
const double ImNumber::phi()const {
    return atan2(im, real);
}