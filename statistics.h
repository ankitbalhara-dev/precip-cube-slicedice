#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
#include <algorithm>
#include <cmath>
#include <stdexcept>

#include "dataset.h"

using namespace std;


// Sum

inline double sum(const vector<Record> &data)
{
    double total = 0.0;

    for (const Record &r : data)
        total += r.precipitation;

    return total;
}


// Mean

inline double mean(const vector<Record> &data)
{
    if (data.empty())
        throw runtime_error("Dataset is empty.");

    return sum(data) / data.size();
}


// Minimum

inline double minimum(const vector<Record> &data)
{
    if (data.empty())
        throw runtime_error("Dataset is empty.");

    double minValue = data[0].precipitation;

    for (const Record &r : data)
    {
        if (r.precipitation < minValue)
            minValue = r.precipitation;
    }

    return minValue;
}


// Maximum

inline double maximum(const vector<Record> &data)
{
    if (data.empty())
        throw runtime_error("Dataset is empty.");

    double maxValue = data[0].precipitation;

    for (const Record &r : data)
    {
        if (r.precipitation > maxValue)
            maxValue = r.precipitation;
    }

    return maxValue;
}


// Range

inline double range(const vector<Record> &data)
{
    return maximum(data) - minimum(data);
}


// Variance (Population)

inline double variance(const vector<Record> &data)
{
    if (data.empty())
        throw runtime_error("Dataset is empty.");

    double avg = mean(data);

    double var = 0.0;

    for (const Record &r : data)
    {
        double diff = r.precipitation - avg;
        var += diff * diff;
    }

    return var / data.size();
}

// Standard Deviation

inline double standardDeviation(const vector<Record> &data)
{
    return sqrt(variance(data));
}


// Median

inline double median(const vector<Record> &data)
{
    if (data.empty())
        throw runtime_error("Dataset is empty.");

    vector<double> values;

    values.reserve(data.size());

    for (const Record &r : data)
        values.push_back(r.precipitation);

    sort(values.begin(), values.end());

    int n = values.size();

    if (n % 2 == 0)
        return (values[n / 2 - 1] + values[n / 2]) / 2.0;

    return values[n / 2];
}

// Coefficient of Variation

inline double coefficientOfVariation(const vector<Record> &data)
{
    double avg = mean(data);

    if (avg == 0)
        return 0;

    return (standardDeviation(data) / avg) * 100.0;
}

#endif