
#pragma once
#include "string.h"
#include <iostream>
using namespace std;

class Resource
{
	//�� �� �ķ�
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

	//setter �����ҵ�
	void set_resource_gold(int gold);
	void set_resource_food(int food);
	void set_resource_water(int water);
	//setter overloading
	void set_resource_gold(int areatype, int gold);
	void set_resource_water(int areatype, int water);
	void set_resource_food(int areatype, int food);


	//func 

	//boolŸ������
	//���� ����
	bool CheckArea_Upgrade();

	Resource calculate_produce_unit(string tendency, int cnt);
	//calculate_upgrade_area();
};