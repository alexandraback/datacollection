#include<fstream>
using namespace std;

int main(){
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A-small-attempt0.out");
	int t;
	fin>>t;
	int n;
	int ans1,ans2;
	int maxd;
	int m[1000];
	for(int k=1;k<=t;k++){
		fin>>n;
		ans1=0;
		ans2=0;
		maxd=0;
		fin>>m[0];
		for(int i=1;i<n;i++){
			fin>>m[i];
			if(m[i]<=m[i-1]){
				ans1+=m[i-1]-m[i];
				if(maxd<m[i-1]-m[i])maxd=m[i-1]-m[i];
			}
		}
		for(int i=1;i<n;i++){
			if(m[i-1]>maxd){
				ans2+=maxd;
			}
			else ans2+=m[i-1];
		}
		fout<<"Case #"<<k<<": "<<ans1<<' '<<ans2<<endl;
	}
	return 0;
}