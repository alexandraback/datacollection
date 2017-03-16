import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class MagicTrick {
	
	private List<Integer> rowA = new ArrayList<Integer>();
	private List<Integer> rowB = new ArrayList<Integer>();
	
	public MagicTrick(int cardRowA, int[][] gridA, int cardRowB, int[][] gridB) {
		for(int i = 0; i < gridA[cardRowA].length; i++) {
			rowA.add(gridA[cardRowA][i]);
		}
		for(int i = 0; i < gridB[cardRowB].length; i++) {
			rowB.add(gridB[cardRowB][i]);
		}
		
		//System.out.println(rowA);
		//System.out.println(rowB);
	}
	

	public MagicTrickResult solve() {		
		//Cards that appear in both rows
		boolean[] matchedCards = new boolean[rowA.size()];
		int trues = 0;
		int falses = 0;
		for(int i = 0; i < rowA.size(); i++) {
			matchedCards[i] = rowB.contains(rowA.get(i));
			if(matchedCards[i]) {
				trues++;
			} else {
				falses++;
			}
		}
		
		//Case 1: Volunteer cheated
		if(falses == rowA.size()) {
			return new MagicTrickResult(MagicTrickResult.Type.VOLUNTEER_CHEATED, -1);
		}
		
		//Case 2: Magician sucks
		if(trues > 1) {
			return new MagicTrickResult(MagicTrickResult.Type.BAD_MAGICIAN, -1);
		}
		
		for(int i = 0; i < rowA.size(); i++) {
			if(matchedCards[i]) return new MagicTrickResult(MagicTrickResult.Type.SINGLE_RESULT, rowA.get(i));
		}
		return null;
	}


	private static class MagicTrickResult {
		enum Type {
			SINGLE_RESULT,
			BAD_MAGICIAN,
			VOLUNTEER_CHEATED
		}
		
		Type type;
		int card;
		
		public MagicTrickResult(Type type, int card) {
			super();
			this.type = type;
			this.card = card;
		}
	}


	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner(new FileReader("magic_trick.txt"));
		
		int tests = scanner.nextInt();
		for(int i = 1; i <= tests; i++) {
			int rowA = scanner.nextInt() - 1;
			int[][] gridA = new int[4][4];
			for(int row = 0; row < 4; row++) {
				for(int col = 0; col < 4; col++) {
					gridA[row][col] = scanner.nextInt();
				}
			}
			int rowB = scanner.nextInt() - 1;
			int[][] gridB = new int[4][4];
			for(int row = 0; row < 4; row++) {
				for(int col = 0; col < 4; col++) {
					gridB[row][col] = scanner.nextInt();
				}
			}
			
			MagicTrick trick = new MagicTrick(rowA, gridA, rowB, gridB);
			MagicTrickResult result = trick.solve();
			
			if(result.type == MagicTrickResult.Type.SINGLE_RESULT) {
				System.out.println("Case #" + i + ": " + result.card);
			} else if(result.type == MagicTrickResult.Type.BAD_MAGICIAN) {
				System.out.println("Case #" + i + ": Bad magician!");
			} else if(result.type == MagicTrickResult.Type.VOLUNTEER_CHEATED) {
				System.out.println("Case #" + i + ": Volunteer cheated!");
			}
			
		}
		
		scanner.close();
		
		System.exit(0);
	}

}
