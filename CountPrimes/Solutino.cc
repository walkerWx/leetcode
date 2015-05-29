#include <iostream>

using namespace std;

class Solution {
public:
  int countPrimes(int n) {
    bool primes[n];
    int count = 0;
    for(int i = 0; i < n; ++i) {
      primes[i] = true;
    }
    for (int i = 0; i < n; ++i) {
      if (!primes[i]) {
        continue;
      }
      if (isPrime(i+1)) {
        for (int j = 2; j * (i + 1) <= n; ++j) {
          cout << "we find " << j * (i + 1) << " is not a prime" << endl;
          primes[j*(i+1) - 1] = false;
        }
      } else {
        primes[i] = false;
      }
    }
    for (int i = 0; i < n; ++i) {
      if (primes[i]) {
        ++count;
      }
    }
    return count;
  }

  static bool isPrime(int n) {
    if (n == 1) {
      return false;
    }
    for (int i = 2; i * i <= n; ++i) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  int n;
  Solution s;
  cin >> n;
  cout << s.countPrimes(n) << endl;
}
