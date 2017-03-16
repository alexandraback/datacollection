#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>

using namespace std;
int N,T;
char quale[101][101];
int quanti[101];
int numb[101][101];
int best[101];
int main()
{
    freopen("inputa.in","r",stdin);
    freopen("output.txt","w",stdout);
    cin >> T;
    string a;
    for(int t = 0; t < T; ++t){
        memset(quanti,0,sizeof(quanti));
        memset(numb,0,sizeof(numb));
        cout << "Case #" << t+1 << ": ";
        bool ok = true;
        cin >> N;
        for(int i = 0; i < N; ++i){
            cin >> a;
            quanti[i] = 1;
            quale[i][0] = a[0];
            numb[i][0] = 1;
            for(int j = 1; j < a.length(); ++j){
                if(a[j] != quale[i][quanti[i]-1])
                    quale[i][quanti[i]++] = a[j];
                numb[i][quanti[i]-1]++;
            }
        }


        int L = 0;
        int ans = 0;
        for(int i = 0; i < N; ++i)
            L = max(L,quanti[i]);
        for(int i = 0; i < N; ++i)
            if(quanti[i] != L){
                if(ok)cout << "Fegla Won" << endl;
                ok = false;
        }
        if(!ok) continue;
        for(int i = 0; i < L; ++i){
            char c = quale[0][i];
            for(int j = 0; j < N; ++j){
                if(quale[j][i] != c){
                    if(ok) cout << "Fegla Won" << endl;
                    ok = false;
                }else{
                    best[j] = numb[j][i];
                }

            }
            if(!ok) continue;
            sort(best,best+N);
            int pick = best[N/2];
            for(int j = 0; j < N; ++j)
                ans += abs(pick - best[j]);
        }
        if(!ok) continue;
        cout << ans << endl;

    }

    return 0;

}
