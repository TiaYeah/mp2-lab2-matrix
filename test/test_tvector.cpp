#include "utmatrix.h"

#include <gtest.h>

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
	TVector<int> v1(10);
	TVector<int> v2(v1);
	ASSERT_EQ(v1,v2);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
	TVector<int> v1(10);
	TVector<int> v2(v1);
	ASSERT_NE(&v1, &v2);
}

TEST(TVector, can_get_size)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(4);
	ASSERT_ANY_THROW(v[-1]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
	TVector<int> v(4);
	ASSERT_ANY_THROW(v[MAX_VECTOR_SIZE+1]);
}

TEST(TVector, can_assign_vector_to_itself)
{
	bool f = true;
	TVector<int> v(4);
	for (int i = 0; i < 4; i++)
		v[i] = i;
	v = v;
	for (int i = 0; i < 4; ++i)
		if (v[i] != i)
			f = false;

	ASSERT_EQ(f, true);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
	bool f = true;
	TVector<int> v1(4);
	TVector<int> v2(4);
	for (int i = 0; i < 4; i++)
		v1[i] = i;
	v1 = v2;
	for (int i = 0; i < 4; ++i)
		if (v1[i] != v2[i])
			f = false;

	ASSERT_EQ(f, true);
}

TEST(TVector, assign_operator_change_vector_size)
{
	TVector<int> v1(4);
	TVector<int> v2(5);
	v1 = v2;
	ASSERT_EQ(v1.GetSize(), 5);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
	bool f = true;
	TVector<int> v1(4);
	TVector<int> v2(5);
	for (int i = 0; i < 5; i++)
		v2[i] = i;
	v1 = v2;
	for (int i = 0; i < 5; i++)
		if (v1[i] != v2[i])
			f = false;
	ASSERT_EQ(f, true);
}

TEST(TVector, compare_equal_vectors_return_true)
{
	TVector<int> v1(4);
	TVector<int> v2(4);
	for (int i = 0; i < 4; i++)
		v1[i] = 1;
	v2 = v1;
	ASSERT_EQ(v1, v2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
	TVector<int> v1(4);
	for (int i = 0; i < 4; i++)
		v1[i] = i;
	ASSERT_EQ(v1==v1, true);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
	TVector<int> v1(4);
	TVector<int> v2(5);
	ASSERT_EQ(v1 != v2, true);
}

TEST(TVector, can_add_scalar_to_vector)
{
	bool f = true;
	TVector<int> v1(5);
	for (int i = 0; i < 5; i++)
		v1[i] = 0;
	v1 = v1 + 5;
	for (int i = 0; i < 5; i++)
		if (v1[i] != 5)
			f = false;
	ASSERT_EQ(f, true);
}

TEST(TVector, can_subtract_scalar_from_vector)
{
	bool f = true;
	TVector<int> v1(5);
	for (int i = 0; i < 5; i++)
		v1[i] = 5;
	v1 = v1 - 5;
	for (int i = 0; i < 5; i++)
		if (v1[i] != 0)
			f = false;
	ASSERT_EQ(f, true);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
	bool f = true;
	TVector<int> v1(5);
	for (int i = 0; i < 5; i++)
		v1[i] = 1;
	v1 = v1 * 5;
	for (int i = 0; i < 5; i++)
		if (v1[i] != 5)
			f = false;
	ASSERT_EQ(f, true);
}

TEST(TVector, can_add_vectors_with_equal_size)
{
	TVector<int> v1(5);
	TVector<int> v2(5);
	TVector<int> res(5);
	for (int i = 0; i < 5; i++)
	{
		v1[i] = 1;
		v2[i] = 2;
	}
	res = v1 + v2;
	ASSERT_EQ(res, v1 + v2);
}

TEST(TVector, cant_add_vectors_with_not_equal_size)
{
	TVector<int> v1(5);
	TVector<int> v2(4);
	for (int i = 0; i < 4; i++)
	{
		v1[i] = 1;
		v2[i] = 2;
	}
	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TVector, can_subtract_vectors_with_equal_size)
{
	TVector<int> v1(5);
	TVector<int> v2(5);
	TVector<int> res(5);
	for (int i = 0; i < 5; i++)
	{
		v1[i] = 1;
		v2[i] = 2;
	}
	res = v2 - v1;
	ASSERT_EQ(res, v2 - v1);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_size)
{
	TVector<int> v1(5);
	TVector<int> v2(4);
	for (int i = 0; i < 4; i++)
	{
		v1[i] = 1;
		v2[i] = 2;
	}
	ASSERT_ANY_THROW(v2 + v1);
}

TEST(TVector, can_multiply_vectors_with_equal_size)
{
	TVector<int> v1(5);
	TVector<int> v2(5);
	TVector<int> res(5);
	for (int i = 0; i < 5; i++)
	{
		v1[i] = 1;
		v2[i] = 2;
	}
	res = v2 * v1;
	ASSERT_EQ(res, v2 * v1);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_size)
{
	TVector<int> v1(5);
	TVector<int> v2(4);
	for (int i = 0; i < 4; i++)
	{
		v1[i] = 1;
		v2[i] = 2;
	}
	ASSERT_ANY_THROW(v2 * v1);
}

