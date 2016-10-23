#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <vector>
#include "Util.h"


int main()
{
    vector<float> waves;
    map<int, vector<float> > tabCIE;
    vector<pair<float,float> > res;
    pair<float,float> sd;
    Util util;

    // reading wavelenghts
    waves = util.getWaveLen();
    // reading CIE 1931 values
    tabCIE = util.getCIE();
    // reading intensities and calculating the colors as (x,y)
    res = util.getIntensity(waves,tabCIE);
    // calculating Standard deviation
    sd = util.standDev(res);

    // writing result to Console and CSV
    util.writeResultToCsv(res,sd);

    return 0;
}
