#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define li long int
#define lli long long int
#define fri(n) for(li i=0;i<n;i++)
#define frj(n) for(li j=0;j<n;j++)
using namespace std;
string compress(string a, li *b) {
	string ans = "";
	ans += (a.at(0));
	li count = 0;
	fri(a.length())
		b[i]=0;
	b[0] = 1;
	for (li i = 1; i < a.length(); i++) {
		if (a.at(i - 1) != a.at(i)) {
			ans += (a.at(i));
			count++;
		} else
			b[count]++;
	}
	return ans;
}
string firstcompress(string a, li &b) {
	string ans = "";
	ans += (a.at(0));
	b++;
	for (li i = 1; i < a.length(); i++) {
		if (a.at(i - 1) != a.at(i))
		{
			b++;
			ans += (a.at(i));
		}
	}
	return ans;
}
li subsolve(li *a,li n)
{
	li ans=0;
	sort(a,a+n);
	fri(n/2)
	{
		ans+=(a[n/2]-a[i]);
	}
	for(li i=n/2+1;i<n;i++)
	{
		ans+=(a[i]-a[n/2]);
	}
	return ans;
}
li solve(li **b, li m, li n) {
	li *a = new li[n];
	li finans = 0;
	fri(m)
	{
		frj(n)
			a[j] = b[j][i];
		finans+=(subsolve(a,n));
	}
	return finans;
}
int main() {
	freopen("A-large (1).in", "r", stdin);
	freopen("out.in", "w", stdout);
	li t;
	cin >> t;
	for (li ti = 1; ti <= t; ti++) {
		li n;
		cin >> n;
		string *a = new string[n];
		li **b = new li*[n], m = 0;
		fri(n)
		{
			cin >> a[i];
		}
		string refstring = firstcompress(a[0], m);
		bool finans = 1;
		for (li i = 0; i < n; i++) {
			b[i] = new li[a[i].length()];
			if (compress(a[i], b[i]) != refstring) {
				finans = 0;
				break;
			}
		}

		cout << "Case #" << ti << ": ";
		if (finans)
			cout<<solve(b,m,n)<<"\n";
		else
			cout << "Fegla Won\n";
	}
	return 0;

}
