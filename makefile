
<!-- saved from url=(0075)https://raw.github.com/gpdowning/cs378/master/projects/collatz/makefile.c++ -->
<html><head><meta http-equiv="Content-Type" content="text/html; charset=UTF-8"><style type="text/css"></style></head><body><pre style="word-wrap: break-word; white-space: pre-wrap;">all:
	make run
	make test

diff: RunCollatz
	RunCollatz &lt; RunCollatz.in &gt; RunCollatz.tmp
	diff RunCollatz.out RunCollatz.tmp
	rm RunCollatz.tmp

doc:
	doxygen Doxyfile

log:
	git log &gt; Collatz.log

RunCollatz: Collatz.h Collatz.c++ RunCollatz.c++
	g++ -pedantic -std=c++0x -Wall Collatz.c++ RunCollatz.c++ -o RunCollatz

run: RunCollatz
	RunCollatz &lt; RunCollatz.in

runv: RunCollatz
	valgrind RunCollatz &lt; RunCollatz.in

TestCollatz: Collatz.h Collatz.c++ TestCollatz.c++
	g++ -pedantic -std=c++0x -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz -lcppunit -ldl

test: TestCollatz
	TestCollatz

testv: TestCollatz
	valgrind TestCollatz

turnin-list:
	turnin --list tmtorres cs378pj1

turnin-submit:
	turnin --submit tmtorres cs378pj1 Collatz.zip

turnin-verify:
	turnin --verify tmtorres cs378pj1

zip:
	zip -r Collatz.zip html/ makefile           \
	Collatz.c++ Collatz.h Collatz.log           \
	RunCollatz.c++ RunCollatz.in RunCollatz.out \
	SphereCollatz.c++                           \
	TestCollatz.c++ TestCollatz.out

clean:
	rm -f RunCollatz
	rm -f TestCollatz
	rm -f *.tmp
</pre></body></html>