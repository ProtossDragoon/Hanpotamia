#pragma once
class Resource
{
	//�� �� �ķ�
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