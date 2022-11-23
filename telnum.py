name_list = []
tel_list = []

def print_title():
    print(" = " * 28)
    print(" = " * 8)
    print(" = " * 28)

def print_menu():
    print("1.연락처 추가")
    print("2.연락처 수정")
    print("3.연락처 출력")
    print("4.연락처 삭제")
    print("5. 종료")
    menu  = input("원하는 번호를 선택하세요.:")
    return int(menu)

def add_telnum():
    name_list.append(input("이름:"))
    tel_list.append(input("전화번호:"))

def update_telnum(name , tel):
    for i in range(0, len(name_list)):
        if name_list[i] == name:
            tel_list[i] = tel
            return True
    return False

def print_telnum():
    for i in range(0, len(name_list)):
        print("이름:", name_list)
        print("전화번호.:" , tel_list)

def delete_telnum(name):
    for i in range(0, len(name_list)):
        if name_list[i] == name:
            del(name_list)
            del(tel_list)
            return True
    return False

def print_end():
    print("=" * 28)


while True:
    print_title()
    menu = print_menu()
    if menu ==1:
        add_telnum()
        print_telnum()
    elif menu == 2:
        print_telnum()
        name = input("수정하고 싶은 이름을 입력하세요:")
        tel = input("전화번호:")
        if update_telnum(name, tel ) == True:
            print(name , "의 전화번호를 수정했습니다.")
        else:
            print(name , "는 존재하지 않습니다.")
        
    elif menu == 3:
        print_telnum()

    elif menu == 4:
        print_telnum()
        name = input("삭제하고 싶은 이름을 입력하세요:")
        if delete_telnum(name) == True:
            print(name, "을 삭제했습니다.")
        else:
            print(name , "은 없습니다.")
        print_telnum()

    elif menu == 5:
        print_end()
        break
