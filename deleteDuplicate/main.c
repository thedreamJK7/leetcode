#include <stdio.h>
#include <stdlib.h>

// Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

// SIZNING ALGORITMINGIZ SHU YERGA
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* current = head;
    // duplicate 1
    // while (current && current->next)
    // {
    //     if (current->val == current->next->val)
    //         current->next = current->next->next;
    //     else
    //         current = current->next;
    // }
    // duplicate 2
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy;

    while (current && current->next)
    {
        if (current->val == current->next->val)
        {
            while (current->next && current->val == current->next->val)
                current = current->next;
            
            prev->next = current->next;
            current = current->next;
        }
        else
        {
            prev = current;
            current = current->next;
        }
    }
    return dummy->next;
}


// LINKED LIST YARATISH (test uchun)
struct ListNode* createList(int arr[], int size) {
    if (size == 0) return NULL;
    
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = arr[0];
    head->next = NULL;
    
    struct ListNode* current = head;
    for (int i = 1; i < size; i++) {
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = arr[i];
        current->next = NULL;
    }
    return head;
}

// LINKED LISTNI CHOP ETISH
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

// LINKED LISTNI O'CHIRISH (xotirani bo'shatish)
void freeList(struct ListNode* head) {
    struct ListNode* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

// MAIN FUNKSIYA - TEST QILISH UCHUN
int main() {
    // Test case 1
    int arr1[] = {1, 1, 2};
    struct ListNode* head1 = createList(arr1, 3);
    printf("Original: ");
    printList(head1);
    head1 = deleteDuplicates(head1);
    printf("After: ");
    printList(head1);
    freeList(head1);
    
    // Test case 2
    int arr2[] = {1, 1, 2, 3, 3};
    struct ListNode* head2 = createList(arr2, 5);
    printf("\nOriginal: ");
    printList(head2);
    head2 = deleteDuplicates(head2);
    printf("After: ");
    printList(head2);
    freeList(head2);
    
    // Test case 3 - bosh linked list
    struct ListNode* head3 = NULL;
    printf("\nOriginal: ");
    printList(head3);
    head3 = deleteDuplicates(head3);
    printf("After: ");
    printList(head3);
    
    // Test case 4 - hammasi bir xil
    int arr4[] = {2, 2, 2, 2};
    struct ListNode* head4 = createList(arr4, 4);
    printf("\nOriginal: ");
    printList(head4);
    head4 = deleteDuplicates(head4);
    printf("After: ");
    printList(head4);
    freeList(head4);
    
    return 0;
}