#include <iostream>
#include <algorithm>
#include <cmath>
#include <climits>
#include <iomanip>
#include <cstdio>

using namespace std;

const int MAXSPROCKETS = 11;
const int MAXGEARRATIOS = 122;

int main()
{
    int nFrontSprockets = 0;
    int nRearSprockets = 0;
    int frontTeeth[MAXSPROCKETS] = {0};
    int rearTeeth[MAXSPROCKETS] = {0};
    int m = 0;
    int n = 0;
    float gearRatio = 0.0;
    float gearRatios[MAXGEARRATIOS] = {0.0};
    float maxSpread = 0.0;
    float spread = 0.0;
    int totalGearRatios = 0;
    int index = 0;

    while (cin >> nFrontSprockets) {
        if (nFrontSprockets == 0) break;
        cin >> nRearSprockets;
        for (int i = 0; i < nFrontSprockets; ++i) {
            cin >> frontTeeth[i];
        }
        for (int j = 0; j < nRearSprockets; ++j) {
            cin >> rearTeeth[j];
        }
        //cout << "Debug: " << " gear ratios: " << endl;
        index = -1;
        for (int i = 0; i < nFrontSprockets; ++i) {
            for (int j = 0; j < nRearSprockets; ++j) {
                n = rearTeeth[j];
                m = frontTeeth[i];
                gearRatio = ((float)n/(float)m);
//                index = i*nRearSprockets + j;
                gearRatios[++index] = gearRatio;
                //cout << "Debug: " << "index= " << index << " [" << j << "," << i << "]: " << "rearTeeth[j]= " << n << " frontTeeth[i]= " << m << ":" << gearRatio << endl;
            }
        }
        totalGearRatios = (nFrontSprockets * nRearSprockets);
        sort(gearRatios, gearRatios + totalGearRatios);
        maxSpread = gearRatios[0];
        for (int i = 0; i < (totalGearRatios - 1); ++i) {
            //cout << "Debug: " << "GearRatios[" << i << "]: " << gearRatios[i] << endl;
            spread = gearRatios[i+1]/gearRatios[i];
            if (spread > maxSpread)
                maxSpread = spread;
        }
        //cout << "Debug: " << " max spread= ";
        //cout << "Debug: " << "Without precision= " << maxSpread << endl;
        printf("%.2f\n", maxSpread);
        //cout << std::setprecision(3) << maxSpread << endl;


    }
    return 0;
}
