#MCP3301 Usage
Instantiate class
'''cpp
MCP3301 dac(vRef, &csPORT, csPIN);
'''
e.g
'''C++
MCP3301 dac(4.096, &PORTB, (1<<1));
'''
