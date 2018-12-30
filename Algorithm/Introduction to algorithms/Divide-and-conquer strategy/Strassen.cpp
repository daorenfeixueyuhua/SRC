#include <iostream>
#include <cstdio>
using namespace ::std;
const int length = 100;

void square_marteix_multipy(int A[length][length], int B[length][length], int C[length][length])
{
    int i, j, k;
    for (i = 0; i < length; ++i)
    {
        for (j = 0; j < length; ++j)
        {
            for (int k = 0; k < length; ++k)
            {
                C[i][j] += C[i][j] + A[i][k] * B[k][j];
            }
        }
    }
}

int main()
{
    int A[length][length] = {0}, B[length][length] = {0};
    int C[length][length] = {0};
    for (int i = 0; i < length;++i){
        for (int j = 0; j < length;++j){
            A[i][j] = i + j;
            B[i][j] = i + j;
        }
    }
    printf("start\n");
    square_marteix_multipy(A, B, C);
    printf("end\n");
    return 0;
}