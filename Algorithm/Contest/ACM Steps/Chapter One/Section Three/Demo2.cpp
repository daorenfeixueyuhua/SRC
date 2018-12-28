#include <bits/stdc++.h>
using namespace::std;
class Arrow{
public:
    int cnt;    // 箭个数
    int length; // 箭身长
    string s;
    Arrow(){
        cnt=0;
        length=0;
    }
    Arrow(int _length, int _cnt){
        cnt = _cnt;
        length = _length;
        // s[0]='>';
        s.push_back('>');
        // s[1]='+';
        s.push_back('+');
        for(int i=2;i<=length-1;++i)
            s.push_back('-');
        s.push_back('+');
        s.push_back('>');
    }

    void show(){
        for(int i=0;i<cnt;++i){
            cout << s << endl;
        }
    }
};

bool cmp(const Arrow &a, const Arrow &b){
    return a.length<b.length;
}
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        Arrow *A = new Arrow[n];
        for(int i=0;i<n;i++){
            int length, cnt;
            cin >> length >> cnt;
            Arrow a(length, cnt);
            A[i]=a;
        }
        sort(A, A+n, cmp);
        for(int i=0;i<n;i++){
            A[i].show();
            cout << endl;
        }
    }
    return 0;
}
