#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
	
class P{
	public:
		P(long long int _x,long long int _y):x(_x),y(_y){}
		long long int x;
		long long int y;
		long long int v;
};
int main(){
	int TT;
	cin>>TT;
	//int ans=0;


	int n;
	long long int x[4000];
	long long int y[4000];
	for(int T=1;T<=TT;++T){
		
		cin>>n;
		
		for(int i=0;i<n;++i){
			cin>>x[i]>>y[i];
		}
		cout<<"Case #"<<T<<":\n";
		for(int k=0;k<n;++k){
			int mi = n-1;
			vector<P> v;
			for(int i=0;i<n;++i){
				if(x[i]!=x[k]||y[i]!=y[k]){
					v.push_back(P(x[i],y[i]));
				}
			}
			int vs=v.size();
			for(int j=0;j<vs;++j){
				int count = 0;
				int count2 = 0;
				int count3 = 0;
				for(int i=0;i<vs;++i){
					if(i==j)
						continue;
					if((v[i].x-x[k])*(v[j].y-y[k])-(v[j].x-x[k])*(v[i].y-y[k])>0){
						++count;
					}
					else if((v[i].x-x[k])*(v[j].y-y[k])-(v[j].x-x[k])*(v[i].y-y[k])<0){
						++count2;
					}
					else if((v[i].x-x[k])*(v[j].y-y[k])-(v[j].x-x[k])*(v[i].y-y[k])==0){
						++count3;
					}
				}
				if(count<mi)
					mi=count;
				if(count2<mi)
					mi=count2;
			    //cout<<count<<" "<<count2<<" "<<count3<<endl;
			}
			cout<<mi<<endl;
		}


	}
	return 0;
}
