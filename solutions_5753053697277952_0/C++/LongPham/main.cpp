#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <unordered_map>
#include <cmath>
#include <cstdint>
#include <iostream>
#include <set>
#include <numeric>

using namespace std;

#define for0(i, n) for(int i=0; i<n; i++)
#define for1(i, n) for(int i=1; i<=n; i++)

int main() {
    std::ifstream in{ "small-practice.in" };
    std::ofstream out{ "small.out" };

    int T;
    in >> T;
    int t{ 1 };

    while (t <= T) {
        out << "Case #" << t << ": ";
        int N;
        in >> N;

        vector<int>parties{};
        int sum = 0;

        for0(i, N) {
            int senetorNum;
            in >> senetorNum;
            sum += senetorNum;
            parties.push_back(senetorNum);
        }

        while (sum > 0) {
            auto party1 = std::max_element(parties.begin(), parties.end());
            (*party1)--;
            auto pos1 = std::distance(parties.begin(), party1);
            char char1 = 'A' + pos1;
            out << char1;
            sum--;

            auto party2 = std::max_element(parties.begin(), parties.end());
            int remainParties = 0;
            if (*party2 == 1) {
                for (auto it = parties.begin(); it != parties.end(); ++it) {
                    if (*it > 0) remainParties++;
                }

                if (remainParties == 2) {
                    out << " ";
                    continue;
                }
            }

            (*party2)--;
            auto pos2 = std::distance(parties.begin(), party2);
            char char2 = 'A' + pos2;
            out << char2 << " ";
            sum--;
        }

        out << endl;


        t++;
    }

    return 0;
}