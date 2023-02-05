#include <iostream>
#include <string>
#include <vector>
using namespace std;

// install base ropot class

class ropot{
    private:
        string name;
        
        float brttary_live;
    public:
        ropot(string namee, float brttary_livee){
            name = namee;
            brttary_live=brttary_livee;
        }
        float get_brttary (){
            return brttary_live;
        }
        string get_name (){
            return name;
        }
        void RechargeBattery(){
            brttary_live=100;
        }
        void DecreaseBatteryLevel (float amount ){
            brttary_live -= amount;
            if(brttary_live <= 0 ){
                RechargeBattery();
            }


        }
        int compare(ropot * x){
            if(get_brttary () > x ->get_brttary()){
                return 1;
            }else if(get_brttary () < x ->get_brttary()) {
                return -1;
            }else{
                return 0;
            }
        }
        virtual string get_type() = 0;
        void Attack(ropot * x){
            if(x=this){
                cout << "same ropot"<<endl;
            }
           else if(this->get_type() == "DefensiveRobot"&& x->get_type() == "DefensiveRobot"){
            if(this->compare(x) == 1){
                x->DecreaseBatteryLevel(30);

            }else if(this->compare(x) == -1){
                this->DecreaseBatteryLevel(30);
            }
           }else if(this->get_type() == "DefensiveRobot"&& x->get_type() == "NormalRobot"){
                x->DecreaseBatteryLevel(30);
           } else if (this->get_type() == "NormalRobot"&& x->get_type() == "DefensiveRobot"){
            this->DecreaseBatteryLevel(30);
           }
         

        }
        void print(){
            cout << "type is "<< this ->get_type()<<endl;
            cout << "bettary is "<< this ->get_brttary ()<<endl;
            cout << "name is "<< this ->get_name ()<<endl;
         }
       
};



// install DefensiveRobot

class DefensiveRobot : public ropot{
    private:
        string type = "DefensiveRobot";
        int fire_power;
    public:
        DefensiveRobot(string name, float brttary_live,int fire_powere):ropot(name, brttary_live){
            fire_power=fire_powere;
        }
        void SetFirePower(float amount){
            fire_power = amount;
        }
        int GetFirePower(){
            return fire_power;
        }
         string get_type(){
            return type;
         }
         
       
};



// install NormalRobot

class NormalRobot : public ropot{
     private:
        string type = "NormalRobot";
     public:
         NormalRobot(string name, float brttary_live):ropot(name, brttary_live){}
         string get_type(){
            return type;
         }
};









int main(){
    DefensiveRobot d1("mrckatron" , 70 , 30);
    DefensiveRobot d2("mrckatron" , 60 , 30);
    NormalRobot n1("prime",30);
    ropot *y;
    y = &d1;
    ropot *x;
    x = &n1;
    ropot *z;
    z = &d2;
    // cout << y<<endl;
    y->Attack(y);
    y->print();
    z->print();
    x->print();

    return 0 ;
}
