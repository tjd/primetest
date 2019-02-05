// primetest.cpp

using namespace std;

#include "prime.h"
#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>

void is_prime_test() {
	vector<int> some_primes = {2, 3, 5, 7, 11, 23, 31, 37, 101, 103};
	vector<int> some_non_primes = {-1, 0, 1, 4, 6, 8, 9, 10, 26, 169};
	for(int n : some_primes) assert(is_prime(n));
	for(int n : some_non_primes) assert(!is_prime(n));
	assert(num_primes_less_than(1000000) == 78498);
	cout << "all is_prime tests passed\n";
}

void is_composite_test() {
	vector<int> some_composites = {4, 6, 8, 9, 10, 25, 26, 169};
	vector<int> some_non_composites = {-1, 0, 1, 2, 3, 5, 7, 11, 23, 31, 37, 101, 103};
	for(int n : some_composites) assert(is_composite(n));
	for(int n : some_non_composites) assert(!is_composite(n));
	cout << "all is_composite tests passed\n";
}

void is_prime_time() {
	cout << "Timing test for is_prime ...\n";
	clock_t start = clock();

	const int max_num = 10000000;  // 10 million
	int num_primes = num_primes_less_than(max_num);

	clock_t end = clock();
	clock_t duration = end - start;
	double dur_secs = duration / (double) CLOCKS_PER_SEC;
	cout << "  Time to find all " << num_primes << " less than " << max_num
	     << ": " << dur_secs << "s\n";
}

int main() {
	is_prime_test();
	is_composite_test();
	is_prime_time();
}
