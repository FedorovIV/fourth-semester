#ifndef to_give_a_massive_of_char_from_file_h

#define to_give_a_massive_of_char_from_file_h

struct massive_of_char *to_give_a_massive_of_char_from_file(char *path, struct massive_of_char *text);
int to_remove_massive_of_char(struct massive_of_char *text);

struct massive_of_char{
    char *arr;
    int size;
    int num_of_char;
};

#endif