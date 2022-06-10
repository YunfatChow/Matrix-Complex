#ifndef Matrix_H_
#define Matrix_H_
#include<iostream>
#include<fstream>
#include"Complex.h"
class Matrix
{
public:
	int n, m;
	Complex** element;
	Matrix(int = 0, int = 0, int = 0);//bool判断初始化类型，0为零矩阵，1为单位阵，2为输入矩阵
	Matrix(const Matrix&);
	~Matrix();
	void Scan();
	void Print();
	void row_exchange(int, int);//行交换
	void row_add(int, int, double);//给第i行加上第j行的k倍
	void row_multiply(int, double);//行乘法
	void row_add(int, int, Complex);
	void row_multiply(int, Complex);
	void down_em(int = 1);//向下消元 
	void up_em(int = -1);//向上消元
	Matrix Augement(Matrix);//增广矩阵
	double det();
	Complex& operator()(int, int);
	Matrix operator+(const Matrix&) const;
	Matrix operator*(const Matrix&) const;
	Matrix operator=(const Matrix&);
	Matrix transpose();
	bool NullRowCheck(int i);//检查第i行是否为零行
//	double* EigenValue();//求特征值 
	double trace();//求迹
};
std::istream& operator>>(std::istream&, Matrix&);
std::ostream& operator<<(std::ostream&, const Matrix&);
Matrix inverse(Matrix);
#endif // !Matrix_h
#pragma once
