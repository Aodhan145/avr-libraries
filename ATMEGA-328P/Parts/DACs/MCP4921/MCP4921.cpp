/* 
* MCP4921.cpp
*
* Created: 05/12/2016 22:38:41
* Author: Aodhan
*/

#include "MCP4921.h"

// default constructor
MCP4921::MCP4921(double vRef, volatile uint8_t *csPort, uint8_t csPin, volatile uint8_t *ldacPort,	uint8_t ldacPin)
{
	//ENABLE SPI
	SPCR = (1<<SPE)|(1<<MSTR)|(1<<SPR0);
	this->csPORT = csPort;
	this->csPIN = csPin;
	this->ldacPORT = ldacPort;
	this->ldacPIN = ldacPin;
	this->vRef = vRef;
} 

// default destructor
MCP4921::~MCP4921()
{
} 

void MCP4921::setValue(int value)
{
	//Set CS Low
	*this->csPORT &= ~csPIN;
	byte data = (1<<5)|(1<<4)|((value&0xF00)>>8);
	SPDR = data;
	//Wait for data to be transmitted
	while((SPSR & (1<<SPIF)) == 0);
	data = value&0xFF;
	SPDR = data;
	//Wait for data to be transmitted
	while((SPSR & (1<<SPIF)) == 0);
	//Set CS HIGH
	*this->csPORT |= csPIN;
	//Set LDAC Low
	*this->ldacPORT &= ~ldacPIN;
	//Delay > 100ns [ 2 Clock cycles == 125 ns]
	asm volatile ("nop");
	asm volatile ("nop");
	//Set LDAC HIGH
	*this->ldacPORT |= ldacPIN;
}

void MCP4921::setVoltage(double voltage)
{
	voltage = voltage / this->vRef;
	voltage = voltage * 4096.0;
	int value = voltage;
	
	if(value >= 4096)
	{
		value = 4095;
	}
	if(value<0)
	{
		value = 0;
	}
	setValue(value);
}
