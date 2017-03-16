import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class P1MagicTrick
{
	private final int id;
	private final int firstAnswer;
	private final int[][] firstArrangement;
	private final int secondAnswer;
	private final int[][] secondArrangement;

	public P1MagicTrick(int id, int firstAnswer, int[][] firstArrangement, int secondAnswer, int[][] secondArrangement)
	{
		this.id = id;
		this.firstAnswer = firstAnswer;
		this.firstArrangement = firstArrangement;
		this.secondAnswer = secondAnswer;
		this.secondArrangement = secondArrangement;
	}

	public void solve()
	{
		int[] possibleValues1 = firstArrangement[firstAnswer - 1];
		int[] possibleValues2 = secondArrangement[secondAnswer - 1];

		int finalAnswer = 0;
		int possibleAnswers = 0;
		for(int i = 0; i < 4; i++)
		{
			for(int j = 0; j < 4; j++)
			{
				if(possibleValues1[i] == possibleValues2[j])
				{
					possibleAnswers++;
					finalAnswer = possibleValues1[i];
				}
			}
		}

		if(possibleAnswers == 1)
			System.out.println("Case #" + (id + 1) + ": " + finalAnswer);
		else if(possibleAnswers == 0)
			System.out.println("Case #" + (id + 1) + ": Volunteer cheated!");
		else
			System.out.println("Case #" + (id + 1) + ": Bad magician!");
	}

	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);

		int numberOfTestCases = in.nextInt();
		List<P1MagicTrick> problemList = new ArrayList<P1MagicTrick>();

		for(int i = 0; i < numberOfTestCases; i++)
		{
			int firstAnswer = in.nextInt();
			int[][] firstArrangement = new int[4][4];
			for(int y = 0; y < 4; y++)
			{
				for(int x = 0; x < 4; x++)
				{
					firstArrangement[y][x] = in.nextInt();
				}
			}

			int secondAnswer = in.nextInt();
			int[][] secondArrangement = new int[4][4];
			for(int y = 0; y < 4; y++)
			{
				for(int x = 0; x < 4; x++)
				{
					secondArrangement[y][x] = in.nextInt();
				}
			}

			problemList.add(new P1MagicTrick(i, firstAnswer, firstArrangement, secondAnswer, secondArrangement));
		}

		for(P1MagicTrick problem : problemList)
		{
			problem.solve();
		}
	}
}
