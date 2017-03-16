import java.util.Scanner;


public class B {

	private static boolean[][] field;
	private static int r;
	private static int c;
	private static int n;
	private static int min;
	private static int curr;
	private static int currVal;
	private static boolean[][] minField;
	

	public static void main(String[] args) {
		
		// BufferedReader r = new BufferedReader(new InputStreamReader(System.in));
		// int numCases = Integer.parseInt(r.readLine());
		
		Scanner s = new Scanner(System.in);
		int numCases = s.nextInt();
		
		
		for(int numC = 0; numC < numCases; ++numC)
		{
			r = s.nextInt();
			c = s.nextInt();
			n = s.nextInt();
			
			field = new boolean[r][c];
			min = 1000000;
			curr = 0;
			currVal = 0;
			
			minField = null;
			bruteForce(0, 0);
			
			
			if(n == 0)
			{
				min = 0;
			}
			
			System.out.print("Case #");
			System.out.print(numC+1);
			System.out.print(": ");
			System.out.println(min);
		}

	}
	
	static void bruteForce(int x, int y)
	{
		if(x >= r)
		{
			bruteForce(0, y+1);
			return;
		}
		if(y >= c)
		{
			return;
		}
		
		bruteForce(x+1, y);
		field[x][y] = true;
		
		curr++;
		
		int adding = 0;
		if(saveTest(x-1, y))
		{
			adding++;
		}
		if(saveTest(x+1, y))
		{
			adding++;
		}
		if(saveTest(x, y-1))
		{
			adding++;
		}
		if(saveTest(x, y+1))
		{
			adding++;
		}
		
		currVal += adding;
		
		if(curr == n)
		{
			if(currVal < min)
			{
				min = currVal;
				// minField = field.clone();
			}
		}else
		{
			bruteForce(x+1, y);
		}
		
		currVal -= adding;
		curr--;
		field[x][y] = false;
		
	}
	
	static boolean saveTest(int x, int y)
	{
		if(x < 0 || y < 0 || x >= r || y >= c)
		{
			return false;
		}
		return field[x][y];
	}

}
