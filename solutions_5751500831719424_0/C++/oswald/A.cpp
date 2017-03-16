#include<bits/stdc++.h>
using namespace std;
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
		string s1, s2;
		vector<int> v1, v2;
		char prev=strings[0][0];
		int count=1;
		s1.push_back(prev);
		for(int k1=1; k1<strings[0].length(); k1++){
			if(strings[0][k1]==prev){
				count++;
				continue;
			}
			else{
				s1.push_back(strings[0][k1]);
				v1.push_back(count);
				count=0;
				prev=strings[0][k1];
			}
		}
		v1.push_back(count);
		count=1;
		prev=strings[1][0];
		s2.push_back(prev);
		for(int k1=1; k1<strings[1].length(); k1++){
			if(strings[1][k1]==prev){
				count++;
				continue;
			}
			else{
				s2.push_back(strings[1][k1]);
				v2.push_back(count);
				count=0;
				prev=strings[1][k1];
			}
		}
		v2.push_back(count);
		if(s1==s2){
			int ans=0;
			for(int k=0; k<v1.size(); k++){
				int x = v1[k]-v2[k];
				if(x<0) x = -x;
				ans+=x;
			}
			printf("Case #%i: %i\n", tt, ans);
		}
		else{
			printf("Case #%i: Fegla Won\n", tt);
		}
	}
}