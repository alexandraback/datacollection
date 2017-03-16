#include <bits/stdc++.h>

using namespace std;

vector<int> a[20];
map<int,int> g;

int r,c,n;
int f[20][20];

void pre(){
	for (int i=0;i<20;i++) a[i].clear();
	for (int i=0;i<(1<<17);i++){
		int now = __builtin_popcount(i);
		a[now].push_back(i);
	}
}

int main(){
	int T;
	scanf("%d",&T);
	pre();
	for (int ti=1;ti<=T;ti++){
		scanf("%d %d %d",&r,&c,&n);
		printf("Case #%d: ",ti);
		if (n==0){
			printf("0\n");
			continue;
		}
		int tot=1<<(r*c);
		int cnt=(r*(c-1)+c*(r-1))*2;
	//	cout << cnt<<endl;
		for (int i=0;i<a[n].size();i++){
			int now = a[n][i];
			if (now>tot) continue;
			memset(f,0,sizeof(f));
			int p=0;
			int ans=0;
			for (int di=1;di<=r;di++)
				for (int dj=1;dj<=c;dj++){
					if ((now>>p)&1) f[di][dj]=1;
					p++;
				}
			for (int di=1;di<=r;di++)
				for (int dj=1;dj<=c;dj++)
					if (f[di][dj]){
						if (f[di-1][dj]) ans++;
						if (f[di][dj-1]) ans++;
						if (f[di+1][dj]) ans++;
						if (f[di][dj+1]) ans++;
					}
			//cout <<now <<" "<<ans<<endl;
			if (ans<cnt) cnt=ans;
		}
		printf("%d\n",cnt/2);
	}
	return 0;
}
