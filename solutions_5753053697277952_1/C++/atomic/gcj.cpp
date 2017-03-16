#include<algorithm>
#include<array>
#include<atomic>
#include<bitset>
#include<cstring>
#include<deque>
#include<functional>
#include<fstream>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<limits>
#include<memory>
#include<queue>
#include<stack>
#include<string>
#include<typeinfo>
#include<type_traits>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>
using namespace std;

int main()
{
	int T;
	ifstream ifs{"in.in"};
	ofstream ofs{"out"};
	ifs>>T;
	for(int case_i{0};case_i!=T;++case_i)
	{
		int N;
		ifs>>N;
		int total{0};
		vector<pair<int,char>> p(N);
		for(int i{0};i!=N;++i)
		{
			ifs>>p[i].first;
			total+=p[i].first;
			p[i].second='A'+i;
		}
		ofs<<"Case #"<<case_i+1<<":";
		bool has{false};
		while(true)
		{
			if(has==false)
				ofs<<' ';
			sort(begin(p),end(p),[](const auto lhs,const auto rhs){return lhs.first>rhs.first;});
			if(p.front().first==0)
				break;
			if(!((has==true)&&(p.front().first==p[1].first)))	//only one
			{
				ofs<<p.front().second;
				--p.front().first;
			}
			has=!has;
		}
		ofs<<endl;
	}
}