#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
struct node {
	int x,y;
};
using namespace std;
bool b[16][16];
int ones(string s) {
	int ans=0;
	for(int i=0;i<s.size();i++)if(s[i]=='1')ans++;
	return ans;
}
int hp(int r,int c) {
	int ans=0;
	for(int i=0;i<r;i++) {
		for(int j=0;j<c;j++) {
			//cout<<b[i][j];
			if(b[i][j]==0)continue;
			if(i-1>=0 && b[i-1][j]==1)ans++;
			if(j-1>=0 && b[i][j-1]==1)ans++;
		}
		//cout<<endl;
	}
	return ans;
}
int main() {
	int cas=1,T;
	cin>>T;
	while(cas<=T) {
		int r,c,n,ans,tot;
		cin>>r>>c>>n;
		tot=r*c;
		ans=tot*10;
		if(tot%2)tot++;
		if(n>tot/2) {
			vector<node> v;
			for(int i=0;i<r;i++) {
				for(int j=0;j<c;j++) {
					node nod;
					nod.x=i;nod.y=j;
					v.push_back(nod);
				}
			}
			//cout<<v.size()<<endl;
			for(int i=0;i<=pow(2,tot);i++) {
				string bv="";
				int it=i;
				while(it) {
					if(it%2==0)bv+='0';
					else bv+='1';
					it/=2;
				}
				if(ones(bv)!=n || bv.size()>r*c)continue;
				//cout<<bv.size()<<" "<<tot<<endl;
				while(bv.size()<v.size())bv+='0';
				reverse(bv.begin(),bv.end());
				//cout<<bv<<endl;
				for(int j=0;j<bv.size();j++) {
					if(bv[j]=='1')b[v[j].x][v[j].y]=1;
					else b[v[j].x][v[j].y]=0;
				}
				ans=min(ans,hp(r,c));
			}
		} else ans=0;
		cout<<"Case #"<<cas<<": "<<ans<<endl;
		cas++;
	}
	return 0;
}
