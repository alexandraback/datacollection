#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;
	int C;
int main(){
	
	cin>>C; 
	for(int j=0; j<C; j++){
	    int n;
	    cin>>n;
	    vector<int> sen(n); int tot=0;
	    for(int i=0; i<n; i++){cin>>sen[i];tot+=sen[i];}
	    cout<<"Case #"<<j+1<<": ";
	    while(tot>3){
		auto it = max_element(sen.begin(), sen.end());
		(*it)--;
		cout<<string(1,('A'+(it-sen.begin())));
		it = max_element(sen.begin(), sen.end());
		(*it)--;
		cout<<string(1,('A'+(it-sen.begin())))<<" " ;
		tot-=2;
	    }
	    if(tot==3 || tot==1){
		auto it = max_element(sen.begin(), sen.end());
		(*it)--;
		cout<<string(1,('A'+(it-sen.begin())))<<" " ;
	    }
	    if(tot>=2){
		auto it = max_element(sen.begin(), sen.end());
		(*it)--;
		cout<<string(1,('A'+(it-sen.begin())));
		it = max_element(sen.begin(), sen.end());
		(*it)--;
		cout<<string(1,('A'+(it-sen.begin())))<<" " ;
	    }
	    cout<<"\n" ;
	}
	
}
