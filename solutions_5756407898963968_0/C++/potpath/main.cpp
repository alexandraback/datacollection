#include<cstdio>
int main()
{
	int T,a,t;
	scanf("%d",&T);
	for (int iT=1; iT<=T; ++iT) {
		int c[17]={},n=0;
		scanf("%d",&a);
		for (int i=1; i<a; ++i) {
			scanf("%*d%*d%*d%*d");
		}
		for (int i=0; i<4; ++i) {
			scanf("%d",&t);
			++c[t];
		}
		for (int i=a; i<4; ++i) {
			scanf("%*d%*d%*d%*d");
		}
		scanf("%d",&a);
		for (int i=1; i<a; ++i) {
			scanf("%*d%*d%*d%*d");
		}
		for (int i=0; i<4; ++i) {
			scanf("%d",&t);
			if (c[t]==1) {
				n==0?n=t:n=-1;
			}
		}
		for (int i=a; i<4; ++i) {
			scanf("%*d%*d%*d%*d");
		}
		printf("Case #%d: ",iT);
		n>0?printf("%d\n",n):n==0?printf("Volunteer cheated!\n"):printf("Bad magician!\n");
	}
    return 0;
}

