char qipan[3][3];

void dtmQipan()
{
	bool xwin = 0;
	bool owin = 0;
	if (qipan[0][0] == qipan[1][0] && qipan[1][0] == qipan[2][0])
	{
		if (qipan[0][0] == 'X')
			xwin = 1;
		if (qipan[0][0] == 'O')
			owin = 1;
	}
	//2
	if (qipan[0][0] == qipan[0][1] && qipan[0][1] == qipan[0][2])
	{
		if (qipan[0][0] == 'X')
			xwin = 1;
		if (qipan[0][0] == 'O')
			owin = 1;
	}
	//3
	if (qipan[1][0] == qipan[1][1] && qipan[1][1] == qipan[1][2])
	{
		if (qipan[0][0] == 'X')
			xwin = 1;
		if (qipan[0][0] == 'O')
			owin = 1;
	}

	//4
	if (qipan[2][0] == qipan[2][1] && qipan[2][1] == qipan[2][2])
	{
		if (qipan[0][0] == 'X')
			xwin = 1;
		if (qipan[0][0] == 'O')
			owin = 1;
	}
	//5
	if (qipan[0][1] == qipan[1][1] && qipan[2][1] == qipan[1][1])
	{
		if (qipan[0][0] == 'X')
			xwin = 1;
		if (qipan[0][0] == 'O')
			owin = 1;
	}
	//6
	if (qipan[0][2] == qipan[1][2] && qipan[2][2] == qipan[1][2])
	{
		if (qipan[0][0] == 'X')
			xwin = 1;
		if (qipan[0][0] == 'O')
			owin = 1;
	}
	//7
	if (qipan[0][0] == qipan[1][1] && qipan[2][2] == qipan[1][1])
	{
		if (qipan[0][0] == 'X')
			xwin = 1;
		if (qipan[0][0] == 'O')
			owin = 1;
	}
	//8
	if (qipan[2][0] == qipan[1][1] && qipan[0][2] == qipan[1][1])
	{
		if (qipan[0][0] == 'X')
			xwin = 1;
		if (qipan[0][0] == 'O')
			owin = 1;
	}

	if (xwin)
	{
		printf("X Win\n");
		return;
	}
	if (owin)
	{
		printf("O Win\n");
		return;
	}

	printf("Draw\n");
	return;
}

int dtmQipan(char _qipan[3][3])
{
	bool xwin = 0;
	bool owin = 0;
	if (_qipan[0][0] == _qipan[1][0] && _qipan[1][0] == _qipan[2][0])
	{
		if (_qipan[0][0] == 'X')
			xwin = 1;
		if (_qipan[0][0] == 'O')
			owin = 1;
	}
	//2
	if (_qipan[0][0] == _qipan[0][1] && _qipan[0][1] == _qipan[0][2])
	{
		if (_qipan[0][0] == 'X')
			xwin = 1;
		if (_qipan[0][0] == 'O')
			owin = 1;
	}
	//3
	if (_qipan[1][0] == _qipan[1][1] && _qipan[1][1] == _qipan[1][2])
	{
		if (_qipan[0][0] == 'X')
			xwin = 1;
		if (_qipan[0][0] == 'O')
			owin = 1;
	}

	//4
	if (_qipan[2][0] == _qipan[2][1] && _qipan[2][1] == _qipan[2][2])
	{
		if (_qipan[0][0] == 'X')
			xwin = 1;
		if (_qipan[0][0] == 'O')
			owin = 1;
	}
	//5
	if (_qipan[0][1] == _qipan[1][1] && _qipan[2][1] == _qipan[1][1])
	{
		if (_qipan[0][0] == 'X')
			xwin = 1;
		if (_qipan[0][0] == 'O')
			owin = 1;
	}
	//6
	if (_qipan[0][2] == _qipan[1][2] && _qipan[2][2] == _qipan[1][2])
	{
		if (_qipan[0][0] == 'X')
			xwin = 1;
		if (_qipan[0][0] == 'O')
			owin = 1;
	}
	//7
	if (_qipan[0][0] == _qipan[1][1] && _qipan[2][2] == _qipan[1][1])
	{
		if (_qipan[0][0] == 'X')
			xwin = 1;
		if (_qipan[0][0] == 'O')
			owin = 1;
	}
	//8
	if (_qipan[2][0] == _qipan[1][1] && _qipan[0][2] == _qipan[1][1])
	{
		if (_qipan[0][0] == 'X')
			xwin = 1;
		if (_qipan[0][0] == 'O')
			owin = 1;
	}

	if (xwin)
	{
		//printf("X Win\n");
		return 1;
	}
	if (owin)
	{
		//printf("O Win\n");
		return 1;
	}

	return 0 ;
}



int main()
{
	// read input
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		int xnum = 0, onum = 0;
		for (int j = 0; j < 3; j++)
		{
			scanf("%c%c%c\n", &qipan[j][0], &qipan[j][1], &qipan[j][2]);
		}

		// count number
		for (int p = 0; p < 3; p++)
			for (int q = 0; q < 3; q++)
			{
				if (qipan[p][q] == 'X')
					xnum++;
				if (qipan[p][q] == 'O')
					onum++;
			}
			// case 1
			if (xnum - onum < 0)
			{
				printf("Invalid\n");
				continue;
			}

			// case 2
			if (xnum == 3 && onum == 3)
			{
				dtmQipan();
				continue;
			}

			if (xnum == 2 && onum == 2) // 
			{
				char temp[3][3];
				for (int i = 0; i < 3; i++)
					strcpy(temp[i], qipan[i]);
				for (int p = 0; p < 3; p++)
					for (int q = 0; q < 3; q++)
					{
						if (qipan[p][q] == '_')
						{
							temp[p][q] = 'X';
							if (dtmQipan(temp))
							{
								printf("Next Win");
								break;
							}
							else
								continue;
						}


					}
			}

			if (xnum == 3 && onum == 2) // 
			{
				char temp[3][3];
				for (int i = 0; i < 3; i++)
					strcpy(temp[i], qipan[i]);
				for (int p = 0; p < 3; p++)
					for (int q = 0; q < 3; q++)
					{
						if (qipan[p][q] == '_')
						{
							temp[p][q] = 'O';
							if (dtmQipan(temp))
							{
								printf("Next Win\n");
								break;
							}
							else
								continue;
						}


					}
			}

			printf("Next cannot win\n");

	}


	return 0;

}
