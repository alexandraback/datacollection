#include <set>
#include <map>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <cstdio>
#include <cstring>
#include <complex>
#include <iostream>
#include <algorithm>
#include<iomanip>
#include<fstream>

using namespace std;

vector<int> A[1009];
int tt[1009];

int N;
int check(int root,int son);

int main(){
	fstream mcin,mcout;
	mcout.open("d:\\data.txt",ios::out);
	mcin.open("d:\\B-small-attempt1.in",ios::_Nocreate);

	int T;
	mcin>>T;
	int x,y;
	for(int i=1; i<=T; i++){
		//memset(A,0,sizeof(A));
		memset(tt,0,sizeof(tt));
		
		//输入数据
		mcin>>N;
		for(int j=1; j<N; j++){
			mcin>>x>>y;
			A[x].push_back(y);
			A[y].push_back(x);
			tt[x]++;
			tt[y]++;
		}
		//做计算
		int max = 1;
		for(int ii=1; ii<=N; ii++){
			if(tt[ii] == 1){
				continue;
			}
			int tem=check(-1,ii);
			if(tem > max) max=tem;
		}

		//输出
		mcout<<"Case #"<<i<<": "<<N-max<<endl;
		for(int j=1; j<=N; j++) A[j].clear();
	}

	//system("pause");
	return 0;
}

int check(int root,int son){
	if(root == -1){
		if(tt[son] == 2){
			return check(son,A[son][0]) + check(son,A[son][1])+1;
		}
		else{//如果多于两个节点
			int max,submax;
			max = check(son,A[son][0]);//计算权重
			submax = check(son,A[son][1]);

			if(max < submax){
				int temp = max;
				max = submax;
				submax = temp;
			}
			for(int i=2; i<tt[son]; i++){
				int ttt = check(son,A[son][i]);
				if(ttt>=max){
					submax = max;
					max = ttt;
				}
				else if(ttt > submax){
					submax = ttt;
				}
			}
			return max+submax+1;
		}
	}
	else{
		if(tt[son] == 3){
			if(A[son][0] == root) return check(son,A[son][2])+check(son,A[son][1])+1;
			else if(A[son][1] == root) return check(son,A[son][0])+check(son,A[son][2])+1;
			else return check(son,A[son][0])+check(son,A[son][1])+1;
		}
		else if(tt[son] > 3){
			int max = 0,submax = 0;

			for(int i=0; i<tt[son]; i++){
				if(A[son][i] == root) continue;

				int ttt = check(son,A[son][i]);
				if(ttt>=max){
					submax = max;
					max = ttt;
				}
				else if(ttt > submax){
					submax = ttt;
				}
			}
			return max+submax+1;
		}
		else{
			return 1;
		}
	}
	
}