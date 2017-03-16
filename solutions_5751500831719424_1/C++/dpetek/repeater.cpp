#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string reduce(string s) {
    string ret;
    for (int i=0;i<s.size();++i) {
        if (i == 0 || s[i] != s[i-1]) {
            ret.push_back(s[i]);
        }
    }
    return ret;
}

vector<int> getCount(string s) {
    vector<int> ret;
    int cnt = 1;

    for (int i=1;i<s.size();++i) {
        if (s[i] != s[i-1]) {
            ret.push_back(cnt);
            cnt = 1;
        } else {
            cnt ++;
        }
    }

    if (cnt) ret.push_back(cnt);

    return ret;
}

int numActions(vector<int> v) {
    int miny = 92384234, cnt = 0;
    for (int i=0;i<=100;++i) {
        cnt = 0;
        for (int j=0;j<v.size();++j) {
            cnt += abs(v[j] - i);
        }
        miny = min(cnt, miny);
    }

    return miny;
}

int solve(vector<vector<int> > counts) {
    int res = 0;
    for (int i=0;i<counts[0].size();++i) {
        vector<int> tmp;
        for (int j=0;j<counts.size();++j) {
            tmp.push_back(counts[j][i]);
        }
        res += numActions(tmp);
    }
    return res;
}

int main(void)
{

//    freopen("A-small.in", "r", stdin);
//    freopen("A-small.out", "w", stdout);

    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);

    int tests;

    scanf("%d", &tests);

    for (int test=1;test<=tests;++test) {
        int n;
        string s, prevReduced, reduced = "";
        vector<string> w;
        vector<vector<int> > counts;
        vector<int> cnt;
        bool lost = false;


        scanf("%d", &n);
        for (int i=0;i<n;++i) {
            cin >> s;
            w.push_back(s);
            reduced = reduce(s);
            if (prevReduced != "" && reduced != prevReduced) {
                lost = true;
            }
            prevReduced = reduced;

            counts.push_back(getCount(s));
        }

        if (lost) {
            printf("Case #%d: Fegla Won\n", test);
        } else {
            printf("Case #%d: %d\n", test, solve(counts));
        }


    }
    return 0;
}
