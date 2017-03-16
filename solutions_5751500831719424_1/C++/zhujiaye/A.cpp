#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int test,testcase,N,M,A[105][105];
char str[105];
char letter[105];
vector<int>List;

int main(){
	freopen("i.txt","r",stdin);
	scanf("%d",&test);
	int testcase=1;
	for (;test--;testcase++){
		printf("Case #%d: ",testcase);
		scanf("%d",&N);
		M=0;
		memset(A,0,sizeof(A));
		bool ok=true;
		for (int i=0;i<N;i++){
			scanf("%s",str);
			int now=-1,c=0;
			int len=strlen(str);
			for (int j=0;j<len;j++){
				if (j==0 || str[j]!=str[j-1]){
					if (now>=0) A[i][now]=c;
					now++;
					if (i==0){
						letter[M++]=str[j];
					}
					else{
						if (now>M || str[j]!=letter[now]){
							ok=false;
						}
					}
					c=1;
				}
				else c++;
			}
			if (now!=M-1) ok=false;
			A[i][now]=c;
		}
		if (!ok) {
			puts("Fegla Won");
			continue;
		}
		//for (int i=0;i<M;i++) putchar(letter[i]);
		//puts("");

		//for (int i=0;i<N;i++,puts(""))
		//	for (int j=0;j<M;j++) printf("%d ",A[i][j]);
		
		int ans=0;
		for (int i=0;i<M;i++){
			List.clear();
			for (int j=0;j<N;j++) List.push_back(A[j][i]);
			sort(List.begin(),List.end());
			int mid=List[N/2];
			for (int j=0;j<N;j++) ans+=abs(mid-A[j][i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}
