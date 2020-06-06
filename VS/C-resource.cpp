#include "resource.h"
#include "string.h"

////construtor
//Resource::Resource() {
//
//}

void Resource::set_resource_gold(int gold)
{
	_resource_gold = gold;
}
void Resource::set_resource_food(int food)
{
	_resource_food = food;
}
void Resource::set_resource_water(int water)
{
	_resource_water = water;
}

//void Resource::set_resource_gold(int areatype, int gold)
//{
//	if (areatype == 0)//areatype==0 -> ground
//	{
//		//1.  _resource_gold += 100;
//		//2.  _resource_gold += gold;
//	}
//	else if (areatype == 1)//areatype==1 -> water
//	{
//		//1.  _resource_gold += 10;
//		//2.  _resource_gold += gold;
//	}
//	cout << " " << endl;
//	/*else if (areatype == 2)areatype==2 -> ground&&water
//	{
//
//	}*/
//}

//unit�� ������ ���� �޾Ƽ� �ʿ��� �ڿ��� ���
Resource Resource::calculate_produce_unit(string tendency, int cnt)
{
	Resource troop;
	if (tendency=="Infantry")
	{
		troop.set_resource_gold(cnt * 10);
		troop.set_resource_water(cnt * 10);
		troop.set_resource_food(cnt * 10);
	}
	else if (tendency == "Archer")
	{
		troop.set_resource_gold(cnt * 10);
		troop.set_resource_water(cnt * 5);
		troop.set_resource_food(cnt * 5);
	}
	else if (tendency == "Cavalry")
	{
		troop.set_resource_gold(cnt * 20);
		troop.set_resource_water(cnt * 10);
		troop.set_resource_food(cnt * 10);
	}
	else if (tendency == "Navy")
	{
		troop.set_resource_gold(cnt * 10);
		troop.set_resource_water(cnt * 20);
		troop.set_resource_food(cnt * 20);
	}
	return troop;
}


//player�� �ڿ��� �ʿ��� �ڿ��� ���Ͽ� �ൿ�� ����Ǵ��� Ȯ��
bool Resource::check_resource(Resource *player, Resource *need) 
{
	int i=0;
	if (player->get_resource_food() >= need->get_resource_food) i++;
	if (player->get_resource_water() >= need->get_resource_water) i++;
	if (player->get_resource_gold() >= need->get_resource_gold) i++;
	if (i == 3) return true;
	else
	{
		cout << "�ڿ��� �����մϴ�!" << endl;
		return false;
	}
}

void Resource::calculate_upgrade_area() 
{

}