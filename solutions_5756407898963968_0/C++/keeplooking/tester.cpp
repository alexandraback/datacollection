#include<bits/stdc++.h>
#define sc(n) scanf("%d",&n)
#define pn(n) printf("%d\n",n)
#define slc(n) scanf("%lld",&n)
#define pln(n) printf("%lld\n",n)
#define ps(n) printf("%d ",n) //
using namespace std;
int A[5][5];
int B[5][5];
void out(int type,int ans)
{
	if(type==1)
		cout<<ans<<endl;
	else if(type>=2)
		printf("Bad magician!\n");
	else
		printf("Volunteer cheated!\n");
}
int main()
{
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	int t,ty = 1,temp,ans,c1,c2;
	cin>>t;
	while(t--){
		printf("Case #%d: ",ty++);
		cin>>c1;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				cin>>A[i][j];
			}
		}
		cin>>c2;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				cin>>B[i][j];
			}
		}
		temp=0;
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++)
				if(A[c1-1][i]==B[c2-1][j]){
					ans=A[c1-1][i];
					temp++;
				}					
		}
		out(temp,ans);
	}
}
