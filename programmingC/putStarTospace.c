#include <stdio.h>

char *star (char * a){

	int len = strlen(a);

	for (int i = 0; i < len; i++){
		if (a[i] == ' '){
			a[i] = '**';
		}
	}
	return a;
}
