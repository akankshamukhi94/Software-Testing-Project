#define _CRT_SECURE_NO_WARNINGS

#include "cargo.h"
#include <stdio.h>

void printHdr() {
    printf("Seneca College Deliveries\n");
}

void printFtr() {
    printf("Thanks for shipping with Seneca!\n");
}

void setTruck(struct TruckInfo* truck)
{
    truck->weight = 0;
    
    while (!validateWeight(truck->weight))
    {
        printf("Enter truck weight in kg (1-1200): ");
        scanf("%lf", &(truck->weight));
    }
        
    truck->boxSize = 0;

    while (!validateBoxSize(truck->boxSize))
    {
        printf("Enter truck box size in cubic meters (0.5, 1, 5): ");
        scanf("%lf", &(truck->boxSize));
    }
}

bool isDestValid(const struct Map* routeMap, int destRow, char destCol) 
{
    return routeMap->squares[destRow][destCol - 'A'] == 1; // returns true if is a building
}

bool checkDestInput(const char* inputString, int* rowNum, char* columnChar)
{
    if(sscanf(inputString, "%d%c", rowNum, columnChar)==2){
        if (*columnChar >= 'A' && *columnChar <= 'Y' && *rowNum >= 1 && *rowNum <= 25) {
            return true;  //  valid
        }

    }
    return false;
}

bool validateWeight(double weight)
{
    return (weight >= LOWWEIGHT && weight <= HIGHWEIGHT); // returns true if weight is valid
}

bool validateBoxSize(double boxSize)
{
    return (boxSize == SIZE_MIN || boxSize == SIZE_MID || boxSize == SIZE_MAX); // returns true of boxSize is valid
}

char getSym(const struct Map* routeMap, int row, char column) {
    if (row < 0 || row >= routeMap->numRows || column < 'A' || column >= 'A' + routeMap->numCols) {
        return 0; // Return 0 for invalid input
    }
    return routeMap->squares[row][column - 'A'];
}


struct Coordinate convertToCoordinate(int row, char column) 
{
    struct Coordinate coordinate;
    coordinate.row = row;
    coordinate.column = column;

    return coordinate;
}

struct Coordinate findClosest(const struct Coordinate destination, const struct TruckInfo* trucks, const struct Map* baseMap)
{
    struct Point destinationPoint = { destination.row, destination.column };
    double minimumDistance;
    const struct Route* closestRoute;

    const struct Route blueRoute = getBlueRoute();
    const struct Route greenRoute = getGreenRoute();
    const struct Route yellowRoute = getYellowRoute();

    double blueDistance = distance(&blueRoute.points[0], &destinationPoint);
    double greenDistance = distance(&greenRoute.points[0], &destinationPoint);
    double yellowDistance = distance(&yellowRoute.points[0], &destinationPoint);

    minimumDistance = blueDistance;           // set min to blue

    if (greenDistance < minimumDistance)      // if green is smaller,
    {
        minimumDistance = greenDistance;      // set min to green

        if (yellowDistance < minimumDistance) // if yellow is even smaller than green,
        {
            minimumDistance = yellowDistance; // set min to yellow
            closestRoute = &yellowRoute;
        }
        else
        {
            closestRoute = &greenRoute;
        }
    }
    else
    {
        closestRoute = &blueRoute;
    }

    int closestIndex = getClosestPoint(closestRoute, destinationPoint);
    struct Coordinate closestCoordinate = convertToCoordinate(closestRoute->points[closestIndex].row, closestRoute->points[closestIndex].col + 'A');
    
    return closestCoordinate;
}

void printDiversion(const struct Route* diversionRoute, const struct Route* originalRoute, const struct Coordinate* destination)
{
    for (int i = 0; i < diversionRoute->numPoints; i++)
        printf("(%d, %c) ", diversionRoute->points[i].row, diversionRoute->points[i].col + 'A');
}


