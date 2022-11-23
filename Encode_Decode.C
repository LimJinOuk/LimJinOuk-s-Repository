#include<stdio.h>
#include<string.h>


int print_length(const char* str) {
	int temp;
	temp = strlen(str);
}

int checkCondition(const char* str, int length) {
	if (length >= 9 && length <= 13) {
		return 1;
	}
	else {
		return 0;
	}
}

int check_Alphabet_Num(const char * str , int length) {
	int checkdigit = 0;
	int checkalpha = 0;
	
	for (int i = 0; i < length; i++) {
		if (48 <= str[i] && str[i] <= 57) {
			checkdigit = 3;
		}

		if (97 <= str[i] && str[i] <= 122) {
			checkalpha = 1;
		}

		if (65 <= str[i] && str[i] <= 90) {
			checkalpha = 1;
		}
	}
	int result = checkalpha + checkdigit;
	if (result > 3) {
		return 1;
	}
	else {
		return 0;
	}
}

void encode(const char* str, int length, const char* encodingTable, char* newStr) {

}

void decode(const char* str, int length, const char* encodingTable, char* newStr) {

}

int main(void) {
	int length;
	const char* str[13];
	char* encodingTable = "wyhfxumtjvsgenbrdzlqapcoki";
	char* newStr;

	while (1) {
		printf("패스워드를 입력하세요(숫자와 알파벳을 혼합하여 8-12자):");
		fgets(str, sizeof(str), stdin);
		length = print_length(str);
		
		if (checkCondition(str, length) == 1) {
			if (check_Alphabet_Num(str , length) == 1) {
				printf("입력하신 패스워드가 로 암호화 되었습니다.\n");
				break;
			}
			else if (check_Alphabet_Num(str , length) == 0) {
				printf("숫자와 알파벳을 혼합해 주세요.\n");
			}
			
		}
		else {
			printf("범위 내의 문자 수로 다시 입력하세요:\n");
		}
	}
}
