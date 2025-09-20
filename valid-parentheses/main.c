#include <string.h>
#include <stdlib.h>

typedef struct s_list
{
	char			content;
	struct s_list	*next;
}					t_list;

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new -> next = *lst;
	*lst = new;
}

t_list	*ft_lstnew(char content)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node -> content = content;
	new_node -> next = NULL;
	return (new_node);
}

void list_remove_first(t_list **list)
{
	t_list *tail;

	tail = (*list)->next;
	*list = tail;
}

int main()
{
	char *str;
	char *tmp;
	int	i = 0;
	t_list *brackets;
	t_list *temp;

	str = "{{[]}}\0";
	brackets = NULL;
	while (str[i])
	{
		tmp = strchr("({[", str[i]);
		if (tmp)
		{
			temp = ft_lstnew(strchr("({[", str[i])[0]);
			ft_lstadd_front(&brackets, temp);
			i++;
			continue ; 
		} 
		tmp = strchr("]})", str[i]);
		if (*(tmp) != brackets->content)
		{
			return (0);
		}
		if (*(tmp) == brackets->content)
		{
			list_remove_first(&brackets);
		}
		i++;
	}
	return (1);
}
