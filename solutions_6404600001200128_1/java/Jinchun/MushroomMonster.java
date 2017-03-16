import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;


public class MushroomMonster {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		Scanner in = new Scanner(new File("A-large.in"));//C-small-practice.in
		PrintWriter out = new PrintWriter("out.txt");
		int T = in.nextInt();
		for(int i=1;i<=T;i++){
			int N = in.nextInt();
			int[] num = new int[N];
			for(int j=0;j<N;j++){
				num[j] = in.nextInt();
			}
			int res1 = minM(num);
			int res2 = minMC(num);
			out.println("Case #"+i+": "+res1+" "+res2);
		}
		out.close();
		in.close();
	}
	
	private static int minM(int[] num){
		int res = 0;
		for(int i=1;i<num.length;i++){
			if(num[i]<num[i-1]){
				res+=num[i-1]-num[i];
			}
		}
		return res;
	}
	private static int minMC(int[] num){
		int res = 0;
		int speed=0;
		for(int i=1;i<num.length;i++){
			speed=Math.max(speed, num[i-1]-num[i]);
		}
		for(int i=1;i<num.length;i++){
			res+=Math.min(speed, num[i-1]);
		}
		return res;
	}

}
