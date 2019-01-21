#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <random>
#include <cmath>

using namespace ::std;

/**
 * 
 * */

int main(){
    // 随机播种
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 6);
    for (int i = 0; i < 10;++i){
        cout << dis(gen) << " ";
    }
    cout << endl;
    return 0;
}