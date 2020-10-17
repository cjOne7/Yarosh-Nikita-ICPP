#include "../headfiles/Monstrum.h"

int Monstrum::getHp() const {
	return hp;
}

void Monstrum::setHp(int hp) {
	Monstrum::hp = hp;
}

int Monstrum::getMaxHp() const {
	return maxHp;
}

void Monstrum::setMaxHp(int maxHp) {
	Monstrum::maxHp = maxHp;
}
