#include <iostream>
using namespace std;

int main() {

  // nah
  //for (int i = 0; i < 10; i++){
  //  cout << i << endl;
  //}

  int i = 0;
  loop: if (i < 10) {
    cout << i << endl;
    i += 1;
    goto loop;
  }
}

