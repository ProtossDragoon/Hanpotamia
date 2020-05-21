#pragma once
class Resource
{
	//물 금 식량
private:
	int Resource_Gold;
	int Resource_Water;
	int Resource_Food;

protected:
	//xx

public:
	//getter
	int getGold();
	int getFood();
	int getWater();

	//setter
	void setGold();
	void setFood();
	void setWater();

};