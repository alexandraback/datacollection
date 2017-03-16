#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <map>
#include <queue>
#include <stack>
#include <cstring>
#include <cstdlib>
#include <list>
#include <set>
#include <ctime>
#include <list>
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define vi vector<int>
#define vd vector<double>
#define pii pair<int,int>
#define pdd pair<double,double>
#define ll long long
#define INF (1<<30)
using namespace std;

int N;
string s[128];

vector<pair<int, char> > process(string s)
{
    vector<pair<int, char> > v;
    int i, cnt = 1;
    char last = s[0];
    for(i = 1; i < s.length(); ++i)
    {
        if(s[i] != last)
        {
            v.pb(mp(last, cnt));
            cnt = 1;
            last = s[i];
        }
        else ++cnt;
    }
    if(cnt > 0) v.pb(mp(last, cnt));
    return v;
}

vector<pair<int, char> > P[128];

void solve_case(int case_id)
{
    printf("Case #%d: ", case_id);
    int i, j, k, best = 0;
    cin >> N;
    for(i = 0; i < N; ++i) cin >> s[i];
    for(i = 0; i < N; ++i) P[i] = process(s[i]);
    for(i = 0; i < N; ++i)
        for(j = i + 1; j < N; ++j)
        {
            if(P[i].size() != P[j].size())
            {
                cout << "Fegla Won\n";
                return;
            }
        }

    for(i = 0; i < N; ++i)
        for(j = i + 1; j < N; ++j)
            for(k = 0; k < P[i].size(); ++k)
            {
                if(P[i][k].x != P[j][k].x)
                {
                    cout << "Fegla Won\n";
                    return;
                }
            }

    for(i = 0; i < P[0].size(); ++i)
    {
        k = 0;
        for(j = 0; j < N; ++j) k += P[j][i].y;
        k /= N;
        for(j = 0; j < N; ++j) best += abs(k - P[j][i].y);
    }
    cout << best<< '\n';
}

int main()
{
    int i, t;
    scanf("%d", &t);
    for(i = 1; i <= t; ++i) solve_case(i);
    return 0;
}
