#include <cmath>
#include "sources/Fraction.hpp"
#include "doctest.h"
#include <iostream> 
#include <stdexcept>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <fstream>
using namespace std;
using namespace ariel;



TEST_CASE("negetiv fraction")
{
    Fraction f1(1, 2);
    Fraction f2(-1, 2);
    Fraction f3(1, -2);
    Fraction f4(-1, -2);
    CHECK(f1 == f2);
    CHECK(f1 == f3);
    CHECK(f1 == f4);
    CHECK(f2 == f3);
    CHECK(f2 == f4);
    CHECK(f3 == f4);
}

TEST_CASE("positive fraction")
{
    Fraction f1(1, 2);
    Fraction f2(3, 6);
    Fraction f3(3, 88);
    Fraction f4(28, 2);
    CHECK(f1 == f2);
    CHECK(f1 == f3);
    CHECK(f1 == f4);
    CHECK(f2 == f3);
    CHECK(f2 == f4);
    CHECK(f3 == f4);
}

TEST_CASE("division by zero")
{
    CHECK_THROWS(Fraction(1, 0));
    CHECK_THROWS(Fraction(-1, 0));
    CHECK_THROWS(Fraction(0, 0));
}
TEST_CASE("operator +")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(1, 1);
    CHECK(f1 + f2 == f3);
    CHECK(f1 + f2 == 1);
    CHECK(f1 + 1 == f3);
    CHECK(1 + f1 == f3);
}
TEST_CASE("operator -")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(0, 1);
    CHECK(f1 - f2 == f3);
    CHECK(f1 - f2 == 0);
    CHECK(f1 - 1 == -0.5);
    CHECK(1 - f1 == 0.5);
}
TEST_CASE("operator *")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(1, 4);
    CHECK(f1 * f2 == f3);
    CHECK(f1 * f2 == 0.25);
    CHECK(f1 * 2 == 1);
    CHECK(2 * f1 == 1);
}
TEST_CASE("operator /")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(1, 1);
    CHECK(f1 / f2 == f3);
    CHECK(f1 / f2 == 1);
    CHECK(f1 / 2 == 0.25);
    CHECK(2 / f1 == 4);
}
TEST_CASE("operator ++")
{
    Fraction f1(1, 2);
    Fraction f2(3, 2);
    CHECK(++f1 == f2);
    CHECK(f1 == f2);
}
TEST_CASE("operator --")
{
    Fraction f1(1, 2);
    Fraction f2(-1, 2);
    CHECK(--f1 == f2);
    CHECK(f1 == f2);
}
TEST_CASE("operator +=")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(1, 1);
    CHECK((f1 += f2) == f3);
    CHECK(f1 == f3);
}
TEST_CASE("operator -=")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(0, 1);
    CHECK((f1 -= f2) == f3);
    CHECK(f1 == f3);
}
TEST_CASE("operator *=")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(1, 4);
    CHECK((f1 *= f2) == f3);
    CHECK(f1 == f3);
}
TEST_CASE("operator /=")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(1, 1);
    CHECK((f1 /= f2) == f3);
    CHECK(f1 == f3);
}
TEST_CASE("operator >")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(1, 1);
    CHECK(f3 > f1);
    CHECK(f3 > f2);
    CHECK(f3 > 0.5);
    CHECK(f3 > 0);
}
TEST_CASE("operator <")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(1, 1);
    CHECK(f1 < f3);
    CHECK(f2 < f3);
    CHECK(0.5 < f3);
    CHECK(0 < f3);
}
TEST_CASE("operator >=")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(1, 1);
    CHECK(f3 >= f1);
    CHECK(f3 >= f2);
    CHECK(f3 >= 0.5);
    CHECK(f3 >= 0);
}
TEST_CASE("operator <=")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(1, 1);
    CHECK(f1 <= f3);
    CHECK(f2 <= f3);
    CHECK(0.5 <= f3);
    CHECK(0 <= f3);}
TEST_CASE("operator ==")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(1, 1);
    CHECK(f1 == f2);
    CHECK(f1 == 0.5);
    CHECK(0.5 == f1);
}
TEST_CASE("operator !=")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(1, 1);
    CHECK(f1 != f3);
    CHECK(f2 != f3);
    CHECK(f1 != 1);
    CHECK(1 != f1);
}
TEST_CASE("operator double")
{
    Fraction f1(1, 2);
    CHECK(f1.to_double() == 0.5);

}

TEST_CASE("operator <<")
{
    Fraction f1(1, 2);
    std::stringstream ss;
    ss << f1;
    CHECK(ss.str() == "1/2");
}
TEST_CASE("operator >>")
{
    Fraction f1(1, 2);
    std::stringstream ss;
    ss << "1/2";
    ss >> f1;
    CHECK(f1 == 0.5);
}
TEST_CASE("multiplay by zero")
{
    Fraction f1(1, 2);
    Fraction f2(0, 1);
    CHECK(f1 * f2 == f2);
    CHECK(f1 * f2 == 0);
    CHECK(f1 * 0 == f2);
    CHECK(0 * f1 == f2);
}
TEST_CASE("division by zero")
{
    Fraction f1(1, 2);
    Fraction f2(0, 1);
    CHECK(f1 / f2 == f2);
    CHECK(f1 / f2 == 0);
    CHECK(f1 / 0 == f2);
    CHECK(0 / f1 == f2);
}
TEST_CASE("multiplay Fraction")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(1, 4);
    CHECK(f1 * f2 == f3);
    CHECK(f1 * f2 == 0.25);
    CHECK(f1 * 2 == 1);
    CHECK(2 * f1 == 1);
}
TEST_CASE("division Fraction")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(1, 1);
    CHECK(f1 / f2 == f3);
    CHECK(f1 / f2 == 1);
    CHECK(f1 / 2 == 0.25);
    CHECK(2 / f1 == 4);
}
TEST_CASE("Add a number to a Fraction")
{
    Fraction f1(1, 2);
    Fraction f2(3, 2);
    CHECK(f1 + 2 == f2);
    CHECK(2 + f1 == f2);
}
TEST_CASE("Subtract a number from a Fraction")
{
    Fraction f1(1, 2);
    Fraction f2(-1, 2);
    CHECK(f1 - 2 == f2);
    CHECK(2 - f1 == -f2);
}
TEST_CASE("Add a Fraction to a Fraction")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(1, 1);
    CHECK(f1 + f2 == f3);
    CHECK(f1 + f2 == 1);
}
TEST_CASE("check the sign of the Fraction")
{
    Fraction f1(1, 2);
    Fraction f2(-1, 2);
    CHECK(f1 > 0);
    CHECK(f2 < 0);
}
TEST_CASE("check floor")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(1, 1);
    CHECK(f1.floor() == 0);
    CHECK(f2.floor() == 0);
    CHECK(f3.floor() == 1);

}
TEST_CASE("check ceil")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(1, 1);
    CHECK(f1.ceil() == 1);
    CHECK(f2.ceil() == 1);
    CHECK(f3.ceil() == 1);
}
TEST_CASE("convert to string")
{
    Fraction f1(1, 2);
    CHECK(f1.to_string() == "1/2");
}
TEST_CASE("convert to double")
{
    Fraction f1(1, 2);
    CHECK(f1.to_double() == 0.5);
}
TEST_CASE("convert to float")
{
    Fraction f1(1, 2);
    CHECK(f1.to_float() == 0.5f);
}
TEST_CASE("all comparison operators")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(1, 1);
    CHECK(f1 == f2);
    CHECK(f1 != f3);
    CHECK(f1 < f3);
    CHECK(f1 <= f3);
    CHECK(f3 > f1);
    CHECK(f3 >= f1);
}
TEST_CASE("all arithmetic operators")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(1, 1);
    CHECK(f1 + f2 == f3);
    CHECK(f1 - f2 == 0);
    CHECK(f1 * f2 == 0.25);
    CHECK(f1 / f2 == 1);
}
TEST_CASE("all arithmetic operators with numbers")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(1, 1);
    CHECK(f1 + 2 == f3);
    CHECK(f1 - 2 == -f3);
    CHECK(f1 * 2 == 1);
    CHECK(f1 / 2 == 0.25);
}
TEST_CASE("end point test")
{
    Fraction f1(1, 2);
    Fraction f2(1, 2);
    Fraction f3(1, 1);
    CHECK(f1 == f2);
    CHECK(f1 != f3);
    CHECK(f1 < f3);
    CHECK(f1 <= f3);
    CHECK(f3 > f1);
    CHECK(f3 >= f1);
    CHECK(f1 + f2 == f3);
    CHECK(f1 - f2 == 0);
    CHECK(f1 * f2 == 0.25);
    CHECK(f1 / f2 == 1);
    CHECK(f1 + 2 == f3);
    CHECK(f1 - 2 == -f3);
    CHECK(f1 * 2 == 1);
    CHECK(f1 / 2 == 0.25);
}

