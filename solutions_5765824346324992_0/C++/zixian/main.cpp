#include <cstdio>
#include <queue>
#include <utility>
using namespace std;

typedef long long ll;
typedef pair<ll, int> lli;
typedef priority_queue<lli> pqlli;

ll gcd(ll a, ll b){ return b==0? a: gcd(b, a%b); }
ll computeLCM(ll a, ll b){  return max(a, b)/gcd(a, b)*min(a, b); }

int main(){
  int numTC, TC = 1, N, B, M[25], n;
  ll lcm;
  scanf("%d", &numTC);
  while(numTC--){
    scanf("%d %d", &B, &N); N--;
    for(int i=0; i<B; i++) scanf("%d", &M[i]);
    lcm = 1; n = 0;
    for(int i=0; i<B; i++) lcm = computeLCM(lcm, M[i]);
    for(int i=0; i<B; i++) n+=(int)(lcm/M[i]);
    N%=n;
    if(N<B){ printf("Case #%d: %d\n", TC++, N+1); continue; }
    pqlli q; ll time = 0;
    for(int i=0; i<N; i++){
      if(i<B) q.push(lli(-M[i], -i));
      else{
	lli temp = q.top(); q.pop(); temp.first-=M[-temp.second]; q.push(temp);
      }
    }
    printf("Case #%d: %d\n", TC++, 1+(-q.top().second));
  }
  return 0;
}
