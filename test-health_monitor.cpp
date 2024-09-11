#include "./health_monitor.h"

#include "gtest/gtest.h"

namespace health_monitor {
namespace test {
    TEST(HealthMonitor, NotOkWhenTempIsOffRange) {
        // Test the Lower bound
        EXPECT_EQ(vitalsOk(90, 90, 95), TEMP_OUT_OF_RANGE);
        // Test the Upper bound
        EXPECT_EQ(vitalsOk(110, 90, 95), TEMP_OUT_OF_RANGE);
    }

    TEST(HealthMonitor, NotOkWhenPulseRateIsOffRange) {
        // Test the Lower bound
        EXPECT_EQ(vitalsOk(99, 55, 95), PULSERATE_OUT_OF_RANGE);
        // Test the Upper bound
        EXPECT_EQ(vitalsOk(99, 105, 95), PULSERATE_OUT_OF_RANGE);
    }

    TEST(HealthMonitor, NotOkWhenSpo2IsOffRange) {
        // Spo2 can be maximum of 100, so testing only its lower bound
        EXPECT_EQ(vitalsOk(99, 90, 80), SPO2_OUT_OF_RANGE);
    }

    TEST(HealthMonitor, OkWhenAllVitalsAreInRange) {
        EXPECT_EQ(vitalsOk(98.1, 70, 98), ALL_VITALS_OK);
    }
}  // namespace test
}  // namespace health_monitor

