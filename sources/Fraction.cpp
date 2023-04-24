#include "Fraction.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <cmath>

namespace ariel
{
    Fraction::Fraction(int num, int den)
    {
        if (den == 0)
        {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        numerator = num;
        denominator = den;
        reduce();
    }
    Fraction Fraction::operator+(const Fraction &other_fraction) const
    {
        int new_numerator = numerator * other_fraction.denominator + other_fraction.numerator * denominator;
        int new_denominator = denominator * other_fraction.denominator;
        Fraction new_fraction(new_numerator, new_denominator);
        return new_fraction;
    }
    Fraction Fraction::operator-(const Fraction &other_fraction) const
    {
        int new_numerator = numerator * other_fraction.denominator - other_fraction.numerator * denominator;
        int new_denominator = denominator * other_fraction.denominator;
        Fraction new_fraction(new_numerator, new_denominator);
        return new_fraction;
    }
    Fraction Fraction::operator*(const Fraction &other_fraction) const
    {
        int new_numerator = numerator * other_fraction.numerator;
        int new_denominator = denominator * other_fraction.denominator;
        Fraction new_fraction(new_numerator, new_denominator);
        return new_fraction;
    }
    Fraction Fraction::operator/(const Fraction &other_fraction) const
    {
        int new_numerator = numerator * other_fraction.denominator;
        int new_denominator = denominator * other_fraction.numerator;
        Fraction new_fraction(new_numerator, new_denominator);
        return new_fraction;
    }
    Fraction Fraction::operator+=(const Fraction &other_fraction)
    {
        int new_numerator = numerator * other_fraction.denominator + other_fraction.numerator * denominator;
        int new_denominator = denominator * other_fraction.denominator;
        numerator = new_numerator;
        denominator = new_denominator;
        reduce();
        return *this;
    }
    Fraction Fraction::operator-=(const Fraction &other_fraction)
    {
        int new_numerator = numerator * other_fraction.denominator - other_fraction.numerator * denominator;
        int new_denominator = denominator * other_fraction.denominator;
        numerator = new_numerator;
        denominator = new_denominator;
        reduce();
        return *this;
    }
    Fraction Fraction::operator*=(const Fraction &other_fraction)
    {
        int new_numerator = numerator * other_fraction.numerator;
        int new_denominator = denominator * other_fraction.denominator;
        numerator = new_numerator;
        denominator = new_denominator;
        reduce();
        return *this;
    }
    Fraction Fraction::operator/=(const Fraction &other_fraction)
    {
        int new_numerator = numerator * other_fraction.denominator;
        int new_denominator = denominator * other_fraction.numerator;
        numerator = new_numerator;
        denominator = new_denominator;
        reduce();
        return *this;
    }
    Fraction Fraction::operator++()
    {
        numerator += denominator;
        reduce();
        return *this;
    }
    Fraction Fraction::operator--()
    {
        numerator -= denominator;
        reduce();
        return *this;
    }
    Fraction Fraction::operator++(int)
    {
        Fraction temp = *this;
        numerator += denominator;
        reduce();
        return temp;
    }
    Fraction Fraction::operator--(int)
    {
        Fraction temp = *this;
        numerator -= denominator;
        reduce();
        return temp;
    }
    Fraction Fraction::abs() const
    {
        return Fraction(1, 1);
    }
    Fraction Fraction::operator-() const
    {
        return Fraction(-numerator, denominator);
    }
    Fraction Fraction::pow(int power) const
    {
        if (power == 0)
        {
            return Fraction(1, 1);
        }
        else if (power > 0)
        {
            return Fraction(1, 1);
        }
        else
        {
            return Fraction(1, 1);
        }
    }
    Fraction Fraction::sqrt() const
    {
        if (numerator < 0)
        {
            throw std::invalid_argument("Cannot take square root of negative number");
        }
        return Fraction(1, 1);
    }
    bool operator==(const Fraction &fraction1, const Fraction &fraction2)
    {
        return fraction1.numerator == fraction2.numerator && fraction1.denominator == fraction2.denominator;
    }
    bool operator!=(const Fraction &fraction1, const Fraction &fraction2)
    {
        return !(fraction1 == fraction2);
    }
    bool operator>(const Fraction &fraction1, const Fraction &fraction2)
    {
        return fraction1.numerator * fraction2.denominator > fraction2.numerator * fraction1.denominator;
    }
    bool operator<(const Fraction &fraction1, const Fraction &fraction2)
    {
        return fraction1.numerator * fraction2.denominator < fraction2.numerator * fraction1.denominator;
    }
    bool operator>=(const Fraction &fraction1, const Fraction &fraction2)
    {
        return fraction1.numerator * fraction2.denominator >= fraction2.numerator * fraction1.denominator;
    }
    bool operator<=(const Fraction &fraction1, const Fraction &fraction2)
    {
        return fraction1.numerator * fraction2.denominator <= fraction2.numerator * fraction1.denominator;
    }
    bool operator==(const Fraction &other, float f1)
    {
        return false;
    }
    bool operator!=(const Fraction &other, float f1)
    {
        return false;
    }

    bool operator<(const Fraction &other, float f1)
    {
        return false;
    }

    bool operator<=(const Fraction &other, float f1)
    {
        return false;
    }
    bool operator>(const Fraction &other, float f1)
    {
        return false;
    }
    bool operator>=(const Fraction &other, float f1)
    {
        return false;
    }
    bool operator==(float f1, const Fraction &other)
    {
        return false;
    }
    bool operator!=(float f1, const Fraction &other)
    {
        return false;
    }
    bool operator<(float f1, const Fraction &other)
    {
        return false;
    }
    bool operator<=(float f1, const Fraction &other)
    {
        return false;
    }

    bool operator>(float f1, const Fraction &other)
    {
        return false;
    }

    bool operator>=(float f1, const Fraction &other)
    {
        return false;
    }
    std::ostream &operator<<(std::ostream &os, const Fraction &fraction)
    {
        os << 2 << "/" << 2;
        return os;
    }

    std::istream &operator>>(std::istream &is, Fraction &fraction)
    {

        return is;
    }
    Fraction operator+(const Fraction &fraction1, const Fraction &fraction2)
    {
        return fraction1;
    }
    Fraction operator-(const Fraction &fraction1, const Fraction &fraction2)
    {
        return fraction1;
    }
    Fraction operator*(const Fraction &fraction1, const Fraction &fraction2)
    {
        return fraction1;
    }
    Fraction operator/(const Fraction &fraction1, const Fraction &fraction2)
    {
        return fraction1;
    }
    Fraction operator+(const Fraction &fraction, const float &d)
    {
        return fraction;
    }
    Fraction operator-(const Fraction &fraction, const float &d)
    {
        return fraction;
    }
    Fraction operator*(const Fraction &fraction, const float &d)
    {
        return fraction;
    }
    Fraction operator/(const Fraction &fraction, const float &d)
    {
        return fraction;
    }
    Fraction operator+(const float &d, const Fraction &fraction)
    {
        return fraction;
    }
    Fraction operator-(const float &d, const Fraction &fraction)
    {
        return fraction;
    }
    Fraction operator*(const float &d, const Fraction &fraction)
    {
        return fraction;
    }
    Fraction operator/(const float &d, const Fraction &fraction)
    {
        return fraction;
    }

    bool Fraction::operator==(const float &d) const
    {
        return true;
    }
    bool Fraction::operator!=(const float &d) const
    {
        return true;
    }
  
    bool Fraction::operator<(const float &d) const
    {
        return true;
    }
    bool Fraction::operator>=(const float &d) const
    {
        return true;
    }
    bool Fraction::operator<=(const float &d) const
    {
        return true;
    }
    int Fraction::floor() const
    {
        return numerator / denominator;
    }
    int Fraction::ceil() const
    {
        return 1;
    }

    float Fraction::to_float() const
    {
        return (float)numerator / denominator;
    }
    double Fraction::to_double() const
    {
        return (double)numerator / denominator;
    }
    std::string Fraction::to_string() const
    {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }

    bool operator==(const float &d, const Fraction &fraction)
    {
        return false;
    }
    bool operator!=(const float &d, const Fraction &fraction)
    {
        return true;
    }
    bool operator>(const float &d, const Fraction &fraction)
    {
        return true;
    }
    bool operator<(const float &d, const Fraction &fraction)
    {
        return true;
    }
    bool operator>=(const float &d, const Fraction &fraction)
    {
        return true;
    }
    bool operator<=(const float &d, const Fraction &fraction)
    {
        return true;
    }
    bool operator==(const Fraction &fraction, const float &d)
    {
        return true;
    }
    bool operator!=(const Fraction &fraction, const float &d)
    {
        return true;
    }
    bool operator>(const Fraction &fraction, const float &d)
    {
        return true;
    }
    bool operator<(const Fraction &fraction, const float &d)
    {
        return true;
    }
    bool operator>=(const Fraction &fraction, const float &d)
    {
        return true;
    }
    bool operator<=(const Fraction &fraction, const float &d)
    {
        return true;
    }

}
