#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int abs(int a){
	if(a>0) return a;
	else return -a;
}
string trf(string X){
	string res="";
	res=res+X[0];
	int len=X.length();
	for(int i=1;i<len;i++){
		if(X[i]!=X[i-1]) res=res+X[i];
	}
	return res;
}
int main(){
	int t;
	freopen("A-large.in","rt",stdin);
	freopen("A-large.out","wt",stdout);
	scanf("%d",&t);
	for(int _=0;_<t;_++){
		printf("Case #%d: ",_+1);
		int n=0;
		scanf("%d",&n);
		int cnt[102][102];
		int tp[102];
		for(int i=0;i<102;i++) for(int j=0;j<102;j++) cnt[i][j]=0;
		for(int i=0;i<102;i++) tp[i]=0;
		string a[100];
		for(int i=0;i<n;i++) cin>>a[i];
		int xx=0;
		string om=trf(a[0]);
		bool flag=false;
		for(int i=1;i<n;i++){
			if(om!=trf(a[i])){
				printf("Fegla Won\n");
				flag=true;
				break;
			}
		}
		if(flag) continue;
		for(int i=0;i<n;i++){
			cnt[tp[i]][i]++;
			int len=a[i].length();
			for(int j=1;j<len;j++){
				if(a[i][j]!=a[i][j-1]) tp[i]++;
				cnt[tp[i]][i]++;
			}
		}
		int tt=0;
		for(int i=0;i<om.length();i++){
			sort(cnt[i],cnt[i]+n);
			for(int j=0;j<n;j++){
				tt+=abs(cnt[i][n/2]-cnt[i][j]);
			}
			//tt+=cnt[i][n/2];
		}
		
	//	for(int k=0;k<2;k++){
	//	for(int i=0;i<100;i++){
	//		printf("%d ",cnt[i][k]);
	//	}
	//	printf("\n");
	//	}
		printf("%d\n",tt);
		//printf("%d\n",tt);
		
	}

}
