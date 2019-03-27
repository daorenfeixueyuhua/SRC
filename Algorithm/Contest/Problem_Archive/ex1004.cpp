// Let the Balloon Rise
#include <iostream>
#include <map>
#include <string>
using namespace ::std;
int main(){
    int n;
    while(cin>>n&&n){
        map<string, int> map;
        for (int i = 0; i < n;++i){
            string s;
            cin >> s;
            // if(map.find(s)==map.end){
                // map.insert(pair<string, int>(s, 1));
            // }else{
                map.insert(pair<string, int>(s, map.find(s) + 1));
            // }
        }
       for(auto p:map){
           cout << p.first << " " << p.second << endl;
       }
    }
    return 0;
}