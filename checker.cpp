#include <iostream>
using namespace std;

class AlertInterface
{ 

    public:
       virtual void raiseAlert(const char* vitalName, const char* level)=0;
};

class AlertWithSMS: public AlertInterface{
    public:
        void raiseAlert(const char* vitalName, const char* level){
            std::cout<<"SMS: "<<vitalName<<" "<<level;
        }
};

class AlertWithSound: public AlertInterface{
    public:
        void raiseAlert(const char* vitalName, const char* level){
            std::cout<<"Sound!"<<vitalName<<" "<<level;
        }
};

class vital_info{
    public:
     float lowerLimit;
     float upperLimit;
     float value;
     const char* name;
     AlertInterface* alerter;

    public:

    void vital_initialise(const char* name, float lowerLimit, float upperLimit,AlertInterface* alerter){
        this->name=name;
        this->lowerLimit=lowerLimit;
        this->upperLimit=upperLimit;
        this->alerter=alerter;
    }

    const char* check(int val){
        if(val<lowerLimit){
            return "too low";
        }
        else if(val>upperLimit){
            return "too high";
        }
        else{
            return "is ok";
        }
    }
};

class VitalsChecker
{
    private:
      int* value;
      vital_info* vitals;

     
    public:
      VitalsChecker(vital_info list[]){
          this->vitals = list;
      }

      void VitalValue(int* v){
        value=v;
        checkAndAlert();        
      }

      void checkAndAlert(){
        for(int i=0;i<3;i++){
           vitals[i].alerter->raiseAlert(vitals[i].name, vitals[i].check(value[i]));
        }    
      }
};

int main(){
    //initialize all vitals, type of alarm ,required
    vital_info vital_list[3];
    AlertWithSMS SMS;
    AlertWithSound sound;
    //input can be changed/added
    vital_list[0].vital_initialise("pulse",70,150,&SMS);
    vital_list[1].vital_initialise("spo2",90,100,&sound);
    vital_list[2].vital_initialise("pulse",30,95,&sound);
     
    //Input the vital measurements
    VitalsChecker check(vital_list);
    int val[]={80,95,60};
    check.VitalValue(val);
    return 0;
} 
