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
<<<<<<< HEAD
	int i, j;
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
	for (i = 0; i < 30; i++) {
		for (j = 0; j < 30; j++) {
			area[i].neighborarea[j] = '\0';
		}
		area[i].areahost = '\0';
		area[i].areaunit.Archercount = 0;
		area[i].areaunit.Cabalrycount = 0;
		area[i].areaunit.Infantrycount = 0;
		area[i].areaunit.Navycount = 0;
		area[i].arearesource->set_resource_food = 0;
		area[i].arearesource->set_resource_water = 0;
		area[i].arearesource->set_resource_gold = 0;
		area[i].occupationcost->set_resource_food = 0;
		area[i].occupationcost->set_resource_gold = 0;
		area[i].occupationcost->set_resource_water = 0;
	}
=======
	area[0] = { "ï¿½ï¿½ï¿½ï¿½ï¿½ï¿½",0,"ï¿½ï¿½ï¿½ï¿½",1 };
	area[1] = { "ï¿½ï¿½ê±¸",1,"ï¿½ï¿½ï¿½ï¿½",1 };
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
	area[19] = { "ï¿½ï¿½ï¿½ï¿½ï¿½",19,"ï¿½ï¿½ï¿½ï¿½",1 };
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
>>>>>>> master
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

int Map::floyd(int from, int to) {
	int MAX, i, temp;
	int** graph;
	int** before;
	MAX = _max_area;
	graph = (int**)malloc(MAX * sizeof(int*));
	for (i = 0; i < MAX; i++) {
		graph[i] = (int*)malloc(MAX * sizeof(int));
	}
	before = (int**)malloc(MAX * sizeof(int*));
	for (i = 0; i < MAX; i++) {
		before[i] = (int*)malloc(MAX * sizeof(int));
	}
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			graph[i][j] = MAX;
			if (i == j) {
				graph[i][j] = 0;
			}
			before[i][j] = -1;
		}
	}
	for (int mid = 0; mid < MAX; mid++) {
		for (int start = 0; start < MAX; start++) {
			for (int end = 0; end < MAX; end++) {
				if (graph[start][end] > graph[start][mid] + graph[mid][end]) {
					graph[start][end] = graph[start][mid] + graph[mid][end];
					before[start][end] = before[mid][end];
				}
			}
		}
	}
	return graph[from][to];
}

string Map::get_movableArea(string areaname) {
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
		temp.arearesource->set_resource_food = 100;
	}
	else {
		temp.arearesource->set_resource_food = 50;
	}
}

int Map::set_acquirableGold(string areaname) {
	areainformation temp;
	temp = findArea(areaname);
	if (temp.areatype == "ï¿½ï¿½ï¿½ï¿½") {
		temp.arearesource->set_resource_gold = 100;
	}
	else {
		temp.arearesource->set_resource_gold = 10;
	}
}

int Map::set_acquirableWater(string areaname) {
	areainformation temp;
	temp = findArea(areaname);
	if (temp.areatype == "ï¿½ï¿½ï¿½ï¿½") {
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
		cout << host << "ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½Ï´ï¿½." << endl;
	}
}

string Map::get_occupationPlayer(string areaname) {
	areainformation temp;
	temp = findArea(areaname);
	if (temp.areahost.empty) {
		cout << areaname << "ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½Ö´ï¿½ ï¿½ï¿½ï¿½ï¿½ ï¿½ï¿½ï¿½ï¿½ï¿½Ï´ï¿½." << endl;
		return NULL;
	}
	else {
		return temp.areahost;
	}
}

void Map::set_occupationCost(string areaname) {
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

void Map::get_occupationCost(string areaname) {
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

<<<<<<< HEAD
void Map::upgrade_Area(string areaname) {
=======
void Map::set_areaLevelUpgrade(string areaname) { ////í•¨ìˆ˜ ì´ë¦„ê³¼ í•¨ìˆ˜ ì„±ê²©ì´ ì•ˆë§žëŠ”ê²ƒê°™ì€ .??
>>>>>>> master
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
		temp.areaunit.Cabalrycount += count;
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
	cout << "Áö¿ªÀÌ¸§ :" << temp.areaname << endl;
	cout << "Áö¿ª¹øÈ£ :" << temp.areanum << endl;
	cout << "Áö¿ª¼Ó¼º :" << temp.areatype << endl;
	cout << "---ÀÌµ¿°¡´ÉÇÑ Áö¿ªµé---" << endl;
	for (int i = 0; temp.neighborarea[i].size != 0; i++) {
		cout << temp.neighborarea[i] << endl;
	}
	cout << "Áö¿ª¼ÒÀ¯ÁÖ :" << temp.areahost << endl;
	cout << "---Áö¿ªº´·Â---" << endl;
	cout << "±Ãº´ :" << temp.areaunit.Archercount << endl;
	cout << "±âº´ :" << temp.areaunit.Cabalrycount << endl;
	cout << "º¸º´ :" << temp.areaunit.Infantrycount << endl;
	cout << "¼ö±º :" << temp.areaunit.Navycount << endl;
	cout << "---Áö¿ª¿¡¼­ ¾òÀ» ¼ö ÀÖ´Â ÀÚ¿ø---" << endl;
	tempResource = temp.arearesource->get_resource_food;
	cout << "½Ä·® :" << tempResource << endl;
	tempResource = temp.arearesource->get_resource_gold;
	cout << "±Ý :" << tempResource << endl;
	tempResource = temp.arearesource->get_resource_water;
	cout << "¹° :" << tempResource << endl;
	cout << "---Áö¿ª Á¡·É ºñ¿ë---" << endl;
	tempCost = temp.occupationcost->get_resource_food;
	cout << "À½½Ä :" << tempCost << endl;
	tempCost = temp.occupationcost->get_resource_gold;
	cout << "±Ý :" << tempCost << endl;
	tempCost = temp.occupationcost->get_resource_water;
	cout << "¹° :" << tempCost << endl;
}

int* Map::get_wholeArea(Player* _host_player) {
	string temp;
	temp = _host_player->get_player_name;
	int wholeArea[30] = { 0 };
	for (int i = 0; i < 30; i++) {
		if (temp == area[i].areahost) {
			wholeArea[i] = 1;
		}
	}
	return wholeArea;
}