#include <iostream>
using namespace std;

#if 0

// O(N) algorithm for primality test
bool isPrime(int a) {
    if(a < 1) return false;
    if(a == 1) return false;
    //if(a == 2) return true;

    for(int i = 2; i < a; i++) {
        if(a % i == 0)
            return false;
    }

    return true;
}

#else

// O(sqrt(N)) algorithm for primality test
bool isPrime(int a) {
    if(a < 1) return false;
    if(a == 1) return false;

    int x = 2;
    while(x * x <= a) {
        if(a % x == 0)
            return false;
        x++;
    }
    return true;
}

#endif

int main() {

    int number = 7;

    bool flag = isPrime(number);

    cout<<number<<" is "<<(flag ? "prime" : "nonprime")<<endl;

    return 0;
}