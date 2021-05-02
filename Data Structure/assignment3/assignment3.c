#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct player{
	struct player* prev;
	int win;
	int lose;
	struct player* next;
} PLAYER;

typedef struct {
	PLAYER* head;
}listhead;

listhead* createHList(void) {
	listhead* HEAD;
	HEAD = (listhead*)malloc(sizeof(listhead));
	HEAD->head = NULL;
	return HEAD;
}

void createNode(listhead *HEAD) {
	PLAYER* newpl;
	newpl = (PLAYER*)malloc(sizeof(PLAYER));
	newpl->win = 0;
	newpl->lose = 0;

	PLAYER* tmp;

	if(HEAD->head == NULL) { // empty list
		newpl->next = newpl;
		newpl->prev = newpl;
		HEAD->head = newpl;
	}
	else { // not empty list
		tmp = HEAD->head;
		while(tmp->next != HEAD->head) {
			tmp = tmp->next;
		}
		newpl->next = tmp->next;
		tmp->next = newpl;
		newpl->prev = tmp;
		HEAD->head->prev = newpl;
		tmp = NULL;
	}
}

void insertNode(listhead *HEAD, PLAYER *pre) {
	PLAYER* newpl;
	newpl = (PLAYER*)malloc(sizeof(PLAYER));
	newpl->win = 0;
	newpl->lose = 0;

	newpl->next = pre->next;
	pre->next = newpl;
	newpl->prev = pre;
	newpl->next->prev = newpl;
}

void deleteNode(listhead *HEAD, PLAYER* old) {
	if(HEAD->head == NULL) return; // empty list

	if(HEAD->head->next == HEAD->head) { // only one node
		free(HEAD->head);
		HEAD->head = NULL;
		return;
	}

	else if(old == NULL) return;

	else {
		if(HEAD->head == old) { // when HEAD pointing a deleted node
			HEAD->head = old->next;
		}
		old->prev->next = old->next;
		old->next->prev = old->prev;
		free(old);
	}
}

void deleteList(listhead *HEAD) {
	PLAYER* tmp;
	if(HEAD->head == NULL) return; // case of empty list
	else {
		while(HEAD->head != NULL) {
			tmp = HEAD->head;
			tmp->prev->next = NULL;
			HEAD->head = tmp->next;

			free(tmp);
		}	
	}				
}
		

void printNode(listhead *HEAD) {
	PLAYER* tmp;
	tmp = HEAD->head;
	int i = 1;
	if(HEAD->head == NULL) { // empty list
		printf("NULL\n");
	}

	else {
		while(1) {
			if(tmp->next == HEAD->head) {
				printf("prev : %p [ %d. PLAYER : %p WIN = %d, LOSE = %d ] next : %p ->\n", tmp->prev, i, tmp,  tmp->win, tmp->lose, tmp->next);
				return;
			}
			printf("prev : %p [ %d. PLAYER : %p WIN = %d, LOSE = %d ] next : %p ->\n", tmp->prev, i, tmp, tmp->win, tmp->lose, tmp->next);
			tmp = tmp->next;
			i++;
		}
	}
}

void RSP(listhead* HEAD, PLAYER *pre);

int main(int argc, char *argv[]) {
	int num, i;
	num = atoi(argv[1]);

	listhead* HEAD;
	PLAYER* computer_ptr;

	HEAD = createHList();

	for(i = 0; i < num; i++) {
		createNode(HEAD);
	}
	computer_ptr = HEAD->head;

	if(num > 0) {
		RSP(HEAD, computer_ptr);
	}
	else {
		printNode(HEAD);
	}

	deleteList(HEAD);
	return 0;
}

void RSP(listhead* HEAD, PLAYER* pre) {
	int player, computer;
	PLAYER* play;
	
	while(1) {
		printf("\n> Select (1. Scissor 2. Rock 3. Paper 4. Quit) ? ");
		scanf("%d", &player);
		
		srand(time(NULL));
		computer = rand() % 3 + 1;
		

		if(player == 4) {
			printf("Quit\n");
			break;
		}

		if((player - computer) == 1 || (computer - player) == 2) {
			pre->win++;
			printf("Computer Lose. Now move to the right of the node..\n");
			if(pre->win >= 3) {
				pre->win = 0;
				insertNode(HEAD, pre);
			}
			pre = pre->next;
		}

		else if((player - computer) == 2 || (computer - player) == 1) {
			pre->lose++;
			printf("Computer Win. Now move to the left side of the node..\n");
			if(pre->lose >= 3) {
				play = pre;
				pre = pre->next;
				deleteNode(HEAD, play);
			}
			pre = pre->prev;
		}

		else if(computer == player) {
			printf("Again\n");
			continue;
		}

		else { // case of wrong type
			continue;
		}

		printf("\n");
		printNode(HEAD);
		if(HEAD->head == NULL) { // empty list
			printf("No player for playing. End the game.\n");
			break;
		}
	}
}
