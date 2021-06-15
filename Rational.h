#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <exception>
#include <stdexcept>

using namespace std;

class Rational{
public:
  Rational();

  Rational(int numenator,int denuminator);

  int Numerator() const;
  int Denominator() const;

  void setFraction(int a,int b);

  double getFraction() const;
private:
  void Reduce();

  void ResolveSign();

  int num;
  int deNum;
};

int GCD(int a, int b);

Rational operator+(const Rational& lhs, const Rational& rhs);

Rational operator-(const Rational& lhs, const Rational& rhs);

bool operator==(const Rational& lhs, const Rational& rhs);

Rational operator*(const Rational& lhs, const Rational& rhs);

Rational operator/(const Rational& lhs, const Rational& rhs);

ostream& operator<<(ostream& output,const Rational fraction);

istream& operator>>(istream& input,Rational& fraction);

bool operator<(const Rational& lhs,const Rational& rhs);

bool operator>(const Rational& lhs,const Rational& rhs);

#endif
