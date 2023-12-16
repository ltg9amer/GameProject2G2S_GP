#include "pch.h"
#include "Food.h"
#include "Coin.h"
#include "Inventory.h"

void Food::Purchase()
{
	if (Coin::GetInst()->GetValue() >= price)
	{
		Inventory::GetInst()->invenFood.push_back(this);
		Coin::GetInst()->MinusCoinValue(price);
	}
}
