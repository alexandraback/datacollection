#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

const string INPUT_FILE = "A-small-attempt0.in";
const string OUTPUT_FILE = "output.txt";

string solveCase(ifstream & input, ofstream & output) {
    int firstChoice;
    int firstRow[4];
    int secondChoice;
    int secondRow[4];

    input >> firstChoice;
    firstChoice--;
    for (int i = 0; i < 16; i++) {
        int temp;
        input >> temp;
        if (firstChoice == i/4)
            firstRow[i%4] = temp;
    }
    input >> secondChoice;
    secondChoice--;
    for (int i = 0; i < 16; i++) {
        int temp;
        input >> temp;
        if (secondChoice == i/4)
            secondRow[i%4] = temp;
    }

    int answer = -1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (firstRow[i] == secondRow[j]) {
                if (answer == -1)
                    answer = firstRow[i];
                else
                    return "Bad magician!";
            }
        }
    }
    ostringstream convert;
    convert << answer;
    return answer == -1 ? "Volunteer cheated!" : convert.str();
}

void solveAllCases(ifstream & input, ofstream & output) {
    int cases;
    input >> cases;
    cout << "Testcases to run: " << cases << endl;
    for (int i = 1; i <= cases; i++) {
        output << "Case #" << i << ": ";
        output << solveCase(input, output);
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
