
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
    void add_resource_gold(int gold);
    void add_resource_food(int food);
    void add_resource_water(int water);

    //func
    //플레이어가 보유한 자원과 필요한 자원의 양을 비교하여 행동을 수행할 수 있는지 확인
    bool check_resource(Resource* player, Resource* need);
    //유닛을 생산하는데 필요한 자원양계산
    Resource * calculate_produce_unit(string tendency, int cnt);
};