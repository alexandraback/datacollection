#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int unhappiness(vector<bool>way,int r,bool debug){
	int ret=0;
	int c=way.size()/r;
	swap(r,c);
	for(int i=0;i<r;i++){
		for(int j=0;j<c-1;j++){
			if(way[i*c+j]&&way[i*c+j+1]){
				ret++;
				if(debug){
					printf("at %d %d\n",i,j);
				}
			}
			else if(debug){
				printf("not at %d %d (%d %d)\n",i,j,i*r+j,i*r+j+1);
			}
		}
	}
	for(int i=0;i<r-1;i++){
		for(int j=0;j<c;j++){
			if(way[i*c+j]&&way[(i+1)*c+j]){
				ret++;
				if(debug){
					printf("at2 %d %d\n",i,j);
				}
			}
		}
	}
	if(debug){printf("%d %d %d\n",r,c,ret);}
	return ret;
}

int number_of_bits(vector<bool> n){
	int cnt=0;
	for(int i=0;i<n.size();i++){
		cnt+=n[i];
	}
	return cnt;
}

int main(){
	int t;
	scanf("%d",&t);
	for(int tc=1;tc<=t;tc++){
		int mn=1000000;
		int r,c,n;
		scanf("%d %d %d",&r,&c,&n);
		int mx=1<<(r*c);
		int rc=r*c;
		for(int i=0;i<mx;i++){
			vector<bool> way;
			for(int j=0;j<rc;j++){
				way.push_back((i&(1<<j))>0);
			}
			if(number_of_bits(way)==n){
				int score=unhappiness(way,r,false);
				if(score<mn){
					mn=score;
					//fprintf(stderr,"Improvement: %d @ %d\n",score,i);
					//int score=unhappiness(way,r,true);
				}
			}
		}
		printf("Case #%d: %d\n",tc,mn);
	}
}
