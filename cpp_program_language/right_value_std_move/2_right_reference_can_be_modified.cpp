#include <iostream>
using namespace std;

/* 
void f(const int& n) {
  n += 1; //编译错误
}
*/

void f2(int&& n) {
  n += 1;
}

int main() {
  //f(5);
  f2(5);
  int i = 5;
  f2(std::move(i));
  cout << i << endl; // 6
}
