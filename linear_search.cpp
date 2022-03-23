#include <iostream>
using namespace std;

int LinearSearch(int A[], int N, int key) {
    int i = 0;

    while(i < N) {
        if (A[i] == key)
            return i;

        i++;
    }

    if (i >= N)
        return -1;
}

int main() {

    int A[] = {5, 6, 10, 2, 1, 7, 8, 12};

    int number = 10;

    int index = LinearSearch(A, 8, number);

    cout << "Index: " << index << endl;

    return 0;
}