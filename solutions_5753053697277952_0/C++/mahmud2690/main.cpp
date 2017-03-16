#include <bits/stdc++.h>

using namespace std;

const int me = 1025;


int t, n;
int p[me];
int main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    freopen("input.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> t;
    for(int cc = 0; cc < t; cc ++){
        cin >> n;
        for(int i = 1; i <= n; i ++)
            cin >> p[i];
        int all = 0;
        vector<string> ans;
        for(int i = 1; i <= n; i ++)
            all += p[i];
        while(all > 0){
            if(all & 1){
                int pos = 1;
                for(int i = 1; i <= n; i ++)
                    if(p[i] > p[pos])
                        pos = i;
                all --;
                p[pos] --;
                string g = "";
                g.push_back((char)(pos + 'A' - 1));
                ans.push_back(g);
            }
            else{
                int pos = 1;
                for(int i = 1; i <= n; i ++)
                    if(p[i] > p[pos])
                        pos = i;
                all --;
                p[pos] --;
                string g = "";
                g.push_back((char)(pos + 'A' - 1));
                pos = 1;
                for(int i = 1; i <= n; i ++)
                    if(p[i] > p[pos])
                        pos = i;
                all --;
                p[pos] --;
                g.push_back((char)(pos + 'A' - 1));
                ans.push_back(g);
            }

        }
        cout << "Case #" << cc + 1 << ":";
        for(string i : ans)
            cout << " " << i;
        cout << endl;
    }

    return 0;
}
