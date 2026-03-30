#include<stdlib.h>
#include<stdio.h>

#define maxNameLength 12
#define maxChatLength 100

void clearConsole() {
	system("cls");
}

char* menu() {
	char* name = malloc(sizeof(char) * maxNameLength + 1);

	printf("What's your name?\n");
	scanf("%12s", name);

	return name;
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