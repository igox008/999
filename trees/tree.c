#include "tree.h"

t_tree	*new_tree(char *content)
{
	static int	i;
	t_tree		*ret;

	ret = malloc(sizeof(t_tree));
	if (!ret)
		return (NULL);
	ret->content = strdup(content);
	if (!ret)
		return (NULL);
	ret->left = NULL;
	ret->right = NULL;
	if (!i)
		ret->tag = ROOT;
	else
		ret->tag = NODE;
	(!i) && (i++);
	return (ret);
}

void	printtree(t_tree *node)
{
	if (!node)
		return ;
	printf("%s\n", node->content);
	printtree(node->left);
	printtree(node->right);
}

int main()
{
	t_tree	*root = new_tree("root");
	t_tree	*node1 = new_tree("node1");
	t_tree	*node2 = new_tree("node2");
	t_tree	*node3 = new_tree("node3");
	t_tree	*node4 = new_tree("node4");
	t_tree	*node5 = new_tree("node5");
	t_tree	*node6 = new_tree("node6");
	t_tree	*node7 = new_tree("node7");
	t_tree	*node8 = new_tree("node8");

	root->left = node1;
	root->right = node2;

	node1->left = node3;
	node1->right = node4;

	node2->left = node5;
	node2->right = node6;

	node5->right = node7;

	node6->left = node8;
	printtree(root);
	exit(0);
}