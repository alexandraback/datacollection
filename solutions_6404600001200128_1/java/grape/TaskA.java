package round1a15.a;

import static util.io.SuperPrinter.*;
import util.io.InputParser;
import util.io.OutputGenerator;

public class TaskA {
	
	static final String inputFilename = "A-large.in";  // 
	
	
	static final OutputGenerator og = new OutputGenerator("src/round1a15/out/" + inputFilename.substring(0, inputFilename.length()-3) + ".out");
	static final InputParser ip = new InputParser("src/round1a15/in/" + inputFilename, og);

	
	public static void main(String[] args) {
		final int noCases = ip.i();
		
		while(true) {
			int noTimeIntervalls = ip.i();
			int[] noMushroms = ip.ia();
			assert(noMushroms.length == noTimeIntervalls);
			og.oCase(calcMethod1(noMushroms) +" " + calcMethod2(noMushroms));
		}
	}
	
	static final int calcMethod1(int[] noMushroms)  {
		int minEaten = 0;
		int prevVal = noMushroms[0];
		for(int val : noMushroms) {
			if(val < prevVal) {
				minEaten += prevVal - val;
			}
			prevVal = val;
		}
		return minEaten;
	}
	
	static final int calcMethod2(int[] noMushroms)  {
		int rate = 0;
		int prevVal = noMushroms[0];
		for(int val : noMushroms) {
			rate = Math.max(rate, prevVal-val);
			prevVal = val;
		}
//		System.out.println("\trate :" + rate);
		int minEaten = 0;
		for(int i=0; i<noMushroms.length-1; i++) {
			minEaten += Math.max(0, Math.min(rate, noMushroms[i]));
		}
		return minEaten;
	}
}