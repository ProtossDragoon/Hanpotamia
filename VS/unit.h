#pragma once
class Unit
{
private:

protected:
	int UnitType;//Unit����
	int AttackDamage;//����
	int HitPoint;//ü��
	int Resource_Gold;//��
	int Resource_Water;//��
	int Resource_Food;//����
	int TroopProduction;//���ϻ��꺴��
	int MovingRange;//�����̵�����
	int MovingAreaType;//�̵��� �� �ִ� ���� Ư��
	int AttackRange;//���ݰ��ɹ���

public:
	//������


	/*Unit::Unit() {
		UnitType = 0;
		AttackDamage = 0;
		HitPoint = 0;
		Resource_Gold = 0;
		Resource_Water = 0;
		Resource_Food = 0;
		TroopProduction = 0;
		MovingRange = 0;
		MovingAreaType = 0;
		AttackRange = 0;
	}*/


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

	//setter
	void setUnitType();
	void setAttackDamage();
	void setHitPoint();
	void setResource_Gold();
	void setResource_Water();
	void setResource_Food();
	void setTroopProduction();
	void setMovingRange();
	void setAttackRange();

	//getter
	int getUnitType();
	int getAttackDamage();
	int getHitPoint();
	int getResource_Gold();
	int getResource_Water();
	int getResource_Food();
	int getTroopProduction();
	int getMovingRange();
	int getAttackRange();
};


//����ϴ� �Ļ�Ŭ�������� UnitŬ������ ��������鿡 ������ ���� ������ �ִ�(�����ڸ� ȣ���� �� ���� ���ڸ� ���� �ʿ䰡 ����)
class Unit_Infantry {
private:
	int UnitType;
protected:

public:
	//������
	Unit_Infantry(int new_UnitType = 0, int new_AttackDamage = 0, int new_Hitpoint = 0, int new_Resource_Gold = 0, int new_Resource_Water = 0, int new_Resource_Food, int new_TroopProduction, int new_MovingRange, int new_AttackRange) :Unit(new_AttackDamage, new_Hitpoint, new_Resource_Gold, new_Resource_Water, new_Resource_Food, new_TroopProduction, new_MovingRange, new_AttackRange) {};

	//Unit.cpp
	//Unit_Infantry::Unit_Infantry(int new_UnitType, int new_AttackDamage, int new_Hitpoint, int new_Resource_Gold, int new_Resource_Water, int new_Resource_Food, int new_TroopProduction, int new_MovingRange, int new_AttackRange)):Unit(new_AttackDamage, new_Hitpoint, new_Resource_Gold, new_Resource_Water, new_Resource_Food, new_TroopProduction, new_MovingRange, new_AttackRange){//�Ļ�Ŭ����Unit_Infantry�� �����ڿ��� ���� �Ű������� ���� ���Ŭ����Unit�� ����
	//	UnitType = new_UnitType;
	//	AttackDamage = new_AttackDamage;
	//	HitPoint = new_HitPoint;
	//	Resource_Gold = new_Resource_Gold;
	//	Resource_Water = new_Resource_Water;
	//	Resource_Food = new_Resource_Food;
	//	TroopProduction = new_TroopProduction;
	//	MovingRange = new_MovingRange;
	//	AttackRange = new_AttackRange;
	//}

};

class Unit_Archer {
private:

protected:

public:
	//������

};

class Unit_Cavalry {
private:

protected:

public:
	//������

};

class Unit_Navy {
private:

protected:

public:
	//������

};