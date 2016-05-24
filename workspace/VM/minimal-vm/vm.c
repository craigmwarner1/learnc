#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <inttypes.h>
#include "vm.h"
#include "rom.h"
#include "bitstuff.c"
/*Brandon Calhoun & Craig Warner*/
/* Global Variables */
uint16_t RAM[RAMSIZE], Areg, Dreg, loop;

/* initialize_vm()
 * Zeros all storage locations.
 */
int initialize_vm () {
  /* Set the program counter, A, and D registers to zero. */
  Areg = 0;
  Dreg = 0;
  loop = 0;
  /* Zero out RAM. */
  for (int i = 0 ; i < RAMSIZE ; i++) {
    RAM[i] = 0;
  }
  
  /* Return non-zero in case of error. */
  return 0;
}

/* print_vm()
 * This is a handy debugging tool. It prints the A and D registers,
 * as well as the PC, and RAM. Your variable names may need to change.
 *
*/
/*
void print_vm () {
  printf("\n");
  printf(  "A          %04x ", A);
  p(sizeof(uint16_t), &A);
  printf(  "D          %04x ", D);
  p(sizeof(uint16_t), &D);
  printf(  "iptr       %04x ", pc);
  p(sizeof(uint16_t), &iptr);
  
  for (int ndx = 0; ndx < RAMSIZE; ndx++) {
    printf("RAM [%04X] %04x ", ndx, RAM[ndx]);
    p(sizeof(uint16_t), &RAM[ndx]);
  }
}
*/


int runloop () {
  /* You might keep track of what the program counter is.
   * If it is greater than the constant ROMSIZE, then you 
   * should probably stop looping.
   */
  
  
  int destination;
  while (loop <= ROMSIZE)
  {
   uint16_t instr = ROM[loop];
   uint16_t ayayay = iBit(instr);
   
   if ( ayayay == 0){
     Areg = instr & 0x7FFF;
     loop++;
   }
   else{
     uint16_t RM = RAM[Areg];
     uint16_t aluOutput = ALU(instr, Dreg, Areg, RM);
     //printf("%" PRIu16 "\n", aluOutput);
     destination = dest(instr);
     switch (destination)
     {
      case 2:
        RAM[Areg] = aluOutput;
        break;
      case 3:
        Dreg = aluOutput;
        //printf("%" PRIu16 "\n",Dreg);
        break;
      case 4:
        Dreg = aluOutput;
        RAM[Areg] = aluOutput;
        break;
      case 5:
        Areg = aluOutput;
        break;
      case 6:
        Areg = aluOutput;
        RAM[Areg] = aluOutput;
        break;
      case 7:
        Areg = aluOutput;
        Dreg = aluOutput;
        break;
      case 8:
        Areg = aluOutput;
        Dreg = aluOutput;
        RAM[Areg] = aluOutput;
        break;
      default:
        printf("Nope.");
        break;
     }
     uint16_t jumpinstr = instr & 0x7;
    if (jumpinstr == 0){
      loop = loop + 1;
    }
    else {
      uint16_t RM = RAM[Areg];
      uint16_t aluOutput = ALU(instr, Dreg, Areg, RM);
      loop = jmp(instr, aluOutput, loop);
      
    }
     
   }
   
    
    printf("Areg %" PRIu16 "\n",Areg);
    printf("Dreg %" PRIu16 "\n",Dreg);
   sleep(1);
  }
  return 0;
}

int main (int argv, char *args[]) {
  initialize_vm ();
  // print_vm ();
  
  runloop();

  return 0;
}