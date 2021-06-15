#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <exception>
#include <stdexcept>
#include "Rational.h"

using namespace std;

int GCD(int a,int b){
    while(a*b != 0)
      if(a >= b)
        a = a-b;
        else
        b = b-a;
    return a+b;
}

Rational::Rational(){
  num = 0;
  deNum = 1;
}

Rational::Rational(int numenator,int denuminator){
  if(denuminator == 0)
    throw invalid_argument("Invalid argument");

  num = numenator;
  if(num == 0)
    deNum = 1;
  else
    deNum = denuminator;
  ResolveSign();
  Reduce();
}

int Rational::Numerator() const{
  return num;
}

int Rational::Denominator() const{
  return deNum;
}

void Rational::setFraction(int a,int b){
  if(b == 0)
    throw invalid_argument("Invalid argument");
  num = a;
  deNum = b;
  ResolveSign();
  Reduce();
}

double Rational::getFraction() const{return (double) num/deNum;}

void Rational::Reduce(){
  int gcd = GCD(abs(num),abs(deNum));
  if(gcd != 1){
    num /= gcd;
    deNum /= gcd;
  }
}

void Rational::ResolveSign(){
  if(num >= 0 && deNum < 0){
    num = -num;
    deNum = -deNum;
  }
  else if(num < 0 && deNum < 0){
    num = -num;
    deNum = -deNum;
  }
}

Rational operator+(const Rational& lhs, const Rational& rhs){
  int gDiv = GCD(lhs.Denominator(),rhs.Denominator());
  return Rational(lhs.Numerator()*rhs.Denominator()/gDiv + rhs.Numerator()*lhs.Denominator()/gDiv,
                  lhs.Denominator()*rhs.Denominator()/gDiv);
}

Rational operator-(const Rational& lhs, const Rational& rhs){
  int gDiv = GCD(rhs.Denominator(),lhs.Denominator());
  return Rational(lhs.Numerator()*rhs.Denominator()/gDiv - rhs.Numerator()*lhs.Denominator()/gDiv,
                  lhs.Denominator()*rhs.Denominator()/gDiv);
}

bool operator==(const Rational& lhs, const Rational& rhs){
  return (rhs.Numerator() == lhs.Numerator() && rhs.Denominator() == lhs.Denominator());
}

Rational operator*(const Rational& lhs, const Rational& rhs){
  return Rational(lhs.Numerator()*rhs.Numerator(),lhs.Denominator()*rhs.Denominator());
}

Rational operator/(const Rational& lhs, const Rational& rhs){
  if(rhs.Numerator() == 0)
    throw domain_error("Division by zero");

  return Rational(lhs.Numerator()*rhs.Denominator(),lhs.Denominator()*rhs.Numerator());
}

ostream& operator<<(ostream& output,const Rational fraction){
  return output << fraction.Numerator() << "/" << fraction.Denominator();
}

istream& operator>>(istream& input,Rational& fraction){
  int a, b;
  char c;
  string str;
  if(input >> a >> c >> b)
    if(c == '/')
      fraction.setFraction(a,b);
  return input;
}

bool operator<(const Rational& lhs,const Rational& rhs){
  return lhs.getFraction() < rhs.getFraction();
}

bool operator>(const Rational& lhs,const Rational& rhs){
  return lhs.getFraction() > rhs.getFraction();
}

//small calculator
int main() {
  Rational lhs, rhs;
  char op;
  try{
    cin >> lhs >> op >> rhs;
  } catch(exception& ex){
    cout << ex.what();
    return 1;
  }

  if(op == '+')
    cout << lhs + rhs;
  else if(op == '-')
   cout << lhs - rhs;
  else if(op == '*')
    cout << lhs*rhs;
  else
    try{
      cout << lhs/rhs;
    }catch(exception& ex){
      cout << ex.what();
      return 2;
    }
  return 0;
}
