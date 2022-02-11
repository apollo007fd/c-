#include <iostream>
using namespace std;

void f(std::string&& s) {
  s += " nba";
}

int main() {
  std::string s = "cba";
  f(std::move(s));
  cout << s << endl;
}
