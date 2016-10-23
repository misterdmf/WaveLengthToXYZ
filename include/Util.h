#ifndef UTIL_H
#define UTIL_H
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <math.h>
using namespace std;
class Util
{
    public:
        // To read the wavelengths
        vector<float> getWaveLen();
        // To read the intensities and to calculate the color as (x,y)
        vector<pair<float,float> > getIntensity(vector<float> wave,map<int, vector<float> > m);
        // To read the CIE 1931 values
        map<int, vector<float> > getCIE();
        // To calculate the standard deviation
        pair<float,float> standDev(vector<pair<float,float> > res);
        // To write results to Console and CSV
        void writeResultToCsv(vector<pair<float,float> > res,pair<float,float> sd);

};

#endif // UTIL_H
