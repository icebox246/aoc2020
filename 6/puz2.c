#include <stdio.h>
#include <stdlib.h>

int occ[26];
int T=0;
int t = 0;
void clear_occ() {
	for(int i = 0; i < 26; i++) {
		T+=(occ[i]==t);
		occ[i] = 0;
	}
}

int main() {
	size_t size=32;
	char* line = (char*)malloc(size*sizeof(char));
	while(!feof(stdin)) {
		int len = getline(&line,&size,stdin);
		for(int i = 0; i < len-1; i++) {
			occ[line[i]-'a']++;
		}
		if(len == 1) {
			clear_occ();
			t=0;
			printf("%d\n",T);
		} else
			t++;
	}
	printf("%d\n",t);
}
