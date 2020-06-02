#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

areainformation Map::findArea(string areaname) {
	for (int i = 0; i < 30; i++) {
		if (area[i].areaname == areaname) {
			return area[i];
		}
	}
}

void Map::set_areaInformation(areainformation area[]) {
	area[0] = { "°­³²±¸",0,"À°Áö",1 };
	area[1] = { "¿ë»ê±¸",1,"À°Áö",1 };
	area[2] = { "¼­ÃÊ±¸",2,"À°Áö",1 };
	area[3] = { "¼ÛÆÄ±¸",3,"À°Áö",1 };
	area[4] = { "¸¶Æ÷±¸",4,"À°Áö",1 };
	area[5] = { "¼ºµ¿±¸",5,"À°Áö",1 };
	area[6] = { "µ¿ÀÛ±¸",6,"À°Áö",1 };
	area[7] = { "¿µµîÆ÷±¸",7,"À°Áö",1 };
	area[8] = { "±¤Áø±¸",8,"À°Áö",1 };
	area[9] = { "Á¾·Î±¸",9,"À°Áö",1 };
	area[10] = { "Áß±¸",10,"À°Áö",1 };
	area[11] = { "°­µ¿±¸",11,"À°Áö",1 };
	area[12] = { "¾çÃµ±¸",12,"À°Áö",1 };
	area[13] = { "µ¿´ë¹®±¸",13,"À°Áö",1 };
	area[14] = { "¼­´ë¹®±¸",14,"À°Áö",1 };
	area[15] = { "°­¼­±¸",15,"À°Áö",1 };
	area[16] = { "°ü¾Ç±¸",16,"À°Áö",1 };
	area[17] = { "¼ººÏ±¸",17,"À°Áö",1 };
	area[18] = { "ÀºÆò±¸",18,"À°Áö",1 };
	area[19] = { "³ë¿ø±¸",19,"À°Áö",1 };
	area[20] = { "±¸·Î±¸",20,"À°Áö",1 };
	area[21] = { "Áß¶û±¸",21,"À°Áö",1 };
	area[22] = { "±ÝÃµ±¸",22,"À°Áö",1 };
	area[23] = { "°­ºÏ±¸",23,"À°Áö",1 };
	area[24] = { "µµºÀ±¸",24,"À°Áö",1 };
	area[25] = { "°­1",25,"°­",1 };
	area[26] = { "°­2",26,"°­",1 };
	area[27] = { "°­3",27,"°­",1 };
	area[28] = { "°­4",28,"°­",1 };
	area[29] = { "°­5",29,"°­",1 };
}

Map::~Map() {
}

Map::Map(int _max_area):_max_area(_max_area) {
	_route = (int**)malloc(_max_area * sizeof(int*));
	for (int i = 0; i < _max_area; i++) {
		_route[i] = (int*)malloc(_max_area * sizeof(int));
		memset(_route[i], 0, _max_area * sizeof(int));
	}
	_route[0][2] = 1;
	_route[0][3] = 1;
	_route[0][28] = 1;
	_route[1][4] = 1;
	_route[1][6] = 1;
	_route[1][10] = 1;
	_route[1][27] = 1;
	_route[2][16] = 1;
	_route[2][27] = 1;
	_route[3][11] = 1;
	_route[3][16] = 1;
	_route[4][14] = 1;
	_route[4][25] = 1;
	_route[4][26] = 1;
	_route[5][8] = 1;
	_route[5][10] = 1;
	_route[5][13] = 1;
	_route[6][7] = 1;
	_route[6][16] = 1;
	_route[7][20] = 1;
	_route[7][26] = 1;
	_route[8][29] = 1;
	_route[9][10] = 1;
	_route[9][14] = 1;
	_route[9][17] = 1;
	_route[9][18] = 1;
	_route[11][19] = 1;
	_route[11][21] = 1;
	_route[11][29] = 1;
	_route[12][15] = 1;
	_route[12][20] = 1;
	_route[13][17] = 1;
	_route[13][21] = 1;
	_route[13][28] = 1;
	_route[15][25] = 1;
	_route[16][22] = 1;
	_route[17][23] = 1;
	_route[19][21] = 1;
	_route[19][24] = 1;
	_route[20][22] = 1;
	_route[23][24] = 1;
	_route[25][26] = 1;
	_route[26][27] = 1;
	_route[27][28] = 1;
	_route[28][29] = 1;
}

int Map::get_movableArea(string areaname, int start) {
	int j = 0;
	for (int i = 0; i < _max_area; i++) {
		if (_route[start][i] == 1) {
			area[start].neighborarea[j] = area[i].areaname;
			j++;
		}
	}
}

void Map::get_acquirableResource(string areaname) {
	set_acquirableFood(areaname);
	set_acquirableGold(areaname);
	set_acquirableWater(areaname);
}

int Map::set_acquirableFood(string areaname) {
	areainformation temp;
	temp = findArea(areaname);
	if (temp.areatype == "À°Áö") {
		temp.arearesource->set_resource_food = 100;
	}
	else {
		temp.arearesource->set_resource_food = 50;
	}
}

int Map::set_acquirableGold(string areaname) {
	areainformation temp;
	temp = findArea(areaname);
	if (temp.areatype == "À°Áö") {
		temp.arearesource->set_resource_gold = 100;
	}
	else {
		temp.arearesource->set_resource_gold = 10;
	}
}

int Map::set_acquirableWater(string areaname) {
	areainformation temp;
	temp = findArea(areaname);
	if (temp.areatype == "À°Áö") {
		temp.arearesource->set_resource_water = 30;
	}
	else {
		temp.arearesource->set_resource_water = 100;
	}
}

void Map::set_areaHost(Player* _host_player, string areaname) {
	areainformation temp;
	string host;
	temp = findArea(areaname);
	host = _host_player->get_player_name;
	temp.areahost = host;
}

Army Map::get_unit(string areaname, Player* _host_player) {
	areainformation temp;
	string host;
	int cnt = 0;
	host = _host_player->get_player_name;
	temp = findArea(areaname);
	if (host == temp.areahost) {
		return temp.areaunit;
		cnt++;
	}
	else {
		cout << temp.areaname << "´Â" << areaname << "ÀÇ ¼ÒÀ¯ÁÖ°¡ ¾Æ´Õ´Ï´Ù." << endl;
	}	
	if (cnt == 0) {
		cout << areaname << "ÀÌ¶õ ¶¥Àº ¾ø½À´Ï´Ù." << endl;
	}
}

Army Map::get_unitWhole(Player* _host_player) {
	string host;
	Army temp;
	int i;
	int cnt = 0;
	host = _host_player->get_player_name;
	for (i = 0; i < 30; i++) {
		if (host == area[i].areahost) {
			temp.Archercount += area[i].areaunit.Archercount;
			temp.Navycount += area[i].areaunit.Navycount;
			temp.Cabalrycount += area[i].areaunit.Cabalrycount;
			temp.Infantrycount += area[i].areaunit.Infantrycount;
			cnt++;
		}
	}
	return temp;
	if (cnt == 0) {
		cout << host << "°¡ °¡Áø ¶¥Àº ¾ø½À´Ï´Ù." << endl;
	}
}

string Map::get_occupationPlayer(string areaname) {
	areainformation temp;
	temp = findArea(areaname);
	if (temp.areahost.empty) {
		cout << areaname << "ÀÇ ¼ÒÀ¯ÁÖ´Â ¾ÆÁ÷ ¾ø½À´Ï´Ù." << endl;
		return NULL;
	}
	else {
		return temp.areahost;
	}
}

void Map::set_occupationCost(string areaname) {
	areainformation temp;
	temp = findArea(areaname);
	if (temp.areatype == "À°Áö") {
		temp.occupationcost->set_resource_food = 100;
		temp.occupationcost->set_resource_gold = 100;
		temp.occupationcost->set_resource_water = 100;
	}
	else {
		temp.occupationcost->set_resource_food = 100;
		temp.occupationcost->set_resource_gold = 100;
		temp.occupationcost->set_resource_water = 100;
	}
}

void Map::get_occupationCost(string areaname) {
	areainformation temp;
	temp = findArea(areaname);
	if (temp.areatype == "À°Áö") {
		temp.occupationcost->set_resource_food = 100;
		temp.occupationcost->set_resource_gold = 100;
		temp.occupationcost->set_resource_water = 100;
	}
	else {
		temp.occupationcost->set_resource_food = 100;
		temp.occupationcost->set_resource_gold = 100;
		temp.occupationcost->set_resource_water = 100;
	}
}

void Map::get_upgradeCost(string areaname) {
	areainformation temp;
	temp = findArea(areaname);

}

areainformation Map::get_areaInformation(string areaname) {
	areainformation temp;
	temp = findArea(areaname);
	return temp;
}

void Map::set_areaLevelUpgrade(string areaname) {
	areainformation temp;
	temp = findArea(areaname);
	temp.arealevel++;
}