#include <iostream>
#include <fstream>
#include <vector>


using namespace std;

int main() {

	ifstream fin("input.txt");
	ofstream fout("output.txt");

	int T;

	fin >> T;

    for (int t = 1; t <= T; ++t)
    {
        int firstAnswer;
        fin >> firstAnswer;

        vector<vector<int> > arrBefore;
        for (int j = 0; j < 4; ++j)
        {
            vector<int> emptyVector;
            arrBefore.push_back(emptyVector);
            for (int k = 0; k < 4; ++k)
            {
                int number;
                fin >> number;
                arrBefore[j].push_back(number);
            }
        }

        int secondAnswer;
        fin >> secondAnswer;

        vector<vector<int> > arrAfter;
        for (int j = 0; j < 4; ++j)
        {
            vector<int> emptyVector;
            arrAfter.push_back(emptyVector);
            for (int k = 0; k < 4; ++k)
            {
                int number;
                fin >> number;
                arrAfter[j].push_back(number);
            }
        }

        // Test info received

        int matchesCounter = 0;
        int firstMatch = 0;
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                if (arrBefore[firstAnswer - 1][i] == arrAfter[secondAnswer - 1][j])
                {
                    if (firstMatch == 0)
                        firstMatch = arrBefore[firstAnswer - 1][i];
                    matchesCounter++;
                }
            }
        }

        // Output

        fout << "Case #" << t << ": ";
        if (matchesCounter == 0)
        {
            fout << "Volunteer cheated!" << endl;
        }
        else if (matchesCounter == 1)
        {
            fout << firstMatch << endl;
        }
        else
        {
            fout << "Bad magician!" << endl;
        }
    }

	fin.close();
	fout.close();

	return 0;
}
