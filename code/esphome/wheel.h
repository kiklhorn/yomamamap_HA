// https://votecharlie.com/blog/2018/08/improved-color-wheel-function.html
// Adapted from https://www.stm32duino.com/viewtopic.php?t=56#p8160
unsigned int sqrt32(unsigned long n) {
    unsigned int c = 0x8000;
    unsigned int g = 0x8000;
    while(true) {
    if(g*g > n) {
        g ^= c;
    }
    c >>= 1;
    if(c == 0) {
        return g;
    }
    g |= c;
    }
}

// Input values 0 to 255 to get color values that transition R->G->B. 0 and 255
// are the same color. This is based on Adafruit's Wheel() function, which used
// a linear map that resulted in brightness peaks at 0, 85 and 170. This version
// uses a quadratic map to make values approach 255 faster while leaving full
// red or green or blue untouched. For example, Wheel(42) is halfway between
// red and green. The linear function yielded (126, 129, 0), but this one yields
// (219, 221, 0). This function is based on the equation the circle centered at
// (255,0) with radius 255:  (x-255)^2 + (y-0)^2 = r^2
// Color Wheel(byte position) {  //Red & Green swapped vs Adafruit. Is this mistake?
//     byte R = 0, G = 0, B = 0;
//     if (position < 85) {
//     R = sqrt32((1530 - 9 * position) * position);
//     G = sqrt32(65025 - 9 * position * position);
//     } else if (position < 170) {
//     position -= 85;
//     R = sqrt32(65025 - 9 * position * position);
//     B = sqrt32((1530 - 9 * position) * position);
//     } else {
//     position -= 170;
//     G = sqrt32((1530 - 9 * position) * position);
//     B = sqrt32(65025 - 9 * position * position);
//     }
//     return Color(R, G, B);
// }

Color Wheel(byte position) {
    byte R = 0, G = 0, B = 0;
    if (position < 85) {
    G = sqrt32((1530 - 9 * position) * position);
    R = sqrt32(65025 - 9 * position * position);
    } else if (position < 170) {
    position -= 85;
    G = sqrt32(65025 - 9 * position * position);
    B = sqrt32((1530 - 9 * position) * position);
    } else {
    position -= 170;
    R = sqrt32((1530 - 9 * position) * position);
    B = sqrt32(65025 - 9 * position * position);
    }
    return Color(R, G, B);
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
Color WheelAda(byte WheelPos) {
    WheelPos = 255 - WheelPos;
    if(WheelPos < 85) {
        return Color(255 - WheelPos * 3, 0, WheelPos * 3);
    }
    if(WheelPos < 170) {
        WheelPos -= 85;
        return Color(0, WheelPos * 3, 255 - WheelPos * 3);
    }
    WheelPos -= 170;
    return Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}

//https://medium.com/@kslooi/print-formatted-data-in-arduino-serial-aaea9ca840e3
#include <stdarg.h>
#define SERIAL_PRINTF_MAX_BUFF      256
void serialPrintf(const char *fmt, ...);
void serialPrintf(const char *fmt, ...) {
    /* Buffer for storing the formatted data */
    char buff[SERIAL_PRINTF_MAX_BUFF];
    /* pointer to the variable arguments list */
    va_list pargs;
    /* Initialise pargs to point to the first optional argument */
    va_start(pargs, fmt);
    /* create the formatted data and store in buff */
    vsnprintf(buff, SERIAL_PRINTF_MAX_BUFF, fmt, pargs);
    va_end(pargs);
    Serial.print(buff);
}
