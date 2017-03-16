#include <iostream>
#include <vector>

using namespace std;
const double err=1e-15;

struct ptr
{
  ptr(int i,double a, double b):id(i),x(a),y(b){}
  double x, y;
  int id;
};

ptr ptrMinus(ptr a, ptr b)
{
  return ptr(0, a.x-b.x,a.y-b.y);
}

double cross(ptr a, ptr b)
{
  return a.x*b.y-a.y*b.x;
}

int main()
{
  int cnt;
  cin >> cnt;
  for(int i = 0; i < cnt; ++i)
    {
      int N;
      cin >> N;
      vector<ptr> vec;
      for(int j = 0; j < N; ++j)
	{
	  double x,y;
	  cin >> x >> y;
	  vec.push_back(ptr(j,x,y));
	}
      cout << "Case #" << i+1 << ":" << endl;
      for(int j = 0; j < vec.size(); ++j)
	{
	  int ans=10000000;
	  for(int k = 0; k < vec.size(); ++k)
	    {
	      if(k==j){continue;}
	      int left=0;
	      int right=0;
	      ptr ln=ptrMinus(vec[k],vec[j]);
	      for(int l = 0; l < vec.size(); ++l)
		{
		  if(l==k || l==j){continue;}
		  ptr curr=ptrMinus(vec[l],vec[j]);
		  double c=cross(ln,curr);
		  if(c>err){left++;}
		  else if(c<-err){right++;}
		}
	      if(ans>left){ans=left;}
	      if(ans>right){ans=right;}
	    }
	  if(ans==10000000){ans=0;}
	  cout << ans << endl;
	}
    }
}
