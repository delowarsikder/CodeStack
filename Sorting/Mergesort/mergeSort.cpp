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
  for (ll i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void merge(vector<ll> &arr, ll left, ll mid, ll right)
{
  int i = left, j = mid + 1;
  vector<ll> tempArr;
  while (i <= mid && j < right)
  {
    if (arr[i] < arr[j])
    {
      tempArr.pb(arr[i]);
      i++;
    }
    else
    {
      tempArr.pb(arr[j]);
      j++;
    }
  }
  while (i <= mid)
  {
    tempArr.pb(arr[i]);
    i++;
  }
  while (j < right)
  {
    tempArr.pb(arr[j]);
    j++;
  }
  for(int i=left;i<right;i++){
    arr[i]=tempArr[i-left];
  }
}

void mergeSort(vector<ll> &arr, ll left, ll right)
{
  if (left >= right)
  {
    return;
  }
  ll mid = left + (right - left) / 2;
  mergeSort(arr, left, mid);
  mergeSort(arr, mid + 1, right);
  merge(arr, left, mid, right);
}

int main()
{
  FASTIO;
  freopen("input.txt", "r", stdin);
  ll n, temp;
  vector<ll> arr;
  cin >> n;
  for (ll i = 0; i < n; i++)
  {
    cin >> temp;
    arr.pb(temp);
  }
  cout << "Print before sort " << endl;
  print(arr);

  // merge sort
  mergeSort(arr, 0, arr.size());

  cout << "print after sort" << endl;
  print(arr);

  return 0;
}
