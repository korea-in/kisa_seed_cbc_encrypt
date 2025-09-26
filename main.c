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
	
	printf ("##### 테스트 정보 ######");
	printf("\n평문(문자열): %s", plainText);
	printf("\n암호키(문자열): ");
	for (i=0;i<16;i++) printf("%c",pbszUserKey[i]);
	
	printf("\n\n평문(16진수): ");
	for (i=0;i<strlen(plainText);i++) printf("%02X ",plainText[i]);
	printf("\n암호키(16진수): ");
	for (i=0;i<16;i++) printf("%02X ",pbszUserKey[i]);
	

	printf ("\n\n##### 초기화 벡터 생성(난수) ######");
	for(int i=0; i<16; i++) pbszIV[i] = rand() % 0xff;
	printf ("\n초기화 벡터(문자열): ");
	for (i=0;i<16;i++) printf("%c",pbszIV[i]);
	
	printf("\n초기화 벡터 16진수(문자열): ");
	for(int i=0; i<16; i++) printf("%02X", pbszIV[i]);
	printf("\n초기화 벡터 16진수(배열): {");
	for(int i=0; i<16; i++) {
		printf("0x%02X", pbszIV[i]);
		if(i!=16-1) printf(", ");
	}
	printf("}");
	
	printf ("\n\n##### 암호화 시작 ######");
	nCipherTextLen = SEED_CBC_Encrypt( pbszUserKey, pbszIV, plainText, strlen(plainText), pbszCipherText );
	printf("\n암호문 길이: %d", nCipherTextLen);
	printf("\n암호문(문자열): %s", pbszCipherText);
	printf("\n암호문 16진수(문자열): ");
	for(int i=0; i<nCipherTextLen; i++) printf("%02X", pbszCipherText[i]);
	printf("\n암호문 16진수(배열): {");
	for(int i=0; i<nCipherTextLen; i++) {
		printf("0x%02X", pbszCipherText[i]);
		if(i!=nCipherTextLen-1) printf(", ");
	}
	printf("}");

	printf ("\n\n##### 복호화 시작 ######");
	nPlainTextLen = SEED_CBC_Decrypt( pbszUserKey, pbszIV, pbszCipherText, nCipherTextLen, pbszPlainText );
	printf("\n복호화 길이: %d", nPlainTextLen);
	printf("\n복호화 문자열: %s", pbszPlainText);

	printf ("\n");
}