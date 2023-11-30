#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  size_t temp = 0;
  while (n != 0)
  {
    cout << (n & 1) << endl;
    n = n >> 1;
  }
  return 0;
}