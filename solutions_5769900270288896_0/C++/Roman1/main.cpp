#include <cassert>
#include <fstream>
#include <string>
#include <vector>

#define MAX_R_C 16

int
calc(int R, int C, int N)
{
	int min = MAX_R_C * MAX_R_C;

	for (unsigned int i = 0; i <= (1u << 16) - 1; i++)
	{
		int n = 0;

		for (int r = 0; r < R; r++)
		{
			for (int c = 0; c < C; c++)
			{
				int index = r * C + c;
				
				if ((i & (1u << index)) != 0)
				{
					n++;
				}
			}
		}

		if (n != N)
		{
			continue;
		}

		int points = 0;

		const int offsets[4][2] = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

		for (int r = 0; r < R; r++)
		{
			for (int c = 0; c < C; c++)
			{
				int index1 = r * C + c;

				if ((i & (1u << index1)) != 0)
				{
					for (int offset = 0; offset < 4; offset++)
					{
						int offset_r = offsets[offset][0];
						int offset_c = offsets[offset][1];

						if (r + offset_r >= 0
							&& r + offset_r < R
							&& c + offset_c >= 0
							&& c + offset_c < C)
						{
							int index2 = (r + offset_r) * C + (c + offset_c);

							if ((i & (1u << index2)) != 0)
							{
								points++;
							}
						}
					}
				}
			}
		}

		assert(points % 2 == 0);
		points /= 2;

		if (min > points)
		{
			min = points;
		}
	}

	return min;
}

int
main(int argc, char **argv)
{
	std::ifstream in("input.txt");
	std::ofstream out("output.txt");

	int T;
	in >> T;
	for (int t = 0; t < T; t++)
	{
		int R, C, N;
		in >> R >> C >> N;

		int answer = calc(R, C, N);

		out << "Case #" << (t + 1) << ": " << answer << std::endl;
	}

	in.close();
	out.close();

	return 0;
}