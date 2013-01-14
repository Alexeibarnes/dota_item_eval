#pragma once
#include <stdlib.h>
#include <vector>

static enum Item_List
{
	BUTTERFLY,
	CRYSTALYS,
	DAEDALUS,
	DESOLATOR,
	RAPIER,
	MJOLLNIR,
	MONKEY
} item_ids;

enum stat_order
{
	DAMAGE, STR, AGI, INT, ARMOR, ARMOR_DEBUFF, ATTACK_SPEED, EVASION, CRIT_CHANCE, CRIT_MULT, DAMAGE_PROC_CHANCE, DAMAGE_PROC, TOTAL_STATS
};

struct Item_Entry
{
	char *name;
	int id;
};

struct Item_DB
{
	Item_Entry *i;
};

struct Stats
{
	float s[TOTAL_STATS];

	Stats();
	~Stats();
};

struct Item
{
	Stats *stats;
	char *name;
	int price;
	int id;
};

struct IDB
{
	std::vector<Item*> *items;

	IDB();
	~IDB();
};