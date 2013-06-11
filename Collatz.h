// --------------------------
// projects/collatz/Collatz.h
// Copyright (C) 2013
// Glenn P. Downing
// --------------------------

#ifndef Collatz_h
#define Collatz_h

// --------
// includes
// --------

#include <iostream> // istream, ostream

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
bool collatz_read (std::istream&, int&, int&);

// ------------
// collatz_eval
// ------------

/**
 * @param i the beginning of the range, inclusive
 * @param j the end       of the range, inclusive
 * @return the max cycle length in the range [i, j]
 */
int collatz_eval (int, int);

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
void collatz_print (std::ostream&, int, int, int);

// -------------
// collatz_solve
// -------------

/**
 * read, eval, print loop
 * @param r a std::istream
 * @param w a std::ostream
 */
void collatz_solve (std::istream&, std::ostream&);

// ------------
// cycle
// ------------

/**
 * @param cache - the cache storing the cycle lengths for the integers 1 through n inclusive. 
 * n is the upper-bound for the array and the largest integer stored in the array
 * @param size - size of the parameter, main_cache
 * @param n - current integer
 * @return the cycle length of the integer n
 */
int cycle(int [], int, int);

// ------------
// init_cache
// ------------

/**
 * @param cache - an array that will contain the precomputed cycle lengths for the integers 1 through n
 * @param size - size of the parameter, cache
 * n is the upper-bound for the array and the largest integer stored in the array
 * Initialize the cache for the value 1 through n
 */
void init_cache (int[], int);

#endif // Collatz_h
