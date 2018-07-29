# systick_test project  
This is 4th sample project.  
LED works blinking 1Hz at pin 11(port 0.2).  
The uart TXD0( at pin 9 ) polling output every 100ms.  
Output data is fixed data from 0x30, '0' to 0x36, '6'.  
Baud rate is 38400bps, the data fomat is 8bits, 1 stop bit, non-parity.  
The polling 100ms period is made from systick timer each 500us, 1ms, 2ms 5ms, 10ms, 33.3ms and 50ms. 
## Updates
New InitTimer0_us() function controls update period of systick timer.  
The update period is 52000 microseconds max, means 52 miliseconds.  
The systick timer is named "systick" as uint16_t type.
