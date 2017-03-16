import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.util.Scanner;


public class Round1B_P2 {
	
	public static int randomSol(int r, int c, int n)
	{
		boolean[][] mat = new boolean[r][c];

		while(n > 0)
		{
			int i = (int)(Math.random()*r);
			int j = (int)(Math.random()*c);
			if(!mat[i][j]  && n > 0)
			{
				mat[i][j] = true;
				n--;
			}
			
		}
				
		return unhappy(mat, r, c);
	}
	
	public static int sol3(int r, int c, int n)
	{
		boolean[][] mat = new boolean[r][c];
		
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
			{
				if((i+j) % 2 == 0 && n > 0 && (i == 0 || i == r-1 || j == 0 || j == c-1))
				{
					mat[i][j] = true;
					n--;
				}
				
			}
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
			{
				if(!mat[i][j] && (i+j) % 4 == 0 && n > 0)
				{
					mat[i][j] = true;
					n--;
				}
				
			}
		if(n > 0)
		{
			for(int i = 0; i < r; i++)
				for(int j = 0; j < c; j++)
				{
					if(!mat[i][j] && (i == 0 || i == r-1 || j == 0 || j == c-1) && n > 0)
					{
						mat[i][j] = true;
						n--;
					}
					
				}
				
		}
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
			{
				if(!mat[i][j] && (i+j) % 2 == 0 && n > 0)
				{
					mat[i][j] = true;
					n--;
				}
				
			}
		
		if(n > 0)
		{
			for(int i = 0; i < r; i++)
				for(int j = 0; j < c; j++)
				{
					if(!mat[i][j]  && n > 0)
					{
						mat[i][j] = true;
						n--;
					}
					
				}
				
		}
				
		return unhappy(mat, r, c);
	}
	
	
	public static int sol2(int r, int c, int n)
	{
		boolean[][] mat = new boolean[r][c];
		
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
			{
				if((i+j) % 2 == 0 && n > 0 && (i == 0 || i == r-1 || j == 0 || j == c-1))
				{
					mat[i][j] = true;
					n--;
				}
				
			}

		if(n > 0)
		{
			for(int i = 0; i < r; i++)
				for(int j = 0; j < c; j++)
				{
					if(!mat[i][j] && (i == 0 || i == r-1 || j == 0 || j == c-1) && n > 0)
					{
						mat[i][j] = true;
						n--;
					}
					
				}
				
		}
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
			{
				if(!mat[i][j] && (i+j) % 2 == 0 && n > 0)
				{
					mat[i][j] = true;
					n--;
				}
				
			}
		
		if(n > 0)
		{
			for(int i = 0; i < r; i++)
				for(int j = 0; j < c; j++)
				{
					if(!mat[i][j]  && n > 0)
					{
						mat[i][j] = true;
						n--;
					}
					
				}
				
		}
				
		return unhappy(mat, r, c);
	}
	
	public static int sol(int r, int c, int n)
	{
		boolean[][] mat = new boolean[r][c];
		
	
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
			{
				if((i+j) % 2 == 0 && n > 0 && (i == 0 || i == r-1 || j == 0 || j == c-1))
				{
					mat[i][j] = true;
					n--;
				}
				
			}
		
		for(int i = 0; i < r; i++)
			for(int j = 0; j < c; j++)
			{
				if(!mat[i][j] && (i+j) % 2 == 0 && n > 0)
				{
					mat[i][j] = true;
					n--;
				}
				
			}
		
		if(n > 0)
		{
			for(int i = 0; i < r; i++)
				for(int j = 0; j < c; j++)
				{
					if(!mat[i][j] && (i == 0 || i == r-1 || j == 0 || j == c-1) && n > 0)
					{
						mat[i][j] = true;
						n--;
					}
					
				}
				
		}
		if(n > 0)
		{
			for(int i = 0; i < r; i++)
				for(int j = 0; j < c; j++)
				{
					if(!mat[i][j]  && n > 0)
					{
						mat[i][j] = true;
						n--;
					}
					
				}
				
		}
				
		return unhappy(mat, r, c);
	}
	
	public static int unhappy(boolean[][] mat, int r, int c)
	{
		int edges = 0;
		for(int i = 0; i < r; i ++)
			for(int j = 0; j < c; j++)
			{
				if(mat[i][j])
				{
					edges += ((i+1 < r) && mat[i+1][j]) ? 1 : 0;
					edges += ((j+1 < c) && mat[i][j+1]) ? 1 : 0;
				}
			}
		return edges;
	}
	
	public static void print(boolean[][] mat, int r, int c)
	{
		for(int i = 0; i < r; i++)
		{
			for(int j = 0; j < c; j++)
			{
				if(mat[i][j])
					System.out.print(1 + " ");
				else
					System.out.print("0 ");
			}
			System.out.println();
		}
	}

	public static void main(String[] args)
	{
		
		Scanner s = new Scanner(System.in);
		try {
			s = new Scanner(new FileReader("input.txt"));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			s.close();
			return;
		}
		
		Writer out = null;
		
		try {
			out = new BufferedWriter(new OutputStreamWriter(
	              new FileOutputStream("output.txt"), "utf-8"));
		}
		
		catch ( IOException e ) {
            e.printStackTrace();
        }
		
		
		
		int t = s.nextInt();
		

		for(int i = 0; i < t; i++)
		{ 	
			System.out.println("Case #" + (i+1));
			
			int r = s.nextInt(), c = s.nextInt(), n = s.nextInt();
			
			int min = Math.min(Math.min(sol(r,c,n),sol2(r,c,n)),sol3(r,c,n));
			
			for(int k = 0; k < 500000; k++)
			{
				int random = randomSol(r,c,n);
				if(random < min)
					min = random;
			}
			
			try {
				out.write("Case #"+(i+1)+": "+ min + "\n");
			}
			catch ( IOException e ) {
	            e.printStackTrace();
	        }
		}
		
		
		
		try {
		out.close();
		}
		catch ( IOException e ) {
            e.printStackTrace();
        }
		
		s.close();
		
	}
}
