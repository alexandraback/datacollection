#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;

int trialCount;

int main() {
    ifstream fin("contest.in");
    ofstream fout("contest.out");

    fin >> trialCount;

    for(int caseNo = 1; caseNo <= trialCount; caseNo++) {
        int intervalCount = 0;
        fin >> intervalCount;
        vector<int> intervals(intervalCount);
        for(int i = 0; i <  intervalCount; i++) {
            fin >> intervals[i];
        }

        int computation1 = 0, computation2 = 0, mostFall = 0;
        for(int i = 0; i < intervalCount - 1; i++) {
            computation1 += max(intervals[i] - intervals[i + 1], 0);
            mostFall = max(mostFall, intervals[i] - intervals[i + 1]);
        }

        for(int i = 0; i < intervalCount - 1; i++) {
            computation2 += min(mostFall, intervals[i]);
        }



        fout << "Case #" << caseNo << ": " << computation1 << " " << computation2 << "\n";
    }

    return 0;
}
