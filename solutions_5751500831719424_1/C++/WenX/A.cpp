//This template is CopyRight By WenX(R), Southeast University, China
//wenxiao1992@gmail.com
//This is for GCJ 2014 Round 1B

#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable: 4996)

//SYS
#include <iostream>
#include <string>/////////
#include <cstring>////////This two
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <complex>
#include <cassert>
//ALG
#include <list>
#include <vector>
#include <stack>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    int cc, tt;
    int ables;
    cin >> tt;
    for (cc = 1; cc <= tt; cc++){
        string s[111];
        string mins[111];
        int rep_num[111][111];
        int n;

        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> s[i];
            mins[i] = "";

            int current_id = -1;
            for (int j = 0; j < s[i].size(); j++){
                if (j == 0 || s[i][j] != s[i][j - 1]){
                    current_id++;
                    rep_num[current_id][i] = 1;
                    mins[i] += s[i][j];
                }
                else{
                    rep_num[current_id][i]++;
                }
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++)
        if (mins[i] != mins[0]){
            ans = -1;
        }

        if (ans == -1)
        {
            printf("Case #%d: Fegla Won\n", cc);
        }
        else
        {
            for (int j = 0; j < mins[0].size(); j++){
                sort(rep_num[j], rep_num[j] + n);
                for (int k = 0; k < n; k++){
                    ans += abs(rep_num[j][k] - rep_num[j][n / 2]);
                }
            }

            printf("Case #%d: %d\n", cc, ans);
        }

    }
    return 0;
}