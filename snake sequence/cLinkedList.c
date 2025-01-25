#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

struct Node *create_node(int data) {
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Invalid Memory Allocation\n");
        exit(1);
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}

struct Node *create_Circular_LinkedList(struct Node *head, int data) {
    struct Node *newnode = create_node(data);
    if (head == NULL) {
        head = newnode;
        newnode->next = head; // Point to itself to form a circle
    } else {
        struct Node *current = head;
        while (current->next != head) {
            current = current->next;
        }
        current->next = newnode;
        newnode->next = head; // Ensure circular linkage
    }
    return head;
}

void display(struct Node *head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node *ptr = head;
    do {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    } while (ptr != head); // Stop when back to the head
    printf("%d ",ptr->data);

    printf("\n");
}

void insertAtIdx(Node **head, int i, int val){
    Node *newNode = create_node(val);
    if(i == 1){
        if(*head == NULL){
            newNode->next = newNode;
            *head = newNode;
        }else{
            Node *temp = *head;
            while(temp->next != *head){
                temp = temp->next;
            }
            newNode->next = *head;
            temp->next = newNode;
            *head = newNode;
        }
        return;
    }
    Node *curr = *head;
    int pos = 1;
    while(pos < i && curr->next!=*head){
        curr = curr->next;
        pos++;
    }
    newNode->next = curr->next;
    curr->next = newNode;
}

int main() {
    struct Node *head = NULL;
    int n, x;
    printf("Enter the number of nodes you want in the LinkedList:\n");
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        printf("Enter the element number %d:\n", i);
        scanf("%d", &x);
        head = create_Circular_LinkedList(head, x);
    }
    display(head);

    insertAtIdx(&head, 1, 10);
    display(head);

    return 0;
}