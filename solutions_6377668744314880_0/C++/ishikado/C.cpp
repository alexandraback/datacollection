#include <bits/stdc++.h>
using namespace std;
 
typedef pair<int,int> pii;
typedef long long ll;
typedef complex<double> P;

void fastStream(){cin.tie(0);std::ios_base::sync_with_stdio(0);}

const double EPS=1e-8;
bool EQ(double a,double b){
  return abs((a)-(b))<EPS;
}
bool EQV(P &a,P &b){
  return (EQ((a).real(),(b).real()) && EQ((a).imag(),(b).imag()));
}
// 内積
double dot(const P &a, const P &b) {
  return (a.real() * b.real() + a.imag() * b.imag());
}
// 外積
double cross(const P &a, const P &b) {
  return (a.real() * b.imag() - a.imag() * b.real());
}
// 辞書順で比較
bool cmp_x(const P&p,const P&q){
  if(!EQ(p.real(),q.real()))return p.real()<q.real();
  return p.imag()<q.imag();
}
// a1,a2を端点とする線分とb1,b2を端点とする線分の交差判定
int is_intersected_ls(const P &a1, const P &a2, const P &b1, const P &b2) {
    // 線分が平行な場合は重なっていないことにする
    if(abs(cross(a2-a1,b2-b1)) < EPS){
        return 0;
    }
    return ( cross(a2-a1, b1-a1) * cross(a2-a1, b2-a1) < EPS ) &&
        ( cross(b2-b1, a1-b1) * cross(b2-b1, a2-b1) < EPS );
}

// 凸包を求める
vector<P> convex_hull(P *ps,int n){
  sort(ps,ps+n,cmp_x);
  int k=0;
  vector<P> qs(n*2);
  // こっちは凸包の辺上の点は凸包の要素に含まない
  for(int i=0;i<n;i++){
    while(k>1&&(cross(qs[k-1]-qs[k-2],ps[i]-qs[k-1])<0||EQ(cross(qs[k-1]-qs[k-2],ps[i]-qs[k-1]),0)))k--;
    qs[k++]=ps[i];
  }
  for(int i=n-2,t=k;i>=0;i--){
    while(k>t&&(cross(qs[k-1]-qs[k-2],ps[i]-qs[k-1])<0||EQ(cross(qs[k-1]-qs[k-2],ps[i]-qs[k-1]),0)))k--;
    qs[k++]=ps[i];
  }
  qs.resize(k-1);
  return qs;
}

// 点a,bを端点とする線分と点cとの距離
double distance_ls_p(const P &a, const P &b, const P &c) {
  if ( dot(b-a, c-a) < EPS ) return abs(c-a);
  if ( dot(a-b, c-b) < EPS ) return abs(c-b);
  return abs(cross(b-a, c-a)) / abs(b-a);
}


int N;
P ps[20];
int main(){

  fastStream();
  int T;
  cin>>T;
  for(int t=1;t<=T;t++){
    cout<<"Case #"<<t<<":"<<endl;
    cin>>N;
    for(int i=0;i<N;i++){
      int x,y;
      cin>>x>>y;
      ps[i]=P(x,y);
    }
    if(N==1){
      cout<<0<<endl;
    }
    else{
      // どれを端にしたいか
      for(int i=0;i<N;i++){
        int ans = 1<<29;
        // 切るものはmaskで決定する
        for(int mask=0;mask<(1<<N);mask++){
          if((mask>>i)&1)continue;
          // 残った要素でconvex hullを作る
          // 作ったconvex hullの線分のどれかの上に,ps[i]が乗ってればOK
          P p[N];
          int cnt=0;
          for(int j=0;j<N;j++)if(!((mask>>j)&1))p[cnt++]=ps[j];
          vector<P> hull = convex_hull(p,cnt);
          bool ok = false;
          for(int j=0;j<(int)hull.size();j++){
            P p1 = hull[j];
            P p2 = hull[(j+1)%(int)hull.size()];
            // p1-p2ラインに乗っているか調べる
            if(EQ(0,distance_ls_p(p1,p2,ps[i]))){
              ok=true;
              break;
            }
          }
          if(ok){
            int bits = 0;
            for(int j=0;j<N;j++)
              if((mask>>j)&1)bits++;
          
            ans=min(ans,bits);
          }
        }
        cout<<ans<<endl;
      }
    }
  }
  
  return 0;
}
