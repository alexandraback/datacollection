package codejam.Y2015;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

public class Haircut {
	
	static final String CASE_PREFIX = "Case #";
    static final String COLON = ":";
    static final String BLANK_SPACE = " ";
    static final String COLON_SPACE = COLON+BLANK_SPACE;
    
    /**
	 * 
	 * Declare any static variable over here
	 */
	
    public static void main(String[] args) {
    	String root_path = "C:/Vijay/Workspaces/GoogleCodeJam/";
        String fileName=root_path+"inputFiles/2015/Haircut/B-small-attempt0";
        
        execute(fileName+".in",fileName+"_out.txt");
        System.out.println("Done executing");
     }
    
    static void execute(String inputFileName, String outputFileName){
    	
        try (Scanner reader = new Scanner(new BufferedReader(new FileReader(inputFileName)));
        		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(outputFileName), "utf-8"))	){
           
           
            int T = reader.nextInt();
            for(int caseNumber=1;caseNumber<=T;caseNumber++){
            	int B = reader.nextInt();
            	long N = reader.nextLong();
            	long[] rate = new long[B];
            	for(int i=0;i<B;i++){
            		rate[i]=reader.nextLong();
            	}
                
            	long lcm = lcm(rate);
            	
            	long cyc1_per = 0;
            	for(int i=0;i<B;i++){
            		cyc1_per+=lcm/rate[i];
            	}
            	
            	if(cyc1_per>0)
            		N = N%cyc1_per;
            	if(N==0)N=cyc1_per;
                // Write the logic
                
            	long result = 0;
            	
            	int[] ser = new int[B];
            	int cper=0;
            	
            	z:while(true){
            	for(int i=0;i<B;i++){
	            	if(ser[i]==0){
	            		ser[i] = (int)rate[i];
	            		cper++;
	            		if(cper==N){
	            			result=i+1;
	            			break z;
	            		}
	            	}
	            	ser[i]=ser[i]-1;
            	}
            	}
                
                // write output
                writer.write(CASE_PREFIX+caseNumber+COLON_SPACE+result);
                writer.newLine();
            }
            
            
        } catch (IOException ex) {
            Logger.getLogger(Haircut.class.getName()).log(Level.SEVERE, null, ex);
        }
    }
    
    private static long gcd(long a, long b)
    {
        while (b > 0)
        {
            long temp = b;
            b = a % b; // % is remainder
            a = temp;
        }
        return a;
    }
    
    private static long lcm(long a, long b)
    {
        return a * (b / gcd(a, b));
    }

    private static long lcm(long[] input)
    {
        long result = input[0];
        for(int i = 1; i < input.length; i++) result = lcm(result, input[i]);
        return result;
    }
    
    public static void main2(String[] arg){
    	
    	System.out.println(lcm(new long[]{5,10,36,89,12}));
    }


  
    
}

