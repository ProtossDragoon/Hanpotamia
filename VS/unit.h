#pragma once
class Unit
{
private:

protected:
	AttackDamage//����
	HitPoint//ü��
	Resource_Gold//��
	Resource_Water//��
	Resource_Food//����
	TroopProduction//���ϻ��꺴��
	MovingRange//�����̵�����
	AttackRange//���ݰ��ɹ���

public:
	//������
	Unit::Unit(){
		AttackDamage=0;
		HitPoint=0;
		Resource_Gold=0;
		Resource_Water=0;
		Resource_Food=0;
		TroopProduction=0;
		MovingRange=0;
		AttackRange=0;
	}
	/*Unit::Unit(int new_AttackDamage, int new_Hitpoint, int new_Resource_Gold, int new_Resource_Water, int new_Resource_Food, int new_TroopProduction, int new_MovingRange, int new_AttackRange){
		AttackDamage=new_AttackDamage;
		HitPoint=new_HitPoint;
		Resource_Gold=new_Resource_Gold;
		Resource_Water=new_Resource_Water;
		Resource_Food=new_Resource_Food;
		TroopProduction=new_TroopProduction;
		MovingRange=new_MovingRange;
		AttackRange=new_AttackRange;
	}*/ //�����ڵ��� ���߿� ����

	//setter
	void setAttackDamage();
	void setHitPoint();
	void setResource_Gold();
	void setResource_Water();
	void setResource_Food();
	void set1TurnTroopProduction();
	void set1TurnMovingRange();
	void set1TurnAttackRange();

	//getter
	int getAttackDamage();
	int getHitPoint();
	int getResource_Gold();
	int getResource_Water();
	int getResource_Food();
	int get1TurnTroopProduction();
	int get1TurnMovingRange();
	int get1TurnAttackRange();
};


//����ϴ� �Ļ�Ŭ�������� UnitŬ������ ��������鿡 ������ ���� ������ �ִ�(�����ڸ� ȣ���� �� ���� ���ڸ� ���� �ʿ䰡 ����)
class Unit_Infantry{
private:

protected:

public:
	//������
	//Unit_Infantry::Unit_Infantry(int new_AttackDamage, int new_Hitpoint, int new_Resource_Gold, int new_Resource_Water, int new_Resource_Food, int new_TroopProduction, int new_MovingRange, int new_AttackRange)):Unit(new_AttackDamage, new_Hitpoint, new_Resource_Gold, new_Resource_Water, new_Resource_Food, new_TroopProduction, new_MovingRange, new_AttackRange){//�Ļ�Ŭ����Unit_Infantry�� �����ڿ��� ���� �Ű������� ���� ���Ŭ����Unit�� ����
	//	
	//}

};

class Unit_Archer{
private:

protected:

public:
	//������

};

class Unit_Cavalry{
private:

protected:

public:
	//������

};

class Unit_Navy{
private:

protected:

public:
	//������

};
