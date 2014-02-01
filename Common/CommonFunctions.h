#ifndef COMMON_FUNCTIONS_H
#define COMMON_FUNCTIONS_H
#define PI 3.14159f
#define ARRAY_LEN(arr) (int)(sizeof(arr)/sizeof(arr[0]))
inline float RadiansToDegrees(float radians){return radians * 180 / PI;}
inline float DegreesToRadians(float degrees){return degrees * PI / 180;}
#endif
