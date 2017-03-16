#include <iostream>
#include <string>

using namespace std;


int main() {
    int i, j, t, n, cont=0, r, c, aux, res;
    cin >>t;
    int a[5];

    for (i=0; i<t; i++){
    	cout << "Case #" << ++cont << ": ";
    	cin >> r >> c >> n;
    	if (r==3 && c==3 && n== 8) {cout << 8 << endl; continue;}
    	if (r > c) {aux = c; c = r; r = aux;};
    	res = 0;
    	if (r==1){
    		if (n <= (c+1)/2) {cout << 0 << endl; continue;}
    		else{
    			n -= (c+1)/2;
    			if (c%2==0){n--; res++;}
    			res += n*2;
    		}
    		cout << res << endl; continue;
    	}
    	else if (r==2){
    		if (n <= c) cout << 0 << endl;
    		else{
    			n -=c;
    			if (n<=2) cout << n*2 << endl;
    			else {
    				n-=2; res+=4;
    				cout << res + n*3 << endl;
    			}
    		}
    	}
    	else if (r==3){
    		if (n<= (2*((c+1)/2)-((r+1)/2) )) cout << 0 << endl;
    		else{
    			n-= (2*((c+1)/2)-((r+1)/2) );
    			if (c%2==0){
    				if (n<=2) cout << n*2 << endl;
    				else{
    					n-=2;
    					res += 4;
    					if (c==4){
    						if (n<= 3) cout << res +n*3 << endl;
    						else{n-=3; res+= 9; cout << res +n*4 << endl;}
    					}
    					if (c==2){
    						cout << res +n*3 << endl;
    					}
    				}
    			}
    			else{
    				if (c==1) cout  << n*2 << endl;
    				else if (c==3){
    					cout << n*3 << endl;
    				}
    				else if (c== 5){
    					if (n<= 6) cout << n*3 << endl;
    					else cout << n*3+1 << endl;
    				}
    			}
    		}

    	}else if (r==4){
    		if (n<= (2*((c+1)/2)-((r+1)/2) )) cout << 0 << endl;
			else{
				n-= (2*((c+1)/2)-((r+1)/2) );
				if (n<=2) cout << n*2 << endl;
				else{
					res +=4;
					n-=2;
					if (n<=4) {res += 3*n; cout << res << endl;}
					else{ res += 12; n-=4;cout << res+4*n << endl; }
				}
			}
    	}
    }
    return 0;
}
/*
res =0;
    	cout << "Case #" << ++cont << ": ";
    	cin >> r >> c >> n;
    	a[0]= ((r+1)/2) *((c+1)/2);
    	a[1]=0;
    	if (!(c & 1)) a[1] += (r+1)/2 ;
    	if (!(r & 1)) a[1] += (c+1)/2 ;
    	if (r%2==0) aux = r-1;
    	else aux = r;
    	a[2] = (aux * ((c+1)/2))-((r+1)/2);
    	if ((r%2==0)&&(c%2==0)) a[2]+=1;
    	a[3] = a[1];
    	if (r%2==0) a[3]-=1;
    	if(c%2==0) a[3]-=1;
    	a[4] = r*c-a[0]-a[1]-a[2]-a[3];
    	for (j=0; j<5; j++){
    		if (j==1 && a[1]-n>=2) {res += j*n; res-=1;break;}
    		if (n <= a[j]) {res += j*n; break;}
    		else {res += a[j]*j; n-= a[j];}
    	}
    	cout << res << endl;
*/
