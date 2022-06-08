#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define stringLenght 128

//simulate error in data transfer (change bit from 0 to 1 or opposite)
char* corrupte_message(const char* message, int number_bits)
{
	char* result = _strdup(message);

	for (int i = 0; i < number_bits; i++)
	{
		int randomByte = rand() % strlen(message);
		int randomBit = rand() % 8;

		result[randomByte] ^= 1 << randomBit; //xor operation 1->0 or 0->1
	}

	return result;
}

unsigned char checksum(const char* message, int messagelenght)
{
	unsigned char result = 0;

	for (int i = 0; i < messagelenght; i++)
	{
		result += message[i];
	}

	return result;
}


int main(void)
{
	srand((unsigned)time(NULL));
	char poruka[stringLenght];

	printf("Unesi poruku za poslati do %d znaka:", stringLenght);
	scanf("%s", poruka);

	printf("Poslano    : %s\t checksum:%x\n", poruka, checksum(poruka, strlen(poruka)));

	//fake error
	char* poruka2 = corrupte_message(poruka, 1);

	printf("Primljeno  : %s\t checksum:%x\n", poruka2, checksum(poruka2, strlen(poruka2)));

}

