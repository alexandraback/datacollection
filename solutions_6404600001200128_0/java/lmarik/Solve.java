package MushroomMonster20151A;

public class Solve {
	
	public static String solveMushroomMonster(MushroomMonster h) {
		String solutionStr = null;
		
		//first, solve for she eats at variable rate
		int minMushroomsA = 0;
		int previousCount = -1;
		for (Integer c: h.getMushroomCounts()) {
			if (previousCount != -1 && c < previousCount) {
				minMushroomsA += (previousCount-c);
			}
			previousCount = c;
		}
		
		//next, solve for she eats at constant rate (figure out what minimum rate would be)
		int minMushroomsB = 0;
		int minRate = 0;
		previousCount = -1;
		for (Integer c: h.getMushroomCounts()) {
			if (previousCount != -1 && c < previousCount && minRate < previousCount-c) {
				minRate = (previousCount-c);
			}
			previousCount = c;
		}
		//of course, she only eats at the min rate if they're available
		previousCount = -1;
		for (Integer c:h.getMushroomCounts()) {
			if (previousCount != -1) {
				if (previousCount < minRate)
					minMushroomsB += (previousCount);
				else
					minMushroomsB += minRate;
			}
			previousCount = c;		
		}
		
		solutionStr = Integer.toString(minMushroomsA) + " " + Integer.toString(minMushroomsB);
		return solutionStr;
	}

}
