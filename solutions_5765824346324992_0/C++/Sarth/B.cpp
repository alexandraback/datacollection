#include <cstdio>
#include <vector>
#include <set>
struct Barber
{
	Barber() {freeAt = 0; customer = -1;}

	long long freeAt;
	int customer;

	int mk;
	int myNum;

	bool operator<(const Barber &b)const {
		if (this->freeAt != b.freeAt)
			return this->freeAt < b.freeAt;
		else
			return this->myNum < b.myNum;
	}
};
long long gcd(long long a, long long b)
{
	long long c, temp;
	while (a %b != 0){
		c = a%b;
		temp = b;
		b = c;
		a = temp;
	}
	return b;
}

long long findLCM(long long a, long long b)
{
	long long  g = gcd(a, b);
	return (a/g)*b;

}



void solve(int caseNo)
{
	int B, N;
	Barber M[1001];

	scanf("%d %d", &B, &N);
	long long lcm = 1;
	for (int i = 0; i != (B); i++){
		scanf("%d", &M[i].mk);
		M[i].myNum = (i+1);
		lcm = findLCM(M[i].mk, lcm);
	}
	//printf("\n LCM: %I64d", lcm);
	int total = 0;
	for (int i = 0; i != (B); i++){
		total += lcm/M[i].mk;
	}
	if (N > total) N = N % total;
	if (N == 0) N += total;

	std::set<Barber> bset(M, M+B);
	std::set<Barber> ::iterator it;
	for (int j = 1; j < N; j++){
		it = bset.begin();
		//Remove from set
		Barber b = *it;
		bset.erase(it);

		b.customer = j;
		b.freeAt += b.mk;

		bset.insert(b);
	}
	it = bset.begin();

	if (caseNo > 1)
		printf("\n");
	printf("Case #%d: %d", caseNo, it->myNum);
}

int main()
{
	int numOfTestCases, i;
	scanf("%d", &numOfTestCases);
	for (i = 0; i < numOfTestCases; i++){
		solve(i+1);
	}
}
