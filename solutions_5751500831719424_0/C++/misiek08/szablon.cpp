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
        int i=0, j=0;
        for(; i<S[1].length(); )
        {
            char znak=S[1][i];
            //cout << "biore " << znak << endl;
            int licznik1=0, licznik2=0;
            while(S[1][i]==znak) {licznik1++; i++;}
            while(S[2][j]==znak) {licznik2++; j++;}
            //cout << licznik1 << " " << i << " " << licznik2 << " " << j << endl;
            if(licznik2==0) identyczne=false;
            result+=abs(licznik1-licznik2);
        }
        if(j<S[2].length()) identyczne=false;
        cout << "Case #" << lzd << ": ";
        if(!identyczne) cout << "Fegla Won" << endl;
        else cout << result << endl;
    }
    return 0;
}
