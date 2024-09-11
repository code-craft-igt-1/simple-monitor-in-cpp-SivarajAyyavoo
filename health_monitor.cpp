#include "./health_monitor.h"
#include <assert.h>
#include <thread>
#include <chrono>
#include <iostream>
using std::cout, std::flush, std::this_thread::sleep_for, std::chrono::seconds;

namespace health_monitor {
    bool isInputValueWithinRange(float inputValue, float lowerRange, float upperRange) {
        return inputValue > lowerRange && inputValue < upperRange;
    }

    void sendAlert() {
        for (int i = 0; i < 6; i++) {
            cout << "\r* " << flush;
            sleep_for(seconds(1));
            cout << "\r *" << flush;
            sleep_for(seconds(1));
        }
    }

    std::string sendMessage(int vitalNum, VitalAlertLevel vitalAlertLevel) {
        std::string msg = VITALS_IN_DIFF_LANG[LANGUAGE_USED][vitalNum];
        if (VitalAlertLevel::WARNING == vitalAlertLevel) {
            msg += WARNING_IN_DIFF_LANG[LANGUAGE_USED];
        }
        else if (VitalAlertLevel::OUT_OF_RANGE == vitalAlertLevel) {
            msg += OUT_OF_RANGE_IN_DIFF_LANG[LANGUAGE_USED];
        }
        return msg;
    }

    void isVitalCritical(float vitalValue, int vitalNum) {
        if (isInputValueWithinRange(vitalValue, VITALS_OUT_OF_RANGE_MIN_VAL[vitalNum],
            VITALS_WARNING_MIN_VAL[vitalNum]) ||
            isInputValueWithinRange(vitalValue, VITALS_WARNING_MAX_VAL[vitalNum],
                VITALS_OUT_OF_RANGE_MAX_VAL[vitalNum])) {
            sendMessage(vitalNum, VitalAlertLevel::WARNING);
        }
    }

    bool isVitalOutOfRange(float vitalValue, int vitalNum) {
        bool result = false;
        if (!isInputValueWithinRange(vitalValue, VITALS_OUT_OF_RANGE_MIN_VAL[vitalNum],
            VITALS_OUT_OF_RANGE_MAX_VAL[vitalNum])) {
            sendAlert();
            sendMessage(vitalNum, VitalAlertLevel::OUT_OF_RANGE);
            result = true;
        }
        return result;
    }

    int vitalsOk(float temperature_in_f, float pulseRate, float spo2) {
        float testResult[NO_OF_VITALS] = { temperature_in_f, pulseRate, spo2 };

        for (unsigned int vitalNum = 0; vitalNum < NO_OF_VITALS; vitalNum++) {
            isVitalCritical(testResult[vitalNum], vitalNum);
            if (isVitalOutOfRange(testResult[vitalNum], vitalNum)) {
                return vitalNum;
            }

        }
        return VitalStatus::ALL_VITALS_OK;
    }
}  // namespace health_monitor
