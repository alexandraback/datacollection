// Victor Guerra <vguerra@gmail.com>
// 2014-03-12
//

#include <iostream>
#include <map>

#define ROWS 4 
#define COLS 4

using namespace std;

int main() {
  int T; 
  cin >> T; 
  for (int t = 1; t <= T; ++t ) {
    int row_one; 
    int row_two; 
    map<int, bool> row; 
    cin >> row_one;
    cin.ignore(12, '\n');

    // consume first arrangement of cards
    for (int i = 0; i < ROWS; ++i) {
      if (i + 1 == row_one) {
        for (int j = 0; j < COLS; ++j) {
          int card; 
          cin >> card;
          row[card] = true;
        }
        cin.ignore(12, '\n');
      } else {
        cin.ignore(12, '\n');
      }
    }
    cin >> row_two; 
    cin.ignore(12, '\n');
    int matches = 0; 
    int winning_card = 0; 
    
    for (int i = 0; i < ROWS; ++i) {
      if (i + 1 == row_two) {
        for (int j = 0; j < COLS; ++j) {
          int card; 
          cin >> card; 
          if (row.find(card) != row.end()) {
            ++matches; 
            winning_card = card;
          }
        }
        cin.ignore(1, '\n');
      } else {
        cin.ignore(12, '\n');
      }
    }

    cout << "Case #" << t << ": ";
    if (matches == 0) {
      cout << "Volunteer cheated!";
    } else if (matches == 1) {
      cout <<  winning_card;
    } else {
      cout << "Bad magician!";
    }
    cout << "\n";
  }
  return 0;
}
