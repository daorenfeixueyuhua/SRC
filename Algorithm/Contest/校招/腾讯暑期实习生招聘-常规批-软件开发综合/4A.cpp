#include <bits/stdc++.h>
using namespace std;

// const int MAXSIZE = 1e6 + 3;

class Stack {
public:
  int size = 0;
  int data[1000002] = {0};
  void push(int x) { data[size++] = x; }
  void pop() {
    data[size - 1] = -1;
    size--;
  }
  int top() { return data[size - 1]; }
};

class Queue {
public:
  // S1 保存数据， S2备份数据
  Stack S1, S2;
  void push(int x) { S1.push(x); }
  // 超时
  int front() {
    int ans = 0;
    // 将数据迁移到S2中
    while (S1.size != 1) {
      S2.push(S1.top());
      S1.pop();
    }
    ans = S1.top();
    // 将数据转回S1中
    while (S2.size) {
      S1.push(S2.top());
      S2.pop();
    }
    return ans;
  }
  void pop() {
    // 将数据迁移到S2中
    while (S1.size != 1) {
      S2.push(S1.top());
      S1.pop();
    }
    // 丢掉S1中最后一个元素
    S1.pop();
    // 将数据转回S1中
    while (S2.size) {
      S1.push(S2.top());
      S2.pop();
    }
  }
};

int main() {
  // cout << 111 << endl;
  Queue Q;
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string s;
    int x;
    cin >> s;
    if (s == "add") {
      cin >> x;
      Q.push(x);
    }
    if (s == "poll") {
      Q.pop();
    }
    if (s == "peek") {
      cout << Q.front() << endl;
    }
  }
  return 0;
}