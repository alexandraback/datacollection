#include <iostream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;
int dp[200][200];
string group(string a, int i)
{
    string ans;
    ans += a[0];
    int k = 0;
    dp[k][i]++;
    for(int j = 1;j < a.length(); j++)
    {
        if(a[j] != a[j-1])
        {
            ans+=a[j];
            dp[++k][i]++;
        }
        else
        {
            dp[k][i]++;
        }
    }
    return ans;
}

int main() {
    int Case = 1;
    int t,i,j,n;
    cin>>t;
    while(t--)
    {
        for(i = 0; i < 200; i++)
            for(j = 0; j < 200; j++)
                dp[j][i] = 0;
        cin>>n;
        string temp;
        string firstone;
        int flag = 1;
        for(i = 0; i < n; i++)
        {
            cin>>temp;
            if(i == 0)
                firstone = group(temp,i);
            else if(firstone != group(temp,i))
            {
                cout<<"Case #"<<Case++<<": Fegla Won"<<endl;
                flag = 0;
            }
        }
        if(flag == 0) continue;
        for(i = 0; i < firstone.length(); i++)
        {
            sort(dp[i],dp[i]+n);
        }
        int num = 0;
        for(i = 0; i < firstone.length(); i++)
        {
            int mid = dp[i][n/2];
            for(j = 0; j < n ; j++)
            {
                num += abs(dp[i][j] - mid);
            }
        }
        int num1 = 0;
        for(i = 0; i < firstone.length(); i++)
        {
            int mid = dp[i][(n-1)/2];
            for(j = 0; j < n ; j++)
            {
                num1 += abs(dp[i][j] - mid);
            }
        }
       
        cout<<"Case #"<<Case++<<": "<<num<<endl;
        
    }
    
    return 0;
}
