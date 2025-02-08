#include "cargo.h"
#include "assert.h"


//1
// Set up a truck with valid weight and box size
void test_setTruck_validInput() {
    struct TruckInfo truck;
    setTruck(&truck);
    
    // Check if weight is within range
    assert(truck.weight >= LOWWEIGHT && truck.weight <= HIGHWEIGHT);
    
    // Check if box size is one of the valid sizes
    assert(truck.boxSize == SIZE_MIN || truck.boxSize == SIZE_MID || truck.boxSize == SIZE_MAX);
}

// Set up a truck with an invalid weight and check if it remains unchanged
void test_setTruck_invalidWeight() {
    struct TruckInfo truck;
    // Set weight outside valid range
    truck.weight = 1300;
    setTruck(&truck);

    // Weight should not be updated
    assert(truck.weight < LOWWEIGHT || truck.weight > HIGHWEIGHT);
}

// Set up a truck with an invalid box size and check if it remains unchanged
void test_setTruck_invalidBoxSize() {
    struct TruckInfo truck;
    // Set box size to an invalid value
    truck.boxSize = 3.0;
    setTruck(&truck);

    // Box size should not be updated
    assert(truck.boxSize != 3.0);
}


//2
// Check if a destination is valid on the map
void test_isDestValid_validDestination() {
    struct Map map;
    // Initialize map with valid data

    assert(isDestValid(&map, 10, 'A'));
}

// Check if an invalid destination is correctly identified
void test_isDestValid_invalidDestination() {
    struct Map map;
    // Initialize map with valid data

    assert(!isDestValid(&map, 30, 'Z'));
}

// Check if an invalid row is correctly identified
void test_isDestValid_invalidRow() {
    struct Map map;
    // Initialize map with valid data

    assert(!isDestValid(&map, -1, 'A'));
}


//3
// Validate a weight within given limits
void test_validateWeight_validWeight() {
    assert(validateWeight(500.0));
}

// Validate the lower limit of weight
void test_validateWeight_lowerBound() {
    assert(validateWeight(LOWWEIGHT));
}

// Validate the upper limit of weight
void test_validateWeight_upperBound() {
    assert(validateWeight(HIGHWEIGHT));
}

// Validate an invalid weight
void test_validateWeight_invalidWeight() {
    assert(!validateWeight(-10.0));
}


//4
// Validate a valid box size
void test_validateBoxSize_validSize() {
    assert(validateBoxSize(SIZE_MIN));
}

// Validate an invalid box size
void test_validateBoxSize_invalidSize() {
    assert(!validateBoxSize(2.0));
}

// Validate the lower bound of box size
void test_validateBoxSize_lowerBound() {
    assert(validateBoxSize(SIZE_MIN));
}

// Validate the upper bound of box size
void test_validateBoxSize_upperBound() {
    assert(validateBoxSize(SIZE_MAX));
}


//5
// Get the symbol at a valid location on the map
void test_getSym_validSymbol() {
    struct Map map = populateMap();
    int value = getSym(&map, 5, 'B');  // Get the value at position (5, 'B')
    // Debugging : printf("Value at (5, 'B'): %d\n", value);  // Print the value for debugging
    assert(value == 0);  // Check if the value is 0( no building)
}


//Get the symbol at an invalid location on the map
void test_getSym_invalidSymbol() {
    struct Map map;
    // Initialize map with valid data

    assert(getSym(&map, 30, 'Z') == '.');
}

//Get the symbol at an invalid row on the map
void test_getSym_invalidRow() {
    struct Map map;
    // Initialize map with valid data

    assert(getSym(&map, -1, 'B') == '\0');
}

//6
// Convert valid coordinates to a struct Coordinate
void test_convertToCoordinate_valid() {
    struct Coordinate coord = convertToCoordinate(10, 'A');
    assert(coord.row == 10 && coord.column == 'A');
}

//Convert invalid row to a struct Coordinate
void test_convertToCoordinate_invalidRow() {
    struct Coordinate coord = convertToCoordinate(-1, 'A');
    assert(coord.row == -1 && coord.column == '\0');
}

//Convert invalid column to a struct Coordinate
void test_convertToCoordinate_invalidColumn() {
    struct Coordinate coord = convertToCoordinate(10, 'Z');
    assert(coord.row == -1 && coord.column == '\0');
}

//Convert invalid row and column to a struct Coordinate
void test_convertToCoordinate_invalidRowAndColumn() {
    struct Coordinate coord = convertToCoordinate(-1, 'Z');
    assert(coord.row == -1 && coord.column == '\0');
}
