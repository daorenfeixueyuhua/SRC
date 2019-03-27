// 按位运算符的使用
#include <iostream>
#include <bitset>

using namespace::std;
int main() {

	int v = 6;
	// 左移n位，相当于*2^n
	cout << v << " << 1 = " << (v << 1) << endl;
	// 有移n位，相当于/2^n
	cout << v << " >> 1 = " << (v >> 1) << endl;

	cout << "~" << v << " = " << (~v) << endl;
	cout << "v binary is: " << (new bitset<8>(v))->to_string() << endl;
	cout << "~v binary is: " << (new bitset<8>(v))->to_string() << endl;
	v = compl v bitand 7;
	
	// 常见按位运算技术
	unsigned int lottabits = 7;
	cout << "lottabits的二进制是：" << (new bitset<8>(lottabits))->to_string() << endl;
	cout << "打开lottabits的第3位：" << (new bitset<8>(lottabits | 8))->to_string() << endl;
	cout << "切换lottabits的第3位：" << (new bitset<8>(lottabits ^ 8))->to_string() << endl;
	cout << "关闭lottabits的第2位：" << (new bitset<8>(lottabits &~4))->to_string() << endl;
	cout << "测试lottabits的第3位：" << (new bitset<8>(lottabits & 8))->to_string() << endl;
	cout << "得到lottabits的第2位：" << (new bitset<8>(lottabits >> 2 & 1))->to_string() << endl;
	cin.get();
	cin.get();
	return 0;
}