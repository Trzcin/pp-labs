#include <iostream>
#include <ostream>
using namespace std;

void shape1();
void shape2();
void shape3();
void print_many_chars(char c, int count, bool newLn);

int main() {
  shape1();
  cout << "\n" << "\n";
  shape2();
  cout << "\n" << "\n";
  shape3();
}

void shape1() {
  for (int i = 0; i < 3; i++) {
    cout << "./\\." << '\n';
    cout << "/..\\" << '\n';
    cout << "\\../" << '\n';
    cout << ".\\/." << '\n';
  }
}

void shape2() {
  print_many_chars('*', 16, true);
  cout << "*\\.*./*\\.*./*\\.*" << "\n";
  cout << "*.\\*/.*.\\*/.*.\\*" << "\n";
  print_many_chars('*', 16, true);
  cout << "*./*\\.*./*\\.*./*" << "\n";
  cout << "*/.*.\\*/.*.\\*/.*" << "\n";
  print_many_chars('*', 16, true);
}

void shape3() {
  print_many_chars('*', 16, true);
  for (int i=0; i<2; i++) {
    cout << '*';
    print_many_chars('.', 14, false);
    cout << '*' << "\n";
  }

  cout << '*';
  print_many_chars('.', 11, false);
  cout << "*\\.*" << "\n";
  cout << '*';
  print_many_chars('.', 11, false);
  cout << "*.\\*" << "\n";

  print_many_chars('*', 16, false);
}

void print_many_chars(char c, int count, bool newLn) {
  for (int i = 0; i < count; i++){
    cout << c;
  }
  if (newLn)
    cout << endl;
}
