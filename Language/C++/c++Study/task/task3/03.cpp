#include <iostream>

using namespace std;

class Date;
class Time
{
  private:
    int hour;
    int minute;
    int sec;

  public:
    Time(int, int, int);
    friend void display(Date &d, Time &t);
};
class Date
{
  private:
    int month;
    int day;
    int year;

  public:
    Date(int, int, int);
    friend void display(Date &d, Time &t);
};
Time::Time(int _hour, int _minute, int _sec)
{
    hour = _hour;
    minute = _minute;
    sec = _sec;
}
Date::Date(int _month, int _day, int _year)
{
    year = _year;
    month = _month;
    day = _day;
}

void display(Date &d, Time &t)
{
    cout << d.month << "/" << d.day << "/" << d.year << endl;
    cout << t.hour << ":" << t.minute << ":" << t.sec << endl;
}
int main()
{
    Time t(10, 23, 26);
    Date d(12, 25, 2004);
    display(d, t);
    cin.get();
    cin.get();
    return 0;
}