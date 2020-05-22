#include "resource.h"
//#include "player.h"
#pragma once
using namespace std;
class Unit
{
private:

protected:
	int _unit_type;//���� infantry(����)=0, Archer(�ü�)=1, Cavalry(�⺴)=2, Navy(����)=3
	int _attack_damage;//���� infantry(����)=10, Archer(�ü�)=10, Cavalry(�⺴)=20, Navy(����)=20
	int _hit_point;//ü�� infantry(����)=50, Archer(�ü�)=30, Cavalry(�⺴)=100, Navy(����)=20
	int _resource_gold;//�� infantry(����)=10, Archer(�ü�)=10, Cavalry(�⺴)=20, Navy(����)=10
	int _resource_water;//�� infantry(����)=10, Archer(�ü�)=5, Cavalry(�⺴)=10, Navy(����)=20
	int _resource_food;//���� infantry(����)=10, Archer(�ü�)=5, Cavalry(�⺴)=10, Navy(����)=20
	int _troop_production;//���ϻ��꺴�� infantry(����)=50, Archer(�ü�)=3, Cavalry(�⺴)=2, Navy(����)=2
	int _moving_range;//�����̵����� infantry(����)=2, Archer(�ü�)=1, Cavalry(�⺴)=3, Navy(����)=2
	int _moving_area_type;//�̵��� �� �ִ� ���� Ư��	--�����ʿ�--	��=0, ��=1, ��+��=2		infantry(����)=0(��������-upgrade to 2), Archer(�ü�)=0, Cavalry(�⺴)=0, Navy(����)=2
	int _attack_range;//���ݰ��ɹ��� infantry(����)=0, Archer(�ü�)=1, Cavalry(�⺴)=0, Navy(����)=2

public:
	//constructor

	Unit();
	//Unit(int);

	//�Ҹ���

	//~Unit();

	/*Unit::Unit(int new_UnitType, int new_AttackDamage, int new_Hitpoint, int new_Resource_Gold, int new_Resource_Water, int new_Resource_Food, int new_TroopProduction, int new_MovingRange, int new_MovingAreaType, int new_AttackRange){
		UnitType=new_UnitType;
		AttackDamage=new_AttackDamage;
		HitPoint=new_HitPoint;
		Resource_Gold=new_Resource_Gold;
		Resource_Water=new_Resource_Water;
		Resource_Food=new_Resource_Food;
		TroopProduction=new_TroopProduction;
		MovingRange=new_MovingRange;
		MovingAreaType=new_MovingAreaType;
		AttackRange=new_AttackRange;
	}*/ //�����ڵ��� ���߿� ����

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

	//�Լ�
	//void pro.product(tendency, product_count);//����, ���� ���� ���ڷ�->palyer���� ��ȸ�ؼ� ���갡������ �˻�
};


//����
class Unit_Infantry : public Unit{
private:
	//int UnitType=0;
protected:

public:
	//������
	//Unit_Infantry(int new_unit_type, int new_attack_damage, int new_hit_point, int new_resource_gold, int new_resource_water, int new_resource_food, int new_troop_production, int new_moving_range, int new_moving_area_type, int new_attack_range) :Unit(new_unit_type, new_attack_damage, new_hit_point, new_resource_gold, new_resource_water, new_resource_food, new_troop_production, new_moving_range, new_moving_area_type, new_attack_range) {};
	Unit_Infantry();
};

//�ü�
class Unit_Archer : public Unit{
private:
	
protected:

public:
	//������
	Unit_Archer();
};

//�⺴
class Unit_Cavalry : public Unit{
private:
	
protected:

public:
	//������
	Unit_Cavalry();
};

//����
class Unit_Navy : public Unit{
private:

protected:

public:
	//������
	Unit_Navy();
};