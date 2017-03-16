#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>

using namespace std;

void solve(int testcase);

int main() {
    int N;
    cin >> N;
    for(int i=0; i<N; ++i)
        solve(i+1);
}

class vec {
public:
	long x,y;
	vec() : x(0),y(0) {}
	vec(long x,long y) : x(x),y(y) {}
	
	vec operator-(vec &rhs) {
		return vec(x-rhs.x,y-rhs.y);
	}
	vec normal() {
		vec ret;
		ret.x = -y;
		ret.y = x;
		return ret;
	}
};
long operator*(vec lhs,vec rhs) {
	return lhs.x*rhs.x + lhs.y*rhs.y;
}

unsigned numcuts(vec trees[], unsigned numtrees, unsigned treeindex) {
	vec tree = trees[treeindex];
	unsigned minimum = numtrees-1;
	for(unsigned i=0; i<numtrees; i++){
		if(i==treeindex) continue;
		vec normal = (trees[i]-tree).normal(); // create hyperplane (line)
		long b = normal.x*tree.x + normal.y*tree.y;
		unsigned left = 0, right = 0;
		for(unsigned j=0; j<numtrees; ++j) {
			long val = normal * trees[j];
			//cerr << treeindex << " " << i << " " << j << " (" << normal.x << " " << normal.y << ") = " << b << "   " << val << endl;
			if(val < b) left++;
			else if(val > b) right++;
		}
		//cerr << "bla " << left  << " " << right << endl;
		minimum = min(minimum,min(left,right));
		if(minimum == 0) break;
	}
	return minimum;
}
void solve(int testcase) {
    unsigned numtrees;
    cin >> numtrees;
    vec trees[numtrees];
    for(unsigned i=0; i<numtrees; ++i) {
    	cin >> trees[i].x >> trees[i].y;
    }
    cout << "Case #" << testcase << ": " << endl;
    for(unsigned i=0; i<numtrees; ++i) {
    	cout << numcuts(trees,numtrees,i) << endl; 
    }
}
