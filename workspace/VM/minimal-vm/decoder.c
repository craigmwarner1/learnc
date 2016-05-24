#include <stdio.h>
#include <stdint.h>
#include <string.h>
    
void decode_moods (uint16_t messages)
{
    uint16_t mood = messages;
    uint16_t n = mood >> 11;  
    uint16_t m = n & 0x000F; 
    switch (m)
    {
    case 0x0000:   
        printf( "happy ");
        break;
    case 0x0001: 
        printf( "sad ");
        break;
    case 0x0005:    
        printf( "angry ");
        break;
    case 0x0007:    
        printf( "elated ");
        break;
    case 0x000A:    
        printf( "confused ");
        break;
    case 0x000D:    
        printf( "groovy ");
        break;
    }
}

void decode_color (uint16_t messages)
{
    uint16_t color = messages;
    uint16_t n = color >> 8;
    uint16_t m = n & 0x0007;
    switch (m)
    {
    case 0x0001:
        printf( "red ");
        break;
    case 0x0003:
        printf( "blue ");
        break;
    case 0x0004:
        printf( "purple ");
        break;
    case 0x0006:
        printf( "gold ");
        break;
    case 0x0007:
        printf( "orange ");
        break;
    }
}

void decode_animal (uint16_t messages)
{
    uint16_t animal = messages;
    uint16_t n = animal >> 4;
    uint16_t m = n & 0x000F;
    switch (m)
    {
    case 0x0002:
        printf( "giraffe");
        break;
    case 0x0003:
        printf( "platypus");
        break;
    case 0x0006:
        printf( "lion");
        break;
    case 0x0007:
        printf( "chicken");
        break;
    case 0x000B:
        printf( "dog");
        break;
    case 0x000F:
        printf( "frog");
        break;
    }
}

int main ()
{
    uint16_t messages; //Add value for testing
    decode_moods(messages);
    decode_color(messages);
    decode_animal(messages);
    printf("\n");
    
    return 0;
}