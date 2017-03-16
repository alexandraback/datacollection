#include <iostream>
#include <fstream>
#include <algorithm>
#include <deque>
#include <vector>
#include <sstream>
using namespace std;

const string INPUT_FILE = "A-large.in";
const string OUTPUT_FILE = "out.txt";

int calculateminmoves(vector<int> moves) {
    int minscore = INT_MAX;

    sort(moves.begin(), moves.end());
    int total = 0;
    for (int i=0; i<moves.size(); i++) {
        int score = 0;
        for (int a=0; a < i; a++) {
            score += moves[i] - moves[a];
        }
        for (int b = i + 1; b < moves.size(); b++) {
            score += moves[b] - moves[i];
        }
    if (score < minscore) minscore = score;
    }
    return minscore;
}

string solveCase(ifstream & input) {
    vector<string> strings;
    vector<int> pos;
    vector<int> moves;
    int score = 0;
    int n;
    input >> n;
    string bla;
    getline(input, bla);
    for (int i = 0; i < n; i++) {
        string word;
        getline(input, word);
        strings.push_back(word);
        pos.push_back(0);
        moves.push_back(0);
    }
    char kar;
    while (pos[0] < strings[0].size()) {
        kar = strings[0][pos[0]];
        moves[0] = 0;
        do {
            pos[0]++;
            moves[0]++;
        }
        while (pos[0] < strings[0].size() && strings[0][pos[0]] == kar);
        for (int j=1;j<strings.size();j++) {
            if (pos[j] >= strings[j].size() || strings[j][pos[j]] != kar) return "Fegla Won";
            else {
                moves[j] = 0;
                do {
                    moves[j]++;
                    pos[j]++;
                } while (pos[j] < strings[j].size() && strings[j][pos[j]] == kar);
            }
        }

        int minmoves = calculateminmoves(moves);
        score += minmoves;
    }

    for (int i = 1; i < strings.size(); i++) {
        if (pos[i] < strings[i].size()) {
            return "Fegla Won";
        }
    }
    ostringstream conv;
    conv << score;
    return conv.str();
}

void solveAllCases(ifstream & input, ofstream & output) {
    int cases;
    input >> cases;
    cout << "Testcases to run: " << cases << endl;
    for (int i = 1; i <= cases; i++) {
        cerr << "Case #" << i << ": ";
        output << "Case #" << i << ": ";
        output << solveCase(input);
        output << endl;
    }
}

int main()
{
    ifstream input(INPUT_FILE.c_str(), ios::in);
    ofstream output(OUTPUT_FILE.c_str(), ios::out);
    solveAllCases(input, output);
    input.close();
    output.close();
    return 0;
}
