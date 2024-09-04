#include "./health_monitor.h"

#include "gtest/gtest.h"

namespace health_monitor {
namespace test {
    TEST(HealthMonitor, NotOkWhenTempIsOffRange) {
        // Test the Lower bound
        ASSERT_FALSE(vitalsOk(90, 90, 95));
        // Test the Upper bound
        ASSERT_FALSE(vitalsOk(110, 90, 95));
    }

    TEST(HealthMonitor, NotOkWhenPulseRateIsOffRange) {
        // Test the Lower bound
        ASSERT_FALSE(vitalsOk(99, 55, 95));
        // Test the Upper bound
        ASSERT_FALSE(vitalsOk(99, 105, 95));
    }

    TEST(HealthMonitor, NotOkWhenSpo2IsOffRange) {
        // Spo2 can be maximum of 100, so testing only its lower bound
        ASSERT_FALSE(vitalsOk(99, 90, 80));
    }

    TEST(HealthMonitor, OkWhenAllVitalsAreInRange) {
        ASSERT_TRUE(vitalsOk(98.1, 70, 98));
    }
}  // namespace test
}  // namespace health_monitor

