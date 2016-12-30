#include "../SPPoint.h"
#include "unit_test_util.h"
#include <stdbool.h>

//Checks if copy Works
bool pointBasicCopyTest() {
	double data[2] = { 1.0, 1.0 };
	int dim = 2;
	int index = 1;
	SPPoint* p = spPointCreate(data, dim, index);
	SPPoint* q = spPointCopy(p);
	ASSERT_TRUE(spPointGetIndex(p) == spPointGetIndex(q));
	ASSERT_TRUE(spPointGetDimension(p) == spPointGetDimension(q));
	for (int i = 0; i < spPointGetDimension(p); i++) {
		ASSERT_TRUE(spPointGetAxisCoor(p, i) == spPointGetAxisCoor(q, i));
	}
	spPointDestroy(p);
	spPointDestroy(q);
	return true;
}
bool pointBasicL2Distance() {
	double data1[2] = { 1.0, 1.0 };
	double data2[2] = { 1.0, 0.0 };
	int dim1 = 2;
	int dim2 = 2;
	int index1 = 1;
	int index2 = 1;
	SPPoint* p = spPointCreate(data1, dim1, index1);
	SPPoint* q = spPointCreate(data2, dim2, index2);
	ASSERT_TRUE(spPointL2SquaredDistance(p, p) == 0.0);
	ASSERT_TRUE(spPointL2SquaredDistance(q, q) == 0.0);
	ASSERT_FALSE(spPointL2SquaredDistance(p, q) == 0.0);
	spPointDestroy(p);
	spPointDestroy(q);
	return true;
}

// check if dimension is as set
bool pointDimensionTest() {
	double data[2] = { 1.0, 1.0 };
	int dim = 2;
	int index = 1;
	SPPoint* p = spPointCreate(data, dim, index);
	ASSERT_TRUE(spPointGetDimension(p) == 2);
	spPointDestroy(p);
	return true;
}

// check if the coordinates ar as set
bool pointCoordinateTest() {
	double data[3] = { 1.0, 2.0, 3.0 };
	int dim = 3;
	int index = 1;
	SPPoint* p = spPointCreate(data, dim, index);
	for (int i = 0; i < dim; i++) {
		ASSERT_TRUE(spPointGetAxisCoor(p, i) == data[i]);
	}
	spPointDestroy(p);
	return true;
}

// check if index is as set
bool pointIndexTest() {
	double data[3] = { 1.0, 2.0, 3.0 };
	int dim = 3;
	int index = 1;
	SPPoint* p = spPointCreate(data, dim, index);
	ASSERT_TRUE(spPointGetIndex(p) == index);
	spPointDestroy(p);
	return true;
}

// check if changing the source point does not change the point copy
bool pointCopyChangeTest() {
	double data[2] = { 1.0, 1.0 };
	int dim = 2;
	int index = 1;
	SPPoint* p = spPointCreate(data, dim, index);
	SPPoint* q = spPointCopy(p);
//	p->data[0] = 0.0;
//	ASSERT_FALSE(spPointGetAxisCoor(p, 0) == spPointGetAxisCoor(q, 0));
	spPointDestroy(p);
	ASSERT_TRUE(spPointGetDimension(q) == dim);
	ASSERT_TRUE(spPointGetIndex(q) == index);
	spPointDestroy(q);
	return true;
}

// check if invalid values are handles correctly
bool invalidInputTest() {
	double data[2] = { 1.0, 1.0 };
	int dim = 2;
	int index = 1;
	ASSERT_TRUE(spPointCreate(data, dim, -1) == NULL);
	ASSERT_TRUE(spPointCreate(data, 0, index) == NULL);
	ASSERT_TRUE(spPointCreate(NULL, dim, index) == NULL);
	return true;
}

// check if L2 squared distance handles zero vectors
bool l2ZeroTest() {
	double data1[2] = { 0.0, 0.0 };
	double data2[2] = { 0.0, 0.0 };
	int dim1 = 2;
	int dim2 = 2;
	int index1 = 1;
	int index2 = 1;
	SPPoint* p = spPointCreate(data1, dim1, index1);
	SPPoint* q = spPointCreate(data2, dim2, index2);
	ASSERT_TRUE(spPointL2SquaredDistance(p, q) == 0.0);
	spPointDestroy(p);
	spPointDestroy(q);
	return true;
}

// check if L2 squared distance handles vectors with negative values
bool l2NegativeTest() {
	double data1[2] = { -10.0, -2.0 };
	double data2[2] = { 3.0, -7.0 };
	int dim1 = 2;
	int dim2 = 2;
	int index1 = 1;
	int index2 = 1;
	SPPoint* p = spPointCreate(data1, dim1, index1);
	SPPoint* q = spPointCreate(data2, dim2, index2);
	ASSERT_TRUE(spPointL2SquaredDistance(p, q) == 194.0);
	spPointDestroy(p);
	spPointDestroy(q);
	return true;
}

int main() {
	RUN_TEST(pointBasicCopyTest);
	RUN_TEST(pointBasicL2Distance);
	RUN_TEST(pointDimensionTest);
	RUN_TEST(pointCoordinateTest);
	RUN_TEST(pointIndexTest);
	RUN_TEST(pointCopyChangeTest);
	RUN_TEST(invalidInputTest);
	RUN_TEST(l2ZeroTest);
	RUN_TEST(l2NegativeTest);
	return 0;
}
