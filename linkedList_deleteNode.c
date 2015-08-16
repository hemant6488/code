#include <stdio.h>
#include <stdlib.h>

struct list{
	int data;
	struct list *next;
};

struct list *createNode(int newData){
	struct list *newNode = (struct list *) malloc(sizeof(struct list));

	newNode->data = newData;
	newNode->next = NULL;	
	return newNode;
}

struct list *insertAtEnd(struct list *head, int newData){
	struct list *newNode = createNode(newData);
	struct list *current = head;

	if(head==NULL){
		return newNode; 
	}else{
		while(current->next!=NULL){ //traverse the list till the end
			current = current->next;
		}
		current->next = newNode;
		return head;	
	}

}


//Deletion of node from linked list.

int deleteNodeAtPos(struct list *head, int pos){
	int i=0, deletedData=0;
	struct list *current = head, *toBeDeleted=NULL; //intialize a temporary variable for the use of traversing.
	for(i=1; i<pos-1; i++){ //traverse to the (pos-1)th node
		current = current->next;
		if(current == NULL){
			printf("\nPosition Not Found.\n");
			return -1;
		}
	}

	toBeDeleted = current->next;
	deletedData = toBeDeleted->data;

	//once we reach the node before the node which needs to be deleted, update the next ptr and free up the space
	
	current->next = current->next->next;

	free(toBeDeleted);
	return deletedData;
}

struct list *deleteNodesContaining(struct list *head, int delVal){
	struct list *current = head, *toBeDeleted=NULL;

	if(current->data == delVal){//if the head contains the value that needs to be deleted
		toBeDeleted=head;
		head = current->next;
		free(toBeDeleted);
		head = deleteNodesContaining(head, delVal);
		return head;
	}else{
		while(current->next != NULL){
			if(current->next->data == delVal){
				toBeDeleted = current->next;
				current->next = current->next->next;
				free(toBeDeleted);
			}
			current = current->next;
		}
	}
	return head;
}


void displayList(struct list *head){
	while(head != NULL){
		printf("%d-> ", head->data);
		head = head->next;
	}
	printf("NULL\n");
}

int main(){
	int x = 21;
	struct list *head = NULL;

	head = insertAtEnd(head, x);
	head = insertAtEnd(head, x);
	head = insertAtEnd(head, x);
	head = insertAtEnd(head, ++x);
	head = insertAtEnd(head, ++x);
	head = insertAtEnd(head, ++x);
	head = insertAtEnd(head, ++x);
	head = insertAtEnd(head, ++x);
	head = insertAtEnd(head, ++x);
	head = insertAtEnd(head, ++x);
	head = insertAtEnd(head, ++x);
	displayList(head);
	
	//delete by position
	printf("Deleted Data : %d\n", deleteNodeAtPos(head, 3));
	displayList(head);

	//delete by value (all the nodes containing this value will be deleted)
	head = deleteNodesContaining(head, 25);
	head = deleteNodesContaining(head, 21);
	displayList(head);

}