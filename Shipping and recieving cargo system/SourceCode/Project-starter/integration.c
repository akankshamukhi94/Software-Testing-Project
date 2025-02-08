#include "cargo.c"
#include "mapping.h"

void testDestination() // tests checkDestInput with the isDestValid function
{
	int row = 1;
	char col = 'A';
	char* string = "1A";
	struct Map routeMap = populateMap();

	if (checkDestInput(string, row, col))
		isDestValid(&routeMap, row, col);
	else
		printf("Incorrect destination.");
}

void testCoordinateandTruck() // tests setTruck and convertToCoordinate with the findClosest function
{
	int row = 1;
	char col = 'A';
	struct TruckInfo truck;
	struct Map routeMap = populateMap();

	setTruck(&truck);
	struct Coordinate coord = convertToCoordinate(row, col);
	struct Coordinate closest = findClosest(coord, &truck, &routeMap);
	printf("Row: %d", closest.row);
	printf("Column: %c", closest.column);
}

void testSymbol() // tests convertToCoordinate with getSym function
{
	struct Map routeMap = populateMap();
	struct Coordinate coord = convertToCoordinate(1, 'A');
	char symbol = getSym(&routeMap, coord.row, coord.column);

	printf("Symbol: %c", symbol);
}
