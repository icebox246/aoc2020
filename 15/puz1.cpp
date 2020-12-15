// Project: puz1
#include <bits/stdc++.h>
using namespace std;

int n;
long mem[100000000];
long line[30000007];

int main() {
	ios_base::sync_with_stdio(0);
	/* line[0] = 0; */
	/* line[1] = 3; */
	/* line[2] = 6; */
	/* long cntIndex= 3; */
	line[0] = 0;
	line[1] = 1;
	line[2] = 5;
	line[3] = 10;
	line[4] = 3;
	line[5] = 12;
	line[6] = 19;
	long cntIndex= 7;

	for (int i = 0; i < 100000000; i++) {
		mem[i] = -1;
	}
	for(int i = 0; i < cntIndex-1; i++) {
		mem[line[i]] = i;
	}

	for(;cntIndex < 30000000 + 3;cntIndex++) {
		if(mem[line[cntIndex-1]]!=-1) {
			line[cntIndex] = cntIndex - mem[line[cntIndex-1]] -1;
		}
		else {
			line[cntIndex] = 0;	
		}
		mem[line[cntIndex-1]] = cntIndex-1;
		/* if((cntIndex+1)%1000 == 0) */
			/* cout << cntIndex << ' ' << line[cntIndex] << '\n'; */
	}

	cout << line[30000000-1] << '\n';
}
