/*
 * Google Code Challenge Java
 * 
 * Code written for the Google Code Challenge by Greg Dougherty
 * Created: April 17, 2015
 * 
 * Copyright 2015 by Greg Dougherty
 */

package com.google.GregTD.CodeJam2015.Round1A.Problem2;

import java.io.*;

/**
 * @author Greg Dougherty
 *
 */
public class Haircut
{
	
	private static final String	kInSuffix = ".in";
	private static final String	kOutSuffix = ".out";
	
	
	/**
	 * @param args
 	 */
	public static void main (String[] args)
	{
		String	inName = args[0];
		int		nameLen = inName.indexOf (kInSuffix);
		String	outName = inName.substring (0, nameLen) + kOutSuffix;
		File	dataFile = new File (args[0]);
		File	resultFile = new File (outName);
		
		try
		{
			BufferedReader	dataReader = new BufferedReader (new FileReader (dataFile));
			BufferedWriter	dataWriter = new BufferedWriter (new FileWriter (resultFile));
			String			line = dataReader.readLine ();	// Get first line
			int				numCases = Integer.parseInt (line);
			StringBuilder	results = new StringBuilder (200);
			
			// Run each test case
			for (int i = 0; i < numCases; ++i)
			{
				line = dataReader.readLine ();
				String[]	values = line.split (" ");
				
				int		numBarbers = Integer.parseInt (values[0]);
				int		myPlace = Integer.parseInt (values[1]);
				int[]	times = new int[numBarbers];
				int[]	timeToDone = new int[numBarbers];
				int		myBarber = 0;
				
				line = dataReader.readLine ();
				values = line.split (" ");
				for (int j = 0; j < numBarbers; ++j)
					times[j] = Integer.parseInt (values[j]);
				
				int	leastCommonMultiple = lcm (times);
				int	doneInLCM = 0;
				
				for (int j = 0; j < numBarbers; ++j)
					doneInLCM += (leastCommonMultiple / times[j]);
				
				myPlace = myPlace % doneInLCM;
				if (myPlace == 0)
					myPlace = doneInLCM;
				while (myPlace > 0)
				{
					int	minTime = 25;
					for (int j = 0; j < numBarbers; ++j)
						minTime = Math.min (minTime, timeToDone[j]);
					if (minTime > 0)
					{
						for (int j = 0; j < numBarbers; ++j)
							timeToDone[j] -= minTime;
					}
					for (int j = 0; j < numBarbers; ++j)
					{
						if (timeToDone[j] == 0)
						{
							timeToDone[j] = times[j] - 1;
							--myPlace;
							if (myPlace == 0)
							{
								myBarber = j + 1;
								break;
							}
						}
						else
							--timeToDone[j];
					}
				}
				
				results.delete (0, results.length ());
				results.append ("Case #");
				results.append (i + 1);
				results.append (": ");
				results.append (myBarber);
				dataWriter.write (results.toString ());
				dataWriter.newLine ();
				dataWriter.flush ();
				System.out.println (results.toString ());
			}
			
			dataReader.close ();
			dataWriter.close ();
		}
		catch (IOException ioE)
		{
			ioE.printStackTrace ();
		}
	}
	
	private static int gcd (int a, int b)
	{
	    while (b > 0)
	    {
	    	int temp = b;
	        b = a % b; // % is remainder
	        a = temp;
	    }
	    return a;
	}
	
	private static int lcm (int a, int b)
	{
	    return a * (b / gcd (a, b));
	}

	private static int lcm (int[] input)
	{
		int result = input[0];
		for (int i = 1; i < input.length; i++)
			result = lcm (result, input[i]);
		return result;
	}
}
