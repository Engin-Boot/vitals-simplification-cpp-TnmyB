#include <assert.h>
#include <limits.h>

bool vitalInRange(float value, float lower_limit, float upper_limit){

    return !(value < lower_limit || value > upper_limit);
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {
  
  return vitalInRange(bpm,70,150) && vitalInRange(spo2,90,100) && vitalInRange(respRate,30,95);
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
  assert(vitalsAreOk(70, 90, 30) == true);
  assert(vitalsAreOk(150, 200, 95) == true);
  assert(vitalsAreOk(69, 90, 30) == false);
  assert(vitalsAreOk(-1, -1, -1) == false);
}
