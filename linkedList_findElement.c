#include<stdio.h>
#include<stdlib.h>

struct list{
	int dataInt;
	struct list *next;
};


struct list* createNode(int newData){
	struct list *newNode = (struct list *) malloc (sizeof(struct list));

	newNode->next = NULL;
	newNode->dataInt = newData;
	return newNode;
}

struct list* insertAtEnd(struct list* head, int newData){
	struct list* newNode = createNode(newData);
	struct list* current = head;
	if(head == NULL){
		return newNode;
	}else{
		while(current->next != NULL)
			current = current->next;

		current->next = newNode;
		return head;		
	}

} 

void displayList(struct list* head){
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

//finding a key in the linked list using iterative approach
struct list* findElementIterative(struct list* head, int key){
	struct list* current = head;
	struct list* posHead = NULL; //another linked list that will store the positions of the key, found in the original linked list.
	int pos = 1;
	if(head == NULL){
		printf("Error. Empty List\n");
		return NULL;
	}

	while(current != NULL){
		if(current->dataInt == key){
			posHead = insertAtEnd(posHead, pos); //if the key is found in the original linked list, insert its position in a new linked list.
		}
		pos++;
		current = current->next;
	}
	return posHead;

}



int main(){
	int x = 21;
	struct list* head = NULL;
	struct list* posHead = NULL;
	head = insertAtEnd(head, x);
	head = insertAtEnd(head, ++x);
	head = insertAtEnd(head, ++x);
	head = insertAtEnd(head, x-2);
	head = insertAtEnd(head, ++x);

	displayList(head);

	posHead = findElementIterative(head, 21); // will return a new linked list containing all the positions at which key is present
	if(posHead != NULL){
		printf("Key found at position(Iterative): ");	
		displayList(posHead);
	}	
	else printf("ELement not found\n");
}	
