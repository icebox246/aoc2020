//Project: puz1
#include <bits/stdc++.h>
using namespace std;

string* current, *last;
int height = 0;
int wid = 0;

bool check(int x, int y, int dx, int dy) {
	int cx = x + dx;
	int cy = y + dy;

	while(cx >=1 && cy >= 1 && cx <= wid && cy <= height) {
		if(last[cy][cx] == '#') {
			return 1;
		}
		else if(last[cy][cx] == 'L') {
			return 0;
		}
		cx+=dx;
		cy+=dy;
	}

	return 0;
}

int main() {
	ifstream inp("in1");
	current = new string[100];
	last = new string[100];

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
				for(int i = -1; i <= 1; i++){
					for(int j = -1; j <= 1; j++){
						if(j == 0 && i == 0) continue;
						if(check(x,y,i,j)) neighbourC++;
					}
				}

				if(last[y][x] == 'L' && neighbourC == 0) current[y][x] = '#';
				if(last[y][x] == '#' && neighbourC >= 5) current[y][x] = 'L';
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
