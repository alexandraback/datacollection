import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;


public class Barber {
	static final String filename = "B-large.in";

	static Scanner seer;
	static int T;
	static int B;
	static long N;
	static int i;
	static long[] numlist;

	public static void main(String[] args) throws FileNotFoundException {
		//seer = new Scanner(System.in);
		seer = new Scanner(new File(filename));
		T = seer.nextInt();
		for(i = 0; i < T; i++){
			B = seer.nextInt();
			N = seer.nextInt();
			numlist = new long[B];
			for(int j = 0; j < B; j++){
				numlist[j] = seer.nextInt();
			}
			N = (N % mod()) + mod();
			long res = B-1;
			long[] currlist = new long[B];
			while(N>0){
				for(int ind = 0; ind < B; ind++){
					if(currlist[ind]==0){
						N--;
						currlist[ind] = numlist[ind];
						if(N == 0){
							res = ind;
							break;
						}
					}
				}
				for(int ind = 0; ind < B; ind++){
					currlist[ind]--;
				}
			}
			System.out.printf("Case #%d: %d\n",i+1,res+1);
		}
	}


	static long mod(){
		long lcm = lcm(numlist); //System.out.prlongln("lcm "+lcm);
		long tot = 0;
		for(int ind = 0; ind < numlist.length; ind++){
			tot += lcm/(numlist[ind]);
		} //System.out.prlongln("tot "+tot);
		return tot;
	}
	
	//from http://www.java2s.com/Tutorial/Java/0120__Development/LeastCommonMultipleLCMoftwostrictlypositivelongegernumbers.htm
	public static final long lcm(long x1,long x2) {
		long max,min;
		if (x1>x2) {
			max = x1;
			min = x2;
		} else {
			max = x2;
			min = x1;
		}
		for(long i=1; i<=min; i++) {
			if( (max*i)%min == 0 ) {
				return i*max;
			}
		}
		return 0;
	}

	/** 
	 * Method that calculates the Least Common Multiple (LCM) of several
	 * positive longeger numbers.
	 *
	 * @param x Array containing the numbers.
	 * */
	public static final long lcm(long[] x) {
		long tmp = lcm(x[x.length-1],x[x.length-2]);
		for(int i=x.length-3; i>=0; i--) {
			tmp = lcm(tmp,x[i]);
		}
		return tmp;
	}


}
