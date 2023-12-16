#include "Level.h"
#include "pch.h"

#pragma once
class Food;
class Inventory
{
	SINGLE(Inventory);
public:
	vector<Food*> invenFood;
};