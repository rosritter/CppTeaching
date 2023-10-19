#include "ImNumber.hpp"

/*class ImNumber
{
public:
    double real;
    double im;

    ImNumber() : real(0.0), im(0.0) {}
    ImNumber(double real, double im) : real(real), im(im) {}

    ImNumber operator+(const ImNumber& other) const {
        return ImNumber(real + other.real, im + other.im);
    }

    ImNumber operator-(const ImNumber& other) const {
        return ImNumber(real - other.real, im - other.im);
    }

    ImNumber operator*(const ImNumber& other) const {
        return ImNumber(real * other.real - im * other.im, real * other.im + im * other.real);
    }

    ImNumber operator/(const ImNumber& other) const {
        double denominator = other.real * other.real + other.im * other.im;
        return ImNumber((real * other.real + im * other.im) / denominator,
            (im * other.real - real * other.im) / denominator);
    }

    ImNumber& operator+=(const ImNumber& other) {
        real += other.real;
        im += other.im;
        return *this;
    }

    ImNumber& operator-=(const ImNumber& other) {
        real -= other.real;
        im -= other.im;
        return *this;
    }

    ImNumber& operator*=(const ImNumber& other) {
        double tmpReal = real;
        real = real * other.real - im * other.im;
        im = tmpReal * other.im + im * other.real;
        return *this;
    }

    ImNumber& operator/=(const ImNumber& other) {
        double denominator = other.real * other.real + other.im * other.im;
        double tmpReal = real;
        real = (real * other.real + im * other.im) / denominator;
        im = (im * other.real - tmpReal * other.im) / denominator;
        return *this;
    }

    ImNumber operator!() const {
        return ImNumber(real, -im);
    }

    double operator()() const {
        return std::sqrt(real * real + im * im);
    }

    bool operator==(const ImNumber& other) const {
        return (real == other.real) && (im == other.im);
    }

    bool operator<(const ImNumber& other) const {
        return ((*this)() < other());
    }

    friend std::ostream& operator<<(std::ostream& os, const ImNumber& num) {
        if (num.im >= 0)
            os << num.real << '+' << num.im << 'i';
        else
            os << num.real << num.im << 'i';
        return os;
    }

    double phi() const {
        return std::arg(std::complex<double>(real, im));
    }
};/*
