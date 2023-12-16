#pragma once

enum class StatisticType
{
	Hunger,
	Energy,
	Fun
};

class Statistic
{
private:
	const UINT _maxStatistics = 100;
	UINT _hunger;
	UINT _energy;
	UINT _fun;

public:
	Statistic();

	~Statistic();

	const UINT& GetHunger() const
	{
		return _hunger;
	}

	const UINT& GetEnergy() const
	{
		return _energy;
	}

	const UINT& GetFun() const
	{
		return _fun;
	}

	void IncreaseStatistic(const StatisticType& type, const UINT value);

	void DecreaseStatistic(const StatisticType& type, const UINT value);
};

