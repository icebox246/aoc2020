#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int target;
/* int cbD = 1000000000, cbT = 0; */
long cW = 0;
long cM = 1;
int cnID = 0;
int nums[1000];

long long max(long a, long b) {
	return (a<b) ? b : a;
}
long long min(long a, long b) {
	return (a>b) ? b : a;
}

long long gcd(long a, long b) {
	if( a== 0 || b == 0) {
		return max(a,b);
	}
	else {
		long a1 = max(a,b);
		long b1 = min(a,b);
		return gcd(a1 % b1, b1);
	}
}

long lcm(long a, long b) {
	return a * b / gcd(a,b);
}

int main () { 
	char buffer[1000];
	int num;
	char numS[100] = "";

	scanf("%d", &target);	
	scanf("%s", buffer);

	for(int i = 0; i < strlen(buffer);i++) {
		/* printf("%c",buffer[i]); */
		switch(buffer[i]) {
			case 'x':

				break;
			case ',':
				num = atoi(numS);
				nums[cnID] = num;
				memset(numS,0,100);
				cnID++;
				break;
			default:
				strncat(numS,buffer+i,1);
		}
	}

	if(strlen(numS)) {
		num = atoi(numS);
		nums[cnID] = num;
		memset(numS,0,100);
		cnID++;
	}

	nums[cnID] = -1;

	long long mul = 0;
	long long mod = 1;

	for(int i = 0; i < cnID-1; i++) {
		if(!nums[i]) continue;
		/* printf("%d\n", nums[i]); */
		mod = lcm(mod, nums[i]);
		int next = i + 1;	
		while(!nums[next]) next++;
		if (nums[next] == -1 || next >= cnID) break;

		while((mul+ next) % nums[next] != 0) {
			mul += mod;
			/* printf("%lli\n", mul); */
			/* printf("%d\n", nums[next]); */
		}
	}

	printf("Yooo\n");
	printf("%lli\n", mul);
}
