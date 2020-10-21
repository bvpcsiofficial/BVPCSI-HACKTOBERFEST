//Program for constructing new data points within a range of a discrete set of given data point,
// the lagrange interpolation technique is used.

#include <iostream>
#define maxN 4
using namespace std;

double lagrange_interpolation(double x[], double fx[], double x1)
{
  double res = 0, tempSums = 0;

  for (int i = 1; i <= maxN; i++)
  {
    double tempProd = 1; //for each iteration initialize temp product
    for (int j = 1; j <= maxN; j++)
    {
      if (i != j)
      {                                          //if i = j, then denominator will be 0
        tempProd *= (x1 - x[j]) / (x[i] - x[j]); //multiply each term using formula
      }
    }
    tempProd *= fx[i]; //multiply f(xi)
    res += tempProd;
  }
  return res;
}

main()
{
  double x[maxN + 1] = {0, 1, 3,4, 7};
  double y[maxN + 1] = {1, 3, 49, 129, 813};
  double x1 = 0.3;
  cout << "Result after lagrange interpolation f(" << x1 << ") = " << lagrange_interpolation(x, y, x1);
}