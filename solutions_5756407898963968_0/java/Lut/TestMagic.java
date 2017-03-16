import java.lang.Math;

public class TestMagic{
	static int[] cards1,cards2;
	static int guess1,guess2;
	static String result="";
	static String[] game;

	public static void main(String[] args){
		game=args[0].split("\n");
		int T= Integer.parseInt(game[0]);
		//System.out.println("\nInput\n\n"+args[0]);
		for (int round=0;round<T;round++)
		set(round);

		System.out.println("\nOutput\n"+result);
	}

	public static void set(int round){
		guess1=Integer.parseInt(game[round*10+1])-1;
		cards1= new int[16];
		for (int line=0;line<4;line++){
			String[] inLine=game[round*10+2+line].split(" ");
			for (int col=0;col<4;col++){
				cards1[line*4+col]=Integer.parseInt(inLine[col]);
			}
		}

		guess2=Integer.parseInt(game[round*10+6])-1;
		cards2= new int[16];
		for (int line=0;line<4;line++){
			String[] inLine=game[round*10+7+line].split(" ");
			for (int col=0;col<4;col++){
				cards2[line*4+col]=Integer.parseInt(inLine[col]);
			}
		}

		result=result+test(round+1);
	}

	public static String test(int round){
		int card=-1;
		for(int pos=guess1*4;pos<guess1*4+4;pos++){
			for(int pos2=guess2*4;pos2<guess2*4+4;pos2++){
				if (cards1[pos]==cards2[pos2]){
					if (card!=-1) return "Case #"+round+": Bad magician!\n";
					else card=cards1[pos];
				}
			}
		}
		if (card>=0) return "Case #"+round+": "+card+"\n";
		else return "Case #"+round+": Volunteer cheated!\n";
	}

}