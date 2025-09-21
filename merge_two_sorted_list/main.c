#include <string.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
    int val;
    struct ListNode *next;
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
    if (!list1 && !list2)
        return (NULL);
    int listarr[100];
    int i = 0;
    while (list1)
    {
        listarr[i++] = list1->val;
        list1 = list1-> next;
    }
    while (list2)
    {
        listarr[i++] = list2->val;
        list2 = list2-> next;
    }
    int len = i;
    for (int j = 0; len > j; j++)
    {
        for(int k = 0; len - j - 1 > k; k++)
        {
            int tmp;
            if (listarr[k] > listarr[k+1])
            {
                tmp = listarr[k];
                listarr[k] = listarr[k+1];
                listarr[k+1] = tmp;
            }
        }
    }
    struct ListNode* mlist;
    struct ListNode* head;
    head = ft_lstnew(listarr[0]);
    mlist = head;
    for (int k = 1; len > k; k++)
    {
        mlist->next = ft_lstnew(listarr[k]);
        mlist = mlist->next;
    }
    return (head);
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
