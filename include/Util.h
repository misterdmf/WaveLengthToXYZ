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
        vector<float> getWaveLen();
        vector<pair<float,float> > getIntensity(vector<float> wave,map<int, vector<float> > m);
        map<int, vector<float> > getCIE();
        pair<float,float> desvio(vector<pair<float,float> > res);
        void writeResultToCsv(vector<pair<float,float> > res,pair<float,float> sd);

    protected:
    private:
};

#endif // UTIL_H
