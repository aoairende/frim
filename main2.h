#ifndef MAIN2_H
#define MAIN2_H

/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: length of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;

/**
 * struct tokenize_cmd_ops - commands and logical ops tokens
 * @cmd_tokens: commands tokens
 * @ops_tokens: logical ops tokens
 */
typedef struct tokenize_cmd_ops
{
	char **cmd_tokens;
	char **ops_tokens;
} cmd_ops;

int is_only_spaces(char *s);
void free_cmd_ops(cmd_ops *cls);
void callback(int signum);
void _free(char *s);
void free_all(char **argv, list_t *head_argv, FILE *stream,
	      char ***tokens, int exit_code);

#endif
