/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#include <stdlib.h>
#include <string.h>

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    int **mainArr;
    int count = 0;
    
    mainArr = (int **)malloc(sizeof(int *) * 2);
    for(int i = 0; numsSize > i; i++)
    {
		
    }
    *returnSize = count;
    return (mainArr);
}


/*

void backtrack(params) {
    // Rekursiya uchun baza sharti
    if (yechim topildi) {
        // ... saqla va qayt
        return;
    }

    // Iteratsiya: Barcha tanlovlar bo'yicha sikl
    for (har bir tanlov) {
        // Tanlovni amalga oshirish
        // ...
        
        // Rekursiv chaqiruv: Chuqurroq kirish
        backtrack(params);
        
        // Backtrack: Tanlovni bekor qilish
        // ...
    }
}

*/