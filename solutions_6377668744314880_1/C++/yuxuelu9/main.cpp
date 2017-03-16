#include<fstream>
#include<math.h>
#include<algorithm>
using namespace std;
#define PI 3.1415926535897932

int compare(const void *a, const void *b)
{
    double *pa = (double*)a;
    double *pb = (double*)b;
	if(*pa<*pb)return -1;
	else return 1;  
}

int main(){
	ifstream fin("C-large.in");
	ofstream fout("C-large.out");
	int t;
	fin>>t;
	int n,num;
	int m[3000][2];
	int log[3000];
	double angle[3000][3000];
	for(int k=1;k<=t;k++){
		fin>>n;
		for(int i=0;i<n;i++){
			fin>>m[i][0]>>m[i][1];
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(j<i){
					angle[i][j]=atan2(m[j][1]-m[i][1],m[j][0]-m[i][0]);
				}
				else if(j>i){
					angle[i][j-1]=atan2(m[j][1]-m[i][1],m[j][0]-m[i][0]);
				}
			}
		}
		for(int i=0;i<n;i++){
			if(n<=3)num=0;
			else{
				num=n;
				qsort(angle[i],n-1,sizeof(double),compare);
				int a=0,b=1;
				int tmp=0;
				do{
					while(b<n-1&&angle[i][b]-angle[i][a]<PI){
						b++;
						tmp++;
					}
					if(num>tmp)num=tmp;
					a++;
					tmp--;
				}while(a<n-1&&angle[i][a]<0);
				a=0;
				b=1;
				tmp=1;
				do{
					while(b<n-1&&angle[i][b]-angle[i][a]<=PI){
						b++;
						tmp++;
					}
					if(num>n-1-tmp)num=n-1-tmp;
					a++;
					tmp--;
				}while(a<n-1&&angle[i][a]<0);
				a=n-3;
				b=n-2;
				tmp=0;
				do{
					while(a>=0&&angle[i][b]-angle[i][a]<PI){
						a--;
						tmp++;
					}
					if(num>tmp)num=tmp;
					b--;
					tmp--;
				}while(b>=0&&angle[i][b]>=0);
				a=n-3;
				b=n-2;
				tmp=1;
				do{
					while(a>=0&&angle[i][b]-angle[i][a]<=PI){
						a--;
						tmp++;
					}
					if(num>n-1-tmp)num=n-1-tmp;
					b--;
					tmp--;
				}while(b>=0&&angle[i][b]>=0);
			}
			log[i]=num;
		}

		fout<<"Case #"<<k<<":"<<endl;
		for(int i=0;i<n;i++)
			fout<<log[i]<<endl;
	}
	return 0;
}