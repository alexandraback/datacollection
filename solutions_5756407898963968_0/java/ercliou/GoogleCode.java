import java.io.File;
import java.io.IOException;
import java.nio.charset.Charset;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;


public class GoogleCode {
	public static void main(String[] args) throws IOException {
		long start = System.currentTimeMillis();
		String input = readFile("C:\\google\\A-small-attempt0.in", StandardCharsets.UTF_8);
		int casesAmount = getSingle(0, input);
		
		for (int i = 0 ; i < casesAmount ; i++) {
			int firstPick = getSingle(10*i + 1, input);
			int secondPick = getSingle(10*i + 6, input);
			List<Integer> firstArrangement = parseListToInteger(splitLines(10*i+2, 4, input, " "));
			List<Integer> secondArrangement = parseListToInteger(splitLines(10*i+7, 4, input, " "));
			
			List<Integer> firstRow = splitList(firstArrangement, (firstPick -1)*4, (firstPick -1)*4 + 3);
			List<Integer> secondRow = splitList(secondArrangement, (secondPick -1)*4, (secondPick -1)*4 + 3);
			
			List<Integer> intersection = intersection(firstRow, secondRow);
			
			if(intersection.size() > 1) {
				System.out.println("Case #" + (i+1) + ": Bad magician!");
			} else if (intersection.size() == 0) {
				System.out.println("Case #" + (i+1) + ": Volunteer cheated!");
			} else {
				System.out.println("Case #" + (i+1) + ": " + intersection.get(0));
			}
			
		}
		
//		System.out.println(System.currentTimeMillis() - start + " ms");
	}
	
	private static String readFile(String path, Charset encoding) throws IOException {
		byte[] encoded = Files.readAllBytes(Paths.get(path));
		return new String(encoded, encoding);
	}
	
	private static void listFiles(String path) {
		File folder = new File(path);
		File[] listOfFiles = folder.listFiles();

		    for (int i = 0; i < listOfFiles.length; i++) {
		      if (listOfFiles[i].isFile()) {
		        System.out.println("File " + listOfFiles[i].getName());
		      } else if (listOfFiles[i].isDirectory()) {
		        System.out.println("Directory " + listOfFiles[i].getName());
		      }
		    }
	}
	
	private static int getSingle(int lineIndex, String input) {
		String [] lines = input.split("\n");
		return Integer.parseInt(lines[lineIndex]);
	}
	
	private static List<String> splitLines(int from, int linesAmount, String input, String separatorRegex) {
		String [] lines = input.split("\n");
		List<String> tokens = new ArrayList<String>();
		for(int i = from; i < from + linesAmount ; i++) {
			tokens.addAll(Arrays.asList(lines[i].split(separatorRegex)));
		}
		return tokens;
	}
	
	private static List<Integer> parseListToInteger(List<String> strings) {
		List<Integer> tokens = new ArrayList<Integer>();
		for (String s : strings) {
			tokens.add(Integer.parseInt(s));
		}
		return tokens;
	}
	
	private static List<Integer> splitList(List<Integer> list, int from, int to) {
		List<Integer> result = new ArrayList<Integer>();
		for(int i = from; i <= to; i++) {
			result.add(list.get(i));
		}
		
		return result;
	}
	
	private static <T> List<T> intersection(List<T> list1, List<T> list2) {
        List<T> list = new ArrayList<T>();

        for (T t : list1) {
            if(list2.contains(t)) {
                list.add(t);
            }
        }

        return list;
    }
} 