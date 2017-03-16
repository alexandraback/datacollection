#include<bits/stdc++.h>
using namespace std;
inline int abs(int x){
	if(x<0) return -x;
}
inline int min(int x1, int x2, int x3){
	if(x1<x2 && x1<x3)
		return x1;
	if(x2<x1 && x2<x3)
		return x2;
	if(x3<x1 && x3<x2)
		return x3;

}
int main(){
	int t;
	scanf("%i", &t);
	for(int tt=1; tt<=t; tt++){
		int n;
		scanf("%i", &n);
		string strings[n];
		for(int j=0; j<n; j++){
			cin>>strings[j];
		}
		string s[n];
		vector<int> v[n];
		for(int k2=0; k2<n; k2++){
			char prev=strings[k2][0];
			int count=1;
			s[k2].push_back(prev);
			for(int k1=1; k1<strings[k2].length(); k1++){
				if(strings[k2][k1]==prev){
					count++;
					continue;
				}
				else{
					s[k2].push_back(strings[k2][k1]);
					v[k2].push_back(count);
					count=0;
					prev=strings[k2][k1];
				}
			}
			v[k2].push_back(count+1);
		}
		bool notposs=false;
		for(int k=0; k<n; k++){
			if(s[k]!=s[0])
			{
				notposs=true;
				break;
			}
		}


		// if(!notposs){
		// 	for(int k=0; k<n; k++){
		// 		for(int k2=0; k2<v[k].size(); k2++){
		// 			printf("%i ", v[k][k2]);
		// 		}
		// 		printf("\n");
		// 	}
		// }

		if(!notposs){
			int ans=0;
			for(int j=0; j<v[0].size(); j++){
				int x1=0, x2=0, x3=0;
				vector<int> xi;
				for(int k=0; k<n; k++){
					xi.push_back(v[k][j]);
				}
				sort(xi.begin(), xi.end());
				if(int(xi.size())%2){
					x1=xi[(xi.size()-1)/2];
				}
				else{
					x3=xi[xi.size()/2];
					x2=xi[(xi.size()/2)-1];
					x1=(x2+x3)/2;
				}
				int d1=0, d2=0, d3=0;
				for(int k=0; k<n; k++){
					d1+=abs(v[k][j]-x1);
					d2+=abs(v[k][j]-x2);
					d3+=abs(v[k][j]-x3);
				}
				ans+=min(d1,d2,d3);
			}
			printf("Case #%i: %i\n", tt, ans);
		}
		else{
			printf("Case #%i: Fegla Won\n", tt);
		}
	}
}