#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define fs first
#define sc second
#define pb push_back

int pos[105];
string s[105];
vector< pair<char,int> > v[105];

int main(){
 freopen("A-large.in","r",stdin);
 freopen("A-large.out","w",stdout);
 int tes;
 scanf("%d",&tes);
 for(int tcase=1;tcase<=tes;tcase++){
	 int n;
	 
	 scanf("%d",&n);
	 for(int i=1;i<=n;i++){
		 v[i].clear();
		 cin >> s[i];	
	 }
	 
	 for(int i=1;i<=n;i++){
	    for(int j=0;j<(int)s[i].length();j++){
		    char c = s[i][j];
		    int cnt = 1;
			 while(j+1 < (int)s[i].length()){
				 if(s[i][j+1] == c) cnt++,j++;
				 else break;	
			 }		
			 v[i].pb(mp(c,cnt));
		 }		
	 }
	 
	 int ans = 0;
	 bool valid = true;
	 for(int i=1;i<=n;i++){
	    if(v[i].size() != v[1].size()) valid = false;		
	 }
	 if(valid){
		 for(int pos=0;pos<(int)v[1].size();pos++){
			 int maks = 0;
			 for(int i=1;i<=n;i++){
			    if(v[i][pos].fs != v[1][pos].fs){
				    valid = false;
					 break;		
				 }		
				 maks = max(maks,v[i][pos].sc);
			 }
			 if(!valid) break;
			 int dif = 0, mindif = 100000000;
			 for(int med=1;med<=maks;med++){
					dif = 0;
			    for(int j=1;j<=n;j++){
				    dif += abs(v[j][pos].sc-med);		
				 }
				 mindif = min(mindif,dif);		
			 }
			 ans += mindif;
		 }
	 }
	 
	 printf("Case #%d: ",tcase);
	 if(!valid) printf("Fegla Won\n");
	 else printf("%d\n",ans);
 }
 
 fclose(stdin);
 fclose(stdout);
// system("pause");
 return 0;	
}
