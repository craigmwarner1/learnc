#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>



uint16_t  iBit(uint16_t instr)
{
    uint16_t shift = instr;
    uint16_t post = shift >> 15;
    uint16_t i = post & 0x1;
    return i;
}
uint16_t aBit (uint16_t instr)
{
    uint16_t shift = instr;
    uint16_t post = shift >> 12;
    uint16_t a = post & 0x1;
    return a;
}

int dest (uint16_t instr)
{
    uint16_t destInst = instr >> 3;
    uint16_t dinst = destInst & 0x7;
    //uint16_t destArray[3] = {0,0,0};
    switch (dinst)
    {
    case 0x0:
        return 1;
        break;
    case 0x1:
        //destArray = {0,0,1};
        return 2;
        break;
    case 0x2:
        //destArray = {0,1,0};
        return 3;
        break;
    case 0x3:
       // destArray = {0,1,1};
        return 4;
        break;
    case 0x4:
        //destArray = {1,0,0};
        return 5;
        break;
    case 0x5:
        //destArray = {1,0,1};
        return 6;
        break;
    case 0x6:
        //destArray = {1,1,0};
        return 7;
        break;
    case 0x7:
        //destArray = {1,1,1};
        return 8;
        break;
    default:
        printf("DESTINATION ERROR");
        break;
    }
    
}

char jmp (uint16_t instr, uint16_t aluOutput, uint16_t loop)
{
    uint16_t jumpinstr = instr & 0x7;
    
    switch (jumpinstr)
    {
        case 0x1:
            if (aluOutput > 0){
                loop = aluOutput;
                return loop;
            }
            break;
        case 0x2:
            if (aluOutput == 0){
                loop = aluOutput;
                return loop;
            }
            break;
        case 0x3:
            if (aluOutput >= 0){
                loop = aluOutput;
                return loop;
            }
            break;
        case 0x4:
            if (aluOutput < 0){
                loop = aluOutput;
                return loop;
            }
            break;
        case 0x5:
            if (aluOutput != 0){
                loop = aluOutput;
                return loop;
            }
            break;
        case 0x6:
            if (aluOutput <= 0){
                loop = aluOutput;
                return loop;
            }
            break;
        case 0x7:
            loop = aluOutput;
            return loop;
            break;
        default:
            return 0;
            break;
    }
    
}

 uint16_t ALU (uint16_t instr, uint16_t Dreg, uint16_t Areg, uint16_t RAM)
{
    uint16_t a = aBit(instr);
    
     
    uint16_t command = instr;
    uint16_t n = command >> 6;  
    uint16_t m = n & 0x3F;
    uint16_t RM = RAM;
    
    switch (m)
    {
    case 0x2A:   
        if (a==0x0) {return 0;}
        break;
    case 0x3F: 
        if (a==0x0) {return 1;}
        break;
    case 0x3A:    
        if (a==0x0) {return - 1;}
        break;
    case 0xC:    
        if (a==0x0) {return Dreg;}
        break;
    case 0x30:
        
        if (a==0x0) {return Areg;}
        else {return RM;}
        break;
    case 0xD:    
        if (a==0x0) {return !Dreg;}
        break;
    case 0x31:
        if (a==0x0) {return !Areg;}
        else {return !RM;}
        break;
    case 0xF:
        if (a==0x0) {return !Dreg;}
        break;
    case 0x33:
        if (a==0x0) {return -Areg;}
        else {return -RM;}
        break;
    case 0x1F:
        if (a==0x0) {return Dreg + 1;}
        break;
    case 0x37:
        if (a==0x0) {return Areg + 1;}
        else {return RM + 1;}
        break;
    case 0xE:
        if (a==0x0) {return Dreg-1;}
        break;
    case 0x32:
        if (a==0x0) {return Areg - 1;}
        else {return RM - 1;}
        break;
    case 0x2:
        if (a==0x0) {return Dreg + Areg;}
        else {return Dreg + RM;}
        break;
    case 0x13:
        if (a==0x0) {return Dreg-Areg;}
        else {return Dreg-RM;}
        break;
    case 0x7:
        if (a==0x0) {return Areg-Dreg;}
        else {return RM-Dreg;}
        break;
    case 0x0:
        if (a==0x0) {return Dreg&Areg;}
        else {return Dreg&RM;}
        break;
    case 0x15:
        if (a==0x0) {return Dreg||Areg;}
        else {return Dreg||RM;}
        break;
    /*case 0x39:
        digitalWrite(Areg, HIGH);
        break;
    case 0x38:
        digitalWrite(Areg, LOW);
    case 0x40:
        delay(Areg);*/
        
    default:
        printf("ALU INSTRUCTION ERROR");
        return 42;
        break;
    }
}