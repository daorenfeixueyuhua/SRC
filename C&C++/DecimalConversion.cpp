#include <iostream>
#include <stack>
//����ת������ʮ����ת��Ϊ�˽��� 
using namespace::std;
int main(){
	stack<int> stack;
	int n,e;
	while(cin>>n&&n!=-1){
		e=-1;
		while(n){
			stack.push(n%8);
			n=n/8;
		}
		while(!stack.empty()){
			e=stack.top();
			stack.pop();
			cout << e;
		}
		cout << endl;
	}
	return 0;
}
