#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "cmatrix.h"

TEST(CMatrixTest, PrintEmptyMatrix) {
    CMatrix matrix;
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    matrix.print("Test");
    std::cout.rdbuf(oldCout);
    ASSERT_EQ(ss.str(), "Матрица: Test---матрицы не существует!\n");
}

TEST(CMatrixTest, PrintNonEmptyMatrix) {
    CMatrix matrix(2, 3);
    matrix.matrix[0][0] = 1;
    matrix.matrix[1][2] = 5;
    std::stringstream ss;
    std::streambuf* oldCout = std::cout.rdbuf();
    std::cout.rdbuf(ss.rdbuf());
    matrix.print("Test");
    std::cout.rdbuf(oldCout);
    ASSERT_EQ(ss.str(), "\nМатрица: Test\n( 1 0 0 )\n( 0 0 5 )\n");
}

TEST(CMatrixTest, YmenchMatrix) {
    CMatrix matrix(3, 4);
    matrix.ymench();
    ASSERT_EQ(matrix.rows, 2);
    ASSERT_EQ(matrix.colls, 3);
}

TEST(CMatrixTest, GetRows_EmptyMatrix) {
    CMatrix matrix;
    EXPECT_EQ(matrix.Get_rows(), 0);
}

TEST(CMatrixTest, GetRows_NonEmptyMatrix) {
    CMatrix matrix(3, 4);
    EXPECT_EQ(matrix.Get_rows(), 3);
}


TEST(CMatrixTest, GetColls_EmptyMatrix) {
    CMatrix matrix;
    EXPECT_EQ(matrix.Get_colls(), 0);
}

TEST(CMatrixTest, GetColls_NonEmptyMatrix) {
    CMatrix matrix(3, 4);
    EXPECT_EQ(matrix.Get_colls(), 4);
}
