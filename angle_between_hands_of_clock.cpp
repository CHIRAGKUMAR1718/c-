class Solution {
public:
    double angleClock(int hour, int minutes) {
        double t_m=minutes*6.0;
        double t_h=(hour%12)*30+minutes/2.0;
        double ans=abs(t_h-t_m);
        return min(ans,360-ans);
    }
};