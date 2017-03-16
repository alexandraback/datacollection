#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <sstream>
#include <fstream>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<double, int> pdi;

int trialCount;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    ifstream fin("contest.in");
    ofstream fout("contest.out");

    fin >> trialCount;

    for (int caseNo = 1; caseNo <= trialCount; caseNo++) {
        int barbCount = 0, myPos = 0, result = 0;
        fin >> barbCount >> myPos;
        vector<ll> barbTimes(barbCount);
        for (int i = 0; i < barbCount; i++) {
            fin >> barbTimes[i];
        }
        vector<double> inverseTimes(barbCount);
        for (int i = 0; i < barbCount; i++) {
            inverseTimes[i] = ((double) 1) / barbTimes[i];
        }
        double sumTime = accumulate(inverseTimes.begin(), inverseTimes.end(), (double) 0.0);
        for (int i = 0; i < barbCount; i++) {
            inverseTimes[i] /= sumTime;
        }

        if (myPos <= barbCount) {
            result = myPos;
        }
        else {
            myPos -= barbCount;
            for(int i = 0; i < barbCount; i++) {
                inverseTimes[i] *= myPos;
            }

            ll cutWithoutTail = 0;
            for(double d : inverseTimes) {
                cutWithoutTail += (ll) d;
            }

            vector<pdi> numPairs(barbCount);
            for(int i = 0; i < barbCount; i++) {
                numPairs[i] = pdi(inverseTimes[i], i + 1);
            }

            sort(numPairs.begin(), numPairs.end(), [](const pdi &a, const pdi &b) {
                    double tailA = a.first - (ll) a.first;
                    double tailB = b.first - (ll) b.first;
                    if (tailA == tailB) {
                        return a.second < b.second;
                    }
                    else {
                        return tailA > tailB;
                    }
                 });

            /* DEBUG
            for(pdi pa : numPairs) {
                cerr << pa.first << " " << pa.second << endl;
            }
            //*/
            if(cutWithoutTail == myPos) {
                result = barbCount;
            }
            else {
                result = numPairs[myPos - cutWithoutTail - 1].second;
            }
        }

        fout << "Case #" << caseNo << ": " << result << "\n";
    }

    return 0;
}
