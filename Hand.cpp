#include "Hand.h"
#include <string>
/**
 * @brief Constructs a new instance of the Hand class.
 * used to keep track of the player's hand in the game of BlackJack.
*/
Hand::Hand() {
	aces = 0;
	score = 0;
	altScore = 0;
	n = 0;
	end = false;
	for (int i = 0; i < 10; i++) nCards[i] = -1;
}