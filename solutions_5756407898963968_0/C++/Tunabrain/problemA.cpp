#include <iostream>

#define BAD_MAGICIAN 0
#define CHEATER      1
#define SOLVED       2

int checkCondition(int row1, int row2, int cards1[4][4], int cards2[4][4], int &card)
{
    int candidateCount = 0;
    card = -1;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (cards1[row1][i] == cards2[row2][j]) {
                candidateCount++;
                card = cards1[row1][i];
            }
        }
    }
    
    return candidateCount == 0 ? CHEATER :
          (candidateCount == 1 ? SOLVED : BAD_MAGICIAN);
}

void solveCase()
{
    int row1, row2;
    int cards1[4][4], cards2[4][4];
    std::cin >> row1;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            std::cin >> cards1[i][j];
    std::cin >> row2;
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            std::cin >> cards2[i][j];
    int card;
    int result = checkCondition(row1 - 1, row2 - 1, cards1, cards2, card);
    
    switch (result) {
    case BAD_MAGICIAN:
        std::cout << "Bad magician!" << std::endl;
        break;
    case CHEATER:
        std::cout << "Volunteer cheated!" << std::endl;
        break;
    case SOLVED:
        std::cout << card << std::endl;
        break;
    }
}

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        std::cout << "Case #" << i + 1 << ": ";
        solveCase();
    }
    
    return 0;
}