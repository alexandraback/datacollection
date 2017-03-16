#include<bits/stdc++.h>
#define long long ll
#define loop(i, a, b)  for(int i=a;i<b;i++)
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t, n, x, len, sum, k;
    bool ans;
    char c;
    string s1, s2;
    int cnt[256];
    cin>>t;
    loop(x, 1, t+1)
    {
        sum = 0;
        ans = true;
        int cntmx[105] = {0};
        int cntmn[105];
        loop(i, 0, 105)
            cntmn[i] = 101;
        int cnts[105] = {0};
        cin>>n;
        string s[n];
        loop(i, 0, n)
            cin>>s[i];
        len = s[0].size();
        s1 = "";
        s1 += s[0][0];
        c = s[0][0];
        k = 0;
        loop(i, 1, len)
        {
            if(s[0][i]==c)
                cnts[k]++;
            else
            {
                s1 += s[0][i];
                c = s[0][i];
                k++;
            }
        }
        loop(i, 1, n)
        {
            memset(cnt, 0, sizeof cnt);
            s2 = "";
            len = s[i].size();
            c = s[i][0];
            s2 += c;
            k = 0;
            loop(j, 1, len)
            {
                if(s[i][j]==c)
                    cnt[k]++;
                else
                {
                    s2 += s[i][j];
                    c = s[i][j];
                    k++;
                }
            }
            if(s1!=s2)
            {
                ans = false;
                break;
            }
            else
            {
                loop(j, 0, 105)
                {
                    cntmx[j] = max(cntmx[j], cnt[j]);
                    cntmn[j] = min(cntmn[j], cnt[j]);
                }
            }
        }
//        cout<<s1<<' '<<s2<<endl;
//        loop(i, 0, 101)
//        {
//            cout<<"cntmx "<<char(i)<<": "<<cntmx[i]<<" cntmn "<<char(i)<<": "<<cntmn[i]<<" cntms "<<char(i)<<": "<<cnts[i]<<endl;
//        }
        cout<<"Case #"<<x<<": ";
        if(ans)
        {
            loop(i, 0, 101)
                sum += max(abs(cntmn[i] - cnts[i]), abs(cntmx[i] - cnts[i]));
            cout<<sum<<endl;
        }
        else
            cout<<"Fegla Won\n";
    }
    return 0;
}
