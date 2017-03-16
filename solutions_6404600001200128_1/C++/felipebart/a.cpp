#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calc_any(const vector<int>& mushrooms)
{
    int n = mushrooms.size();
    int resp = 0;
    for(int i=1;i<n;++i)
    {
        resp += max(0, mushrooms[i-1] - mushrooms[i]);
    }
    
    return resp;
}

int calc_const(const vector<int>& mushrooms)
{
    int n = mushrooms.size();
    int minrate = 0;
    for(int i=1;i<n;++i)
    {
        minrate = max(minrate, mushrooms[i-1] - mushrooms[i]);   
    }
    
    int resp = 0;
    for(int i=0;i<n-1;++i)
    {
        resp += min(minrate, mushrooms[i]);
    }
    
    return resp;
}

int main()
{
    int t;
    cin >> t;
    for(int lp=1;lp<=t;++lp)
    {
        int n;
        cin >> n;
        vector<int> mushrooms(n);
        for(auto&& m : mushrooms)
        {
            cin >> m;
        }
        
        cout << "Case #" << lp << ": " << calc_any(mushrooms) << " " << calc_const(mushrooms) << "\n";     
    }
    return 0;
}