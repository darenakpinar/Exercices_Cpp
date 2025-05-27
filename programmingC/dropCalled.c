char *decoder(char const* S){

	int len = strlen(S);
	char *new =(char*)malloc(len * 2);
	int i = 0;
	int j = 0;
	while (S[i] != '\0'){

		if (S[i] == 'x'){
			i+=2;
			continue;
		}else if(S[i] == '+'){
			new[j++] = S[i+1];
			new[j++] = S[i+1];
			i += 2;
		}else{
			new[j++] = S[i++];
		}

	}
	S[j] = '\0';
	return new;
}
