#include<stdio.h>
#include<stdlib.h>

typedef struct list{
	int dataInt;
	struct list *next;
}linkedList;

linkedList *createNode(int newData){
	linkedList *newNode = (linkedList *)malloc(sizeof(linkedList));

	newNode->dataInt = newData;
	newNode->next = NULL;
}

void insertAtEnd(linkedList **head_ref, int newData){
	linkedList *newNode = createNode(newData);
	linkedList *current = *head_ref;
	if(*head_ref == NULL){
		*head_ref = newNode;
		return;
	}else{
		while(current->next != NULL){
			current = current->next;
		}
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
			printf("%d-> ", current->dataInt);
			current = current->next;
		}	
		printf("NULL\n");
	}
}

//delete the whole linked list
void deleteList(linkedList **head_ref){
	linkedList *current = *head_ref;
	linkedList *temp = current;

	if(*head_ref == NULL){
		printf("Empty List.\n");	
		return;
	}

	while(temp->next != NULL){
		current = temp->next;	
		temp = current;
		free(current);
	}

	*head_ref = NULL;
        return;
}

int main(){
	int x = 21;
	struct list *head = NULL;

	insertAtEnd(&head, x);
	insertAtEnd(&head, ++x);
	insertAtEnd(&head, ++x);
	insertAtEnd(&head, ++x);
	insertAtEnd(&head, ++x);
	insertAtEnd(&head, ++x);

	displayList(head);
	deleteList(&head);
	displayList(head);
}
