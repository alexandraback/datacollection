package problems;

import java.util.HashMap;

import io.FrontJam;

public class GoogJam1 {
	FrontJam problemSet;
	
	int firstCall = 0;
	int secondCall = 0;
	
	int firstSet[][] = new int[4][4];
	int secondSet[][] = new int[4][4];
	
	HashMap collision = new HashMap();
	
	
	public GoogJam1(){
		problemSet = new FrontJam("C:\\Users\\M\\Downloads\\A-small-practice (3).in", 10);

	}

	
	public GoogJam1(String file){
		problemSet = new FrontJam(file, 10);
	}
	
	public void closeProblems(){
		problemSet.closeFileOut();
	}
	
	public void solveSet(){
		for(int i = 0; i <problemSet.getNumberOfCases();i++){
			loadNextProblem();
			String answer = solve();
			problemSet.answerCurrentProblem(""+answer);
		}
		problemSet.closeFileOut();
	}
	
	public String solve(){
		
		int rowCall = firstCall - 1;
		//first row into collision
		for(int i = 0 ; i < 4; i++){
			int num = firstSet[rowCall][i];
			collision.put(num, 1);
		}
		
		
		//now check for collisions
		rowCall = secondCall - 1;
		int count = 0;
		int answer = -1;
		for(int i = 0; i < 4; i++){
			int num = secondSet[rowCall][i];
			if(collision.containsKey(num)){
				count ++;
				answer = num;
			}
		}
		
		if(count > 1){
			return "Bad magician!";
		}
		else if( count == 1){
			return answer + "";
		}
		else{
			return "Volunteer cheated!";
		}
		
		
	}
	
	public void loadNextProblem(){
		collision = new HashMap();
		String prob = problemSet.getNextProblem();
		String splitSetRows[] = prob.split("\n");
		//row 1 is first call
		firstCall = Integer.parseInt(splitSetRows[0]);
		
		//next four rows and first card placement
		for(int i = 0; i < 4; i ++){
			String splitCards[] = splitSetRows[1+i].split(" ");
			for(int j = 0; j < 4; j ++){
				firstSet[i][j] = Integer.parseInt(splitCards[j]);
			}
		}
		
		//row 6 is second call
		secondCall = Integer.parseInt(splitSetRows[5]);
		 
		//final set of cards
		for(int i = 0; i < 4; i ++){
			String splitCards[] = splitSetRows[6+i].split(" ");
			for(int j = 0; j < 4; j ++){
				secondSet[i][j] = Integer.parseInt(splitCards[j]);
			}
		}
		
	}
}
