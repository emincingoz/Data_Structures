#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;

#if 0

// O(N * M) algorithm
vector<int> SetIntersection(vector<int>& A, vector<int>& B) {

    vector<int> C;

    for (int i = 0; i < A.size(); i++) {
        for(int j = 0; j < B.size(); j++) {
            if(A[i] == B[j]) {
                C.push_back(A[i]);
            }
        }
    }

    return C;
}

#elif 0

// O(logN) algorithm
int BinarySearch(vector<int>& A, int key) {

    int left = 0;
    int right = A.size() - 1;

    while (left <= right) {
        int mid = (right + left) / 2;

        if(A[mid] == key)
            return mid;
        else if(A[mid] < key)
            left = mid + 1;
        else right = mid - 1;
    }

    return -1;
}

// O(NlogN + MlogM) algorithm
vector<int> SetIntersection(vector<int>& A, vector<int>& B) {

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    vector<int> C;

    for (int i = 0; i < A.size(); i++) {

        int num = BinarySearch(B, A[i]);
        if(num != -1)
            C.push_back(A[i]);
    }

    return C;
}

#else

// O(N + M) algorithm but requires extra space
vector<int> SetIntersection(vector<int>& A, vector<int>& B) {

    vector<int> C;

    unordered_set<int> S;

    for(int i = 0; i < A.size(); i++) {
        S.insert(A[i]);
    }
    for(int i = 0; i < B.size(); i++) {
        if (S.find(B[i]) != S.end()) 
            C.push_back(B[i]);
        S.insert(B[i]);
    }

    return C;
}

#endif

int main() {

    vector<int> A{4, 2, 5, 1, 9, 7, 15, 11};
    vector<int> B{1, 20, 7, 18, 5, 6};

    vector<int> C = SetIntersection(A, B);

    for (int i = 0; i < C.size(); i++) {

        cout<<C[i]<<"\t";
    }

    return 0;
}