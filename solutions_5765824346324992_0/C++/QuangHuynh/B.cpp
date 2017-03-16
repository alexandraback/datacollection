#include <bits/stdc++.h>
using namespace std;

int a[1111], c[111111];
bool fr[111111];
std::vector<int> v;

int gcd(int u, int v){

	int tmp;

    while (u != 0) {
    	tmp = u; u= v % u; v = tmp;
    }
    return v;
}

int lcm(int u, int v){

    return (abs(u*v) / gcd (u,v));
}

int main(){

	freopen("B-small-attempt0.in", "r", stdin);
	freopen("test.out", "w", stdout);

	int test, res1= 0, res2 = 0, carry = 1, n, b;
	bool check;
	scanf("%d", &test);
	for (int i=1; i<= test; i++)
	{
		carry = 1;
		scanf("%d %d", &b, &n);
		for (int j=1; j<= b; j++){
			scanf("%d", &a[j]);
			carry = lcm(a[j], carry);
		}

		for (int j=1; j<= b; j++)
			fr[j] = true;
		v.clear();
		int j = 0;
		v.push_back(0);
		while (j < carry){
			j++;
			check= true;
			while (check) {
				check = false;
				for (int k=1; k<= b; k++)
				if (fr[k]){
					check = true;
					fr[k] = false;
					v.push_back(k);
				}
			}
			for (int k = 1; k<= b; k++){
				if ( j % a[k] == 0){
					fr[k] = true;
				}
			}
		}
		v[0] = v[v.size()-1];
		printf("Case #%d: %d\n", i, v[ n % (v.size() -1)]);
	}
}