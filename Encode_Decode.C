#include<stdio.h>
#include<string.h>

const char* str;
int length;
char entered_PW[13];
char encrypted_PW;
char Decrypted_PW;
const char* encodingTable = "wyhfxumtjvsgenbrdzlqapcoki";
char* newStr;

int checkCondiotion(const char* str, int length) {
	if (length >= 8 && length <= 12) {
		return 0;
	}
	else {
		return 1;
	}
}

void encode(const char* str, int length, const char* encodiongTable, char* newStr) {

}

void decode(const char* str, int length, const char* encodiongTable, char* newStr) {

}

int main(void) {
	int length = strlen(entered_PW);
	while (1) {
		printf("�н����带 �Է��ϼ���(���ڿ� ���ĺ��� ȥ���Ͽ� 8-12��):");
		fgets(entered_PW, sizeof(entered_PW), stdin);
		if (checkCondiotion(str, length) == 1) {
			printf("%s\n", entered_PW);
			printf("%d\n", length);
			printf("���� ���� ���� ���� �ٽ� �Է��ϼ���.:\n");
		}
		else {
			break;
		}
	}
	return 0;
}