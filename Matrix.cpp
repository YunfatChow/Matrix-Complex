#include<iostream>
#include<fstream>
#include<cmath>
#include<cstdio>
#include"Matrix.h"
using std::cout;
using std::cin;
Matrix::Matrix(int m, int n, int f) :m(m), n(n)
{
	if (m == 0 || n == 0)
	{
		element = NULL;
		return;
	}
	element = new Complex* [m + 1];
	element[0] = NULL;
	for (int i = 1; i <= m; i++) element[i] = new Complex[n + 1];
	if (f == 0 || f == 1)
	{
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				element[i][j] = 0;
			}
		}
		for (int i = 1; i <= m; i++) element[i][0] = NULL;//不用的指针置空
	}
	if (f == 1)
	{
		for (int i = 1; i <= m && i <= n; i++) element[i][i] = 1;
	}
	if (f == 2)
	{
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				cin >> element[i][j];
			}
		}
	}
}
Matrix::Matrix(const Matrix& A):m(A.m),n(A.n)
{
	element = new Complex* [m + 1];
	for (int i = 1; i <= m; i++) element[i] = new Complex[n + 1];
	element[0] = NULL;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			element[i][j] = A.element[i][j];
		}
	}
	for (int i = 1; i <= m; i++) element[i][0] = NULL;
}
Matrix::~Matrix()
{
	for (int i = 1; i <= m; i++) if (element[i]) delete[] element[i];
	if (element) delete[] element;
	element = NULL;
}
double Matrix::det()//用高斯消元为上三角矩阵后求出对角线元素乘积
{
	if(n!=m)
	{
		cout<<"只有方阵才能求行列式\n";
		return 0; 
	}
	Matrix B(*this);
	B.down_em();
	Complex d=1;
	for (int i = 1; i <= n; i++) d *= B.element[i][i];
	return d;
}
double Matrix::trace()//求出对角线元素和(迹)
{
	if (m != n)
	{
		cout << "只有方阵才有迹\n";
		return 0;
	}
	Complex t = 0;
	for (int i = 1; i <= n; i++) t += element[i][i];
	return t;
}
void Matrix::Scan()
{
	scanf_s("%d %d",&m,&n);
	element = new Complex * [m + 1];
	for (int i = 1; i <= m; i++) element[i] = new Complex[n + 1];
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cin >> element[i][j];
		}
	}
}
void Matrix::Print()
{
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cout << element[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void Matrix::row_exchange(int i,int j)//交换第i，j行
{
	for(int k=1;k<=n;k++)
	{
		std::swap(element[i][k],element[j][k]);
	}
} 
void Matrix::row_add(int i,int j,double k)//给第i行加上k倍的第j行
{
	for(int p=1;p<=n;p++)
	{
		element[i][p] += k * element[j][p];
	}
}
void Matrix::row_multiply(int i,double k)//给第i行数乘k
{
	for(int p=1;p<=n;p++)
	{
		element[i][p] *= k;
	}
}
void Matrix::row_add(int i, int j, Complex k)
{
	for (int p = 1; p <= n; p++)
	{
		element[i][p] += k * element[j][p];
	}
}
void Matrix::row_multiply(int i, Complex k)//给第i行数乘k
{
	for (int p = 1; p <= n; p++)
	{
		element[i][p] *= k;
	}
}
bool Matrix::NullRowCheck(int i)
{
	for(int j=1;j<=n;j++)
	{
		if (element[i][j] != 0) return false;
	}
	return true;
}
Matrix Matrix::Augement(Matrix B)//返回[A|B]的增广矩阵
{
	if(m!=B.m) return *this;//行数不相等不可增广
	Matrix C(m, B.n + n);
	for(int i=1;i<=m;i++)
	{
		for (int j = 1; j <= n; j++)
		{
			C.element[i][j] = element[i][j];
		}
		for(int j=n+1;j<=n+B.n;j++)
		{
			C.element[i][j]=B.element[i][j-B.n];
		}
	}
	return C;
}
void Matrix::down_em(int r)
{
	if (r >= m) return;
	if(element[r][r]==0)
	{
		int p=r;
		while (p <= m && element[p][r] == 0) p++;
		if(p>m) return ;
		row_exchange(r, p);
	}
	for(int i=r+1;i<=m;i++)//用第r行消去r+1至m行的第r个元素
	{
		Complex k = element[i][r] / element[r][r];
		row_add(i, r, -k);
	}
	down_em(r+1);
}
void Matrix::up_em(int r)//针对上三角矩阵 
{
	if (r == -1) r = m;
	if (r <= 1) return;
	while (element[r][r] == 0) r--;
	for(int i=1;i<=r-1;i++)//用第r行消去第1至c-1行的第r个元素
	{
		Complex k = element[i][r] / element[r][r];
		row_add(i,r,-k);
	}
	up_em(r-1);
}
Matrix inverse(Matrix A)
{
	if(A.m!=A.n)
	{
		cout << "只有方阵才存在逆矩阵\n";
		return A;
	}
	Matrix B(A.m, A.n, 1);
	A = A.Augement(B);
	A.down_em();
	for(int i=1;i<=A.m;i++)
	{
		if(A.element[i][i]==0)//消元后对角线上有0，则说明行列式为0
		{
			cout << "矩阵A不可逆\n";
			return B;//返回值为单位阵
		}
	}
	A.up_em();
	for(int i=1;i<=B.n;i++)
	{
		for(int j=1;j<=B.n;j++)
		{
			B.element[i][j] = A.element[i][j + B.n] / A.element[i][i];//取出消元后的矩阵B并单位化A 
		}
	}
	return B;
}
Matrix Matrix::operator+(const Matrix &B) const
{
	Matrix C(n,n,0);
	if(n!=B.n || m!=B.m)
	{
		cout<<"矩阵不同型不可相加\n";
		C.Print();
		return C;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			C.element[i][j]=element[i][j]+B.element[i][j];
		}
	}
	return C;
}
Matrix Matrix::operator*(const Matrix &B) const
{
	Matrix C(m,B.n);//C初始化为零矩阵 
	if(n!=B.m)
	{
		std::cout<<"该乘法不合法\n";
		return C;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=B.n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				C.element[i][j]+=element[i][k]*B.element[k][j];
			}
		}
	}
	return C;
}
Matrix Matrix::operator=(const Matrix& A)
{
	if (element != NULL)
	{
		for (int i = 1; i <= m; i++) if (element[i] != NULL) delete[] element[i];
		if (element) delete[] element;
	}
	m = A.m;
	n = A.n;
	element = new Complex* [m + 1];
	for (int i = 1; i <= m; i++) element[i] = new Complex[n + 1];
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			element[i][j] = A.element[i][j];
		}
	}
	return *this;
}
Complex& Matrix::operator()(int i,int j)
{
	try
	{
		if (i<1 || i>m || j<1 || j>n)
		{
			throw "Error:Index(i,j) out of range.\n";
		}
	}
	catch (const char* s)
	{
		std::cout << s;
	}
	return element[i][j];
}

Matrix Matrix::transpose()
{
	Matrix X;
	X.m=n;
	X.n=m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			X.element[i][j]=element[j][i];
		}
	}
	return X;
}
std::istream& operator>>(std::istream& fin,Matrix& A)
{
	A.Scan();
	return fin;
}
std::ostream& operator<<(std::ostream& fout,const Matrix& A)
{
	for (int i = 1; i <= A.m; i++)
	{
		for (int j = 1; j <= A.n; j++)
		{
			fout << A.element[i][j] << " ";
		}
		fout << "\n";
	}
	fout << "\n";
	return fout;
}
void SolveEquation(Matrix A)
{
	A.down_em();
	A.up_em();
	for (int i = 1; i <= A.m; i++)
	{
		if(A.element[i][i] != 0) A.row_multiply(i, 1/A.element[i][i]);
	}
	int j=A.m;
	for(int i=1;i<A.m && i<j;i++)//将零行移到最下方 
	{
		if(A.NullRowCheck(i))//第i行为零行 
		{
			A.row_exchange(i,j);
			j--;
		}
	}
	A.Print();
}