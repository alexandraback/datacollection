import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;


public class Haircut {
	public static void main(String args[]) throws NumberFormatException, IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream("input.txt")));
		
	    int test_no = Integer.parseInt(br.readLine());
	    
	    BufferedWriter out = new BufferedWriter(new FileWriter("out.txt"));	
	
	    for(int i = 1; i <= test_no; i++)
	    {
	    	//int stringlength = Integer.parseInt(br.readLine());
	    	
	    	String[] data = br.readLine().split(" ");
	    	
	    	int B = Integer.parseInt(data[0]);
	    	long N = Long.parseLong(data[1]);
	    	int assign = 0;
	    	
	    	String[] M_k = br.readLine().split(" ");
	    	
	    	long allmincommon = getallmincommon(M_k);
	    	
	    	
	    	long unitnum = 0;
	    	
	    	for(int j = 0; j < M_k.length; j++)
	    	{
	    		unitnum += allmincommon / Long.parseLong(M_k[j]);
	    	}

	    	
	    	long innerindex = N % unitnum;
	    	//System.out.println(innerindex);
	    	if (innerindex == 0)
	    			innerindex = unitnum;
	    	
	    	int count = 0;
	    	int result = 0;
	    	boolean getit = false;
	    	//int oldcount = count;
	    	for(int m = 0; m < allmincommon; m++)
	    	{
		    	for(int j = 0; j < M_k.length; j++)
		    	{
		    		long this_num =  Long.parseLong(M_k[j]);
		    		
		    		if(m % this_num == 0)
		    		{
		    			count++;
		    		}
		    		if (count == innerindex)
		    		{
		    			result = j;
		    			getit = true;
		    			break;
		    		}
		    			
		    	}
		    	if(getit == true)
		    		break;
	    		
	    		
	    	}
	    	

//	    	System.out.println(result + 1);
//	    	System.out.println(count_second2);
	    	out.write("Case #");
	    	out.write(String.valueOf(i));
	    	out.write(": ");
	    	out.write(String.valueOf(result + 1));
	    	out.write("\n");
	    }
	    br.close();
	    out.close();
	    
	    
	}
	
	public static long getallmincommon(String[] alldata)
	{
		long finalresult = Long.parseLong(alldata[0]);
		for(int i = 0; i < alldata.length-1; i++)
		{
			long left = finalresult;
    		long right = Integer.parseInt(alldata[i+1]);
			finalresult = minCommonMultiple(left,right);
			
		}
		
		return finalresult;
	}
	public static long maxCommonDivisor(long m, long n) {  
		  
        if (m < n) {
            long temp = m;  
            m = n;  
            n = temp;  
        }  
        while (m % n != 0) {  
            long temp = m % n;  
            m = n;  
            n = temp;  
        }  
        return n;  
    } 
	
	public static long minCommonMultiple(long m, long n) {  
        return m * n / maxCommonDivisor(m, n);  
    }  
 
}
