package Haircut20151A;

public class Solve {
	
	public static String solveHaircut(Haircut h) {
		String solutionStr = null;
		
		//speed calculations up a lot
		int LCM = h.getLeastCommonMultiple();
		int num = h.getNumPatronsInLCM(LCM);
		
		int numPatronsRemaining = h.getPositionInLine();
		if (numPatronsRemaining > num) {
			numPatronsRemaining = numPatronsRemaining%num;
		}
		if (numPatronsRemaining == 0)
			numPatronsRemaining = num;
		
		int time = 0;
		while (numPatronsRemaining > 0) {
			
			for (Barber b: h.getBarbers()) {
				//first, update any barbers that are done
				if (b.getFinishTime() == time)
				{
					b.setFinishTime(-1);
					
				}
				//then assign patrons to barbers
				if (b.getFinishTime() == -1)
				{
					numPatronsRemaining--;
					if (numPatronsRemaining == 0) //my turn!!!
						return b.toString();
					b.setFinishTime(time+b.getHaircutSpeed());
				}
			}
			
			//then increment time
			time++;
		}
		return solutionStr;
	}

}
