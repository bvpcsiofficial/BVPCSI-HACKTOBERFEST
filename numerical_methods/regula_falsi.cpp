// C++ program for implementation of Regula Falsi for
// solving equations
#include <iostream>
using namespace std;
#define MAX 1000000

// An example function whose solution is determined using
// Regula Falsi Method. The function is x^3 - 2*x - 5
double func(double x)
{
  return x * x * x - 2 * x - 5;
}

// Prints root of func(x) in interval [a, b]
void regulaFalsi(double a, double b)
{
  if (func(a) * func(b) >= 0)
  {
    cout << "a & b values are wrongly decided";
    return;
  }

  double result = a; // Initialize result

  for (int i = 0; i < MAX; i++)
  {
    // Find the point that touches x axis
    result = (a * func(b) - b * func(a)) / (func(b) - func(a));

    // Check if the above found point is root
    if (func(result) == 0)
      break;

    // Decide the side to repeat the steps
    else if (func(result) * func(a) < 0)
      b = result;
    else
      a = result;
  }
  cout << "The value of root is : " << result;
}

// Driver program to test above function
int main()
{
  // Initial values assumed
  double a = 2, b = 3;
  regulaFalsi(a, b);
  return 0;
}
