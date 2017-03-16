import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;


public class Barber {
	static final String filename = "B-small-attempt8.in";

	static Scanner seer;
	static int T;
	static int B;
	static int N;
	static int i;
	static int[] numlist;

	public static void main(String[] args) throws FileNotFoundException {
		//seer = new Scanner(System.in);
		seer = new Scanner(new File(filename));
		T = seer.nextInt();
		for(i = 0; i < T; i++){
			B = seer.nextInt();
			N = seer.nextInt();
			numlist = new int[B];
			for(int j = 0; j < B; j++){
				numlist[j] = seer.nextInt();
			}
			N = (N % mod()) + mod();
			int res = B-1;
			int[] currlist = new int[B];
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


	static int mod(){
		int lcm = lcm(numlist); //System.out.println("lcm "+lcm);
		int tot = 0;
		for(int ind = 0; ind < numlist.length; ind++){
			tot += lcm/(numlist[ind]);
		} //System.out.println("tot "+tot);
		return tot;
	}
	
	//from http://www.java2s.com/Tutorial/Java/0120__Development/LeastCommonMultipleLCMoftwostrictlypositiveintegernumbers.htm
	public static final int lcm(int x1,int x2) {
		int max,min;
		if (x1>x2) {
			max = x1;
			min = x2;
		} else {
			max = x2;
			min = x1;
		}
		for(int i=1; i<=min; i++) {
			if( (max*i)%min == 0 ) {
				return i*max;
			}
		}
		return 0;
	}

	/** 
	 * Method that calculates the Least Common Multiple (LCM) of several
	 * positive integer numbers.
	 *
	 * @param x Array containing the numbers.
	 * */
	public static final int lcm(int[] x) {
		int tmp = lcm(x[x.length-1],x[x.length-2]);
		for(int i=x.length-3; i>=0; i--) {
			tmp = lcm(tmp,x[i]);
		}
		return tmp;
	}


}
