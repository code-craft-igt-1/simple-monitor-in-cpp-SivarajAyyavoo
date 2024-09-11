#ifndef HEALTH_MONITOR_H_
#define HEALTH_MONITOR_H_

#include <map>
#include <string>

namespace health_monitor {
    const unsigned int NO_OF_VITALS = 3;
    const unsigned int NO_OF_LANG = 2;

    enum Language {
        ENGLISH = 0,
        DUTCH = 1
    };

    const std::string VITALS_IN_DIFF_LANG[NO_OF_LANG][NO_OF_VITALS] =
    { { "Temperature", "PulseRate", "SpO2" },
      { "Temperatuur", "Pulseren", "SpO2" } };

    const std::string WARNING_IN_DIFF_LANG[NO_OF_LANG] =
    { "is approaching out of range", "nadert buiten bereik" };
    const std::string OUT_OF_RANGE_IN_DIFF_LANG[NO_OF_LANG] =
    { "is out of range", "is buiten bereik" };

    const Language LANGUAGE_USED = Language::DUTCH;

    enum VitalStatus {
        TEMP_OUT_OF_RANGE = 0,
        PULSERATE_OUT_OF_RANGE = 1,
        SPO2_OUT_OF_RANGE = 2,
        ALL_VITALS_OK = 3
    };

    enum VitalAlertLevel {
        WARNING = 0,
        OUT_OF_RANGE = 1
    };

    const float VITALS_OUT_OF_RANGE_MIN_VAL[NO_OF_VITALS] = { 95.0F, 60.0F, 90.0F };
    const float VITALS_OUT_OF_RANGE_MAX_VAL[NO_OF_VITALS] = { 102.0F, 100.0F, 100.0F };

    const float VITALS_WARNING_MIN_VAL[NO_OF_VITALS] = { 96.5F, 61.5F, 91.5F };
    const float VITALS_WARNING_MAX_VAL[NO_OF_VITALS] = { 100.5F, 98.5F, 100.0F };

    bool isInputValueWithinRange(float inputValue, float lowerRange, float upperRange);
    void sendAlert();
    int vitalsOk(float temperature_in_f, float pulseRate, float spo2);
    std::string sendMessage(int vitalNum, VitalAlertLevel vitalAlertLevel);
}  // namespace health_monitor


#endif  // HEALTH_MONITOR_H_
