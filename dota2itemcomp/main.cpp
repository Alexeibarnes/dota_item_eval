#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include "main.h"
#include "Item.h"
#include "Hero.h"

int main(void)
{
	Hero *h;
	h = new Hero();
	h->set_type(AGILITY);
	h->set_damage(DAMAGE_TEST);
	h->set_money(MONEY_TEST);

	int i = 0;
	while (h->best_item_greedy() && i < 6) {
		fprintf(stdout, "Item  : %s\nDamage: %f\nMoney : %d\nValue : %f\n\n", h->items[i]->name, h->e_damage, h->money_left, h->evaluate(h->items[i]->id));
		i++;
	}

	std::cin.get();
	return 0;
}