
#pragma once
#include "string.h"
#include <iostream>
using namespace std;

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
	//setter overloading
	void set_resource_gold(int areatype, int gold);
	void set_resource_water(int areatype, int water);
	void set_resource_food(int areatype, int food);


	//func 

	//bool타입으로
	//지역 업글
	//bool CheckArea_Upgrade();
	bool check_resource(Resource *player, Resource *need);


	Resource calculate_produce_unit(string tendency, int cnt);
	//calculate_upgrade_area();
};
//
//지역업글 
//
//유닛생산 
//player  resource 인원