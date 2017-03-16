#include <iostream>
#include <set>
#include <string>
using namespace std;

string solve(){
  set<int> SA;
  int R1,R2;
  cin>>R1;
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++){
      int val;
      cin>>val;
      if(i+1==R1)
	SA.insert(val);
    }
  cin>>R2;
  int sol=-1;
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++){
      int val;
      cin>>val;
      if(i+1==R2)
	if(SA.find(val)!=SA.end()){
	  if(sol==-1)
	    sol=val;
	  else
	    sol=-2;
	}
    }
  if(sol==-1)
    return "Volunteer cheated!";
  else if(sol==-2)
    return "Bad magician!";
  else
    return to_string(sol);
}

int main(){
  int NC;
  cin>>NC;
  for(int i=0;i<NC;i++){
    cout<<"Case #"<<i+1<<": "<<solve()<<endl;
  }
  return 0;
}
