package bround;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class Repeater {
	static final String inFile = "A-large.in";
	static final String outFile = "A-large0OUT.txt";
	static Scanner scanner;
	static PrintWriter writer;
	static int numOfLetters = 0;
	
	public static void main(String[] args) throws IOException{
		scanner = new Scanner(new File(inFile));
		writer = new PrintWriter(new File(outFile));
		int numOfTests = scanner.nextInt();
		for(int i = 0; i < numOfTests; i++){
			writer.print("Case #"+(i+1)+": ");solve(i+1);
			
		}
		writer.flush();
		scanner.close();
		writer.close();
		
	}
	public static void solve(int caseNum){
		System.out.println("----------");
		int N = scanner.nextInt();scanner.nextLine();
		String[] words = new String[N];
		for(int i = 0; i < N; i++)
			words[i] = scanner.nextLine();
		Arrays.sort(words, new Comparator<String>() {

			@Override
			public int compare(String o1, String o2) {
				if (o1.length() == o2.length()) return 0;
				if (o1.length() > o2.length()) return 1;
				return -1;
			}});
		boolean possible = true;
		for(int i = 0; i < N - 1; i++) {
			if (!check(words[i], words[i+1], words, i, i+1)) {
				writer.println("Fegla Won"); possible = false; break;
			};
		}
		if (possible) {
			int[][] counts = new int[numOfLetters][words.length];
			for(int j = 0; j < words.length; j++){
				String s = words[j];
				int letter = 0;
				int count = 0;
				int prev = s.charAt(0);
				for (int i = 0; i < s.length(); i++){
					if (prev == s.charAt(i)) count++;
					else {
						prev = s.charAt(i);
						counts[letter][j] = count;
						count = 1;
						letter++;
					}
				counts[letter][j] = count;
				}
			}
			
			int sum = 0;
			for (int i = 0; i < numOfLetters; i++){
				sum += calcDist(counts[i]);
			}
			writer.println(sum);
			
		}
		
		for(int i = 0; i < N; i++)
			System.out.println(words[i]);
	}
	public static boolean check(String s1, String s2, String[] words, int a, int b){
		char[] c1 = s1.toCharArray();
		char[] c2 = s2.toCharArray();
		char prev = '1';
		ArrayList<Character> list1 = new ArrayList<Character>();
		ArrayList<Character> list2 = new ArrayList<Character>();
		for (int i = 0; i < c1.length; i++){
			if (c1[i] != prev) {
				prev = c1[i];
				list1.add(c1[i]);
			}
		}
		prev = '1';
		for (int i = 0; i < c2.length; i++){
			if (c2[i] != prev) {
				prev = c2[i];
				list2.add(c2[i]);
				
			}
		}
		numOfLetters = list2.size();
		return (list1.equals(list2));
		
		/*
		System.out.println("c2: " + Arrays.toString(c2));
		
		
		ArrayList<Character> l1 = new ArrayList<Character>();
		for (int i = 0; i < c1.length; i++){
			l1.add(c1[i]);
		}
		System.out.println("L1: " + Arrays.toString(l1.toArray()));
		
		for(int i = 0; i < c2.length; i++){
			if (i >= l1.size()){
				if (l1.get(l1.size()-1) != c2[i]) return false; 
			}
			else {
				if (l1.get(i) != c2[i]) {
					if (i == 0) return false;
					else if (l1.get(i-1) != c2[i]) return false;
					else l1.add(i, c2[i]);
				}
			}
		}
		char lastC2 = c2[c2.length-1];
		
		for (int i = c2.length - 1; i < l1.size(); i++)
			if (l1.get(i) != lastC2) return false;
		
		return true;*/
	}
	
	public static int calcDist(int[] nums){
		Arrays.sort(nums);
		int med = nums.length/2;
		int medLength = nums[med];
		int sum = 0;
		for (int s : nums){
			sum += Math.abs(s - medLength);
		}
		int med2 = (nums.length + 1)/2;
		if (med != med2) {
			int medLength2 = nums[med2];
			int sum2 = 0;
			for (int s : nums){
				sum2 += Math.abs(s - medLength2);
			}
			return Math.min(sum, sum2);
		}
		return sum;
	}
}
