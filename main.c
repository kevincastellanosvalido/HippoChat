#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include<sys/socket.h>

#define maxNameLength 12
#define maxChatLength 100

void clearConsole(){ // clears terminal
	system("clear");
}

void clear_input_buffer() { // clears carryover input
	int ch;
	while ((ch = getchar()) != '\n' && ch != EOF);
}

void clear_newline_char(char string[]){ // gets rid of the newline character
	string[strcspn(string, "\n")] = 0;
}

char* menu() {
	char* name = malloc(sizeof(char) * maxNameLength + 1);

	while (1) {
		char* tempName = malloc(20);

		printf("What's your name?\n");
		fgets(tempName, maxNameLength, stdin);
		clear_newline_char(tempName);

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
	char chatMessage[maxChatLength + 1];

	while(1){
		printf("%s: ", username);
		fgets(chatMessage, maxChatLength, stdin);
		clear_newline_char(chatMessage);

		if (strcmp(chatMessage, "/quit") == 0){
			exit(1);
		}
	}
}
