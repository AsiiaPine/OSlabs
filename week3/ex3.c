#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct linked_list linked_list;
typedef struct node node;

struct node {
    struct node *next_node;
    int value;
};

struct linked_list {
    struct node *head;
    int size;
};

node *create_node() {
    node *n = malloc(sizeof(node));
    n->next_node = NULL;
    n->value = -1;
    return n;
}

void init_linked_list(linked_list *list) {
    list->head = NULL;
    list->size = 0;
}

node *get_last_node(linked_list *self) {
    node *n = self->head;
    while (n->next_node != NULL) {
        n = n->next_node;
    }
    return n;
}

void append_node(linked_list *self, int value) {
    if (self->size == 0) {
        self->head = create_node();
        self->head->value = value;
        self->size++;
    } else {
        node *n = get_last_node(self);
        node *new_node = create_node();
        n->next_node = new_node;
        new_node->value = value;
        self->size++;
    }
}

void insert_node(struct linked_list *self, int value, int position) {
    if (position == self->size) {
        append_node(self, value);
        return;
    }

    if (position < self->size) {
        node *current_node = self->head;
        for (int i = 0; i < position; i++)
            current_node = current_node->next_node;
        node *next_node = current_node->next_node;
        node new_node;
        new_node.next_node = next_node;
        current_node->next_node = &new_node;
        self->size++;
    } else {
        printf("Position is out of list");
    }
}

void delete_node(struct linked_list *self, int position) {
    if (position < self->size) {
        node *current_node = self->head;
        for (int i = 0; i < position; i++)
            current_node = current_node->next_node;
        current_node->next_node = current_node->next_node->next_node;
        self->size--;
    } else printf("Position is out of list");
}

void print_list(struct linked_list *self) {
    node *current_node = self->head;
    for (int i = 0; i < self->size; i++) {
        printf("%d ", current_node->value);
        current_node = current_node->next_node;
    }
}

int convertStringToInt(char *str) {
    int value = 0;
    while (*str != '\0') {
        value = value * 10 + (*str - '0');
        str++;
    }
    return value;
}

int main() {
    int arr_len;
    printf("Enter array length: ");
    scanf("%i", &arr_len);
    printf("Waiting for %i elements\n", arr_len);

    int *elements = malloc(arr_len);

    for (int i = 0; i < arr_len; i++) {
        char word[256];
        scanf("%s", word);
        printf("Parsed word '%s'\n", word);
        int number = convertStringToInt(word);
        elements[i] = number;

        if (i != arr_len - 1)
            scanf(" ");
    }

    linked_list list;
    init_linked_list(&list);

    for (int i = 0; i < arr_len; i++) {
        insert_node(&list, elements[i], i);
    }
    printf("Elements: ");
    node *current = list.head;
    for (int i = 0; i < arr_len; i++) {
        printf("%i ", current->value);
        current = current->next_node;
    }
    printf("\n");


    return 0;
}
