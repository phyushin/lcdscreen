phyushin's adventures in arduino / lcd screens!

this example uses the LCD screen from http://www.adafruit.com/products/250

currently pulsates in selected colour 

- button press controls the colour
colour is selected on a bit mask flag (buttonpress count % 8) 

2^0 =     1 = RED
2^1 =     2 = GREEN
(2^2)-1 = 3 = YELLOW
2^2 =     4 = BLUE
(2^2)+1 = 5 = PURPLE
(2^2)+2 = 6 = TURQUOISE
(2^3)-1 = 7 =  WHITE
2^3 =     8 =OFF