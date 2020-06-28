#include "map.h"
#include "master.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wreturn-stack-address"
using namespace std;
extern Master game_master;

areainformation Map::findArea(string areaname) {
	for (int i = 0; i < 30; i++) {
		if (game_master.get_gameMap()->area[i].areaname == areaname) {
			return area[i];
		}
	}
}

////박태정 작성 Overloading 함수
areainformation Map::findArea(int areaNum) {
	return area[areaNum];
}


////삭제 니니

void Map::set_areaInformation() {
	int i, j;
	areainformation temp;
	string tempareaname;
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
	area[26] = { "강2",26,"강",1 };
	area[27] = { "강3",27,"강",1 };
	area[28] = { "강4",28,"강",1 };
	area[29] = { "강5",29,"강",1 };
	for (i = 0; i < 30; i++) {
		for (j = 0; j < 30; j++) {
			area[i].neighborarea[j] = "\0";
		}
		tempareaname = area[i].areaname;
		area[i].areahost = "\0";
		area[i].areaunit.Archercount = 0;
		area[i].areaunit.Cavalrycount = 0;
		area[i].areaunit.Infantrycount = 0;
		area[i].areaunit.Navycount = 0;
		
		area[i].arearesource = new Resource();
		if (area[i].areatype == "육지") {
			area[i].arearesource->set_resource_food(100);
			area[i].arearesource->set_resource_water(100);
			area[i].arearesource->set_resource_gold(30);
		}
		else{
			area[i].arearesource->set_resource_food(50);
			area[i].arearesource->set_resource_water(10);
			area[i].arearesource->set_resource_gold(100);
		}
		area[i].occupationcost = new Resource();
		if (area[i].areatype == "육지") {
			area[i].occupationcost->set_resource_food(100);
			area[i].occupationcost->set_resource_gold(100);
			area[i].occupationcost->set_resource_water(100);
		}
		else {
			area[i].occupationcost->set_resource_food(100);
			area[i].occupationcost->set_resource_gold(100);
			area[i].occupationcost->set_resource_water(100);
		}
	}
}

Map::~Map() {
}

Map::Map(int _max_area):_max_area(_max_area) {
    _route = new int* [_max_area];
    for (int i = 0; i < _max_area; i++) {
        _route[i] = new int[_max_area];
    }
    for (int i = 0; i < _max_area; i++) {
        for (int j = 0; j < _max_area; j++) {
            _route[i][j] = 0;
        }
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
//	set_areaInformation();
}

int Map::attackable(string startarea, string endarea) {
	int from, to;
	areainformation temp;
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
				return 1;
			}
		}
	}
	return 0;
}

string* Map::get_movableArea(string areaname) {
	areainformation temp;
	int tempnum;
	int j = 0;
	temp = findArea(areaname);
	tempnum = temp.areanum;
	for (int i = 0; i < _max_area; i++) {
		if (_route[tempnum][i] == 1) {
			temp.neighborarea[j] = area[i].areaname;
			j++;
		}
	}
	temp.neighborarea[j]="NO";
	return temp.neighborarea;
}

Resource* Map::get_acquirableResource(string areaname) {
	areainformation temp;
	temp = findArea(areaname);
	return temp.arearesource;
}

void Map::set_acquirableFood(string areaname) {
	areainformation temp;
	int tempnum;
	temp = findArea(areaname);
	tempnum = temp.areanum;
	if (area[tempnum].areatype == "육지") {
		area[tempnum].arearesource->set_resource_food(100);
	}
	else {
		area[tempnum].arearesource->set_resource_food(50);
	}
}

void Map::set_acquirableGold(string areaname) {
	areainformation temp;
	int tempnum;
	tempnum = temp.areanum;
	temp = findArea(areaname);
	if (area[tempnum].areatype == "육지") {
		area[tempnum].arearesource->set_resource_gold(100);
	}
	else {
		area[tempnum].arearesource->set_resource_gold(10);
	}
}

void Map::set_acquirableWater(string areaname) {
	areainformation temp;
	int tempnum;
	tempnum = temp.areanum;
	temp = findArea(areaname);
	if (area[tempnum].areatype == "육지") {
		area[tempnum].arearesource->set_resource_water(30);
	}
	else {
		area[tempnum].arearesource->set_resource_water(100);
	}
}

int Map::get_acquirableFood(string areaname) {
	areainformation temp;
	int tempnum;
	temp = findArea(areaname);
	tempnum = temp.areanum;
	return area[tempnum].arearesource->get_resource_food();
}

int Map::get_acquirableGold(string areaname) {
	areainformation temp;
	int tempnum;
	temp = findArea(areaname);
	tempnum = temp.areanum;
	return area[tempnum].arearesource->get_resource_gold();
}

int Map::get_acquirableWater(string areaname) {
	areainformation temp;
	int tempnum;
	temp = findArea(areaname);
	tempnum = temp.areanum;
	return area[tempnum].arearesource->get_resource_water();
}


void Map::set_areaHost(Player* _host_player, string areaname) {
    areainformation temp;
    string host;
    int tempnum;
    temp = findArea(areaname);
    host = _host_player->get_player_name();
    tempnum = temp.areanum;
    area[tempnum].areahost = host;
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
		cout << temp.areaname << "는" << areaname << "아닙니다." << endl;
	}
	if (cnt == 0) {
		cout << areaname << "주인이 없습니다." << endl;
	}
}

Army Map::get_unitWhole(Player* _host_player) {
	string host;
	Army* temp;
	temp = new Army;
	temp->Cavalrycount=0;
	temp->Navycount=0;
	temp->Infantrycount=0;
	temp->Archercount=0;
	temp->Navy=new Unit_Navy();
	temp->Archer=new Unit_Archer();
	temp->cavalry = new Unit_Cavalry();
	temp->Infantry= new Unit_Infantry();
	int i;
	int cnt = 0;
	host = _host_player->get_player_name();
	for (i = 0; i < 30; i++) {
		if (host == area[i].areahost) {
			temp->Archercount += area[i].areaunit.Archercount;
			temp->Navycount += area[i].areaunit.Navycount;
			temp->Cavalrycount += area[i].areaunit.Cavalrycount;
			temp->Infantrycount += area[i].areaunit.Infantrycount;
			cnt++;
		}
	}
	return *temp;
	if (cnt == 0) {
		cout << host << "주인이 아닙니다." << endl;
	}
}

string Map::get_occupationPlayer(string areaname) {
	areainformation temp;
	temp = findArea(areaname);
	if (temp.areahost=="\0") {
		cout << areaname << "의 주인이 없습니다." << endl;
		return "\0";
	}
	else {
		return temp.areahost;
	}
}

Resource *Map::get_occupationCost(string areaname) {
	Resource *hi =new Resource();
	hi->set_resource_food(100);
	hi->set_resource_gold(100);
	hi->set_resource_water(100);
	return hi;
}

areainformation Map::get_areaInformation(string areaname) {
	areainformation temp;
	temp = findArea(areaname);
	return temp;
}

void Map::upgrade_Area(string areaname) {
	areainformation temp;
	int tempnum;
	temp = findArea(areaname);
	tempnum = temp.areanum;
	area[tempnum].arealevel++;
}

void Map::set_unit(string areaname, string tendency, int count) {
	areainformation temp;
	int tempnum;
	temp = findArea(areaname);
	tempnum = temp.areanum;
	if (tendency == "Infantry") {
		area[tempnum].areaunit.Infantrycount += count;
	}
	else if (tendency == "Navy") {
		area[tempnum].areaunit.Navycount += count;
	}
	else if (tendency == "Cavalry") {
		area[tempnum].areaunit.Cavalrycount += count;
	}
	else {
		area[tempnum].areaunit.Archercount += count;
	}
}

void Map::showAreaInformation(string areaname) {
	areainformation temp;
	int tempResource = 0;
	int tempCost = 0;
	temp = findArea(areaname);
	cout << "이름 :" << temp.areaname << endl;
	cout << "지역번호 :" << temp.areanum << endl;
	cout << "지역속성 :" << temp.areatype << endl;
	cout << "---이동 가능한 지역---" << endl;
	for (int i = 0; temp.neighborarea[i].size() != 0; i++) {
		cout << temp.neighborarea[i] << endl;
	}
	cout << "소유주 :" << temp.areahost << endl;
	cout << "---지역 병력---" << endl;
	cout << "궁병 :" << temp.areaunit.Archercount << endl;
	cout << "기병 :" << temp.areaunit.Cavalrycount << endl;
	cout << "보병 :" << temp.areaunit.Infantrycount << endl;
	cout << "수군 :" << temp.areaunit.Navycount << endl;
	cout << "---지역에서 얻을 수 있는 자원---" << endl;
	tempResource = temp.arearesource->get_resource_food();
	cout << "식량 :" << tempResource << endl;
	tempResource = temp.arearesource->get_resource_gold();
	cout << "금 :" << tempResource << endl;
	tempResource = temp.arearesource->get_resource_water();
	cout << "물 :" << tempResource << endl;
	cout << "---지역 점령 비용---" << endl;
	tempCost = temp.occupationcost->get_resource_food();
	cout << "식량 :" << tempCost << endl;
	tempCost = temp.occupationcost->get_resource_gold();
	cout << "금 :" << tempCost << endl;
	tempCost = temp.occupationcost->get_resource_water();
	cout << "물 :" << tempCost << endl;
}

int* Map::get_wholeArea(Player* _host_player) {
	string temp;
	temp = _host_player->get_player_name();
	int* wholeArea;
	wholeArea = new int [30];
	for (int i = 0; i < 30; i++) 
	{
        if (temp == area[i].areahost) 
		{
            wholeArea[i] = 1;
        }
		else
		{
			wholeArea[i] = 0;
		}
    }
	return wholeArea;
}

void Map::firstArea(Player* player, int i) {
    if (i == 1) {
        set_areaHost(player, "강남구");
    }
    else if (i == 2) {
        set_areaHost(player, "구로구");
    }
    else if (i == 3) {
        set_areaHost(player, "노원구");
    }
    else {
        set_areaHost(player, "은평구");
    }
}

int Map::areaLevel(string areaname) {
	areainformation temp;
	temp = findArea(areaname);
	return temp.arealevel;
}

bool Map::show_conquerAbleArea(string areaHost){
    int check=0;
    string semihost = areaHost+"(Semi)";
    cout << areaHost << "의 병력이 주둔하고 있는 지역을 표시합니다. " << endl;
    cout << "===================================================" << endl;
    for(int i=0; i<30; i++){
        if(game_master.get_gameMap()->findArea(i).areahost==semihost) {
            cout << game_master.get_gameMap()->findArea(i).areaname << endl;
            check=1;
        }
    }
    if(check==1)
        return true;
    else
        return false;

}

void Map::set_SemiareaHost(Player* _host_player, string areaname) {
    areainformation temp;
    string host;
    int tempnum;
    temp = findArea(areaname);
    host = _host_player->get_player_name()+"(Semi)";
    tempnum = temp.areanum;
    area[tempnum].areahost = host;
}

bool Map::isTrue(string areaname) {

	for (int i = 0; i < 30; i++) {
		if (area[i].areaname == areaname) {
			return true;
		}
	}
	return false;
}
#pragma clang diagnostic pop