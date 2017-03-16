#define _CRT_SECURE_NO_WARNINGS
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;
#define DPF(fmt,...) printf(fmt,##__VA_ARGS__); fprintf(outf, fmt,##__VA_ARGS__);
const int MAX_STR = 2000;
#define CV(vec, type, x) vector<type> vec; vec.resize(x);
#define CV2(vec, type, x, y) vector<vector<type>> vec; vec.resize(y); for(int i = 0; i < y; i++) {vec[i].resize(x);}
#define RI(val) int val = 0; scanf("%d", &val);
#define RF(val) float val = 0.0f; scanf("%f", &val);
#define RS(val) string val; {char str[2000]; scanf("%s", str); val = str;}
#define RC(val) char val = 0; scanf("%c", &val);
#define RL(val) string val; {char str[MAX_STR]; fgets(str, MAX_STR, stdin); int len = strlen(str); str[len - 1] = '\0'; val = str;}
#define RNL() {char str[MAX_STR]; fgets(str, MAX_STR, stdin);}
#define RLI(vec) {int vs = (vec).size(); for(int ii = 0; ii < vs; ii++) {int val; scanf("%d", &val); (vec)[ii] = val;} RNL();}
#define RLF(vec) {int vs = (vec).size(); for(int ii = 0; ii < vs; ii++) {float val; scanf("%f", &val); (vec)[ii] = val;} RNL();}
#define RLS(vec) {int vs = (vec).size(); for(int ii = 0; ii < vs; ii++) {char val[MAX_STR]; scanf("%s", val); (vec)[ii] = val;} RNL();}
#define RLC(vec) {int vs = (vec).size(); for(int ii = 0; ii < vs; ii++) {char val; scanf("%c", &val); (vec)[ii] = val;} RNL();}
#define REP(ii, nn) for (int ii = 0; ii < nn; ii++)
typedef unsigned long long ULL;
typedef long long LL;


int main()
{
    FILE* inf = freopen("in.txt", "r", stdin);
    FILE* outf = fopen("out.txt", "w");
    RI(np); RNL();
    for (int pp = 1; pp <= np; pp++)
    {
        DPF("Case #%d: ", pp);
        RI(N); RNL();
        vector<string> vs;
        REP(i, N)
        {
            RS(s); RNL();
            vs.push_back(s);
        }

        // try to insert.
        bool good = false;
        int curr = 0;
        int ans = 0;
        bool next[100] = { 0 };
        while (!good)
        {
            sort(vs.begin(), vs.end());
            memset(next, 0, sizeof(next));
            bool equal = true;
            int nextct = 0;
            REP(i, N)
            {
                if (i < N - 1 && 
                    vs[i][curr] != vs[i + 1][curr])
                {
                    equal = false;
                }
                else
                {
                    if (vs[i].size() > curr + 1)
                    {
                        next[i] = (vs[i][curr] == vs[i][curr + 1]);
                        if (next[i] == true)
                        {
                            nextct++;
                        }
                    }
                }
            }
            if (!equal)
            {
                break;
            }
            else
            {
                bool equalanddone = true;
                REP(i, N)
                {
                    if (vs[i].size() != curr + 1)
                    {
                        equalanddone = false;
                    }
                }
                if (equalanddone)
                {
                    good = true;
                    break;
                }
                if (nextct == 0 || nextct == N)
                {
                    curr++;
                }
                else if (N - nextct < nextct)
                {
                    // duplicate
                    REP(i, N)
                    {
                        if (next[i] == false)
                        {
                            vs[i].insert(vs[i].begin() +curr + 1, vs[i][curr]);
                            ans++;
                        }
                    }
                }
                else
                {
                    // delete
                    REP(i, N)
                    {
                        if (next[i] == true)
                        {
                            vs[i].erase(vs[i].begin() + curr + 1);
                            ans++;
                        }
                    }
                }
            }
        }
        if (!good)
        {
            DPF("Fegla Won\n");
        }
        else
        {
            DPF("%d\n", ans);
        }
    }
    fclose(inf);
    fclose(outf);
}