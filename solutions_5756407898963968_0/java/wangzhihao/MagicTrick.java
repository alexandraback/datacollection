import java.io.*;
import java.util.*;

class Cards{
	public static final int size = 4;

	public Cards(){
		board = new int[size][size];
	}

	public int row;

	public int [][] board;

	public void input(Scanner sc){
		row = sc.nextInt();
		for(int i = 0; i < size; i++){
			for(int j = 0; j < size; j++){
				board[i][j] = sc.nextInt();
			}
		}
	}

	public int getCard(int column){
		return board[row - 1][column - 1];
	}

}

public class MagicTrick{
	public static void main(String[] args) throws Exception {
		//Scanner sc = new Scanner(System.in);
		//Scanner sc = new Scanner(new File("./sample.txt"));
		Scanner sc = new Scanner(new File("./small.txt"));
		//Scanner sc = new Scanner(new File("./large.txt"));
		int T = sc.nextInt();
		for (int i = 1; i <= T; i++ ){
			System.out.print("Case #"+ i + ": ");
			Cards one = new Cards();
			Cards two = new Cards();
			one.input(sc);
			two.input(sc);
			int count = 0, card = 0;
			for(int x = 1; x <= one.size; x++){
				boolean match = false;
				for(int y = 1; y <= two.size; y++){
					if(two.getCard(y) == one.getCard(x)){
						match = true;
					}
				}
				if(match){
					count++;
					card = one.getCard(x);
				}
			}
			switch(count){
				case 0:
					System.out.println("Volunteer cheated!");
				break;
				case 1:
					System.out.println(card);
				break;
				default:
					System.out.println("Bad magician!");
			}
		}		
	}
}