#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const string f="gcj12";
const string fin=f+".in";
const string fout=f+".out";

int arr[26];

void set2Max()
{
    while(1)
    {
        int mxi=max_element(arr,arr+26)-arr;
        if(count(arr,arr+26,arr[mxi])>1)
            break;
        cout<<" "<<(char)(mxi+'A');
        arr[mxi]--;
    }
}

void solve()
{
    int mx=*max_element(arr,arr+26);
    int ai=-1,bi=-1;
    for(int i=0;i<26 && bi==-1;i++)
    {
        if(arr[i]==mx)
        {
            if(ai==-1)
                ai=i;
            else
                bi=i;
        }
    }
    for(int i=0;i<26;i++)
    {
        if(i==ai || i==bi)
            continue;
        while(arr[i])
            arr[i]--,cout<<" "<<(char)(i+'A');
    }
    while(arr[ai])
        arr[ai]--,arr[bi]--,cout<<" "<<(char)(ai+'A')<<(char)(bi+'A');
    cout<<"\n";
}

int main()
{
    freopen(fin.c_str(),"r",stdin);
    freopen(fout.c_str(),"w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin>>t;
    int T=0;
    while(t--)
    {
        T++;
        int n;
        cin>>n;
        memset(arr,0,sizeof arr);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<"Case #"<<T<<":";
        set2Max();
        solve();
    }
    return 0;
}
