#include "game_of_life.h"

bool game_of_life::slucajna_vrijednost() {
	return !((rand() & 1) || (rand() & 1));
}

bool game_of_life::celija_zauzeta(int i, int j) {
	return _generacija[i][j];
}

game_of_life::game_of_life() {
	gen = 0;
	for (int i = 0; i < REDAKA; ++i) {
		for (int j = 0; j < STUPACA; ++j) {
			_generacija[i][j] = slucajna_vrijednost();
		}
	}
}

void game_of_life::sljedeca_generacija() {
	for (int i = 0; i < REDAKA; ++i) {
		for (int j = 0; j < STUPACA; ++j) {
			int susedi = 0;
			for (int l = -1; l <= 1; ++l) {
				for (int m = -1; m <= 1; ++m) {
					susedi += _generacija[l + i][m + j];
				}
			}
			susedi -= _generacija[i][j];
			//mortus
			if ((_generacija[i][j] == 1) && (susedi < 2)) {
				_sljedeca_generacija[i][j] = 0;
			}
			//umre
			else if ((_generacija[i][j] == 1) && (susedi > 3)) {
				_sljedeca_generacija[i][j] = 0;
			}
			//rada
			else if ((_generacija[i][j] == 0) && (susedi == 3)) {
				_sljedeca_generacija[i][j] = 1;
			}
			//ostaje
			else {
				_sljedeca_generacija[i][j] = _generacija[i][j];
			}
		}
	}
	//kopi
	for (int i = 0; i < REDAKA; ++i) {
		for (int j = 0; j < STUPACA; ++j) {
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

void game_of_life::iscrtaj() {
	system("cls");
	for (int i = 0; i < REDAKA; ++i) {
		for (int j = 0; j < STUPACA; ++j) {
			if (_generacija[i][j]) { cout << "*"; }
			else { cout << " "; }
		}
		cout << endl;
	}
	cout << "Generacija: " << ++gen << endl;
}
