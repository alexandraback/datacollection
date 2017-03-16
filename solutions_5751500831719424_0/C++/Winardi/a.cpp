/*template by : Dewangga Winardi*/
#include <bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define MAX(a,b) a=max(a,b)
#define MIN(a,b) a=min(a,b)	
#define mp make_pair
#define fi first
#define sc second
#define ll long long
#define pb push_back
#define RESET(v,a) memset(v,a,sizeof(v))	
#define pause system("pause")
#define INF 1000000000
#define INFL 1000000000LL

using namespace std;

inline string GetString()
{
	char S[1000005];
	scanf("%s",S);
	string ret=S;
	return ret;
}

template<typename t>
t getnum()
{
 t res=0;
 char c;
 int sign=1;
 while(1){
	c=getchar_unlocked();
	if(c==' '||c=='\n')continue;
	else break;}
 if(c=='+'){}
 else if(c=='-')sign=-1;
 else res=c-'0';
 while(1){
	c=getchar_unlocked();
	if(c>='0'&&c<='9')res=res*10+c-'0';
	else break;}
return res*sign;
}

/*end of template*/

int main(int argc , char** argv)
{			
	//freopen("input.txt","r",stdin);
	freopen("a_small.out","w",stdout);
	string s[105],piv;
	int t=getnum<int>();
	for (int tc=1; tc<=t; tc++) {
		printf("Case #%d: ",tc);
		int n=getnum<int>();
		int cnt[105][105];
		memset(cnt,0,sizeof(cnt));
		for (int i=0; i<n; i++) {
			s[i]=GetString();
		}
		piv="";
		for (int i=0; i<s[0].length(); i++) {			
			piv+=s[0][i];
			while (i<s[0].length()-1 && s[0][i]==s[0][i+1]) i++;
		}
		int bisa=true;
		for (int i=0; i<n; i++) {
			int j=0,k=0;
			while (j<s[i].length()) {
				if (!bisa) break;
				if (s[i][j]!=piv[k]) {					
					bisa=false;
					break;
				}
				int hitung=1;
				while (j+1<s[i].length() && s[i][j+1]==piv[k]) {
					hitung++;
					j++;
					if (j==s[i].length()) break;
				}
				cnt[i][k]=hitung;
				//printf("%c %d\n",piv[k],cnt[i][k]);
				j++;
				k++;
			}						
		}
		for (int i=0; i<n; i++) for (int j=0; j<piv.length(); j++) {
			if (cnt[i][j]==0) bisa=false;
		}
		if (bisa) {
			int ans=0;
			for (int i=0; i<piv.length(); i++) {
				int lala=INF;
				for (int k=1; k<=100; k++) {
					int temp=0;					
					for (int j=0; j<n; j++) {
						temp+=abs(k-cnt[j][i]);
					}
					lala=min(lala,temp);
				}
				ans+=lala;				
			}
			printf("%d\n",ans);	
		} else puts("Fegla Won");
		
	}
	return 0;
}