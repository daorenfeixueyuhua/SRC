#include <iostream>
#include <stack>
//进制转换：将十进制转换为八进制 
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
