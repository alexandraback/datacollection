#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

string strings[100];

int T, N;

void output(int Case, int ans)
{
    if (ans == -1)
    {
        cout << "Case " << "#" << Case << ": Fegla Won" << endl;

    }else
    {
        cout << "Case " << "#" << Case << ": " << ans << endl;
    }
}

int numMoves()
{
    vector< vector< pair<char, int> > > data;

    for (int i = 0; i < N; i++)
    {
        vector<pair<char, int> > transitions;
        char cur = strings[i][0];
        int curCtr = 1;
        int pos = 1;
        while (pos < strings[i].size())
        {
            if (strings[i][pos]==cur)
            {
                curCtr++;
            }else
            {
                transitions.push_back(make_pair(cur, curCtr));
                cur = strings[i][pos];
                curCtr = 1;
            }
            pos++;
        }
        transitions.push_back(make_pair(cur, curCtr));
        data.push_back(transitions);
    }
    int numTrans = data[0].size();
    for (int i = 0; i < N; i++)
    {
        if (numTrans != data[i].size()) return -1;
    }
    int moves = 0;
    for (int i = 0; i < numTrans; i++)
    {
        char curChar = data[0][i].first;
        int summy = data[0][i].second;
        for (int j = 1; j < N; j++)
        {
            if (data[j][i].first != curChar)
            {
                return -1;
            }else
            {
                summy += data[j][i].second;
            }
        }
        int mean = round(summy/N);
        for (int j = 0; j < N; j++)
        {
            moves += abs(data[j][i].second - mean);
        }
    }
    return moves;
}

int main()
{
    freopen("A.in", "r", stdin);
    freopen("A.out", "w", stdout);

    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        for (int j = 0; j < N; j++)
        {
            cin >> strings[j];
        }
        int ans = numMoves();
        output(i+1, ans);


    }
    return 0;
}
