#define _CRT_SECURE_NO_WARNINGS
#include<stdlib.h>
#include<stdio.h>
#include <string.h>

#define maxNameLength 12
#define maxChatLength 100

void clearConsole() {
	system("cls");
}

void clear_input_buffer() { // clears carryover input
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
}

char* menu() {
	char* name = malloc(sizeof(char) * maxNameLength + 1);

	while (1) {
		char* tempName = malloc(20);

		printf("What's your name?\n");
		scanf("%14s", tempName);

		if(strlen(tempName) > 12){
			printf("Please enter a valid name\n");
			free(tempName);
			clear_input_buffer();
		}
		else {
			strcpy(name, tempName);
			free(tempName);
			return name;
		}
	}
	
}

int main(){
	char* username = menu();
	clearConsole();
	char* chatMessage[maxChatLength + 1];

	while(1){
		printf("%s: ", username);
		scanf("%s", chatMessage);
	}
}