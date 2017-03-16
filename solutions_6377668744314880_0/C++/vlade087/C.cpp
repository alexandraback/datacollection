#include<stdio.h>
#include<iostream>
#include<math.h>
#include<ctype.h>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<string.h>
#include<algorithm>
#include <complex>
using namespace std;
#define ll long long
#define MaxN 200002
const double EPS = 1e-9;
typedef complex<double> P;
bool compareP(const P &a, const P &b) {
    return real(a)!=real(b) ? real(a)<real(b) : imag(a)<imag(b);
}
struct L : vector<P> {
    L (const P &a, const P &b){
        push_back(a);
        push_back(b);
    }
};
double cross(P a, P b){
    return imag(conj(a)*b);
}
double dot(P a, P b){
    return real(conj(a)*b);
}
int ccw(P a, P b, P c){ //Orientacion de 3 puntos used in Convex Hull
    b-=a; c-=a;
    if (cross(b,c) > 0) return +1;  //counter clockwise
    if (cross(b,c) < 0) return -1;  //clockwise
    if (dot(b,c) < 0) return +2;    //c - a - b line
    if (norm(b)<norm(c)) return -2; //a - b - c line
    return 0;
}
bool intersectSP (L s,P p){//Interseccion segmento y punto
    return abs(s[0]-p) + abs(s[1]-p) - abs(s[1]-s[0]) < EPS;  //desigualdad triangular
}

typedef vector<P> Pol;

Pol convexHull(Pol ps){
    int n = ps.size(), k=0;
    sort(ps.begin(), ps.end(), compareP);
    Pol ch (2*n);
    for (int i = 0; i <n; ch [k++] = ps [i++])
        while (k >= 2 && ccw(ch[k- 2 ], ch[k- 1 ], ps[i]) <= 0 ) --k;
    for ( int i = n-2 , t = k+1 ; i >= 0 ; ch[k++] = ps[i--])
        while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0 ) --k;
    ch.resize(k-1);
    return ch;
}

enum{OUT, ON, IN};
#define next(P,i) P[(i+1)%P.size()]

int pointInPolygon(const Pol &pol, const P &p){
    bool in = false;
    for (int i=0; i<pol.size(); i++){
        P a = pol[i] - p, b = next(pol,i) - p;
        if (imag(a)>imag(b)) swap(a,b);
        if (imag(a)<=0 && 0<imag(b))
            if (cross(a,b)<0) in = !in;
        if (abs(cross(a,b)) <= EPS && dot(a,b) <= 0) return ON;
    }
    return in?IN:OUT;
}

int t,n,cp;
double x,y;
Pol pol;
P point;
map< pair<double,double>,int > ans;
vector<pair<double,double> > pairs,sub;
int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("output.out","w",stdout);
    scanf("%d",&t);
    for(int w=1;w<=t;w++){
        pol.clear();
        pairs.clear();
        ans.clear();
        scanf("%d",&n);
        for (int i=0; i<n; i++){
            scanf("%lf%lf",&x,&y);
            ans[make_pair(x,y)] = 1000;
            pol.push_back(P(x,y));
            pairs.push_back(make_pair(x,y));
        }
        Pol submask;
        for(int mask = 0; mask < (1<<n);mask++){
        	submask.clear();
        	sub.clear();
        	int deleted = 0;
        //	cout<<"mask--->"<<mask<<endl;
        	for(int i = 0; i < n;i++ )
        		if(mask & (1<<i)){
        				deleted++;
				}else{
				//	cout<<"punto"<<pairs[i].first<<" "<<pairs[i].second<<endl;
						submask.push_back(pol[i]);
        				sub.push_back(pairs[i]);
				}
			if(submask.size() < 3 ) continue;	
			Pol ch = convexHull(submask);
			/*	cout<<"Convex hull es "<<endl;
				for(int i = 0;i < ch.size();i++){
					cout<<real(ch[i])<<" "<<imag(ch[i])<<endl;
				}*/
				for(int i = 0; i < submask.size();i++){
					 int pos = pointInPolygon(ch,submask[i]);
					 if(pos == ON){
					 //	cout<<"*******"<<sub[i].first<<" "<<sub[i].second<<endl;
					 	ans[sub[i]] = min(ans[sub[i]],deleted);
					 }
				}
		}
		printf("Case #%d:\n",w);
		for(int i = 0; i < n;i++){
			int res = ans[pairs[i]];
			res%=1000;
			printf("%d\n",res);
		}
    }
}
