#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
int main(int argc, char *argv[])
{
    int T;
    cin >> T;
    for (int ct = 1; ct <= T; ct++) {
        printf("Case #%d: ", ct);
        int N;
        string tmp;
        cin >> N;
        vector<string> V;
        int mapping[200] = {0};
        for (int i = 0; i < N; i++) {
            cin >> tmp;
            V.push_back(tmp);
        }
        vector<string> VV;
        for (int i = 0; i < V.size(); i++) {
            char strTmp[200] = {0};
            int strin = 0;
            for (int j = 0; j < V[i].length(); j++) {
                char ch = V[i][j];
                while (j < V[i].length() && ch == V[i][j]) {
                    j++;
                }
                j--;
                strTmp[strin++] = ch;
            }
            VV.push_back(strTmp);
        }
        bool hasAns = true;
        for (int i = 0; i < VV.size(); i++) {
            for (int j = 0; j < VV.size(); j++) {
                hasAns = hasAns & (VV[i] == VV[j]);
            }
        }
        if (!hasAns) {
            printf("Fegla Won\n");
        } else {
            vector<int> VVV[200];
            int index = 0;
            for (int i = 0; i < V.size(); i++) {
                index = 0;
                for (int j = 0; j < V[i].length(); j++) {
                    char ch = V[i][j];
                    int cccct = 0;
                    while(j < V[i].length() && V[i][j] == ch) {
                        j++;
                        cccct++;
                    }
                    j--;
                    VVV[index++].push_back(cccct);
                }
            }
            int ans = 0;
            for (int i = 0; i < index; i++) {
                sort(VVV[i].begin(), VVV[i].end());
                for (int j = 0; j < N; j++) {
                    ans += abs(VVV[i][N/2] - VVV[i][j]);
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
