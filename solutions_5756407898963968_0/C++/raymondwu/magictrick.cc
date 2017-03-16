#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <set>
using namespace std;

int main () {
    ifstream input;
    input.open("A-small-attempt2.in");
    int numCases;
    input >> numCases;
    for (int j = 0; j < numCases; j++) {
        int card;
        int row1;
        input >> row1;
        vector<int> cards1;
        for (int i = 0; i < 16; i++) {
            input >> card;
            cards1.push_back(card);
        }
        vector<int> possible;
        for (int i = 0; i < 4; i++) {
            possible.push_back(cards1[i+(row1-1)*4]);
        }
        int row2;
        input >> row2;
        vector<int> cards2;
        for (int i = 0; i < 16; i++) {
            input >> card;
            cards2.push_back(card);
        }
        vector<int> final;
        for (int i = 0; i < 4; i++) {
            int nextcard = cards2[i+(row2-1)*4];
            if (possible[0] == nextcard || possible[1] == nextcard || possible[2] == nextcard || possible[3] == nextcard)
                final.push_back(nextcard);
        }
        cout << "Case #" << (j+1) << ": ";
        if (final.size() > 1)
            cout << "Bad magician!" << endl;
        else if (final.size() < 1)
            cout << "Volunteer cheated!" << endl;
        else
            cout << final[0] << endl;
    }
}
