/* 
* MCP3301.cpp
*
* Created: 06/12/2016 20:59:15
* Author: Aodhan
*/


#include "MCP3301.h"

// default constructor
MCP3301::MCP3301(double vRef ,volatile uint8_t *csPort, uint8_t csPin)
{
	this->csPort = csPort;
	this->csPin = csPin;
	this->vRef = vRef;
} //MCP3301

// default destructor
MCP3301::~MCP3301()
{
} //~MCP3301

int MCP3301::readData()
{
	//CS Low
	*csPort &= ~csPin;
	//Transmit nothing
	SPDR = 0x00;
	//Wait for data to be transmitted
	while((SPSR & (1<<SPIF)) == 0);
	byte firstData = SPDR;
	//Transmit nothing
	SPDR = 0x00;
	//Wait for data to be transmitted
	while((SPSR & (1<<SPIF)) == 0);
	byte secondData = SPDR;
	//CS High
	*csPort |= csPin;
	int data = (((firstData&0x0F)<<8)|secondData);
	if((firstData&(1<<4)) != 0)
	{
		data = -data;
	}
	return data;
}

double MCP3301::readVoltage()
{
	int data = readData();
	double voltage = this->vRef * data;
	voltage = voltage / 4096.0;
	return voltage;
}
