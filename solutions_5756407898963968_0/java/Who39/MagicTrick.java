import java.util.*;
import java.io.*;

public class MagicTrick implements Solution {
	private static final Map<String, Calculator> cache = new HashMap<String, Calculator>();
	
	public Datum execute(final BufferedReader input) throws IOException{
		Input datum = new Input(input);
		System.out.println(datum);
		return datum.result();
	}
	
	private static class Output implements Solution.Datum {
		private final String output;
		public Output(String output){
			this.output = output;
		}

		
		public List<String> getLines(){
			List<String> result = new ArrayList<String>();
			result.add(output);
			return result;
		}
	}
	
	private static class Input implements Solution.Datum {
		private int firstRowSelection;
		private final int secondRowSelection;
		private int[][] firstCardOrder;
		private int[][] secondCardOrder;
		private final int hash;
		
		public Input(final BufferedReader input)throws IOException{
			int hash = 31;
			firstRowSelection = getRowSelection(input);
			hash = hash * 31 + firstRowSelection;
			firstCardOrder = getCardArray(input);
			hash = hash * 31 + computeHash(firstCardOrder);
			secondRowSelection = getRowSelection(input);
			hash = hash * 31 + secondRowSelection;
			secondCardOrder = getCardArray(input);
			hash = hash * 31 + computeHash(secondCardOrder);
			this.hash = hash;
		}
		
		private static int getRowSelection(final BufferedReader input)throws IOException{
			if(input.ready()) return Integer.parseInt(input.readLine());
			else throw new IllegalArgumentException("cannot find row selection");
		}
		
		private static int[][] getCardArray(final BufferedReader input)throws IOException{
			int[][] result = new int[4][4];
			for(int i = 0; i < 4; i++){
				if(input.ready()){
					String[] value = input.readLine().split("\\s+");
					if(value.length != 4) throw new IllegalArgumentException("bad card array");
					for(int j = 0; j< 4; j++) result[i][j] = Integer.parseInt(value[j]);
				}
			}
			return result;
		}
		
		private Set<Integer> getFirstCardOrderRow(){
			Set<Integer> result = new HashSet<Integer>();
			for(int i = 0; i < 4; i++) result.add(firstCardOrder[firstRowSelection-1][i]);
			return result;
		}
		
		private Set<Integer> getSecondCardOrderRow(){
			Set<Integer> result = new HashSet<Integer>();
			for(int i = 0; i < 4; i++) result.add(secondCardOrder[secondRowSelection-1][i]);
			return result;
		}
		
		public Output result(){
			Set<Integer> firstRow = getFirstCardOrderRow();
			firstRow.retainAll(getSecondCardOrderRow());
			if(firstRow.isEmpty()) return new Output("Volunteer cheated!");
			else if(firstRow.size() != 1) return new Output("Bad magician!");
			for(Integer val : firstRow) return new Output(Integer.toString(val));
			return null;
		}
		
		private static int computeHash(int[][] map){
			int hash = 31;
			for(int i = 0; i < map.length; i++){
				for(int j = 0; j < map[i].length; j++){
					hash = hash * 31 + map[i][j]; 
				}
			}
			return hash;
		}
		
		@Override
		public String toString(){
			StringBuilder builder = new StringBuilder();
			for(String line : getLines()) builder.append(line).append("\n");
			return builder.toString();
		}
		
		private String mapToString(int[][] map){
			StringBuilder builder = new StringBuilder();
			for(int i = 0; i < 4; i++){
				for(int j = 0; j<4; j++) builder.append(map[i][j]).append(" ");
				builder.append("\n");
			}
			return builder.toString();
		}
		
		public List<String> getLines(){
			List<String> result = new ArrayList<String>();
			result.add(Integer.toString(firstRowSelection));
			result.add(mapToString(firstCardOrder));
			result.add(Integer.toString(secondRowSelection));
			result.add(mapToString(secondCardOrder));
			return result;
		}
	}
}