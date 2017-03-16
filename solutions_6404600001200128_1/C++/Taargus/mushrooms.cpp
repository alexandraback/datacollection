#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("A-large.in");
    ofstream fout("A-large.out");

    int cases;
    fin >> cases;

    for(int i = 0; i < cases; i++) {
        int intervals;
        fin >> intervals;

        int amount[1000];

        int maxnum = 0;
        int case1 = 0;
        int case2 = 0;

        for(int j = 0; j < intervals; j++) {
            fin >> amount[j];
            if(j > 0 && amount[j - 1] - amount[j] > maxnum) {
                maxnum = amount[j - 1] - amount[j];
            }
        }

        for(int j = 0; j < intervals; j++) {
            if(j > 0 && amount[j] < amount[j - 1]) {
                int difference = amount[j - 1] - amount[j];
                case1 += difference;
            }

            if(j < intervals - 1) {
                case2 += min(amount[j], maxnum);
            }
        }

        fout << "Case #" << i + 1 << ": " << case1 << " " << case2 << "\n";
    }
    return 0;
}
