#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define fast ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr)
#define endl "\n"
using namespace std;

//1063 bj
int main() {
	fast;
	string king, dol;
	int a;
	int ch[8][8] = { 0, };
	cin >> king >> dol >> a;
	int k1 = king[0] - 65, k2 = king[1] - 49, d1 = dol[0] - 65, d2 = dol[1] - 49;
	ch[k2][k1] = 2;
	ch[d2][d1] = 1;
	while (a--) {
		int mem = ch[k2][k1];
		string Move;
		cin >> Move;
		if (Move[0] == 'R') {
			if (Move.size() != 2 && !(k1 + 1 > 7)) {
				ch[k2][k1++] = 0;
				if (ch[k2][k1] == 1) {
					if (k1 + 1 > 7) {
						ch[k2][--k1] = mem;
						continue;
					}
					ch[k2][k1 + 1] = ch[k2][k1];
				}
				ch[k2][k1] = mem;
			}
			else if (Move[1] == 'T') {
				if (!(k2 + 1 > 7 || k1 + 1 > 7)) {
					ch[k2++][k1++] = 0;
					if (ch[k2][k1] == 1) {
						if (k1 + 1 > 7 || k2 + 1 > 7) {
							ch[--k2][--k1] = mem;
							continue;
						}
						ch[k2 + 1][k1 + 1] = ch[k2][k1];
					}
					ch[k2][k1] = mem;
				}
			}
			else {
				if (!(k2 - 1 < 0 || k1 + 1 > 7)) {
					ch[k2--][k1++] = 0;
					if (ch[k2][k1] == 1) {
						if (k2 - 1 < 0 || k1 + 1 > 7) {
							ch[++k2][--k1] = mem;
							continue;
						}
						ch[k2 - 1][k1 + 1] = ch[k2][k1];
					}
					ch[k2][k1] = mem;
				}
			}
		}
		else if (Move[0] == 'L') {
			if (Move.size() != 2 && !(k1 - 1 < 0)) {
				ch[k2][k1--] = 0;
				if (ch[k2][k1] == 1) {
					if (k1 - 1 < 0) {
						ch[k2][++k1] = mem;
						continue;
					}
					ch[k2][k1 - 1] = ch[k2][k1];
				}
				ch[k2][k1] = mem;
			}
			else if (Move[1] == 'T') {
				if (!(k2 + 1 > 7 || k1 - 1 < 0)) {
					ch[k2++][k1--] = 0;
					if (ch[k2][k1] == 1) {
						if (k1 - 1 < 0 || k2 + 1 > 7) {
							ch[--k2][++k1] = mem;
							continue;
						}
						ch[k2 + 1][k1 - 1] = ch[k2][k1];
					}
					ch[k2][k1] = mem;
				}
			}
			else {
				if (!(k2 - 1 < 0 || k1 - 1 < 0)) {
					ch[k2--][k1--] = 0;
					if (ch[k2][k1] == 1) {
						if (k2 - 1 < 0 || k1 - 1 < 0) {
							ch[++k2][++k1] = mem;
							continue;
						}
						ch[k2 - 1][k1 - 1] = ch[k2][k1];
					}
					ch[k2][k1] = mem;
				}
			}
		}
		else if (Move[0] == 'B') {
			if (!(k2 - 1 < 0)) {
				ch[k2--][k1] = 0;
				if (ch[k2][k1] == 1) {
					if (k2 - 1 < 0) {
						ch[++k2][k1] = mem;
						continue;
					}
					ch[k2 - 1][k1] = ch[k2][k1];
				}
				ch[k2][k1] = mem;
			}
		} 
		else if (Move[0] == 'T') {
			if (!(k2 + 1 > 7)) {
				ch[k2++][k1] = 0;
				if (ch[k2][k1] == 1) {
					if (k2 + 1 > 7) {
						ch[--k2][k1] = mem;
						continue;
					}
					ch[k2 + 1][k1] = ch[k2][k1];
				}
				ch[k2][k1] = mem;
			}
		}
	}
	string Array[2];
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (ch[i][j] == 2) Array[0] = char(j + 65) + to_string(i + 1);
			else if (ch[i][j] == 1) Array[1] = char(j + 65) + to_string(i + 1);
		}
	}
	cout << Array[0] << endl;
	cout << Array[1];
}