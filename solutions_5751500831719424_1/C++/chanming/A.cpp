#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
vector <int> num[210];
vector <char> myc[210];
int N;

int abs(int x){
    if (x < 0) x = -x;
    return x;
}

int check(){
    string s[210];
    for (int i = 0; i < N; ++i){
        s[i]="";
        for (int j = 0; j < myc[i].size(); ++j)
            s[i] += myc[i][j];
        if (i && s[i] != s[i - 1])
            return -1;
    }
    int ans = 0;
    int Len = num[0].size();
    for (int i = 0; i < Len; ++i){
        vector <int> llist;
        for (int j = 0; j < N; ++j)
            llist.push_back(num[j][i]);
        sort(llist.begin(), llist.end());
        int x = llist[N / 2];
        for (int j = 0; j < N; ++j)
            ans += abs(num[j][i] - x);
    }
    return ans;
}

int main(){
    string str;
    freopen("A-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int _ = 1; _ <= T; ++_){
        cin >> N;
        for (int i = 0; i < N; ++i){
            num[i].clear();
            myc[i].clear();
            cin >> str;
            char c = str[0];
            int p = 1;
            for (int j = 1; j < str.size(); ++j)
                if (str[j] == str[j - 1]){
                    //cout << str[j];
                    p++;
                }else{
                    myc[i].push_back(str[j - 1]);
                    num[i].push_back(p);
                    p = 1;
                }
            myc[i].push_back(str[str.size() - 1]);
            num[i].push_back(p);
        }
        printf("Case #%d: ", _);
       // cout << myc[0][0] <<  " " << num[0][0] << endl;
        int ans = check();
        if (ans == -1) puts("Fegla Won");
            else printf("%d\n", ans);
    }
    return 0;
}
