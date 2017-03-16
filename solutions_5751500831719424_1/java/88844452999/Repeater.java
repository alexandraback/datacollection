package jam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;
import java.util.Collections;

public class Repeater {
	
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		File file=new File("A-large.in");
        Writer output = null;
        File out=new File("A-large.out");
        output = new BufferedWriter(new FileWriter(out));
        BufferedReader fileIn = new BufferedReader(new FileReader(file));
        String fileLine,delims,outs;
        String[] tokens;
        int cases,n,l,i;
        ArrayList<String> words;
        
        String ans;
        
       
        fileLine=fileIn.readLine();
        cases = Integer.parseInt(fileLine);
        delims = "[ ]+";
        System.out.println("Cases = "+cases);
        
        for	(i=0;i<cases;++i)
        {
        words = new ArrayList<String>();
        output.write("Case #");
        output.write(Integer.toString(i+1));
        output.write(": ");
    	fileLine=fileIn.readLine();
    	n = Integer.parseInt(fileLine);
    	for(int j =0;j<n;++j)
    	{
    		fileLine=fileIn.readLine();
    		words.add(fileLine);
    	}
    	 	   	
    	ans = solve(words);
    	output.write(ans);
        output.write("\r\n");
        System.out.println(ans);
        }
        output.close();
	}

	private static String solve(ArrayList<String> words) {
		// TODO Auto-generated method stub
		String s = shrink(words.get(0));
		
		for(String st: words)
		{
			if(!shrink(st).equals(s))
			{
				return"Fegla Won";
			}
				
		}
		
		int le = s.length();
		
		ArrayList<ArrayList<Integer>> intlist = new ArrayList<ArrayList<Integer>>();
		
		for(int i = 0; i < le;++i)
		{
			intlist.add(new ArrayList<Integer>());
		}
		
		for(String st:words)
		{
			int[] t = getarr(st, le);
			for(int i = 0; i < le;++i)
			{
				intlist.get(i).add(t[i]);
			}
		}
		
		int total = 0;
		for(int i = 0; i < le;++i)
		{
			ArrayList<Integer> temp = intlist.get(i);
			Collections.sort(temp);
			int j = 0;
			while(j<temp.size()-1-j)
			{
				total = total + temp.get(temp.size()-1-j) - temp.get(j);
				++j;
			}
		}
		
		
		return Integer.toString(total);
	}
	
	private static String shrink(String s)
	{
		String res = "";
		char c,l;
		c = s.charAt(0);
		res = res + c;
		l = c;
		for(int i = 1;  i < s.length();++i )
		{
			c = s.charAt(i);
			if(c!=l)
			{
				res = res + c;
				l = c;
			}
			
		}
		return res;
	}
	
	private static int[] getarr(String s,int le)
	{
		int arr[] = new int[le];
		char c,l;
		c = s.charAt(0);
		arr[0]=1;
		int k = 0;
		l = c;
		for(int i = 1;  i < s.length();++i )
		{
			c = s.charAt(i);
			if(c!=l)
			{
				k = k + 1;
				arr[k]++;
				l = c;
			}
			else
			{
				arr[k]++;
			}
			
		}
		return arr;
	}
	
	
}
