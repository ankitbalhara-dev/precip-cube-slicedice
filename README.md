# Spatio-Temporal Data Cube Query Engine in C++

A C++ implementation of a **Spatio-Temporal Data Cube Query Engine** that performs **OLAP Dice operations** on a synthetic precipitation dataset. The project allows users to filter records using multiple spatial and temporal dimensions and compute statistical measures on the filtered results.

---

## Overview

This project simulates a multidimensional data warehouse where each record represents precipitation measured at a particular geographic location and time.

The query engine supports flexible **Dice operations**, enabling users to filter the cube using:

- Latitude
- Longitude
- Time
- Custom temporal filters

After filtering, the program can compute several statistical measures on the selected records.

---

## Dataset

The synthetic data cube contains **297,600 records**.

### Dimensions

| Dimension | Values |
|-----------|---------|
| Latitude | 1 – 20 |
| Longitude | 1 – 20 |
| Day | 1 – 31 |
| Month | 3 |
| Year | 2024 |
| Hour | 0 – 23 |

### Measure

- Precipitation (0–100 mm)

---

## Record Structure

Each record contains:

```cpp
Record
{
    latitude
    longitude
    time
    precipitation
}
```

where

```cpp
Time
{
    day
    month
    year
    hour
}
```

---

# Features

## Dice Query Processing

Supports filtering by

### Latitude

- Exact value
- Range

### Longitude

- Exact value
- Range

### Time

- Exact timestamp
- Time interval

### Custom Time Filter

Filter independently by

- Day
- Month
- Year
- Hour

Example:

```
Day = 15
Hour = 12
```

without specifying month or year.

---

## Statistical Operations

After filtering, users may compute

- Sum
- Mean
- Minimum
- Maximum
- Range
- Variance
- Standard Deviation
- Median
- Coefficient of Variation

Statistics are computed only on the filtered records.

---

# Project Structure

```
Project
│
├── dataset.h
├── dice.h
├── statistics.h
├── main.cpp
└── README.md
```

---

# How It Works

```
Generate Data Cube
        │
        ▼
Take User Filters
        │
        ▼
Perform Dice Operation
        │
        ▼
Generate Filtered Dataset
        │
        ▼
Choose Statistical Operation
        │
        ▼
Display Result
        │
        ▼
(Optional)
Print Matching Records
```

---

# Dice Operation Workflow

For every record in the cube

```
Check Latitude

      │

      ▼

Check Longitude

      │

      ▼

Check Time

      │

      ▼

Check Custom Time Filters

      │

      ▼

If all conditions satisfied

      │

      ▼

Store Record
```

---

# Time Comparison

Instead of comparing

```
Year
Month
Day
Hour
```

individually, the program converts time into a single sortable integer.

Example

```
2024-03-15 12
```

becomes

```
2024031512
```

This enables efficient

- equality comparison
- range comparison

using integer operations.

---

# Optimization

The Dice algorithm uses **early pruning (early termination).**

Example

```cpp
if(!match)
    continue;
```

If a record fails one filter, the remaining conditions are skipped.

Benefits

- fewer comparisons
- lower execution time
- improved practical performance

---

# Time Complexity

## Dataset Generation

```
O(N)
```

where

```
N = 297,600
```

---

## Dice Operation

Worst Case

```
O(N)
```

Each record is checked once.

---

## Statistical Operations

| Operation | Complexity |
|------------|------------|
| Sum | O(n) |
| Mean | O(n) |
| Minimum | O(n) |
| Maximum | O(n) |
| Range | O(n) |
| Variance | O(n) |
| Standard Deviation | O(n) |
| Median | O(n log n) |
| Coefficient of Variation | O(n) |

where

```
n = number of filtered records
```

---

# Compilation

Using g++

```bash
g++ main.cpp -o cube
```

or

```bash
g++ -std=c++17 main.cpp -o cube
```

---

# Running

```bash
./cube
```

Windows

```bash
cube.exe
```

---

# Example Execution

```
Total Records : 297600

Latitude Filter
1. No Filter
2. Exact Value
3. Range

Longitude Filter
1. No Filter
2. Exact Value
3. Range

Time Filter
1. No Filter
2. Exact Time
3. Time Range
4. Custom Time Filter
```

Output

```
Matching Records : 744

Mean : 49.63 mm
```

---

# Future Improvements

- Slice operation
- Roll-up
- Drill-down
- Pivot
- Multi-threaded Dice processing
- Parallel statistical computation
- File-based dataset loading
- Distributed query processing

---

# Applications

- Weather analytics
- Climate data analysis
- OLAP systems
- Spatial databases
- Decision support systems
- Research in multidimensional query processing

---

# Author

Developed as a C++ implementation of a **Spatio-Temporal Data Cube Query Engine** for studying multidimensional query processing and statistical analysis.
