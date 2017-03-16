#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define LL long long

using namespace std;

typedef vector<LL> vi;
typedef vector<vi> vvi;

LL gcd ( LL a, LL b ) {
  LL c;
  while ( a != 0 ) {
     c = a; a = b%a;  b = c;
  }
  return b;
}
vi v;

LL att(LL time) {
    LL ans = 0;
    for (LL i = 0; i < v.size(); ++i) {
        ans += 1 + time/v[i];
    }
    return ans;
}

LL binarylower(LL m,LL l,LL u)
{
	LL mid,c=0;
   	if(l<=u)
	{
 	    	mid=(l+u)/2;
      		if(m==att(mid))
      		{
			c=m;
        	 	return binarylower(m,l,mid-1);
      		}
      		else if(m<att(mid))
		{	
        	  	return binarylower(m,l,mid-1);
      		}
      		else
		{     
			return binarylower(m,mid+1,u);
       		}
    	}
   	else
        	return l;
  }

int main(int argc, char** argv) {

    LL T;
    cin >> T;
    for (LL cases = 1; cases <= T; ++cases) {
        LL B, N;
        cin >> B >> N;
        
        v = vi(B);
        for (LL i = 0; i < B; ++i) cin >> v[i];
        LL low = 0, high = 2e15, midpoLL = 0;
	while (low <= high) {
		midpoLL = low + (high - low)/2;
		if (N <= att(midpoLL))
			high = midpoLL - 1;
		else
			low = midpoLL + 1;
	}
        LL t = low + (high - low)/2;

        LL ans = -1;
        LL c = att(t) - N;

        LL m = t % v[0];
        for (LL i = B-1; i >= 0; --i) m = min(m,  t % v[i]);
        for (LL i = B-1; i >= 0; --i) {
            if (m == t % v[i]) {
                if (c == 0) 
                    ans = i;
                c--;
            }
        }
        cout << "Case #" << cases << ": " << ans+1 << endl;
    }
    return 0;
}

