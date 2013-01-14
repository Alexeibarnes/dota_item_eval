#include "Hero.h"
#include <math.h>

using namespace std;

Hero::Hero()
{
	database = new IDB();
	for (int i = 0; i < 6; i++) {
		items[i] = NULL;
	}

	damage = 0;
	money = 0;
	type = NONE;
}

Hero::~Hero()
{
	delete[] database;
	delete[] items;
}

void Hero::set_damage(int damage)
{
	this->damage = damage;
	e_damage = damage;
}

void Hero::set_money(int money)
{
	this->money = money;
	money_left = money;
}

void Hero::set_type(int type)
{
	this->type = type;
}

float Hero::damage_of(int i)
{
	float dmg = e_damage;
	float base = 0;
	
	if (type != 0)
		dmg += database->items->at(i)->stats->s[type];
	dmg += database->items->at(i)->stats->s[DAMAGE];
	base = dmg;

	dmg += base * database->items->at(i)->stats->s[CRIT_CHANCE] * database->items->at(i)->stats->s[CRIT_MULT];
	dmg += database->items->at(i)->stats->s[DAMAGE_PROC_CHANCE] * database->items->at(i)->stats->s[DAMAGE_PROC];
	if (database->items->at(i)->stats->s[ARMOR_DEBUFF] == 6)
		dmg += base * 0.31;

	return dmg - e_damage;
}

float Hero::evaluate(int i)
{
	float value = damage_of(i);

	value = value / database->items->at(i)->price;

	return value;
}

bool Hero::best_item_greedy()
{
	int slot = 0;
	while (slot < 7) {
		if (slot < 6)
			if (items[slot] == NULL)
				break;
		slot++;
	}
	if (slot == 6)
		return false;


	bool can_buy_any = false;
	for (int i = 0; i < database->items->size(); i++)
		if (database->items->at(i)->price < money)
			can_buy_any = true;

	if (!can_buy_any)
		return false;

	float value = evaluate(0) - 1;
	int item_id = -1;
	for (int i = 0; i < database->items->size(); i++) {
		if (money_left < database->items->at(i)->price)
			continue;

		float prev = value;
		value = max<float>(value, evaluate(i));
		if (value != prev)
			item_id = i;
	}

	if (item_id < 0)
		return false;

	money_left -= database->items->at(item_id)->price;
	e_damage += damage_of(item_id);
	items[slot] = database->items->at(item_id);
	return true;
}