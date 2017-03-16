package Mushrooms;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class Solution {
	
	List<Integer> res1 = new ArrayList<Integer>();
	List<Integer> res2 = new ArrayList<Integer>();
	
	public int solveFirst(int[] num){
		
		int sum=0;
		for(int i=0;i<num.length-1;i++){
			if(num[i]>num[i+1])
				sum+=(num[i]-num[i+1]);
		}
		
		return sum;
	}
	
	public int solveSecond(int[] num){
		
		int sum = 0;
		int d = 0;
		for(int i=0;i<num.length-1;i++){
			if(num[i]>num[i+1])
				d=Math.max(d, num[i]-num[i+1]);
		}
		for(int i=0;i<num.length-1;i++){
			if(num[i]<=d)
				sum+=num[i];
			else
				sum+=d;
		}
		
		return sum;
		
	}
	
	public void createTestCase(String path){
		try{
			FileInputStream fis = new FileInputStream(path);
			InputStreamReader isr= new InputStreamReader(fis);
			BufferedReader bf = new BufferedReader(isr);
			String s = bf.readLine();
			int caseNumbers = Integer.parseInt(s);

			for(int i=0;i<caseNumbers;i++){
				s = bf.readLine();
				int n = Integer.parseInt(s);
				s = bf.readLine();
				String[] temp = s.split(" ");
				int[] num = new int[n];
				for(int j=0;j<num.length;j++){
					num[j]=Integer.parseInt(temp[j]);
				}
				res1.add(solveFirst(num));
				res2.add(solveSecond(num));
			}
			bf.close();
		}catch(IOException e){
			e.printStackTrace();
		}
	}
	
	public void printAnswer(){
		
		PrintWriter writer;
		try {
			writer = new PrintWriter("output.txt");
			for(int i=0;i<res1.size();i++){
				writer.write("Case #"+(i+1)+":	"+res1.get(i)+" "+res2.get(i));
				writer.write("\n");
			}
			writer.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		}
	}
	
	public static void main(String[] args){
		Solution s = new Solution();
		s.createTestCase("input.txt");
		s.printAnswer();
	}

}
