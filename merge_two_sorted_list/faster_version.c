#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode* next;
};

struct ListNode* ft_lstnew(int content)
{
	struct ListNode	*new_node;

	new_node = malloc(sizeof(struct ListNode));
	if (!new_node)
		return (NULL);
	new_node -> val = content;
	new_node -> next = NULL;
	return (new_node);
}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy; // Dummy node to simplify the process
    struct ListNode* op = &dummy; // Pointer to traverse the merged list

    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            op->next = list1;
            list1 = list1->next;
        } else {
            op->next = list2;
            list2 = list2->next;
        }
        op = op->next;
    }

    // Attach the remaining part of the non-empty list
    op->next = (list1 != NULL) ? list1 : list2;

    return dummy.next; // The merged list starts at dummy.next
}

int main(void)
{
    struct ListNode *a1 = ft_lstnew(1);
    struct ListNode *a2 = ft_lstnew(2);
    struct ListNode *a3 = ft_lstnew(4);
    a1->next = a2;
    a2->next = a3;

    struct ListNode *b1 = ft_lstnew(1);
    struct ListNode *b2 = ft_lstnew(3);
    struct ListNode *b3 = ft_lstnew(4);
    b1->next = b2;
    b2->next = b3;

    struct ListNode *merged = mergeTwoLists(a1, b1);

    while (merged)
    {
        printf("%d ", merged->val);
        merged = merged->next;
    }
    printf("\n");

    return 0;
}