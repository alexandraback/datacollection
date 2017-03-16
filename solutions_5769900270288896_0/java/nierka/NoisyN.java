import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.InputStream;
import java.util.ArrayList;
import java.util.Scanner;


public class NoisyN {

	public static void generateOutput (ArrayList<Long> TestCases) 
	{
		String outFileName = "C:\\dev\\projects\\R2_2NoisyN\\src\\output.txt";
		try { 
        File file = new File(outFileName);
        BufferedWriter output = new BufferedWriter(new FileWriter(file));
        for (int i =0; i < TestCases.size(); i++) {
        	output.write("Case #" + (i+1) + ": " + TestCases.get(i));
        	output.newLine();
        }
        
        output.close();
		} catch ( Exception e ) {
			e.printStackTrace();
		} 
		
	}
	
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {

		ArrayList<Long> TestCases;
		
		TestCases = new ArrayList<Long>();
		
		String fileName = "C:\\dev\\projects\\R2_2NoisyN\\src\\Example.txt";
		
		try 
		{
			InputStream in = new FileInputStream(new File(fileName));
			Scanner reader = new Scanner(in);
	        

	        int cntTests = reader.nextInt();
	        
	        for (int i = 0; i<cntTests; i++) 
	        {
	        	System.out.println("TEST NUMBER " + i);
	        	long R = reader.nextInt();
	        	long C = reader.nextInt();
	        	long N = reader.nextInt();
	        	long copyN = N;
	        	System.out.println(R+" "+C+" "+N);
	        	long unhappy = 0;
	        	
	        	long zeroH = (R * C) /  2;
	        	
	        	if (C ==1 || R ==1) {
	        		if ((R*C - zeroH) > zeroH) {
		        		zeroH= R*C - zeroH;
		        	}
	        		
	        		if (zeroH > N) {
		        		unhappy = 0;
		        	} else {
		        		N = N - zeroH;
		        		
		        		long corners =1;
		        		
		        		if ((R %2 != 0) && (C%2!=0)) {
		        			corners = 0;
		        		}

		        		if (corners > N) {
		        			unhappy = N * 1;
		        		} else {
		        			N = N - corners;
		        			unhappy = unhappy + corners;
		        			
		        		
		        			unhappy = unhappy + N * 2;
		        			
		        		}
		        	}
	        		
	        	} else {
	        	
	        		
	        		
	        		
	        		
	        		
	        		
	        		
	        	if ((R*C - zeroH) > zeroH) {
	        		zeroH= R*C - zeroH;
	        	}
	        	
	        	if (zeroH > N) {
	        		unhappy = 0;
	        	} else {
	        		N = N - zeroH;
	        		long corners =2;
	        		if ((R %2 != 0)&& (C%2 !=0)) {
	        			corners = 0;
	        		}
	        		
	       
	        		
	        		
	        		
	        		if (corners > N) {
	        			unhappy = N * 2;
	        		} else {
	        			N = N - corners;
	        			unhappy = unhappy + corners *2;
	        			
	        			long unhappy3 = (R+R+C+C-4)/2;
	        			unhappy3 = unhappy3 - corners;
	        			
	        			if (unhappy3 > N) {
		        			unhappy = unhappy + N * 3;
		        		} else {
		        			N = N - unhappy3;
		        			unhappy = unhappy + unhappy3 * 3;
		        			unhappy = unhappy + N * 4;
		        		}
	        		}
	        		
	        		
	        		
	        		if (corners == 0) {
	        			 N = copyN - (R * C) /  2;
	        			 long copyunhap2 = unhappy;
	 	        		unhappy = 0;
	 	        		corners = 4;
	 	        		if (corners > N) {
		        			unhappy = N * 2;
		        		} else {
		        			N = N - corners;
		        			unhappy = unhappy + corners *2;
		        			
		        			long unhappy3 = (R+R+C+C-4)/2;
		        			unhappy3 = unhappy3 - corners;
		        			
		        			if (unhappy3 > N) {
			        			unhappy = unhappy + N * 3;
			        		} else {
			        			N = N - unhappy3;
			        			unhappy = unhappy + unhappy3 * 3;
			        			unhappy = unhappy + N * 4;
			        		}
		        		}
	 	        		
	 	        		if (copyunhap2 < unhappy) {
	 	        			unhappy = copyunhap2;
	 	        		}
	        		}
	        		
	        	}
	        	}

		        	
	        	TestCases.add(unhappy);
	        	System.out.println(unhappy);
	        
	        }
	        reader.close();
		} catch (Exception ex)	{
			ex.printStackTrace();
		}
		
		generateOutput(TestCases);
		System.out.println("Done");

	}


}
