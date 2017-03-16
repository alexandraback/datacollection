package Round1B;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

import input.Input;

public class LargeProblem1 {

	static Input input;

	public static void main(String args[]) {
		String fileName = "A-large.in";
		input = new Input(fileName);
		int N = input.nextInt();

		for (int i = 0; i < N; i++) {
			System.out.println("Case #" + (i + 1) + ": " + solve());
		}
	}

	private static String solve() {
		String answer = "Fegla Won";

		int N = input.nextInt();

		ArrayList<String> list = new ArrayList<String>();
		String pattern = "";
		boolean cont = true;
		for(int i=0;i<N;i++){
			String initialTest = "";
			String line = input.nextLine();
			for(int j = 0 ; j < line.length() ; j++){
				if(j==0){
					initialTest += line.charAt(j);
				}else{
					if(line.charAt(j-1) != line.charAt(j)){
						initialTest += line.charAt(j);
					}
				}
			}
			if(i==0){
				pattern = initialTest;
			}else{
				if(!initialTest.equals(pattern)){
					cont = false;
				}
			}
			list.add(line);
		}
		
		if(!cont){
			return answer;
		}
		
		int arr[][] = new int[list.size()][pattern.length()];
		int k=0;
		int i=0;
		
		for(String line : list){
				for(int j=0;j<pattern.length();j++){
					while(i < line.length() && line.charAt(i) == pattern.charAt(j)){
						arr[k][j]++;
						i++;
					}
			}
			k++;
			i=0;
		}
		
		int min = 0;
		
		for(int kk=0;kk<pattern.length();kk++){
			int[] a = new int[list.size()];
			for(int ii=0;ii<list.size();ii++){
				a[ii] = arr[ii][kk];
			}
			Arrays.sort(a);
			if(a.length % 2 == 0){
				int m1 = a.length/2;
				int m2 = m1 - 1;
				min += Math.min(diff(a, m1), diff(a, m2));
			}else{
				int median = a.length/2;
				min += diff(a,median);
			}
		}
		return ""+min;
	}
	
	public static int diff(int[] a, int median){
		int diff = 0;
		if(median >= a.length){
			return 0;
		}
		int val = a[median];
		for(int i=0;i<a.length;i++){
			diff +=  Math.abs(a[i] - val);
		}
		return diff;
	}
	
}
