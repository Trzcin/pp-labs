#include <iostream>
#include <bitset>
#include <math.h>
using namespace std;

enum PlayerState {NO_ROLLS=0, ROLLED_1=1, CAN_MOVE=2};
int main() {
  int pos[4]{};
  PlayerState states[4] {NO_ROLLS};
  int curr_player = 0;
  int board_size;
  unsigned char diodes = 0b00000000;
  unsigned char base_mask = 128;
  // player 1 mask 0b10000000 = 128
  // 0b01000000 = 64;

  cin >> board_size;
  bool done = false;
  while (!done) {
    char command;
    cin >> command;
    if (command == 'P') {
      cout << pos[0] << ' ' << pos[1] << ' ' << pos[2] << ' ' << pos[3] << ' ' << bitset<8>(diodes) << endl;
    } else if (command == 'M') {
      int val;
      cin >> val;
      switch (states[curr_player]) {
        case NO_ROLLS:
          if (val == 1) states[curr_player] = PlayerState::ROLLED_1;
          break;
        case ROLLED_1:
          if (val == 6) {
            states[curr_player] = PlayerState::CAN_MOVE;
            //cout << bitset<8>((base_mask / (4*curr_player))) << endl;
            diodes |= (unsigned char)(base_mask / pow(4, curr_player));
          }
          else states[curr_player] = PlayerState::NO_ROLLS;
          break;
        case CAN_MOVE:
          pos[curr_player] += val;
          if (pos[curr_player] % 2 != 0) {
            diodes |= (unsigned char)(base_mask / pow(2, 1 + 2 * curr_player));
          }

          for (int i = 0; i < 4; i++){
            if (i == curr_player) continue;
            if (pos[i] == pos[curr_player]) {
              pos[i] = 0;
              states[i] = PlayerState::NO_ROLLS;
            diodes &= ~(unsigned char)(base_mask / pow(4, curr_player));
            diodes &= ~(unsigned char)(base_mask / pow(2, 1 + 2 * curr_player));
            }
          }

          if (pos[curr_player] >= board_size) {
            cout << "END OF GAME" << endl;
            done = true;
          }
          break;
      }
      curr_player++;
      if (curr_player == 4) {curr_player = 0;}
    } else {
      cout << "Invalid command!" << endl;
    }
  }
}
