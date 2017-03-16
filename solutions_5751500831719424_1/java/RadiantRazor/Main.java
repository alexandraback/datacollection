package ramanvesh.codejam.theRepeater;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;

public class Main {
	
	public static void main(String[] args) {
		String path = System.getProperty("user.dir");
		try{
			@SuppressWarnings("resource")
			BufferedReader fileReader = new BufferedReader(new FileReader(new File(path + "/input" )));
			int noOfCases = Integer.parseInt(fileReader.readLine().trim());
			for(int caseNum =1; caseNum<=noOfCases; caseNum++){
				int numOfStrings = Integer.parseInt(fileReader.readLine().trim());
				List<String> strings = new ArrayList<String>(numOfStrings);
				for(int stringNum = 0; stringNum< numOfStrings; stringNum++){
					strings.add(fileReader.readLine());
				}
				int[] markers = new int[numOfStrings];
				boolean impossible = false;
				int minSteps = 0;
				while(!impossible){
					boolean[] broken = new boolean[numOfStrings];
					int[] length = new int[numOfStrings];
					char currentChar = (char)0;
					for (int i = 0; !checkIfAllTrue(broken) && checkIfMarkersInLimit(markers,strings); i = (i+1)%numOfStrings) {
						if(broken[i]){
							continue;
						}
						String string = strings.get(i);
						if(markers[i] >=  string.length()){
							broken[i]=true;
							continue;
						}
						char thisChar = string.charAt(markers[i]);
						if(currentChar == (char)0){
							currentChar = thisChar;
						} 
						if(currentChar != thisChar){
							broken[i] = true;
						} else {
							length[i]++;
							markers[i]++;
						}
					}
					int minStepsToReachCommonNumber = getMinStepsToReachCommonNumber(length);
					if(minStepsToReachCommonNumber < 0){
						impossible = true;
					} else{
						minSteps += minStepsToReachCommonNumber;
					}
					if(!checkIfMarkersInLimit(markers, strings)){
						break;
					}
				}
				System.out.println("Case #"+caseNum+": "+(impossible? "Fegla Won" : minSteps));
			}
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	private static boolean checkIfMarkersInLimit(int[] markers,List<String> strings) {
		for(int i =0; i< strings.size(); i++){
			if(markers[i] < strings.get(i).length()){
				return true;
			}
		}
		return false;
	}

	private static int getMinStepsToReachCommonNumber(int[] length) {
		int minSteps = Integer.MAX_VALUE;
		for(int i = 0; i < length.length; i++){
			int thisSteps = 0;
			if(length[i] == 0){
				return -1;
			}
			for(int j =0; j< length.length; j++){
				thisSteps += Math.abs(length[i] - length[j]);
			}
			minSteps = Math.min(minSteps, thisSteps);
		}
		return minSteps;
	}

	private static boolean checkIfAllTrue(boolean[] broken) {
		for (boolean b : broken) {
			if(!b){
				return false;
			}
		}
		return true;
	}
}