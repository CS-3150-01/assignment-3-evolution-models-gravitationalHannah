#include <stdio.h>
#include <iostream>
using namespace std;

int creatures;
int foods;

class Actions{
    public:
        void createCreature(){
            creatures++;
        };
        void createFood(){
            foods++;
        };

};

class Object{
    int position;
    float spawnChance = 1;
    float deathRotChance = 0;
    public:
        int getPosition(){
            return position;
        }
        void setPosition(int newPosition){
            position = newPosition;
        }
        void setSpawn(float newSpawnChance){
            spawnChance = newSpawnChance;
        }
        void setDeath(float newDeathRotChance){
            deathRotChance = newDeathRotChance;
        }
        bool trySpawn(int spawnChance){
            if(spawnChance == 0){
                return false;
            }else return true;
        }
        bool tryDeathRot(int deathRotChance){
            if(deathRotChance == 0){
                return false;
            }else return true;
        }
};

class food: public Object, public Actions{
    private:
        void rot(bool tryDeathRot){
            if(tryDeathRot){
                //code to remove food
                foods--;
            }
        }
        
};

class creature: public Object, public Actions{
    float reproduceChance;
    private:
        bool tryReproduction(int reproduceChance){
            if(reproduceChance == 0){
                return false;
            }else return true;
        }
        void reproduction(bool reproduceChance){
            if(reproduceChance){
                createCreature();
            }
        }
        void die(bool tryDeathRot){
            if(tryDeathRot){
                creatures--;
            }
        }
};

class world: public Actions, public Object{
    
    public:
        void createCreature(bool trySpawn){
            if(trySpawn){
                creatures++;
            }
        }
        void createFood(bool trySpawn){
            if(trySpawn){
                foods++;
            }
        }
};
int main(){
    int N = 1;
    world w1;
    for(int i = 0; i<5; i++){
        int a = rand() % N;
         w1.setSpawn(a);
         bool test = w1.trySpawn(a);
         w1.createCreature(test);
    }
   
    return 0;
};