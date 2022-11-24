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

int check_Alphabet_Num(const char* str, int length) {
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
	int temp = 0;
	int temp2 = 0;
	for (int i = 0, p =0 ; p <13, i < length ; p++ , i++) {
		temp = str[i];
		if (48 <= temp && temp <= 57) {
			if (temp <= 55) {
				temp2 = temp + 2;
			}
			else {
				temp2 = temp - 8;
			}
			newStr[p] = temp2;
		}
		else if (97 <= temp && temp <= 122) {
			for (int k = 97, o = 0; k < 123, o < 26 ; k++, o++) {
				if (temp == k) {
					temp2 = encodingTable[o];
					newStr[p] = temp2;
				}
			}
		}
		else {
			temp = newStr[p];
		}
	}
	return newStr;
}

void decode(const char* str, int length, const char* encodingTable, char* newStr) {
	int temp;
	int temp2;
	char* encoding1 = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0, p = 0; i < length, p < 13; i++, p++) {
		temp = str[i];
		if (48 <= temp && temp <= 57) {
			if (temp <= 55) {
				temp2 = temp - 2;
			}
			else {
				temp2 = temp + 8;
			}
			newStr[p] = temp2;
		}
		else if (97 <= temp && temp <= 122) {
			for (int k = 0, o = 0; k < 13, o < 26; k++, o++) {
				if (temp == encodingTable[k]) {
					temp2 = encoding1[o];
					newStr[p] = temp2;
				}
			}
		}
		else {
			temp = newStr[p];
		}

	}
	return newStr;
}

int main(void) {
	int length;
	const char* str[13];
	char* encodingTable = "wyhfxumtjvsgenbrdzlqapcoki";
	char* newStr = str;

	while (1) {
		printf("패스워드를 입력하세요(숫자와 알파벳을 혼합하여 8-12자):");
		fgets(str, sizeof(str), stdin);
		length = print_length(str);

		if (checkCondition(str, length) == 1) {
			if (check_Alphabet_Num(str, length) == 1) {
				encode(str, length, encodingTable , newStr);
				printf("입력하신 패스워드가 %s로 암호화 되었습니다.\n" ,newStr );
				decode(str, length, encodingTable, newStr);
				printf("이를 다시 복호화한 결과 패스워드는 %s입니다.\n", str);
				break;
			}
			else if (check_Alphabet_Num(str, length) == 0) {
				printf("숫자와 알파벳을 혼합해 주세요.\n");
			}

		}
		else {
			printf("범위 내의 문자 수로 다시 입력하세요:\n");
		}
	}
}