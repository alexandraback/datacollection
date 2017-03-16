#include<vector>
#include <utility>
#include<iostream>
#include <algorithm>

using namespace std;
int R,C,N;
int matr[20][20];
long long _min;



void _try(int up,int left,int rim,int act_min){
if(rim==0)return;


if(act_min>=_min)return;

int i;
for(i=(up-1)*C+(left-1);i<R*C;i++){
int ri=(i/C)+1,co=i%C+1;
matr[ri][co]=1;
int act=(!!matr[ri-1][co])+(!!matr[ri][co-1]);
int i2=i+1;
int ri2=(i2/C)+1,co2=i2%C+1;
if(rim>1)_try(ri2,co2,rim-1,act_min+act);
else if((act+act_min)<_min)_min=act+act_min;

matr[ri][co]=0;
}



}

int main(void){
int T,ii;
long long N;

int i,j;

for(i=0;i<20;i++)
	for(j=0;j<20;j++)
		matr[i][j]=0;
cin>>T;

for(ii=0;ii<T;ii++){
cin>>R>>C>>N;
if(N!=0)_min=1000000L;
else _min=0;
_try(1,1,N,0);
cout<<"Case #"<<(ii+1) <<": "<<_min<<endl;
}


return 0;
}
