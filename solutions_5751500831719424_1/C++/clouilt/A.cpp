#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

char str[103][103];
char str2[103][103];
int arr[103][103];
using namespace std;

int main(){
	freopen("i:\\1b\\A-large.in","r",stdin);
	freopen("i:\\1b\\A-large.txt","w",stdout);
	int T,N,cnt2;

	long long sum=0;
	cin>>T;
	for(int cs=1;cs<=T;++cs){
		scanf("%d",&N);
		for(int i=0;i<N;++i){
			scanf("%s",str[i]);
			int l=strlen(str[i]);
			for(int j=0;j<=l;++j)
				str2[i][j]=str[i][j];
			std::unique(str[i],str[i]+l+1);
			//cout<<str[i]<<endl;
		}
		for(int i=1;i<N;++i){
			if(strcmp(str[0],str[i])!=0)
				goto err;
		}

		memset(arr,0,sizeof(arr));

		for(int i=0;i<N;++i){
			int l=strlen(str2[i]);
			char pre=0;
			int cnt=-1;
			for(int j=0;j<l;++j){
				if(str2[i][j]==pre)
					++arr[cnt][i];
				else{
					++cnt;
					pre=str2[i][j];
				}
			}
		}
		cnt2=strlen(str[0]);
	/*	for(int i=0;i<N;++i){
			for(int j=0;j<cnt2;++j)
				cout<<arr[j][i]<<' ';
		}*/
		for(int i=0;i<cnt2;++i)
			std::sort(arr[i],arr[i]+N);
		sum=0;
		for(int i=0;i<cnt2;++i){
			for(int j=0;j<N;++j)
				sum+=abs(arr[i][j]-arr[i][N/2]);
		}
		cout<<"Case #"<<cs<<": "<<sum<<endl;
		continue;


		err:
			printf("Case #%d: Fegla Won\n",cs);

	}
	return 0;
}
