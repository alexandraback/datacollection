import java.util.*;

class p1
{
	private static final int NUMBERS_IN_ROW = 4;
	
	public static void main (String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int testCases = sc.nextInt();
		for(int i=0; i<testCases; i++){
			List<Integer> firstRow = new ArrayList<Integer>();
			List<Integer> secondRow = new ArrayList<Integer>();
			int firstRowNumber = sc.nextInt();
			for(int j=0; j<firstRowNumber-1; j++){
				for(int k=0; k<NUMBERS_IN_ROW; k++){
					sc.nextInt();
				}
			}
			for(int j=0; j<NUMBERS_IN_ROW; j++){
				firstRow.add(sc.nextInt());
			}
			for(int j=firstRowNumber; j<NUMBERS_IN_ROW; j++){
				for(int k=0; k<NUMBERS_IN_ROW; k++){
					sc.nextInt();
				}
			}

			int secondRowNumber = sc.nextInt();
			for(int j=0; j<secondRowNumber-1; j++){
				for(int k=0; k<NUMBERS_IN_ROW; k++){
					sc.nextInt();
				}
			}
			for(int j=0; j<NUMBERS_IN_ROW; j++){
				secondRow.add(sc.nextInt());
			}
			for(int j=secondRowNumber; j<NUMBERS_IN_ROW; j++){
				for(int k=0; k<NUMBERS_IN_ROW; k++){
					sc.nextInt();
				}
			}
			
			System.out.print("Case #"+(i+1)+": ");
			System.out.println(getCompareRowsResult(firstRow,secondRow));
		}
	}
	
	public static String getCompareRowsResult(List<Integer> a, List<Integer> b){
		Set<Integer> s1 = new HashSet<Integer>(a);
		Set<Integer> s2 = new HashSet<Integer>(b);
		s1.retainAll(s2);

		if(s1.size() == 0){
			return "Volunteer cheated!";
		}
		else
		if(s1.size() == 1){
			return s1.iterator().next().toString();
		}
		else{
			return "Bad magician!";
		}
	}
}
