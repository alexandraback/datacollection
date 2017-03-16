#include<iostream>
#include<vector>
#include<algorithm>
#include<complex>
#include<cmath>
#define EPS 1e-8
#define EQ(x,y) (fabs((x)-(y))<EPS)
#define LT(x,y) ((x)<=(y)-EPS)
using namespace std;
typedef complex<double> Point;
const int BUF = 3005;
const int INF = 1 << 30;


namespace std {
  bool operator< (const Point& a, const Point& b) {
    if(EQ(a.real(),b.real())) return LT(a.imag(),b.imag());
    return LT(a.real(),b.real());
  }
  
  bool operator== (const Point& a, const Point& b) {
    return EQ(norm(a - b), 0);
  }
}

double cross(Point a, Point b){
  return imag(conj(a)*b);
}

int ccw(Point &a, Point &b, Point &c){
  double ret = cross(b-a,c-a);

  if(EQ(ret,0)) return 0;
  return (ret>0 ? 1:-1);
}

void pushPt(vector<Point> &ret, bool low, vector<Point> &ptList){
  int bgn = (low ? 0 : ptList.size()-1);
  int end = (low ? ptList.size() : -1);
  int d = (low ? 1 : -1);
  
  ret.push_back(ptList[bgn]);
  int m = ret.size();
  
  for(int i=bgn+d;i!=end;i+=d){
    for(int k;(k=ret.size())>m && 
	  ccw(ret[k-2],ret[k-1],ptList[i])<0;) 
      ret.pop_back();
    ret.push_back(ptList[i]);
  }
  ret.pop_back();
}

vector<Point> calcConvex(vector<Point> &ptList){
  sort(ptList.begin(), ptList.end());
  vector<Point> ret;
  pushPt(ret,true, ptList);
  pushPt(ret,false, ptList);
  return ret;
}


int nPoint;
Point pt[BUF];

void read(){
  cin >> nPoint;
  
  for(int i=0;i<nPoint;i++){
    int x,y;
    cin >> x >> y;

    pt[i] = Point(x,y);
  }
}


void work(int cases) {
    
    //for (int i = 0; i < convexHull.size(); ++i)
    //    cout << convexHull[i] << ' ';
    //cout << endl;
    
    cout << "Case #" << cases << ":" << endl;
    for (int loop = 0; loop < nPoint; ++loop) {
        
        int minV = INF;
        
        for (int mask = 0; mask < (1 << nPoint); ++mask) {
            if (mask & (1 << loop))
                continue;

            int nCut = __builtin_popcount(mask);
            if (minV <= nCut)
                continue;
    
            vector<Point> ptList;
            for (int i = 0; i < nPoint; ++i)
                if (!(mask & (1 << i)))
                    ptList.push_back(pt[i]);
            
            vector<Point> convexHull = calcConvex(ptList);
            
            for (int i = 0; i < convexHull.size(); ++i)
                if (pt[loop] == convexHull[i]) {
                    minV = nCut;
                    break;
                }
        }

        cout << minV << endl;
    }
}


int main() {
    int cases;
    cin >> cases;
    
    for (int i = 0; i < cases; ++i) {
        read();
        work(i + 1);
    }
    return 0;
}
