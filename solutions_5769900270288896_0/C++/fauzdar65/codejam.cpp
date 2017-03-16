#include <bits/stdc++.h>
/*#include <boost/multiprecision/cpp_int.hpp> */
#define ll long long
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define gc getchar_unlocked
#define pp pair<int,int>
#define bigint boost::multiprecision::cpp_int
#define bsize 600
using namespace std;

int n,r,c;

int adjj(vector<int> v)
{
    int ret=0;
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            if((v[i] & (1 << j))==0)continue;

            if((i+1)<r && (v[i+1] & (1 << j))!=0)ret++;
            if((j+1)<c && (v[i] & (1 << (j+1)))!=0)ret++;
        }
    }
    return ret;
}

void solve(int posx,int posy,vector<int> v,int &an,int rem)
{
    if(posx==r)
    {
        if(rem!=0)return;

      //  cout<<v[0]<<" "<<c<<endl;
        int tt=adjj(v);
        if(tt<an)an=tt;
        return;
    }

    if(posy<(c-1))
    {

        solve(posx,posy+1,v,an,rem);
        v[posx]=v[posx] | (1 << posy);
        if(rem>0)solve(posx,posy+1,v,an,rem-1);
        return;
    }
     solve(posx+1,0,v,an,rem);
        v[posx]=v[posx] | (1 << c-1);
        if(rem>0)solve(posx+1,0,v,an,rem-1);
}
int main()
{
   int T,cas=1;
	cin>>T;

	while(T--)
	{

    cin>>r>>c>>n;
    vector<int> v;
    v.resize(r+1,0);
    int ans=1000000;

    solve(0,0,v,ans,n);





	cout<<"Case #"<<cas++<<": "<<ans<<"\n";
	}

return 0;
}
