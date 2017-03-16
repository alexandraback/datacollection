import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Scanner;

// you can also use imports, for example:
// import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
	public static void main(String[] args){
		//int c='Z';
		//System.out.println(c);
		//String finput="/Users/yifangyin/Downloads/A-small-attempt0.in";
		String finput="/Users/yifangyin/Downloads/A-large.in";
		File file = new File(finput);
		int numofcases=0;
		try{
			Scanner sc = new Scanner(file);
			numofcases=sc.nextInt();
			StringBuilder sb=new StringBuilder();
			for(int i=0;i<numofcases;i++){
				int nump=sc.nextInt();
				int[] people=new int[nump];
				for(int j=0;j<nump;j++){
					people[j]=sc.nextInt();
				}
				String output=solver(nump,people);
				String s="Case #"+String.valueOf(i+1)+": "+output;
				sb.append(s);
				sb.append("\n");
				
				//System.out.println(S);
				//System.out.println(s);
			}
			sc.close();
			
			String foutput="/Users/yifangyin/Downloads/test.txt";
			PrintWriter writer = new PrintWriter(foutput);
			writer.println(sb.toString());
			writer.close();
			
		}catch(IOException e){
			e.printStackTrace();
		}
	}
	
	public static String solver(int nump, final int[] people){
		String output="";
		StringBuilder sb=new StringBuilder();
		
		Integer[] idx=new Integer[nump];
		Character[] parties=new Character[nump];
		for(int i=0;i<nump;i++){
			idx[i]=i;
			parties[i]=(char) ('A'+i);
		}
		
		Arrays.sort(idx, new Comparator<Integer>(){
			@Override
			public int compare(Integer idx1, Integer idx2) {
				// TODO Auto-generated method stub
				if(people[idx1]>people[idx2]){
					return -1;
				}else if(people[idx1]<people[idx2]){
					return 1;
				}else{
					return 0;
				}
			}	
		});
		
		int[] tmp=people.clone();
		while(tmp[idx[0]]!=tmp[idx[1]]){
			sb.append(parties[idx[0]].toString()+" ");
			tmp[idx[0]]--;
		}
		
		for(int i=2;i<nump;i++){
			while(tmp[idx[i]]!=0){
				sb.append(parties[idx[i]].toString()+" ");
				tmp[idx[i]]--;
			}
		}
		
		while(tmp[idx[0]]!=0){
			sb.append(parties[idx[0]].toString()+parties[idx[1]].toString()+" ");
			tmp[idx[0]]--;
			tmp[idx[1]]--;
		}
		
		output=sb.toString();
		return output;
	}
}