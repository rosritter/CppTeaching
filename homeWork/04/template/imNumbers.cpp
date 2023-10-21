#include "ImNumbers.hpp"
/* template <class T>
ImNumber<T> ImNumber<T>::operator+(const ImNumber<T>& num)const {
    return ImNumber<T>(real + num.real, im + num.im);
}
template <class T>
ImNumber<T> ImNumber<T>::operator-(const ImNumber<T>& num)const {
    return ImNumber<T>(real - num.real, im - num.im);
}
template <class T>
ImNumber<T> ImNumber<T>::operator/(const ImNumber<T>& num)const {
    return ImNumber<T>((real*num.real + im*num.im)/(pow(num.real,2) + pow(num.im,2)), (num.real*im - real*num.im)/(pow(num.real,2) + pow(num.im,2)));
}
template <class T>
ImNumber<T> ImNumber<T>::operator*(const ImNumber<T>& num)const {
    return ImNumber<T>(real * num.real - im * num.im, real * num.im + num.real * im);
}
template <class T>
ImNumber<T>& ImNumber<T>::operator+=(const ImNumber<T>& num) {
    real += num.real;
    im += num.im;
    return *this;
}
template <class T>
ImNumber<T>& ImNumber<T>::operator-=(const ImNumber<T>& num) {
    real -= num.real;
    im -= num.im;
    return *this;
}
template <class T>
ImNumber<T>& ImNumber<T>::operator/=(const ImNumber<T>& num) {
    double realt = real, imt = im;
    real = (realt*num.real + imt*num.im)/(pow(num.real,2) + pow(num.im,2));
    im = (num.real*imt - realt*num.im)/(pow(num.real,2) + pow(num.im,2));
    return *this;
}
template <class T>
ImNumber<T>& ImNumber<T>::operator*=(const ImNumber<T>& num) {
    double realt = real, imt = im;
    real = realt * num.real - imt * num.im;
    im =  realt * num.im + num.real * imt;
    return *this;
}
template <class T>
ImNumber<T> ImNumber<T>::operator!()const {
    return ImNumber<T>(real, -im);
}
template <class T>
T ImNumber<T>::operator()()const {
    return sqrt(pow(real,2) + pow(im,2));
}
template <class T>
bool ImNumber<T>::operator==(const ImNumber<T>& num)const {
    return fabs(real - num.real) < EPS && fabs(im - num.im) < EPS;
}
template <class T>
bool ImNumber<T>::operator<(const ImNumber<T>& num)const {
    ImNumber<T> t(real, im);
    return t() < num();
}
template <class T>
const T ImNumber<T>::phi()const {
    return atan2(im, real);
}
template <class T>
void ImNumber<T>::operator=(const ImNumber<T>& num)const {
    num.real = real;
    num.im = im;
} */