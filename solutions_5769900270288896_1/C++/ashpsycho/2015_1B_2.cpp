#include <bits/stdc++.h>
using namespace std;
int main(){
	long long t,te,i,j,k,n,r,c,x,y,m,a,b,d;
	cin>>t;
	for(te=0;te<t;te++){
		cin>>r>>c>>n;
		if(n>(((r*c)+1)/2)){
			if((r%2)==0||(c%2)==0){
				x=n-((r*c)/2);
				if(x<3)m=2*x;
				else{
					y=max(0LL,((r-2)*(c-2))/2);
					y=((r*c)/2)-y;
					if(x<=y)m=4+(3*max(0LL,(x-2)));
					else {
						m=4+(3*max(0LL,y-2));
						x-=y;
						m+=(4*x);
					}
				}
				if(r==1||c==1){
					x=n-((r*c)/2);
					m=2*x-1;
				}
			}
			else{
				x=n-(((r*c)+1)/2);
				a=max(0LL,((r-2)*(c-2))/2);
				b=(r*c)/2;
				a=b-a;
				if(x<=a)y=3*x;
				else y=(3*a)+(4*(x-a));
				x=y;
				a=max(0LL,(((r-2)*(c-2))+1)/2);
				b=((r*c)+1)/2;
				a=b-a;
				y=n-(((r*c))/2);
				if(y<5)d=2*y;
				else if(y<=a)d=8+max(0LL,(y-4))*3;
				else d=8+(max(0LL,(a-4))*3) + ((y-a)*4);
				m=min(x,d);
				if(r==1||c==1)m=2*(n-(((r*c)+1)/2));
			}
		}
		else m=0;
		cout<<"Case #"<<(te+1)<<": "<<m<<"\n";
	}
}