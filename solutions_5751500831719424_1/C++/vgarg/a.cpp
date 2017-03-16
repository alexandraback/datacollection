#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long ll;

const int INF = 1e9;

typedef pair<char,int> pci;

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int t, T, n;
    cin >> T;
    for (t = 1; t <= T; t++){
        cin >> n;
        vector<string> v(n);
        for (int i=0; i < n;i++){
            cin>>v[i];
        }
        vector< vector<pci> > a(n);
        pci p;
        p.first=v[0][0];
        p.second=1;
        for (int j=1;j<v[0].size();j++){
            if(v[0][j]==p.first){
                p.second++;
            }else{
                a[0].push_back(p);
                p.first = v[0][j];
                p.second = 1;
            }
        }
        a[0].push_back(p);

        int cost=0;
        for(int i=1;i<n&&cost!=-1;i++){
            pci p;
            p.first=v[i][0];
            p.second=1;
            int c = 0;
            if (p.first != a[i-1][c].first){
                cost=-1;
                break;
            }

            for (int j=1;j<v[i].size();j++){
                if(v[i][j]==p.first){
                    p.second++;
                }else{
                    a[i].push_back(p);
                    p.first = v[i][j];
                    p.second = 1;
                    c++;
                    if (c < a[i-1].size() && p.first != a[i-1][c].first){
                        cost=-1;
                        break;
                    }
                }
            }
            a[i].push_back(p);
            if (a[i].size()!=a[0].size()){
                cost = -1;
            }
        }
        if (cost==-1){
            cout<<"Case #"<<t<<": Fegla Won\n";
            continue;
        }
        cost=0;
        for(int i=0;i<a[0].size();i++){
            int mc=INF,c,cc;
            for (int j=0;j<n;j++){
                c=0;
                for(int k=0;k<n;k++){
                    if (k==j)continue;
                    c+=abs(a[j][i].second-a[k][i].second);
                }
                if(c<mc)mc=c;
            }
            cost+=mc;
        }
        cout<<"Case #"<<t<<": "<<cost<<"\n";
    }
}
