 #include <iostream>
 #include <cmath>
 using namespace::std;
  
 //��x��n�η� 
 int m(int x,int n){
 	if(n==0)	return 1;
 	else return n*m(x,n);
 }
 
 int f(int x,int n){
 	if(n==1)	return x;
 	else return int(pow(double(-1),n-1)*pow(double(x),n))+f(x,n-1);
 }
 int main(){
 	int x,n;
 	cin >> x >> n;
 	cout << f(x,n) << endl;
 	return 0;
 }

 
 
