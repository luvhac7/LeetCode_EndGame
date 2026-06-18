class Solution {
public:
typedef double d;
    double angleClock(int hr, int min) {
        d man=6.0*min,han=30.0*(hr%12)+0.5*min;
        d dif=abs(man-han);
        return std::min(dif,360.0-dif);
    }
};