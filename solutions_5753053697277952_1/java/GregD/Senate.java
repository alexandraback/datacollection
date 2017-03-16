/*
 * Google Code Challenge Java
 * 
 * Code written for the Google Code Challenge by Greg Dougherty
 * Created: April 17, 2015
 * 
 * Copyright 2015 by Greg Dougherty
 */

package com.google.GregTD.CodeJam2016.Round1C.Problem1;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

/**
 * @author Greg Dougherty
 *
 */
public class Senate
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
			StringBuilder	out = new StringBuilder (200);
			
			// Run each test case
			for (int i = 0; i < numCases; ++i)
			{
				line = dataReader.readLine ();
				
				int		numParties = Integer.parseInt (line);
				int[]	numMembers = new int[numParties];
				
				line = dataReader.readLine ();
				String[]	members = line.split (" ");
				for (int j = 0; j < numParties; ++j)
					numMembers[j] = Integer.parseInt (members[j]);
				
				String	outStr = getOrder (numMembers, numParties, out);
				results.delete (0, results.length ());
				results.append ("Case #");
				results.append (i + 1);
				results.append (": ");
				results.append (outStr);
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


	/**
	 * 
	 * @param numMembers
	 * @param numParties
	 * @return
	 */
	private static String getOrder (int[] numMembers, int numParties, StringBuilder out)
	{
		out.delete (0, out.length ());
		
		boolean	allGone = false;
		boolean	first = true;
		
		while (!allGone)
		{
			List<Integer>	maxPos = getBest (numMembers, numParties);
			int				numMax = maxPos.size ();
			
			if (first)
				first = false;
			else
				out.append (' ');
			
			int	which = maxPos.get (0).intValue ();
			out.append ((char) ('A' + which));
			numMembers[which] = numMembers[which] - 1;
			if ((numMax & 1) == 0)
			{
				which = maxPos.get (1).intValue ();
				out.append ((char) ('A' + which));
				numMembers[which] = numMembers[which] - 1;
			}
			
			allGone = true;
			for (int i = 0; i < numParties; ++i)
			{
				if (numMembers[i] > 0)
				{
					allGone = false;
					break;
				}
			}
		}
		
		return out.toString ();
	}


	/**
	 * 
	 * @param numMembers
	 * @return
	 */
	private static List<Integer> getBest (int[] numMembers, int numParties)
	{
		int	max = numMembers[0];
		List<Integer>	maxPos = new ArrayList<Integer> (numParties);
		
		maxPos.add (Integer.valueOf (0));
		
		for (int i = 1; i < numParties; ++i)
		{
			int	value = numMembers[i];
			if (value < max)
				continue;
			
			if (value == max)
				maxPos.add (Integer.valueOf (i));
			else
			{
				maxPos.clear ();
				maxPos.add (Integer.valueOf (i));
				max = value;
			}
		}
		
		return maxPos;
	}
	
}
