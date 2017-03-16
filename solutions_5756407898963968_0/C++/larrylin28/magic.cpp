#include "iohelper.h"
#include <set>
#include <sstream>
using namespace std;

vector<string> result9;

void readFunc9(ifstream& in)
{
	int N1;
	in>>N1;
	set<int> choose;
	for(int i = 0;i < 4;i++)
	{
		int a[4];
		in>>a[0]>>a[1]>>a[2]>>a[3];
		if(i == N1-1)
		{
			choose.insert(a[0]);
			choose.insert(a[1]);
			choose.insert(a[2]);
			choose.insert(a[3]);
		}
	}
	int N2;
	in>>N2;
	vector<int> ans;
	for(int i = 0;i < 4;i++)
	{
		int a[4];
		in>>a[0]>>a[1]>>a[2]>>a[3];
		if(i == N2-1)
		{
		   for(int j = 0;j < 4;j++)
		   {
			   if(choose.find(a[j]) != choose.end())
			   {
				   ans.push_back(a[j]);
			   }
		   }
		}
	}
	if(ans.size() <= 0) result9.push_back("Volunteer cheated!");
	else if(ans.size() == 1){
		stringstream ss("");
		ss<<ans[0];
		result9.push_back(ss.str());
	}
	else result9.push_back("Bad magician!");
	
}

int main()
{
	IOHelper io;
	io.readFile("A-small-attempt0.in",readFunc9);
	io.writeFile("A-small-attempt0.out",result9);
	return 0;
}