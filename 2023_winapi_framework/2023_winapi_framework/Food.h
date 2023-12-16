#pragma once

class Food
{
private:
	int codeName;
public:
	int price;
public:
	int fullness;
public:
	void Purchase();
public:
	int GetCodeName()
	{
		return codeName;
	}
	int SetCodeName(int value)
	{
		codeName = value;
	}
};

