/*
Problem: Given only the address of the node that needs to be deleted, delete the node
 */

#include <stdio.h>
#include <stdlib.h>

struct list{
	int dataInt;
	struct list *next;
};

struct list *createNode(int newData){
	struct list *newNode = (struct list *) malloc(sizeof(struct list));
	newNode->dataInt = newData;
	newNode->next = NULL;
	return newNode;
}

struct list *insertAtEnd(struct list *head, int newData){
	struct list *newNode = createNode(newData);
	struct list *current = head;

	if(head == NULL){
		return newNode;	
	}	else{
		while(current->next != NULL){
			current = current->next;
		}
		current->next = newNode;
		return head;
	}
}

void displayList(struct list *head){
	struct list* current = head;

	if(head ==NULL){
		printf("Empty List");
		return;
	}
	while(current != NULL){
		printf("%d-> ", current->dataInt);
		current = current->next;
	}
	printf("NULL\n");

}


//Delete a node, given only its address
int deleteNode(struct list *node){
	int temp = node->dataInt;
	node->dataInt = node->next->dataInt;
	node->next = node->next->next;
	free(node->next);
	return temp;
}

int main(){
	int x=21;
	struct list *head = NULL;
	head = insertAtEnd(head, x);
	head = insertAtEnd(head, ++x);
	head = insertAtEnd(head, ++x);
	head = insertAtEnd(head, ++x);
	displayList(head);

	printf("Deleted data: %d \n", deleteNode(head->next->next));
	
	displayList(head);
	return 0;
}
