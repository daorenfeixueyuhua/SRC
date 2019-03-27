#include <random>
#include <fstream>

using namespace std;

int main()
{
    fstream fout("./data.in", ios::out);
    const int n = 10;
    fout << n << endl;
    for (int i = 0; i < n;++i)
    
        fout.close();
    return 0;
}