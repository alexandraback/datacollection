import java.io.FileReader;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;


public class Problem1 {
	
	public static void main(String[] args) throws Exception {
		Scanner scanner = new Scanner(new FileReader("problem1.txt"));
		
		int tests = scanner.nextInt();		
		for(int i = 1; i <= tests; i++) {
			int N = scanner.nextInt();
			
			String[] strings = new String[N];
			for(int j = 0; j < N; j++) {
				strings[j] = scanner.next();
			}
			
			int best = getMinMoves(strings);
			
			if(best == Integer.MAX_VALUE) {
				System.out.printf("Case #%d: Fegla Won\n", i);
			} else {
				System.out.printf("Case #%d: %d\n", i, best);
			}
			
		}
		
		scanner.close();
		
		System.exit(0);
	}
	
	
	public static int getMinMoves(String[] strings) {
		char[] groups = getGroups(strings[0]);
		
		int moves = 0;
		for(int i = 0; i < groups.length; i++) {
			//System.out.println("=====" + groups[i] + "=====");
			//Check if the first character is the group char
			for(String s : strings) {
				if(s.length() == 0 || s.charAt(0) != groups[i]) {
					return Integer.MAX_VALUE;
				}
			}
			
			moves += getMinMoves(strings, groups[i]);
		}
		
		for(String s : strings) {
			if(s.length() != 0) {
				return Integer.MAX_VALUE;
			}
		}
		
		return moves;
	}
	
	public static int getMinMoves(String[] strings, char c) {
		int moves = 0;
		String pattern = "^(" + c + "*)";
		//System.out.println(pattern);
		Pattern r = Pattern.compile(pattern);
		
		int min = Integer.MAX_VALUE;
		int max = Integer.MIN_VALUE;
		int[] lengths = new int[strings.length]; 
		for(int i = 0; i < strings.length; i++) {
			//System.out.println("testing " + strings[i]);
			Matcher m = r.matcher(strings[i]);
			if(m.find()) {
				lengths[i] = m.group(1).length();
				/*while(strings[i].charAt(0) == c) {
					strings[i] = strings[i].substring(1);
					System.out.println("** " + strings[i]);
				}*/
				strings[i] = strings[i].replaceFirst("^" + c + "*", "");
			
				if(lengths[i] < min) min = lengths[i];
				if(lengths[i] > max) max = lengths[i];
			} else {
				return Integer.MAX_VALUE;
			}
		}
		
		int best = Integer.MAX_VALUE;
		for(int a = min; a <= max; a++) {
			int test = 0;
			for(int i = 0; i < lengths.length; i++) {
				test += Math.abs(a - lengths[i]);
				//System.out.println("*** " + test);
			}
			if(test < best) best = test;
		}
		
		return best;
	}
	
	public static char[] getGroups(String s) {
		char[] groups = new char[100];
		
		char[] chars = s.toCharArray();
		
		groups[0] = s.toCharArray()[0];
		int groupIdx = 0;
		for(char c : chars) {
			if(c != groups[groupIdx]) {
				groupIdx++;
				groups[groupIdx] = c;
			}
		}
		groupIdx++;
		
		char[] rtn = new char[groupIdx];
		for(int i = 0; i < groupIdx; i++) {
			rtn[i] = groups[i];
			//System.out.print(rtn[i]);
		}
		
		return rtn;
	}
	


}
