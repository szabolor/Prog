/* 
 * 2014 Google Code Jam - Qualification Round
 * Problem B
 * https://code.google.com/codejam/contest/2974486/dashboard#s=p1
*/ 

#include <iostream>
#include <iomanip>

using namespace std;

enum {
  MAX_CACHE = 100000
};

int main() {
  int count = 0, cases;
  cout << fixed << setprecision(7);

  cin >> cases;
  while (count < cases) {
    double cache[MAX_CACHE] = {0};
    double c, f, x;
    
    cin >> c >> f >> x;
    int k = (int) (x / c - 2 / f);
    k = k < 0 ? 0 : k;
    
    // prepare sum(c/(2+i*f),{i,0,k-1})
    cache[0] = c / 2;
    for (int i=0; i<k; i++)
      cache[i+1] = cache[i] + c / (2.0  + (i+1) * f);

    double result;
    if (k > 0)
      result = cache[k-1] + (x / (2 + k * f));
    else
      result = (x / (2 + k * f));

    cout << "Case #" << ++count << ": " << result << endl;
  }

  return 0;
}
