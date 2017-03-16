#include <bits/stdc++.h>      
using namespace std;  

#define ll long long

struct Point{
	ll x,y;
	Point(ll x,ll y):x(x),y(y){
	}
	Point(){
	}
}pts[3010];

struct Vector{
	ll x,y;
	Vector(ll x,ll y):x(x),y(y){
	}
	Vector(){
	}
	Vector(Point A,Point B){
		x=B.x-A.x;
		y=B.y-A.y;
	}
};

ll Cross(Vector A,Vector B){
	return A.x*B.y - A.y*B.x;
}

int main(){
	freopen("C-small-attempt2.in","r",stdin);
	freopen("C-small-attempt2.out","w",stdout);
	int t;
	cin>>t;
	int cas=0;
	while(t--){
		cas++;
		int n;
		cin>>n;
		
		for(int i=1;i<=n;i++){
			cin>>pts[i].x>>pts[i].y;
		}
		
		printf("Case #%d:\n",cas);
		
		for(int i=1;i<=n;i++){
			int ans=max(n-3,0);
			for(int j=1;j<=n;j++){	//Ã¶¾Ù 
				if(i==j)continue;
				int left=0;
				int right=0;
				for(int k=1;k<=n;k++){
					if(k==i)continue;
					if(k==j)continue;
					Vector v1 = Vector(pts[i],pts[j]);
					Vector v2 = Vector(pts[i],pts[k]);
					ll cp = Cross(v1,v2);
					if(cp<0)left++;
					if(cp>0)right++;
				}
				int tmp=min(left,right);
				ans=min(ans,tmp);
			}
			cout<<ans<<endl;
		}
	}
	
	return 0;
}
