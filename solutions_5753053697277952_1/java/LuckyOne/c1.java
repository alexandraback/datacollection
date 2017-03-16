import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;

public class c1 {

	static String fileName = "E:/tmp/codeJam2016/c1/input_test.txt";
	static String outFileName = "E:/tmp/codeJam2016/c1/output.txt";
	
	public static void main(String[] args) throws FileNotFoundException, IOException {
		// TODO Auto-generated method stub

		try (BufferedReader br = new BufferedReader(new FileReader(fileName))) {
			BufferedWriter bw = new BufferedWriter(new FileWriter(outFileName));
			String line;

			line = br.readLine();
			int testCases = Integer.parseInt(line);
			int caseCounter = 1;
			
			// ---------
			while ((line = br.readLine()) != null) {
				int parties = Integer.parseInt(line);
				int[] senators = new int[parties];
				String inputLine = br.readLine();
				int i = 0;
				for(String s : inputLine.split(" ")){
					senators[i++] = Integer.parseInt(s);
				}
				String result = solve(senators);
				System.out.println("Case #" + caseCounter + ": " + result);
				bw.write("Case #" + caseCounter + ": " + result + "\n");
				
				caseCounter++;
			}
			
			// ---------
			
			bw.close();
		}
	}

	
	public static String solve(int[] senators) {
		StringBuilder sb = new StringBuilder();
		int numberOfSenators = 0;
		for(int i : senators) numberOfSenators += i;
		
		while(numberOfSenators != 0){
			int index = 0;
			int max = 0;
			for(int i = 0; i < senators.length - 1; i++){
				if(senators[i] > max){
					index = i;
					max = senators[i];
				}
			}
			
			int second = valid(senators, index, numberOfSenators);
			if(second == -1){
				numberOfSenators--;
				senators[index]--;
				sb.append((char)(index + 65));
				sb.append(" ");
			}else{
				numberOfSenators = numberOfSenators - 2;
				senators[index]--;
				senators[second]--;
				sb.append((char)(index + 65));
				sb.append((char)(second + 65));
				sb.append(" ");
			}
		}
		return sb.toString().trim();
	}
	
	public static int valid(int[] senators, int first, int number){
		int max = (number - 1) / 2;
		for(int i = 0; i < senators.length; i++){
			if(i == first){
				if((senators[i] - 1) > max) return i;
			}else{
				if(senators[i] > max) return i;
			}
		}
		return -1;
	}

}
