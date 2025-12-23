#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stddef.h>

// struct*
typedef struct s_list
{
	int				num;
	struct s_list	*next;
	int				index;
}	t_list;

#endif