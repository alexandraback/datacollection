#include<algorithm>
#include<cstdio>
#include<iostream>
#include<map>
#include<set>
#include<sstream>
#include<queue>
#include<vector>

using namespace std;

#define forn(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(),v.end()

struct pto{
    long long x,y;
};

pto center;

int getCuad(const pto &p)
{
    if(p.y == center.y)
    {
        if(p.x > center.x)
            return 1;
        else
            return 5;
    }
    if(p.x == center.x)
    {
        if(p.y > center.y)
            return 3;
        else
            return 7;
    }
    if(p.x > center.x && p.y > center.y)
        return 2;
    if(p.x < center.x && p.y > center.y)
        return 4;
    if(p.x < center.x && p.y < center.y)
        return 6;
    return 8;
}

bool operator<(const pto &p1,const pto &p2)
{
    int a = getCuad(p1), b = getCuad(p2);
    if(a!=b)
        return a<b;
    if(a%2 == 1)
        return make_pair(p1.x,p1.y) < make_pair(p2.x,p2.y);
    if((p1.x-center.x)*(p2.y-center.y) == (p2.x-center.x)*(p1.y-center.y))
        return p1.x < p2.x;
    return (p1.x-center.x)*(p2.y-center.y) > (p2.x-center.x)*(p1.y-center.y);
}

bool mismoLado(pto p1, pto p2)
{
    return (p1.x-center.x)*(p2.y-center.y) >= (p2.x-center.x)*(p1.y-center.y);
}

int calc(int p1, int p2, int n)
{
    if(p1 < p2)
        return n-(p2-p1+1);
    else
        return p1-p2-1;
}

int almostchull(vector<pto> poly, int p){
    if(poly.size() <= 3)
        return 0;
    center = poly[p];
    swap(poly[p],poly[poly.size()-1]);
    poly.resize(poly.size()-1);
    sort(all(poly));
    int p1 = 0, p2 = 0;
    while(p2 < poly.size()-1 && mismoLado(poly[p1],poly[p2+1]))
        p2++;
    int res = poly.size()-1-p2;
    while(p1 < poly.size()-1)
    {
        p1++;
        if((p2+1)%poly.size() == p1)
            p2 = p1;
        do{
            if(!mismoLado(poly[p1],poly[(p2+1)%poly.size()]))
                break;
            p2 = (p2+1)%poly.size();
        }while((p2+1)%poly.size() != p1);
        res = max(0,min(res,calc(p1,p2,poly.size())));
    }
    return res;
}

vector<pto> vec;

int main()
{
    freopen("C-small.in","r",stdin);
    freopen("C-small.out","w",stdout);
	int casos;
	cin >> casos;
	for(int casito = 1; casito <= casos; casito++)
    {
        int n;
        cin >> n;
        vec.resize(n);
        forn(i,n)
            cin >> vec[i].x >> vec[i].y;
        cout << "Case #"<<casito<<":"<< endl;
        forn(i,n)
            cout << almostchull(vec,i)<<endl;

    }
}
