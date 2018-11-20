#include <iostream>
using namespace::std;

//[ride,size)
int hasMax(int n,int ride,int array[],int size){
	for(int i=ride+1;i<size;i++)
		if(n<array[i])
			return 1;
	return 0;
}
int isMax(int n,int ride,int array[],int size){
	for(int i=ride+1;i<size;i++)
		if(n<array[i])
			return 0;
	return 1;
}
int isMin(int n,int ride,int array[],int size){
	for(int i=ride+1;i<size;i++)
		if(n>array[i])
			return 0;
	return 1;
}
void case1(int n,int &money,int &times,int N[]){
	int has=0;
	for(int i=0;i<n;i++){
		//	cout << "momey" << money << " ";
		//	cout << N[i];
			if(isMin(N[i],i,N,n)&&i!=n-1&&has+1<=n-i-1){
				has++;
				money-=N[i];
				times++;
		//		cout << "-" << endl;
			}
			else if((has>0&&isMax(N[i],i,N,n))||has==n-i){
				has--;
				money+=N[i];
				times++;
		//		cout << "+" << endl;
			}
		//	else cout << endl;
		//	cout  << "has" << has << "times"<<times<< endl;
		}
}
void case2(int n,int &money,int &times,int N[]){
	int has=0;
	for(int i=0;i<n;i++){
	//		cout << "momey" << money << " ";
	//		cout << N[i];
			if(hasMax(N[i],i,N,n)&&i!=n-1&&has+1<=n-i-1){
				has++;
				money-=N[i];
				times++;
	//			cout << "-" << endl;
			}
			else if((has>0&&isMax(N[i],i,N,n))||has==n-i){
				has--;
				money+=N[i];
				times++;
	//			cout << "+" << endl;
			}
	//		else //cout << endl;
	//		cout  << "has" << has << "times"<<times<< endl;
		}
}
int main(){
	int T,n;
	int N[100000];
	cin >> T;
	while(T--){
		int money1=0,money2=0;
		int times1=0,times2=0;
		cin >> n;
		for(int i=0;i<n;i++)
			cin >> N[i];
		case1(n,money1,times1,N);
		case2(n,money2,times2,N);
		cout << money1 << " " << times1 << endl;
		cout << money2 << " " << times2 << endl;
		if(money1<money2){
			money1=money2;
			times1=times2;
		}
		cout << money1 << " " << times1 << endl;
	} 
	return 0;
} 
