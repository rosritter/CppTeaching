#pragma once
#include <cmath>
#include <iostream>
#include <stack>


const double EPS = 1e-10;

template <typename T>
class ImNumber {
private:
    T real;
    T im;

public:
    ImNumber();
    ImNumber(T real, T im);
    
    double phi() const;
    
    ImNumber<T> operator+(const ImNumber<T>& num) const;
    ImNumber<T> operator-(const ImNumber<T>& num) const;
    ImNumber<T> operator*(const ImNumber<T>& num) const;
    ImNumber<T> operator/(const ImNumber<T>& num) const;
    ImNumber<T>& operator+=(const ImNumber<T>& num);
    ImNumber<T>& operator-=(const ImNumber<T>& num);
    ImNumber<T>& operator*=(const ImNumber<T>& num);
    ImNumber<T>& operator/=(const ImNumber<T>& num);
    bool operator==(const ImNumber<T>& num) const;
    bool operator!=(const ImNumber<T>& num) const;
    bool operator<(const ImNumber<T>& num) const;
    ImNumber<T> operator!() const;
    double operator()() const;
    
    template <typename U>
    friend std::ostream& operator<<(std::ostream& out, const ImNumber<U>& num);
};

template <typename T>
ImNumber<T>::ImNumber() : real(0), im(0) {}

template <typename T>
ImNumber<T>::ImNumber(T real, T im) : real(real), im(im) {}

template <typename T>
double ImNumber<T>::phi() const {
    return atan2(im, real);
}

template <typename T>
ImNumber<T> ImNumber<T>::operator+(const ImNumber<T>& num) const {
    return ImNumber<T>(real + num.real, im + num.im);
}

template <typename T>
ImNumber<T> ImNumber<T>::operator-(const ImNumber<T>& num) const {
    return ImNumber<T>(real - num.real, im - num.im);
}

template <typename T>
ImNumber<T> ImNumber<T>::operator*(const ImNumber<T>& num) const {
    return ImNumber<T>(real * num.real - im * num.im, real * num.im + im * num.real);
}

template <typename T>
ImNumber<T> ImNumber<T>::operator/(const ImNumber<T>& num) const {
    T dm = num.real * num.real + num.im * num.im;
    return ImNumber<T>((real * num.real + im * num.im) / dm, (im * num.real - real * num.im) / dm);
}

template <typename T>
ImNumber<T>& ImNumber<T>::operator+=(const ImNumber<T>& num) {
    real += num.real;
    im += num.im;
    return *this;
}

template <typename T>
ImNumber<T>& ImNumber<T>::operator-=(const ImNumber<T>& num) {
    real -= num.real;
    im -= num.im;
    return *this;
}

template <typename T>
ImNumber<T>& ImNumber<T>::operator*=(const ImNumber<T>& num) {
    T new_real = real * num.real - im * num.im;
    T new_im = real * num.im + im * num.real;
    real = new_real;
    im = new_im;
    return *this;
}

template <typename T>
ImNumber<T>& ImNumber<T>::operator/=(const ImNumber<T>& num) {
    T dm = num.real * num.real + num.im * num.im;
    T new_real = (real * num.real + im * num.im) / dm;
    T new_im = (im * num.real - real * num.im) / dm;
    real = new_real;
    im = new_im;
    return *this;
}

template <typename T>
bool ImNumber<T>::operator==(const ImNumber<T>& num) const {
    double tolerance = EPS;
    return (fabs(real - num.real) < tolerance) && (fabs(im - num.im) < tolerance);
}

template <typename T>
bool ImNumber<T>::operator!=(const ImNumber<T>& num) const {
    double tolerance = EPS;
    return (fabs(real - num.real) >= tolerance) || (fabs(im - num.im) >= tolerance);
}


template <typename T>
bool ImNumber<T>::operator<(const ImNumber<T>& num) const {
    return hypot(real, im) < hypot(num.real, num.im);
}

template <typename T>
ImNumber<T> ImNumber<T>::operator!() const {
    return ImNumber<T>(real, -im);
}

template <typename T>
double ImNumber<T>::operator()() const {
    return hypot(real, im);
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const ImNumber<T>& num) {
    out << num.real;
    if (num.im >= 0) {
        out << "+i" << num.im;
    } else {
        out << "-i" << -num.im;
    }
    return out;
}

