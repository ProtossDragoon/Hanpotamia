#include "resource.h"
#include <iostream>
//#include "player.h"
#pragma once
using namespace std;
class Unit
{
private:

protected:
    string _unit_type;//ë³‘ì¢… Infantry(ë³´ë³‘)=0, Archer(ê¶ìˆ˜)=1, Cavalry(ê¸°ë³‘)=2, Navy(?˜êµ°)=3
    int _attack_damage;//ê³µê²© infantry(ë³´ë³‘)=10, Archer(ê¶ìˆ˜)=10, Cavalry(ê¸°ë³‘)=20, Navy(?˜êµ°)=20
    int _hit_point;//ì²´ë ¥ infantry(ë³´ë³‘)=50, Archer(ê¶ìˆ˜)=30, Cavalry(ê¸°ë³‘)=100, Navy(?˜êµ°)=20
    int _resource_gold;//ê¸?infantry(ë³´ë³‘)=10, Archer(ê¶ìˆ˜)=10, Cavalry(ê¸°ë³‘)=20, Navy(?˜êµ°)=10
    int _resource_water;//ë¬?infantry(ë³´ë³‘)=10, Archer(ê¶ìˆ˜)=5, Cavalry(ê¸°ë³‘)=10, Navy(?˜êµ°)=20
    int _resource_food;//?Œì‹ infantry(ë³´ë³‘)=10, Archer(ê¶ìˆ˜)=5, Cavalry(ê¸°ë³‘)=10, Navy(?˜êµ°)=20
    int _troop_production;//?œí„´?ì‚°ë³‘ë ¥ infantry(ë³´ë³‘)=50, Archer(ê¶ìˆ˜)=3, Cavalry(ê¸°ë³‘)=2, Navy(?˜êµ°)=2
    int _moving_range;//?œí„´?´ë™ë²”ìœ„ infantry(ë³´ë³‘)=2, Archer(ê¶ìˆ˜)=1, Cavalry(ê¸°ë³‘)=3, Navy(?˜êµ°)=2
    int _moving_area_type;//?´ë™?????ˆëŠ” ì§€???¹ì„±	--?˜ì •?„ìš”--	??0, ë¬?1, ??ë¬?2		infantry(ë³´ë³‘)=0(?˜ì •?¬í•­-upgrade to 2), Archer(ê¶ìˆ˜)=0, Cavalry(ê¸°ë³‘)=0, Navy(?˜êµ°)=2
    int _attack_range;//ê³µê²©ê°€?¥ë²”??infantry(ë³´ë³‘)=1, Archer(ê¶ìˆ˜)=2, Cavalry(ê¸°ë³‘)=1, Navy(?˜êµ°)=3
    int _unit_cnt;//? ë‹›??
public:
    //constructor

    Unit();
    //Unit(int);

    //?Œë©¸??    
	~Unit();


    //setter
    void set_unit_type(string type);
    void set_attack_damage(int attackdamage);
    void set_hit_point(int hp);
    void set_resource_gold(int gold);
    void set_resource_water(int water);
    void set_resource_food(int food);
    void set_troop_production(int troopproduction);
    void set_moving_range(int movingrange);
    void set_moving_area_type(int movingareatype);//ë³´ë³‘??ë¬¼ì—???¤ë‹???ˆê²Œ ?œë‹¤ë©??¬ìš©
    void set_attack_range(int attackrange);
    void set_unit_cnt(int cnt);

    //getter
    string get_unit_type() { return _unit_type; };
    int get_attack_damage() { return _attack_damage; };
    int get_hit_point() { return _hit_point; };
    int get_resource_gold() { return _resource_gold; };
    int get_resource_water() { return _resource_water; };
    int get_resource_food() { return _resource_food; };
    int get_troop_production() { return _troop_production; };
    int get_moving_range() { return _moving_range; };
    int get_moving_area_type() { return _moving_area_type; };
    int get_attack_range() { return _attack_range; };
    int get_unit_cnt() { return _unit_cnt; };

    //?¨ìˆ˜

 

    //º´·ÂÀÌ °ø°İÇØ¼­ º¯È­ÇÏ´Â »ó´ëº´·ÂÀÇ ¼ö¸¦ °è»ê   
	virtual void calculate_unit(string to, string undetattack_tendency, string attack_tendency, int cnt);

};


//ë³´ë³‘
class Unit_Infantry : public Unit{
private:

protected:

public:
    //?ì„±??    
	Unit_Infantry();
    //?Œë©¸??    
	~Unit_Infantry();
    //º´·ÂÀÌ °ø°İÇØ¼­ º¯È­ÇÏ´Â »ó´ëº´·ÂÀÇ ¼ö¸¦ °è»ê   
    virtual void calculate_unit(string to, string undetattack_tendency, string attack_tendency, int cnt);
};

//ê¶ìˆ˜
class Unit_Archer : public Unit{
private:

protected:

public:
    //?ì„±??    
	Unit_Archer();
    //?Œë©¸??    
	~Unit_Archer();
    //º´·ÂÀÌ °ø°İÇØ¼­ º¯È­ÇÏ´Â »ó´ëº´·ÂÀÇ ¼ö¸¦ °è»ê   
    virtual void calculate_unit(string to, string undetattack_tendency, string attack_tendency, int cnt);
};

//ê¸°ë³‘
class Unit_Cavalry : public Unit{
private:

protected:

public:
    //?ì„±??    
	Unit_Cavalry();
    //?Œë©¸??    
	~Unit_Cavalry();
    //º´·ÂÀÌ °ø°İÇØ¼­ º¯È­ÇÏ´Â »ó´ëº´·ÂÀÇ ¼ö¸¦ °è»ê   
    virtual void calculate_unit(string to, string undetattack_tendency, string attack_tendency, int cnt);
};

//?˜êµ°
class Unit_Navy : public Unit{
private:

protected:

public:
    //?ì„±??    
	Unit_Navy();
    //?Œë©¸??    
	~Unit_Navy();
    //º´·ÂÀÌ °ø°İÇØ¼­ º¯È­ÇÏ´Â »ó´ëº´·ÂÀÇ ¼ö¸¦ °è»ê   
    virtual void calculate_unit(string to, string undetattack_tendency, string attack_tendency, int cnt);
};