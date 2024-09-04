#ifndef HEALTH_MONITOR_H_
#define HEALTH_MONITOR_H_

namespace health_monitor {
    const float TEMP_IN_F_MIN = 95.0f;
    const float TEMP_IN_F_MAX = 102.0f;
    const float PULSE_MIN = 60.0f;
    const float PULSE_MAX = 100.0f;
    const float SPO2_MIN = 90.0f;
    const float SPO2_MAX = 100.0f;

    enum VitalStatus {
        ALL_VITALS_OK = 1,
        VITALS_OUT_OF_RANGE = 0
    };

    bool isInputValueWithinRange(float inputValue, float lowerRange, float upperRange);
    void introduceDelay();
    int vitalsOk(float temperature_in_f, float pulseRate, float spo2);
}  // health_monitor

#endif  // HEALTH_MONITOR_H_
