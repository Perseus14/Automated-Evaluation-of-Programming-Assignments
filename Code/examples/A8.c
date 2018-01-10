#include <stdio.h>

typedef struct _a_r
{
	int		score;
	char	name[64];
	int 	latest;
} a_r;

a_r rs[1000];

int main()
{
	int r = 0;
	int i = 0;
	int j = 0;
	int w = 0;
	int k = 0;
	int max_score = 0;
	
	scanf("%d", &r);
	
	while (scanf("%s%d", &rs[i].name, &rs[i].score) != EOF)
	{	
		for (j = 0; j != i; ++j)
		{
			if (strcmp(rs[j].name, rs[i].name) == 0 && rs[j].latest == 1)
			{
				rs[i].score += rs[j].score;
				rs[j].latest = 0;
			}
		}
		
		rs[i].latest = 1;
		
		++i;
	}
	
	for (j = 0; j != i; ++j)
	{
		if (rs[j].score > max_score && rs[j].latest == 1)
			max_score = rs[j].score;
	}
	
	for (j = 0; j != i; ++j)
	{
		if (rs[j].score >= max_score)
		{
			for (k = j; k != i; ++k)
			{
				if (rs[k].latest == 1 && rs[k].score >= max_score && strcmp(rs[k].name, rs[j].name) == 0)
				{
					w = k;
					printf("%s", rs[w].name);
					return 0;
				}
			}
		}	
	}
	
	printf("err, not find the result!\n");
	
	return 0;
}
