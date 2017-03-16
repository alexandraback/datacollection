#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <utility>
#define inf 2000000000
#define ll long long
#define Max

using namespace std;

vector<string>dict;

vector<pair<char, int> > parseString(string str, string &parsed) {
    parsed = "";
    int c = 1;
    char ch = str[0];
    vector<pair<char, int> > ret;

    for(int i = 1; i < str.size(); i++) {
        if(str[i] != ch) {
            parsed += ch;
            ret.push_back(make_pair(ch, c));
            c = 0;
        }
        c ++;
        ch = str[i];
    }
    parsed += ch;
    ret.push_back(make_pair(ch, c));

    return ret;
}

int main()
{
    freopen("input_A3.txt", "r", stdin);
    freopen("outputA.txt", "w", stdout);

    int T, N;
    cin >> T;
    for(int cas = 1; cas <= T; cas ++) {

        cin >> N;
        dict.clear();

        int ret = inf;

        for(int i = 0; i < N; i++) {
            string str;
            cin >> str;
            dict.push_back(str);
        }

        int flag = 1;


        vector<string>parsed;
        vector<vector<pair<char, int> > > V;
        for(int i = 0; i < N; i++) {

            string ref = dict[i], temp;
            vector<pair<char, int> > parsedRef = parseString(ref, temp);
            parsed.push_back(temp);
            V.push_back(parsedRef);
        }

        string parsedRef = parsed[0];

        for(int i = 0; i < N; i++) {
            if(parsed[i] != parsedRef) {
                flag = 0;
                break;
            }
        }

        if( flag ) {
            ret = 0;
            for(int i = 0; i < parsedRef.size(); i++) {

                int toAdd = 1e9;

                for(int k = 1; k <= 100; k++) {
                    int add = 0;
                    for(int j = 0; j < N; j++) {
                        add += fabs(V[j][i].second - k);
                    }
                    toAdd = min(add, toAdd);
                }

                ret += toAdd;
            }
        }
        printf("Case #%d: ", cas);
        if(ret < inf) {
            cout << ret << endl;
        } else {
            puts("Fegla Won");
        }
    }

    return 0;
}
