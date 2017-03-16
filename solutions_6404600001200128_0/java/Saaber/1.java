import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;






public class InfHousePancake {

	public static void main(String[] args) throws IOException{
		
		String filePath = "C:/codeJam/secondRound/1/";
		BufferedReader buffer = new BufferedReader(new FileReader(filePath+"attempt.in"));
		
		String line = buffer.readLine();
		
		int numOfCase = 1;
		StringBuilder sb = new StringBuilder();
		while (buffer.readLine() != null) {
			line = buffer.readLine();
			
			String[] cabs = line.split(" ");
			int resCase1 = caseOne(cabs);
			int resCase2 = caseTwo(cabs);
			sb.append("Case #"+numOfCase+": "+resCase1+" "+resCase2);
			sb.append(System.lineSeparator());
			numOfCase++;
			
		}
		File file = new File(filePath+"res.out");
        BufferedWriter output = new BufferedWriter(new FileWriter(file));
        output.write(sb.toString());
        output.close();
	}

	private static int caseOne(String[] cabs) {
		int sum = 0;
		for(int i = 1 ; i < cabs.length ; i++){
			if(Integer.parseInt(cabs[i]) < Integer.parseInt(cabs[i-1]))
				sum += Integer.parseInt(cabs[i-1]) - Integer.parseInt(cabs[i]) ;
		}
		return sum;
	}
	
	private static int caseTwo(String[] cabs) {
		int sum = 0;
		int maxDif = 0;
		for(int i = 1 ; i < cabs.length ; i++){
			
			if(Integer.parseInt(cabs[i-1]) - Integer.parseInt(cabs[i]) > maxDif)
				maxDif= Integer.parseInt(cabs[i-1]) - Integer.parseInt(cabs[i]);
		}
		for(int i = 0 ; i < cabs.length-1 ; i++){
			if(Integer.parseInt(cabs[i]) > maxDif)
				sum += maxDif;
			else 
				sum += Integer.parseInt(cabs[i]);
		}
		return sum;
	}

}
