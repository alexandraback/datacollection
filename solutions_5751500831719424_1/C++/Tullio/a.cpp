#include<cstdio>
#include<cstring>
#include<string>
#include<cctype>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

#define pii pair<int,int>
#define pci pair<char,int>
#define f first
#define s second
#define fr(a,b,c) for(int a = b; a < c; a++)
#define rep(a,b) fr(a,0,b)
#define db if(1)
#define pb push_back

typedef long long ll;

int n;
char name[200][1000];
vector<pci> keys[300];

bool read(){
    if(scanf("%d", &n) == EOF) return false;
	
	rep(i, n) {
		scanf("%s", name[i]);
	}
    return true;
}

int cn = 1;

void func(int index, char* str){
	
	int len = strlen(str);
	
	pci curr = pci(str[0], 1);
	keys[index].clear();
	
	fr(i, 1, len){
		if(str[i] == curr.f) {
			curr.s++;
		} else {
			keys[index].pb(curr);
			curr = pci(str[i], 1);
		}
	}
	
	keys[index].pb(curr);
}

void process(){
	func(0, name[0]);
	int size = keys[0].size();
	
	fr(i, 1, n) {
		func(i, name[i]);
		if (keys[i].size() != size) {
			printf("Case #%d: Fegla Won\n", cn++);
			return;
		}
	}
	
	rep(i, n) {
		rep(j, n) {
			rep(k, size) {
				if (keys[i][k].f != keys[j][k].f) {
					printf("Case #%d: Fegla Won\n", cn++);
					return;
				}
			}
		}
	}
	
	int res = 0;
	
	rep(i, size) {
		int aux = 0;
		rep(j, n) {
			aux = max(aux, keys[j][i].s);
		}
		
		int minval = 1<<20;
		rep(j, aux) {
			int val = 0;
			rep(k, n) {
				val += abs(keys[k][i].s - (j + 1));
			}
			minval = min(minval, val);
		}
		res += minval;
	}

	printf("Case #%d: %d\n", cn++, res);
}

int main(){  
	int t = -1;
	
	scanf("%d", &t);

    while(t-- && read()){
        process();
    }
    
    return 0;
}
