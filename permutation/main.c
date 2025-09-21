/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

void swap(int *x, int *y) 
{ 
	int temp; 
	temp = *x;
	*x = *y;
	*y = temp;
}

void my_permute(int* s, int s_p, int l_p, int ***results, int **returnSize)
{
    if (s_p == l_p)
    {
		(*results)[(**returnSize)] = malloc(sizeof(int) * (l_p + 1));
		memcpy((*results)[(**returnSize)], s, sizeof(int) * (l_p + 1));
		++(**returnSize);
		return ;
    }
    else
    {
        for (int i = s_p; i <= l_p; i++)
        {
            swap(&s[s_p], &s[i]);
            my_permute(s, s_p + 1, l_p, &(*results), &(*returnSize));

            // backtrack
            swap(&s[s_p], &s[i]);
        }
        return ;
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
	int **results = malloc(sizeof(int *));

	results[0] = NULL;
	*returnSize = 0;
	my_permute(nums, 0, numsSize - 1, &results, &returnSize);
	results[(*returnSize)] = NULL;

	*returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
	return (results);
}

int main(void) 
{
    int s[3] = {1, 2, 3};
	int **permute1;
	int rs;
	int	*reCS;

	permute1 = permute(s, 3, &rs, &reCS);
	printf("%d \n", rs);
	int i = 0;
	while (permute1[i])
	{
		printf("%d ", permute1[i][0]);
		printf("%d ", permute1[i][1]);
		printf("%d ", permute1[i][2]);
		printf("\n");
		i++;
	}
    return (0);
}
