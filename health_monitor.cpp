#include "./health_monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

namespace health_monitor {
    bool checkValues(float inputValue, float lowerRange, float upperRange) {
        bool isValueWithinRange = true;
        if (inputValue > upperRange || inputValue < lowerRange) {
            isValueWithinRange = false;
        }
        return isValueWithinRange;
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
        if (checkValues(temperature_in_f, 95.0f, 102.0f)) {
            cout << "Temperature is critical!\n";
            introduceDelay();
            return 0;
        }
        else if (checkValues(pulseRate, 60.0f, 100.0f)) {
            cout << "Pulse Rate is out of range!\n";
            introduceDelay();
            return 0;
        }
        else if (checkValues(spo2, 90.0f, 100.0f)) {
            cout << "Oxygen Saturation out of range!\n";
            introduceDelay();
            return 0;
        }
        return 1;
    }
}  // namespace health_monitor
