import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.OutputStreamWriter;
import java.io.Writer;
import java.math.BigDecimal;
import java.util.Arrays;
import java.util.Scanner;


public class Logging {
	
	public static int sol(BigDecimal[][] angle, int n, int c)
	{
		
		BigDecimal[] cAngles = new BigDecimal[n];
		
		BigDecimal tbigPI = new BigDecimal(2*Math.PI);
		
		int u = 0;
		for(int i = 0; i < n+1; i++)
		{
			if(i != c)
			{
				cAngles[u] = angle[c][i];
				if(cAngles[u].compareTo(new BigDecimal(0)) < 0)
					cAngles[u].add(tbigPI);
				u++;
			}
				
		}
		
		Arrays.sort(cAngles);
		
		BigDecimal[] angles = new BigDecimal[2*n];
		for(int i = 0; i < n; i++)
		{
			angles[i] = cAngles[i];
			angles[n+i] =  cAngles[i].add(tbigPI);
		}
		
		int tdMin = n;
		/*
		for(int i = 0; i < 2*n; i++)
			System.out.print(angles[i]+ " ");
		System.out.println();
		*/
		for(int i = 0; i < n; i++)
		{
			int k = i+1, td = 0;
			BigDecimal sup = angles[i].add(new BigDecimal(Math.PI));
			while(angles[k].compareTo(sup) < 0)
			{
				k++;
				td++;
			}
			if(td < tdMin)
				tdMin = td;
		}
		
		return tdMin;
		
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
		

		
		int n;
		
		BigDecimal bigPI = new BigDecimal(Math.PI);
		
		for(int i = 0; i < t; i++)
		{ 	
			System.out.println("Case #" + (i+1)+":");
			
			n = s.nextInt();
			
			int[] x = new int[n];
			int[] y = new int[n];
			
			for(int j = 0; j < n; j++)
			{
				x[j] = s.nextInt();
				y[j] = s.nextInt();
			}
			
			BigDecimal[][] angle = new BigDecimal[n][n];
			
			for(int k = 0; k < n; k++)
			{
				angle[k][k] = new BigDecimal(0.0);

				for(int j = k+1; j < n; j++)
				{
					if(x[k] == x[j])
					{
						if(y[k] < y[j])
							angle[k][j] = new BigDecimal(Math.PI/2);
						else
							angle[k][j] = new BigDecimal(-Math.PI/2);
					}
					else
					{
						angle[k][j] = new BigDecimal(Math.atan((y[j]-y[k])/(x[j]-x[k])));
						
						if(x[k] > x[j])
							angle[k][j] = angle[k][j].add(bigPI);
					}
					
					angle[j][k] = angle[k][j].add(bigPI);
				}
				
			}

			try {
				out.write("Case #"+(i+1)+":\n");
				for(int j = 0; j < n; j++)
					out.write(sol(angle,n-1,j)+"\n");
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
