import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.StringTokenizer;

public class Main {

	public static void main(String[] args) {
		try {
			BufferedReader reader = new BufferedReader(new FileReader("input"));
			PrintWriter writer = new PrintWriter(new BufferedWriter(
					new FileWriter("output")));
			int n = Integer.valueOf(reader.readLine());
			int row;
			StringTokenizer tokenizer = null;
			HashSet<Integer> candidates = new HashSet<Integer>(4);
			ArrayList<Integer> result = new ArrayList<Integer>(4);
			String msg;
			for (int i = 0; i < n; i++) {
				candidates.clear();
				result.clear();
				msg = "Case #" + (i + 1) + ": ";
				
				row = Integer.valueOf(reader.readLine()) - 1;
				for (int j = 0; j < 4; j++) {
					if (j == row) {
						tokenizer = new StringTokenizer(reader.readLine());
						while (tokenizer.hasMoreElements()) {
							candidates.add(Integer.valueOf(tokenizer
									.nextToken()));
						}
					} else {
						reader.readLine();
					}
				}

				row = Integer.valueOf(reader.readLine()) - 1;
				for (int j = 0; j < 4; j++) {
					if (j == row) {
						tokenizer = new StringTokenizer(reader.readLine());
						while (tokenizer.hasMoreElements()) {
							int temp = Integer.valueOf(tokenizer.nextToken());
							if (candidates.contains(temp)) {
								result.add(temp);
							}
						}
					} else {
						reader.readLine();
					}
				}
				
				switch (result.size()) {
				case 0:
					msg += "Volunteer cheated!";
					break;
					
				case 1:
					msg += "" + result.get(0);					
					break;

				default:
					msg += "Bad magician!";					
					break;
				}
				
				writer.println(msg);
			}
			
			writer.close();
			reader.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

}
