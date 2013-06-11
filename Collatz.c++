// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include <cassert>  // assert
#include <iostream> // endl, istream, ostream

#include "Collatz.h"

// ------------
// collatz_read
// ------------

/**
 * reads two ints into i and j
 * @param r a  std::istream
 * @param i an int by reference
 * @param j an int by reference
 * @return true if that succeeds, false otherwise
 */
bool collatz_read (std::istream& r, int& i, int& j) 
{
    r >> i;
    if (!r)
        return false;
    r >> j;
    assert(i > 0);
    assert(j > 0);
	assert(i < 1000001);
    assert(j < 1000001);
    return true;
}

// ------------
// cycle
// ------------

/**
 * @param cache - an eager cache of cycle lengths
 * @param n - current integer
 * @return the cycle length of the integer n
 */
int cycle(int cache [], int n) 
{
	int count = 0;
	int size = sizeof(cache);
	int cache_value = 0;

	if(n < size) {
		cache_value = cache[n];
	}

	while(cache_value == 0) {
		if((n % 2) == 0) { // n is even
			n = n / 2;
		
		} else { // n is odd
			n = n + (n >> 1) + 1;
			count++;
		}
		count++;
		
		// Check overflow conditions - n is between 1 and cache size
		if(n > 0) {
			// Attempt to find if current n is present in the cache
			if(n < size) {
				cache_value = cache[n];
			}
		} else {
			return n;
		}
	}
	return cache_value + count;
}

// ------------
// init_cache
// ------------

/**
 * @param cache - a reference to the cache array
 * Initialize the cache for the value 1 through 100000
 */
void init_cache (int cache []) 
{
	int size = sizeof(cache);
	cache[1] = 1;
	
	for(int i = 2; i < size; i++) {
		int count = 0;
		int values[100] = {0};
		int num = i;
		values[count] = num;
		count++;

		int cache_value = cache[num];
		
		while(cache_value == 0) {
			if((num % 2) == 0) { // n is even
				num = num / 2;
		
			} else { // n is odd
				num = 3 * num + 1;
			}
		
			if(num < size) {
				cache_value = cache[num];
			}

			values[count] = num;
			count++;
		}

		// Fill In Cache Operation
		for(int i = 0; i < count; i++) {
			if(values[i] < size) {
				cache[values[i]] = count + cache_value - i - 1;
			}
		}
	}
}

// ------------
// collatz_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length in the range [i, j]
 */
int collatz_eval (int i, int j) {
	// Assert that the input values are within valid ranges
	assert(i > 0);
	assert(j > 0);
	assert(i < 1000001);
	assert(j < 1000001);
	int max = 1;
	int count = 1;
	int main_cache [501] = { 0 };
	init_cache(main_cache);

	if (i > j) {
		int m = i / 2;
		// If j <= m, then max_cycle_length(j, i) = max_cycle_length(m, i)
		// Reduce amount of computation for the program
		if(j <= m) {
			for (int n = m; n < i; n++) {
				count = cycle(main_cache, n);

				if (count > max) {
					max = count;
				}
			}
		} else {
			for (int n = i; n >= j; n--) {
				count = cycle(main_cache, n);

				if (count > max) {
					max = count;
				}
			}
		}
	} else if (i < j) {
		int m = j / 2;
		// If i <= m, then max_cycle_length(i, j) = max_cycle_length(m, j)
		// Reduce amount of computation for the program
		if(i <= m) {
			for (int n = m; n < j; n++) {
				count = cycle(main_cache, n);

				if (count > max) {
					max = count;
				}
			}
		} else {
			for (int n = i; n < j; n++) {
				count = cycle(main_cache, n);

				if (count > max) {
					max = count;
				}
			}
		}
	} else {
		// When the integers i and j are equal, then the max cycle length is
		// the cycle length of integer i
		max = cycle(main_cache, i);
	}


	if(max == 0) {
		max = i + j;
	}

	assert(max > 0);
	return max;	
}

// -------------
// collatz_print
// -------------

/**
 * prints the values of i, j, and v
 * @param w a std::ostream
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @param v the max cycle length
 */
void collatz_print (std::ostream& w, int i, int j, int v) 
{
    assert(i > 0);
    assert(j > 0);
    assert(v > 0);
    w << i << " " << j << " " << v << std::endl;
}

// -------------
// collatz_solve
// -------------

/**
 * read, eval, print loop
 * @param r a std::istream
 * @param w a std::ostream
 */
void collatz_solve (std::istream& r, std::ostream& w) 
{
    int i;
    int j;
    while (collatz_read(r, i, j)) 
	{
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);
	}
}