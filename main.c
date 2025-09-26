#include "KISA_SEED_CBC.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <time.h>

void main()
{
	srand(time(NULL));
	BYTE pbszUserKey[16] = "qwertasdfghjriao"; 
	BYTE pbszIV[16] = {0x00};
	BYTE plainText[2048] = "Encrypt Test Message";
	BYTE pbszCipherText[2048] = {0x00};
	BYTE pbszPlainText[2048] = {0x00};
	int i;
	int nPlainTextLen;
	int nCipherTextLen;
	
	printf ("##### �׽�Ʈ ���� ######");
	printf("\n��(���ڿ�): %s", plainText);
	printf("\n��ȣŰ(���ڿ�): ");
	for (i=0;i<16;i++) printf("%c",pbszUserKey[i]);
	
	printf("\n\n��(16����): ");
	for (i=0;i<strlen(plainText);i++) printf("%02X ",plainText[i]);
	printf("\n��ȣŰ(16����): ");
	for (i=0;i<16;i++) printf("%02X ",pbszUserKey[i]);
	

	printf ("\n\n##### �ʱ�ȭ ���� ����(����) ######");
	for(int i=0; i<16; i++) pbszIV[i] = rand() % 0xff;
	printf ("\n�ʱ�ȭ ����(���ڿ�): ");
	for (i=0;i<16;i++) printf("%c",pbszIV[i]);
	
	printf("\n�ʱ�ȭ ���� 16����(���ڿ�): ");
	for(int i=0; i<16; i++) printf("%02X", pbszIV[i]);
	printf("\n�ʱ�ȭ ���� 16����(�迭): {");
	for(int i=0; i<16; i++) {
		printf("0x%02X", pbszIV[i]);
		if(i!=16-1) printf(", ");
	}
	printf("}");
	
	printf ("\n\n##### ��ȣȭ ���� ######");
	nCipherTextLen = SEED_CBC_Encrypt( pbszUserKey, pbszIV, plainText, strlen(plainText), pbszCipherText );
	printf("\n��ȣ�� ����: %d", nCipherTextLen);
	printf("\n��ȣ��(���ڿ�): %s", pbszCipherText);
	printf("\n��ȣ�� 16����(���ڿ�): ");
	for(int i=0; i<nCipherTextLen; i++) printf("%02X", pbszCipherText[i]);
	printf("\n��ȣ�� 16����(�迭): {");
	for(int i=0; i<nCipherTextLen; i++) {
		printf("0x%02X", pbszCipherText[i]);
		if(i!=nCipherTextLen-1) printf(", ");
	}
	printf("}");

	printf ("\n\n##### ��ȣȭ ���� ######");
	nPlainTextLen = SEED_CBC_Decrypt( pbszUserKey, pbszIV, pbszCipherText, nCipherTextLen, pbszPlainText );
	printf("\n��ȣȭ ����: %d", nPlainTextLen);
	printf("\n��ȣȭ ���ڿ�: %s", pbszPlainText);

	printf ("\n");
}