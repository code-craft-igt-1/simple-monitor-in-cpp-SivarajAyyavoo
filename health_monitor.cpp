#include "./health_monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

namespace health_monitor {
    bool isInputValueWithinRange(float inputValue, float lowerRange, float upperRange) {
        return inputValue < lowerRange || inputValue > upperRange;
    }

    void introduceDelay() {
        for (int i = 0; i < 6; i++) {
            cout << "\r* " << flush;
            sleep_for(seconds(1));
            cout << "\r *" << flush;
            sleep_for(seconds(1));
        }
    }

    int vitalsOk(float temperature_in_f, float pulseRate, float spo2) {
        bool isTempCritical = isInputValueWithinRange(temperature_in_f, 
            TEMP_IN_F_MIN, TEMP_IN_F_MAX);
        bool isPulseOutOfRange = isInputValueWithinRange(pulseRate, PULSE_MIN, PULSE_MAX);
        bool isSpo2OutOfRange = isInputValueWithinRange(spo2, SPO2_MIN, SPO2_MAX);

        if (isTempCritical | isPulseOutOfRange | isSpo2OutOfRange) {
            cout << "One of the vital (Temperature/Pulse/Spo2 is out of range !\n";
            introduceDelay();
            return VitalStatus::VITALS_OUT_OF_RANGE;
        }

        return VitalStatus::ALL_VITALS_OK;
    }
}  // namespace health_monitor
