#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<list>
#include<stack>
#include<deque>
#include<cmath>
#include<cstdio>
#define MAX_N 21
using namespace std;

int T, N, result;
bool identyczne;
string S[102];
int licznik[102];
int it[102];
int ile[102];
//string A, B;

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> T;
    for(int lzd=1; lzd<=T; ++lzd)
    {
        cin >> N;
        for(int i=1; i<=N; ++i) cin >> S[i];
        sort(S+1, S+N+1);
        identyczne=true; result=0;
        for(int i=2; i<=N; ++i) if(S[i][0]!=S[i-1][0]) identyczne=false;
        int i=0;
        for(int i=0; i<S[1].length(); )
        {
            char znak=S[1][i];
            int dodaj=0;
            //cout << "biore " << znak << endl;
            while(S[1][i]==znak) {ile[1]++; i++;}
            for(int j=2; j<=N; ++j)
            {
                while(S[j][it[j]]==znak) {ile[j]++; it[j]++;}
            }
            sort(ile+1, ile+N+1);
            //for(int k=1; k<=N; ++k) cout << ile[k] << " ";
            //cout << endl;
            if(N%2)
            {
                int wez=(N+1)/2;
                for(int k=1; k<=N; ++k)
                {
                    if(ile[k]==0) identyczne=false;
                    if(k==wez) continue;
                    dodaj+=abs(ile[k]-ile[wez]);
                }
            }
            else
            {
                int wez1=N/2, wez2=N/2+1, temp1=0, temp2=0;
                for(int k=1; k<=N; ++k)
                {
                    if(ile[k]==0) identyczne=false;
                    if(k==wez1) continue;
                    temp1+=abs(ile[k]-ile[wez1]);
                }
                for(int k=1; k<=N; ++k)
                {
                    if(ile[k]==0) identyczne=false;
                    if(k==wez2) continue;
                    temp2+=abs(ile[k]-ile[wez2]);
                }
                dodaj+=min(temp1, temp2);
            }
            result+=dodaj;
            for(int k=1; k<=N; ++k) ile[k]=0;
        }
        for(int i=2; i<=N; ++i) if(it[i]<S[i].length()) identyczne=false;
        cout << "Case #" << lzd << ": ";
        if(!identyczne) cout << "Fegla Won" << endl;
        else cout << result << endl;
        for(int i=0; i<=N; ++i) ile[i]=it[i]=0;
    }
    return 0;
}
