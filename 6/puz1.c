#include <stdio.h>
#include <stdlib.h>

int occ[26];
void clear_occ() {
	for(int i = 0; i < 26; i++) {
		occ[i] = 0;
	}
}

int main() {
	size_t size=32;
	char* line = (char*)malloc(size*sizeof(char));
	int t = 0;
	while(!feof(stdin)) {
		int len = getline(&line,&size,stdin);
		/* printf("%d\n",len); */
		for(int i = 0; i < len-1; i++) {
			t+=(occ[line[i]-'a']++==0);
		}
		if(len == 1) {
			/* t=0; */
			clear_occ();
		}
	}
			printf("%d\n",t);
}
