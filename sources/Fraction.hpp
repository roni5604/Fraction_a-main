#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <numeric>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

namespace ariel
{
    class Fraction
    {
    private:
        int numerator;
        int denominator;
        void reduce()
        {
            int gcd = std::gcd(numerator, denominator);
            numerator /= gcd;
            denominator /= gcd;
        }

    public:
        Fraction(int num, int den);
        Fraction operator+(const Fraction &other_fraction) const;
        Fraction operator-(const Fraction &other_fraction) const;
        Fraction operator*(const Fraction &other_fraction) const;
        Fraction operator/(const Fraction &other_fraction) const;
        Fraction operator+=(const Fraction &other_fraction);
        Fraction operator-=(const Fraction &other_fraction);
        Fraction operator*=(const Fraction &other_fraction);
        Fraction operator/=(const Fraction &other_fraction);
        Fraction operator++();
        Fraction operator--();
        Fraction operator++(int);
        Fraction operator--(int);
        Fraction operator-() const;
        Fraction abs() const;
        Fraction pow(int n) const;
        Fraction sqrt() const;

        friend bool operator==(const Fraction &f1, const Fraction &f2);
        friend bool operator!=(const Fraction &f1, const Fraction &f2);
        friend bool operator>(const Fraction &f1, const Fraction &f2);
        friend bool operator<(const Fraction &f1, const Fraction &f2);
        friend bool operator>=(const Fraction &f1, const Fraction &f2);
        friend bool operator<=(const Fraction &f1, const Fraction &f2);


        friend bool operator==(const Fraction &other, float f1);
        friend bool operator!=(const Fraction &other, float f1);
        friend bool operator<(const Fraction &other, float f1);
        friend bool operator<=(const Fraction &other, float f1);
        friend bool operator>(const Fraction &other, float f1);
        friend bool operator>=(const Fraction &other, float f1);
        
        friend bool operator==(float f1, const Fraction &other);
        friend bool operator!=(float f1, const Fraction &other);
        friend bool operator<(float f1, const Fraction &other);
        friend bool operator<=(float f1, const Fraction &other);
        friend bool operator>(float f1, const Fraction &other);
        friend bool operator>=(float f1, const Fraction &other);

        


        friend Fraction operator+(const float &d, const Fraction &f);
        friend Fraction operator-(const float &d, const Fraction &f);
        friend Fraction operator*(const float &d, const Fraction &f);
        friend Fraction operator/(const float &d, const Fraction &f);
        friend Fraction operator+(const Fraction &f, const float &d);
        friend Fraction operator-(const Fraction &f, const float &d);
        friend Fraction operator*(const Fraction &f, const float &d);
        friend Fraction operator/(const Fraction &f, const float &d);
        friend std::ostream &operator<<(std::ostream &os, const Fraction &f);
        friend std::istream &operator>>(std::istream &is, Fraction &f);

        bool operator==(const float &d) const;
        bool operator!=(const float &d) const;
        bool operator<(const float &d) const;
        bool operator>=(const float &d) const;
        bool operator<=(const float &d) const;

        int ceil() const;
        int floor() const;
        

        float to_float() const;
        double to_double() const;
        std::string to_string() const;
    };

}