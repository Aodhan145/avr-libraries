#MCP4921 Usage
Instantiate class
```C++
MCP4921* dac = new MCP4921(vRef, &csPORT, csPIN, &ldacPORT, ldacPIN);
```
e.g
vRef = 4.096V CS pin: PB1 LDAC pin: PB2
```C++
MCP4921* dac = new MCP3301(4.096, &PORTB, (1<<1), &PORTB, (1<<2));
```
Set Voltage
```C++
  dac->setVoltage(2.0);
```
Set Value
```C++
  dac->setVoltage(2048);
```
