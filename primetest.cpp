// primetest.cpp

using namespace std;

#include "prime.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>

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
	cout << "Time to find all " << num_primes << " less than " << max_num
	     << ": " << dur_secs << "s\n";
}

int main() {
	is_prime_test();
	is_prime_time();
}
