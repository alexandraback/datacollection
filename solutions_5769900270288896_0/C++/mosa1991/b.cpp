#include<iostream>
#include <utility>
#include <vector>
#include <cmath>


using namespace std;

void takeInputAndProcess()
{
	int R,C,N;
	cin >> R >> C >> N;
	int ed=0,cr=0,ans=0,edw=3,crw=2,rw=4;
	long long p = R*C;
	if(R == 1 || C == 1)
	{
	   crw = 1;
	   edw = rw = 2;
	}
	if(p%2 != 0)
	{
	   int N1 = N,cr1,ed1;	   
	   N = N-((R*C)/2)-1;
	   N1 = N1-((R*C)/2);
	   if(R ==1 || C== 1)
		cr1 = 2;
	   else
	   	cr1 = 4;
	   cr = 0;
	   ed = (2*(R+C))-4;
	   ed = ed/2;
	   ed1 = (2*(R+C))-4;
	   ed1 = ed1/2;
	   ed = ed-cr;
	   ed1 = ed1-cr1;
	   int ans1=0;
	   if(N > 0)
	   {
		ans += min(cr,N)*crw;
		N = N-min(cr,N);
	   }
	   if(N1 > 0)
	   {
		ans1 += min(cr1,N1)*crw;
		N1 = N1-min(cr1,N1);
	   }
	  if(N > 0)
	  {
		ans += min(ed,N)*edw;
		N = N-min(ed,N);
	  }
	  if(N1 > 0)
	  {
		ans1 += min(ed1,N1)*edw;
		N1 = N1-min(ed1,N1);
	  }
	  if(N > 0)
	  {
		ans += (N*rw);
	  }
	  if(N1 > 0)
	  {
		ans1 += (N1*rw);
	  }

	  ans = min(ans1,ans);

	}
	else
	{
		N = N-((R*C)/2);
		if(R ==1 || C== 1)
		 cr = 1;
		else
		  cr = 2;
		ed = (2*(R+C))-4;
		ed = ed/2;
		ed = ed-cr;
		if(N > 0)
		{
		   ans += min(cr,N)*crw;
		   N = N-min(cr,N);
		}
		if(N > 0)
		{
		    ans += min(ed,N)*edw;
		    N = N-min(ed,N);
		}
		if(N > 0)
		{
		    ans += (N*rw);
		}
	}
	cout << ans;
}
int main()
{
	int T;
	cin >> T;
	for(int i=1;i<=T;i++)
	{
	   cout << "Case #" << i << ": " ;
            takeInputAndProcess();
            cout << endl;
	}
	return 0;
}
