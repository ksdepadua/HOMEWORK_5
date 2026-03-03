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

void test_subtract_overflow(void) {
    int result = subtract(INT_MAX, -1);         // INT_MAX - -1 should wrap around to the "bottom"
    TEST_ASSERT_TRUE(result < 0);
}

void test_subtract_underflow(void) {
    int result = subtract(INT_MIN, 1);          // INT_MIN - 1 should wrap around to the "top"
    TEST_ASSERT_TRUE(result > 0);
}

/* MULTIPLY() TESTS */
void test_multiply_positive_numbers(void) {
    TEST_ASSERT_EQUAL(20, multiply(4, 5));      // Expect 4 * 5 = 20
}

void test_multiply_positive_and_negative_numbers(void) {
    TEST_ASSERT_EQUAL(-12, multiply(6, -2));      // Expect 6 * -2 = -12
}

void test_multiply_negative_numbers(void) {
    TEST_ASSERT_EQUAL(21, multiply(-3, -7));     // Expect -3 * -7 = 21
}

void test_multiply_zero(void) {
    TEST_ASSERT_EQUAL(0, multiply(10, 0));      // Expect 10 * 0 = 0
    TEST_ASSERT_EQUAL(0, multiply(0, 0));       // Expect 0 * 0 = 0
}

void test_multiply_overflow(void) {
    int result = multiply(INT_MAX, 2);
    TEST_ASSERT_TRUE(result < 0);
}

void test_multiply_underflow(void) {
    int result = multiply(INT_MIN, 2);
    TEST_ASSERT_TRUE(result >= 0);              // Seems like INT_MIN * 2 = 0, which still seems like an underflow.
}

/* DIVIDE TESTS */
void test_divide_positive_numbers(void) {
    TEST_ASSERT_EQUAL(4, divide(8, 2));       // Expect 8 / 2 = 4
}

void test_divide_positive_and_negative_numbers(void) {
    TEST_ASSERT_EQUAL(-2, divide(6, -3));      // Expect 6 / -3 = -2
}

void test_divide_negative_numbers(void) {
    TEST_ASSERT_EQUAL(3, divide(-12, -4));     // Expect -12 / -4 = 3
}

void test_divide_one(void) {
    TEST_ASSERT_EQUAL(10, divide(10, 1));     // Expect 10 / 1 = 10
    TEST_ASSERT_EQUAL(3, divide(3, 1));       // Expect 3 / 1 = 3
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
    RUN_TEST(test_subtract_overflow);
    RUN_TEST(test_subtract_underflow);

    /* MULTIPLY() TESTS */
    RUN_TEST(test_multiply_positive_numbers);
    RUN_TEST(test_multiply_positive_and_negative_numbers);
    RUN_TEST(test_multiply_negative_numbers);
    RUN_TEST(test_multiply_zero);
    RUN_TEST(test_multiply_overflow);
    RUN_TEST(test_multiply_underflow);

    /* DIVIDE() TESTS */
    RUN_TEST(test_divide_positive_numbers);
    RUN_TEST(test_divide_positive_and_negative_numbers);
    RUN_TEST(test_divide_negative_numbers);
    RUN_TEST(test_divide_one);
    
    return UNITY_END();
}