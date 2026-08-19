/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#include <stdio.h>
#include <stdlib.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int sum = 0;
    for (int i = 0; digitsSize > i; i++)
        sum = (sum * 10) + digits[i];
    sum++;
	int temp = sum;
	int	base = 1;
	int j = 0;
	while (temp >= 10) {
        temp /= 10;
        base *= 10;
		j++;
    }
	int *result;
	result = malloc(sizeof(int) * j);
	int i = 0;
    while (base > 0)
	{
		result[i] = sum / base;
		sum = sum % base;
		base /= 10;
		i++;
	}
	return (result);
}

