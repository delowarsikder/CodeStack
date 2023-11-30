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

ll partition(vector<ll> &arr, ll left, ll right)
{
  ll partitionIndex = left;
  ll pivot = arr[right];
  ll pivotIndex = right;

  for (ll i = left; i < right; i++)
  {
    if (arr[i] <= pivot)
    {
      swap(arr[i], arr[partitionIndex]);
      partitionIndex++;
    }
  }
  swap(arr[pivotIndex], arr[partitionIndex]);
  return partitionIndex;
}

void quickSort(vector<ll> &arr, ll left, ll right)
{
  if (left >= right)
  {
    return;
  }
  ll pivot = partition(arr, left, right);
  quickSort(arr, left, pivot - 1);
  quickSort(arr, pivot + 1, right);
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
  quickSort(arr, 0, arr.size() - 1);
  cout << "print after sort" << endl;
  print(arr);
  return 0;
}
