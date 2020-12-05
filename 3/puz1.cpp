// Project: puz1
#include <bits/stdc++.h>
using namespace std;

vector<string> lines;

int checkSlope(int dx, int dy) {
	int C = 0;

	int cx=0;
	int cy=0;
	int wid = 31;

	for(string line : lines) {
		if(!(cy % dy)) {
			if(line[cx] == '#'){
				C++;
			}
			cx +=dx;
			cx %=wid;
		}
		cy ++;
	}

	return C;
}


int main() {
	ifstream inp("in1");
	while(inp.peek() != EOF) {
		string line;
		getline(inp,line);
		lines.push_back(line);
	}
	inp.close();

	long T = 1;
	T*= checkSlope(1,1);
	T*= checkSlope(3,1);
	T*= checkSlope(5,1);
	T*= checkSlope(7,1);
	T*= checkSlope(1,2);

	cout << T << '\n';
	cout << checkSlope(1,1) << '\n';
	cout << checkSlope(3,1) << '\n';
	cout << checkSlope(5,1) << '\n';
	cout << checkSlope(7,1) << '\n';
	cout << checkSlope(1,2) << '\n';
}
