# uart0_tx2 project  
This is 5th sample project.  
The uart TXD0( at pin 9 ) outputs by intterupt.  
The fixed output data of UART0 is as follows.  
Three  
TWO  
1  
Zero  
Go! RL78/G10 AE-R5F10Y47ASP...  
Baud rate is 38400bps, the data fomat is 8bits, 1 stop bit, non-parity.  
LED works blinking 1Hz at pin 11(port 0.2).  
## Updates
New InitTimer0_20ms() function controls update every 20ms.    
The systick timer counts from 0 to 49. It means systick timer reset every second.  

