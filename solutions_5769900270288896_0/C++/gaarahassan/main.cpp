#include <bits/stdc++.h>
#define mp make_pair
#define ll long long

using namespace std;

vector<int>v;
vector <vector <int> > vv;
int  r , c;
bool arr[10][10];
int anss=INT_MAX;
void check()
{
    int ans=0;
    for(int i = 0 ; i < r ; i++)
    {
        for(int j = 0 ; j < c ; j++)
        {
            if(arr[i][j])
            {
                if(j+1 < c && arr[i][j+1])
                    ans++;
                if(i+1 < r && arr[i+1][j])
                    ans++;
            }
        }
    }
    anss=min(ans,anss);
}

void solve(int i , int j , int n)
{
    if(n==0)
    {
        check();
        return;
    }
    if(j==c)
    {
        i++;
        j=0;
    }
    if(i==r)
        return;
    arr[i][j]=true;
    solve(i , j+1 , n-1);
    arr[i][j]=false;
    solve(i , j+1 , n);
    return ;
}

int main()
{
   freopen("in.txt" , "r" , stdin);
   freopen("out.txt" , "w" , stdout);
    int t;
    int a ;
    cin >> t ;
    a=0;
    while(a++ < t)
    {
        int n;
        cin >> r >> c >> n;
        anss=INT_MAX;
        solve(0 , 0 , n);
        cout << "Case #" << a << ": " << anss << endl;
    }
}
