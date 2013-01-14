#include "Item.h"
#include "main.h"

using namespace std;

Stats::Stats()
{
	for (int i = 0; i < (sizeof(s)/sizeof(s[0])); i++) {
		s[i] = 0;
	}
}

Stats::~Stats()
{
	delete[] s;
}

IDB::IDB()
{
	items = new vector<Item*>();
	
	Item *Butterfly = new Item();
	Item *Crystalys = new Item();
	Item *Daedalus = new Item();
	Item *Desolator = new Item();
	Item *Rapier = new Item();
	Item *Mjollnir = new Item();
	Item *Monkey = new Item();

	items->push_back(Butterfly);
	items->push_back(Crystalys);
	items->push_back(Daedalus);
	items->push_back(Desolator);
	items->push_back(Rapier);
	items->push_back(Mjollnir);
	items->push_back(Monkey);

	for (int i = 0; i < items->size(); i++) {
		items->at(i)->stats = new Stats();
	}
	
	Butterfly->name = "Butterfly";
	Butterfly->id = BUTTERFLY;
	Butterfly->price = 6000;
	Butterfly->stats->s[DAMAGE] = 30;
	Butterfly->stats->s[ATTACK_SPEED] = 30;
	Butterfly->stats->s[AGI] = 30;
	Butterfly->stats->s[EVASION] = 0.35;
	
	Crystalys->name = "Crystalys";
	Crystalys->id = CRYSTALYS;
	Crystalys->price = 2150;
	Crystalys->stats->s[DAMAGE] = 30;
	Crystalys->stats->s[CRIT_CHANCE] = 0.2;
	Crystalys->stats->s[CRIT_MULT] = 1.75;
	
	Daedalus->name = "Daedalus";
	Daedalus->id = DAEDALUS;
	Daedalus->price = 5550;
	Daedalus->stats->s[DAMAGE] = 81;
	Daedalus->stats->s[CRIT_CHANCE] = 0.25;
	Daedalus->stats->s[CRIT_MULT] = 2.4;
	
	Desolator->name = "Desolator";
	Desolator->id = DESOLATOR;
	Desolator->price = 4100;
	Desolator->stats->s[DAMAGE] = 60;
	Desolator->stats->s[ARMOR_DEBUFF] = 6;
	
	Rapier->name = "Divin Rapier";
	Rapier->id = RAPIER;
	Rapier->price = 6200;
	Rapier->stats->s[DAMAGE] = 300;
	
	Mjollnir->name = "Mjollnir";
	Mjollnir->id = MJOLLNIR;
	Mjollnir->price = 5400;
	Mjollnir->stats->s[DAMAGE] = 24;
	Mjollnir->stats->s[ATTACK_SPEED] = 80;
	Mjollnir->stats->s[DAMAGE_PROC_CHANCE] = 0.25;
	Mjollnir->stats->s[DAMAGE_PROC] = 160;
	
	Monkey->name = "Monkey King Bar";
	Monkey->id = MONKEY;
	Monkey->price = 5400;
	Monkey->stats->s[DAMAGE] = 88;
	Monkey->stats->s[ATTACK_SPEED] = 15;
	Monkey->stats->s[DAMAGE_PROC_CHANCE] = 0.35;
	Monkey->stats->s[DAMAGE_PROC] = 100;
}

IDB::~IDB()
{
	for (int i = 0; i < items->size(); i++) {
		delete[] items->at(i);
	}
	delete[] items;
}