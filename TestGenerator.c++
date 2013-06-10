// --------
// includes
// --------

#include <iostream> // cin, cout, ios_base
#include <stdlib.h>
#include <time.h>

int main ()
{
  using namespace std;
  ios_base::sync_with_stdio(false); // turn off synchronization with C I/O

  int i, j;
  int range = 100;

  /* initialize random seed: */
  srand ( time(NULL) );

  for(int n = 0; n < 1000; n++) {
	  /* generate a random number between 1 and 1000000 */
	  i = rand() % range + 1;
	  j = rand() % range + 1;
	  
	  // Vary the range of the random number generator
	  // range - Max Value created by the generator	
	  range += 100;
	  cout <<  i << " " << j << std::endl;
  }

  return 0;	
}
