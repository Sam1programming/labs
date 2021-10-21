#include <iostream>
#include "ellipse.hpp"
#include <gtest/gtest.h>

//тестирование конструкторов
TEST(Constructor, DefaultCon){
    Prog2::Ellipse el;
    ASSERT_EQ(0, el.getP().x);
    ASSERT_EQ(0, el.getP().y);
    ASSERT_EQ(5, el.getA());
    ASSERT_EQ(3, el.getB());
    Prog2::Ellipse el1(7, 8);
    ASSERT_EQ(7, el1.getA());
    ASSERT_EQ(8, el1.getB());
}

TEST(Constructor, WithPoint){
    Prog2::Point p(1, 10);
    Prog2::Ellipse el(p);
    ASSERT_EQ(1, el.getP().x);
    ASSERT_EQ(10, el.getP().y);
    ASSERT_EQ(5, el.getA());
    ASSERT_EQ(3, el.getB());
}

TEST(Constructor, TestException){
    Prog2::Point p;
    ASSERT_ANY_THROW(Prog2::Ellipse el(-2, 5));
    ASSERT_ANY_THROW(Prog2::Ellipse el1(2, -1));
    ASSERT_ANY_THROW(Prog2::Ellipse el2(p, -5));
    ASSERT_ANY_THROW(Prog2::Ellipse el3(p, 1, -4));
}

TEST(Methods, Setters){
    Prog2::Point p(3, 3);
    Prog2::Ellipse el;
    el.setP(p);
    el.setA(1);
    el.setB(1);
    ASSERT_EQ(3, el.getP().x);
    ASSERT_EQ(3, el.getP().y);
    ASSERT_EQ(1, el.getA());
    ASSERT_EQ(1, el.getB());
    el.setP(15, 15);
    ASSERT_EQ(15, el.getP().x);
    ASSERT_EQ(15, el.getP().y);

}

TEST(Constructor, Setters_TestException){
    Prog2::Point p(3, 3);
    Prog2::Ellipse el;
    ASSERT_ANY_THROW(el.setA(-1));
    ASSERT_ANY_THROW(el.setB(-1));
}

TEST(Methods, MathsFunctions){
    const double err = 0.01;
    Prog2::Ellipse el;
    ASSERT_NEAR(8, el.focal(), err);
    ASSERT_NEAR(0.8, el.excent(), err);
    ASSERT_NEAR(25.56, el.length(), err);
    ASSERT_NEAR(47.12, el.square(), err);
    ASSERT_NEAR(1, el.min(), err);
    ASSERT_NEAR(9, el.max(), err);
    el.setA(7);
    el.setB(4);
    ASSERT_NEAR(11.48, el.focal(), err);
    ASSERT_NEAR(0.82, el.excent(), err);
    ASSERT_NEAR(35.26, el.length(), err);
    ASSERT_NEAR(87.96, el.square(), err);
    ASSERT_NEAR(1.25, el.min(), err);
    ASSERT_NEAR(12.74, el.max(), err);
    ASSERT_NEAR(2.06, el.findY(6), err);
    ASSERT_NEAR(3.61, el.findY(-3), err);
    ASSERT_ANY_THROW(el.findY(20));
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}