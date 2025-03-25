#include <iostream>

using namespace std;
template <typename T>
T SumTowNumber(T a, T b)
{
  return a + b;
}

template <class T>
class Calculator
{

  T a, b;

public:
  Calculator(T a, T b)
  {
    this->a = a;
    this->b = b;
  }
  T AddTwoNumber()
  {
    return a + b;
  }
};
int main()
{
  // cout << "Sum :" << SumTowNumber(22.2, 22.2);
  Calculator<int>  intnum (1,1);
  cout<< intnum.AddTwoNumber();
  return 0;
}