
<!-- saved from url=(0074)https://raw.github.com/gpdowning/cs378/master/projects/collatz/Collatz.c++ -->
<html><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8"><style type="text/css"></style></head><body><pre style="word-wrap: break-word; white-space: pre-wrap;">// ----------------------------
// projects/collatz/Collatz.c++
// Copyright (C) 2013
// Glenn P. Downing
// ----------------------------

// --------
// includes
// --------

#include &lt;cassert&gt;  // assert
#include &lt;iostream&gt; // endl, istream, ostream

#include "Collatz.h"

// ------------
// collatz_read
// ------------

bool collatz_read (std::istream&amp; r, int&amp; i, int&amp; j) {
    r &gt;&gt; i;
    if (!r)
        return false;
    r &gt;&gt; j;
    assert(i &gt; 0);
    assert(j &gt; 0);
    return true;}

// ------------
// collatz_eval
// ------------

int collatz_eval (int i, int j) {
    assert(i &gt; 0);
    assert(j &gt; 0);
    // &lt;your code&gt;
    int v = 1;
    assert(v &gt; 0);
    return v;}

// -------------
// collatz_print
// -------------

void collatz_print (std::ostream&amp; w, int i, int j, int v) {
    assert(i &gt; 0);
    assert(j &gt; 0);
    assert(v &gt; 0);
    w &lt;&lt; i &lt;&lt; " " &lt;&lt; j &lt;&lt; " " &lt;&lt; v &lt;&lt; std::endl;}

// -------------
// collatz_solve
// -------------

void collatz_solve (std::istream&amp; r, std::ostream&amp; w) {
    int i;
    int j;
    while (collatz_read(r, i, j)) {
        const int v = collatz_eval(i, j);
        collatz_print(w, i, j, v);}}
</pre></body></html>