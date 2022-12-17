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
        bool trySpawn(){
            if(spawnChance == 0){
                return false;
            }else return true;
        }
        bool tryDeathRot(){
            if(deathRotChance == 0){
                return false;
            }else return true;
        }
};

class food: public Object, public Actions{
    bool testR = tryDeathRot();
    public:
        void rot(){
            if(testR){
                //code to remove food
                foods--;
            }
        }
        
};

class creature: public Object, public Actions{
    float reproduceChance = 0;
    creature();
    bool testD = tryDeathRot();
    bool rep = tryReproduction();
    public:
        bool tryReproduction(){
            if(reproduceChance == 0){
                return false;
            }else return true;
        }
        void reproduction(){
            if(rep){
                createCreature();
            }
        }
        void die(){
            if(testD){
                creatures--;
            }
        }
};

class world: public Actions, public Object{
    bool test = trySpawn();
    
    public:
        void createCreature(){
            if(test){
                creatures++;
            }
        }
        void createFood(){
            if(test){
                foods++;
            }
        }
};
int main(){
    int N = 1;
    world w1;
    for(int i = 0; i<5; i++){
    w1.setSpawn(rand() % N);
    w1.createCreature();
    }
   
    return 0;
};