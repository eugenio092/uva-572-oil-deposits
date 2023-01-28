#include <bits/stdc++.h>

using namespace std;

int lin, col;
char mat[105][105];

int ax[8] = {-1,-1,0,1,1,1,0,-1};
int ay[8] = {0,1,1,1,0,-1,-1,-1};

void flood_fill(int l, int c)
{
	mat[l][c] = '*';
	
	for(int i = 0; i < 8; i++)
	{
		int x = l + ax[i];
		int y = c + ay[i];
		
		if(x >= 0 and x < lin and y >= 0 and y < col and mat[x][y] == '@')
		{
			flood_fill(x,y);
		}
	}
}

int main()
{
	int num;

	cin >> lin >> col;
	
	while(lin != 0 or col != 0)
	{
		for(int i = 0; i < lin; i++)
		{
			for(int j = 0; j < col; j++)
			{
				cin >> mat[i][j];
			}
		}
		
		num = 0;
		
		for(int i = 0; i < lin; i++)
		{
			for(int j = 0; j < col; j++)
			{
				if(mat[i][j] == '@')
				{
					num++;
					
					flood_fill(i,j);
				}
			}
		}
		
		cout << num << endl;
		
		cin >> lin >> col;
	}
}
