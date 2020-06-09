#include "master.h"
#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

// extern master
extern Master game_master;

////ë°•íƒœ???‘ì„± Overloading ?¨ìˆ˜
areainformation Map::findArea(int areaNum){
    areainformation *find = get_wholeMap();
    return find[areaNum];
}

areainformation* Map::get_wholeMap() {
    return area;
}
////?? œ ?ˆë‹ˆ


areainformation Map::findArea(string areaname) {
	for (int i = 0; i < 30; i++) {
		if (area[i].areaname == areaname) {
			return area[i];
		}
	}
}

////¹ÚÅÂÁ¤ ÀÛ¼º Overloading ÇÔ¼ö
areainformation Map::findArea(int areaNum) {
	areainformation* find = get_wholeMap();
	return find[areaNum];
}

areainformation* Map::get_wholeMap() {
	return area;
}
////»èÁ¦ ´Ï´Ï

void Map::set_areaInformation(areainformation area[]) {
	int i, j;
	areainformation temp;
	string tempareaname;
	area[0] = { "ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½",0,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[1] = { "ï¿½ï¿½ê±?,1,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[2] = { "ï¿½ï¿½ï¿½Ê±ï¿½",2,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[3] = { "ï¿½ï¿½ï¿½Ä±ï¿½",3,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[4] = { "ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½",4,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[5] = { "ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½",5,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[6] = { "ï¿½ï¿½ï¿½Û±ï¿½",6,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[7] = { "ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½",7,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[8] = { "ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½",8,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[9] = { "ï¿½ï¿½ï¿½Î±ï¿½",9,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[10] = { "ï¿½ß±ï¿½",10,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[11] = { "ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½",11,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[12] = { "ï¿½ï¿½Ãµï¿½ï¿½",12,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[13] = { "ï¿½ï¿½ï¿½ë¹®ï¿½ï¿½",13,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[14] = { "ï¿½ï¿½ï¿½ë¹®ï¿½ï¿½",14,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[15] = { "ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½",15,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[16] = { "ï¿½ï¿½ï¿½Ç±ï¿½",16,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[17] = { "ï¿½ï¿½ï¿½Ï±ï¿½",17,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[18] = { "ï¿½ï¿½ï¿½ï¿½",18,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[19] = { "ï¿½ï¿½ï¿½ï¿½ï¿?,19,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[20] = { "ï¿½ï¿½ï¿½Î±ï¿½",20,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[21] = { "ï¿½ß¶ï¿½ï¿½ï¿½",21,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[22] = { "ï¿½ï¿½Ãµï¿½ï¿½",22,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[23] = { "ï¿½ï¿½ï¿½Ï±ï¿½",23,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[24] = { "ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½",24,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[25] = { "ï¿½ï¿½1",25,"ï¿½ï¿½",1 };
	area[26] = { "ï¿½ï¿½2",26,"ï¿½ï¿½",1 };
	area[27] = { "ï¿½ï¿½3",27,"ï¿½ï¿½",1 };
	area[28] = { "ï¿½ï¿½4",28,"ï¿½ï¿½",1 };
	area[29] = { "ï¿½ï¿½5",29,"ï¿½ï¿½",1 };
	for (i = 0; i < 30; i++) {
		for (j = 0; j < 30; j++) {
			area[i].neighborarea[j] = '\0';
		}
		tempareaname = area[i].areaname;
		area[i].areahost = '\0';
		area[i].areaunit.Archercount = 0;
		area[i].areaunit.Cavalrycount = 0;
		area[i].areaunit.Infantrycount = 0;
		area[i].areaunit.Navycount = 0;
		area[i].arearesource->set_resource_food(0);
		area[i].arearesource->set_resource_water(0);
		area[i].arearesource->set_resource_gold(0);
		area[i].occupationcost->set_resource_food(0);
		area[i].occupationcost->set_resource_gold(0);
		area[i].occupationcost->set_resource_water(0);
	}
}

Map::~Map() {
}

Map::Map(int _max_area):_max_area(_max_area) {
	int** _route;
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

int Map::attackable(string startarea, string endarea) {
	areainformation temp;
	int from, to;
	temp = findArea(startarea);
	from = temp.areanum;
	temp = findArea(endarea);
	to = temp.areanum;
	if (_route[from][to] == 1) {
		return 1;
	}
	for (int i = 0; i < _max_area; i++) {
		if (_route[from][i] == 1) {
			if (_route[i][to] == 1) {
				return 2;
			}
		}
	}
	return 0;
}

string* Map::get_movableArea(string areaname) {
	areainformation temp;
	int tempnum = 0;
	int j = 0;
	temp = findArea(areaname);
	tempnum = temp.areanum;
	for (int i = 0; i < _max_area; i++) {
		if (_route[tempnum][i] == 1) {
			temp.neighborarea[j] = area[i].areaname;
			j++;
		}
	}
	return temp.neighborarea;
}

void Map::get_acquirableResource(string areaname) {
	set_acquirableFood(areaname);
	set_acquirableGold(areaname);
	set_acquirableWater(areaname);
}

int Map::set_acquirableFood(string areaname) {
	areainformation temp;
	temp = findArea(areaname);
	if (temp.areatype == "ï¿½ï¿½ï¿½ï¿½") {
		temp.arearesource->set_resource_food(100);
	}
	else {
		temp.arearesource->set_resource_food(50);
	}
}

int Map::set_acquirableGold(string areaname) {
	areainformation temp;
	temp = findArea(areaname);
	if (temp.areatype == "ï¿½ï¿½ï¿½ï¿½") {
		temp.arearesource->set_resource_gold(100);
	}
	else {
		temp.arearesource->set_resource_gold(10);
	}
}

int Map::set_acquirableWater(string areaname) {
	areainformation temp;
	temp = findArea(areaname);
	if (temp.areatype == "ï¿½ï¿½ï¿½ï¿½") {
		temp.arearesource->set_resource_water(30);
	}
	else {
		temp.arearesource->set_resource_water(100);
	}
}

void Map::set_areaHost(Player* _host_player, string areaname) {
	areainformation temp;
	string host;
	temp = findArea(areaname);
	host = _host_player->get_player_name();
	temp.areahost = host;
}

Army Map::get_unit(string areaname, Player* _host_player) {
	areainformation temp;
	string host;
	int cnt = 0;
	host = _host_player->get_player_name();
	temp = findArea(areaname);
	if (host == temp.areahost) {
		return temp.areaunit;
		cnt++;
	}
	else {
		cout << temp.areaname << "ï¿½ï¿½" << areaname << "ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½Ö°ï¿½ ï¿½Æ´Õ´Ï´ï¿½." << endl;
	}	
	if (cnt == 0) {
		cout << areaname << "ï¿½Ì¶ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½Ï´ï¿½." << endl;
	}
}

Army Map::get_unitWhole(Player* _host_player) {
	string host;
	Army temp;
	int i;
	int cnt = 0;
	host = _host_player->get_player_name();
	for (i = 0; i < 30; i++) {
		if (host == area[i].areahost) {
			temp.Archercount += area[i].areaunit.Archercount;
			temp.Navycount += area[i].areaunit.Navycount;
			temp.Cavalrycount += area[i].areaunit.Cavalrycount;
			temp.Infantrycount += area[i].areaunit.Infantrycount;
			cnt++;
		}
	}
	return temp;
	if (cnt == 0) {
		cout << host << "ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½Ï´ï¿½." << endl;
	}
}

string Map::get_occupationPlayer(string areaname) {
	areainformation temp;
	temp = findArea(areaname);
	if (temp.areahost.empty()) {
		cout << areaname << "ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½Ö´ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½Ï´ï¿½." << endl;
		return NULL;
	}
	else {
		return temp.areahost;
	}
}

Resource Map::set_occupationCost(string areaname) {
	areainformation temp;
	temp = findArea(areaname);
	if (temp.areatype == "ï¿½ï¿½ï¿½ï¿½") {
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

Resource Map::get_occupationCost(string areaname) {
	areainformation temp;
	temp = findArea(areaname);

	if (temp.areatype == "ï¿½ï¿½ï¿½ï¿½") {
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

void Map::upgrade_Area(string areaname) {
	areainformation temp;
	temp = findArea(areaname);
	temp.arealevel++;
}

void Map::set_unit(string areaname, string tendency, int count) {
	areainformation temp;
	temp = findArea(areaname);
	if (tendency == "Infantry") {
		temp.areaunit.Infantrycount += count;
	}
	else if (tendency == "Navy") {
		temp.areaunit.Navycount += count;
	}
	else if (tendency == "Cavalry") {
		temp.areaunit.Cavalrycount += count;
	}
	else {
		temp.areaunit.Archercount += count;
	}
}

void Map::showAreaInformation(string areaname) {
	areainformation temp;
	int tempResource = 0;
	int tempCost = 0;
	temp = findArea(areaname);
	cout << "ï¿½ï¿½ï¿½ï¿½ï¿½Ì¸ï¿½ :" << temp.areaname << endl;
	cout << "ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½È£ :" << temp.areanum << endl;
	cout << "ï¿½ï¿½ï¿½ï¿½ï¿½Ó¼ï¿½ :" << temp.areatype << endl;
	cout << "---ï¿½Ìµï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½---" << endl;
	for (int i = 0; temp.neighborarea[i].size != 0; i++) {
		cout << temp.neighborarea[i] << endl;
	}
	cout << "ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ :" << temp.areahost << endl;
	cout << "---ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½---" << endl;
	cout << "ï¿½Ãºï¿½ :" << temp.areaunit.Archercount << endl;
	cout << "ï¿½âº´ :" << temp.areaunit.Cavalrycount << endl;
	cout << "ï¿½ï¿½ï¿½ï¿½ :" << temp.areaunit.Infantrycount << endl;
	cout << "ï¿½ï¿½ï¿½ï¿½ :" << temp.areaunit.Navycount << endl;
	cout << "---ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ ï¿½Ö´ï¿½ ï¿½Ú¿ï¿½---" << endl;
	tempResource = temp.arearesource->get_resource_food();
	cout << "ï¿½Ä·ï¿½ :" << tempResource << endl;
	tempResource = temp.arearesource->get_resource_gold();
	cout << "ï¿½ï¿½ :" << tempResource << endl;
	tempResource = temp.arearesource->get_resource_water();
	cout << "ï¿½ï¿½ :" << tempResource << endl;
	cout << "---ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿?--" << endl;
	tempCost = temp.occupationcost->get_resource_food();
	cout << "ï¿½ï¿½ï¿½ï¿½ :" << tempCost << endl;
	tempCost = temp.occupationcost->get_resource_gold();
	cout << "ï¿½ï¿½ :" << tempCost << endl;
	tempCost = temp.occupationcost->get_resource_water();
	cout << "ï¿½ï¿½ :" << tempCost << endl;
}

int* Map::get_wholeArea(Player* _host_player) {
	string temp;
	temp = _host_player->get_player_name();
	int wholeArea[30] = { 0 };
	for (int i = 0; i < 30; i++) {
		if (temp == area[i].areahost) {
			wholeArea[i] = 1;
		}
	}
	return wholeArea;
}
