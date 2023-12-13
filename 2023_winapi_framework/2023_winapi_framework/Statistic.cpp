#include "pch.h"
#include "Statistic.h"

Statistic::Statistic() : _hunger(_maxStatistics), _energy(_maxStatistics), _fun(_maxStatistics)
{
}

Statistic::~Statistic()
{
}

void Statistic::IncreaseStatistic(const StatisticType& type, const UINT value)
{
	switch (type)
	{
	case StatisticType::Hunger:
	{
		_hunger = std::clamp(_hunger + value, UINT(0), _maxStatistics);
	}

	break;

	case StatisticType::Energy:
	{
		_energy = std::clamp(_energy + value, UINT(0), _maxStatistics);
	}

	break;

	case StatisticType::Fun:
	{
		_fun = std::clamp(_fun + value, UINT(0), _maxStatistics);
	}

	break;

	default:
		break;
	}
}

void Statistic::DecreaseStatistic(const StatisticType& type, const UINT value)
{
	switch (type)
	{
	case StatisticType::Hunger:
	{
		_hunger = std::clamp(_hunger - value, UINT(0), _maxStatistics);
	}

	break;

	case StatisticType::Energy:
	{
		_energy = std::clamp(_energy - value, UINT(0), _maxStatistics);
	}

	break;

	case StatisticType::Fun:
	{
		_fun = std::clamp(_fun - value, UINT(0), _maxStatistics);
	}

	break;

	default:
		break;
	}
}
