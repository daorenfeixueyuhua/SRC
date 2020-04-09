#include <iostream>
#include <string>
using namespace std;
class Salesman
{
public:
  static double average();
  static void display();
  Salesman(string, int, double);

public:
  static double discount;
  static double sum;
  static int n;

private:
  string num;
  int quantity;
  double price;
};

double Salesman::discount = 0.98;
double Salesman::sum = 0.0;
int Salesman::n = 0;

Salesman::Salesman(string _num, int _quantity, double _price)
{
  num = _num;
  quantity = _quantity;
  price = _price;
  if (quantity >= 10)
  {
    sum += quantity * discount * price;
  }
  else
  {
    sum += quantity * price;
  }
  n += quantity;
}

double Salesman::average()
{
  return sum / n;
}

void Salesman::display()
{
  cout << "n is : " << n << endl;
  cout << "sum is : " << sum << endl;
  cout << "average is : " << average() << endl;
}
int main()
{

  Salesman s[3] = {
      Salesman("101", 5, 23.5),
      Salesman("102", 12, 24.56),
      Salesman("103", 100, 21.5)};
  Salesman::display();
  cin.get();
  cin.get();
  return 0;
}