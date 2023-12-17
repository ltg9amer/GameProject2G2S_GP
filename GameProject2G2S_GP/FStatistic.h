#pragma once

enum class EStatisticType {
	Hunger,
	Energy,
	Fun
};

class FStatistic {
	const UINT MaxStatistics = 100;
	UINT Energy;
	UINT Fun;
	UINT Hunger;

public:
	FStatistic();

	~FStatistic();

	const UINT& GetEnergy() const {
		return Energy;
	}

	const UINT& GetFun() const {
		return Fun;
	}

	const UINT& GetHunger() const {
		return Hunger;
	}

	void DecreaseStatistic(const EStatisticType& Type, const UINT Value);

	void IncreaseStatistic(const EStatisticType& Type, const UINT Value);
};

