import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class A {
	
	static int[] getAnswers(BufferedReader br) throws IOException{
		String line = br.readLine();
		int answer = Integer.parseInt(line);
		for(int j = 1; j <= 4; j++)
			if(j == answer)
				line = br.readLine();
			else
				br.readLine();
		String[] split = line.split("\\s+");
		int[] answers = new int[4];
		for(int j = 0; j < 4; j++)
			answers[j] = Integer.parseInt(split[j]);
		return answers;
	}

	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line = br.readLine();
		int tests = Integer.parseInt(line);
		for(int i = 1; i <= tests; i++){
			int[] ans1 = getAnswers(br);
			int[] ans2 = getAnswers(br);
			ArrayList<Integer> matches = new ArrayList<Integer>();
			for(int j = 0; j < 4; j++)
				for(int k = 0; k < 4; k++)
					if(ans1[j] == ans2[k])
						matches.add(ans1[j]);
			System.out.print("Case #" + i + ": ");
			switch(matches.size()){
			case 0:
				System.out.println("Volunteer cheated!");
				break;
			case 1:
				System.out.println(matches.get(0));
				break;
			default:
				System.out.println("Bad magician!");
				break;
			}
		}
	}
}
