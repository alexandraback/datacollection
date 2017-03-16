package solution;

import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;



class Solution {
	//io start
	 public ArrayList<String> input;
	 public int index;
	 
	 public Solution() {
		 input = new ArrayList<String>();
		 index = 0;
	 }
	 
	 public void readFile(String inputfile) {
		 String str;
		 try{
	    	 try{
	    		 File f = new File(inputfile);
	    		 BufferedReader br = new BufferedReader(new FileReader(f));
	    		 while(( str = br.readLine()) != null)
	    			 input.add(str);
	    		 br.close();
	    	 }
	    	 catch(FileNotFoundException e) {}
	     }
	     catch(IOException e) {}
	 }
	 
	 
	 public void writeFile(String file, String[] ans) {
		 try{
	    	 try{
	    		 File f = new File(file);
	    		 BufferedWriter bw = new BufferedWriter(new FileWriter(f));
	    		 for(int i = 0; i < ans.length; i++) {
	    			 bw.write(ans[i]);
	    		     bw.write("\n");
	    		 }
	    		 bw.close();
	    	 }
	    	 catch(FileNotFoundException e) {}
	     }
	     catch(IOException e) {}
	 }
	 
	 public String inputNext() {
		 return input.get(index++);
	 }
	 
	//io end  
	
	 public int findMove(ArrayList<String> list) {

		 ArrayList<Character> indchar =  new ArrayList<Character>();
		 String t  = list.get(0);
		 for(int i = 0; i < t.length(); i++) {
			 if(i == 0 || t.charAt(i) != t.charAt(i-1))
				 indchar.add(t.charAt(i));
		 }
		 int[][] sum = new int[list.size()][indchar.size()];
		 for(int i = 0; i < list.size(); i ++) 
			 for(int j = 0; j < indchar.size(); j++)
				 sum[i][j] = 0;
		 for(int i = 0; i < list.size(); i++) {
			 String str = list.get(i);
			 int j = 0;
			 for(int k = 0; k < str.length(); k++) {
				 if(str.charAt(k) == indchar.get(j))
					 sum[i][j]++;
				 else {
					 j++;
					 if( j == indchar.size()) return -1;
					 if( indchar.get(j) != str.charAt(k)) return -1;
					 if( indchar.get(j) == str.charAt(k)) sum[i][j]++;
				 }
			 }	 
		 }
		 int opt = 0;
		 for(int i = 0; i < indchar.size(); i ++) {
			 int[] c = new int[list.size()];
			 for(int j = 0; j < list.size(); j++)
				 c[j] = sum[j][i];
			 Arrays.sort(c);
			 for(int j = 0; j < list.size(); j++) {
				 if(c[j] == 0) return -1;
				 opt += Math.abs(c[j] - c[list.size()/2]);
			 }
		 }
		 return opt;
	 }
	 
     public static void main(String[] args) {
   
    	 String file = "A-large.txt", fileOut = "AlargeOut.txt";
    	 Solution sol = new Solution();
    	 sol.readFile(file);
    	 String[] outlet;
    	 String[] device;
    	 int C;
    	 C = Integer.parseInt(sol.inputNext());
    	 String input;
    	 String[] inputS, ans;
    	 ans = new String[C];
    	 int numString;
    	 ArrayList<String> list;
    	 int move;
    	 for(int i = 0; i < C; i++) {
    		 list = new ArrayList<String>();
    		 numString = Integer.parseInt(sol.inputNext());
    		 for(int j = 0; j < numString; j++)
    			 list.add(sol.inputNext());
    		 move = sol.findMove(list);
    		 if(move == -1)
    			 ans[i] = String.format("Case #%d: Fegla Won", i+1);
    		 else ans[i] = String.format("Case #%d: %d", i+1, move);
    	 }
    	 sol.writeFile(fileOut, ans);
    //	 System.out.println(Long.MAX_VALUE);
    
    	 
    	 
     }
}

