#include<iostream>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

#define d_pi 57.2957795
#define LL long long
int sig[17];
int A[5][5],B[5][5],a,b;
int main(){
	freopen("in.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T_case;
	cin>>T_case;
	for(int i_case=1;i_case<=T_case;i_case++){
		cin>>a;
		for(int i=1;i<=4;i++)for(int j=1;j<=4;j++)scanf("%d",&A[i][j]);
		cin>>b;
		for(int i=1;i<=4;i++)for(int j=1;j<=4;j++)scanf("%d",&B[i][j]);
		for(int i=1;i<=16;i++)sig[i]=0;
		for(int i=1;i<=4;i++){
			sig[A[a][i]]++;
			sig[B[b][i]]++;
		}
		vector<int> tmp;
		for(int i=1;i<=16;i++){
			if(sig[i]>1)tmp.push_back(i);
		}
		printf("Case #%d: ",i_case);
		if(tmp.size()>1)printf("Bad magician!\n");
		else if(tmp.size()<1)printf("Volunteer cheated!\n");
		else printf("%d\n",tmp[0]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}