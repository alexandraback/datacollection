#include<cstdlib>
#include<cstdio>
#include<vector>
using namespace std;	
int n,b[2000];
void work()
{

	scanf("%d",&n);
	for(int i = 0; i < n; i++)scanf("%d",&b[i]);
	int ans1 = 0,ans2=0;
	int rate =0;
	for(int i = 1; i < n; i++){
		if(b[i-1]> b[i]){
			ans1+= b[i-1]-b[i];
			if (b[i-1]-b[i]> rate)
				rate = b[i-1]-b[i];
		}
	}
	for(int i = 0; i < n-1; i++){
		if (b[i] < rate){
			ans2+=b[i];
		}
		else 
			ans2+=rate;
	}
	printf("%d %d\n",ans1,ans2);
	return;
}
int main()
{
	int T;
	scanf("%d",&T);
	for (int i = 1; i <=T; i++){
		printf("Case #%d: ", i);
		work();		
	}
	return 0;
}