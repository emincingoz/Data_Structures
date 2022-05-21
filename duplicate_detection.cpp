#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

#if 0

// O(N^2) algorithm
bool CheckDuplicate(int A[], int N) {

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            if (A[i] == A[j]) {
                return true;
            }
        }
    }

    return false;
}

#elif 0

int partition(vector<int>& A, int start, int end) {

    int pivot = A[end];
    int count = 0;

    int i = start - 1;

    for (int j = start; j <= end - 1; j++) {

        if (A[j] <= pivot) {
            i++;

            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    }

    int temp = A[i + 1];
    A[i + 1] = A[end];
    A[end] = temp;

    return (i + 1);
}

// O(NlogN) algorithm for sorting
void QuickSort(vector<int>& A, int start, int end) {

    // Base Case
    if (start > end)
        return;

    // Partition the array
    int pivot = partition(A, start, end);

    // Sorting the left part
    QuickSort(A, start, pivot - 1);

    // Sorting the right part
    QuickSort(A, pivot + 1, end);
}

// O(N + NlogN) => O(N) Algorithm
bool CheckDuplicate(vector<int>& A) {
    
    // Array must be sorted
    QuickSort(A, 0, A.size() - 1);

    // Sort the array in O(NlogN) time
    //sort(A.begin(), A.end());    // inside algorithm library

    for (int i = 0; i < A.size(); i++) {
        cout<<A[i] <<"\t";
    }

    cout<<endl<<endl;

    for (int i = 0; i < A.size() - 1; i++) {
        if(A[i] == A[i + 1])
            return true;
    }

    return false;
}

#else

// O(N) algorithm but requires extra spaces O(N)
bool CheckDuplicate(vector<int>& A) {

    // HashSet
    unordered_set<int> S;

    for (int i = 0; i < A.size(); i++) {

        if (S.find(A[i]) != S.end())
            return true;

        S.insert(A[i]);
    }

    return false;
}

#endif

int main() {

    vector<int> A{4, 2, 7, 10, 6, 9, 7};

    bool flag = CheckDuplicate(A);

    cout<<flag<<endl;



    return 0;
}