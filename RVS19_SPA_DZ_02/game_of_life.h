#pragma once

class game_of_life {
private:
	int gen;
	static const unsigned int STUPACA = 40;
	static const unsigned int REDAKA = 20;
	bool _generacija[REDAKA][STUPACA];
	bool _sljedeca_generacija[REDAKA][STUPACA];
	bool slucajna_vrijednost();
	bool celija_zauzeta(int i, int j);
public:
	game_of_life();
	void sljedeca_generacija();
	void iscrtaj();
};