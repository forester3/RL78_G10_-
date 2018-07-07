# uart0-tx1 project  
This is third sample projet.  
LED works blinking 1.2Hz at pin 11(port 0.2).  
You can connect LED through  around 1k ohm from 5V.  
This sample works reset voltage at 4.2V.  
## Updates
The uart TXD0( at pin 9 ) polling output every 100ms.  
Output date is fixed data from 0x30, '0' to 0x37, '7'.  
Baud rate is 38400bps, the data fomat is 8bits, 1 stop bit, non-parity.