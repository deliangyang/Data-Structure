
#include <iostream>

using namespace std;

class A
{
  int value;
public:
  A(int n = 0) : value(n) {}
  int GetValue()
  {
    return value;
  }
  void SetValue(int n)
  {
    value = n;
  }
};
void f()
{
  A a;
  *((int *)&a) = 5;		// get a's address, and then stronge change to (int *), get value to assignment
}

int main(int argc, char *argv[])
{
	f();
	std::system("pause");
	return 0;
}
