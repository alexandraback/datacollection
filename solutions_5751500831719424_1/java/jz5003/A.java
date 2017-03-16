import java.util.*;
import java.io.*;
public class A {
	static HashSet<Character> hs;
	static int t, freq[][];
	static String[] arr;
	public static void main(String[] args) throws IOException
	{
		BufferedReader in = new BufferedReader(new FileReader("A-large.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("A.out")));
		t = i(in.readLine());
		for(int x = 0; x < t; x++)
		{
			//System.out.printf("Case #%d: ",x+1);
			out.printf("Case #%d: ",x+1);
			boolean fwon = false;
			int n = i(in.readLine());
			arr = new String[n];
			for(int i = 0; i < n; i++)
				arr[i]=in.readLine();
			StringBuilder order =new StringBuilder();
			order.append(arr[0].charAt(0));
			for(int i = 1; i < arr[0].length(); i++)
				if(arr[0].charAt(i)==arr[0].charAt(i-1)) continue;
				else order.append(arr[0].charAt(i));
			//System.out.println(order); //
			int[][] mat = new int[n][order.length()];
			outer:
			for(int i = 0; i < n; i++)
			{
				int k = 0; //index in order
				for(int j = 0; j < arr[i].length();)
				{
					//System.out.println(arr[i].charAt(j)+" "+order.charAt(k));
					if(k>=order.length() || arr[i].charAt(j)!=order.charAt(k)) 
					{
						
						fwon = true;
						break outer;
					}
					while(j < arr[i].length() && arr[i].charAt(j)==order.charAt(k))
					{
						mat[i][k]++;
						j++;
					}
					k++;
				}
				//System.out.println(k);
				if(k!=order.length()) fwon = true;
			}			
			int sum = 0;
			outer:
			for(int i = 0; i < order.length(); i++)
			{
				ArrayList<Integer> f = new ArrayList<Integer>();
				for(int j = 0; j < n; j++)
				{
					f.add(mat[j][i]);
				}
				Collections.sort(f);
				int mid = f.size()>>1;
				int med = (f.size()%2==0)? (f.get(mid-1)+f.get(mid))>>1 : f.get(mid);
				for(int j = 0; j < n; j++)
					sum+=Math.abs(med-mat[j][i]);				
			}
			if(fwon)
			{
				//System.out.println("Fegla Won");
				out.println("Fegla Won");
			}
			else
			{
				//System.out.println(sum);
				out.println(sum);
			}
		}
		out.close();
		System.exit(0);
	}
	static int i(String s)
	{
		return Integer.parseInt(s);
	}
}
