/*
 * Google Code Challenge Java
 * 
 * Code written for the Google Code Challenge by Greg Dougherty
 * Created: April 17, 2015
 * 
 * Copyright 2015 by Greg Dougherty
 */

package com.google.GregTD.CodeJam2015.Round1A.Problem1;

import java.io.*;

/**
 * @author Greg Dougherty
 *
 */
public class Shrooms
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
				int	intervals = Integer.parseInt (line);
				
				line = dataReader.readLine ();
				String[]	values = line.split (" ");
				int[]		counts = new int[intervals];
				int[]		eatAmounts = new int[intervals];
				int			answer1 = 0;
				int			answer2 = 0;
				int			maxEat = 0;
				
				for (int j = 0; j < intervals; ++j)
					counts[j] = Integer.parseInt (values[j]);
				
				for (int j = 1; j < intervals; ++j)
					answer1 += eatAmounts[j] = Math.max (0, counts[j - 1] - counts[j]);
				
				for (int j = 1; j < intervals; ++j)
					maxEat = Math.max (maxEat, eatAmounts[j]);
				
				--intervals;
				for (int j = 0; j < intervals; ++j)
					answer2 += Math.min (maxEat, counts[j]);
				
				results.delete (0, results.length ());
				results.append ("Case #");
				results.append (i + 1);
				results.append (": ");
				results.append (answer1);
				results.append (' ');
				results.append (answer2);
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
	
}
