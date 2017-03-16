#include<bits/stdc++.h>

using namespace std;

int ou;

int r,c;
bool isOn(int i,int j,int v, bool gbr) {
    int pos = i*c + j;

    bool re = v & (1 << pos);

    if(gbr) {
        // cout << i << ',' <<  j << ':';
        // cout << "BIT KE " << pos << " " << re << '\n';
    }
    return re;
}
void gbr(int v) {
    cout << "MENGGAMBAR " << v << '\n';
    string p = "";
    int tx = v;
    while(tx) {
        if(tx%2==0) {
            p+='0';
        } else {
            p+='1';
        }
        tx/=2;
    }
    reverse(p.begin(),p.end());
    cout << p << '\n';
    for(int i =0 ; i < r; i++) {
        for(int j =0 ; j < c; j++) {
            if(isOn(i,j,v,1)) {
                cout << 1 << ' ';
            } else {
                cout << 0 << ' ';
            }
        }
        cout << '\n';
    }
}

int dfs(int v) {
    int ct =0;
    for(int i =0 ; i < r; i++) {
        for(int j =0 ; j < c; j++) {
            if(isOn(i,j,v,0)) {
                if(i > 0 && isOn(i-1,j,v,0)) {
                    ct++;
                }
                if(j>0 && isOn(i,j-1,v,0)) {
                    ct++;
                }
            }
        }
    }

    return ct;
}
vector<int> bit[25];
void solve() {
    int n;
    ou = 1000*1000*1000;
    cin >> r >> c >> n;

    int mk = 1 << r*c;
    mk--;

    // cout << "MK " << mk << '\n';

    for(int i =0 ; i < (int)bit[n].size(); i++) {
        if(bit[n][i]<=mk) {
            int v =  dfs(bit[n][i]);
            ou = min(ou,v);

            // cout << "COBA " << bit[n][i] << '=' << v << '\n';
            //gbr(bit[n][i]);
        }
        if(ou == 0) {
            break;
        }
    }
    cout << ou << '\n';
}



int main() {
    for(int i =0; i<=1000*1000; i++) {
        int p = 0;
        int v =i;
        while(v) {
            if(v%2) {
                p++;
            }
            v/=2;
        }
        bit[p].push_back(i);
    }
    int tc;
    scanf("%d", &tc);
    for(int i = 1; i<=tc; i++) {
        printf("Case #%d: ",i);
        solve();
    }
}