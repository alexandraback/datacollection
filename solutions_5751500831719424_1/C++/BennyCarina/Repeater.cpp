#include<iostream>
#include<math.h>
#include<vector>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

#define d_pi 57.2957795
#define LL long long
#define LarN 100
string read[LarN+5];
int N;
void init(){
	cin>>N;
	for(int i=0;i<N;i++){
		read[i].clear();
		cin>>read[i];
	}
}
int solve(){
	int ret=0;
	string buf;
	char a;
	a=read[0][0];
	buf.push_back(a);
	vector<vector<int> > nums;
	for(int i=0;i<N;i++)nums.push_back(vector<int>());
	int k=1;
	for(int i=1;i<read[0].length();i++){
		if(read[0][i]!=a){
			a=read[0][i];
			buf.push_back(a);
			nums[0].push_back(k);
			k=1;
		}
		else {
			k++;
		}
	}
	nums[0].push_back(k);
	int idx_buf=0;
	for(int i=1;i<N;i++){
		idx_buf=0;
		k=1;
		a=read[i][0];
		if(a!=buf[idx_buf]){
			return -1;
		}
		for(int j=1;j<read[i].length();j++){
			if(read[i][j]!=a){
				a=read[i][j];
				idx_buf++;
				if(idx_buf>=buf.length() || a!=buf[idx_buf])return -1;
				nums[i].push_back(k);
				k=1;
			}
			else {
				k++;
			}
		}
		nums[i].push_back(k);
		if(nums[i].size()<buf.length())return -1;
	}
	
	for(int i=0;i<nums[0].size();i++){
		vector<int> tmp;
		for(int j=0;j<N;j++){
			tmp.push_back(nums[j][i]);
		}
		sort(tmp.begin(),tmp.end());
		k=tmp[tmp.size()/2];
		for(int j=0;j<N;j++){
			ret+=abs(k-tmp[j]);
		}
	}
	
	return ret;
}
				

int main(){
	freopen("in.in","r",stdin);
	freopen("out.txt","w",stdout);
	int T_case;

	cin>>T_case;
	for(int i_case=1;i_case<=T_case;i_case++){
		init();
		int ans=solve();
		if(ans<0){
			printf("Case #%d: Fegla Won\n",i_case);
		}
		else {
			printf("Case #%d: %d\n",i_case,ans);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}