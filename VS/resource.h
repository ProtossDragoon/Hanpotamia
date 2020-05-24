#pragma once
class Resource
{
	//물 금 식량
private:
	int _resource_gold;
	int _resource_water;
	int _resource_food;

protected:
	//xx

public:
	////constructor
	//Resource();
	//~Resource();

	//getter
	int get_resource_gold() { return _resource_gold; };
	int get_resource_food() { return _resource_food; };
	int get_resource_water() { return _resource_water; };

	//setter 사용안할듯
	void set_resource_gold(int gold);
	void set_resource_food(int food);
	void set_resource_water(int water);

};