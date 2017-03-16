#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cstdio>
#include <sstream>
#include <stack>
#include <cmath>
#include <queue>
#include <set>
using namespace std;
 
typedef vector < string > vs;
typedef vector <int> vi;
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define deb(x) cout << #x << ": " << x << endl;
#define debv(x) for(int i = 0; i < (x).size(); i++) cout << x[i] << ' '; cout << endl;

vs strsp(string a, string delim=" ")
{
    vs ret;
    string cr = "";
    for(int i = 0; i < a.size(); i++)
    {
 	   if(delim.find(a[i])==string::npos) cr += a[i];
 	   else { if(cr.size()) ret.push_back(cr); cr = ""; }
    }
    if(cr.size()) ret.push_back(cr);
    return ret;
}

int main()
{
	int test_cases = 0;
	cin >> test_cases;

	for(int test_case = 1; test_case <= test_cases; test_case++)
	{
        int N;
        cin >> N;
        int shrooms[N];
        for(int i = 0; i < N; i++)
        {
            cin >> shrooms[i];
        }
        int total_diff = 0;
        int max_diff = 0;
        for(int i = 1; i < N; i++)
        {
            total_diff += max(0, shrooms[i-1]-shrooms[i]);
            max_diff = max(max_diff, shrooms[i-1]-shrooms[i]);
        }

        int total_eat = 0;
        for(int i = 0; i < N-1; i++)
        {
            total_eat += min(max_diff, shrooms[i]);
        }


        printf("Case #%d: %d %d\n", test_case, total_diff,total_eat);
	}
}
