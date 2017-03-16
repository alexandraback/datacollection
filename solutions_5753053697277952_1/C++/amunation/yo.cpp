#include<bits/stdc++.h>
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define eb emplace_back
#define pb push_back
#define ll unsigned long long
#define mp make_pair
#define x first
#define y second
#define mod 1000000007
#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b
using namespace std;
bool cmp(pair < int , int > a , pair < int , int > b)
{
    return a.x>b.x;
}
bool all(vector < pair < int , int > > &sd)
{
    rep(i,0,sd.size())
    {
    if(sd[i].x!=1)
        return false;
    }
    return true;
        
}
void solve(int j)
{
    int n;
    vector < pair < int , int >  > sd;
    cin >> n;
    int tmp;
    int i;
    rep(i,0,n)
    {
        cin >> tmp;
        sd.pb(mp(tmp,i));
    }
        cout << "Case #" << j+1 << ": ";   
    while(true)
    {
        int c=0;
        
         rep(i,0,sd.size())
        {
            if(sd[i].x==1)
                c++;
                
        }
        if(c==n)
            break;
        sort(sd.begin(),sd.end(),cmp);
        if(sd[0].x==sd[1].x)
        {
            char c1,c2;
            c1=sd[0].y+'A';
            c2=sd[1].y+'A';
            cout << c1 << c2 << " ";
            sd[0].x--;
            sd[1].x--;
        }
        else{
            char c1=sd[0].y+'A';
            cout << c1 << " ";
            sd[0].x--;
        }
    }
    rep(i,0,sd.size()-2)
    {
        char c1=sd[i].y+'A';
        cout << c1 << " ";
    }
    //char c1,c2;
    char c1=sd[n-2].y+'A';
     char c2=sd[n-1].y+'A';
     
     cout << c1 << c2 << " ";
     cout << "\n";
     return;
}
int main()
{
    
    int t;
    cin >> t;
    int j;
    rep(j,0,t)
    {
        solve(j);
    }
    return 0;
}