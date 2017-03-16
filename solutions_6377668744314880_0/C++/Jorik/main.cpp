#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstdlib>
#include <set>
#include <map>
#include <fstream>

#define PI 3.14159265359

using namespace std;
typedef unsigned long long ull;

bool right_turn(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3)
{
    long long x1 = p1.first-p2.first;
    long long y1 = p1.second-p2.second;
    long long x2 = p3.first-p2.first;
    long long y2 = p3.second-p2.second;
    return (x1*y2-x2*y1) > 0;
}

void convex_hull(vector< pair<int, int> > &points, vector<int> &indices, vector<bool> &used)
{
    vector< pair<pair<int, int>, int> > actual_points;
    for(int i=0; i<indices.size(); i++)
    {
        actual_points.push_back(make_pair(points[indices[i]], indices[i]));
    }

    sort(actual_points.begin(), actual_points.end());
    /*if(indices.size() == 5)
    {
        for(int i=0; i<actual_points.size(); i++)
        {
            cout << actual_points[i].first.first << " " << actual_points[i].first.second << " " << actual_points[i].second << endl;
        }
    }*/

    vector<int> actual_used;
    vector<int> lower;
    for(int i=0; i<actual_points.size(); i++)
    {
        while(lower.size() >= 2 && right_turn(actual_points[lower[lower.size()-2]].first, actual_points[lower[lower.size()-1]].first, actual_points[i].first))
        {
            /*if(indices.size() == 5)
            {
                cout << lower[lower.size()-2] << " " << lower[lower.size()-1] << " " << i << endl;
            }*/
            lower.pop_back();
            actual_used.pop_back();
        }
        lower.push_back(i);
        actual_used.push_back(actual_points[i].second);
    }

    /*if(indices.size() == 5)
    {
        for(int i=0; i<lower.size(); i++)
        {
            cout << lower[i] << " ";
        }
        cout << endl;
    }*/
    vector<int> upper;
    for(int i=actual_points.size()-1; i>=0; i--)
    {
        while(upper.size() >= 2 && right_turn(actual_points[upper[upper.size()-2]].first, actual_points[upper[upper.size()-1]].first, actual_points[i].first))
        {
            upper.pop_back();
            actual_used.pop_back();
        }
        upper.push_back(i);
        actual_used.push_back(actual_points[i].second);
    }

    for(int i=0; i<actual_used.size(); i++)
    {
        used[actual_used[i]] = true;
    }
}

int main()
{
    freopen("inp.in", "r", stdin);
    freopen("outp.out", "w", stdout);
    int tc;
    scanf("%d", &tc);
    for(int kras=1; kras<=tc; kras++)
    {
        int n;
        scanf("%d", &n);
        vector< pair<int, int> > points(n);
        for(int i=0; i<n; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            points[i] = make_pair(a, b);
        }
        vector<int> ans(n, 10000000);
        for(int test=0; test<(1<<n); test++)
        {
            int enen=0;
            vector<int> indices;
            for(int i=0; i<n; i++)
            {
                if(test & (1<<i))
                {
                    enen++;
                    indices.push_back(i);
                }
            }
            if(enen <= 2)
            {
                for(int i=0; i<indices.size(); i++)
                {
                    ans[indices[i]] = min(ans[indices[i]], n-enen);
                }
            }
            else
            {
                vector<bool> used(n, false);
                convex_hull(points, indices, used);
                for(int i=0; i<indices.size(); i++)
                {
                    if(used[indices[i]])
                    {
                        ans[indices[i]] = min(ans[indices[i]], n-enen);
                    }
                }
            }
        }
        printf("Case #%d:\n", kras);
        for(int i=0; i<n; i++)
        {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
