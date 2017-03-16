import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;


public class A
	{

		
		static BufferedReader in = new BufferedReader(new InputStreamReader(
				System.in));
		static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(
				System.out));
		 
		public static void main(String[] args) throws NumberFormatException,
				IOException {
			long test =strToLong(in.readLine());
//			long test =1;
			
			
			for (int i = 0; i < test; i++) {
				req(i);
			}
			out.flush();

		}

		public static void req(int testcase) throws IOException {

		         	out.write("Case #"+(testcase+1)+": ");
//		         	
		         	
		         	int n = strToInt(in.readLine());
		         	
		         	String[] s = in.readLine().split(" ");
		         	
		         	int arr[] = new int[n];
		         	int max_diff = 0;
		         	int ans1=0;
		         	for(int i =0;i<n;i++)
		         		{
		         			arr[i]=strToInt(s[i]);
		         			if(i>0)
		         				{
		         					if(arr[i-1]-arr[i]>max_diff)
		         						{
		         							max_diff= arr[i-1] -arr[i];
		         						}
		         					
		         					if(arr[i]<arr[i-1])
				         				{
				         					ans1+=arr[i-1]-arr[i];
				         				}
		         				}
		         			
		         			
		         			
		         		}
		         	
		         	
		         	int rate = max_diff;
		         	//System.out.println(rate);
		         	int ans2 =0;
		         	for(int i =0;i<n-1;i++)
		         		{
		         			if(arr[i]<rate)
		         				{
		         					ans2+=arr[i];
		         				}
		         			else
		         				ans2+=rate;
		         				
		         		}
		         	
		         	
		         	
		         	out.write(ans1+" "+ans2+"\n");
		         	
		         	
		         	
		    			}
		
		
		

		public static int strToInt(String str) {
			int i = 0;
			int num = 0;
			boolean isNeg = false;
			// Check for negative sign; if it's there, set the isNeg flag
			if (str.charAt(0) == '-') {
				isNeg = true;
				i = 1;
			}
			// Process each character of the string;
			while (i < str.length()) {
				num *= 10;
				num += str.charAt(i++) - '0'; // Minus the ASCII code of '0' to get
				// the value of the charAt(i++).
			}
			if (isNeg)
				num = -num;
			return num;
		}

		public static long strToLong(String str) {
			int i = 0;
			long num = 0;
			boolean isNeg = false;
			// Check for negative sign; if it's there, set the isNeg flag
			if (str.charAt(0) == '-') {
				isNeg = true;
				i = 1;
			}
			// Process each character of the string;
			while (i < str.length()) {
				num *= 10;
				num += str.charAt(i++) - '0'; // Minus the ASCII code of '0' to get
				// the value of the charAt(i++).
			}
			if (isNeg)
				num = -num;
			return num;
		}

	}
