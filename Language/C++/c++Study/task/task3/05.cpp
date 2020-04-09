#include <iostream>
using namespace std;
template <class T>
class Complex
{
  private:
    T a, b;

  public:
    Complex(T _a, T _b) : a(_a), b(_b) {}
    void display()
    {
        cout << a;
        if (b > 0)
            cout << "+" << b;
        else
            cout << b;
        cout << "i" << endl;
    }
};

int main()
{
    Complex<int> c1(1, 2);
    Complex<double> c2(1.0, -2.0);
    cout << "c1 is : ";
    c1.display();
    cout << "c2 is : ";
    c2.display();

    cin.get();
    cin.get();
    return 0;
}