//
// Created by mwypych on 01.06.17.
//

#include <gtest/gtest.h>
#include <string>
#include <stdexcept>
#include <ArabicRoman.h>

TEST(arabicroman, ConversionOfArabicNumber1ToRomanReturnI) {
    EXPECT_EQ("I", ArabicToString(1));
}

TEST(arabicroman, ConversionOfArabicNumber0) {
    EXPECT_THROW(ArabicToString(0), invalid_argument);
}

TEST(arabicroman, ConversionOfArabicNumber_1) {
    EXPECT_THROW(ArabicToString(-1), invalid_argument);
}

TEST(arabicroman, ConversionOfArabicNumber3ToRomanReturnIII) {
    EXPECT_EQ("III", ArabicToString(3));
}

TEST(arabicroman, ConversionOfArabicNumber4ToRomanReturnIV) {
    EXPECT_EQ("IV", ArabicToString(4));
}

TEST(arabicroman, ConversionOfArabicNumber5ToRomanReturnV) {
    EXPECT_EQ("V", ArabicToString(5));
}

TEST(arabicroman, ConversionOfArabicNumber7ToRomanReturnVII) {
    EXPECT_EQ("VII", ArabicToString(7));
}

TEST(arabicroman, ConversionOfArabicNumber9ToRomanReturnIX) {
    EXPECT_EQ("IX", ArabicToString(9));
}

TEST(arabicroman, ConversionOfArabicNumber12ToRomanReturnXII) {
    EXPECT_EQ("XII", ArabicToString(12));
}

TEST(arabicroman, ConversionOfArabicNumber30ToRomanReturnXXX) {
    EXPECT_EQ("XXX", ArabicToString(30));
}

TEST(arabicroman, ConversionOfArabicNumber40ToRomanReturnXL) {
    EXPECT_EQ("XL", ArabicToString(40));
}

TEST(arabicroman, ConversionOfArabicNumber50ToRomanReturnV) {
    EXPECT_EQ("L", ArabicToString(50));
}

TEST(arabicroman, ConversionOfArabicNumber70ToRomanReturnLXX) {
    EXPECT_EQ("LXX", ArabicToString(70));
}

TEST(arabicroman, ConversionOfArabicNumber90ToRomanReturnXC) {
    EXPECT_EQ("XC", ArabicToString(90));
}