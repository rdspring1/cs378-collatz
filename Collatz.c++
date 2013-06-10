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
    return true;
}

// ------------
// cycle
// ------------

/**
 * @param n - current integer
 * @return the cycle length of the integer n
 */
int cycle(int num) 
{
	int count = 1;	
	while(num != 1) 
	{
		if((num % 2) == 0) 
		{ // n is even
			num = num / 2;
			
		} 
		else 
		{ // n is odd
			num = 3 * num + 1;
		}
		
		count++;
	}	
	return count;
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
	assert(i > 0);
	assert(j > 0);
	int max = 1;
	int count = 1;

	if (i > j) 
	{
		for (int n = i; n >= j; n--) 
		{
			count = cycle(n);

			if (count > max) 
			{
				max = count;
			}
		}
	} 
	else if (i < j) 
	{
		for (int n = i; n < j; n++) 
		{
			count = cycle(n);

			if (count > max) 
			{
				max = count;
			}
		}
	} 
	else 
	{
		// When the integers i and j are equal, then the max cycle length is
		// the cycle length of integer i
		max = cycle(i);
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