// prime.cpp

using namespace std;

#include "cmpt_error.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>

bool is_prime(int n) {
    if (n < 2) return false;       // 2 is the smallest prime
    if (n == 2) return true;       // 2 is the only even prime
    if (n % 2 == 0) return false;  // all other even numbers are not prime
    
    // Next we generate trial divisors, d, starting with 3. We increment d by
    // 2 each time because we know by this point in the function that n is
    // odd, and so there is no need to see if it is divisible by an even 
    // number.
    int d = 3; 
    while (d * d <= n) {
        if (n % d == 0) return false;
        d += 2;
    }
    return true;
}

int num_primes_less_than(int n) {
	int num_primes = 0;
	for(int i = 1; i < n; i++) {
		if (is_prime(i)) num_primes++;
	}
	return num_primes;
}

void is_prime_test() {
	vector<int> some_primes = {2, 3, 5, 7, 11, 23, 31, 101, 103};
	vector<int> some_non_primes = {-1, 0, 1, 4, 6, 8, 9, 10, 26, 169};
	for(int p : some_primes) assert(is_prime(p));
	for(int c : some_non_primes) assert(!is_prime(c));
	assert(num_primes_less_than(1000000) == 78498);
	cout << "all is_prime tests passed\n";
}

void is_prime_time() {
	clock_t start = clock();

	const int max_num = 10000000;  // 10 million
	int num_primes = num_primes_less_than(max_num);

	clock_t end = clock();
	clock_t duration = end - start;
	double dur_secs = duration / (double) CLOCKS_PER_SEC;
	cout << "Time to find all " << num_primes << " primes less than " << max_num
	     << ": " << dur_secs << "s\n";
}

int main() {
	is_prime_test();
	is_prime_time();
}
