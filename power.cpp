#include <iostream>
using namespace std;

#if 0

// complexity = O(N) time
int Power(int a, int n) {
    int power = 1;
    while (n > 0) {
        power *= a;
        n--;
    }
    return power;
}
#else

// Complexity: O(logN) time
// if n is even then power operation of x^n can be divided as x^(n/2) * x^(n/2)
// if n is odd then power operation of x^n can be divided as x * x^(n/2) * x^(n/2)
// The O(logN) time approach use the above instructions
int Power(int a, int n) {
    int power = 1;
    int currentPow = a;
    while (n > 0) {
        // if n is odd multiply the result by currentPow
        //if(n & 1) power *= currentPow;
        //if(n & 0x1) power *= currentPow;
        if(n % 2 == 1) power *= currentPow;

        currentPow *= currentPow;

        // divide n by 2
        n >>= 1;    // n = n/2
    }
    return power;
    //return currentPow;
}

#endif

int main() {

    int power = Power(5, 4);

    cout<<"Power: "<<power<<endl;

    return 0;
}