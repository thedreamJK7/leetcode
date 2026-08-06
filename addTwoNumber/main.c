#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// Function to create a new node
struct ListNode* createNode(int val) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list from array
struct ListNode* createList(int arr[], int size) {
    if (size == 0) return NULL;
    
    struct ListNode* head = createNode(arr[0]);
    struct ListNode* current = head;
    
    for (int i = 1; i < size; i++) {
        current->next = createNode(arr[i]);
        current = current->next;
    }
    
    return head;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
	int sum = 0;
	struct ListNode * head = createNode(0);
	struct ListNode * current = head;

    while (l1 != NULL || l2 != NULL)
	{
		int d1, d2;
		if (l1 == NULL)
			d1 = 0;
		else
			d1 = l1->val;
		if (l2 == NULL)
			d2 = 0;
		else
			d2 = l2->val;
		sum = d1 + d2 + carry;
		if (sum > 9)
		{
			current->val = sum % 10;
			carry = 1;
		}
		else
		{
			current->val = sum;
			carry = 0;
		}
		if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
		if (l1 != NULL || l2 != NULL)
		{
			current->next = createNode(0);
            current = current->next;
		}
        else if (carry == 1)
            current->next = createNode(1);
	}
	return (head);
}

void printList(struct ListNode* head) {
    printf("[");
    struct ListNode* current = head;
    while (current != NULL) {
        printf("%d", current->val);
        if (current->next != NULL) {
            printf(",");
        }
        current = current->next;
    }
    printf("]\n");
}

void freeList(struct ListNode* head) {
    struct ListNode* current = head;
    while (current != NULL) {
        struct ListNode* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    // Test case 1: l1 = [2,4,3], l2 = [5,6,4]
    printf("Test case 1:\n");
    int arr1[] = {2, 4, 3};
    int arr2[] = {5, 6, 4};
    
    struct ListNode* l1 = createList(arr1, 3);
    struct ListNode* l2 = createList(arr2, 3);
    
    printf("l1 = ");
    printList(l1);
    printf("l2 = ");
    printList(l2);
    
    struct ListNode* result = addTwoNumbers(l1, l2);
    printf("Output: ");
    printList(result);
    printf("Explanation: 342 + 465 = 807\n\n");
    
    freeList(l1);
    freeList(l2);
    freeList(result);
    
    // Test case 2: l1 = [0], l2 = [0]
    printf("Test case 2:\n");
    int arr3[] = {0};
    int arr4[] = {0};
    
    l1 = createList(arr3, 1);
    l2 = createList(arr4, 1);
    
    printf("l1 = ");
    printList(l1);
    printf("l2 = ");
    printList(l2);
    
    result = addTwoNumbers(l1, l2);
    printf("Output: ");
    printList(result);
    printf("Explanation: 0 + 0 = 0\n\n");
    
    freeList(l1);
    freeList(l2);
    freeList(result);
    
    // Test case 3: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
    printf("Test case 3:\n");
    int arr5[] = {9, 9, 9, 9, 9, 9, 9};
    int arr6[] = {9, 9, 9, 9};
    
    l1 = createList(arr5, 7);
    l2 = createList(arr6, 4);
    
    printf("l1 = ");
    printList(l1);
    printf("l2 = ");
    printList(l2);
    
    result = addTwoNumbers(l1, l2);
    printf("Output: ");
    printList(result);
    printf("Explanation: 9999999 + 9999 = 10009998\n");
    
    freeList(l1);
    freeList(l2);
    freeList(result);
    
    return 0;
}