#define _CRT_SECURE_NO_DEPRECATE

#include<stdio.h>
#include<memory.h>

int checkingInputString(char* input, int length);

int main(void) {

	char* input;
	int length = 0;

	printf("!] INPUT DIFFERENT N NUMBERS OR CHARACTERS.\n");
	printf("   ex) 1234 or abcse \n");

	scanf("%s", &input);
	length = sizeof(input) / sizeof(char);

	if (checkingInputString(input, length) > 0) {

	}
	else {
		printf("!] Error. Incorrect input.");
		exit(1);
	}
	
}

int checkingInputString(char* input, int length) {
	int result = 1;
	char temp;

	for (int i = 1; i < length; i++) {
		temp = input[i];
		for (int j = 0; j < i; j++) {
			if (temp == input[j]) {
				result = 0;
				break;
			}
		}
	}
	
	return result;
}