#pragma once
class Map
{
private:
	char _area;
	(����)(�÷��̾� Ŭ����) �����ͺ���->�����÷��̾�(class)* _host_player
	(����)(�ڿ� Ŭ����) ���� ���ɽ� �ҵ�(class) _occupation_acquirable_resource
	(����)(�ڿ� Ŭ����) ���� ���ɺ��(class) _occupation_cost
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