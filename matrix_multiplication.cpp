#include <iostream>
//#include <random>
using namespace std;

void MatrixMultiplication(int A[][5], int B[][5], int C[][5], int N) {
    
    //int C[5][5];

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            C[i][j] = 0;

            for(int k = 0; k < N; k++) {
                C[i][j] = A[i][k] * B[k][j];
            }
        }
    }
}

int main() {

    int A[5][5], B[5][5], C[5][5];

    int N = 5;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = rand() % 10;
            B[i][j] = rand() % 10;
            C[i][j] = 0;
        }
    }
    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout<<C[i][j]<<'\t';
        }
        cout<<endl;
    }

    MatrixMultiplication(A, B, C, 5);
    cout<<endl<<endl;

    for (int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cout<<C[i][j]<<'\t';
        }
        cout<<endl;
    }

    return 0;
}