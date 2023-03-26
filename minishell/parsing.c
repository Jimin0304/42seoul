# include "../includes/tree.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

void	syntax_pipeline(t_node *parent);
void	syntax_cmd(t_node *parent);
void	syntax_redirect_list(t_node *parent);
void	syntax_redirect(t_node *parent);
void	syntax_simple_cmd(t_node *parent);
int	get_token(t_node *parent);
char	**ft_split(char *s, char c);
int	ft_strlen(char *s);
char	*ft_strdup(char *s1);
int	ft_strlcpy(char *dst, char *src, int dstsize);

void	syntax_pipeline(t_node *parent)
{
	parent->type = get_token(parent);
	syntax_cmd(parent->left);
	if (parent->type == T_PIPE)
	{
		syntax_pipeline(parent->right);
	}
}

void	syntax_cmd(t_node *parent)
{
	parent->type = get_token(parent);
	syntax_simple_cmd(parent->right);
	if (parent->type == T_REDIR_LIST)
	{
		syntax_redirect_list(parent->left);
	}
}

void	syntax_redirect_list(t_node *parent)
{
	//printf("%d, %s\n", parent->type, parent->str1);
	parent->type = get_token(parent);
	syntax_redirect(parent->left);
	if (parent->type == T_REDIR_LIST)
	{
		syntax_redirect_list(parent->right);
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

void	syntax_redirect(t_node *parent)
{
	parent->str2 = ft_split(parent->str1, (char)32);
	return ; //test하려고 바로 빠져나가게

	if ((ft_strcmp(parent->str2[0], "<") != 0) || (ft_strcmp(parent->str2[0], "<<") != 0) \
	|| (ft_strcmp(parent->str2[0], ">") != 0) || (ft_strcmp(parent->str2[0], ">>") != 0))
		exit(1);	// 잘못된 redirect 기호가 들어가 있을 때
	if (parent->str2[2] != NULL)
		exit(1);	// 리다이렉션 기호, 파일 이름 이 외에 더 들어왔을 때
}

void	syntax_simple_cmd(t_node *parent)
{
	parent->str2 = ft_split(parent->str1, (char)32);
	return ; //test하려고 바로 빠져나가게


	if (ft_strcmp(parent->str2[0], "echo") == 0)
		;
	else if (ft_strcmp(parent->str2[0], "cd") == 0)
		;
	else if (ft_strcmp(parent->str2[0], "pwd") == 0)
		;
	else if (ft_strcmp(parent->str2[0], "export") == 0)
		;
	else if (ft_strcmp(parent->str2[0], "unset") == 0)
		;
	else if (ft_strcmp(parent->str2[0], "env") == 0)
		;
	else if (ft_strcmp(parent->str2[0], "exit") == 0)
		;
	else
		exit(1);	// 정의 되지 않은 빌트인 함수
}

t_tree	*make_top_node(char *str)
{
	t_node	*node;
	t_tree	*top;

	node = (t_node *)malloc(sizeof(t_node));
	top = (t_tree *)malloc(sizeof(t_tree));
	if (!(node && top))
		exit(1);
	node->type = T_PIPE;
	node->str1 = str;
	top->top = node;
	return (top);
}

char	*ft_substr(char *s, unsigned int start, int len)
{
	char	*str;
	int		size;
	int		i;

	if (!s)
		return (0);
	size = ft_strlen(s);
	if (start >= size)
		return (ft_strdup(""));
	if (size - start < len)
		len = size - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < len && s[start] != '\0')
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

void	make_tree(int i, int type, t_node *parent)
{
	t_node	*left_node;
	t_node	*right_node;

	left_node = (t_node *)malloc(sizeof(t_node));
	right_node = (t_node *)malloc(sizeof(t_node));
	if (!(left_node && right_node))
		exit(1);
	if (type == T_PIPE)
	{
		left_node->str1 = ft_substr(parent->str1, 0, i);
		right_node->str1 = ft_substr(parent->str1, i, ft_strlen(parent->str1) - i);
		left_node->type = T_CMD;
		right_node->type = T_PIPE;
		left_node->parent = parent;
		right_node->parent = parent;
		parent->left = left_node;
		parent->right = right_node;
	}
	else if (type == T_CMD)
	{
		left_node->str1 = ft_substr(parent->str1, i, ft_strlen(parent->str1) - i);
		right_node->str1 = ft_substr(parent->str1, 0, i);
		left_node->type = T_REDIR_LIST;
		right_node->type = T_WORD;
		left_node->parent = parent;
		right_node->parent = parent;
		parent->left = left_node;
		parent->right = right_node;
	}
	else if (type == T_REDIR)
	{
		left_node->str1 = ft_substr(parent->str1, 0, i);
		left_node->type = T_REDIR;
		left_node->parent = parent;
		parent->left = left_node;
		if (i == 0)
		{
			parent->right = NULL;
			return ;
		}
		right_node->str1 = ft_substr(parent->str1, i, ft_strlen(parent->str1) - i);
		right_node->type = T_REDIR_LIST;
		right_node->parent = parent;
		parent->right = right_node;
	}
}

int	get_token(t_node *parent)
{
	int	i;

	i = 0;
	while (parent->str1[i])
	{
		if ((i > 0) && (parent->str1[i] == '|'))
		{
			make_tree(i, T_PIPE, parent);
			printf("\ntype:%d\nleft:%s\nright:%s\n", parent->type, parent->left->str1, parent->right->str1);
			return (T_PIPE);
		}
		i++;
	}
	if (parent->type == T_PIPE)
		parent->type = T_CMD;
	i = 0;
	while (parent->str1[i])
	{
		if ((i > 1) && (parent->str1[i] == '<' || parent->str1[i] == '>'))
		{
			if (parent->type == T_CMD)
			{
				make_tree(i, T_CMD, parent);
				printf("\ntype:%d\nleft:%s\nright:%s\n", parent->type, parent->left->str1, parent->right->str1);
				return (T_REDIR_LIST);
			}
			else
			{
				make_tree(i, T_REDIR, parent);
				printf("\ntype:%d\nleft:%s\nright:%s\n", parent->type, parent->left->str1, parent->right->str1);
				return (T_REDIR_LIST);
			}
		}
		i++;
	}
	printf("%s\n", parent->str1);
	if (parent->type == T_REDIR_LIST)
	{
		make_tree(0, T_REDIR, parent);
		return (T_REDIR);
	}
	make_tree(i, T_CMD, parent);
	printf("\ntype:%d\nleft:%s\nright:%s\n", parent->type, parent->left->str1, parent->right->str1);
	return (T_CMD);
}

t_tree	*parser(char *str)
{
	t_tree	*top;

	top = make_top_node(str);
	//printf("%s, %d\n", top->top->str1, top->top->type);
	syntax_pipeline(top->top);
	return (top);
}

int main()
{
	t_tree	*t;

	t = parser("ls -a -l >> a < b > c | grep "" | cat << x > y");
	while (t->top)
	{
		//printf("%s\n", t->top->str1);
		t->top = t->top->left;
	}
}



static int	cmp(char s, char c)
{
	if (s == c)
		return (0);
	else
		return (-1);
}

static int	word_count(char *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] != '\0' && cmp(s[i], c) == 0)
			i++;
		if (s[i] != '\0' && cmp(s[i], c) != 0)
			cnt++;
		while (s[i] != '\0' && cmp(s[i], c) != 0)
			i++;
	}
	return (cnt);
}

static void	free_all(char **result, int r)
{
	int	i;

	i = 0;
	while (i <= r)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return ;
}

static int	word_print(char *s, char c, int check, char **result)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (s[i])
	{
		while (s[i] != '\0' && cmp(s[i], c) == 0)
			i++;
		check = i;
		while (s[i] != '\0' && cmp(s[i], c) != 0)
			i++;
		if (check == i)
			break ;
		result[r] = (char *)malloc(sizeof(char) * (i - check + 1));
		if (!(result[r]))
		{
			free_all(result, r);
			return (1);
		}
		ft_strlcpy(result[r], &s[check], i - check + 1);
		r++;
	}
	result[r] = NULL;
	return (0);
}

char	**ft_split(char *s, char c)
{
	char	**result;
	int		count;

	if (!s)
		return (0);
	count = word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (0);
	if (word_print(s, c, 0, result) == 1)
		return (0);
	else
		return (result);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		size;
	char	*dest;
	int		i;

	size = ft_strlen(s1);
	dest = (char *)malloc(sizeof(char) * (size + 1));
	if (!dest)
		return (0);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;
	int	res;

	i = 0;
	res = ft_strlen(src);
	if (dstsize == 0)
		return (res);
	while ((src[i] != '\0') && (i < dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (res);
}

