#pragma once
#include "Item.h"

enum Types
{
	NONE,
	STRENGTH,
	AGILITY,
	INTELEGENCE
};

struct Hero
{
	Item *items[6];
	IDB *database;
	int damage;
	int money;
	int type;
	
	float e_damage;
	int money_left;

	Hero();
	~Hero();

	void set_damage(int damage);
	void set_money(int money);
	void set_type(int type);

	int get_money_left();
	int get_effective_damage();
	
	float damage_of(int i);
	float evaluate(int i);

	bool best_item_greedy();
};