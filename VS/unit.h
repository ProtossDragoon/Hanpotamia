#pragma once
class Unit
{
private:

protected:
	int UnitType;//Unit종류
	int AttackDamage;//공격
	int HitPoint;//체력
	int Resource_Gold;//금
	int Resource_Water;//물
	int Resource_Food;//음식
	int TroopProduction;//한턴생산병력
	int MovingRange;//한턴이동범위
	int MovingAreaType;//이동할 수 있는 지역 특성
	int AttackRange;//공격가능범위

public:
	//생성자


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
	}*/ //생성자들은 나중에 수정

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


//상속하는 파생클래스들은 Unit클래스의 멤버변수들에 각각의 값을 가지고 있다(생성자를 호출할 때 따로 숫자를 넣을 필요가 없다)
class Unit_Infantry {
private:
	int UnitType;
protected:

public:
	//생성자
	Unit_Infantry(int new_UnitType = 0, int new_AttackDamage = 0, int new_Hitpoint = 0, int new_Resource_Gold = 0, int new_Resource_Water = 0, int new_Resource_Food, int new_TroopProduction, int new_MovingRange, int new_AttackRange) :Unit(new_AttackDamage, new_Hitpoint, new_Resource_Gold, new_Resource_Water, new_Resource_Food, new_TroopProduction, new_MovingRange, new_AttackRange) {};

	//Unit.cpp
	//Unit_Infantry::Unit_Infantry(int new_UnitType, int new_AttackDamage, int new_Hitpoint, int new_Resource_Gold, int new_Resource_Water, int new_Resource_Food, int new_TroopProduction, int new_MovingRange, int new_AttackRange)):Unit(new_AttackDamage, new_Hitpoint, new_Resource_Gold, new_Resource_Water, new_Resource_Food, new_TroopProduction, new_MovingRange, new_AttackRange){//파생클래스Unit_Infantry의 생성자에서 받은 매개변수의 값을 기반클래스Unit에 전달
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
	//생성자

};

class Unit_Cavalry {
private:

protected:

public:
	//생성자

};

class Unit_Navy {
private:

protected:

public:
	//생성자

};