#include <iostream>
#include <queue>  
#include <vector>   
#include <set>
#include <utility>
#include <math.h>       /* atan */
#include <limits>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <string.h>
#include <stdlib.h>
#include <stack>

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
#define foreach(i, n) for (int i = 0; i < (int)(n); i++)
long double diff = 1e-10;

struct Node{
	char sen;
	int no;
};
struct Comp{
    bool operator()(Node& a, Node& b){
    	if(a.no<=b.no)
    		return true;
    	return false;
    }
};
bool debug  = false;
void cal(vector<string> &result, priority_queue<Node, vector<Node>, Comp> &mypq, int totalNO){
	if(totalNO == 0)
		return;
	Node topnode = mypq.top();
	bool OK = true;
	if(debug)
		cout<<"totalNO "<<totalNO<<":"<<mypq.size()<<endl;
	mypq.pop();
	if(mypq.empty() == false){
		Node newtop = mypq.top();
		if(debug)
			cout<<topnode.sen<<":"<<newtop.sen<<endl;
		if(topnode.no>=2){
			if(newtop.no *2 > totalNO-2){
				OK = false;
			}
			else{
				topnode.no -= 2;
				if(topnode.no>0)
					mypq.push(topnode);
				if(debug)
					cout<<"option 1 " <<topnode.sen<<endl;
				string res; res.push_back(topnode.sen); res.push_back(topnode.sen); 
				result.push_back(res);
				totalNO -= 2;
				cal(result, mypq, totalNO);	
				OK=true;
			}
			if(OK)
				return;
		}

		if(topnode.no>=1){
			if(newtop.no *2 > totalNO-1){
				OK = false;
			}
			else{
				topnode.no -= 1;
				if(topnode.no>0)
					mypq.push(topnode);
				if(debug)
				cout<<"option 2 "<<topnode.sen<<endl;
				string res; res.push_back(topnode.sen); 
				result.push_back(res);
				totalNO -= 1;
				cal(result, mypq, totalNO);	
				OK=true;
			}
			if(OK)
				return;
		}
		
		//have to pop 2
		if(debug)
			cout<<"option 3 "<<topnode.sen<<":"<<newtop.sen<<endl;
				
		mypq.pop();
		topnode.no -= 1;
		newtop.no -= 1;		
		if(topnode.no>0)
			mypq.push(topnode);
		if(newtop.no>0)
			mypq.push(newtop);
		string res; res.push_back(topnode.sen); res.push_back(newtop.sen); 
		result.push_back(res);
		totalNO -= 2;
		cal(result, mypq, totalNO);	
	}
	else
		cout<<"untrue"<<endl;
}
int main(int argc, char** argv) {
	int T;
	cin>>T;
	foreach(itest, T){
		int N;
		cin>>N;
		vector<int> PI(N, 0);
		priority_queue<Node, vector<Node>, Comp> mypq;
		int totalNO = 0;
		for(int i=0; i<N; i++){
			cin>>PI[i];
			Node n;
			n.sen = (char)('A'+i);
			n.no = PI[i];
			mypq.push(n);
			totalNO += PI[i];
		}
		
		vector<string> result;
		cal(result, mypq, totalNO);
		
		cout<<"Case #"<<itest+1<<": ";
		for(int i = 0; i<result.size(); i++){
			cout<<result[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
