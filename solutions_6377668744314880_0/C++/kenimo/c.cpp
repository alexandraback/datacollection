#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <iomanip>
using namespace std;
typedef long long LL;
typedef pair<double,double> P;
typedef pair<double,int> Q;
typedef vector<Q>::iterator It;
// difference
P operator-(const P& lhs, const P& rhs)
{
	return P(lhs.first-rhs.first,lhs.second-rhs.second);
}

// outer product
double Cross(const P& lhs, const P& rhs)
{
	return lhs.first*rhs.second-lhs.second*rhs.first;
}

// passed POJ 1912
// CW
void full(vector<P>& in, vector<P>& out)
{
	sort(in.begin(),in.end());
	for(int i=0;i<in.size();i++){
		while(out.size()>=2){
			P v=out[out.size()-1]-out[out.size()-2];
			P w=in[i]-out[out.size()-1];
			if(Cross(v,w)>0){
				out.pop_back();
			}
			else
			{
				break;
			}
		}
		out.push_back(in[i]);
	}
	for(int i=in.size()-2,k=max((int)out.size(),1);i>=0;i--){
		while(out.size()>k){
			P v=out[out.size()-1]-out[out.size()-2];
			P w=in[i]-out[out.size()-1];
			if(Cross(v,w)>0){
				out.pop_back();
			}
			else
			{
				break;
			}
		}
		out.push_back(in[i]);
	}
}

P ps[3000];
int ret[3000];
void run()
{
	int N;
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> ps[i].first >> ps[i].second;
		ret[i]=1;
	}
	int upper=1<<N;
	vector<P> in,out;
	for(int u=0;u<upper;u++){
		int bc=0;
		in.clear();
		out.clear();
		for(int i=0;i<N;i++){
			if(u&(1<<i)){
				bc++;
				in.push_back(ps[i]);
			}
		}
		full(in,out);
		for(int i=0;i<N;i++){
			if(u&(1<<i)){
				for(auto p:out){
					if(p==ps[i]){
						ret[i]=max(ret[i],bc);
					}
				}
			}
		}
	}
	for(int i=0;i<N;i++){
		cout << N-ret[i] << endl;
	}
}


int main() {
	int TotalCase;
	cin >> TotalCase;
	for (int Case=1;Case<=TotalCase;Case++) {
		cout << "Case #" << Case << ": " << endl;
		run();
	}
}
