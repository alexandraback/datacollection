#include <iostream>
#include <string.h>
using namespace std;

const int BOARD_SIZE = 4;
const int MAX_CARD_INDEX = BOARD_SIZE * BOARD_SIZE;

struct MagicTrickResult {
    bool ambiguity;
    int cardIndex;
};

int chosenCards[MAX_CARD_INDEX + 1];

void readChoiceAndBoard() {
    int row;
    cin >> row;

    int cardIndex;
    for (int i = 1; i <= BOARD_SIZE; i++) {
        for (int j = 1; j <= BOARD_SIZE; j++) {
            cin >> cardIndex;
            if (i == row) {
                chosenCards[cardIndex]++;
            }
        }
    }
}

MagicTrickResult getMegicTrickResult() {
    memset(chosenCards, 0, sizeof(chosenCards));
    readChoiceAndBoard();
    readChoiceAndBoard();

    MagicTrickResult result;
    result.ambiguity = false;
    result.cardIndex = 0;

    for (int i = 1; i <= MAX_CARD_INDEX; i++) {
        //cout << i << " : "  << chosenCards[i] << endl;
        if (chosenCards[i] == 2) {
            if (!result.ambiguity && result.cardIndex > 0) {
                result.ambiguity = true;
                result.cardIndex = 0;
            } else {
                result.cardIndex = i;
            }
        }
    }
    return result;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case " << "#" << i << ": ";
        MagicTrickResult result = getMegicTrickResult();
        if (!result.ambiguity) {
            if (result.cardIndex > 0) {
                cout << result.cardIndex << endl;
            } else {
                cout << "Volunteer cheated!" << endl;
            }
        } else {
            cout << "Bad magician!" << endl;
        }
    }

    return 0;
}
