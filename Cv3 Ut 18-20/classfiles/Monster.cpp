#include "../headfiles/Monster.h"

int Monster::getHp() const {
	return hp;
}

void Monster::setHp(int hp) {
	Monster::hp = hp;
}

int Monster::getMaxHp() const {
	return maxHp;
}

void Monster::setMaxHp(int maxHp) {
	Monster::maxHp = maxHp;
}
