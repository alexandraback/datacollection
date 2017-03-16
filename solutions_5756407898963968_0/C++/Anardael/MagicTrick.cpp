#include <iostream>
#include <set>
#include <algorithm>
#include<fstream>
using namespace std;
set<int> readQuestion()
{
  int fa;
    cin>>fa;
    set<int> res;
    for (int i=0;i<4;i++)
    {
      for (int j=0;j<4;j++)
      {
	int t;
	cin >>t;
	if (i==fa-1) res.insert(t);
      }
    }
    return res;
}
int main()
{
  int t;
  cin>>t;
  ofstream f("p1.res");
  for (int ti=0;ti<t;ti++)
  {
    set<int> s1 = readQuestion();
    set<int> s2 = readQuestion();
    set<int> res;
    std::set_intersection( s1.begin(), s1.end(), s2.begin(), s2.end(),std::inserter( res, res.begin() ) );
    f<<"Case #"<<(ti+1)<<": ";
    if (res.size()==1)
      f<< *(res.begin())<<endl;
    else if (res.size()==0)
      f<<"Volunteer cheated!"<<endl;
    else f<<"Bad magician!"<<endl;
    
    
  }
  
  
  return 0;
}