#include <iostream>
#include <vector>
#include<chrono>
#include "dataset.h"
#include "dice.h"
#include"statistics.h"
using namespace std;

int main()
{
    vector<Record> cube = createCube();

    cout << "Total Records : " << cube.size() << endl;

    DiceQuery query;

    int choice;

    // Latitude 
    cout << "\nLatitude Filter\n";
    cout << "1. No Filter\n";
    cout << "2. Exact Value\n";
    cout << "3. Range\n";
    cout << "Enter Choice : ";
    cin >> choice;

    if(choice == 2)
    {
        query.useLatitude = true;
        query.latitudeRange = false;

        cout << "Enter Latitude : ";
        cin >> query.latitude;
    }
    else if(choice == 3)
    {
        query.useLatitude = true;
        query.latitudeRange = true;

        cout << "Enter Minimum Latitude : ";
        cin >> query.minLatitude;

        cout << "Enter Maximum Latitude : ";
        cin >> query.maxLatitude;
    }

    //Longitude 
    cout << "\nLongitude Filter\n";
    cout << "1. No Filter\n";
    cout << "2. Exact Value\n";
    cout << "3. Range\n";
    cout << "Enter Choice : ";
    cin >> choice;

    if(choice == 2)
    {
        query.useLongitude = true;
        query.longitudeRange = false;

        cout << "Enter Longitude : ";
        cin >> query.longitude;
    }
    else if(choice == 3)
    {
        query.useLongitude = true;
        query.longitudeRange = true;

        cout << "Enter Minimum Longitude : ";
        cin >> query.minLongitude;

        cout << "Enter Maximum Longitude : ";
        cin >> query.maxLongitude;
    }

    //Time 
    cout << "\nTime Filter\n";
cout << "1. No Filter\n";
cout << "2. Exact Time\n";
cout << "3. Time Range\n";
cout << "4. Custom Time Filter\n";
cout << "Enter Choice : ";
cin >> choice;

if(choice == 2)
{
    query.useTime = true;
    query.timeRange = false;

    cout << "\nEnter Day Month Year Hour : ";
    cin >> query.time.day
        >> query.time.month
        >> query.time.year
        >> query.time.hour;
}
else if(choice == 3)
{
    query.useTime = true;
    query.timeRange = true;

    cout << "\nStart Time (Day Month Year Hour): ";
    cin >> query.startTime.day
        >> query.startTime.month
        >> query.startTime.year
        >> query.startTime.hour;

    cout << "\nEnd Time (Day Month Year Hour): ";
    cin >> query.endTime.day
        >> query.endTime.month
        >> query.endTime.year
        >> query.endTime.hour;
}
else if(choice == 4)
{
    query.customfilter=true;
    char ch;
    
    cout << "\nFilter by Day? (y/n): ";
    cin >> ch;
    if(ch == 'y' || ch == 'Y')
    {
        query.useDay = true;
        cout << "Enter Day : ";
        cin >> query.day;
    }

    cout << "\nFilter by Month? (y/n): ";
    cin >> ch;
    if(ch == 'y' || ch == 'Y')
    {
        query.useMonth = true;
        cout << "Enter Month : ";
        cin >> query.month;
    }

    cout << "\nFilter by Year? (y/n): ";
    cin >> ch;
    if(ch == 'y' || ch == 'Y')
    {
        query.useYear = true;
        cout << "Enter Year : ";
        cin >> query.year;
    }

    cout << "\nFilter by Hour? (y/n): ";
    cin >> ch;
    if(ch == 'y' || ch == 'Y')
    {
        query.useHour = true;
        cout << "Enter Hour : ";
        cin >> query.hour;
    }
}

   vector<Record> result = dice(cube, query);

cout << "\n---------------------------------\n";
cout << "Matching Records : " << result.size() << endl;
cout << "---------------------------------\n";

if(result.empty())
{
    cout << "\nNo matching records found.\n";
    return 0;
}


// Statistics Menu

int statChoice;

cout << "\n===== Statistical Operations =====\n";
cout << "1. Sum\n";
cout << "2. Mean\n";
cout << "3. Minimum\n";
cout << "4. Maximum\n";
cout << "5. Range\n";
cout << "6. Variance\n";
cout << "7. Standard Deviation\n";
cout << "8. Median\n";
cout << "9. Coefficient of Variation\n";
cout << "10. Skip Statistics\n";
cout << "Enter Choice : ";
cin >> statChoice;

cout << endl;

switch(statChoice)
{
case 1:
    cout << "Sum : "
         << sum(result) << " mm" << endl;
    break;

case 2:
    cout << "Mean : "
         << mean(result) << " mm" << endl;
    break;

case 3:
    cout << "Minimum : "
         << minimum(result) << " mm" << endl;
    break;

case 4:
    cout << "Maximum : "
         << maximum(result) << " mm" << endl;
    break;

case 5:
    cout << "Range : "
         << range(result) << " mm" << endl;
    break;

case 6:
    cout << "Variance : "
         << variance(result) << endl;
    break;

case 7:
    cout << "Standard Deviation : "
         << standardDeviation(result) << endl;
    break;

case 8:
    cout << "Median : "
         << median(result) << " mm" << endl;
    break;

case 9:
    cout << "Coefficient of Variation : "
         << coefficientOfVariation(result)
         << " %" << endl;
    break;

case 10:
    cout << "Statistics skipped.\n";
    break;

default:
    cout << "Invalid Choice.\n";
}

    char printChoice;

    cout << "\nPrint Matching Records? (y/n): ";
    cin >> printChoice;

    if(printChoice == 'y' || printChoice == 'Y')
    {
        printCube(result);
    }

    return 0;
}
