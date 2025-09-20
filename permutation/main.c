// with duplicates allowed 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h>

#include <stdlib.h>
#include <string.h>

void swap(int *x, int *y) 
{ 
	int temp; 
	temp = *x;
	*x = *y;
	*y = temp; 
} 

/* Function to print permutations 
   of string 
   This function takes three parameters: 
   1. String 
   2. Starting index of the string 
   3. Ending index of the string. */
void  permute_helper(int *a, int l, int r, int ***results, int *returnSize) 
{ 
    int i;
	int len = r - l + 1;
    if (l == r)
	{ 
		//(*results)[*returnSize] = malloc(sizeof(int) * (len + 1));
		memcpy(results[*returnSize], a, sizeof(int) * len);
		(*returnSize)++;
		return ;
	} 
    else
    { 
        for (i = l; i <= r; i++) 
        { 
            swap((a + l), (a + i)); 
            permute_helper(a, l + 1, r, results, returnSize);
            //backtrack
            swap((a + l), (a + i)); 
        } 
    } 
	
	// Driver code
}

int** permute(int* nums, int numsSize, int* returnSize)
{
	int **results = malloc(sizeof(int *) * 100);

	permute_helper(nums, 0, numsSize, &results, returnSize);

	results = realloc(results, sizeof(int *) * (*returnSize));

    // *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    // for (int i = 0; i < *returnSize; i++) {
    //     (*returnColumnSizes)[i] = numsSize;
    // }
	return (results);
}
int main() 
{ 
    char str[] = "12"; 
    int n = strlen(str);
	int returnSize = 0;
	int **permute1;

    permute1 = permute(str, n - 1, &returnSize); 

    return 0; 
}
