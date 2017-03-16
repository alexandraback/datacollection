import java.io.File;
import java.util.Arrays;
import java.util.Scanner;


public class Noisy {
	public static void main(String[] args) throws Exception{
		Scanner s = new Scanner(new File("B-small-attempt0.in"));
		int numCases = Integer.parseInt(s.nextLine());
		for(int currentCase = 1;currentCase<=numCases;currentCase++) {
			String items = s.nextLine();
			String[] itemsArr = items.split("\\s+");
			int r = Integer.parseInt(itemsArr[0]);
			int c = Integer.parseInt(itemsArr[1]);
			int n = Integer.parseInt(itemsArr[2]);
			int result = solve(r,c,n);
			System.out.println("Case #" + currentCase + ": " + solve(r,c,n));
		}
	}
	public static int solve(int r, int c, int n) {
		
		return solve(r,c,n,new boolean[r*c],0,0);
	}
	public static int solve(int r, int c, int n, boolean[] placed, int nextAvail, int unhappiness) {
		//System.out.println(n + " : " + Arrays.toString(placed));
		if(n==0) return unhappiness;
		int min = Integer.MAX_VALUE;
		for(int place = nextAvail;place<=r*c-n;place++) {
			placed[place] = true;
			int newUnhappy = 0;
			if(place % r !=0 && placed[place-1]) newUnhappy++;
			if(place / r !=0 && placed[place-r]) newUnhappy++;
			int result = solve(r,c,n-1,placed,place+1,unhappiness+newUnhappy);
			placed[place] = false;
			if(result<min) 
				min = result;
		}
		return min;
	}
}
