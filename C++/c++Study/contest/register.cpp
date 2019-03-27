#include <iostream>
#include <vector>

const int MAX = 8;
using namespace std;


class Register{
private:
    int * v;
public:
    Register();
    Register(const int);
    // 析构函数
    ~Register();
    // 重载 << 运算符
    friend ostream& operator<<(ostream&, Register&);
    // 重载 >> 运算符
    friend istream& operator>>(istream&, Register&);
    // 重载 << 左移移运算符
    Register& operator<<(const int n);
    // 重载 >> 右移运算符
    Register& operator>>(const int n);
    // 重载 ～ 运算符，取反操作
    Register& operator~();
    // 返回该寄存器内的原码表示
    Register getTureFrom();
    // 返回v对应的十进制
    int getValue();
};
Register::Register(){
    v = new int[MAX];
}
Register::Register(int n){
    v = new int[MAX];
    for(int i=MAX-1;i>=0;--i){         
        v[i] = n & 1;
        n >>= 1;
    }
}
Register::~Register(){
    delete[] v;
}
ostream& operator<<(ostream& os, Register& r){
    for(int i=0;i<MAX;++i)
        os << r.v[i];
    return os;
}
istream& operator>>(istream& in, Register& r){
    int n;
    in >> n;
    r.v = new int[MAX];
    for(int i=MAX-1;i>=0;--i){
        r.v[i] = n & 1;
        n >>= 1;
    }
    return in;
}

Register& Register::operator~(){
    for(int i=0;i<MAX;++i)
        v[i] = v[i]?0:1;
    return *this;
    
}


int Register::getValue(){
    //todo
}

int main(){
    Register r;
    cin >> r;
    cout << ~r << endl;
    return 0;
}