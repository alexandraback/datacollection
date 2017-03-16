package Round1B;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Comparator;

import input.Input;

public class Problem1 {

	static Input input;

	public static void main(String args[]) {
		String fileName = "A-small-attempt1.in";
		input = new Input(fileName);
		int N = input.nextInt();

		for (int i = 0; i < N; i++) {
			System.out.println("Case #" + (i + 1) + ": " + solve());
		}
	}

	private static String solve() {
		String answer = "Fegla Won";

		int N = input.nextInt();

//		ArrayList<String> list = new ArrayList<String>();
//		for(int i=0;i<N;i++){
//			list.add(input.nextLine());
//		}
		
		String line1 = input.nextLine();
		String line2 = input.nextLine();
		
		int count = 0;
		int i=0;
		int j=0;
		
		while(i < line1.length() || j < line2.length()){
			if(i == line1.length()){
				line1 += "_";
			}
			if(j == line2.length()){
				line2 += "_";
			}
			char c1 = line1.charAt(i);
			char c2 = line2.charAt(j);
			if(c1 != c2){
				if(i > 0 && j > 0){
					char repeat1 = line1.charAt(i-1);
					char repeat2 = line2.charAt(j-1);
					if(repeat1 == c1){
						j--;
						count++;
					}else if(repeat2 == c2){
						i--;
						count++;
					}else{
						return answer;
					}
				}else{
					return answer;
				}
			}
			i++;
			j++;
		}
		
		
		return ""+count;
	}

	public static String sortString(String str) {
		char[] chars = str.toCharArray();
		Arrays.sort(chars);
		String sorted = new String(chars);
		return sorted;
	}
}
