//Project: puz1
#include <bits/stdc++.h>
using namespace std;

string* current, *last;

int main() {
	ifstream inp("in1");
	current = new string[100];
	last = new string[100];
	int height = 0;
	int wid = 0;

	while(inp.peek() != EOF) {
		height ++;
		string s;
		getline(inp,s);
		last[height] = " " + s + " ";
		current[height] = " " + s + " ";
		wid = last[height].size();
	}

	/* for(int i = 0; i < wid;i++) { */
	/* 	last[0] += "."; */
	/* 	last[height+1] += "."; */
	/* } */

	/* cout << wid << " " << height << '\n'; */

	int changeC = 1;
	int occC = 0;
	int itC = 0;

	while(changeC) {
		/* cout << itC << '\n'; */
		itC++;
		changeC = 0;
		occC = 0;
		for(int x = 1; x < wid - 1; x++) {
			for(int y = 1; y < height + 1; y++) {
				current[y][x] = last[y][x];
				if(last[y][x] == '.') continue;
				int neighbourC = 0;
				for(int i = x-1; i <= x+1; i++){
					for(int j = y-1; j <= y+1; j++){
						if(j == y && i == x) continue;
						if(last[j][i] == '#') neighbourC++;
					}
				}

				if(last[y][x] == 'L' && neighbourC == 0) current[y][x] = '#';
				if(last[y][x] == '#' && neighbourC >= 4) current[y][x] = 'L';
				if(last[y][x] != current[y][x]) changeC++;
				if(current[y][x] == '#') occC++;
			}
		}
		/* for(int y = 0; y < height +  2; y++) { */
		/* 	cout << current[y] << '\n'; */
		/* } */
		
		string *temp = last;
		last = current;
		current = temp;
	}

	cout << occC;
}
