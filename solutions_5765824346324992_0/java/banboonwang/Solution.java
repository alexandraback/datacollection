package HairCut;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

public class Solution {
	
	List<Integer> res = new ArrayList<Integer>();
	
	public int solve(int barbers, int n, int[] time){
		
//		if(n<=barbers) {
//			return n==0?barbers:n;
//		}
		
		Queue<Integer> q = new PriorityQueue<Integer>();

		int[] t = new int[barbers];
		for(int i=1;i<=barbers;i++){
			q.offer(i);
		}
		for(int i=0;i<n;){
			if(!q.isEmpty()){
				if(i==n-1) return q.peek();
				int tmp = q.poll();
				t[tmp-1]=time[tmp-1];
				i++;
			}
			else{
				int min = t[0];
				for(int j=0;j<t.length;j++){
					min=Math.min(min, t[j]);
				}
				for(int j=0;j<t.length;j++){
					t[j]=t[j]-min;
					if(t[j]==0){
						q.offer(j+1);
					}
				}
			}
			
		}
		
		return -1;
	}
	
	public int help(int barbers, int[] time, int n){
		
		int mp = time[0];
		for(int i=1;i<time.length;i++){
			mp = lcm(mp,time[i]);
		}
		
		int count = 0;
		for(int i=0;i<time.length;i++){
			count+=(mp/time[i]);
		}
		
		n = n%count;
		if(n==0) n = count;
		
		return solve(barbers,n,time);
	}
	
	public int gcd(int m, int n){
		if (n == 0)
			return m;
		else
			return gcd(n, m%n);
	}
	
	public int lcm(int m, int n){
		return m*n/gcd(m,n);
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
				String[] tmp = s.split(" ");
				int barbers = Integer.parseInt(tmp[0]);
				int n = Integer.parseInt(tmp[1]);
				s = bf.readLine();
				String[] temp = s.split(" ");
				int[] num = new int[barbers];
				for(int j=0;j<num.length;j++){
					num[j]=Integer.parseInt(temp[j]);
				}
				res.add(help(barbers,num,n));
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
			for(int i=0;i<res.size();i++){
				writer.write("Case #"+(i+1)+":	"+res.get(i));
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
