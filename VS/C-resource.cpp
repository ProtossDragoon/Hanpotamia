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

Resource Resource::calculate_produce_unit(string tendency, int cnt)
{
	Resource troop;
	if (tendency=="Navy") {
		troop.set_resource_food(get_);
	}
}

void Resource::calculate_upgrade_area() 
{

}