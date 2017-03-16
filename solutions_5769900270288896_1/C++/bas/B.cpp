#include<iostream>
#include<vector>
#include<string>
#define eps 1e-18
#define ll long long

using namespace std;
	int R,C,N;
    
	int T;
int sol(int R, int C, int rem ){
		int fours=0, tr=0,tw=0;
    if(R>2 && C>2){
	fours = min(((R-2)*(C-2))/2, rem);
	rem-=fours;
    }
    tr = min(R-2+C-2, rem);
    rem-=tr;
    tw = rem;
    return R*(C-1)+C*(R-1)-4*fours-3*tr-2*tw;
    
}
int sol1(int R, int C, int rem ){
		int fours=0, tr=0,tw=0;
    if(R>2 && C>2){
	fours = min(((R-2)*(C-2))/2, rem);
	rem-=fours;
    }
    tr = min(R-1+C-1, rem);
    rem-=tr;
    tw = 0;
    return R*(C-1)+C*(R-1)-4*fours-3*tr-2*tw;
    
}
int sol2(int R, int C, int rem ){
		int fours=0, tr=0,tw=0;
	fours = min(((R-2)*(C-2))/2+1, rem);
	rem-=fours;
    tr = min(R-3+C-3, rem);
    rem-=tr;
    tw = rem;
    return R*(C-1)+C*(R-1)-4*fours-3*tr-2*tw;
    
}
int main(){

	cin>>T; 
	for(int j=0; j<T; j++){
		cin>>R>> C>> N;
		int res = R*(C-1)+C*(R-1);
		bool odd=false;
		if (N<=R*C/2 || ((R*C)%2 && N==R*C/2+1)){
			cout<<"Case #"<<j+1<<": " <<0<<"\n";
			continue;
		}
		int rem = R*C-N;
		if(R==1 || C==1){
		    res-=2*rem;
			cout<<"Case #"<<j+1<<": " <<res<<"\n";
			continue;
		}
		int fours=0, tr=0,tw=0;
		if((R*C)%2==0)res = sol(R, C, rem); else
		res = min(sol1(R,C, rem), sol2(R, C, rem));
		cout<<"Case #"<<j+1<<": " <<res<<"\n";

	}
	
}
