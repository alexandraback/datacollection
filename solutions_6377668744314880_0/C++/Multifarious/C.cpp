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
#define PI 3.14159265359
double eps = 1e-7;
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
        int x[N], y[N], total[N];
        for(int i = 0; i < N; i++)
        {
            cin >> x[i] >> y[i];
        }

        for(int i = 0; i < N; i++)
        {
            vector<double> angles;
            for(int j = 0; j < N; j++)
            {
                if (i == j)
                    continue;
                int ydiff = y[j] - y[i];
                int xdiff = x[j] - x[i];
                if(xdiff == 0)
                {
                    if(ydiff < 0)
                    {
                        angles.push_back(270.0);
                        continue;
                    }
                    else
                    {
                        angles.push_back(90.0);
                        continue;
                    }
                }
                double my_angle = atan2(ydiff, xdiff) * 180.0 / PI;
                if(my_angle < 0)
                    my_angle += 360.0;
                angles.push_back(my_angle);

            }
            sort(angles.begin(), angles.end());
            int mn = N+1;
            int left = 0, right = 0;
            for(int idx = 1; idx < angles.size(); idx++)
            {
                if(angles[idx]-angles[0] > 180.0+eps)
                {
                    right = idx;
                    break;
                }

            }
            if(left == right)
            {
                total[i] = 0;
                continue;
            }
            else
            {
                mn = min(mn, N-1-(right-left));
                for(int left = 1; left < angles.size(); left++)
                {
                    while(true)
                    {
                        double ex = 0.0;
                        if(angles[right] < angles[left])
                            ex = 360.0;

                        if((angles[right] - angles[left] + ex) > 180.0+eps)
                        {
                            break;
                        }
                        if(right == left)
                        {
                            break;
                        }
                        right++;
                        if(right == (N-1))
                            right = 0;
                    }
                    if(left == right)
                    {
                        mn = 0;
                        break;
                    }
                    else
                    {
                        mn = min(mn, (N-1 - ( (N-1)+right-left)%(N-1) ));
                    }
                }
                total[i] = mn;
            }
        }
		cout << "Case #" << test_case << ':' << endl;
        for(int idx = 0; idx < N; idx++)
        {
            cout << total[idx] << endl;
        }
	}
}
