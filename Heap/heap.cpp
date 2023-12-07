#include <bits/stdc++.h>
using namespace std;

void print(int arr[], int _size)
{
  for (int i = 0; i < _size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int leftPosition(int idx)
{
  return 2 * idx + 1;
}
int rightPosition(int idx)
{
  return 2 * idx + 2;
}

void maxHeapify(int arr[], int _size, int currentPosition)
{
  int left = leftPosition(currentPosition);
  int right = rightPosition(currentPosition);
  int currentMax = currentPosition;

  if (left < _size && arr[left] > arr[currentMax])
  {
    currentMax = left;
  }
  if (right < _size && arr[right] > arr[currentMax])
  {
    currentMax = right;
  }

  if (currentMax != currentPosition)
  {
    swap(arr[currentMax], arr[currentPosition]);
    maxHeapify(arr, _size, currentMax);
  }
}
void buildHeap(int arr[], int _size)
{

  for (int i = _size / 2; i >= 0; i--)
  {
    maxHeapify(arr, _size, i);
  }
}

void heapSort(int arr[], int _size)
{
  buildHeap(arr, _size);
  int n = _size;
  while (n != 0)
  {
    swap(arr[--n], arr[0]);
    maxHeapify(arr, n, 0);
  }
}

int main()
{
  freopen("input.txt", "r", stdin);
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int _size=sizeof(arr) / sizeof(int);
  cout << "print input element" << endl;
  print(arr, _size);
  heapSort(arr, sizeof(arr) / sizeof(int));
  cout << "print sorted" << endl;
  print(arr, _size);
  return 0;
}
