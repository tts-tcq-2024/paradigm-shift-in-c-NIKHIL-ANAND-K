#include <stdio.h>
#include <assert.h>
 
#define OUTOFBOUNDARY 0
#define WITHINRANGE 1
 
/*Function to check whether the battery paramter is within the range*/
int checkRange(float data, float min, float max, const char* nameOfBatteryParameter)
{
int output = WITHINRANGE;
if (data > max || data < min)
{
  output = OUTOFBOUNDARY;
  logger(nameOfBatteryParameter);
}
return output;
}
 
/*Function to print the error logs*/
void logger(const char* stringToBePrinted)
{
printf("%s out of range!\n",stringToBePrinted);
}
 
int batteryIsOk(float temperature, float soc, float chargeRate) 
{
int functionResult = 1; 
if(checkRange(temperature,0,45,"Temperature") == OUTOFBOUNDARY)
{
  functionResult = 0;
}
else if(checkRange(soc,20,80,"State of Charge") == OUTOFBOUNDARY)
{
  functionResult = 0;
}
else
{
  functionResult = checkRange(chargeRate,0,0.8,"Charge Rate");
}
  return functionResult;
}
 
int main() {
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
