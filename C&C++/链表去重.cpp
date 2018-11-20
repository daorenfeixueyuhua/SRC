 #include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace::std;
template<typename T>
class Node
{
public:
	string frio;
	T date;
	string next;
	friend istream& operator >> (istream&, Node&);
	friend ostream& operator << (ostream&, Node&);
};

istream& operator>>(istream& in, Node<int>& l)
{
	in >> l.frio >> l.date >> l.next;
	return in;
}

ostream& operator<<(ostream& out, Node<int>& l)
{
	out << l.frio << " " << l.date << " " << l.next;
	return out;
}
int main()
{
	int N; int start;
	cin >> start >> N;
	vector<Node<int>> lists(N);
	for (int i = 0; i < N; ++i)
		cin >> lists[i];

	return 0;
}

