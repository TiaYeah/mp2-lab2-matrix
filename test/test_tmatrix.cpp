#include "utmatrix.h"

#include <gtest.h>

TEST(TMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TMatrix<int> m(5));
}

TEST(TMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TMatrix<int> m(-5));
}

TEST(TMatrix, can_create_copied_matrix)
{
  TMatrix<int> m(5);

  ASSERT_NO_THROW(TMatrix<int> m1(m));
}

TEST(TMatrix, copied_matrix_is_equal_to_source_one)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(m1);
	ASSERT_EQ(m1, m2);
}

TEST(TMatrix, copied_matrix_has_its_own_memory)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(m1);
	ASSERT_NE(&(m1[0][0]), &(m2[0][0]));
}

TEST(TMatrix, can_get_size)
{
	TMatrix<int> m1(5);

	EXPECT_EQ(5, m1.GetSize());
}

TEST(TMatrix, can_set_and_get_element)
{
	TMatrix<int> m1(5);
	m1[0][0] = 1;

	EXPECT_EQ(1, m1[0][0]);
}

TEST(TMatrix, throws_when_set_element_with_negative_index)
{
	TMatrix<int> m1(5);
	ASSERT_ANY_THROW(m1[-1][0]);
}

TEST(TMatrix, throws_when_set_element_with_too_large_index)
{
	TMatrix<int> m1(5);
	ASSERT_ANY_THROW(m1[5][0]);
}

TEST(TMatrix, can_assign_matrix_to_itself)
{
	bool f = true;
	TMatrix<int> m1(5);
	for (int i = 0; i < 5; i++)
		for (int j = i; j < 5; j++)
			m1[i][j] = 1;
	m1 = m1;
	for (int i = 0; i < 4; i++)
		for (int j = i; j < 4; j++)
			if (m1[i][j] != 1)
				f = false;

	ASSERT_EQ(f, true);
}

TEST(TMatrix, can_assign_matrices_of_equal_size)
{
	bool f = true;
	TMatrix<int> m1(5);
	TMatrix<int> m2(5);
	for (int i = 0; i < 5; i++)
		for (int j = i; j < 5; j++)
			m1[i][j] = 1;
	m2 = m1;
	for (int i = 0; i < 4; i++)
		for (int j = i; j < 4; j++)
			if (m2[i][j] != 1)
				f = false;

	ASSERT_EQ(f, true);
}

TEST(TMatrix, assign_operator_change_matrix_size)
{
	TMatrix<int> m1(4);
	TMatrix<int> m2(5);
	m1 = m2;
	ASSERT_NE(m1.GetSize(),4);
}

TEST(TMatrix, can_assign_matrices_of_different_size)
{
	bool f = true;
	TMatrix<int> m1(5);
	TMatrix<int> m2(4);
	for (int i = 0; i < 5; i++)
		for (int j = i; j < 5; j++)
			m1[i][j] = 1;
	m2 = m1;
	for (int i = 0; i < 5; i++)
		for (int j = i; j < 5; j++)
			if (m2[i][j] != 1)
				f = false;
	ASSERT_EQ(f, true);
}

TEST(TMatrix, compare_equal_matrices_return_true)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(m1);
	ASSERT_EQ(m1==m2, true);
}

TEST(TMatrix, compare_matrix_with_itself_return_true)
{
	TMatrix<int> m1(5);
	ASSERT_EQ(m1 == m1, true);
}

TEST(TMatrix, matrices_with_different_size_are_not_equal)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(4);
	ASSERT_EQ(m1 == m2, false);
}

TEST(TMatrix, can_add_matrices_with_equal_size)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(5);
	TMatrix<int> res(5);
	for (int i = 0; i < 5; i++)
		for (int j = i; j < 5; j++)
		{
			m1[i][j] = 1;
			m2[i][j] = 1;
		}
	res = m1 + m2;
	ASSERT_EQ(res, m1+m2);
}

TEST(TMatrix, cant_add_matrices_with_not_equal_size)
{
	TMatrix<int> m1(4);
	TMatrix<int> m2(5);
	ASSERT_ANY_THROW(m1 + m2);
}

TEST(TMatrix, can_subtract_matrices_with_equal_size)
{
	TMatrix<int> m1(5);
	TMatrix<int> m2(5);
	TMatrix<int> res(5);
	for (int i = 0; i < 5; i++)
		for (int j = i; j < 5; j++)
		{
			m1[i][j] = 1;
			m2[i][j] = 1;
		}
	res = m1 - m2;
	ASSERT_EQ(res, m1 - m2);
}

TEST(TMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TMatrix<int> m1(4);
	TMatrix<int> m2(5);
	ASSERT_ANY_THROW(m2 - m1);
}

