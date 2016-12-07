#MCP3301 Usage
Instantiate class
```C++
MCP3301* dac = new MCP3301(vRef, &csPORT, csPIN);
```
e.g
vRef = 4.096V CS pin: PB1
```C++
MCP3301* dac = new MCP3301(4.096, &PORTB, (1<<1));
```
Read Voltage
```C++
double voltage = dac->readVoltage();
```
Read Value
```C++
int value = dac->readValue();
```
