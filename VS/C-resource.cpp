#include "resource.h"
#include "string.h"

////construtor
Resource::Resource() {
    _resource_gold = 0;
    _resource_water = 0;
    _resource_food = 0;
}
Resource::~Resource() {}

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



Resource *Resource::calculate_produce_unit(string tendency, int cnt)
{
    Resource *troop=NULL;
    if (tendency=="Infantry")
    {
        troop->set_resource_gold(cnt * 10);
        troop->set_resource_water(cnt * 10);
        troop->set_resource_food(cnt * 10);
    }
    else if (tendency == "Archer")
    {
        troop->set_resource_gold(cnt * 10);
        troop->set_resource_water(cnt * 5);
        troop->set_resource_food(cnt * 5);
    }
    else if (tendency == "Cavalry")
    {
        troop->set_resource_gold(cnt * 20);
        troop->set_resource_water(cnt * 10);
        troop->set_resource_food(cnt * 10);
    }
    else if (tendency == "Navy")
    {
        troop->set_resource_gold(cnt * 10);
        troop->set_resource_water(cnt * 20);
        troop->set_resource_food(cnt * 20);
    }
    return troop;
}


//player
bool Resource::check_resource(Resource *player, Resource *need)
{
    int i=0;
    if (player->get_resource_food() >= need->get_resource_food()) i++;
    if (player->get_resource_water() >= need->get_resource_water()) i++;
    if (player->get_resource_gold() >= need->get_resource_gold()) i++;
    if (i == 3) 
    {
        player->set_resource_food(player->get_resource_food() - need->get_resource_food());
        player->set_resource_gold(player->get_resource_gold() - need->get_resource_gold());
        player->set_resource_water(player->get_resource_water() - need->get_resource_water());
        return true;
    }
    else
    {
        cout << " no resource!" << endl;
        return false;
    }
}