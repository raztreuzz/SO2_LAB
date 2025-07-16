#include <stdio.h>

int main(){

    int num = 0x12345678;
    unsigned char *bytePtr = (unsigned char *)&num;
    printf("Original number: 0x%08X\n", num);
    printf("Byte order:\n");
    for (int i = 0; i < sizeof(num); i++) {
        printf("Byte %d: 0x%02X\n", i, bytePtr
[i]);   
    }

    // Check endianness
    if (bytePtr[0] == 0x78) {
        printf("System is Little Endian\n");
    } else {
        printf("System is Big Endian\n");
    }

    return 0;

}