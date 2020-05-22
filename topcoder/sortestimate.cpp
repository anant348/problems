#include <bits/stdc++.h>
using namespace std;

class SortEstimate
{
private:
  long double log2(long double a)
  {
    return log(a) / log(2);
  }
  bool isSmaller(int time, int c, long double n)
  {
    return c * n * log2(n) < (long double)(time);
  }

public:
  double howMany(int c, int time)
  {
    long double lo = 0;
    long double hi = (long double)(2000000000.0);
    while (abs(lo - hi) > (long double)1e-9)
    {
      long double mid = (lo + hi) / 2;
      bool p = isSmaller(time, c, mid);
      if (p)
        lo = mid;
      else
        hi = mid;
    }
    printf("%lf\n", double(lo));
    return lo;
  }
};

int main()
{
  SortEstimate s;
  cout << s.howMany(1, 2000000000) << endl;
}