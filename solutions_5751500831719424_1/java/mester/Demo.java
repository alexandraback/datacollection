import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class Demo {

	public static void main(String[] args) throws FileNotFoundException {

		Scanner scanner = new Scanner(new File("D:\\DEV\\Eclipse\\workspace_11.04.2014\\Question1\\src\\input.txt"));

		// eat T
		scanner.next();
		
		int curCaseNo = 1;
		while (scanner.hasNext()) {
			int N = scanner.nextInt();
			
			String[] strArr = new String[N];
			for ( int i = 0; i < N; i++ ) {
				strArr[i] = scanner.next();
			}
			
			List<String> strList = Arrays.asList(strArr);
			int result = findResult(strList);
			
			System.out.println("Case #" + curCaseNo + ": " + (result < 0 ? "Fegla Won" : result));
			
			curCaseNo++;
		}

	}

	private static int findResult(List<String> strList) {
		if ( strList.size() == 1 ) {
			return 0;
		}
		
		List<Character> commonCharList = null;
		
		List<List<Integer>> numListList = new ArrayList<List<Integer>>();
		
		for ( String str : strList) {
			char[] charArray = str.toCharArray();

			List<Integer> numList = new ArrayList<Integer>();
			List<Character> characterList = new ArrayList<Character>();

			Character lastChar = null;
			for ( int i = 0; i < charArray.length; i++ ) {
				if ( lastChar == null ) {
					lastChar = charArray[i];
					numList.add(1);
					characterList.add(lastChar);
				} else {
					if ( lastChar.charValue() == charArray[i] ) {
						int myNum = numList.get(numList.size() - 1);
						numList.set(numList.size() - 1, myNum + 1);
					} else {
						lastChar = charArray[i];
						numList.add(1);
						characterList.add(lastChar);
					}
				}
			}
			
			if ( commonCharList == null ) {
				commonCharList = new ArrayList<Character>();
				commonCharList.addAll(characterList);
			} else {
				if ( commonCharList.equals(characterList) == false ) {
					return -1;
				}
			}
			
			numListList.add(numList);			
		}

		int total = 0;
		for ( int i = 0; i < numListList.get(0).size(); i++ ) {
			
			List<Integer> myList = new ArrayList<Integer>();
			for ( int j = 0; j < numListList.size(); j++ ) {
				myList.add(numListList.get(j).get(i));
			}

			int minMoves = findMinMoves(myList);
			total += minMoves;
		}
		
		return total;
	}
	
	private static int findMinMoves(List<Integer> numList) {
		
		int min = Integer.MAX_VALUE;
		HashSet<Integer> hs = new HashSet<Integer>();
		hs.addAll(numList);
		
		if ( hs.size() <= 1 ) {
			return 0;
		}
		
		Iterator<Integer> it = hs.iterator();
		while (it.hasNext()) {
			int num = it.next();
			int movesForNum = findMovesForNum(numList, num);
			if ( movesForNum < min ) {
				min = movesForNum;
			}
		}
		
		return min;
	}
	
	private static int findMovesForNum(List<Integer> numList, int num) {
		
		Iterator<Integer> it = numList.iterator();

		int sum = 0;
		while (it.hasNext()) {
			int cur = it.next();
			sum += ((num - cur) > 0 ? (num -cur) : (cur-num));
		}
			
		return sum;
	}

}
