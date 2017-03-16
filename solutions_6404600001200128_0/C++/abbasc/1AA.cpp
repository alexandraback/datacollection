#include <bits/stdc++.h>
//#define DEBUG
using namespace std;

int main()
{
    #ifndef DEBUG

    ifstream in("1aa_s1.in");
    cin.rdbuf(in.rdbuf());
    ofstream out("1aa_s1.out");
    cout.rdbuf(out.rdbuf());

    #endif

    int T;
    cin>>T;
    for(int X = 1; X <= T; X++)
    {
        int N;
        cin>>N;
        vector<int> m(N);
        int ans1= 0,d = 0,ans2 = 0;
        for(int i = 0; i < N; i++)
        {
            cin>>m[i];
            if(i > 0 && m[i-1] > m[i])
            {
                ans1 += m[i-1] - m[i];
                d = max(d,m[i-1] - m[i]);
            }
        }
        for(int i = 0; i < N-1; i++)
        {
            ans2 += min(d,m[i]);
        }

        cout<<"Case #"<<X<<": "<<ans1<<" "<<ans2<<endl;



    }
    return 0;
}
