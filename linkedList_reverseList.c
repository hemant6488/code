#include<stdio.h>
#include<stdlib.h>

struct list{
	int data;
	struct list *next;
};

struct list *createNode(int newData){
	struct list *newNode = (struct list *)malloc(sizeof(struct list));
	newNode->data = newData;
	newNode->next = NULL;
}

void insertAtEnd(struct list **head_ref, int newData){
	struct list *newNode = createNode(newData);
	struct list *current = *head_ref;
	
	if(*head_ref == NULL){
		*head_ref = newNode;
	}else{
		while(current->next != NULL)
			current = current->next;
		
		current->next = newNode;
	}
	return;
}

void displayList(struct list *head){
	struct list *current = head;
	if(head == NULL)
	printf("Empty List\n");
	else{
		while(current != NULL){
			printf("%d-> ", current->data);
			current = current->next;
		}
	printf("NULL\n");
	}
}

void reverseList(struct list **head_ref){
	struct list *current=*head_ref, *next, *prev;
	
	next = current->next;
	current->next = NULL;
	prev = current;
	current = next;
	
	while(next != NULL){
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	
	*head_ref = prev;
}

int main(){
	struct list *head = NULL;
	
	insertAtEnd(&head, 21);
	insertAtEnd(&head, 23);
	displayList(head);
	reverseList(&head);
	printf("Reversed List : ");
	displayList(head);
}
