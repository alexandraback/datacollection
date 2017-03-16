#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	freopen("A-large.in.txt","r",stdin);
	freopen("A-large.out.txt","w",stdout);
	int T,pid=1;
	for (cin>>T;T--;) {
		printf("Case #%d: ",pid++);
        int N=0;
        char str[101][101];
        scanf("%d", &N);
        for (int i = 0;i < N; ++i) {scanf("%s",str[i]);}
        char str1[101][101];
        char prevch = '-';
        for (int i =0; i < N;++i) {
            int k=0;
            prevch='-';
            for (int j =0; j < 1001; ++j){
                if (str[i][j] == '\0') {str1[i][k++] = '\0';break;}
                if (str[i][j]!=prevch) {
                    str1[i][k++]=str[i][j],prevch = str[i][j];
                }
            }
        }
        bool canContinue=false;
        for (int i=0;i<N-1;++i)
            if (strcmp(str1[i], str1[i+1])!=0) {
                canContinue = true;
                printf("Fegla Won\n");
                break;
            }
        if (canContinue) continue;
        
        char nextch='-';
        int i=0;
        int idx[N];
        bool canBreak=false;
        int nchange=0;
        memset(idx, 0, N*sizeof(int));
        while (true) {
            for (;i<1001;++i){
                if (str[0][i]=='\0') {canBreak=true;break;}
                if (str[0][i]!=nextch) {nextch=str[0][i];break;}
            }
            if (canBreak)break;
            //
            int cnt[N];
            int mn=1000,mx=0;
            memset(cnt, 0, N*sizeof(int));
            for (int j=0;j<N;++j){
                for (int k=idx[j];k<1001;++k){
                    if (str[j][k]=='\0'||str[j][k]!=nextch) {idx[j]=k;break;};
                    cnt[j]++;
                }
                if (cnt[j]<mn)mn=cnt[j];
                if (cnt[j]>mx)mx=cnt[j];
            }
            //
            int minchange=1000000;
            for (int k=mn;k<=mx;++k){
                int cntchange=0;
                for (int l=0;l<N;++l)
                    cntchange+=abs(cnt[l]-k);
                if (cntchange<minchange) minchange=cntchange;
            }
            nchange+=minchange;
        }
        printf("%d\n",nchange);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}