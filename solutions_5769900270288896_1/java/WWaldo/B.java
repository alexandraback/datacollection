import java.util.Scanner;


public class B{
	
	
	
	public static void main(String[] args) {
		
		Scanner k = new Scanner(System.in);
		int T = k.nextInt();
		
		for(int i = 0; i < T; i++)
		{
			int R = k.nextInt();
			int C = k.nextInt();
			int N = k.nextInt();
			int N2 = N;
			int output = 0;
			int output2 = 0;
			int walls = ((C - 1) * R) + ((R - 1) * C);
			if(N == R*C)
			{
				output = walls;
				output2 = walls;
			}
			else if(N <= R*C - (R*C/2))
			{
				output = 0;
				output2 = 0;
			}
			else
			{
				int corners = 0;
				int corners2 = 4;
				if(R*C%2 == 0 && R != 1 && C != 1)
				{
					corners = 2;
					corners2 = 2;
				}
				else if(R*C%2 == 0)
				{
					corners = 1;
					corners2 = 1;
				}
				int center = 0;
				int center2 = 0;
				if(R > 2 && C > 2)
				{
					center = ((R - 2) * (C - 2))/2;
					center2 = ((R - 2) * (C - 2)) - center;
				}
				int edges = (R*C/2) - center - corners;
				int edges2 = (R*C-(R*C/2)) - center2 - corners2;
				N = N - (R*C - (R*C/2));
				N2 = N2 - R*C/2;
				//System.out.println(corners2 + " " + edges2 + " " + center2 + " " + N2);
				if(R == 1 || C == 1)
				{
					if(N - corners >= 0)
					{
						output += (corners*1);
						N -= corners;
					}
					else
					{
						output += (N * 1);
						N = 0;
					}
					if(N - edges >= 0)
					{
						output += (edges*2);
						N -= edges;
					}
					else
					{
						output += (N * 2);
						N = 0;
					}
					
					if(N2 - corners2 >= 0)
					{
						output2 += (corners2*1);
						N2 -= corners2;
					}
					else
					{
						output2 += (N2 * 1);
						N2 = 0;
					}
					if(N2 - edges2 >= 0)
					{
						output2 += (edges2*2);
						N2 -= edges2;
					}
					else
					{
						output2 += (N2 * 2);
						N2 = 0;
					}
				}
				else
				{
					if(N - corners >= 0)
					{
						output += (corners*2);
						N -= corners;
					}
					else
					{
						output += (N * 2);
						N = 0;
					}
					if(N - edges >= 0)
					{
						output += (edges*3);
						N -= edges;
					}
					else
					{
						output += (N * 3);
						N = 0;
					}
					
					if(N2 - corners2 >= 0)
					{
						output2 += (corners2*2);
						N2 -= corners2;
					}
					else
					{
						output2 += (N2 * 2);
						N2 = 0;
					}
					if(N2 - edges2 >= 0)
					{
						output2 += (edges2*3);
						N2 -= edges2;
					}
					else
					{
						output2 += (N2 * 3);
						N2 = 0;
					}
				}
				
				if(N - center >= 0)
				{
					output += (center*4);
					N -= center;
				}
				else
				{
					output += (N * 4);
					N = 0;
				}
				
				if(N2 - center2 >= 0)
				{
					output2 += (center2*4);
					N2 -= center2;
				}
				else
				{
					output2 += (N2 * 4);
					N2 = 0;
				}
			}
			if(output2 < output && output2 != 0)
				output = output2;
			System.out.println("Case #"+(i+1)+": " + output);
		}
	}

}
