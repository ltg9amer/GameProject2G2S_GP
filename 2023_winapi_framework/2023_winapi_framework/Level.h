#pragma once
class Level
{
private:
	int experience;
	float needToLevelup;
public:
	int CurrentLevel;
public:
	void IncreaseExperience(int value)
	{
		experience += value;
		if (experience >= needToLevelup) 
			LevelUp();
	}
private:
	void LevelUp()
	{
		CurrentLevel++;
		needToLevelup * 1.4f;
	}
};

