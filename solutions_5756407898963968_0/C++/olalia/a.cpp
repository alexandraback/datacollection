#include<iostream>
#include<set>


using namespace std;


int main(){
  int T; cin>>T;
  for (int tc=1; tc<=T; ++tc){
    cout<<"Case #"<<tc<<": ";
    set<int> s=set<int>();
    int a, b; cin>>a;
    for (int i=0; i<4; ++i)
      for (int j=0; j<4; ++j){
	cin>>b;
	if (a-1==i)
	  s.insert(b);
      }
    cin>>a;
    for (int i=0; i<4; ++i)
      for (int j=0; j<4; ++j){
	cin>>b;
	if (a-1!=i)
	  s.erase(b);
      }
    if (s.size()==0)
      cout<<"Volunteer cheated!\n";
    if (s.size()==1)
      cout<<*(s.begin())<<endl;
    if (s.size()>1)
      cout<<"Bad magician!\n";
  }
  return 0;
}
