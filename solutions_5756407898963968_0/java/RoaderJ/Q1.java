import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;




public class Q1 {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		File file = new File("input.txt");  
		File dest = new File("output.txt");  
		BufferedReader reader = new BufferedReader(new FileReader(file));  
		BufferedWriter writer  = new BufferedWriter(new FileWriter(dest));  
		String data = reader.readLine();
		int num = Integer.parseInt(data);
		int board[][] = new int[4][4];
		int line1[] = new int[4];
		int line2[] = new int[4];
		empty(board);
		empty(line1);
		empty(line2);
		for (int t = 1; t <= num; t++) {
			writer.write("Case #"+t+": ");
			data = reader.readLine();
			int l1 = Integer.parseInt(data);
			for (int l = 0; l < 4; l++) {
				data = reader.readLine();
				String cards[] = data.split(" ");
				for (int i = 0; i < cards.length; i++) 
					board[l][i] = Integer.parseInt(cards[i]);
			}
			for (int i = 0; i < 4; i++) {
				line1[i] = board[l1-1][i];
			}
			data = reader.readLine();
			int l2 = Integer.parseInt(data);
			for (int l = 0; l < 4; l++) {
				data = reader.readLine();
				String cards[] = data.split(" ");
				for (int i = 0; i < cards.length; i++) 
					board[l][i] = Integer.parseInt(cards[i]);
			}
			for (int i = 0; i < 4; i++) {
				line2[i] = board[l2-1][i];
			}
			int target = 0;
			int flag = 3;
			
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (line1[i] == line2[j]) {
						if (flag == 1) {
							flag = 2;
						}
						if (flag == 3) {
							flag = 1;
						}
						target = line1[i];
					}
				}
			}
			if (flag == 1)
				writer.write(""+target+"\n");
			else if (flag == 2)
				writer.write("Bad magician!\n");
			else if (flag == 3)
				writer.write("Volunteer cheated!\n");
		}
		reader.close();
		writer.flush();
		writer.close();
	}
	
	public static void empty(int a[][]) {
		for (int x = 0; x < a.length; x++){
			for (int y = 0; y <a[x].length; y++){
				a[x][y] = 0;
			}
		}
	}

	public static void empty(int a[]) {
		for (int x = 0; x < a.length; x++){
				a[x] = 0;
			}
	}
}
