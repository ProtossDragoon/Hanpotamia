#pragma once
#include <iostream>
using namespace std;

typedef struct {
	string areaname;
	int areanum;
	string areahost;
}areainformation;

class Map
{
private:
	char _area;
	player* _host_player;
	resource _occupation_acquirable_resource;
	resource _occupation_cost;
	int _area_level;
	int _area_number;
	string _area_name;
	string _area_type;
	int _acquirable_resource_water;
	int _acquirable_resource_gold;
	int _acquirable_resource_food;
	const int _max_area;
	int** _route;
	areainformation area[25] = { NULL };

public:
	Map(int _max_area);
	void get_occupationPlayer();
	void get_occupationCost();
	void get_acquirableResource();
	void get_upgradeCost();
	void get_movableArea(int start);

	void set_areaName();
	void set_occupationCost();
	void set_areaLevel();
	void set_areaInformation();
	void set_areaType();

	int calBattle();
};