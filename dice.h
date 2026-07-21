#ifndef DICE_H
#define DICE_H

#include <vector>
#include <iostream>

#include "dataset.h"

using namespace std;


// Dice Query Structure

struct DiceQuery
{
    // Latitude 
    bool useLatitude = false;
    bool latitudeRange = false;

    float latitude;
    float minLatitude;
    float maxLatitude;

    //Longitude 
    bool useLongitude = false;
    bool longitudeRange = false;

    float longitude;
    float minLongitude;
    float maxLongitude;

    //Time 
    bool useTime = false;
    bool timeRange = false;

    Time time;
    Time startTime;
    Time endTime;

    // Custom Time Filters 
    bool customfilter=false;
    bool useDay = false;
    bool useMonth = false;
    bool useYear = false;
    bool useHour = false;

    int day;
    int month;
    int year;
    int hour;
};

// Convert Time into Comparable Number

inline long long timeValue(const Time &t)
{
    return ((long long)t.year * 1000000LL) +
           ((long long)t.month * 10000LL) +
           ((long long)t.day * 100LL) +
           t.hour;
}


// Dice Operation

inline vector<Record> dice(const vector<Record> &cube,
                           const DiceQuery &query)
{
    vector<Record> result;

    for (const Record &r : cube)
    {
        bool match = true;

        //Latitude
        if (query.useLatitude)
        {
            if (query.latitudeRange)
            {
                match &= (r.latitude >= query.minLatitude &&
                          r.latitude <= query.maxLatitude);
            }
            else
            {
                match &= (r.latitude == query.latitude);
            }
        }
        if(!match)
        continue;

        //Longitude
        if (query.useLongitude)
        {
            if (query.longitudeRange)
            {
                match &= (r.longitude >= query.minLongitude &&
                          r.longitude <= query.maxLongitude);
            }
            else
            {
                match &= (r.longitude == query.longitude);
            }
        }
        if(!match)
        continue;
        //Exact Time / Time Range 
        if (query.useTime)
        {
            long long current = timeValue(r.time);

            if (query.timeRange)
            {
                match &= (current >= timeValue(query.startTime) &&
                          current <= timeValue(query.endTime));
            }
            else
            {
                match &= (current == timeValue(query.time));
            }
        }
        if(!match)
        continue;

        // Custom Time Filters
        if(query.customfilter){
        if (query.useDay)
            match &= (r.time.day == query.day);

        if (query.useMonth)
            match &= (r.time.month == query.month);

        if (query.useYear)
            match &= (r.time.year == query.year);

        if (query.useHour)
            match &= (r.time.hour == query.hour);
            }

        //Add Record
        if (match)
            result.push_back(r);
    }

    return result;
}


// Print Cube

inline void printCube(const vector<Record> &cube)
{
    for (const Record &r : cube)
    {
        cout << "Latitude : " << r.latitude
             << "  Longitude : " << r.longitude
             << "  Date : "
             << r.time.day << "-"
             << r.time.month << "-"
             << r.time.year
             << "  Hour : " << r.time.hour
             << "  Precipitation : "
             << r.precipitation << " mm"
             << endl;
    }
}

#endif