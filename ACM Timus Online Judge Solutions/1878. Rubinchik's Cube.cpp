# include <stdio.h>
# include <algorithm>

int Turn[4][4][2] = {
	{{0,0}, {0,3}, {3,3}, {3,0}},
	{{0,1}, {1,3}, {3,2}, {2,0}},
	{{1,0}, {0,2}, {2,3}, {3,1}},
	{{1,1}, {1,2}, {2,2}, {2,1}}
};

int R[4][4], ans[4];

int main ()
{
	for (int i = 0; i < 4; i++)
		for (int h = 0; h < 4; h++)
			scanf("%d" ,&R[i][h]);
	
	for (int i = 0; i < 4; i++)
		for (int h = 0; h < 4; h++)
			if (R[Turn[i][h][0]][Turn[i][h][1]]==1)
				ans[(h+1)%4]++,
				ans[(h+2)%4]+=2,
				ans[(h+3)%4]++;
	
	printf("%d" ,std::min(ans[0], std::min(ans[1], std::min(ans[2], ans[3]))));
	
	return 0;
}
