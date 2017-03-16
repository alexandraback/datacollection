import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class CodeJamA {

	public static void main(String[] args) throws IOException {
		Scanner input = new Scanner(new BufferedReader(new FileReader("A-large.in")));
		try {
			int testCases = input.nextInt();
			for (int i = 1; i <= testCases; i++) {
				System.out.println("Case #" + i + ": " + solveTestCase(input));
			}
		} finally {
			input.close();
		}
	}

	private static String solveTestCase(Scanner input) {
		List<PoliticalParty> politicalParties = new ArrayList<>();
		int numParties = input.nextInt();
		int totalCount = 0;
		for (char i = 0; i < numParties; i++) {
			int partyCount = input.nextInt();
			totalCount += partyCount;
			politicalParties.add(new PoliticalParty(partyCount, (char) ('A' + i)));
			
		}
		
		Collections.sort(politicalParties);
		
		String result = "";
		while (!politicalParties.isEmpty()) {
			// We get the biggest party
			PoliticalParty firstParty = politicalParties.get(0);
			result += firstParty.name;
			firstParty.congressMen--;
			totalCount--;
			
			if (firstParty.congressMen == 0) {
				politicalParties.remove(0);
			}
			if (politicalParties.isEmpty()) {
				break;
			}
			Collections.sort(politicalParties);
			PoliticalParty newFirstParty = politicalParties.get(0);
			int majority = 1 + (totalCount / 2);
			boolean shouldTakeAlsoFirstNewParty = false;
			if (newFirstParty.congressMen >= majority) {
				shouldTakeAlsoFirstNewParty = true;
			} else {
				// Would a party have the majority if we remove 1 from the new first party?
				int newMajority = 1 + (totalCount - 1) / 2;
				if (politicalParties.size() < 2 || politicalParties.get(1).congressMen < newMajority) {
					shouldTakeAlsoFirstNewParty = true;
				}
			}
			
			if (shouldTakeAlsoFirstNewParty) {
				result += newFirstParty.name;
				newFirstParty.congressMen--;
				
				if (newFirstParty.congressMen == 0) {
					politicalParties.remove(0);
				}
				totalCount--;
				Collections.sort(politicalParties);
			}
			result += " ";
			
		}
		
		
		return result;
	}

	public static class PoliticalParty implements Comparable<PoliticalParty> {
		int congressMen;
		Character name;
		
		PoliticalParty(int congressMen, Character name) {
			this.name = name;
			this.congressMen = congressMen;
		}

		@Override
		public int compareTo(PoliticalParty arg0) {
			return Integer.compare(arg0.congressMen, congressMen);
		}
		
		
	}
	
}
