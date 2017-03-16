import java.util.Scanner;


public class MagicTrick {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cards1[][] = new int[4][4];
		int cards2[][] = new int[4][4];
		int guess1, guess2, poss;
		
		int numCases = in.nextInt();
		int casen;
		for(casen = 1 ; numCases > 0; numCases--, casen++){
			cards1 = new int[4][4];
			cards2 = new int[4][4];
			guess1 = in.nextInt() -1;
			poss = -1;
			for(int i = 0; i < 4; i++){
				for(int j = 0; j < 4; j++){
					cards1[i][j] = in.nextInt();
				}
			}
			
			guess2 = in.nextInt() -1;
			for(int i = 0; i < 4; i++){
				for(int j = 0; j < 4; j++){
					cards2[i][j] = in.nextInt();
				}
			}
			
			for(int i = 0; i < 4; i++){
				for(int j = 0; j < 4; j++){
					if(cards1[guess1][i] == cards2[guess2][j]){
						if(poss == -1){
							poss = cards1[guess1][i];
						}else{
							//bad magician..
							poss = -2;
						}
					}
				}
			}
			
			System.out.print("Case #"+casen+": ");
			
			if(poss == -2){
				System.out.println("Bad magician!");
			}else if(poss == -1){
				System.out.println("Volunteer cheated!");
			}else{
				System.out.println(poss);
			}
		}
	}

}
