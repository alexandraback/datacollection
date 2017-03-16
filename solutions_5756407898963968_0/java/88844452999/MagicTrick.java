package jam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Writer;
import java.util.ArrayList;

public class MagicTrick {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		  File file=new File("A-small-attempt0.in");
	        Writer output = null;
	        File out=new File("A-small-attempt0.out");
	        output = new BufferedWriter(new FileWriter(out));
	        BufferedReader fileIn = new BufferedReader(new FileReader(file));
	        String fileLine,delims,outs;
	        String[] tokens;
	        int cases,rowa,rowb,i;
	        ArrayList<Integer> itemsa = null,itemsb = null;
	        String ans;
	        
	        
	        fileLine=fileIn.readLine();
	        cases = Integer.parseInt(fileLine);
	        delims = "[ ]+";
	        System.out.println("Cases = "+cases);
	        
	        for	(i=0;i<cases;++i)
	        {
	        output.write("Case #");
	        output.write(Integer.toString(i+1));
	        output.write(": ");
	    	fileLine=fileIn.readLine();
	    	rowa = Integer.parseInt(fileLine);
	    	for(int j=1;j<=4;++j)
	    	{
	    		fileLine=fileIn.readLine();
	    		if(rowa==j)
	    		{
	    			tokens = fileLine.split(delims);
	    			itemsa = new ArrayList<Integer>();
	    			itemsa.add(Integer.parseInt(tokens[0]));
	    			itemsa.add(Integer.parseInt(tokens[1]));
	    			itemsa.add(Integer.parseInt(tokens[2]));
	    			itemsa.add(Integer.parseInt(tokens[3]));
	    		}
	    		
	    	}
	    	fileLine=fileIn.readLine();
	    	rowb = Integer.parseInt(fileLine);
	    	for(int j=1;j<=4;++j)
	    	{
	    		fileLine=fileIn.readLine();
	    		if(rowb==j)
	    		{
	    			tokens = fileLine.split(delims);
	    			itemsb = new ArrayList<Integer>();
	    			itemsb.add(Integer.parseInt(tokens[0]));
	    			itemsb.add(Integer.parseInt(tokens[1]));
	    			itemsb.add(Integer.parseInt(tokens[2]));
	    			itemsb.add(Integer.parseInt(tokens[3]));
	    		}
	    		
	    	}
	    	
	    	ans = solve(itemsa,itemsb);
	        output.write(ans);
	        output.write("\r\n");
	        System.out.println(ans);
	        }
	        output.close();

	        
	}

	private static String solve(ArrayList<Integer> itemsa, ArrayList<Integer> itemsb) {
		// TODO Auto-generated method stub
		
		int result = -1;
		
		for( Integer i : itemsa)
		{
			if(itemsb.contains(i)&&result==-1)
			{
				result = i;
			}
			else if(itemsb.contains(i)&&result!=-1)
			{
				return"Bad magician!";
			}
		}
		
		if(result==-1)
		{
			return "Volunteer cheated!";
		}
		else
		{
			return Integer.toString(result);
		}
		
	}

}
