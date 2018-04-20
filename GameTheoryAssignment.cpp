#include <bits/stdc++.h>
using namespace std;

#define SIZE 4

int main()
{
	int matrix[SIZE][SIZE];
	
	cout << "\nEnter the payoff matrix of size 4x4 with respect to player A\n";
	int i,j,n;

	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			cin >> matrix[i][j];
		}
	}

	cout << "\nPayoff Matrix\n";
	for(i=0;i<SIZE;i++)
	{
		for(j=0;j<SIZE;j++)
		{
			cout << matrix[i][j] << " ";
		}
		cout << "\n";
	}

	int RowMin[SIZE];
	int ColumnMax[SIZE];

	for(i=0;i<SIZE;i++)
	{
		int mi = 9999999;

		for(j=0;j<SIZE;j++)
		{
			mi = min(mi,matrix[i][j]);
		}

		RowMin[i] = mi;
	}

	for(i=0;i<SIZE;i++)
	{
		int ma = -1;

		for(j=0;j<SIZE;j++)
		{
			ma = max(ma,matrix[j][i]);
		}

		ColumnMax[i] = ma;
	}

	int Maximin = -1, Minimax = 9999999;


	cout << "\n";

	cout << "Row Minimum -> ";
	for(i=0;i<SIZE;i++){
		cout << RowMin[i] << " ";
		Maximin = max(Maximin,RowMin[i]);
	}

	cout << "\nColumn Maximum -> ";
	for(i=0;i<SIZE;i++){
		cout << ColumnMax[i] << " ";
		Minimax = min(Minimax,ColumnMax[i]);
	}

	cout << "\n\n";

	cout << "Maximin value : " << Maximin << "\n";
	cout << "Minimax value : " << Minimax << "\n\n";


	if(Maximin == Minimax)
	{
		cout << "Maximin value is equal to Minimax value\n\n";
		cout << "Value of the game is " << Maximin << "\n\n";
		
		int x = Maximin;
		int a,b;

		for(i=0;i<SIZE;i++)
		{
			if(RowMin[i] == x)
			{
				a = i;
				break;
			}
		}

		for(i=0;i<SIZE;i++)
		{
			if(ColumnMax[i] == x)
			{
				b = i;
				break;
			}
		}

		cout << "Strategies of Player A : ";
		cout << "[ ";
		for(i=0;i<SIZE;i++)
		{
			if(a != i)
			{
				if(i != SIZE-1)
					cout << "0, ";
				else
					cout << "0 ";
			}
			else
			{
				if(i != SIZE-1)
				{
					cout << "1, ";
				}
				else
					cout << "1 ";
			}
		} 

		cout << "]\n";

		cout << "Strategies of Player B : ";
		cout << "[ ";

		for(i=0;i<SIZE;i++)
		{
			if(b != i)
			{
				if(i != SIZE-1)
					cout << "0, ";
				else
					cout << "0 ";
			}
			else
			{
				if(i != SIZE-1)
				{
					cout << "1, ";
				}
				else
					cout << "1 ";
			}
		} 
		cout << "]\n\n";
	}
	else
	{
		cout << "Maximin value is NOT equal to Minimax value\n\n";
		cout << "NO saddle point exists.\n\n";
	}

	cout << "Thank You !\n\n";
	return 0;	 
}