// prime.cpp

#include "prime.h"
#include "cmpt_error.h"
#include <cmath>
#include <vector>

using namespace std;

// returns biggest integer d such that d*d <= n
int isqrt(int n) {
	if (n < 0) cmpt::error("isqrt: arg can't negative");
	return int(sqrt(n));
}

// returns all the trial divisors of n
vector<int> trial_divisors(int n) {
	if (n < 2) {
		return vector<int>{};
	} else {
		vector<int> divs{2};
		for(int d = 3; d*d <= n; d++) {
			divs.push_back(d);
		}
		return divs;
	}
}

bool is_prime(int n) {
    if (n < 2) return false;       // 2 is the smallest prime
    if (n == 2) return true;       // 2 is the only even prime
    for(int d : trial_divisors(n)) {
    	if (n % d == 0) return false;
    }
    return true;
}

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
