#include <stdio.h>
int removeDuplicates(int* nums, int numsSize) {
    int k;

    for (int i = 0; i < numsSize - 1; i++)
    {
        if (nums[i] != nums[i+1])
        {
            continue;
        }
        else
        {
            for (int j = i; j < numsSize - 1; j++)
			{
				nums[j] = nums[j+1];
			}
        }
    }
	k = 0;
	return (k);
}

int main(int argc, char const *argv[])
{
	int nums[9] = {1, 2, 2, 3, 3, 3, 4, 4, 4};
	removeDuplicates(nums, 9);
	for (int i = 0; i < 9; i++)
	{
		printf("%d\n", nums[i]);
	}
	return (0);
}
