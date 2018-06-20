/*
Name: Harlan Chang
Description: Program asks the user for an input file, output file, and whether they want to encode it or decode it. It will take whatever is in the input file and either encode or decode it into the output file. 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char encoding(char a);
char decoding(char a);

int main()
{
	FILE * inputFile, * outputFile;
	char fileInput[50];
	char fileOutput[50];
	int option;
	char encoded;

	printf("Please enter the input file name: ");
	scanf("%s", fileInput);
	inputFile = fopen(fileInput, "r");
	
	if (inputFile == NULL)
	{
		printf("That file does not exist!\n");
		exit(1);
	}
	
	printf("Please enter the output file name: ");
	scanf("%s", fileOutput);
	outputFile = fopen(fileOutput, "w");
	
	printf("Enter 1 for encoding or 2 for decoding: ");
	scanf("%d", &option);
	
	if (option == 1)
	{
		while(!feof(inputFile))
		{
			encoded = encoding(fgetc(inputFile));
			fprintf(outputFile, "%c", encoded);
		}
	}
	else if (option == 2)
	{
		while(!feof(inputFile))
		{
			encoded = decoding(fgetc(inputFile));
			fprintf(outputFile, "%c", encoded);
		}
	}
	
	fclose(inputFile);
	fclose(outputFile);
	printf("The file has been encoded.");
	
	return 0;
}

char encoding(char a)
{
	int i;
	char letters[] = "abcdefghijklmnopqrstuvwxyz";
	char caps[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char enc[] = "kngcadsxbvfhjtiumylzqropwe";
	char encCaps[] = "KNGCADSXBVFHJTIUMYLZQROPWE";
	
	for(i = 0; i <= 25; i++)
	{
		if(a == letters[i])
		{
			return enc[i];
		}
		else if(a == caps[i])
		{
			return encCaps[i];
		}
	}
	
	return a;
}

char decoding(char a)
{
	int i;
	char letters[] = "abcdefghijklmnopqrstuvwxyz";
	char caps[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char enc[] = "kngcadsxbvfhjtiumylzqropwe";
	char encCaps[] = "KNGCADSXBVFHJTIUMYLZQROPWE";
	
	for(i = 0; i <= 25; i++)
	{
		if(a == enc[i])
		{
			return letters[i];
		}
		else if(a == encCaps[i])
		{
			return caps[i];
		}
	}
	
	return a;
}