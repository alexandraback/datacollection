#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int T,N;
int main()
{
	FILE *in =fopen("input.txt","r");
	FILE *out =fopen("output.txt","w");
	fscanf(in,"%d",&T);
	char temp[111];
	for(int t=1;t<=T;t++){
		fscanf(in,"%d",&N);
		string st[111];
		vector< pair<char,int> > vt[111];
		for(int i=0;i<N;i++){
			fscanf(in,"%s",temp);
			st[i] = temp;
			char p = st[i][0];
			int cnt = 1;
			for(int j=1;j<st[i].length();j++){
				if(st[i][j] != p){
					vt[i].push_back(make_pair(p,cnt));
					p=st[i][j];
					cnt=1;
				}
				else cnt++;
			}
			vt[i].push_back(make_pair(p,cnt));
		}
		int ans=2e9;
		bool flag = false;
		vector< vector<int> > v1;
		int rN=vt[0].size();
		v1.resize(rN);
		int iden = 0;
		int sum=0;
		for(int i=0;i<N;i++){
			if(vt[i].size() != vt[iden].size()){
				flag =true;
				break;
			}
			for(int j=0;j<vt[iden].size();j++){
				if(vt[iden][j].first != vt[i][j].first){
					flag = true;
					break;
				}
				if(flag) break;
				v1[j].push_back(vt[i][j].second);
			}
		}
		for(int i=0;i<rN;i++){
			sort(v1[i].begin(),v1[i].end());
		}
		ans=0;
		for(int i=0;i<rN;i++){
			int rS = v1[i].size();
			int p = rS/2;
			for(int j=0;j<rS;j++){
				ans += abs(v1[i][j]-v1[i][p]);
			}
		}
		if(flag) fprintf(out,"Case #%d: Fegla Won\n",t);
		else fprintf(out,"Case #%d: %d\n",t,ans);
	}
	return 0;
}