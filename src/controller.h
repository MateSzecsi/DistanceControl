#if !defined(_CONTROLLER_H_)
#define _CONTROLLER_H_

#include <stdint.h>

class Controller
{
private:
    float integralValue = 0;
    unsigned referenceDistance = 20;
    unsigned currentDistance;
    int16_t currentLoad = 0;
    int8_t error = 0;

    void updateData();
public:
    void calculateAndSetLoad();

    unsigned getCurrentDistance();
    int getCurrentLoad();
    void setReferenceDistance(unsigned referenceDistance);
    
};




#endif // _CONTROLLER_H_
