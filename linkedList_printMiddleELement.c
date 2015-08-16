#include<stdio.h>
#include<stdlib.h>

struct list{
	int dataInt;
	struct list *next;
};

struct list *createNode(int dataNew){
	struct list *newNode = (struct list *)malloc(sizeof(struct list));
	newNode->dataInt = dataNew;
	newNode->next = NULL; 
	return newNode;
}

struct list *insertAtEnd(struct list *head, int dataNew){
	struct list *newNode = createNode(dataNew);	
	struct list *current = head;
	if(head == NULL){
		return newNode;
	}else{
		while(current->next != NULL){
			current = current->next;
		}
		current->next = newNode;
	}
	return head;
}

void displayList(struct list *head){
	struct list *current = head;
	if(head == NULL)
		printf("Empty List");
	else{
		while(current != NULL){
			printf("%d-> ", current->dataInt);
			current = current->next;
		}	
		printf("NULL\n");
	}
}


//Logic : initialize two pointers. Everytime, increment ptr1 by 1 and ptr2 by 2, so this way when ptr2 reaches NULL, ptr1 will be at the mid element.
struct list *getMiddleNode(struct list *head){
	struct list *ptr1 = head, *ptr2 = head;

	//Ensure that list has more than 2 elements
	if(ptr1->next == NULL){
		printf("List contains only 1 node.");
		return ptr1;	
	}else if(ptr1->next->next == NULL){
		printf("List contains only 2 nodes.");
		return ptr1;
	}

	while(ptr2!=NULL){
		if(ptr2->next !=NULL){
			ptr2 = ptr2->next->next;
		}else break;
		ptr1 = ptr1->next;	
	}
	return ptr1;
}

int main(){
	int x = 21;
	struct list *head = NULL;

	head = insertAtEnd(head, x);
	head = insertAtEnd(head, ++x);
	head = insertAtEnd(head, ++x);
	head = insertAtEnd(head, ++x);
	head = insertAtEnd(head, ++x);
	head = insertAtEnd(head, ++x);
	displayList(head);
	printf("Middle Element is : %d\n", getMiddleNode(head)->dataInt);
	return 0;
}
