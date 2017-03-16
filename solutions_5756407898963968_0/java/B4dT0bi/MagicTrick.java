import java.io.BufferedReader;
import java.io.FileReader;

public class MagicTrick
{

	public static void main(String[] args)
	{
		try
		{
			BufferedReader br = new BufferedReader(new FileReader(args[0]));
			int anzTC = Integer.parseInt(br.readLine());
			for (int tc = 0; tc < anzTC; tc++)
			{
				int firstAnswer = Integer.parseInt(br.readLine());
				int[][] deckOne = new int[4][4];
				for (int i = 0; i < 4; i++)
				{
					String[] tmp = br.readLine().split(" ");
					for (int n = 0; n < 4; n++)
						deckOne[i][n] = Integer.parseInt(tmp[n]);
				}
				int secondAnswer = Integer.parseInt(br.readLine());
				int[][] deckTwo = new int[4][4];
				for (int i = 0; i < 4; i++)
				{
					String[] tmp = br.readLine().split(" ");
					for (int n = 0; n < 4; n++)
						deckTwo[i][n] = Integer.parseInt(tmp[n]);
				}
				solve(tc + 1, firstAnswer, secondAnswer, deckOne, deckTwo);
			}
			br.close();
		}
		catch (Exception ex)
		{
			ex.printStackTrace();
		}
	}

	private static void solve(int tc, int firstAnswer, int secondAnswer, int[][] firstDeck, int[][] secondDeck)
	{
		int anzSame = 0;
		int card = 0;
		for (int i = 0; i < 4; i++)
		{
			for (int n = 0; n < 4; n++)
			{
				if (firstDeck[firstAnswer-1][i] == secondDeck[secondAnswer-1][n])
				{
					anzSame++;
					card = firstDeck[firstAnswer-1][i];
				}
			}
		}
		if (anzSame == 0)
		{
			System.out.println("Case #" + tc + ": Volunteer cheated!");
		}
		else if (anzSame == 1)
		{
			System.out.println("Case #" + tc + ": " + card);
		}
		else
		{
			System.out.println("Case #" + tc + ": Bad magician!");
		}
	}

}
