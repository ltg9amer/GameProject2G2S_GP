#pragma once
class Coin
{
	SINGLE(Coin);
private:
	int CoinValue = 10;
public:
	void Init();
	void PlusCoinValue(int value)
	{
		CoinValue += value;
	}
	void MinusCoinValue(int value)
	{
		if (CoinValue > 0)
		{
			CoinValue -= value;
		}
	}
	int GetValue()
	{
		return CoinValue;
	}
};

