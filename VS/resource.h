
#pragma once
#include "string.h"
#include <iostream>
using namespace std;

class Resource
{
    //
private:
    int _resource_gold;
    int _resource_water;
    int _resource_food;

protected:
    //xx

public:
    ////constructor
    Resource();
    ~Resource();

    //getter
    int get_resource_gold() { return _resource_gold; };
    int get_resource_food() { return _resource_food; };
    int get_resource_water() { return _resource_water; };

    //setter
    void set_resource_gold(int gold);
    void set_resource_food(int food);
    void set_resource_water(int water);

    //func

    bool check_resource(Resource* player, Resource* need);
    ////??ª©ë³„ë¡œ ?„ìš”?©ë‹ˆ??

    Resource * calculate_produce_unit(string tendency, int cnt);
};