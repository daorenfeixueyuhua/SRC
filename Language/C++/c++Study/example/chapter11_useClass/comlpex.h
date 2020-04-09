#pragma once
#include <iostream>
class comlpex
{
private:
	double real;
	double imaginary;
public:
	comlpex();
	comlpex(const double _real, const double _imaginary);
	friend std::ostream & operator<<(std::ostream & os, const comlpex & c);
	friend std::istream & operator>>(std::istream & in, comlpex & c);
	// ����+�����
	comlpex operator+(const comlpex & c);
	// ����-�����
	comlpex operator-(const comlpex & c);
	// ����*�����
	comlpex operator*(const comlpex & c);
	// ����*�����
	comlpex operator*(const double & v);
	// ����*�����
	friend comlpex operator*(const double & v,comlpex & c);
	// ����/�����
	comlpex operator/(const comlpex & c);
	// ����~�����
	comlpex operator~();
	~comlpex();
};

