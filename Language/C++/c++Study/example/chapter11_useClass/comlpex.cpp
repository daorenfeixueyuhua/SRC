#include "comlpex.h"



comlpex::comlpex()
{
}

comlpex::comlpex(const double _real, const double _imaginary)
	:real(_real),imaginary(_imaginary)
{
}

comlpex comlpex::operator+(const comlpex & c)
{
	real += c.real;
	imaginary += c.imaginary;
	// 返回调用对象本身
	return *this;
}

comlpex comlpex::operator-(const comlpex & c)
{
	real -= c.real;
	imaginary -= c.imaginary;
	return *this;
}

comlpex comlpex::operator*(const comlpex & c)
{
	comlpex tmp;
	tmp.real = real * c.real - imaginary * c.imaginary;
	tmp.imaginary = real * c.imaginary + imaginary * c.real;
	// 返回tmp的拷贝
	return tmp;
}

comlpex comlpex::operator*(const double & v)
{
	real *= v;
	imaginary *= v;
	return *this;
}


comlpex comlpex::operator/(const comlpex & c)
{
	return *this;
}

comlpex comlpex::operator~()
{
	imaginary = 0 - imaginary;
	return *this;
}

comlpex::~comlpex()
{
}

std::ostream & operator<<(std::ostream & os, const comlpex & c)
{
	os << "(" << c.real << "," << c.imaginary << "i)";
	return os;
}

std::istream & operator>>(std::istream & in, comlpex & c)
{
	std::cout << "real:";
	in >> c.real;
	std::cout << "imaginary:";
	in >> c.imaginary;
	return in;
}

comlpex operator*(const double & v, comlpex & c)
{
	return c.operator*(v);
}
