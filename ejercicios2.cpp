#include <iostream>
#include <stdlib.h> 
#include <time.h>
using namespace std;

const int n=1000;
const int bloq_size=5;

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
   	double sum;
    int en = bloq_size * (n/bloq_size);

    for (int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            C[i][j]=0;

    for (int kk=0;kk<en;kk +=bloq_size){
    	for(int jj=0;jj<en;jj +=bloq_size){
    		for(int i=0;i<n;i++){
    			for(int j=jj;j<jj+bloq_size;j++){
    				sum = C[i][j];
    				for(int k=kk;k<kk+bloq_size;k++){
    					sum += A[i][k]*B[i][k];
    				}
    				C[i][j] = sum;
    			}
    		}
    	}
    }
}

void imprimir_matriz()
{
    for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
            cout<<C[i][j]<<endl;
}


int main(){
	generar_matriz();
	multiplicacion_matriz();
	imprimir_matriz();
	return 0;	
}
