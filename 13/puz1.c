#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int target;
int cbD = 1000000000, cbT = 0;

int main () { 
	char buffer[1000];
	int num;
	char numS[100];

	scanf("%d", &target);	
	scanf("%s", buffer);

	for(int i = 0; i < strlen(buffer);i++) {
		/* printf("%c",buffer[i]); */
		switch(buffer[i]) {
			case 'x':

				break;
			case ',':
				num = atoi(numS);
				if(num) {
					/* printf("%d\n",num); */
					if ( target % num == 0 ) {
						cbD = 0;
						cbT = 0;
					}
					else {
						int sA = (target / num + 1) * num;
						if ( sA - target < cbD ) {
							cbD = sA - target;
							cbT = cbD * num;
						}
					}
				}
				memset(numS,0,100);
				break;
			default:
				strncat(numS,buffer+i,1);
		}
	}

	if(strlen(numS)) {
		num = atoi(numS);
		if(num) {
			/* printf("%d\n",num); */
			if ( target % num == 0 ) {
				cbD = 0;
				cbT = 0;
			}
			else {
				int sA = (target / num + 1) * num;
				if ( sA - target < cbD ) {
					cbD = sA - target;
					cbT = cbD * num;
				}
			}
		}
		memset(numS,0,100);
	}


	printf("%d", cbT);
}
