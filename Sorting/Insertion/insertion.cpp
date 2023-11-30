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

  for (int i = 1; i < n; i++)
  {
    int value = arr[i];
    int j = i - 1;
    while (j >= 0 &&  arr[j] > value)
    {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = value;
  }

  cout << "print after sort" << endl;
  print(arr);

  return 0;
}
