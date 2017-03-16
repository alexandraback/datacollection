import java.util.*;

public class Main1A1NEW {

	public static int GCD(int a, int b) {
		if (b==0) return a;
		return GCD(b,a%b);
	}

	public static void main(String[] args){

		Scanner in = new Scanner(System.in);

		int numCases = in.nextInt();

		for(int Case = 0; Case < numCases; Case++){

			int barbers = in.nextInt();
			long yourPosition = in.nextLong();
			int[] times = new int[barbers];
			int[] currentTimes = new int[barbers];
			long totalTime = 1;
			long customersPerBlock = 0;
			for(int i = 0; i < barbers; i++){
				times[i] = in.nextInt();
			}
			int gcdStore = times[0];
			for(int ss = 1; ss < barbers; ss++){
				gcdStore = GCD(gcdStore, times[ss]);
			}
			if(gcdStore != 1){
				for (int gc = 0; gc < barbers; gc++){
					times[gc] /= gcdStore;
				}
			}
			for(int i = 0; i < barbers; i++){
				totalTime *= times[i];
			}
			for(int i = 0; i < barbers; i++){
				customersPerBlock += (totalTime/times[i]);
			}
			if(yourPosition % customersPerBlock == 0){
				yourPosition = customersPerBlock;
			}
			else{
				yourPosition = yourPosition % customersPerBlock;	
			}
			int[] result = {0};
			for(int i = 0; i < barbers; i++){
				currentTimes[i] = times[i];
				yourPosition -= 1;
				if(yourPosition == 0){
					result[0] = (i+1);
					break;
				}
			}
			if(result[0] == 0){
				while(true){
					for(int i = 0; i < barbers; i++){
						if (currentTimes[i] == 1){
							yourPosition -= 1;
							currentTimes[i] = times[i];
						}
						else{
							currentTimes[i] -= 1;
						}
						if(yourPosition <= 0){
							result[0] = (i+1);
							break;
						}

					}

					if(result[0] != 0){
						break;
					}
				}
			}
			System.out.println("Case #" + (Case+1) + ": " + result[0]);

		}

	}

}