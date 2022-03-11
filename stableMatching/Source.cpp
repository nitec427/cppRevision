#include <iostream>
#include <cstdio>
#include <queue>
#include <string.h>
#pragma warning(suppress : 4996)
using namespace std;

int ranking[5][5]; // Ranking gives the ranking of each man in the preference list of each woman
int man_pref[5][5]; // man's preference list
int woman_pref[5][5]; // woman's preference list
int nextarr[5]; // which woman will be proposed for each man
int matches[5]; // the current engagement of each woman

int main() {
	queue<int> freeMen;
	int count, i, j, w, m, current_woman, current_man;
	cin >> count;
	for (i = 1; i <= count; i++) {
		cin >> w;
		for (j = 1; j <= count; j++) {
			cin >> woman_pref[w][j];
		}
	} // initialize the preference list of woman

	for (i = 1; i <= count; i++) {
		cin >>m;
		for (j = 1; j <= count; j++) {
			cin >> man_pref[m][j];
		}
	} // initialize the preference list of man

	for (i = 1; i <= count; i++)
		for (j = 1; j <= count; j++)
			ranking[i][woman_pref[i][j]] = j; // initialize ranking

	memset(matches, 0, (count + 1) * sizeof(int));

	for (i = 1; i <= count; i++) {
		freeMen.push(i);
		nextarr[i] = 1;
	}

	while (!freeMen.empty()) {
		current_man = freeMen.front();
		current_woman = man_pref[current_man][nextarr[current_man]];

		if (matches[current_woman] == 0) {
			matches[current_woman] = current_man;
			freeMen.pop();
		}
		else if (ranking[current_woman][current_man] < ranking[current_woman][matches[current_woman]]) {
			int ex_man = matches[current_woman];
			freeMen.pop();
			matches[current_woman] = current_man;
			freeMen.push(ex_man);
		}

		nextarr[current_man]++;
	}

	for (i = 1; i <= count; i++) {
		cout << "man :"  << matches[i] << "woman : " << i <<  "get married" << endl;
	}

}