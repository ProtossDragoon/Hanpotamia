#pragma once
class Unit
{
private:

protected:
	AttackDamage//공격
	HitPoint//체력
	Resource_Gold//금
	Resource_Water//물
	Resource_Food//음식
	TroopProduction//한턴생산병력
	MovingRange//한턴이동범위
	AttackRange//공격가능범위

public:
	//생성자
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
	}*/ //생성자들은 나중에 수정

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


//상속하는 파생클래스들은 Unit클래스의 멤버변수들에 각각의 값을 가지고 있다(생성자를 호출할 때 따로 숫자를 넣을 필요가 없다)
class Unit_Infantry{
private:

protected:

public:
	//생성자
	//Unit_Infantry::Unit_Infantry(int new_AttackDamage, int new_Hitpoint, int new_Resource_Gold, int new_Resource_Water, int new_Resource_Food, int new_TroopProduction, int new_MovingRange, int new_AttackRange)):Unit(new_AttackDamage, new_Hitpoint, new_Resource_Gold, new_Resource_Water, new_Resource_Food, new_TroopProduction, new_MovingRange, new_AttackRange){//파생클래스Unit_Infantry의 생성자에서 받은 매개변수의 값을 기반클래스Unit에 전달
	//	
	//}

};

class Unit_Archer{
private:

protected:

public:
	//생성자

};

class Unit_Cavalry{
private:

protected:

public:
	//생성자

};

class Unit_Navy{
private:

protected:

public:
	//생성자

};
