#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int isEmpty(struct Node *head) {
    return head == NULL;
}

struct Node *insertAtEnd(struct Node *head, int x) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = x;
    ptr->next = NULL;

    if (head == NULL) {
        return ptr;
    }

    struct Node *p = head;
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = ptr;
    return head;
}

struct Node *deleteFromEnd(struct Node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    if (head->next == NULL) { 
        free(head);
        return NULL;
    }

    struct Node *ptr = head; 
    while (ptr->next->next != NULL) {
        ptr = ptr->next;
    }

    free(ptr->next);
    ptr->next = NULL;
    return head;
}

void traversal(struct Node *ptr) {
    while (ptr != NULL) {
        printf("%d --> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node *head = NULL;
    int x, n;

    if (isEmpty(head)) {
        printf("The linked list is empty.\n");
    }

    printf("Enter the number of elements you want in the linked list:");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("Enter the element number %d: ", i);
        scanf("%d", &x);
        head = insertAtEnd(head, x); 
    }

    traversal(head);

    head = deleteFromEnd(head);
    traversal(head);

    return 0;
}
