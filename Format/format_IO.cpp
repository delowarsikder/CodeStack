#include <iostream>
#include <iomanip> //required for formatted printing
using namespace std;

int main()
{
  // Have a look at these tutorials:
  // http://faculty.cs.niu.edu/~mcmahon/CS241/c241man/node83.html
  // http://www.cprogramming.com/tutorial/iomanip.html

  //**Keep in mind that setw() only works for next print only, then resets but which is not the case for others

  cout << setw(5) << "12" << endl
       << "12" << endl; // First one is printed in 5 boxes but later on in 2 boxes

  cout << setfill('*') << setw(5) << "12" << endl
       << setw(3) << "12" << endl; // setfill works on both

  // printed values are right aligned by def so for left alignment use cout<<left

  /////////////PRINTING FIXED NO OF DIGITS AFER DECIMAL POINT
  float f = 13.141516;
  cout << setprecision(3); // Maybe we want 2 digits after decimal point
  cout << f << endl;       // Prints 13.1 instead of 13.142 because in general format (which is default) precision means no of total digits before and after decimal point

  // in fixed for setprecision denotes no of digits after decimal point
  cout << setiosflags(ios::fixed);
  cout << f; // now it prints 13.142
  /////////////PRINTING FIXED NO OF DIGITS AFER DECIMAL POINT

  return 0;
}
