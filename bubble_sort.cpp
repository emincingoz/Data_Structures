#include <iostream>
using namespace std;

void BubbleSort(int A[], int N) {

#if 0
    for(int i = 0; i < N - 1; i++) {
        for(int j = i + 1; j < N; j++) {
            if(A[i] > A[j]) {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
#else
    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j < N - i - 1; j++) {
            if(A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
#endif
    cout<<"Sorted Array"<<endl;

    for(int i = 0; i < N; i++) {
        cout<<A[i]<<"\t";
    }
}

int main() {

    int A[] = {5, 13, 24, 2, 6, 78, 1, 7, 9, 11, 2, 6, 5, 9, 3};
    int N = 15;

    for(int i = 0; i < N; i++) {
        cout<<A[i]<<"\t";
    }
    cout<<endl<<endl;

    BubbleSort(A, N);


    return 0;
}