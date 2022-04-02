#include "declarations.h"
#include "unity.h"
#include "fun_call.h"
void setUp(void){
}
void tearDown(void){
}
//This file is for Unit testing purpose

void test();
void test1();
void test2();
void test3();
void test4();

void test(){
        
    TEST_ASSERT_EQUAL(133.33, basic_Salary_Calc(2,2000));
    TEST_ASSERT_EQUAL(3200, basic_Salary_Calc(16,6000));
    TEST_ASSERT_EQUAL(6400.00, basic_Salary_Calc(24,8000));
}
void test1(){
    TEST_ASSERT_EQUAL(2333.33, OT_Calc(56, 5000));
    TEST_ASSERT_EQUAL(6400.00, OT_Calc(96, 8000));
    TEST_ASSERT_EQUAL(4200, OT_Calc(72, 7000));
}
void test2(){
    TEST_ASSERT_EQUAL(600, pf_Calc(5000));
    TEST_ASSERT_EQUAL(720, pf_Calc(6000));
    TEST_ASSERT_EQUAL(960, pf_Calc(8000));
}
void test3(){
    TEST_ASSERT_EQUAL(1, company("ABC-AUTOMOBILES"));
    TEST_ASSERT_EQUAL(0, company("abc-automobiles"));
    TEST_ASSERT_EQUAL(0, company("bcd-auto"));
}
void test4(){
    TEST_ASSERT_EQUAL(1, m_aut_user("Rajasekhar"));
    TEST_ASSERT_EQUAL(0, m_aut_user("Raja"));
    TEST_ASSERT_EQUAL(0, m_aut_user("sekhar"));
}
int dummy(){
    UnityBegin(NULL);
    RUN_TEST(test);
    RUN_TEST(test1);
    RUN_TEST(test2);
    RUN_TEST(test3);
    RUN_TEST(test4);
    return (UnityEnd());
}

