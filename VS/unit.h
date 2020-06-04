#include "resource.h"
#include <iostream>
//#include "player.h"
#pragma once
using namespace std;
class Unit
{
private:

protected:
	int _unit_type;//���� Infantry(����)=0, Archer(�ü�)=1, Cavalry(�⺴)=2, Navy(����)=3
	int _attack_damage;//���� infantry(����)=10, Archer(�ü�)=10, Cavalry(�⺴)=20, Navy(����)=20
	int _hit_point;//ü�� infantry(����)=50, Archer(�ü�)=30, Cavalry(�⺴)=100, Navy(����)=20
	int _resource_gold;//�� infantry(����)=10, Archer(�ü�)=10, Cavalry(�⺴)=20, Navy(����)=10
	int _resource_water;//�� infantry(����)=10, Archer(�ü�)=5, Cavalry(�⺴)=10, Navy(����)=20
	int _resource_food;//���� infantry(����)=10, Archer(�ü�)=5, Cavalry(�⺴)=10, Navy(����)=20
	int _troop_production;//���ϻ��꺴�� infantry(����)=50, Archer(�ü�)=3, Cavalry(�⺴)=2, Navy(����)=2
	int _moving_range;//�����̵����� infantry(����)=2, Archer(�ü�)=1, Cavalry(�⺴)=3, Navy(����)=2
	int _moving_area_type;//�̵��� �� �ִ� ���� Ư��	--�����ʿ�--	��=0, ��=1, ��+��=2		infantry(����)=0(��������-upgrade to 2), Archer(�ü�)=0, Cavalry(�⺴)=0, Navy(����)=2
	int _attack_range;//���ݰ��ɹ��� infantry(����)=0, Archer(�ü�)=1, Cavalry(�⺴)=0, Navy(����)=2
	int _unit_cnt;//���ּ�

public:
	//constructor

	Unit();
	//Unit(int);

	//�Ҹ���
	~Unit();


	//setter ��ǻ� �ʿ������
	void set_unit_type(int type);
	void set_attack_damage(int attackdamage);
	void set_hit_point(int hp);
	void set_resource_gold(int gold);
	void set_resource_water(int water);
	void set_resource_food(int food);
	void set_troop_production(int troopproduction);
	void set_moving_range(int movingrange);
	void set_moving_area_type(int movingareatype);//������ ������ �ٴҼ� �ְ� �Ѵٸ� ���
	void set_attack_range(int attackrange);
	void set_unit_cnt(int cnt);

	//getter
	int get_unit_type() { return _unit_type; };
	int get_attack_damage() { return _attack_damage; };
	int get_hit_point() { return _hit_point; };
	int get_resource_gold() { return _resource_gold; };
	int get_resource_water() { return _resource_water; };
	int get_resource_food() { return _resource_food; };
	int get_troop_production() { return _troop_production; };
	int get_moving_range() { return _moving_range; };
	int get_moving_area_type() { return _moving_area_type; };
	int get_attack_range() { return _attack_range; };
	int get_unit_cnt() { return _unit_cnt; };

	//�Լ�

	//������ ���� �޾Ƽ� map�� �Լ��߰�
	void UnitProduct(string tendency, int product_count);


	//Unit��ü���� ������ �� �Լ�
	void AddUnit();

	//��������ݿ��Լ� ��ü��, ��������, �����̸�
	void calcualte_unit();

};


//����
class Unit_Infantry : public Unit{
private:
	
protected:

public:
	//������
	Unit_Infantry();
	//�Ҹ���
	~Unit_Infantry();
};

//�ü�
class Unit_Archer : public Unit{
private:
	
protected:

public:
	//������
	Unit_Archer();
	//�Ҹ���
	~Unit_Archer();
};

//�⺴
class Unit_Cavalry : public Unit{
private:
	
protected:

public:
	//������
	Unit_Cavalry();
	//�Ҹ���
	~Unit_Cavalry();
};

//����
class Unit_Navy : public Unit{
private:

protected:

public:
	//������
	Unit_Navy();
	//�Ҹ���
	~Unit_Navy();
};