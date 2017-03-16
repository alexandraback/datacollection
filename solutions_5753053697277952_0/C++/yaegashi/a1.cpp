#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

int main(int argc, char **argv)
{
        int T;
        cin >> T;
        for (int testcase = 0; testcase < T; testcase++) {
                int N;
                cin >> N;
                vector<int> P(N);
                int sum = 0;
                for (int i = 0; i < N; i++) {
                        cin >> P[i];
                        sum += P[i];
                }
                vector<string> plan;
                vector<int> p(N);
                iota(p.begin(), p.end(), 0);
                sort(p.begin(), p.end(), [&](int x, int y){ return P[x] > P[y]; });
                while (P[p[0]] > P[p[1]]) {
                        char a[] = {p[0]+65, 0};
                        P[p[0]]--;
                        plan.push_back(a);
                }
                for (int i = 2; i < N; i++) {
                        while (P[p[i]] > 0) {
                                char a[] = {p[i]+65, 0};
                                P[p[i]]--;
                                plan.push_back(a);
                        }
                }
                char ab[] = {p[0]+65, p[1]+65, 0};
                while (P[p[0]] > 0) {
                        P[p[0]]--;
                        plan.push_back(ab);
                }
                cout << "Case #" << testcase+1 << ":";
                for (auto s: plan)
                        cout << " " << s;
                cout << endl;
        }
        return 0;
}
