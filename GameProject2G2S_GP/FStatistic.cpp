#include "pch.h"
#include "FStatistic.h"

FStatistic::FStatistic() : Hunger(MaxStatistics), Energy(MaxStatistics), Fun(MaxStatistics) {

}

FStatistic::~FStatistic() {

}

void FStatistic::DecreaseStatistic(const EStatisticType& Type, const UINT Value) {
	switch (Type) {
	case EStatisticType::Hunger: {
		Hunger = std::clamp(Hunger - Value, UINT(0), MaxStatistics);
	}

							   break;

	case EStatisticType::Energy: {
		Energy = std::clamp(Energy - Value, UINT(0), MaxStatistics);
	}

							   break;

	case EStatisticType::Fun: {
		Fun = std::clamp(Fun - Value, UINT(0), MaxStatistics);
	}

							break;
	}
}

void FStatistic::IncreaseStatistic(const EStatisticType& Type, const UINT Value) {
	switch (Type) {
	case EStatisticType::Hunger: {
		Hunger = std::clamp(Hunger + Value, UINT(0), MaxStatistics);
	}

							   break;

	case EStatisticType::Energy: {
		Energy = std::clamp(Energy + Value, UINT(0), MaxStatistics);
	}

							   break;

	case EStatisticType::Fun: {
		Fun = std::clamp(Fun + Value, UINT(0), MaxStatistics);
	}

							break;
	}
}
