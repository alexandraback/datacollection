import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class B
	{

		static BufferedReader	in	= new BufferedReader(new InputStreamReader(
											System.in));
		static BufferedWriter	out	= new BufferedWriter(
											new OutputStreamWriter(System.out));

		public static void main(String[] args) throws NumberFormatException,
				IOException
			{
				long test = strToLong(in.readLine());
				// long test =1;

				for (int i = 0; i < test; i++)
					{
						req(i);
					}
				out.flush();

			}

		public static void req(int testcase) throws IOException
			{

				out.write("Case #" + (testcase + 1) + ": ");
				//

				String[] s = in.readLine().split(" ");

				int b = strToInt(s[0]);
				int n = strToInt(s[1]);

				s = in.readLine().split(" ");
				int[] arr = new int[b];
				int[] arr2 = new int[b];

				long max = 0;
				for (int i = 0; i < b; i++)
					{
						arr[i] = strToInt(s[i]);
						arr2[i] = strToInt(s[i]);
						if (arr2[i] > max)
							{
								max = arr[i];
							}
					}
				long lcm = 1;
				int a = 2;
				if (max != 1)
					{
						while (true)
							{  
								boolean done =false;
								boolean flag = false;
								boolean mult  =false;
								for (int i = 0; i < b; i++)
									{
										  if(arr2[i]%a==0){
											 mult =true;
                                          arr2[i]/=a;
										  }
										  if(arr2[i]!=1)
											  {
												  done =true;
											  }
										  if(arr2[i]%a==0)
											  {
												  flag=true;
											  }
										  
									}
								if(mult)
								lcm*=a;
								//System.out.println(Arrays.toString(arr2)+ " "  +lcm+ " "+a);
								if(!flag)
									{
										a++;
										//lcm/=a;
									}
								
								if(!done)
									{
										break;
									}
								
								//System.out.println(Arrays.toString(arr2)+ " "  +lcm+ " "+a);
							}
					}
				long turn = 1;
				long cust = 0;
				long ans = -1;
				
				//System.out.println(lcm);
				
				
				long inLcm = 0;
				for(int i =0;i<b;i++)
					{
						inLcm+=lcm/arr[i];
					}
				
				// System.out.println(inLcm);
				if(n<=b)
					{
						out.write(n+"\n");
						return;
					}
				else
					{
						n-=b;
						n=(int)(n%inLcm);
								
					}
				//System.out.println(n);
				if(n!=0)
					{
						outer: while (true)
							{

								for (int i = 0; i < b; i++)
									{
										if (turn % arr[i] == 0)
											{
												cust++;
												// //System.out.println(i +" "+ cust+" "
												// + turn);
												if (cust == n)
													{
														ans = i + 1;
														break outer;
													}
											}
									}
								turn++;

							}

					}
				else
					ans =b;
				out.write(ans + "\n");

			}

		public static int strToInt(String str)
			{
				int i = 0;
				int num = 0;
				boolean isNeg = false;
				// Check for negative sign; if it's there, set the isNeg flag
				if (str.charAt(0) == '-')
					{
						isNeg = true;
						i = 1;
					}
				// Process each character of the string;
				while (i < str.length())
					{
						num *= 10;
						num += str.charAt(i++) - '0'; // Minus the ASCII code of
														// '0' to get
						// the value of the charAt(i++).
					}
				if (isNeg)
					num = -num;
				return num;
			}

		public static long strToLong(String str)
			{
				int i = 0;
				long num = 0;
				boolean isNeg = false;
				// Check for negative sign; if it's there, set the isNeg flag
				if (str.charAt(0) == '-')
					{
						isNeg = true;
						i = 1;
					}
				// Process each character of the string;
				while (i < str.length())
					{
						num *= 10;
						num += str.charAt(i++) - '0'; // Minus the ASCII code of
														// '0' to get
						// the value of the charAt(i++).
					}
				if (isNeg)
					num = -num;
				return num;
			}

	}
