#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000000;

int main(){
    //freopen("in.txt","r",stdin);
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int casos;
    cin >> casos;
    for(int caso = 1 ; caso <= casos ; caso++){
        int n;
        cin >> n;
        string fegla = "Fegla Won";
        vector<string> v(n);
        for(int i = 0 ; i < n ; i++){
            cin >> v[i];
        }
        char m[n][100];
        int a[n][100];
        memset(a,0,sizeof a);
        int l[n];
        for(int i = 0 ; i < n ; i++){
            int idxs = 0;
            int idxm = 0;
            while(idxs < (int)v[i].size()){
                m[i][idxm] = v[i][idxs];
                while((v[i][idxs] == m[i][idxm]) && (idxs < (int)v[i].size())){
                    a[i][idxm]++;
                    idxs++;
                }
                idxm++;
            }
            l[i] = idxm;
        }
        bool sw = true;
        int len = l[0];
        for(int i = 0 ; i < n ; i++){
            sw &= (l[i] == len);
            for(int j = 0 ; j < len ; j++){
                sw &= (m[i][j] == m[0][j]);
            }
        }
        int ans = 0;
        for(int j = 0 ; j < len ; j++){
            int maxi = 0, mini = INF;
            for(int i = 0 ; i  < n ; i++){
                maxi = max(maxi,a[i][j]);
                mini = min(mini,a[i][j]);
            }
            int c = INF;
            for(int k = mini ; k <= maxi ; k++){
                int r = 0;
                for(int i = 0 ; i < n ; i++){
                    r += abs(a[i][j] - k);
                }
                c = min(c,r);
            }
            ans += c;
        }
        if(sw){
            cout << "Case #" << caso <<": "<< ans << endl;
        } else {
            cout << "Case #" << caso <<": "<< fegla << endl;
        }
    }
    return 0;
}
