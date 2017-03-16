package roundc;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class SenateEvacuation {
	
	private static char[] alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ".toCharArray();

	public static void main(String[] args) throws IOException {
		new SenateEvacuation(args[0]);
	}

	public SenateEvacuation(String fileName) throws IOException {
		List<String> lines = Files.readAllLines(Paths.get(fileName + ".in"), Charset.defaultCharset());
		FileOutputStream output = new FileOutputStream(new File(fileName + ".out"));
		int cases = 1;
		int i = 1;
		while (i < lines.size()) {
			String line = lines.get(i);
			int parties = Integer.parseInt(line);
			List<Integer> members = new ArrayList<Integer>();
			i++;
			line = lines.get(i);
			String[] membersArray = line.split(" ");
			int sumOfMembers = 0;
			for (int j = 0; j < membersArray.length; j++) {
				int membersOfParty = Integer.parseInt(membersArray[j]);
				members.add(membersOfParty);
				sumOfMembers += membersOfParty;
			}
			String result = "Case #" + cases + ": " + solve(members, sumOfMembers) + "\n";
			//System.out.print(result);
			output.write(result.getBytes());
			cases++;
			i++;
		}
		output.close();
	}

	private String solve(List<Integer> members, int sum) {
		String result = "";
		while (sum > 0) {
			for (int i = 0; i < members.size(); i++) {
				if (members.get(i) > 0) {
					String separator = "";
					if (result.length() > 1 && result.charAt(1) != ' ') {
						separator = " ";
					}
					result = alphabet[i] + separator + result;
					members.set(i, members.get(i)-1);
					sum--;
				}
			}
		}
		return result;
	}
}
