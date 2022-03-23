#include <iostream>
using namespace std;

///
/// To be able to implement Binary Search, the array must be sorted.
/// Algorithm complexity is O(logN)
/// 
int BinarySearch(int A[], int N, int key) {
    int left = 0;
    int right = N - 1;

    for(int i = 0; i < N; i++) {
        cout<<A[i]<<"\t";
    }

    cout<<endl<<endl;

    while (left <= right) {
        int middle = (left + right) / 2;

        if (A[middle] == key) return middle;
        else if (key < A[middle] ) right = middle - 1;
        else left = middle + 1;
    }
    return -1;
}

int main() {

    int A[] = {10, 20, 15, 3, 4, 8, 9, 74, 13, 34, 56, 13, 18, 2, 6};
    int N = 15;
    int key = 8;

    cout<<endl<<endl;

    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j < N - i - 1; j++) {
            if(A[j] > A[j + 1]) {
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

    int index = BinarySearch(A, N, key);

    cout << "index: "<< index<<endl;

    return 0;
}