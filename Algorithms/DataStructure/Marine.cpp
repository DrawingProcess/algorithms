#include <iostream>

class Marine {
    static int total_marine_num;
    int hp;
    int coord_x, coord_y;
    int damage;
    bool is_dead;
    char* name;

public:
    Marine();
    Marine(int x, int y);
    Marine(int x, int y, const char* marine_name);
    ~Marine();
    Marine(const Marine &ma);

    int attack();
    void be_attacked(int damage_earn);
    void move(int x, int y);

    void show_status();
}
int Marine::total_marine_num = 0;

Marine::Marine() 
    : hp(50), coord_x(0), coord_y(0), damage(5), is_dead(false), name(NULL) {}
Marine::Marine(int x, int y){
    hp = 50;
    coord_x = x;
    coord_y = y;
    damage = 5;
    is_dead = false;
    name = NULL;
}
Marine::Marine(int x, int y, const char* name){
    name = new char[strlen(marine_name) + 1];
    strcpy(name, marine_name);

    hp = 50;
    coord_x = x;
    coord_y = y;
    damage = 5;
    is_dead = false;
}
Marine::Marine(const Marine &ma) {
    
    name = new char[strlen(ma.name) + 1];
    strcpy(name, ma.name);
    hp = ma.hp;
    coord_x = ma.coord_x;
    coord_y = ma.coord_y;
    damage = ma.damage;
    is_dead = ma.is_dead;
}
Marine::~Marine(){
    if (name != NULL){
        delete[] name;
    }
}

void Marine::move(int x, int y) {
  coord_x = x;
  coord_y = y;
}
int Marine::attack() { return damage; }
void Marine::be_attacked(int damage_earn) {
  hp -= damage_earn;
  if (hp <= 0) is_dead = true;
}
void Marine::show_status() {
  std::cout << " *** Marine *** " << std::endl;
  std::cout << " Location : ( " << coord_x << " , " << coord_y << " ) "
            << std::endl;
  std::cout << " HP : " << hp << std::endl;
}

int main() {
    Marine* marines[100];
    marines[0] = new Marine(2, 3);
    marines[1] = new Marine(2, 3);

    marines[0]->show_status();
    marines[1]->show_status();
    
    std::cout << std::endl << "마린 1 이 마린 2 를 공격! " << std::endl;
    
    marines[0]->be_attacked(marines[1]->attack());
    
    marines[0]->show_status();
    marines[1]->show_status();
    
    delete marines[0];
    delete marines[1];
}