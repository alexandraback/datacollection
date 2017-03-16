package codejam;

import java.io.*;
import java.util.*;

public class smallC1 {

	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int t = in.nextInt();
		//in.nextLine();
		for (int i = 1; i <= t; i++) {
			try { int t2 = in.nextInt();
			int[] arr = new int[t2];
			for (int j = 0; j < t2; j++) {
				arr[j] = in.nextInt();
			}
			
			System.out.println("Case #" + i + ":" + calc(arr));
			}
			catch (Exception e) {
				
			}
		}
	
	}
	
	static char let[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	
	static String calc(int[] p) {
		int total = 0;
		
		String r = "";
		
		for (int i : p)
			total += i;
		
		while (total > 0) {
			ArrayList<Integer> l = getLargestIn(p);
			
			if (l.size() == 1 || l.size() > 2 || total == 3) {
				r += " " + let[l.get(0)];
				total--;
				//p.set(l.get(0), p.get(l.get(0)) - 1);
				p[l.get(0)]--;
				
			}
			else { // == 2
				r += " " + let[l.get(0)];
				r += let[l.get(1)];
				total -= 2;
				//p.set(l.get(0), p.get(l.get(0)) - 1);
				//p.set(l.get(1), p.get(l.get(1)) - 1);
				p[l.get(0)]--;
				p[l.get(1)]--;
			}
		}
		return r;
	}
	
	static ArrayList<Integer> getLargestIn(int[] l) {
		int largest = -1;
		ArrayList<Integer> largest_in = new ArrayList<Integer>();
		
		for (int i = 0; i < l.length; i++) {
			if (l[i] == largest) {
				largest_in.add(i);
			}
			else if (l[i] > largest) {
				largest_in.clear();
				largest_in.add(i);
				largest = l[i];
			}
		}
		
		return largest_in;
	}

}
