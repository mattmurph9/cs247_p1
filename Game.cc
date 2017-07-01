#include <iostream>
#include <string>
#include "Game.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "Round.h"

void Game::startGame() {
	initPlayers();

	// deck is preserved throughout rounds. the shuffled deck from a round
	// is the starting deck for the next
	Deck deck;
	deck.shuffle();
	deck.print();

	// deal
	for (int i = 0; i < 4; i++) {
		players[i]->GetCards(i, deck);
	}

	Round roundInstance(players, deck);
	roundInstance.startRound();
}

void Game::initPlayers() {
	// instantiating players
	for (int i = 0; i < 4; i++) {
		std::string in;
		std::cout << "Is player " << i+1 << " a human(h) or a computer(c)?" << std::endl;
		std::cin >> in;
		if (in.compare("h") == 0) {
			addHumanPlayer();
		} else if (in.compare("c") == 0) {
			addComputerPlayer();
		}
	}
}

void Game::addHumanPlayer() {
	int id = players.size();
	players.push_back(std::make_shared<HumanPlayer>(id));
}

void Game::addComputerPlayer() {
	int id = players.size();
	players.push_back(std::make_shared<ComputerPlayer>(id));
}

std::shared_ptr<Player> Game::GetPlayer(int playerNum)
{
	return players[playerNum];
}
