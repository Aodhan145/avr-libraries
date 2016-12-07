/* 
* MCP3301.h
*
* Created: 06/12/2016 20:59:15
* Author: Aodhan
*/


#ifndef __MCP3301_H__
#define __MCP3301_H__
#define byte uint8_t
#include <avr/io.h>
#include <stdint.h>

class MCP3301
{
//variables
public:
	double vRef;
protected:
private:
	volatile uint8_t *csPort;
	uint8_t csPin;

//functions
public:
	MCP3301(double vRef, volatile uint8_t *csPort, uint8_t csPin);
	~MCP3301();
	int readData(void);
	double readVoltage(void);
protected:
private:
	MCP3301( const MCP3301 &c );
	MCP3301& operator=( const MCP3301 &c );

}; //MCP3301

#endif //__MCP3301_H__
