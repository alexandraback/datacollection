#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
	int  N, C;
	vector<string > a;
	vector<vector<int> > nums;
bool check_str(){
    vector<string> b(N, string( 200, ' '));
    for(int i=0; i<N; i++){
	b[i][0]=a[i][0];nums[i][0]=1; int cur=0;
	for(int j=1;j<a[i].length(); j++){
	    if(a[i][j]!=a[i][j-1]){
		cur++;
		b[i][cur] = a[i][j];
		nums[i][cur]=1;
	    }else{
		nums[i][cur]++;
	    }
	}
    }
    for(int i=1; i<N; i++){
	if(b[0]!=b[i]){
	    return false;
	}
    }
    return true;
}
int main(){
	
	cin>>C; 
	for(int j=0; j<C; j++){

		a.clear(); a.resize(0);
		cin>>N;
		string s;
		for(int i=0; i<N; i++){cin>>s; a.push_back(s);}
		nums.clear(); nums.resize(N, vector<int>(200, 0));
		bool good = check_str();
		cout<<"Case #"<<j+1<<": " ;
		if(!good)cout<<"Fegla Won\n";
		else {
		    int res=0;
		    for(int c=0; c<102 && nums[0][c]>0; c++ ){
			int bs=1000000000;
			for(int nl=1; nl<=100; nl++){
			    int sum=0;
			    for(int p=0; p<N; p++){
				sum+=abs(nums[p][c]-nl);
			    }
			    if(bs>sum){
				bs=sum;
			    }
			}
			if(bs<10000000)
			res+=bs;

		    }
		    cout<<res<<"\n";
		}
	}
	
}
