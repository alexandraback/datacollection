import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Mushrooms {
	public static void main(String args[]) throws IOException
	{
		long t = System.currentTimeMillis();

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int ii=1; ii<=T; ii++)
		{		
			int N = Integer.parseInt(br.readLine());
			StringTokenizer st = new StringTokenizer(br.readLine());
			int[] arr = new int[N];
			for(int i=0; i<N; i++)
				arr[i] = Integer.parseInt(st.nextToken());
			System.out.println("Case #"+ii+": "+min(arr)+" "+ratemin(arr));
		}
		System.out.println(System.currentTimeMillis()-t);
	}
	public static int min(int[] arr)
	{
		int sum = 0;
		for(int i=0; i<arr.length-1; i++)
		{
			if(arr[i+1]<arr[i]) sum += arr[i]-arr[i+1];
		}
		return sum;
	}
	public static int ratemin(int[] arr)
	{
		int max = 0;
		for(int i=0; i<arr.length-1; i++)
		{
			if(arr[i+1]<arr[i]) max = Math.max(arr[i]-arr[i+1], max);
		}
		int sum = 0;
		for(int i=0; i<arr.length-1; i++)
		{
			sum += Math.min(arr[i], max);
		}
		return sum;
	}
}
