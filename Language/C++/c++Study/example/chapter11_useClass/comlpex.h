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
	// 重载+运算符
	comlpex operator+(const comlpex & c);
	// 重载-运算符
	comlpex operator-(const comlpex & c);
	// 重载*运算符
	comlpex operator*(const comlpex & c);
	// 重载*运算符
	comlpex operator*(const double & v);
	// 重载*运算符
	friend comlpex operator*(const double & v,comlpex & c);
	// 重载/运算符
	comlpex operator/(const comlpex & c);
	// 重载~运算符
	comlpex operator~();
	~comlpex();
};

