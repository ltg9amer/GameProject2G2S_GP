#include "Level.h"
#include "pch.h"

#pragma once
class Food;
class Inventory
{
	SINGLETON(Inventory);
public:
	vector<Food*> invenFood;
};