#include "pch.h"
#include "Food.h"
#include "Coin.h"
#include "Inventory.h"

void Food::Purchase()
{
	if (Coin::GetInstance()->GetValue() >= price)
	{
		Inventory::GetInstance()->invenFood.push_back(this);
		Coin::GetInstance()->MinusCoinValue(price);
	}
}
