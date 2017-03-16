#include<cstdio>
#include<cstring>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
#include<cmath>

using namespace std;
const int N = 3100;
typedef double real;
struct vec2{
	real x, y;
	vec2(real x=0.0, real y=0.0):x(x), y(y){}
	vec2 operator+(const vec2 &b)const{ return vec2(x+b.x, y+b.y);}
	vec2 operator-(const vec2 &b)const{ return vec2(x-b.x, y-b.y);}
	vec2 operator*(const real &b)const{ return vec2(x*b, y*b);}
	vec2 operator/(const real &b)const{ return vec2(x/b, y/b);} real operator*(const vec2 &b)const{ return x*b.x + y*b.y;}
	real operator^(const vec2 &b)const{ return x*b.y - y*b.x;}
	real len(){return sqrt(x*x+y*y);}
	vec2 unit(){ return *this/len();}
	vec2 rotate(real r){vec2 t(sin(r), cos(r));return vec2(*this ^ t, *this * t);}
	bool operator<(const vec2 &b)const{
		return atan2(y, x) < atan2(b.y, b.x);
	}
};
vec2 b[N];
int n;

void print(vec2 a[], int n){
	for (int i=0; i<n; ++i){
		printf("(%lf,%lf),", a[i].x, a[i].y);
	}
	puts("");
}
int gao(vec2 c, int id, int n){
	vec2 a[N*2];
	for (int i=0; i<n; ++i) a[i] = b[i] - c;
	swap(a[id], a[n-1]);
	n --;
	sort(a, a+n);
	//print(a, n);
	for (int i=0; i<n; ++i) a[i+n] = a[i];
	int ans = n;
	for(int i=0, j=0; i<n; ++i){
		if (j == i) j ++;
		for (; j<2*n; ++j){
			if ((a[i] ^ a[j]) <= 0) break;
		}
		ans = min(ans, j-i-1);
	}
	return ans;
}
int main(){
	int T;
	cin >> T;
	for(int cas=1; cas<=T; ++cas){
		cin >> n;
		for (int i=0; i<n; ++i){
			cin >> b[i].x >> b[i].y;
		}
		printf("Case #%d:\n", cas);
		for (int i=0; i<n; ++i){
			printf("%d\n", gao(b[i], i, n));
		}
	}
	return 0;
}
