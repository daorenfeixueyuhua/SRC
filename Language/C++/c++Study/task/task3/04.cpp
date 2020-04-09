#include <iostream>

using namespace std;

class Time;
class Date
{
  private:
    int month;
    int day;
    int year;

  public:
    friend Time;
    Date(int, int, int);
    // void display(Time &);
};
class Time
{
  private:
    int hour;
    int minute;
    int sec;

  public:
    Time(int, int, int);
    void display(Date &);
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

void Time::display(Date &d)
{
    cout << d.month << "/" << d.day << "/" << d.year << endl;
    cout << hour << ":" << minute << ":" << sec << endl;
}
int main()
{
    Time t(10, 23, 26);
    Date d(12, 25, 2004);
    t.display(d);
    cin.get();
    cin.get();
    return 0;
}