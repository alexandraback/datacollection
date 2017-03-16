#include <iostream>
#include <utility>
#include <vector>
#define eps 1e-8
#define zero(x) (((x)>0?(x):-(x))<eps)
using namespace std;

struct Point {
  int x, y;
};


struct point{double x,y;};
double xmult(point p1,point p2,point p0){
  return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}

point p1,p2;

int graham_cp(const void* a,const void* b){
  double ret=xmult(*((point*)a),*((point*)b),p1);
  return zero(ret)?(xmult(*((point*)a),*((point*)b),p2)>0?1:-1):(ret>0?1:-1);
}

void _graham(int n,point* p,int& s,point* ch){
  int i,k=0;
  for (p1=p2=p[0],i=1;i<n;p2.x+=p[i].x,p2.y+=p[i].y,i++)
    if (p1.y-p[i].y>eps||(zero(p1.y-p[i].y)&&p1.x>p[i].x))
      p1=p[k=i];
  p2.x/=n,p2.y/=n;
  p[k]=p[0],p[0]=p1;
  qsort(p+1,n-1,sizeof(point),graham_cp);
  for (ch[0]=p[0],ch[1]=p[1],ch[2]=p[2],s=i=3;i<n;ch[s++]=p[i++])
    for (;s>2&&xmult(ch[s-2],p[i],ch[s-1])<-eps;s--);
}

int graham(int n,point* p,point* convex,int maxsize=1,int dir=1){
  point* temp=new point[n];
  int s,i;
  _graham(n,p,s,temp);
  for (convex[0]=temp[0],n=1,i=(dir?1:(s-1));dir?(i<s):i;i+=(dir?1:-1))
    if (maxsize||!zero(xmult(temp[i-1],temp[i],temp[(i+1)%s])))
      convex[n++]=temp[i];
  delete []temp;
  return n;
}


void run() {
  int N;
  cin >> N;
  vector<Point> points(N);
  for (int i = 0; i < N; i++) {
    cin >> points[i].x >> points[i].y;
  }
  vector<int> result(N, max(0, N - 3));
  point p[15];
  point convex[15];
  for (int m = 1; m < (1 << N); m++) {
    int n = 0;
    for (int i = 0; i < N; i++) {
      if (m & (1 << i)) {
        p[n].x = points[i].x;
        p[n].y = points[i].y;
        n++;
      }
    }
    int mm = 0;
    if (n > 3) {
      int c = graham(n, p, convex);
      for (int i = 0; i < c; i++) {
        for (int j = 0; j < N; j++) {
          if (convex[i].x == points[j].x && convex[i].y == points[j].y) {
            mm |= (1 << j);
            break;
          }
        }
      }
    } else {
      mm = m;
    }
    for (int i = 0; i < N; i++) {
      if (mm & (1 << i)) {
        result[i] = min(result[i], N - n);
      }
    }
  }
  for (int i = 0; i < N; i++) {
    cout << result[i] << endl;
  }
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << endl;
    run();
  }
}
