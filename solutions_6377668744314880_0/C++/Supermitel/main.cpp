#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

struct punct
{
    double x, y;
    int nrcrt;
    punct(double x = 0, double y = 0):x(x), y(y){}
};

inline double det(punct a, punct b, punct c)
{
    return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
}

punct a[3010];
int apare[3010];
int nap;

vector<punct> v;

int mat[3010][3010];
int minim[3010];
int n;

bool cmp(punct a, punct b)
{
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

bool operator == (punct a, punct b)
{
    return a.x == b.x && a.y == b.y;
}

void citire()
{
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> a[i].x >> a[i].y;
        a[i].nrcrt = i;
        minim[i] = n;
        apare[i] = 0;
        nap = 0;
    }
}

void afisare()
{
    for(int i = 1; i <= n; i++)
        printf("%d\n", minim[i]);
}

void infas()
{
    sort(a, a+n, cmp);

    for(int i = 0; i < n; i++)
        if(apare[i])
    {
        while(v.size() >= 2 && det(v[v.size()-2], v[v.size()-1], a[i]) < 0) //-0.00000001
            v.pop_back();
        v.push_back(a[i]);
    }

    for(int i = n-2; i >= 0; i--)
        if(apare[i])
    {
        while(v.size() >= 2 && det(v[v.size()-2], v[v.size()-1], a[i]) < 0
              || v[v.size()-1] == a[i])
            v.pop_back();
        v.push_back(a[i]);
    }

    if(v.size() > 0 && v.back() == v.front())
        v.pop_back();
}

void solve()
{
    while(apare[n] == 0)
    {
        v.clear();
        infas();
        for(int i = 0; i < v.size(); i++)
            minim[v[i].nrcrt] = min(minim[v[i].nrcrt], n-nap);
        int i = 0;
        while(apare[i])
        {
            apare[i] = 0;
            nap--;
            i++;
        }
        apare[i] = 1;
        nap++;
    }
}

int main()
{
    freopen("log.in", "r", stdin);
    freopen("log.out", "w", stdout);

    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++)
    {
        printf("Case #%d:\n", i);
        citire();
        solve();
        afisare();
    }

    return 0;
}
