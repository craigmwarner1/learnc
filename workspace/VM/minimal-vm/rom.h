uint16_t ROM[] = {
        0x000a, /* @10       => 0000000000001010 */
        0xec10, /* D=A       => 1110110000010000 */
        0x0003, /* @3        => 0000000000000011 */
        0xe090, /* D=D+A     => 1110000010010000 */
        0xe320, /* A=D       => 1110001100100000 */
        0xee40, /* ON        => 1110111001000000 */
        0x01f4, /* @500      => 0000000111110100 */
        0xee80, /* DELAY     => 1110111010000000 */
        0x000d, /* @13       => 0000000000001101 */
        0xee00, /* OFF       => 1110111000000000 */
        0x01f4, /* @500      => 0000000111110100 */
        0xee80, /* DELAY     => 1110111010000000 */
        0x0000, /* @forever  => 0000000000000000 */
        0xea87, /* 0;JMP     => 1110101010000111 */
        0x0000  /*              END OF LINE      */
};
#define ROMSIZE 15