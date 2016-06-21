
#include <iostream>
#include <stdlib.h> 
#include <time.h>

using namespace std;

const int n=100;

int A[n][n];
int B[n][n];
int C[n][n];

void generar_matriz()
{
    int number;
    srand (time(NULL));
    for(int i=0;i<n;++i)
        {
            for(int j=0;j<n;++j)
            {
                number=rand()% 30 +1;
                A[i][j]=number;
                B[i][j]=number+3;
            }
        }
}

void multiplicacion_matriz()
{
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            C[i][j]=0;

    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            for(int k=0;k<n;++k)
            {
                C[i][j]+=AA[i][k]*BB[k][j];
            }
}

void imprimir_matriz()
{
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cout<<C[i][j]<<endl;
}

int main (){
    generar_matriz();
    multiplicacion_matriz();
    imprimir_matriz();
    return 0;
}

