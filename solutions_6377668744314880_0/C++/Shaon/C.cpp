#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef long long LL;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;
//find_by_order
//order_of_key

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );
#define ALL(v) v.begin(),v.end()

#define X first
#define Y second
#define MP make_pair

typedef pair<int,int> pint;
typedef map<int,int> mint;

void show() {cout<<'\n';}
template<typename T,typename... Args>
void show(T a, Args... args) { cout<<a<<" "; show(args...); }
template<typename T>
void show_c(T& a) { for ( auto &x:a ){ cout<<x<<" ";}cout<<endl;  }


struct mathv{
    mathv(){x=0;y=0;}
    mathv(LL a,LL b){x=a;y=b;}
    LL x,y;

    mathv operator + (mathv & p){
        mathv tmp( x+p.x,y+p.y );
        return tmp;
    }
    mathv operator - (mathv & p){
        mathv tmp( x-p.x,y-p.y );
        return tmp;
    }

};

LL cross2D(mathv v1, mathv v2){
    return v1.x * v2.y - v1.y * v2.x;
}
LL dot2D(mathv& v1, mathv& v2){
    return v1.x * v2.x + v1.y * v2.y;
}

bool cmp(const mathv& a, const mathv& b){
    if ( a.y!=b.y ){
        return a.y<b.y;
    }else{
        return a.x<b.x;
    }
}

bool isColinearThreePoint(mathv& p1, mathv& p2, mathv& p){
    return p.x >= min(p1.x, p2.x)
        && p.x <= max(p1.x, p2.x)
        && p.y >= min(p1.y, p2.y)
        && p.y <= max(p1.y, p2.y);
}

int convexHull(mathv points[],mathv convexPoints[],  int x){

    bool col = true;
    for (int i=0;i<x;++i){
        for (int j=0;j<x;++j){
            for (int k=0;k<x;++k){
                if ( !isColinearThreePoint( points[i],points[j],points[k] ) ){
                    col=false;
                    i=j=k=x+10;
                }
            }
        }
    }
    if ( col ){
        for (int i=0;i<x;++i){
            convexPoints[i] = points[i];
        }
        return x;
    }

    sort(points, points+x, cmp);
    int m = 0;
    for(int i = 0; i < x; i++){
        while(m >= 2 && cross2D(convexPoints[m-2]- convexPoints[m-1],convexPoints[m-2]- points[i]) <= 0)
            m--;
        convexPoints[m++] = points[i];
    }
    for(int i = x-2, t = m+1; i >= 0; i--){
        while(m >= t && cross2D(convexPoints[m-2]- convexPoints[m-1],convexPoints[m-2]- points[i]) <= 0)
            m--;
        convexPoints[m++] = points[i];
    }
    return m-1;
}

struct mathl{
    mathv p1,p2;
};
double length2D(mathv& v){
    return sqrt(v.x * v.x + v.y * v.y);
}

double distance2DPointAndLine(mathv& p, mathl& l){
    mathv v1 = p - l.p1, v2 = l.p2 - l.p1;
    return fabs(cross2D(v1, v2)) / length2D(v2);
}
double distance2DPointAndPoint(mathv& v1, mathv& v2){
    return sqrt((v2.x - v1.x) * (v2.x - v1.x)+ (v2.y - v1.y) * (v2.y - v1.y));
}

double distance2DPointAndSegment(mathv p, mathl s){
    mathv p1p = p - s.p1, p1p2 = s.p2 - s.p1;
    mathv p2p = p - s.p2, p2p1 = s.p1 - s.p2;


    if (dot2D(p1p, p1p2) > 0 && dot2D(p2p, p2p1) > 0)
        return distance2DPointAndLine(p, s);
    else
        return min( distance2DPointAndPoint(p, s.p1),distance2DPointAndPoint(p, s.p2) );
}


mathv point[20];

int main(){

    freopen("C-small-attempt1.in","r",stdin);
    freopen("out3.out","w",stdout);

    int kase;
    scanf("%d",&kase);


    for (int kk=1;kk<=kase;++kk){
        int n;
        scanf("%d",&n);

        int ans[20];
        for (int i=0;i<n;++i){
            scanf("%lld %lld",&point[i].x,&point[i].y);
            ans[i] = (1<<29);
        }

        for (int state = 1;state<(1<<n);++state){

            mathv tmp[20];
            int len = 0;
            int now = 0;
            for (int i=0;i<n;++i){
                if ( state & (1<<i) ){
                    tmp[len++] = point[i];
                }else{
                    now++;
                }
            }

            mathv res[20];
            int sz=convexHull( tmp,res,len );

            for (int i=0;i<sz;++i){
                for (int j=0;j<n;++j){
                    if ( res[i].x == point[j].x &&  res[i].y == point[j].y ){
                        ans[j] = min( ans[j] , now );
                    }
                    else if ( distance2DPointAndSegment( point[j] , {res[i],res[ (i+1)%sz ]} ) < 1e-8 ){
                        ans[j] = min( ans[j] , now );
                    }
                }
            }

        }

        //show(kk,n);


        printf("Case #%d:\n",kk);
        for (int i=0;i<n;++i){
            printf("%d\n",ans[i]);
        }

    }



    return 0;
}
