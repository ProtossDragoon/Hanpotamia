#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

void Map::set_areaInformation(areainformation area[]) {
	area[0] = { "강남구",0,"육지",1 };
	area[1] = { "용산구",1,"육지",1 };
	area[2] = { "서초구",2,"육지",1 };
	area[3] = { "송파구",3,"육지",1 };
	area[4] = { "마포구",4,"육지",1 };
	area[5] = { "성동구",5,"육지",1 };
	area[6] = { "동작구",6,"육지",1 };
	area[7] = { "영등포구",7,"육지",1 };
	area[8] = { "광진구",8,"육지",1 };
	area[9] = { "종로구",9,"육지",1 };
	area[10] = { "중구",10,"육지",1 };
	area[11] = { "강동구",11,"육지",1 };
	area[12] = { "양천구",12,"육지",1 };
	area[13] = { "동대문구",13,"육지",1 };
	area[14] = { "서대문구",14,"육지",1 };
	area[15] = { "강서구",15,"육지",1 };
	area[16] = { "관악구",16,"육지",1 };
	area[17] = { "성북구",17,"육지",1 };
	area[18] = { "은평구",18,"육지",1 };
	area[19] = { "노원구",19,"육지",1 };
	area[20] = { "구로구",20,"육지",1 };
	area[21] = { "중랑구",21,"육지",1 };
	area[22] = { "금천구",22,"육지",1 };
	area[23] = { "강북구",23,"육지",1 };
	area[24] = { "도봉구",24,"육지",1 };
	area[25] = { "강1",25,"강",1 };
	area[26] = { "강2",26,"깅",1 };
	area[27] = { "강3",27,"강",1 };
	area[28] = { "강4",28,"강",1 };
	area[29] = { "강5",29,"강",1 };
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
}//(?)

int Map::set_acquirableFood(string areaname) {
	string temp;
	temp = areaname;
	for (int i = 0; i < 30; i++) {
		if (area[i].areaname == temp) {
			if (area[i].areatype == "육지") {
				area[i].areafood = 100;
			}
			else {
				area[i].areafood = 50;
			}
		}
		return area[i].areafood;
	}
}

int Map::set_acquirableGold(string areaname) {
	string temp;
	temp = areaname;
	for (int i = 0; i < 30; i++) {
		if (area[i].areaname == temp) {
			if (area[i].areatype == "육지") {
				area[i].areagold = 100;
			}
			else {
				area[i].areagold = 10;
			}
		}
		return area[i].areagold;
	}
}

int Map::set_acquirableWater(string areaname) {
	string temp;
	temp = areaname;
	for (int i = 0; i < 30; i++) {
		if (area[i].areaname == temp) {
			if (area[i].areatype == "육지") {
				area[i].areawater = 30;
			}
			else {
				area[i].areawater = 100;
			}
		}
		return area[i].areawater;
	}
}

void Map::set_areaHost(Player* _host_player, string areaname) {
	string temp;
	temp = _host_player->get_player_name;
	for (int i = 0; i < 30; i++) {
		if (areaname == area[i].areaname) {
			area[i].areahost = temp;
		}
	}
}

int Map::get_unit(string areaname, Player* _host_player) {
	string temp;
	int i;
	int cnt = 0;
	temp = _host_player->get_player_name;
	for (i = 0; i < 30; i++) {
		if (areaname == area[i].areaname) {
			if (temp == area[i].areahost) {
				return area[i].areaunit;
				cnt++;
			}
			else {
				cout << temp << "는" << areaname << "의 소유주가 아닙니다." << endl;
			}
		}
		
	}
	if (cnt == 0) {
		cout << areaname << "이란 땅은 없습니다." << endl;
	}
}

int Map::get_unitWhole(Player* _host_player) {
	string temp;
	int i;
	int cnt = 0;
	temp = _host_player->get_player_name;
	for (i = 0; i < 30; i++) {
		if (temp == area[i].areahost) {
			cout << temp << "의" << area[i].areaname << "의 배치되어 있는 병력" << area[i].areaunit << endl;
			cnt++;
		}
	}
	if (cnt == 0) {
		cout << temp << "가 가진 땅은 없습니다." << endl;
	}
}

string Map::get_occupationPlayer(string areaname) {
	string temp;
	temp = areaname;
	for (int i = 0; i < 30; i++) {
		if (area[i].areaname == temp) {
			return area[i].areahost;
		}
	}
	cout << areaname << "의 소유주는 아직 없습니다." << endl;
}
