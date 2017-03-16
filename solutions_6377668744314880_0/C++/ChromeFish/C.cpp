#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
ifstream in("C.in");
ofstream out("C.out");

const int maxn = 3010;
int top ;
struct point
{
	long long x,y;
}p[maxn],stack[maxn],a[maxn];
int ans[maxn];
long long dis(point p1,point p2)
{
 return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}
long long  multi(point p1, point p2, point p0)
{
    return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
int cmp(point a,point b)
{
 if(multi(a,b,p[0])>0)
  return 1;
 if(multi(a,b,p[0])==0&&dis(a,p[0])<dis(b,p[0]))
  return 1;
 return 0;
}
void Graham_scan(int n)
{
 
 int i,j,k=0;
 top=2;
 point temp;
 for(i=1;i<n;i++)
  if(p[i].y<p[k].y||((p[i].y==p[k].y)&&(p[i].x<p[k].x)))
   k=i;
 temp=p[0];
 p[0]=p[k];
 p[k]=temp;
 sort(p+1,p+n,cmp);
 stack[0]=p[0],stack[1]=p[1],stack[2]=p[2];
 for(i=3;i<n;i++)
 {
  while(top>1&&multi(p[i],stack[top],stack[top-1])>=0)
   top--;
  stack[++top]=p[i];
 }
}

bool check(point p1)
{
	for (int i=0; i<=top; i++)
		if (multi(stack[i], p1, stack[(i+1)%(top+1)]) == 0)
			return true;
	return false;
}

int main()
{
	int T, n, headNum;
	in>>T;
	for (int i=1; i<=T; i++)
	{
		in>>n;
		for (int j=0; j<n; j++)
			in>>a[j].x>>a[j].y;
		for (int j=0; j<n; j++)
			ans[j]=n;
		for (int k=1; k<(1<<n); k++)
		{
			int num =0;
			for (int j=0; j<n; j++)
				if (k & (1<<j))
				{
					p[num++]=a[j];
				}
			if (num>=3)
			{
				Graham_scan(num);
				for (int j=0; j<n; j++)
					if ( (k & (1<<j)) && check(a[j]))
						ans[j]=min(ans[j], n-num);
			}
		}
		out<<"Case #"<<i <<":"<<endl;
		for (int j=0; j<n; j++)
			out<<ans[j]<<endl;
	}
}