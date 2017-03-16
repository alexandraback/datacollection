#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <cmath>
#include <gmpxx.h>
using namespace std;
long long noseen(long long int time,int m[],int B)
{
long long int seen=0;
for(int i=0;i<B;i++){seen+=time/m[i]+1;}

return seen;

}

long long solve (int m[],int B, int N)
{
long long int low,up;
low=0;up=100000000000000000;
while(up-low>3){long long int mid=(low+up)/2;
if(noseen(mid,m,B)<N){low=mid-1;}
else{up=mid+1;}
}
if(low>50){return low-10;}
return low;

}

int main()
{
    ifstream input;
    input.open("large.in");
    ofstream output;
    output.open("outputlarge.txt");
    int cse=1;
    int t;
    input>>t;

    while(cse<=t)
    {
	long long int ans,B,N;
	ans=0;
	input>>B>>N;

	int m[B];
	long long int time=15;
	long long int seen=0;int check=0;
	for(int i=0;i<B;i++){input>>m[i];}

    time=solve(m,B,N);

    seen=noseen(time-1,m,B);

    while(check==0){

	for(int i=0;i<B;i++){

    if(time%(m[i])==0){
	seen++;
	if(seen==N){ans=i+1;check=1;break;}
	}

	}





	time++;
	}

        output<<"Case #"<<cse<<": "<<ans<<endl;
        cout<<"Case #"<<cse<<": "<<ans<<endl;
        cse++;
    }

    return 0;
}

