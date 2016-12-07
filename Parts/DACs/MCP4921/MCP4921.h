/* 
* MCP4921.h
*
* Created: 05/12/2016 22:38:41
* Author: Aodhan
*/


#ifndef __MCP4921_H__
#define __MCP4921_H__

#include <Arduino.h>
class MCP4921
{
//variables
public:
	double vRef;
protected:
private:
	volatile uint8_t* csPORT;
	uint8_t csPIN;
	volatile uint8_t* ldacPORT;
	uint8_t ldacPIN;

//functions
public:
	MCP4921(double vRef, volatile uint8_t*,uint8_t,volatile uint8_t*,uint8_t);
	~MCP4921();
	void setValue(int);
	void setVoltage(double);
protected:
private:
	MCP4921( const MCP4921 &c );
	MCP4921& operator=( const MCP4921 &c );

}; //MCP4921
#endif //__MCP4921_H__
