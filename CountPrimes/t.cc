#include <iostream>

using namespace std;

class Solution {
public:
     bool *primes;
    int countPrimes(int n) {
          primes = new bool[n];
    int count = 0;
    for(int i = 0; i < n; ++i) {
      primes[i] = true;
    }   
    primes[0] = false;
    for (int i = 0; i < n; ++i) {
      if (!primes[i]) {
        continue;
      }   
      if (isPrime(i+1)) {
        for (int j = 2; j * (i + 1) <= n; ++j) {
          primes[j*(i+1) - 1] = false;
        }   
      } else {
        primes[i] = false;
      }   
    }   
    for (int i = 0; i < n - 1; ++i) {
      if (primes[i]) {
        ++count;
      }   
    }   
    delete[] primes;
    return count;
  }

   bool isPrime(int n) {
    return primes[n-1];
  }

};
int main() {
  Solution s;
  cout << s.countPrimes(100) << endl;
}
