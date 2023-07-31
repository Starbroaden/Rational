#include <iostream>

struct Rational 
{
    Rational(int numerator = 0, int denominator = 1) : numerator_(numerator), denominator_(denominator) {};

    void add(Rational rational) 
    {
        numerator_ = numerator_ * rational.denominator_ + rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void sub(Rational rational)
    {
        numerator_ = numerator_ * rational.denominator_ - rational.numerator_ * denominator_;
        denominator_ *= rational.denominator_;
    }

    void mul(Rational rational) 
    {
        numerator_ *= rational.numerator_;
        denominator_ *= rational.denominator_;
    }

    void div(Rational rational) 
    {
        numerator_ *= rational.denominator_;
        denominator_ *= rational.numerator_;
    }

    void neg() 
    {
        numerator_ = -numerator_;
    }

    void inv() {}

    double to_double() const 
    {
        return numerator_ / (double) denominator_;
    }

    operator double() const
    {
        return to_double();
    }

    Rational & operator += (Rational const & rational)
    {
        this -> add(rational);            
        return *this; 
    }

    Rational & operator += (int number) 
    { 
        this -> add(Rational(number));         
        return *this; 
    }

    Rational & operator -= (Rational const & rational)
    {
        this -> sub(rational);            
        return *this; 
    }

    Rational & operator -= (int number) 
    { 
        this -> sub(Rational(number));         
        return *this; 
    }

    Rational & operator *= (Rational const & rational)
    {
        this -> mul(rational);            
        return *this; 
    }

    Rational & operator *= (int number) 
    { 
        this -> mul(Rational(number));         
        return *this; 
    }

    Rational & operator /= (Rational const & rational)
    {
        this -> div(rational);            
        return *this; 
    }

    Rational & operator /= (int number) 
    { 
        this -> div(Rational(number));         
        return *this; 
    }


    Rational operator -() const 
    {
        Rational rational = Rational(this -> numerator_, this -> denominator_);
        rational.neg();
        return rational;
    }

    Rational operator +() const 
    {
        Rational rational = Rational(this -> numerator_, this -> denominator_);
        return rational;
    }

    bool operator == (Rational const & rational) 
    {
        return (numerator_ * rational.denominator_== rational.numerator_ * denominator_);
    }

    bool operator == (int number) 
    {
        return (numerator_ == (double)number * denominator_);
    }


    bool operator != (Rational const & rational) 
    {
        return !(*this == rational);
    }

    bool operator != (int number) 
    {
        return !(*this == number);
    }

    bool operator > (Rational const & rational) 
    {
        return (numerator_ * rational.denominator_ > rational.numerator_ * denominator_);
    }

    bool operator > (int number) 
    {
        return (numerator_ > (double)number * denominator_);
    }

    bool operator <= (Rational const & rational) 
    {
        return !(*this > rational);
    }

    bool operator <= (int number) 
    {
        return !(*this > number);
    }

    bool operator < (Rational const & rational) 
    {
        return (numerator_ * rational.denominator_ < rational.numerator_ * denominator_);
    }

    bool operator < (int number) 
    {
        return (numerator_ < (double)number * denominator_);
    }

    bool operator >= (Rational const & rational) 
    {
        return !(*this < rational);
    }

    bool operator >= (int number)
    {
        return !(*this < number);
    }

    private:
    int numerator_;
    int denominator_;
};

Rational operator + (Rational left, Rational const & right)
{
    return left += right;
}

Rational operator - (Rational left, Rational const & right)
{
    return left -= right;
}

Rational operator * (Rational left, Rational const & right)
{
    return left *= right;
}

Rational operator / (Rational left, Rational const & right)
{
    return left /= right;
}


bool operator == (int number, Rational const & rational) 
{
    return (Rational(number) == rational);
}

bool operator != (int number, Rational const & rational) 
{
    return !(number == rational);
}

bool operator > (int number, Rational const & rational) 
{
    return (Rational(number) > rational);
}

bool operator <= (int number, Rational const & rational) 
{
    return !(number > rational);
}

bool operator < (int number, Rational const & rational) 
{
    return (Rational(number) < rational);
}

bool operator >= (int number, Rational const & rational) 
{
    return !(number < rational);
}