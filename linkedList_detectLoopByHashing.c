//The program compiles with 2 warnings, because of explicit casting from ptr to int.

#include<stdio.h>
#include<stdlib.h>

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

void insertAtEnd(struct list **head_ref, int newData){
	struct list *current = *head_ref;
	struct list *newNode = createNode(newData);

	if(*head_ref == NULL){
		*head_ref = newNode;
	}else{
		while(current->next != NULL){
			current = current->next;
		}
		current->next = newNode;
	}
	return;
}

void displayList(struct list **head_ref){
	struct list *current = *head_ref;
	if(*head_ref == NULL)
	printf("Empty List\n");
	else{
		while(current != NULL){
			printf("%d-> ", current->data);
			current = current->next;
		}
		printf("NULL\n");
	}
	return;
}


/* Start ~~~~Detect Loop By Hashing~~~~  */

//maintaining a different linked list for the hashed values.
struct hash{
	int address;
	int index;
	struct hash* next;
};

struct hash *createHash(int newAddress, int newIndex){
        struct hash *newHash = (struct hash *) malloc(sizeof(struct hash));
        newHash->address = newAddress;
	newHash->index = newIndex;
        newHash->next = NULL;
        return newHash;
}

void insertAtEndHash(struct hash **head_ref, int newAddress, int newIndex){
        struct hash *current = *head_ref;
        struct hash *newHash = createHash(newAddress, newIndex);

        if(*head_ref == NULL){
                *head_ref = newHash;
        }else{
                while(current->next != NULL){
                        current = current->next;
                }
                current->next = newHash;
        }
        return;
}

int getIndex(struct hash **headHash_ref, int addressToFind){
	struct hash *current = *headHash_ref;
	
	//if the hash table is empty
	if(current == NULL) return -1;

	while(current != NULL){
		if(current->address == addressToFind){
			return current->index;
		}
		current = current->next;
	}
	return -1; //address not found
}

//Detect a loop in linked list function
int detectLoopByHashing(struct list **head_ref){
	struct hash *headHash = NULL;
	struct list *current = *head_ref;
	int index = -1, i=1;
	
	while(current->next != NULL){
		index = getIndex(&headHash, (int)current); //get the index of current node if it already exists in the hash table.
		if(index != -1){
			return i; //loop exists				
		}else{ //if the current node does not exists in the hash table, insert it into the hash table.
			insertAtEndHash(&headHash, (int)current, i);
			i++;			
		} 
		current = current->next;
	}
	return -2; //no loop
	
}

/* End ~~~~Detect Loop By Hashing~~~~~ */
int main(){
	int x = 32, i=0;
	struct list *head = NULL;
	struct list *current;
	insertAtEnd(&head, x);
	insertAtEnd(&head, ++x);
	insertAtEnd(&head, ++x);
	insertAtEnd(&head, ++x);
	insertAtEnd(&head, ++x);
        insertAtEnd(&head, ++x);
        insertAtEnd(&head, ++x);
	
	//introducing a loop in the linked list	
	current = head;
	while(current->next != NULL){
		current = current->next;
	}
	
	//replacing the NULL on the last node with 4th node
	current->next = head->next->next->next;
		
	//invoking the detect loop funciton.
	i = detectLoopByHashing(&head);
	
	if(i==-2)
	printf("No Loop Detected\n");
	else
	printf("Loop Detected at: %d\n", i);

	return 0;
}
