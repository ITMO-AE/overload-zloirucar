#include "rational.h"
#include "assert.h"
#include <string>
#include <vector>





Rational::Rational(int numerator, int denominator):
    l_numerator(numerator),l_denominator(denominator)
{
    nod();

}

Rational const  operator +(const Rational &vector1, const Rational &vector2)
{
    int nok = vector1.Denominator()*vector2.Denominator();
    int new_numerator = vector1.Numerator()*vector2.Denominator()+vector2.Numerator()*vector1.Denominator();
    int new_denominator = nok;
    return Rational (new_numerator,new_denominator);
}

Rational const operator -(const Rational &vector1, const Rational &vector2)
{
    int nok = vector1.Denominator()*vector2.Denominator();
    int new_numerator = vector1.Numerator()*vector2.Denominator()-vector2.Numerator()*vector1.Denominator();
    int new_denominator = nok;
    return Rational (new_numerator,new_denominator);
}

Rational const operator /(const Rational &vector1, const Rational &vector2)
{
    int new_numerator = vector1.Numerator()*vector2.Denominator();
    int new_denominator = vector1.Denominator()*vector2.Numerator();
    return Rational (new_numerator,new_denominator);
}

Rational const operator *(const Rational &vector1, const Rational &vector2)
{
    int new_numerator = vector1.Numerator()*vector2.Numerator();
    int new_denominator = vector1.Denominator()*vector2.Denominator();
    return Rational (new_numerator,new_denominator);
}

const bool operator ==(const Rational &vector1, const Rational &vector2)
{
    if (vector1.Numerator() == vector2.Numerator() && vector1.Denominator() == vector2.Denominator()) return true;
    return false;
}


std::istream &operator >> (std::istream &s, Rational &v)
{
    std::string name;
    int n = 0 , d = 0;
    s >> name;
    if (name.size() == 0) return s;
    bool n_flg = true;
    for (int i = 0; i < name.size(); i++)
    {
        if (name.at(i) == 47)
        {
            n_flg = false;
        }
        if (n_flg  && name.at(i) != 47)
        {
            n = n*10 + (name.at(i) - 48);
        }
        if(!n_flg  && name.at(i) != 47)
        {
            d = d*10 + (name.at(i) - 48);
        }
    }
    v.set_Denominator(d);
    v.set_Numerator(n);
    v.nod();
    return s;
}

std::ostream &operator <<(std::ostream &s, const Rational &v)
{
    s << v.Numerator() << '/' << v.Denominator();
    return s;
}



void Rational::nod()
{
    if (l_numerator < 0 && l_denominator < 0 )
    {
        l_numerator *=-1;
        l_denominator *= -1;
    }
    int k =0;
    if (l_numerator < 0)
    {
        l_numerator*= -1;
        k = 1;
    }
    if (l_denominator < 0)
    {
        l_denominator *= -1;
        k =2;
    }
    if (l_numerator == 0) l_denominator = 1;
    assert(l_denominator != 0);
    for (int i = l_numerator; i > 0; i--) {
            if (l_numerator % i == 0 && l_denominator % i == 0) {
                l_numerator /= i;
                l_denominator /= i;
                if ( k == 1 || k ==2) l_numerator *=-1;
                break;
            }
    }
}

int Rational::Numerator() const
{
    return l_numerator;
}

int Rational::Denominator() const
{
    return l_denominator;
}

void Rational::set_Numerator(int n)
{
    l_numerator = n;
}

void Rational::set_Denominator(int d)
{
    l_denominator = d;
}

