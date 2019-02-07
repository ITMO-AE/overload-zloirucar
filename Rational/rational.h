#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>

class Rational
{
private:
  int l_numerator;
  int l_denominator;
  void nod();
public:
  Rational(int numerator = 0, int denominator = 1);
  int Numerator() const;
  int Denominator() const;
  void set_Numerator(int n);
  void set_Denominator(int d);
  friend const Rational operator +(const Rational &vector1, const Rational &vector2);
  friend const Rational operator -(const Rational &vector1, const Rational &vector2);
  friend const bool operator == (const Rational &vector1, const Rational &vector2);
  friend const Rational operator *(const Rational &vector1, const Rational &vector2);
  friend const Rational operator /(const Rational &vector1, const Rational &vector2);
  friend std::ostream& operator << (std::ostream &s, const Rational &v);
  friend std::istream &operator >> (std::istream &s, Rational &v);

};

#endif // RATIONAL_H
