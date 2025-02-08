#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "mapping.h"
#include "assert.h"
#include "unitTesting.c"

int main(void)
{
	struct Map baseMap = populateMap();
	struct Route blueRoute = getBlueRoute();
	struct Map routeMap = addRoute(&baseMap, &blueRoute);

	printMap(&routeMap, 1, 1);


	printf("Testing starts\n");
  
    test_isDestValid_invalidDestination();
    test_isDestValid_invalidRow();
    test_validateWeight_validWeight();
    test_validateWeight_lowerBound();
    test_validateWeight_upperBound();
    test_validateWeight_invalidWeight();
    test_validateBoxSize_validSize();
    test_validateBoxSize_invalidSize();
    test_validateBoxSize_lowerBound();
    test_validateBoxSize_upperBound();
    test_getSym_validSymbol();
    test_getSym_invalidSymbol();
    test_getSym_invalidRow();
    test_convertToCoordinate_valid();
    test_convertToCoordinate_invalidRow();
    test_convertToCoordinate_invalidColumn();
    test_convertToCoordinate_invalidRowAndColumn();

	printf("All tests have been passed");

	return 0;
}
