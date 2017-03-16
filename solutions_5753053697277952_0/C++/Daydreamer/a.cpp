#include <iostream>
#include <sstream>
using namespace std;
stringstream s;
bool dfs(int n, int* a, int sum)
{   
    if (sum == 0)
    {  return true; }

    for (int i = 0; i < n; ++i)
        if (a[i] > sum/2)
        {   return false;
        }


    for (int i = 0; i < n; ++i)
    {   for (int j = i; j < n; ++j)
        {   if (a[i] > 0)
                --a[i]; 
            else 
                continue;

            if (a[j] > 0)
            {  --a[j]; }
            else 
            { ++a[i]; continue; }
            
            if (dfs(n, a, sum-2)) // Valid exist
            {   s << char('A'+i) << char('A'+j) << " ";
                return true;
            }
            ++a[i];
            ++a[j];
        }
        if (a[i] > 0)
        {   a[i]--;
            if (dfs(n, a, sum-1)) // Valid exist
            {   s << char('A'+i) << " ";
                return true;
            }
        }
    }
    
    return false;
}
int main()
{
    int T;
    cin >> T;
    for (int kase = 1; kase <= T; kase++)
    {   int n;
        cin >> n;
        int a[n], sum = 0;
        for (int i = 0; i < n; ++i) 
        {   cin >> a[i];
            sum += a[i];
        }
        
        dfs(n, a, sum);
        string str;
        getline(s, str);

        for (int i = 0; i < str.length()/2; ++i)
            swap(str[i], str[str.length()-1-i]);
        
        cout << "Case #" << kase << ": " << str << endl;
        s.clear();
    }
    return 0;
}
