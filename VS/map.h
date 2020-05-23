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
	int areaunit;
	int areafood;
	int areawater;
	int areagold;
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
	string get_occupationPlayer(string areaname);
	void get_occupationCost();
	void get_acquirableResource(string areaname);
	void get_upgradeCost();
	int get_movableArea(string areaname, int start);
	int get_unit(string areaname, Player* _host_player);
	int get_unitWhole(Player* _host_player);

	void set_occupationCost();
	void set_areaInformation(areainformation area[]);
	void set_areaHost(Player* _host_player, string areaname);
	int set_acquirableFood(string areaname);
	int set_acquirableGold(string areaname);
	int set_acquirableWater(string areaname);
};