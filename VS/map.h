#pragma once
class Map
{
private:
	char _area;
	(수정)(플레이어 클래스) 포인터변수->소유플레이어(class)* _host_player
	(수정)(자원 클래스) 변수 점령시 소득(class) _occupation_acquirable_resource
	(수정)(자원 클래스) 변수 점령비용(class) _occupation_cost
	int _area_level;
	int _acquirable_resource_water;
	int _acquirable_resource_gold;
	int _acquirable_resource_food;
	
public:
	void get_occupationPlayer();
	void get_occupationCost();
	void get_acquirableResource();
	void get_upgradeCost();
	void get_movableArea();

	void set_occupationCost();

	int calBattle();
	
	
};