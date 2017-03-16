#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin("B-small-attempt2.in");
    ofstream fout("outputBsmall.txt");
    /*ifstream fin("dataB.txt");
    ofstream fout("outputB.txt");*/

    int T;
    fin >> T;

    for (int i=0; i<T; i++) {
        int B, N;
        fin >> B >> N;

        vector<int> barbers(B);
        for (int j=0; j<B; j++) {
            int temp;
            fin >> temp;
            barbers[j] = temp;
        }

        if (N <= B) {
            cout << "Case #" << i+1 << ": " << N << "\n";
            fout << "Case #" << i+1 << ": " << N << "\n";
            continue;
        }

        //cm
        int commonMult = 1;
        for (int j=0; j<B; j++) {
            commonMult *= barbers[j];
        }

        int custPerCycle = 0;
        for (int j=0; j<B; j++) {
            custPerCycle += commonMult/barbers[j];
        }

        int currPos = ((N-1) % custPerCycle) + 1;

        if (currPos <= B) {
            cout << "Case #" << i+1 << ": " << currPos << "\n";
            fout << "Case #" << i+1 << ": " << currPos << "\n";
            continue;
        }

        currPos -= B;

        vector<int> timeLeft(barbers);

        //simulation
        while (currPos > 0) {
            int smallest = *min_element(timeLeft.begin(), timeLeft.end());

            for (int j=0; j<B; j++) {
                timeLeft[j] -= smallest;
            }

            vector<int> available;

            for (int j=0; j<B; j++) {
                if (timeLeft[j] == 0) available.push_back(j);
            }

            if (currPos <= available.size()) {
                cout << "Case #" << i+1 << ": " << available[currPos-1]+1 << "\n";
                fout << "Case #" << i+1 << ": " << available[currPos-1]+1 << "\n";
                break;
            } else {
                currPos -= available.size();
                for (vector<int>::iterator it=available.begin(); it<available.end(); it++) {
                    timeLeft[*it] = barbers[*it];
                }
            }
        }
    }

    fin.close();
    fout.close();

    return 0;
}
