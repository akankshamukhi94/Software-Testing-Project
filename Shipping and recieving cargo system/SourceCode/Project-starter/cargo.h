/*
SFT Group Project
Group 11
rkoirala2@myseneca.ca  - Richa Koirala (Junior Developer )
msingh802@myseneca.ca -  Manjot Singh (Junior Developer ) 
akanksha4@myseneca.ca - Akanksha (Team leader )
agangat2@myseneca.ca  - Ammar Gangat (Project Manager )
*/
#pragma once
#ifndef CARGO_H
#define CARGO_H

#include "stdbool.h"
#include "Mapping.h"

#define LOWWEIGHT 1      // Minimum weight in kilograms
#define HIGHWEIGHT 1200  // Maximum weight in kilograms

#define SIZE_MIN 0.5      // Minimum box size in cubic meters
#define SIZE_MID 1        // Mid-range box size in cubic meters
#define SIZE_MAX 5        // Maximum box size in cubic meters

// Structure to hold truck information
struct TruckInfo {
	double weight;	    // Valid range: 1-1200 Kg
	double boxSize;     // Valid sizes: 0.5, 1, 5 cubic meters
};

// Structure to represent a coordinate
struct Coordinate {
	int row;
	char column;
};

/// <summary>
/// Function to print the header "Seneca College Deliveries" to the console
/// </summary>
void printHdr();

/// <summary>
/// Function to print the footer "Thanks for shipping with Seneca!" to the console
/// </summary>
void printFtr();

/// <summary>
/// Function to get user input for truck details including weight, box size, and destination
/// </summary>
/// <param name="truck">a pointer to TruckInfo that'll hold its info (truck details)</param>
void setTruck(struct TruckInfo*);

/// <summary>
/// Function to validate if the destination is within the grid boundaries
/// </summary>
/// <param name="routeMap">a pointer to Map (a 2D rep. of a map)</param>
/// <param name="destRow">the row position of the square on the routeMap</param>
/// <param name="destCol">the column position of the square on the routeMap</param>
/// <returns>if dest. is within boundaries (true/false)</returns>
bool isDestValid(const struct Map* routeMap, int destRow, char destCol);

/// <summary>
/// Function to check if the entered destination is within the valid range (A-Y for column and 1-25 for row)
/// </summary>
/// <param name="inputString">a char* of the entered destination</param>
/// <param name="rowNum">row position of the destination</param>
/// <param name="columnChar">column position of the destination</param>
bool checkDestInput(const char* inputString, int* rowNum, char* columnChar);

/// <summary>
/// Function to validate truck weight within the range of 1-1200 Kg
/// </summary>
/// <param name="weight">the truck weight in KG</param>
/// <returns>if weight is within range (true/false)</returns>
bool validateWeight(double weight);

/// <summary>
/// Function to validate truck box size within the valid range of 0.5, 1, or 5 cubic meters
/// </summary>
/// <param name="boxSize">size of the truck box in cubic meters</param>
/// <returns>if box is within range (true/false)</returns>
bool validateBoxSize(double boxSize);

/// <summary>
/// Function to return the symbol associated with the row and column on the map
/// </summary>
/// <param name="routeMap">a pointer to the Map being used</param>
/// <param name="row">the row pos on the map</param>
/// <param name="column">the column pos on the map</param>
/// <returns>the symbol at the row-col square</returns>
char getSym(const struct Map* routeMap, int row, char column);

/// <summary>
/// Function to convert validated destination (e.g., 12L) into a Coordinate structure
/// </summary>
/// <param name="row">the row pos of the destination</param>
/// <param name="column">the column pos of the destination</param>
/// <returns>the Coordinate of the destination</returns>
struct Coordinate convertToCoordinate(int row, char column);

/// <summary>
/// Function to find the closest point on the route to the destination point
/// </summary>
/// <param name="destination">Coordinate of the destination (row-col)</param>
/// <param name="trucks">info of all the trucks (weight, box size)</param>
/// <param name="baseMap">the map containing the routes</param>
/// <returns>Coordinate of the closest point</returns>
struct Coordinate findClosest(const struct Coordinate destination, const struct TruckInfo* trucks, const struct Map* baseMap);

/// <summary>
/// Function to print the route diversion onto the console
/// </summary>
/// <param name="diversionRoute">the diversion path the truck will take</param>
/// <param name="originalRoute">the original path of the truck</param>
/// <param name="destination">the destination of the truck</param>
void printDiversion(const struct Route* diversionRoute, const struct Route* originalRoute, const struct Coordinate* destination);

#endif /* CARGO_H */
