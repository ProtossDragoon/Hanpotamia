#pragma once
#include <iostream>
#include"player.h"
#include"resource.h"
using namespace std;

typedef struct {
	string areaname;
	int areanum;
	string areatype;
	int arealevel;
	string neighborarea[30];
	string areahost;
}areainformation;

class Map
{
private:
	char _area;
	Player* _host_player;
	Resource _occupation_acquirable_resource;
	Resource _occupation_cost;
	int _area_level;
	int _area_number;
	string _area_name;
	string _area_type;
	int _acquirable_resource_water;
	int _acquirable_resource_gold;
	int _acquirable_resource_food;
	const int _max_area = 30;
	int** _route;
	areainformation area[30] = { NULL };

public:
	Map(int _max_area);
	string get_occupationPlayer() { return _host_player->get_play_name; }
	void get_occupationCost();
	void get_acquirableResource(areainformation area);
	void get_upgradeCost();
	int get_movableArea(areainformation area[], int start);

	void set_areaName();
	void set_occupationCost();
	void set_areaInformation(areainformation area[]);
	void set_areaHost(Player* _host_player);
	int set_acquirableFood(areainformation area);
	int set_acquirableGold(areainformation area);
	int set_acquirableWater(areainformation area);

	int calBattle();
};