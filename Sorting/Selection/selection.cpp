#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define FASTIO                      \
  ios_base::sync_with_stdio(false); \
  cin.tie(0);

#define discards_buffer cin.ignore(numeric_limits<streamsize>::max(), '\n')
#define MAX 1000005
#define MOD 10000007
#define endl '\n'

#define sc1(a) scanf("%lld", &a)
#define sc2(a, b) scanf("%lld %lld", &a, &b)
#define sc3(a, b, c) scanf("%lld %lld %lld", &a, &b, &c)

#define srt(v) sort(v.begin(), v.end())
#define rev(v) reverse(v.begin(), v.end())
#define pb(a) push_back(a)

typedef vector<ll> vii;
typedef pair<ll, ll> pll;

void print(vector<ll> arr)
{
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void Swap(ll *a, ll *b)
{
  ll temp = *a;
  *a = *b;
  *b = temp;
}

int main()
{
  freopen("input.txt", "r", stdin);
  ll n, temp;
  vector<ll> arr;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    cin >> temp;
    arr.pb(temp);
  }
  cout << "Print before sort " << endl;
  print(arr);

  for (int i = 0; i < n - 2; i++)
  {
    int iMin = i;
    for (int j = i + 1; j < n; j++)
    {
      if (arr[iMin] > arr[j])
      {
        iMin = j;
      }
    }
    Swap(&arr[i], &arr[iMin]); // swap current min vs assumption min
  }

  cout << "print after sort" << endl;
  print(arr);

  return 0;
}
