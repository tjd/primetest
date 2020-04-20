// prime.cpp

#include "prime.h"

using namespace std;

//
// Returns true if n is a prime number, and false otherwise.
//
bool is_prime(int n) {
    if (n < 2) return false;       // 2 is the smallest prime
    if (n == 2) return true;       // 2 is the only even prime
    if (n % 2 == 0) return false;  // all other even numbers are not prime
    
    // Next we generate trial divisors, d, starting with 3. We increment d by
    // 2 each time because we know by this point in the function that n is
    // odd, and so there is no need to check even divisors.
    int d = 3; 
    while (d * d <= n) {
        if (n % d == 0) return false;
        d += 2;
    }
    return true;
}

//
// Returns true if n is a composite number, and false otherwise.
//
bool is_composite(int n) {
   return n > 1 && !is_prime(n);
}

int num_primes_less_than(int n) {
   int num_primes = 0;
   for(int i = 1; i < n; i++) {
      if (is_prime(i)) num_primes++;
   }
   return num_primes;
}
