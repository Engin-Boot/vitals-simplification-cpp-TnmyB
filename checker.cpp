#include <assert.h>


bool check_bpm(float bpm){
    return (bpm>=70 && bpm<=150);
}

bool check_spo2(float spo2){
    return (spo2>=90);
}

bool check_respRate(float respRate){
    return (respRate>=70 && respRate<=95);
}

bool vitalsAreOk(float bpm, float spo2, float respRate) {
  return check_bpm(bpm)&&check_spo2(spo2)&&check_respRate(respRate);
}

int main() {
  assert(vitalsAreOk(80, 95, 60) == true);
  assert(vitalsAreOk(60, 90, 40) == false);
}
