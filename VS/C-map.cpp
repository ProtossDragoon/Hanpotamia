#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>

void Map::set_areaInformation() {
	area[0] = { "강남구",0 };
	area[1]={""}
}

Map::Map(int _max_area):_max_area(_max_area) {
	_route = (int**)malloc(_max_area * sizeof(int*));
	for (int i = 0; i < _max_area; i++) {
		_route[i] = (int*)malloc(_max_area * sizeof(int));
		memset(_route[i], 0, _max_area * sizeof(int));
	}
	_route[0][2] = 1;
	_route[0][3] = 1;
	_route[0][13] = 1;
	_route[1][2] = 1;
	_route[1][4] = 1;
	_route[1][6] = 1;
	_route[1][10] = 1;
	_route[2][16] = 1;
	_route[3][11] = 1;
	_route[3][16] = 1;
	_route[4][7] = 1;
	_route[4][14] = 1;
	_route[4][15] = 1;
	_route[5][8] = 1;
	_route[5][10] = 1;
	_route[5][13] = 1;
	_route[6][7] = 1;
	_route[6][16] = 1;
	_route[7][20] = 1;
	_route[8][11] = 1;
	_route[9][10] = 1;
	_route[9][14] = 1;
	_route[9][17] = 1;
	_route[9][18] = 1;
	_route[11][19] = 1;
	_route[11][21] = 1;
	_route[12][15] = 1;
	_route[12][20] = 1;
	_route[13][17] = 1;
	_route[13][21] = 1;
	_route[16][22] = 1;
	_route[17][23] = 1;
	_route[19][21] = 1;
	_route[19][24] = 1;
	_route[20][22] = 1;
	_route[23][24] = 1;
}

/*void Map::addRoute(int start, int end) {
	_route[start][end] = 1;
	_route[end][start] = 1;
}*/

void Map::get_movableArea(int start) {
	cout << "---이동할 수 있는 지역---" << endl;
	for (int i = 0; i < _max_area; i++) {
		if (_route[start][i] == 1) {
			cout << i << endl;
		}
	}
}

void Map::get_acquirableResource() {
	if (_area_type == "육지") {
		_acquirable_resource_food = 100;
		_acquirable_resource_gold = 100;
		_acquirable_resource_water = 30;
	}
	else {
		_acquirable_resource_food = 50;
		_acquirable_resource_gold = 10;
		_acquirable_resource_water = 100;
	}
}

void Map::set_areaType() {
	
}

int Map::calBattle() {
}
