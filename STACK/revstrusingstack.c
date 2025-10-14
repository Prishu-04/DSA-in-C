#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    struct node *next;
} sn;

typedef struct {
    sn *top;
} stack;

void init(stack *s) {
    s->top = NULL;
}

int push(stack *s, char c) {
    sn *curr = malloc(sizeof(sn));
    if (curr == NULL) return 1;
    curr->data = c;
    curr->next = s->top;
    s->top = curr;
    return 0;
}

char pop(stack *s) {
    if (s->top == NULL) {
        printf("Stack underflow!\n");
        exit(1);
    }
    sn* temp = s->top;
    char popped = temp->data;
    s->top = s->top->next;
    free(temp);
    return popped;
}

void rev(stack *s, char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        push(s, str[i]);
    }
}

int main() {
    stack s;
    init(&s);
    char str[100];
    
    printf("Enter your string: ");
    scanf("%s",str);
    
    rev(&s, str);

    printf("Reversed string: ");
    while (s.top != NULL) {
        printf("%c", pop(&s));
    }
    printf("\n");

    return 0;
}