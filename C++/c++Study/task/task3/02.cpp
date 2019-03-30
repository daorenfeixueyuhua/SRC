#include <iostream>
using namespace std;

/**
 * 商店销售某一商品，商店每天公布统一的折扣（discount）。
 * 同时允许销售人员在销售时灵活掌握售价（price），
 * 在此基础上，对一次购10件以上者，还可以销售98折优待。
 * 现已知当天3个销售员销售情况为：
 * 
 * 请编写程序，计算出当日此商品的总销售款sum以及每件商品的平均售价
 * 。要求：用静态数据成员和静态成员函数实现。
提示：将折扣discount，总销售款sum和商品销售总件数n，
声明为静态数据成员，再定义静态成员函数average（
求平均售价）和display（输出结果）。

 * */
class market
{
  private:
    static int discount;
    static int sum;
    static int n;
    int quantity;
    int price;

  public:
    static void average();
    static void display();
    void buy(int quantity, int price)
    {
    }
};
int main()
{

    return 0;
}