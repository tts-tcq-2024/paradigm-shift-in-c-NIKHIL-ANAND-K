#include <stdio.h>
#include <assert.h>

/* Function prototypes */
void logger(const char* stringToBePrinted);

/* Function to check whether the battery parameter is within the range */
int checkRange(float data, float min, float max, const char* nameOfBatteryParameter) {
    if (data > max || data < min) {
        logger(nameOfBatteryParameter);
        return 0; // OUTOFBOUNDARY
    }
    return 1; // WITHINRANGE
}

/* Function to print the error logs */
void logger(const char* stringToBePrinted) {
    printf("%s out of range!\n", stringToBePrinted);
}

/* Function to check if battery parameters are within acceptable ranges */
int batteryIsOk(float temperature, float soc, float chargeRate) {
    if (!checkRange(temperature, 0, 45, "Temperature")) {
        return 0;
    }
    
    if (!checkRange(soc, 20, 80, "State of Charge")) {
        return 0;
    }
    
    return checkRange(chargeRate, 0, 0.8, "Charge Rate");
}

/* Main function */
int main() {
    assert(batteryIsOk(25, 70, 0.7));
    assert(!batteryIsOk(50, 85, 0));
    
    return 0;
}
