#include <stdio.h>
#include <stdlib.h>

int max_jump(int j[], int n){

	int max = 0;
	int best_start = -1;

	for (int start = 0; start < n; start++){
		int count = 0;
		int index = start;

		while (index >= 0 && index < n && j[index] != -1){
			int next = j[index];
			count++;
			if (next == index) break;
			index = next;
		}
		if (count > max) {
			max = count;
			best_start = start;
		}
	}
	return best_start;
}

int main (){
	int jump[6] = {1, -1, 3, 4, 5, 0};
	int result = max_jump(jump, 0);

	printf("%d\n", result);
	return 0;
}


