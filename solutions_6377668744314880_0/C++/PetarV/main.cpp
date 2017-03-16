/*
 Petar 'PetarV' Velickovic
 Task: Logging
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <complex>
#include <unordered_set>
#include <unordered_map>

#define MAX_N 3003

#define DPRINTC(C) printf(#C " = %c\n", (C))
#define DPRINTS(S) printf(#S " = %s\n", (S))
#define DPRINTD(D) printf(#D " = %d\n", (D))
#define DPRINTLLD(LLD) printf(#LLD " = %lld\n", (LLD))
#define DPRINTLF(LF) printf(#LF " = %.5lf\n", (LF))

using namespace std;
typedef long long lld;
typedef unsigned long long llu;

int t;
int n;

struct Point
{
    lld X, Y;
    int sol;
    int idd;
    bool operator <(const Point &p) const
    {
        return (idd < p.idd);
    }
};
Point P[MAX_N];
Point R;

inline bool cmp(Point A, Point B)
{
    return atan2(A.Y-R.Y,A.X-R.X) < atan2(B.Y-R.Y,B.X-R.X);
}

inline lld CCW(Point a, Point b, Point c)
{
    return ((b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X));
}

inline int GrahamScan(vector<Point> &cH)
{
    int min_id = 1;
    for (int i=2;i<=n;i++)
    {
        if (P[i].Y < P[min_id].Y || (P[i].Y == P[min_id].Y && P[i].X < P[min_id].X))
        {
            min_id = i;
        }
    }
    swap(P[1], P[min_id]);
    R = P[1];
    sort(P+2, P+n+1, cmp);
    
    P[0] = P[n];
    int HullSize = 1;
    
    for (int i=2;i<=n;i++)
    {
        while (CCW(P[HullSize-1], P[HullSize], P[i]) <= 0)
        {
            if (HullSize > 1) HullSize--;
            else if (i == n) break;
            else i++;
        }
        swap(P[++HullSize], P[i]);
    }
    
    for (int i=1;i<=HullSize;i++) cH.push_back(P[i]);
    return HullSize;
}

inline lld crossProduct(Point a, Point b, Point c)
{
    return ((b.X - a.X) * (c.Y - a.Y) - (b.Y - a.Y) * (c.X - a.X));
}

inline bool isLeft(Point a, Point b, Point c)
{
    return (crossProduct(a, b, c) > 0);
}

inline bool isRight(Point a, Point b, Point c)
{
    return (crossProduct(a, b, c) < 0);
}

int main()
{
    freopen("/Users/PetarV/HackerCup/C-small-attempt1.in.txt","r",stdin);
    freopen("/Users/PetarV/HackerCup/C-small-out.txt","w",stdout);
    
    scanf("%d", &t);
    for (int f=1;f<=t;f++)
    {
        scanf("%d", &n);
        for (int i=1;i<=n;i++)
        {
            scanf("%lld%lld", &P[i].X, &P[i].Y);
            P[i].idd = i;
            P[i].sol = -1;
        }
        
        //vector<Point> cH;
        //int m = GrahamScan(cH);
        
        //for (int i=1;i<=m;i++) P[i].sol = 0;
        
        for (int i=1;i<=n;i++)
        {
            P[i].sol = -1;
            for (int j=1;j<=n;j++)
            {
                if (j == i) continue;
                int cnt_left = 0, cnt_right = 0;
                for (int k=1;k<=n;k++)
                {
                    if (isLeft(P[i], P[j], P[k])) cnt_left++;
                    else if (isRight(P[i], P[j], P[k])) cnt_right++;
                }
                if (cnt_left < P[i].sol || P[i].sol == -1) P[i].sol = cnt_left;
                if (cnt_right < P[i].sol || P[i].sol == -1) P[i].sol = cnt_right;
            }
        }
        
        //sort(P + 1, P + n + 1);
        printf("Case #%d:\n", f);
        for (int i=1;i<=n;i++)
        {
            if (n == 1) printf("0\n");
            else printf("%d\n", P[i].sol);
        }
    }
    
    return 0;
}
