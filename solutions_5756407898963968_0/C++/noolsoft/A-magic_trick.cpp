#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int t = 0, row1 = 0, row2 = 0;
set<int> cardsInChosenRow1;
vector<int> cardsInChosenRow2;

string CardNumToString(int cardNum) {
  string units = string(1, cardNum % 10 + '0');

  if (cardNum / 10 > 0) {
    return string("1") + units;
  }

  return units;
}

string ChosenCard() {
  int chosenCard = 0;

  for (int i = 0; i < 4; ++i) {
    if (cardsInChosenRow1.count(cardsInChosenRow2[i]) > 0) {
      if (chosenCard > 0) {
        return "Bad magician!";
      }

      chosenCard = cardsInChosenRow2[i];
    }
  }

  if (0 == chosenCard) {
    return "Volunteer cheated!";
  }

  return CardNumToString(chosenCard);
}

int main() {
  cin >> t;

  for (int caseNum = 1; caseNum <= t; ++caseNum) {
    cardsInChosenRow1.clear();
    cardsInChosenRow2.clear();

    cin >> row1;

    for (int i = 1; i <= 4; ++i) {
      for (int j = 1; j <= 4; ++j) {
        int cardNum = 0;

        cin >> cardNum;

        if (i == row1) {
          cardsInChosenRow1.insert(cardNum);
        }
      }
    }

    cin >> row2;

    for (int i = 1; i <= 4; ++i) {
      for (int j = 1; j <= 4; ++j) {
        int cardNum = 0;

        cin >> cardNum;

        if (i == row2) {
          cardsInChosenRow2.push_back(cardNum);
        }
      }
    }

    cout << "Case #" << caseNum << ": " << ChosenCard() << endl;
  }

  return 0;
}

