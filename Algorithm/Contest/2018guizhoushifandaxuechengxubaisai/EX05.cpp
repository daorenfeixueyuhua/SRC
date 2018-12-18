#include <bits/stdc++.h>
#define PI	3.1415926535897932384626433832795
using namespace::std;
int main(){
	int t,n,x;
	double R;
	cin >> t;
	while(t--){
		cin >> n >> x;
		R=pow(n,PI);
		cout << fixed << setprecision(x) << R << endl;
	}
	return 0;
}
