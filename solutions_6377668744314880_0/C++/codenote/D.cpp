// http://stanford.edu/~liszt90/acm/notebook.html#file8
// Please Do not disqualify me :)

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define N 30000

//#define REMOVE_REDUNDANT 0

typedef double T;
const T EPS = 1e-7;
struct PT {
  T x, y;
  int id;
  PT() {}
  PT(T x, T y,int id) : x(x), y(y), id(id){}
  bool operator<(const PT &rhs) const { return make_pair(y,x) < make_pair(rhs.y,rhs.x); }
  bool operator==(const PT &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};

T cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }
T area2(PT a, PT b, PT c) { return cross(a,b) + cross(b,c) + cross(c,a); }

#ifdef REMOVE_REDUNDANT
bool between(const PT &a, const PT &b, const PT &c) {
  return (fabs(area2(a,b,c)) < EPS && (a.x-b.x)*(c.x-b.x) <= 0 && (a.y-b.y)*(c.y-b.y) <= 0);
}
#endif

void ConvexHull(vector<PT> &pts) {
  sort(pts.begin(), pts.end());
  pts.erase(unique(pts.begin(), pts.end()), pts.end());
  vector<PT> up, dn;
  for (int i = 0; i < pts.size(); i++) {
    while (up.size() > 1 && area2(up[up.size()-2], up.back(), pts[i]) > 0) up.pop_back();
    while (dn.size() > 1 && area2(dn[dn.size()-2], dn.back(), pts[i]) < 0) dn.pop_back();
    up.push_back(pts[i]);
    dn.push_back(pts[i]);
  }
  pts = dn;
  for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);

#ifdef REMOVE_REDUNDANT
  if (pts.size() <= 2) return;
  dn.clear();
  dn.push_back(pts[0]);
  dn.push_back(pts[1]);
  for (int i = 2; i < pts.size(); i++) {
    if (between(dn[dn.size()-2], dn[dn.size()-1], pts[i])) dn.pop_back();
    dn.push_back(pts[i]);
  }
  if (dn.size() >= 3 && between(dn.back(), dn[0], dn[1])) {
    dn[0] = dn.back();
    dn.pop_back();
  }
  pts = dn;
#endif
}



struct nod
{
    double x,y;
}nods[N+10];
int main()
{
    int tc,t;
    freopen("C:\\Users\\dell\\Downloads\\inputd.txt","r",stdin);
    freopen("C:\\Users\\dell\\Desktop\\temp\\CODING\\REPOSITORY\\GCJ\\2015\\Round 1A\\outputD2.txt","w",stdout);
    scanf("%d",&tc);
    for(t = 1 ; t<=tc ; t++)
    {

        int n,i,j;
        scanf("%d",&n);
        int mn[20];
        for(i = 1 ; i<=n ; i++)
        {
            mn[i] = n;
            int x;
            int y;
            scanf("%d %d",&x,&y);
            nods[i].x = x;
            nods[i].y = y;
        }
        int p2 = pow(2,n);
        for(int i = 0 ; i<p2 ; i++)
        {
            vector <PT> pts;
            int f = 0;
            int temp = i;
            int g = 0;
            while(temp > 0)
            {
                f++;
                if(temp%2 == 1)
                {
                    g++;
                    pts.push_back(PT(nods[f].x,nods[f].y,f));
                }
                temp = temp/2;
            }
            ConvexHull(pts);
            int sz = pts.size();
            for(int j = 0 ; j<sz ; j++)
            {
                //printf("%d ",pts[j].id);
                mn[pts[j].id] = min(mn[pts[j].id],n-g);
            }
            //printf("%d\n",n-g);
        }


        printf("Case #%d:\n",t);
        for(i = 1 ; i<=n ; i++) printf("%d\n",mn[i]);
        /*ConvexHull(pts);
        int sz = pts.size();
        //for(int j = 0 ; j<sz ; j++) printf("%lf %lf\n",pts[j].x,pts[j].y);

        for(i = 1 ; i<=n ; i++)
        {
            int mn = n + 1;
            for(int j = 0 ; j<sz ; j++)
            {
                double C = (pts[j].x - nods[i].x)*nods[i].y - (pts[j].y - nods[i].y)*nods[i].x;
                int cntp = 0,cntn=0;
                for(int k = 0 ; k<sz ; k++)
                {
                    double D = (pts[j].x - nods[i].x)*pts[k].y - (pts[j].y - nods[i].y)*pts[k].x;
                    D = D - C;
                    if(D > EPS) cntp++;
                    if(D < -EPS) cntn++;
                }
                mn = min(mn,min(cntp,cntn));
            }
            printf("%d\n",mn);
        }*/
    }
    return 0;
}


