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

/* ADD() TESTS */
void test_add_positive_numbers(void) {
    TEST_ASSERT_EQUAL(5, add(2, 3));    // We expect 2 + 3 = 5
}

void test_add_positive_and_negative_numbers(void) {
    TEST_ASSERT_EQUAL(1, add(5, -4));   // Expect 5 + -4 = 1
}

void test_add_negative_numbers(void) {
    TEST_ASSERT_EQUAL(-7, add(-3, -4)); // Expect -3 + -4 = -7
}

// Can do multiple validations in one test
void test_add_zero(void) {
    TEST_ASSERT_EQUAL(10, add(10, 0));  // Expect 10 + 0 = 10
    TEST_ASSERT_EQUAL(0, add(0, 0));    // Expect 0 + 0 = 0
}

void test_add_overflow(void) {
    int result = add(INT_MAX, 1);       // Should wrap around or cause undefined behavior
    TEST_ASSERT_TRUE(result < 0);       // Checks if overflow occurred
}

void test_add_underflow(void) {
    int result = add(INT_MIN, -1);
    TEST_ASSERT_TRUE(result > 0);       // Checks if underflow occurred
}

/* SUBTRACT() TESTS */
void test_subtract_positive_numbers(void) {
    TEST_ASSERT_EQUAL(3, subtract(8, 5));       // Expect 8 - 5 = 3
}

void test_subtract_positive_and_negative_numbers(void) {
    TEST_ASSERT_EQUAL(9, subtract(6, -3));      // Expect 6 - -3 = 9
}

void test_subtract_negative_numbers(void) {
    TEST_ASSERT_EQUAL(1, subtract(-3, -4));     // Expect -3 - -4 = 1
}

void test_subtract_zero(void) {
    TEST_ASSERT_EQUAL(10, subtract(10, 0));     // Expect 10 - 0 = 10
    TEST_ASSERT_EQUAL(0, subtract(0, 0));       // Expect 0 - 0 = 0
}

int main(void) {
    UNITY_BEGIN();

    /* ADD() TESTS */
    RUN_TEST(test_add_positive_numbers); // Run our test function(s)
    RUN_TEST(test_add_positive_and_negative_numbers);
    RUN_TEST(test_add_negative_numbers);
    RUN_TEST(test_add_zero);
    RUN_TEST(test_add_overflow);
    RUN_TEST(test_add_underflow);

    /* SUBTRACT() TESTS */
    RUN_TEST(test_subtract_positive_numbers);
    RUN_TEST(test_subtract_positive_and_negative_numbers);
    RUN_TEST(test_subtract_negative_numbers);
    RUN_TEST(test_subtract_zero);
    
    return UNITY_END();
}