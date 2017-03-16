#include "cstdio"
#include "cstring"
#include "vector"
#include "algorithm"
#include "utility"
#include "iostream"
#include "cmath"

using namespace std;

vector<pair<int,int> > convert(string);
int distance(vector<int>);

int main(void)
{
    int t;
    scanf("%d",&t);
    for(int test=1;test<=t;test++)
    {
        int n;
        scanf("%d",&n);
        vector<vector<pair<int,int> > > input;
        for(int i=0;i<n;i++)
        {
            string buff;
            cin >> buff;
            input.push_back(convert(buff));
        }
        
        printf("Case #%d: ", test);
        bool able = true;
        vector<vector<int> > nums;
        
        for(int i=0;i<input[0].size();i++)
        {
            vector<int> buff;
            nums.push_back(buff);
            nums[i].push_back(input[0][i].second);
        }
            
        for(int i=1;i<n;i++)
        {
            if(input[0].size() != input[1].size())
            {
                able = false;
                break;
            }
            
            for(int j=0;j<input[0].size();j++)
            {
                if(input[0][j].first!=input[i][j].first)
                {
                    able = false;
                    break;
                }
                nums[j].push_back(input[i][j].second);
            }
            
            if(!able)
                break;
        }
        
        if(!able)
            printf("Fegla Won\n");
        else
        {
            int ans = 0;
            for(int i=0;i<nums.size();i++)
                ans += distance(nums[i]);
            
            printf("%d\n",ans);
        }
    }
    return 0;
}

vector<pair<int,int> > convert(string x)
{
    vector<pair<int,int> > ret;
    char bef = x[0];
    int len = 1;
    
    for(int i=1;i<x.length();i++)
    {
        if(x[i]!=bef)
        {
            ret.push_back(make_pair(bef,len));
            bef = x[i];
            len = 1;
        }
        else
            len++;
    }
    
    ret.push_back(make_pair(bef,len));
    
    return ret;
}

int distance(vector<int> x)
{
    int ret = 200;
    for(int i=1;i<=100;i++)
    {
        int buff = 0;
        for(int j=0;j<x.size();j++)
            buff+=abs(i-x[j]);
        
        ret = min(ret, buff);
    }
    return ret;
}