#include <iostream>
#include <sstream>
#include "pch.h"
#include "CppUnitTest.h"
#include "mapping_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(Test_populateMap)
        {
            struct Map map = populateMap();

            // Verify the number of columns and rows
            Assert::AreEqual(25, map.numRows);
            Assert::AreEqual(25, map.numCols);
        }

        TEST_METHOD(ShortestPath_ValidPath)
        {
            // Arrange: Create a map and define start and destination points
            struct Map testMap = populateMap();
            struct Point start = { 0, 0 };
            struct Point dest = { 5, 5 };

            // Act: Call the shortestPath function
            struct Route result = shortestPath(&testMap, start, dest);

            // Assert: Check if a valid path exists
            Assert::IsTrue(result.numPoints > 0, L"Path should exist");

            // Additional path validation checks to be implemented
        }
        TEST_METHOD(GetClosestPoint_NoPoints)
        {
            // Create an empty route
            struct Route emptyRoute = {};

            // Define a reference point
            struct Point referencePoint = { 5, 5 };

            // Call the getClosestPoint function
            int closestIndex = getClosestPoint(&emptyRoute, referencePoint);

            // Verify that the closest index is -1
            Assert::AreEqual(-1, closestIndex, L"No points should return -1 or similar sentinel value");
        }
        TEST_METHOD(AddRoute_ValidRoute)
        {
            // Create a mock map with some sample data
            struct Map testMap = {
                {
                    {0, 0, 0},
                    {0, 0, 0},
                    {0, 0, 0}
                },
                3,
                3
            };

            // Create a mock route with some sample data
            struct Route testRoute = {
                { {0, 0}, {0, 1}, {0, 2} },
                3,
                '*'
            };

            // Call the addRoute function
            struct Map result = addRoute(&testMap, &testRoute);

            // Define the expected map after adding the route
            struct Map expectedMap = {
                {
                    {'*', '*', '*'},
                    {0, 0, 0},
                    {0, 0, 0}
                },
                3,
                3
            };

            // Verify that the resulting map matches the expected map
            Assert::IsTrue(memcmp(&result, &expectedMap, sizeof(struct Map)) == 0, L"The map after adding the route does not match the expected map.");
        }
        TEST_METHOD(Distance_ValidPoints)
        {
            // Create two points for testing
            struct Point p1 = { 0, 0 };
            struct Point p2 = { 3, 4 };

            // Calculate the expected distance
            double expectedDistance = 5.0; // For (0, 0) and (3, 4) using Pythagorean theorem

            // Call the distance function
            double result = distance(&p1, &p2);

            // Verify that the resulting distance matches the expected distance
            Assert::AreEqual(expectedDistance, result, 0.0001, L"The distance between the points is incorrect.");
        }



    };
}
