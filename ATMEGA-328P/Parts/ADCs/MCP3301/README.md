#MCP3301 Usage
Instantiate class
```C++
MCP3301 dac(vRef, &csPORT, csPIN);
```
e.g
vRef = 4.096V CS pin: PB1
```C++
MCP3301 dac(4.096, &PORTB, (1<<1));
```
