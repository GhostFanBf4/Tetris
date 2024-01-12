#ifndef BRICKS_H
#define BRICKS_H

// Plik z 7 klockami kazdy z 4 rotacjami w matrixach 4 na 4

// Liczby w klockach odpowiadajace kolorom z oryginalnego tetrisa (nintendo)

//         rodzaje
//         |  rotacje
//         |  |  wysokosc
//         |  |  |  szerokosc
//         |  |  |  |
int bricks[7][4][4][4] {
	{
		// 1 Klocek I
		{
			{0, 0, 0, 0},
			{6, 6, 6, 6},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 6, 0},
			{0, 0, 6, 0},
			{0, 0, 6, 0},
			{0, 0, 6, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 0, 0, 0},
			{6, 6, 6, 6},
			{0, 0, 0, 0}
		},
		{
			{0, 6, 0, 0},
			{0, 6, 0, 0},
			{0, 6, 0, 0},
			{0, 6, 0, 0}
		}
	},
	{ // 2 Klocek T
		{
		        {0, 5, 0, 0},
			{5, 5, 5, 0},
		        {0, 0, 0, 0},
		        {0, 0, 0, 0}
        	},
        	{
		        {0, 5, 0, 0},
		        {0, 5, 5, 0},
		        {0, 5, 0, 0},
		        {0, 0, 0, 0}
       		},
        	{
		        {0, 0, 0, 0},
		        {5, 5, 5, 0},
		        {0, 5, 0, 0},
		        {0, 0, 0, 0}
        	},
        	{
		        {0, 5, 0, 0},
		        {5, 5, 0, 0},
		        {0, 5, 0, 0},
		        {0, 0, 0, 0}
        	}
	},
	{
		// 3 Klocek Z
		{
			{0, 1, 0, 0},
			{1, 1, 0, 0},
			{1, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{1, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 1, 0},
			{0, 1, 1, 0},
			{0, 1, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{1, 1, 0, 0},
			{0, 1, 1, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		}
	},
	{
		// 4 Klocek S
		{
			{0, 2, 2, 0},
			{2, 2, 0, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 2, 0, 0},
			{0, 2, 2, 0},
			{0, 0, 2, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{0, 2, 2, 0},
			{2, 2, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{2, 0, 0, 0},
			{2, 2, 0, 0},
			{0, 2, 0, 0},
			{0, 0, 0, 0}
		}
	},
	{
		// 5 Klocek O (kwadrat)
		{
			{0, 3, 3, 0},
			{0, 3, 3, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 3, 3, 0},
			{0, 3, 3, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 3, 3, 0},
			{0, 3, 3, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 3, 3, 0},
			{0, 3, 3, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		}
	},
	{
		// 6 Klocek L
		{
			{0, 0, 7, 0},
			{7, 7, 7, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 7, 0, 0},
			{0, 7, 0, 0},
			{0, 7, 7, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{7, 7, 7, 0},
			{7, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{7, 7, 0, 0},
			{0, 7, 0, 0},
			{0, 7, 0, 0},
			{0, 0, 0, 0}
		}
	},
	{
		// 7 Klocek J
		{
			{4, 0, 0, 0},
			{4, 4, 4, 0},
			{0, 0, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 4, 4, 0},
			{0, 4, 0, 0},
			{0, 4, 0, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 0, 0, 0},
			{4, 4, 4, 0},
			{0, 0, 4, 0},
			{0, 0, 0, 0}
		},
		{
			{0, 4, 0, 0},
			{0, 4, 0, 0},
			{4, 4, 0, 0},
			{0, 0, 0, 0}
		}
	}
};

#endif
