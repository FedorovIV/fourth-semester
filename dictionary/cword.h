#ifndef cword_h

#define cword_h

struct cword
{
    char *arr;
    int size;
};

void cword_remove(struct cword *word);
int cword_create(struct cword *word, char *s);
int cword_print(struct cword *word);
int cword_print_size(struct cword *word);

#endif