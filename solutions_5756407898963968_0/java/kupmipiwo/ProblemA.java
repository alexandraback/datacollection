import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;

public class ProblemA
{

	public static void main(String args[]) throws FileNotFoundException
	{
		Scanner sc;
		sc = new Scanner(new FileInputStream("/home/ola/workspace_java/CodeJam2014/ProblemA2Input"));
		int N = sc.nextInt();

		for (int i = 1; i <= N; ++i)
		{
			HashSet<Integer> numbers = new HashSet<>(4);
			int row = sc.nextInt();
			for (int rowNumber = 1; rowNumber <= 4; ++rowNumber)
			{
				if (rowNumber == row)
				{
					for (int rowElem = 0; rowElem < 4; ++rowElem)
					{
						numbers.add(sc.nextInt());
					}
				} else
				{
					sc.nextInt();
					sc.nextInt();
					sc.nextInt();
					sc.nextInt();
				}
			}

			row = sc.nextInt();
			int counter = 0;
			int solution = -1;
			for (int rowNumber = 1; rowNumber <= 4; ++rowNumber)
			{
				if (rowNumber == row)
				{
					for (int rowElem = 0; rowElem < 4; ++rowElem)
					{
						int currentInt = sc.nextInt();
						if (numbers.contains(currentInt))
						{
							counter++;
							solution = currentInt;
						}
					}
				} else
				{
					sc.nextInt();
					sc.nextInt();
					sc.nextInt();
					sc.nextInt();
				}
			}

			StringBuilder sb = new StringBuilder();
			sb.append(String.format("Case #%d: ", i));
			switch (counter)
			{
			case 0:
				sb.append("Volunteer cheated!");
				break;
			case 1:
				sb.append(solution);
				break;
			default:
				sb.append("Bad magician!");

			}
			
			System.out.println(sb.toString());

		}
		sc.close();
	}
}
