import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Problem2 {
	public static void main(String args[]) throws IOException
	{
		long t = System.currentTimeMillis();

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine());
		for(int ii=1; ii<=T; ii++)
		{		
			StringTokenizer st = new StringTokenizer(br.readLine());
			int R = Integer.parseInt(st.nextToken());
			int C = Integer.parseInt(st.nextToken());
			int N = Integer.parseInt(st.nextToken());
			int NN = N;
			int M = R*C / 2;
			int min = Integer.MAX_VALUE;
			if(R % 2 == 1 && C % 2 == 1)
			{
				M = (R*C + 1)/2;
				int[] arr = new int[5];
				if(R == 1)
				{
					arr[0] = (C+1)/2;
					arr[1] = 0;
					arr[2] = (C-1)/2;
					arr[3] = 0;
					arr[4] = 0;
				}
				else if(C == 1)
				{
					arr[0] = (R+1)/2;
					arr[1] = 0;
					arr[2] = (R-1)/2;
					arr[3] = 0;
					arr[4] = 0;
				}
				else
				{
					arr[0] = M;
					arr[1] = 0;
					arr[2] = 0;
					arr[3] = 2*(R/2) + 2*(C/2);
					arr[4] = R*C - arr[0] - arr[1] - arr[2] - arr[3];
				}
				int score = 0;
				int i = 0;
				while(N > 0 && i < 5)
				{
					int l = Math.min(arr[i], N);
					N -= l;
					score += i*l;
					i++;
				}
				min = Math.min(score, min);
				M = (R*C - 1)/2;
				arr = new int[5];
				arr[0] = M;
				arr[1] = 0;
				arr[2] = 4;
				arr[3] = 2*((R+1)/2 - 2) + 2*((C+1)/2 - 2);
				arr[4] = R*C - arr[0] - arr[1] - arr[2] - arr[3];

				score = 0;
				i = 0;
				while(NN > 0 && i < 5)
				{
					int l = Math.min(arr[i], NN);
					NN -= l;
					score += i*l;
					i++;
				}
				min = Math.min(score, min);
			}
			else
			{
				int[] arr = new int[5];
				arr[0] = R*C/2;
				if(R == 1)
				{
					arr[1] = 1;
					arr[2] = C/2 - 1;
				}
				else if(C == 1)
				{
					arr[1] = 1;
					arr[2] = R/2 - 1;
				}
				else
				{
					arr[1] = 0;
					arr[2] = 2;
					arr[3] = R + C - 4;
					arr[4] = R*C - arr[0] - arr[1] - arr[2] - arr[3];
				}

				int score = 0;
				int i = 0;
				while(N > 0 && i < 5)
				{
					int l = Math.min(arr[i], N);
					N -= l;
					score += i*l;
					i++;
				}
				min = Math.min(score, min);
			}


			System.out.println("Case #"+ii+": "+min);
		}
		System.out.println(System.currentTimeMillis()-t);
	}
}
//for(int i=0; i<(int)(Math.pow(2,M)); i++)
//{
//	String s = Integer.toBinaryString(i);
//	int c = 0;
//	for(int j=0; j<s.length(); j++)
//		if(s.charAt(j)=='1') c++;
//	if(c == N)
//	{
//		int[][] d = new int[R][C];
//		int e = 0;
//		a:for(int k=0; k<R; k++)
//		{
//			for(int l=0; l<C; l++)
//			{
//				if(e < s.length())
//				{
//					d[k][l] = s.charAt(e)-'0';
//					e++;
//				}
//				else
//					break a;
//			}
//		}
//		int score = 0;
//		for(int k=0; k<R; k++)
//		{
//			for(int l=0; l<C; l++)
//			{
//				if(d[k][l]==1)
//				{
//					if(l+1 < C && d[k][l+1]==1) score++;
//					if(l > 0 && d[k][l-1]==1) score++;
//					if(k > 0 && d[k-1][l]==1) score++;
//					if(k+1 < R && d[k+1][l]==1) score++;
//				}
//			}
//		}
//		min = Math.min(min, score);
//	}
//}