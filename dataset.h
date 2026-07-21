#ifndef DATASET_H
#define DATASET_H

#include <vector>
#include <random>

using namespace std;


// Time Dimension

struct Time
{
    int day;
    int month;
    int year;
    int hour;
};

// Cube Record

struct Record
{
    float latitude;
    float longitude;
    Time time;
    double precipitation;
};


// Create Data Cube

inline vector<Record> createCube()
{
    vector<Record> cube;

    cube.reserve(20 * 20 * 31 * 24);

    random_device rd;
    mt19937 gen(rd());

    uniform_real_distribution<double> rain(0.0, 100.0);

    for (float lat = 1.0f; lat <= 20.0f; lat += 1.0f)
    {
        for (float lon = 1.0f; lon <= 20.0f; lon += 1.0f)
        {
            for (int day = 1; day <= 31; day++)
            {
                for (int hour = 0; hour < 24; hour++)
                {
                    Record r;

                    r.latitude = lat;
                    r.longitude = lon;

                    r.time.day = day;
                    r.time.month = 3;
                    r.time.year = 2024;
                    r.time.hour = hour;

                    r.precipitation = rain(gen);

                    cube.push_back(r);
                }
            }
        }
    }

    return cube;
}

#endif