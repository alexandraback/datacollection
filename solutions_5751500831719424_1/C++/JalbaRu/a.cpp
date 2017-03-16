#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	//freopen("1.txt","r",stdin);
	//freopen("A-small-attempt0.in","r",stdin);
	//freopen("A-small-out.txt","w",stdout);
	freopen("A-large.in","r",stdin);
	freopen("A-large-out.txt","w",stdout);
	int T;
	cin>>T;
	for(int at=0;at<T;at++){
		printf("Case #%d: ",at+1);
		int n;
		cin >> n;
		vector<string> s(n);
		for(int i=0;i<n;i++)
			cin >> s[i];
		string t;
		t=s[0][0];
		for(int i=1;i<s[0].size();i++)
			if(s[0][i-1] != s[0][i])
				t += s[0][i];

		vector<vector<int> > d(n, vector<int> (t.size()));
		int fail=0;
		for(int j=0;j<n;j++){
			int len=1;
			int k=0;
			for(int i=1;i<s[j].size();i++)
				if(s[j][i-1] != s[j][i]){
					if(k < t.size() && s[j][i-1] == t[k])
						d[j][k] = len;
					else{
						fail=1;
						break;
					}
					len=1;
					k++;
				}
				else
					len++;
			if(k+1 == t.size() && s[j][s[j].size() - 1] == t[k])
				d[j][k] = len;
			else{
				fail=1;
				break;
			}
		}
	
		if(fail)
			printf("Fegla Won\n");
		else{	
			int ans=0;
			for(int j=0;j<t.size();j++){
				int p;
				int ps=10000000;
				for(p=1;p<=100;p++){
					int cnt=0;
					for(int i=0;i<n;i++){
						cnt += abs(d[i][j]-p);
					}
					if(cnt < ps)
						ps = cnt;
				}
				ans += ps;
			}
			printf("%d\n", ans);
		}

	}



}