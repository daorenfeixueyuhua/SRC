#include <iostream>
#include <string>

using namespace::std;

int main(){
    string number;
    int cnt;
    cin >> number >> cnt;
    for(int i=0;i<cnt&&number.empty()==0;i++){
        for(int j=i;j<number.length();j++){
            if(number[i]<number[j]){
                number.erase(i);
                break;
            }
        }
    }
    return 0;
}