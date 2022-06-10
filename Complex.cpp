#include<iostream>
#include<cmath>
#include<string>
#include"Complex.h"
using namespace std;

Complex::Complex() :real(0), imaginary(0) {};
Complex::Complex(int x) :real(x), imaginary(0) {};//构造函数们
Complex::Complex(float x) :real(x), imaginary(0) {};//后面不能带默认参数，否则会出现多义性
Complex::Complex(double x) :real(x), imaginary(0) {};
Complex::Complex(int x , int y ) :real(x), imaginary(y) {};
Complex::Complex(int x , float y ) :real(x), imaginary(y) {};
Complex::Complex(int x , double y ) :real(x), imaginary(y) {};
Complex::Complex(float x , int y ) :real(x), imaginary(y) {};
Complex::Complex(float x , float y ) :real(x), imaginary(y) {};
Complex::Complex(float x , double y ) :real(x), imaginary(y) {};
Complex::Complex(double x , int y ) :real(x), imaginary(y) {};
Complex::Complex(double x , float y ) :real(x), imaginary(y) {};
Complex::Complex(double x , double y ) :real(x), imaginary(y) {};

Complex::Complex(const Complex& z):real(z.real),imaginary(z.imaginary){}

Complex::~Complex(){}

double Complex::Norm()
{
    return sqrt(real*real+imaginary*imaginary);
}

Complex Complex::operator-()const
{
    return Complex(-real, -imaginary);
}

Complex Complex::operator+(const Complex& z)const
{
    return Complex(real+z.real,imaginary+z.imaginary);
}

Complex Complex::operator-(const Complex& z)const
{
    return Complex(real-z.real,imaginary-z.imaginary);
}

Complex Complex::operator*(const Complex& z)const
{
    return Complex(real*z.real-imaginary*z.imaginary,real*z.imaginary+imaginary*z.real);
}

Complex Complex::operator/(const Complex& z)const
{
    try
    {
        if (z.real == 0 && z.imaginary == 0)
        {
            throw "Divided by zero!\n";
        }
    }
    catch (const char* s)
    {
        std::cout << s;
    }
    double norm2 = z.real * z.real + z.imaginary * z.imaginary;
    return Complex((real * z.real + imaginary * z.imaginary) / norm2, (imaginary * z.real - real * z.imaginary) / norm2);
}

Complex& Complex::operator+=(const Complex& z)
{
    real += z.real;
    imaginary += z.imaginary;
    return *this;
}

Complex& Complex::operator-=(const Complex& z)
{
    real -= z.real;
    imaginary -= z.imaginary;
    return *this;
}

Complex& Complex::operator*=(const Complex& z)
{
    double x = real * z.real - imaginary * z.imaginary;
    double y = real * z.imaginary + imaginary * z.real;
    real = x;
    imaginary = y;
    return *this;
}

Complex& Complex::operator/=(const Complex& z)
{
    try
    {
        if (z.real == 0 && z.imaginary == 0)
        {
            throw "Divided by zero!\n";
        }
    }
    catch (const char* s)
    {
        std::cout << s;
    }
    double norm2 = z.real * z.real + z.imaginary * z.imaginary;
    double x = (real * z.real + imaginary * z.imaginary) / norm2;
    double y = (imaginary * z.real - real * z.imaginary) / norm2;
    real = x;
    imaginary = y;
    return *this;
}

Complex& Complex::operator=(const Complex& z)
{
    real = z.real;
    imaginary = z.imaginary;
    return *this;
}
bool Complex::operator==(const Complex& z)const
{
    return (real == z.real) && (imaginary == z.imaginary);
}
bool Complex::operator!=(const Complex& z)const
{
    return (real != z.real) || (imaginary != z.imaginary);
}
template <typename T>
Complex Complex::operator+(const T& x)const
{
    return Complex(real + x, imaginary);
}

template <typename T>
Complex Complex::operator-(const T& x)const
{
    return Complex(real - x, imaginary);
}

template <typename T>
Complex Complex::operator*(const T& x)const
{
    return Complex(real * x, imaginary * x);
}

template <typename T>
Complex Complex::operator/(const T& x)const
{
    try
    {
        if (x== 0)
        {
            throw "Divided by zero!\n";
        }
    }
    catch (const char* s)
    {
        std::cout << s;
    }
    return Complex(real / x, imaginary / x);
}

template <typename T>
Complex& Complex::operator+=(const T& x)
{
    real += x;
    return *this;
}

template <typename T>
Complex& Complex::operator-=(const T& x)
{
    real -= x;
    return *this;
}

template <typename T>
Complex& Complex::operator*=(const T& x)
{
    real *= x;
    imaginary *= x;
    return *this;
}

template <typename T>
Complex& Complex::operator/=(const T& x)
{
    real /= x;
    imaginary /= x;
    return *this;
}

template <typename T>
Complex& Complex::operator=(const T& x)
{
    real = x;
    return *this;
}

template <typename T>
bool Complex::operator==(const T& x)const//判断实数
{
    return (imaginary == 0) && (real == x);
}
template <typename T>
bool Complex::operator!=(const T& x)const//判断不等于实数
{
    return (imaginary != 0) || (real != x);
}
template Complex Complex::operator+<int>(const int&)const;//显式实例化 T=int
template Complex Complex::operator-<int>(const int&)const;
template Complex Complex::operator*<int>(const int&)const;
template Complex Complex::operator/<int>(const int&)const;
template Complex& Complex::operator+=<int>(const int&);
template Complex& Complex::operator-=<int>(const int&);
template Complex& Complex::operator*=<int>(const int&);
template Complex& Complex::operator/=<int>(const int&);
template Complex& Complex::operator=<int>(const int&);
template bool Complex::operator==<int>(const int&)const;
template bool Complex::operator!=<int>(const int&)const;

template Complex Complex::operator+<float>(const float&)const;//显式实例化 T=float
template Complex Complex::operator-<float>(const float&)const;
template Complex Complex::operator*<float>(const float&)const;
template Complex Complex::operator/<float>(const float&)const;
template Complex& Complex::operator+=<float>(const float&);
template Complex& Complex::operator-=<float>(const float&);
template Complex& Complex::operator*=<float>(const float&);
template Complex& Complex::operator/=<float>(const float&);
template Complex& Complex::operator=<float>(const float&);
template bool Complex::operator==<float>(const float&)const;
template bool Complex::operator!=<float>(const float&)const;

template Complex Complex::operator+<double>(const double&)const;//显式实例化 T=double
template Complex Complex::operator-<double>(const double&)const;
template Complex Complex::operator*<double>(const double&)const;
template Complex Complex::operator/<double>(const double&)const;
template Complex& Complex::operator+=<double>(const double&);
template Complex& Complex::operator-=<double>(const double&);
template Complex& Complex::operator*=<double>(const double&);
template Complex& Complex::operator/=<double>(const double&);
template Complex& Complex::operator=<double>(const double&);
template bool Complex::operator==<double>(const double&)const;
template bool Complex::operator!=<double>(const double&)const;

Complex Complex::Conjugate()const
{
    return Complex(real,-imaginary);
}
Complex::operator double()
{
    return Norm();
}

ostream& operator<<(ostream& os,const Complex& z)//重载<<输出
{
    if(z.real == 0 && z.imaginary == 0)
    {
        os << "0";
        return os;
    }
    if(z.real!=0)
    {
        os << z.real;
    }
    if(z.imaginary!=0)
    {
        if(z.imaginary > 0 && z.real != 0) os << "+";
        if (z.imaginary == -1) os << "-";
        else if (z.imaginary != 1) os << z.imaginary;
        os << "i";
    }
    return os;
}
istream& operator>>(istream& is, Complex& z)//重载>>输入，要求格式为 a+bi (a和'+'可以省略，b可以为1)
{
    string s;
    char c;
    c = is.get();
    while (c == '\n') c = is.get();
    while (c != ' ' && c != '\n')
    {
        s += c;
        c = is.get();
    }
    int pos = s.find('i');//判断i是否存在
    if (pos == s.npos)//不存在i,即为纯实数
    {
        z.real = stod(s);
        z.imaginary = 0;
        return is;
    }
    //存在i，输入中存在虚部 (i必须写在虚部的结尾)
    int sgnpos = 0;//找到虚部前符号位置
    int sgn = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] == '+')
        {
            sgnpos = i;
            sgn = 1;
        }
        if (s[i] == '-')
        {
            sgnpos = i;
            sgn = -1;
        }
    }
    if (sgnpos == 0)//第二位起没有发现符号，则为纯虚数
    {
        if (s[0] == '-')//首位为负号
        {
            if (s[1] == 'i')//输入了-i
            {
                z.imaginary = -1;
            }
            else z.imaginary = -stod(s.substr(1));//从第1位开始获取数字
        }
        else if (s[0] == 'i')//单个字符i 即只输入了i
        {
            z.imaginary = 1;
        }
        else
        {
            z.imaginary = stod(s);
        }
        z.real = 0;//实部位0
    }
    else
    {
        z.real = stod(s.substr(0, sgnpos));
        if (s[sgnpos + 1] == 'i')//符号位后是i，则虚部系数为1，乘上符号
        {
            z.imaginary = sgn;
        }
        else z.imaginary = sgn * stod(s.substr(sgnpos + 1));
    }
    return is;
}