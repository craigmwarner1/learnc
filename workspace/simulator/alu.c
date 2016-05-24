 /* EALU starter file for CSC 335 Midterm Checkup.
 * CC0 2014 by Matt Jadud
 * Compile with:
 *   gcc -o ealu ealu.c
 * and execute then with
 *   ./ealu
 */
 
#include <stdint.h>
#include <stdio.h>
 
#define ERROR 0xFFFF
 
uint16_t alu (uint16_t x, uint16_t y, uint8_t instr) {
  
   
    switch (instr)
    {
    class 0x80:
      return x > y;
      break;
    case 0x40:
      return x < y;
      break;
    case 0x2A:
        return 0;
        break;
    case 0x0D:
        return x;
        break;
        case 
    case 0x1F:
        return x + 1;
        break;
    default:
        return ERROR;
        break;
        
       
}
 
int main () {
  
  uint16_t x, y;
  uint8_t instr;
  int error = 0;
  
  /* Some simple tests. */
  printf ("Tests for the EALU\n");
  printf ("------------------\n");
  
  if (!(alu(0x0042, 0xBEEF, 0x2A) == 0)) {
    printf ("The EALU should return 0 in this case.\n");
    error += 1;
  }
  
  if (!(alu(0x02, 0x02, 0x1F) == 0x03)) {
    printf ("The EALU should return x+1, which is 2+1, or 3, in this case.\n");
    error += 1;
  }
  
  /* You should write additional tests.
   * Your tests should only be noisy in the case of failure.
   */
  if (!(alu(0x000F, 0xFABB, 0x0D) == 0x000F)) {
    printf ("The EALU should return x, which is 15 in this case.\n");      error += 1;
   }
   
  if (!(alu(0X00FF, 0x000F, 0x80) == true)) {
    printf("The EALU should return true, as x > y.\n")
   }
   
  if (!(alu(0x000F, 0x00FF, 0x40) == true)) {
    printf("The EALU should return true, as x < y.\n")
  }
  
  /* The following code should not need modification. It prints
   * the results of your tests. 
   */
  if (error > 0) {
    printf ("The EALU failed to pass %d test", error);
    
    /* Proper plurality agreement is so difficult when writing code... 
     * Good Grammar Or Bust! *cough*
     */
     
    if (error > 1) {
      printf ("s.\n");
    } else {
      printf (".\n");
    }
  } else {
    printf ("All tests passed!\n");
  }
  
  /* We can return anything here, so I choose to return the meaning of life,
   * the universe, and everything, as defined by Douglas Adams. 
   * Zero, of course, is traditional, and suggests everything worked OK.
   */
  return 0;
}