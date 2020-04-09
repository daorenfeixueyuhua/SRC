#include <stdio.h>
#include <random>
#include <iostream>
#include <fstream>

const int MAX = 1e6;

using namespace std;
int main(){

    fstream fout("data.txt", ios::out);

    for (int i = 0; i < MAX;i++){
        fout << rand() << " ";
    }
    fout.close();
    return 0;
}