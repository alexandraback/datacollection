import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;

public class Repeater {
	public static int[][] charSet(String[] str) {
		ArrayList<Character> chars = new ArrayList<Character>();
		for (int i = 0; i < str[0].length(); i++) {
			if (chars.size() == 0
					|| str[0].charAt(i) != chars.get(chars.size() - 1))
				chars.add(str[0].charAt(i));
		}
/*
		for (int i = 0; i < chars.size(); i++) {
			System.out.print(chars.get(i) + "   ");
		}
		*/
		int[][] charCount = new int[str.length][chars.size()];

		for (int s = 0; s < str.length; s++) {
			ArrayList<Character> temp = new ArrayList<Character>();
			for(int i=0;i<str[s].length();i++){
				if (temp.size() == 0
						|| str[s].charAt(i) != temp.get(temp.size() - 1))
					temp.add(str[s].charAt(i));
			}
			if(chars.size()!=temp.size())return null;
			for(int i=0;i<chars.size();i++){
				if(chars.get(i)!=temp.get(i))return null;
			}
			int charIndex=0;
			for(int i=0;i<str[s].length();i++){
				if(i>0&&str[s].charAt(i)==str[s].charAt(i-1)){
					charCount[s][charIndex-1]++;
				}else if(str[s].charAt(i)==chars.get(charIndex)){
					charCount[s][charIndex]++;
					charIndex++;
				}
			}
		}
		/*
		System.out.println();
		for (int i = 0; i < charCount.length; i++) {
			for (int j = 0; j < charCount[0].length; j++) {
				System.out.print(charCount[i][j] + "   ");
			}
			System.out.println();
			
		}
		*/
		int[][] charCount2 = new int[chars.size()][str.length];
		for(int i=0;i<charCount.length;i++)
			for(int j=0;j<charCount[0].length;j++)
				charCount2[j][i]=charCount[i][j];
		return charCount2;
	}

	
	public static int sum(int[][] count){
		if(null==count)return -1;
		int sum=0;
		for(int i=0;i<count.length;i++){
			sum+=median(count[i]);
			
		}
		
		return sum;
	}
	
	public static int median(int[] array){
		Arrays.sort(array);

		//System.out.println();
		int index=(array.length-1)/2;
		//System.out.println(index);
		
		int sum=0;
		for(int i=0;i<array.length;i++){
			sum+=Math.abs(array[i]-array[index]);
		}
		//System.out.println(sum);
		return sum;
	}
	
	public static void test1() {
		String[] s = { "aaabbb","ab","aabb"};
		int sum=sum(charSet(s));
		System.out.println(sum);
	}
	
	public static void test2() {
		int[] s = { 1,2,3,4,5};
		median(s);
	}

	public static void main(String[] args) {
		try {
			System.setIn(new FileInputStream(
					"/Users/ray/Documents/workspace/CrackCode/CodeJam/input"));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		Scanner sc = new Scanner(System.in);
		int caseNum = Integer.valueOf(sc.nextLine());
		for (int caseid = 1; caseid <= caseNum; caseid++) {
			String[] row1 = sc.nextLine().split(" ");
			int num = Integer.valueOf(row1[0]);
			String[] s=new String[num];
			
			for(int i=0;i<num;i++){
				s[i]=sc.nextLine();
				
			}
			int sum=sum(charSet(s));
			if (sum >= 0) {
				System.out.println("Case #" + caseid + ": " + sum);
			} else
				System.out.println("Case #" + caseid + ": Fegla Won");
			

		}
	}
}
