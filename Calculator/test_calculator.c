#include "unity.h"          // Include unit testing framework
#include "calculator.h"

// Optional, but needs to be defined (runs BEFORE each test)
void setUp(void) {
    // Initialize any resources needed for your tests here
    // For example, you might reset a global value, dynamically allocate memory, etc.
    // In this example, we don't need anything here.
}

// Optional, but needs to be defined (runs AFTER each test)
void tearDown(void) {
    // Clean up resources after each test
    // For example, free dynamically allocated memory, reset global values, etc.
    // In this example, we don't need anything here.
}

void test_add_positive_numbers(void) {
    TEST_ASSERT_EQUAL(5, add(2, 3)); // We expect 2 + 3 = 5
                                      // PASS if true, FAIL if false
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_add_positive_numbers); // Run our test function
    return UNITY_END();
}