#include "../include/MathUtil.h"
#include "../include/DivideByZeroException.h"
#include "../include/DomainException.h"
#include "../include/SyntaxException.h"
#include <cmath>

MathUtil::MathUtil()
{
}

MathUtil::~MathUtil()
{

}

//unary operators
double MathUtil::unaryNegation(double operand)
{
    return -1*operand;
}

long long MathUtil::factorial(int n)
{
    if(n<0)
    {
        throw DomainException("Domain Error: negative operand");
    }
    else if(n>20)
        throw DomainException("Domain Error: operand > 20");

    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

double MathUtil::percent(double value)
{
    return value * .01;
}

//binary operators
double MathUtil::add(double left, double right)
{
    return left + right;
}

double MathUtil::subtract(double left, double right)
{
    return left - right;
}

double MathUtil::multiply(double left, double right)
{
    return left * right;
}

double MathUtil::divide(double left, double right)
{
    if(right == 0)
        throw DivideByZeroException("Divide By 0 Error");
    return left / right;
}

double MathUtil::power(double left, double right)
{
    if(left == 0 && right == 0)
    {
        throw DomainException("Domain Error: x and y are 0");
    }
    //if right is not integer and left is negative
    else if((right - floor(right) != 0) && left <0)
    {
        throw DomainException("Domain Error: non-integer and negative operands");
    }

    return pow(left, right);
}

double MathUtil::scientificNotation(double mantissa, double exponent)
{
    if(exponent - floor(exponent) != 0)
        throw SyntaxException("Syntax Error: invalid exponent");
    return mantissa*(pow(10, exponent));
}

double MathUtil::mod(double left, double right)
{
    return fmod(left, right);
}

//trig functions
double MathUtil::sineInDegrees(double angle)
{
    double degreesResult = 0;
    double degrees = angle;

    if(degrees < 0 || degrees > 360)
        degrees = wrapDegrees0To360(degrees);

    if(degrees == 0)
        degreesResult = 0;
    else if(degrees == 90)
        degreesResult = 1;
    else if(degrees == 180)
        degreesResult = 0;
    else if(degrees == 270)
        degreesResult = -1;
    else if(degrees == 360)
        degreesResult = 0;
    else
        degreesResult = sin(degrees*M_PI/180.0);

    return degreesResult;
}

double MathUtil::cosineInDegrees(double angle)
{
    double degreesResult = 0;
    double degrees = angle;

    if(degrees < 0 || degrees > 360)
        degrees = wrapDegrees0To360(degrees);

    if(degrees == 0)
        degreesResult = 1;
    else if(degrees == 90)
        degreesResult = 0;
    else if(degrees == 180)
        degreesResult = -1;
    else if(degrees == 270)
        degreesResult = 0;
    else if(degrees == 360)
        degreesResult = 1;
    else
        degreesResult = cos(degrees*M_PI/180.0);

    return degreesResult;
}

double MathUtil::tangentInDegrees(double angle)
{
    double degreesResult = 0;

    double degrees = angle;

    if(angle > 360 || angle < 0)
        wrapDegrees0To360(angle);

    if(degrees == 0 || mod(degrees, 360) == 0)
        degreesResult = 0;
    else if(degrees == 90 || mod(degrees, 360) == 90)
        throw DomainException("Domain Error");
    else if(degrees == 180 || mod(degrees, 360) == 180)
        degreesResult = 0;
    else if(degrees == 270 || mod(degrees, 360) == 270)
        throw DomainException("Domain Error");
    else if(degrees == 360 || mod(degrees, 360) == 0)
        degreesResult = 0;
    else if(degrees == -90 || mod(degrees, 360) == -90)
        throw DomainException("Domain Error");
    else if(degrees == -180 || mod(degrees, 360) == -180)
        degreesResult = 0;
    else if(degrees == -270 || mod(degrees, 360) == -270)
        throw DomainException("Domain Error");
    else
        degreesResult = tan(degrees*M_PI/180.0);

    return degreesResult;
}

double MathUtil::sineInRadians(double angle)
{
    double radianResult = 0;
    double radians = angle;

    if(radians > 2*M_PI || radians < 0)
        radians = wrapRadians0To2PI(angle);

    if(radians == 0)
        radianResult = 0;
    else if(radians == M_PI/2)
        radianResult = 1;
    else if(radians == M_PI)
        radianResult = 0;
    else if(radians == 3*M_PI/2)
        radianResult = -1;
    else if(radians == 2*M_PI)
        radianResult = 0;
    else
        radianResult = sin(radians);

    return radianResult;
}

double MathUtil::cosineInRadians(double angle)
{
    double radianResult = 0;
    double radians = angle;

    if(radians > 2*M_PI || radians < 0)
        radians = wrapRadians0To2PI(angle);

    if(radians == 0)
        radianResult = 1;
    else if(radians == M_PI/2)
        radianResult = 0;
    else if(radians == M_PI)
        radianResult = -1;
    else if(radians == 3*M_PI/2)
        radianResult = 0;
    else if(radians == 2*M_PI)
        radianResult = 1;
    else
        radianResult = cos(radians);

    return radianResult;
}

double MathUtil::tangentInRadians(double radianValue)
{
    double radianResult = tan(radianValue);

    return radianResult;
}

double MathUtil::asine(double radianValue)
{
    double radianResult =  asin(radianValue);

    return radianResult;
}

double MathUtil::acosine(double radianValue)
{
    double radianResult =  acos(radianValue);

    return radianResult;
}

double MathUtil::atangent(double radianValue)
{
    double radianResult =  atan(radianValue);

    return radianResult;
}

//basic functions
double MathUtil::log(double value)
{
    if(value <= 0)
        throw DomainException("Domain Error: argument is 0 or negative");

    return log10(value);
}

double MathUtil::ln(double value)
{
    if(value <= 0)
        throw DomainException("Domain Error: argument is 0 or negative");
    return std::log(value);
}

double MathUtil::squareRoot(double value)
{
    if(value < 0)
        throw DomainException("Domain Error: argument is negative");
    return sqrt(value);
}

double MathUtil::exponent(double value)
{
    return exp(value);
}

double MathUtil::abs(double value)
{
    return std::abs(value);
}

double MathUtil::wrapDegrees0To360(double degrees)
{
    double angle = fmod(degrees, 360);

    if(angle < 0)
        angle+=360;

    return angle;
}

double MathUtil::wrapRadians0To2PI(double radians)
{
    double twoPI = 2.0*M_PI;
    return radians - twoPI*floor(radians/twoPI);
}
