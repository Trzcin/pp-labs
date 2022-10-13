#include <iostream>
using namespace std;

int main() {
  int board_size;
  int g1{}, g2{}, g3{}, g4{};

  // 0 - not started
  // 1 - rolled 1
  // 2 - can start
  int s1{}, s2{}, s3{}, s4{};
  int player{};
  cin >> board_size;

  bool done = false;
  while (!done) {
    char command;
    cin >> command;
    if (command == 'P') {
      cout << g1 << ' ' << g2 << ' ' << g3 << ' ' << g4 << endl;
    } else {
      int val;
      cin >> val;
      switch (player) {
        case 0:
          switch (s1) {
            case 0:
              if (val == 1) s1 = 1;
              break;
            case 1:
              if (val == 6) s1 = 2;
              else s1 = 0;
              break;
            case 2:
              g1 += val;
              if (g1 >= board_size) {
                cout << "END OF GAME" << endl;
                done = true;
              }
              break;
          }
          break;
        case 1:
          switch (s2) {
            case 0:
              if (val == 1) s2 = 1;
              break;
            case 1:
              if (val == 6) s2 = 2;
              else s2 = 0;
              break;
            case 2:
              g2 += val;
              if (g2 >= board_size) {
                cout << "END OF GAME" << endl;
                done = true;
              }
              break;
          }
          break;
        case 2:
          switch (s3) {
            case 0:
              if (val == 1) s3 = 1;
              break;
            case 1:
              if (val == 6) s3 = 2;
              else s3 = 0;
              break;
            case 2:
              g3 += val;
              if (g3 >= board_size) {
                cout << "END OF GAME" << endl;
                done = true;
              }
              break;
          }
          break;
        case 3:
          switch (s4) {
            case 0:
              if (val == 1) s4 = 1;
              break;
            case 1:
              if (val == 6) s4 = 2;
              else s4 = 0;
              break;
            case 2:
              g4 += val;
              if (g4 >= board_size) {
                cout << "END OF GAME" << endl;
                done = true;
              }
              break;
          }
          break;
      }
      player += 1;
      if (player == 4) player = 0;
    }
  }
}
