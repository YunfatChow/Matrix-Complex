#ifndef Complex_H_
#define Complex_H_ 
#include<iostream>
#include<fstream>
using namespace std;
class Complex{
public:
    double real,imaginary;
    Complex();
    Complex(int);//构造函数们
    Complex(float);
    Complex(double);
    Complex(int, int);
    Complex(int, float);
    Complex(int, double);
    Complex(float, int);
    Complex(float, float);
    Complex(float, double);
    Complex(double, int);
    Complex(double, float);
    Complex(double, double);

    
    Complex(const Complex&);
    ~Complex();
    double Norm();
    Complex operator-()const;
    Complex operator+(const Complex&)const;
    Complex operator-(const Complex&)const;
    Complex operator*(const Complex&)const;
    Complex operator/(const Complex&)const;
    Complex& operator+=(const Complex&);
    Complex& operator-=(const Complex&);
    Complex& operator*=(const Complex&);
    Complex& operator/=(const Complex&);
    Complex& operator=(const Complex&);
    bool operator==(const Complex&)const;
    bool operator!=(const Complex&)const;

    template <typename T> Complex operator+(const T&)const;//T模板重载int float double
    template <typename T> Complex operator-(const T&)const;
    template <typename T> Complex operator*(const T&)const;
    template <typename T> Complex operator/(const T&)const;
    template <typename T> Complex& operator+=(const T&);
    template <typename T> Complex& operator-=(const T&);
    template <typename T> Complex& operator*=(const T&);
    template <typename T> Complex& operator/=(const T&);
    template <typename T> Complex& operator=(const T&);
    template <typename T> bool operator==(const T&)const;
    template <typename T> bool operator!=(const T&)const;
    Complex Conjugate()const;
    operator double();
    friend ostream& operator<<(ostream&, const Complex&);
    friend istream& operator>>(istream&, Complex&);
};
#endif
#pragma once
