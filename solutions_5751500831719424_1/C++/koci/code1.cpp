#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

struct znak{
  int a;
  char kaj;
};

int main(){
  int n;
  cin >> n;
  for(int stevec=1;stevec<=n;stevec++){
    int st;
    cin >> st;
    vector <vector <znak> > data;
    for(int i=0;i<st;i++){
      vector <znak> tren;
      tren.clear();
      znak buff;
      string beseda;
      cin >> beseda;
      buff.kaj=beseda.at(0);
      buff.a=1;
      tren.push_back(buff);
      for(int j=1;j<beseda.length();j++){
	if(beseda.at(j)==tren.back().kaj){tren.back().a++;}else{
	  buff.a=1;
	  buff.kaj=beseda.at(j);
	  tren.push_back(buff);
	}
      }
      data.push_back(tren);
    }
    /*for(int i=0;i<data.size();i++){
      for(int j=0;j<data.at(i).size();j++){
	cout << data.at(i).at(j).a << data.at(i).at(j).kaj << ' ';
      }
      cout << endl;
    }*/
    bool vredu=1;
    for(int i=1;i<st;i++){
      if(data.at(i).size()!=data.at(i-1).size()){vredu=0;}
    }
    if(!vredu){
       cout << "Case #" << stevec << ": Fegla Won" << '\n';
       continue;
    }
    for(int i=1;i<st;i++){
      for(int j=0;j<data.at(i).size();j++){
	if(data.at(i).at(j).kaj!=data.at(i-1).at(j).kaj){vredu=0;}
      }
    }
    if(!vredu){
       cout << "Case #" << stevec << ": Fegla Won" << '\n';
       continue;
    }
    int rez=0;
    for(int j=0;j<data.at(0).size();j++){
      int cena=1000000000;
      for(int i=1;i<=100;i++){
	int tmp=0;
	for(int a=0;a<st;a++){
	  tmp+=abs(i-data.at(a).at(j).a);
	  }
	if(tmp<cena){cena=tmp;}
	}
	rez+=cena;
      }
    cout << "Case #" << stevec << ": " << rez << '\n';
  }
  return 0;
}