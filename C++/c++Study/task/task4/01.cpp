#include <iostream>
#include <complex>
#include <algorithm>
#include <numeric>
using namespace std;
template <typename T>
class Complex
{
private:
    // 实部
    T real;
    // 虚部
    T imaginary;

public:
    // 无参构造函数
    Complex();
    // 有参构造函数
    Complex(T _real, T _imaginary);
    // 重载>>运算符
    friend istream &operator>>(istream &in, Complex<T> &c);
    // 重载<<运算符
    friend ostream &operator<<(ostream &out, const Complex<T> &c);
    // 重载+运算符
    Complex<T> operator+(const Complex &other);
    // 重载-运算符
    Complex<T> operator-(const Complex &other);
    // 重载*运算符
    Complex<T> operator*(const Complex &other);
    // 重载/运算符
    Complex<T> operator/(const Complex &other);
    // 重载+=运算符
    Complex<T> operator+=(const Complex &other);
    // 重载-=运算符
    Complex<T> operator-=(const Complex &other);
    // 重载*=运算符
    Complex<T> operator*=(const Complex &other);
    // 重载/=运算符
    Complex<T> operator/=(const Complex &other);
};

int main()
{
    Complex<int> c1(1, 2), c2(2, 3);
    cin >> c1 >> c2;
    cout << c1 + c2 << endl;
    
    return 0;
}
template <typename T>
istream &operator>>(istream &in, Complex<T> &c)
{
    cin >> c.real >> c.imaginary;
    return in;
}

template <typename T>
ostream &operator<<(ostream &out, const Complex<T> &c)
{
    out << c.real;
    if (c.imaginary < 0)
    {
        out << " - " << abs(c.imaginary) << "i";
    }
    else if (c.imaginary == 0)
    {
    }
    else
    {
        out << " + " << c.imaginary << "i";
    }
    return out;
}

template <typename T>
Complex<T>::Complex()
{
    real = 0;
    imaginary = 0;
}

template <typename T>
Complex<T>::Complex(T _real, T _imaginary)
{
    real = _real;
    imaginary = _imaginary;
}

template <typename T>
Complex<T> Complex<T>::operator+(const Complex &other)
{
    Complex<T> t;
    t.real = real + other.real;
    t.imaginary = imaginary + other.imaginary;
    return t;
}

template <typename T>
Complex<T> Complex<T>::operator-(const Complex &other)
{
    Complex<T> t;
    t.real = real - other.real;
    t.imaginary = imaginary - other.imaginary;
    return t;
}

template <typename T>
Complex<T> Complex<T>::operator*(const Complex &other)
{
    // TODO 待完成
    return Complex<T>();
}

template <typename T>
Complex<T> Complex<T>::operator/(const Complex &other)
{
    return Complex<T>();
}
