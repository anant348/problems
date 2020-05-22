#include <bits/stdc++.h>
using namespace std;

bool isPossWithAtleastX(vector<int> &a, int x, int noOfCow)
{
  int lastIndex = 0;
  int count = noOfCow - 1;
  for (int i = 1; i < a.size() && count > 0; i++)
  {
    if (a[i] - a[lastIndex] >= x)
    {
      lastIndex = i;
      count--;
    }
  }
  return (count == 0);
}

int maxDistance(vector<int> &a, int noCow)
{
  sort(a.begin(), a.end());
  long long int hi = a[a.size() - 1] - a[0];
  long long int lo = a[1] - a[0];
  while (lo < hi)
  {
    int mid = (lo + hi) / 2;
    bool p = isPossWithAtleastX(a, mid, noCow);
    if (p)
      lo = mid + 1;
    else
      hi = mid;
  }
  return lo - 1;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    cout << maxDistance(a, c) << endl;
  }
}