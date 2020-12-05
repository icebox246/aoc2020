//Project: puz1
#include <bits/stdc++.h>
using namespace std;

bool places[8*128];
int highestNum;
int lowestNum=1024;

int main() {
	ifstream inp("in1");

	while(inp.peek()!=EOF) {
		string pass;
		inp >> pass;

		int ci = 0;
		int m;
		int rowm = 0, rowx = 127;
		while(rowx!=rowm) {
			m = (rowm + rowx)/2;
			if(pass[ci] == 'F') {
				rowx = m;
			} else {
				rowm = m+1;
			}
			ci++;
		}
		int colm=0, colx=7;


		while(colx!=colm) {
			m = (colm + colx)/2;
			if(pass[ci] == 'L') {
				colx = m;
			} else {
				colm = m+1;
			}
			ci++;
		}

		int num = rowx * 8 + colx;

		/* cout << num << '\n'; */

		lowestNum = min(num, lowestNum);
		highestNum = max(num, highestNum);
		places[num] = 1;
	}

	/* cout << highestNum; */
	for(int i = lowestNum; i <= highestNum; i++) {
		if(!places[i]) {
			cout << i;
			break;
		}
	}

	inp.close();
}
