#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <queue>
#include <cmath>

using namespace std;

static const string _q = "A";

vector<int> max_indices(vector<int> & P)
{
    int max_p = 0;
    for (int i = 0; i < P.size(); i++)
    {
        if (P[i] > max_p)
        {
            max_p = P[i];
        }
    }

    vector<int> max_inds;

    for (int i = 0; i < P.size(); i++)
    {
        if (P[i] == max_p)
        {
            max_inds.push_back(i);
        }
    }

    return max_inds;
}

void solve()
{
    int N; cin >> N;
    int sen_count = 0;

    vector<int> P(N);
    for (int i = 0; i < N; i++)
    {
        cin >> P[i];
        sen_count += P[i];
    }

    while (sen_count)
    {
        auto max_inds = max_indices(P);


        if (max_inds.size() == 1 || max_inds.size() == 3)
        {
           
            cout << char('A' + max_inds[0]);
            P[max_inds[0]]--;
            sen_count--;   
        }
        else
        {
            
            cout << char('A' + max_inds[0]) << char('A' + max_inds[1]);
            P[max_inds[0]]--;
            P[max_inds[1]]--;
            sen_count-=2;
        }

        if (sen_count)
        {
            cout << " ";
        }
    }
}

int main(void)
{
    ifstream in(_q + ".in");
    ofstream out(_q + ".out");
    cin.rdbuf(in.rdbuf());
    cout.rdbuf(out.rdbuf());

    int T; cin >> T;
    for (int t = 1; t <= T; t++)
    {
        cout << "Case #" << t << ": ";
        solve();
        cout << endl;
    }

    return 0;
}
