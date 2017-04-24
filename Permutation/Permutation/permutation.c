#define _CRT_SECURE_NO_DEPRECATE

#include<stdio.h>
#include<memory.h>
#include<string.h>

int checkingInputString(char* input, int length);
int factorial(int i);
void swap(char* input, int i, int j);
void permutation(char* input, int length, int n);
void printPermutationElement(int length);

char** perElement;
int count = 0;

int main(void) {

	char input[1000];
	int length = 0;
	int permutationNumber = 0;

	printf("!] INPUT DIFFERENT N NUMBERS OR CHARACTERS. (Max length 99)\n");
	printf("   ex) 1234 or abcse \n");

	scanf("%s", &input);
	length = strlen(input);

	if (checkingInputString(input, length) > 0) {

		permutationNumber = factorial(length);
		perElement = (char**)malloc(sizeof(char*)*permutationNumber);

		for (int i = 0; i < permutationNumber; i++) {
			perElement[i] = (char*)malloc(length+1);
		}

		permutation(input, length, length);
		printPermutationElement(permutationNumber);

		printf("!] Done. \n");
	}
	else {
		printf("!] Error. Incorrect input.");
		exit(1);
	}
	
}

void printPermutationElement(int length) {

	printf("========== Result ==========\n");

	for (int i = 0; i < length; i++) {
		printf("%dth permutation element = %s \n", (i+1), perElement[i]);
	}

	printf("\n");
}

void permutation(char* input, int length, int n) {

	if (n == 1) {
		strcpy(perElement[count], input);
		count++;
	}

	for (int i = 0; i < n; i++) {
		swap(input, i, n - 1);
		permutation(input, length, n - 1);
		swap(input, i, n-1);
	}
}

void swap(char* input, int i, int j) {
	if (i != j) {
		char temp = input[i];
		input[i] = input[j];
		input[j] = temp;
	}
}

int factorial(int i) {
	if (i <= 1) {
		return 1;
	}

	return i * factorial(i-1);
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