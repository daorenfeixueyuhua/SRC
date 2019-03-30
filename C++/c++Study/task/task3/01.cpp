#include <iostream>
#include <string>
#include <array>

using namespace std;

class student
{
  public:
    string id;
    string name;
    double score;
    student(string _id, string _name, double _score) : id(_id), name(_name), score(_score) {}
};

student max(student *sp, int n)
{
    student max = sp[0];
    for (int i = 1; i < n; ++i)
        if (max.score < sp[i].score)
            max = sp[0];
    return max;
}

int main()
{
    student s[5] = {student("001", "pengda", 90.0),
                    {"002", "zhangshan", 80.1},
                    {"003", "lishi", 88.9},
                    {"004", "wanger", 78.7},
                    {"005", "mazi", 20.1}};
    student maxStudent = max(s, 5);
    cout << "the maxinum score is " << maxStudent.id << " he's name is : " << maxStudent.name << endl;
    cin.get();
    cin.get();
    return 0;
}