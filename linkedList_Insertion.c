#include <stdio.h>
#include <stdlib.h>

struct list{
	int data;
	struct list *next;
};

/* Typedef "struct list" to linkedList

//one way
typedef struct list linkedList;

//other way
typedef struct list{
	int data;
	struct list *next;
} linkedList;


*/

struct list *createNode(int newData){
	struct list *node = (struct list *) malloc(sizeof(struct list));
	//The C library function void *malloc(size_t size) allocates the requested memory and returns a pointer to it.

	node->next = NULL;
	node->data = newData;
	return node;
}

struct list *insertAtEnd(struct list *head, int newData){
	struct list *newNode = createNode(newData); //create a new node and get its address into a pointer.
	struct list *current = head;

	if(head == NULL){
		// if the linked list is empty.
		head = newNode;
	} else {
		while(current->next != NULL){
			current = current->next;
		}
		current->next = newNode;
	}

	return head;
}

struct list *insertAtBeg(struct list *head, int newData){
	struct list *newNode = createNode(newData);
	
	if(head == NULL){
		head = newNode;
	}else{
		struct list *temp = head;
		newNode->next = temp;
		head = newNode;
	}
	return head;
}

struct list *insertAtNode(struct list *head, int pos, int newData){
	struct list *newNode = createNode(newData);
	struct list *current = head;

	if(head == NULL){
		printf("Error, Empty List.");
	}
	else{
		struct list *temp=NULL;
		int i=0;
		for(i=0; i<pos-2; i++){
			current = current->next;
			if(current == NULL){
				printf("Error, Position does not exists yet.");
				return head;
			}
		}
		temp = current->next;
		current->next = newNode;
		newNode->next = temp;
	}
	return head;
}

void displayList(struct list *head){
	struct list *current = head;
	if(head==NULL) printf("Empty List");
	else	
	while(current != NULL){
		printf(" %d ->", current->data);
		current = current->next;
	}
	printf("NULL\n");
}

int main(){
	int data = 25;
	int data2 = 50; 
	struct list *head=NULL;

	head = insertAtEnd(head, data);
	head = insertAtEnd(head, ++data);
	head = insertAtEnd(head, ++data);
	head = insertAtEnd(head, ++data);
	head = insertAtBeg(head, data2);
	head = insertAtBeg(head, 98);
	head = insertAtNode(head, 5, 21);

	displayList(head);

}


