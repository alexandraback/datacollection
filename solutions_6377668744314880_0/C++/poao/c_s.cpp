#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

// only for small

struct p {
	int x, y;
	bool operator<(const p&b) const {
		return x==b.x ? y<b.y : x<b.x;
	}
	bool operator==(const p&b) const {
		return x==b.x && y==b.y;
	}
} ;

p log[20];
int ans[20];
int T, N;

long long cross(p&o, p&a, p&b) {
	long long ret = (long long)(a.x-o.x) * (b.y-o.y) - (long long)(a.y-o.y) * (b.x-o.x);
	//printf("(%2d,%2d) -> (%2d,%2d) -> (%2d,%2d): %d\n", o.x, o.y, a.x, a.y, b.x, b.y, ret);
	return ret;
}

std::vector<p> calc(std::vector<p> lst) {
	int n = (int)lst.size();
	std::vector<p> ret;
	std::sort( lst.begin(), lst.end() );
	p stack[40];
	int top = -1;
	for(int i=0; i<n; i++) {
		while( top > 0 ) {
			//printf("i %d(%2d,%2d) top %d\n", i, lst[i].x, lst[i].y, top);
			if( cross( stack[top-1], stack[top], lst[i] ) <= 0 ) break;
			top --;
		}
		top ++;
		stack[top] = lst[i];
	}
	int count = top;
	for(int i=n-1; i>=0; i--) {
		while( top > 0 ) {
			if( cross( stack[top-1], stack[top], lst[i] ) <= 0 ) break;
			top --;
		}
		top ++;
		stack[top] = lst[i];
	}
	/*printf("==========\n");
	for(int i=0; i<=top; i++) {
		printf("%d %d\n", stack[i].x, stack[i].y);
	}//*/
	for(int i=0; i<=top; i++) {
		ret.push_back(stack[i]);
	}
	return ret;
}

int main() {
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		scanf("%d", &N);
		for(int i=0; i<N; i++) {
			scanf("%d%d", &log[i].x, &log[i].y);
		}
		memset(ans, 0, sizeof(ans));
		for(int st=(1<<N)-1; st>0; st--) {
			std::vector<p> lst;
			for(int i=0; i<N; i++) {
				if( st & (1<<i) ) {
					lst.push_back( log[i] );
				}
			}
			std::vector<p> ret_lst = calc(lst);
			for(int i=0; i<N; i++) {
				if( st & (1<<i) ) {
					bool is_in = false;
					for(auto it=ret_lst.begin(); it!=ret_lst.end(); ++it) {
						if( *it == log[i] ) {
							is_in = true;
							break;
						}
					}
					if( is_in ) {
						ans[i] = std::max( ans[i], (int)lst.size() );
					}
				}
			}
			//break;
		}
		printf("Case #%d:\n", tc);
		for(int i=0; i<N; i++) {
			printf("%d\n", N-ans[i]);
		}
	}
	return 0;
}