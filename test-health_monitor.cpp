#include "./health_monitor.h"

#include "gtest/gtest.h"

namespace health_monitor {
namespace test {
    TEST(Monitor, NotOkWhenAnyVitalIsOffRange) {
        ASSERT_FALSE(vitalsOk(99, 102, 70));
        ASSERT_TRUE(vitalsOk(98.1, 70, 98));
    }
}  // namespace test
}  // namespace health_monitor

