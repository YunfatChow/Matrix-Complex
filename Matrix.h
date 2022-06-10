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
	Matrix(int = 0, int = 0, int = 0);//bool�жϳ�ʼ�����ͣ�0Ϊ�����1Ϊ��λ��2Ϊ�������
	Matrix(const Matrix&);
	~Matrix();
	void Scan();
	void Print();
	void row_exchange(int, int);//�н���
	void row_add(int, int, double);//����i�м��ϵ�j�е�k��
	void row_multiply(int, double);//�г˷�
	void row_add(int, int, Complex);
	void row_multiply(int, Complex);
	void down_em(int = 1);//������Ԫ 
	void up_em(int = -1);//������Ԫ
	Matrix Augement(Matrix);//�������
	double det();
	Complex& operator()(int, int);
	Matrix operator+(const Matrix&) const;
	Matrix operator*(const Matrix&) const;
	Matrix operator=(const Matrix&);
	Matrix transpose();
	bool NullRowCheck(int i);//����i���Ƿ�Ϊ����
//	double* EigenValue();//������ֵ 
	double trace();//��
};
std::istream& operator>>(std::istream&, Matrix&);
std::ostream& operator<<(std::ostream&, const Matrix&);
Matrix inverse(Matrix);
#endif // !Matrix_h
#pragma once
