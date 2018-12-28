/**
 * 霍纳规则：
 * 用于求值多项式：P(x)=a0+x(a1+x(a2+..+x(an-1+xan)...))
 * 
 * */

int horner(int A[], int x, int n){
    int y=0;
    for(int i=0;i<n;++i){
        y=A[i]+x*y;
    }
    return y;
}

int fun(int A[], int x, int n){
    int y=0;
    int Y[n];
    for(int i=0;i<n;++i){
        Y[i]=0;
        for(int j=0;j<n;++j){
            Y[i]=Y[i]*x;
        }
        y=y+A[i]*Y[i];
    }
    return y;
}

int main(){

    return 0;
}