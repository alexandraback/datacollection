#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector<ii> vii;


ll TC,i,j,k,cno,N;
ll id[110];
char shortform[110];
char s[110][110];

void getshort(char* source, char* des){
	int len = strlen(source);
	int inde = 0;
	des[0] = source[0];

	for (int i=1;i<len;i++)
		if (source[i] != source[i-1]){
			inde ++;
			des[inde] = source[i];
		}
	des[inde+1] = '\0';

}

// ll dif(char* s1,char* s2){
// 	ll re = 0;
// 	ll i1, i2;
// 	i1 = 0; i2 = 0;
// 	ll c1, c2;
// 	for (int i=0;i<(int)strlen(shortform) ;i++){
// 		c1 = 0; c2 = 0;
// 		while (s1[i1]==shortform[i]) {
// 			i1++;
// 			c1++;
// 		}

// 		while (s2[i2]==shortform[i]) {
// 			i2++;
// 			c2++;
// 		}
// 		re += c1 < c2 ? c2 - c1 : c1 - c2;
// 	}
// 	printf("diff of %s and %s is %lld \n",s1,s2,re);
// 	return re;

// }
void doit(){
	int i,j;
	getshort(s[0],shortform);
	//printf("shortform = %s\n", shortform);
	char sf[110];

	for (i=1;i<N;i++){
		getshort(s[i],sf);
		if (strcmp(sf,shortform) != 0) {
			printf("Case #%lld: Fegla Won\n",cno);
			return;
		}
	}

	for (i=0;i<N;i++) id[i] = 0;
	ll re = 0;

	for (i=0;i<(int)strlen(shortform);i++){
		vi a;
		for (j=0;j<N;j++){
			ll c = 0;
			while (s[j][id [ j ] ] == shortform[i] ) {
				c ++;
				id[j]++;
			}
			a.push_back(c);

		}
		sort(a.begin(), a.end() );

		ll mid =  ( a[N/2] + a[(N-1)/2] ) /2;

		for (j=0;j<N;j++) re+= abs( a[j] - mid ) ;

	}

	printf("Case #%lld: %lld\n",cno,re);

}
int main(){
	//freopen("A-large.in","r",stdin); freopen("out.txt","w",stdout);

	//printf("hello\n");
	scanf("%lld ",&TC);


	for (cno = 1;cno <=TC; cno++){
		scanf("%lld ",&N);
		//printf("N = %lld\n", N);
		for (i=0;i<N;i++) scanf("%s", s[i]);

		doit();


	}
	return 0;

}