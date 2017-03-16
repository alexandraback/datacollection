#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long numcut(long long time, const vector<int>& barbers)
{
    long long resp = 0;
    for(auto&& b : barbers)
    {
        resp += 1 + time/b;
    }
    
    return resp;
}

long long get_time(long long pos, const vector<int>& barbers)
{
    long long low = 0;
    long long high = 1000000000000000ll;
    while(low < high)
    {
        auto mid = (low + high)/2;
        auto ncut = numcut(mid, barbers);
        if(ncut < pos)
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
    
    return low;
}

int calc(long long mypos, const vector<int>& barbers)
{
    auto time = get_time(mypos, barbers);
    auto cut_before = numcut(time - 1, barbers);
    auto numgroup = mypos - cut_before;
    //cout << time << " " << cut_before << " " << numgroup << "\n";
    
    auto it = find_if(barbers.begin(), barbers.end(),
                      [&](int b) -> bool
                      {
                          if((time % b) == 0)
                          {
                              --numgroup;                              
                          }
                          
                          return (numgroup == 0);
                      });
    
    return static_cast<int>(it - barbers.begin()) + 1;
}

int main()
{
    int t;
    cin >> t;
    for(int lp=1;lp<=t;++lp)
    {
        int b, mypos;
        cin >> b >> mypos;
        vector<int> barbers(b);
        for(auto&& ba : barbers)
        {
            cin >> ba;
        }
        
        cout << "Case #" << lp << ": " << calc(mypos, barbers) << "\n";      
    }
    
    return 0;
}