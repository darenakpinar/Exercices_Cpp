#include <stdio.h>

char *es3 (const char *input){
	int len = strlen(input);
	char *output = malloc(len * 3 + 1); // worst case: all lowercase doubled

	int j = 0;

	for (int i = 0; input[i] != '\0'; i++){
		char c = input[i];
		if (islower(c)){
			output[j++] = c;
			output[j++] = c;
		}else if(issupper(c)){
			output[j++] = towler(c);
		}else if (c == ' '){
			output[j++] = ' ';
		}
	}
	output[j] = '\0';
	return output;
}
