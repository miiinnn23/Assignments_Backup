import pickle, os

student = [] # 학생들의 정보를 담는 배열
data_index = ["ID", "Name", "Korean", "English", "Math"]

def print_menu():
    print('\n**********************************************************************')
    print('1. Retrieve')
    print('2. Input')
    print('3. Update')
    print('4. Delete')
    print('5. Save')
    print('6. Load')
    print('7. Quit')
    print('**********************************************************************')
    
def Retrieve():
    if(len(student) < 1):
        print("There is no data.")
    else:
        print("Index      ID         Name       Korean     English    Math")
        print("---------- ---------- ---------- ---------- ---------- ----------")
        for i in range(len(student)):
            print(i + 1, student[i][0], student[i][1], student[i][2], student[i][3], student[i][4], sep='\t')
            
        # student[i][0][:10] or
        # for i, element in student:
        # print(str(i + 1), element[0][:10], .....)
        
def Input():
    id = input("ID\t> ")
    name = input("Name\t> ")
    korean = int(input("Korean\t> "))
    while korean < 0 or korean > 100:
        print("Please enter a number between 0 to 100!!")
        korean = int(input("Korean\t> "))
        
    english = int(input("English\t> "))
    while english < 0 or english > 100:
        print("Please enter a number between 0 to 100!!")
        english = int(input("English\t> "))
    
    math = int(input("Math\t> "))
    while math < 0 or math > 100:
        print("Please enter a number between 0 to 100!!")
        math = int(input("Math\t> "))
    
    return id, name, korean, english, math
    
def Update():
    Retrieve()
    if len(student) < 1: # data가 없을 경우 return
        return
    
    idx = int(input("\n> "))
    while idx <= 0 or idx > len(student):
        print("Please enter a number between 1 to ", len(student), "!!", sep='')
        idx = int(input("> "))
   
    student[idx - 1] = Input()
    print('\nUpdated.\n')
    Retrieve()

def Delete():
    Retrieve()
    if len(student) < 1: # data가 없을 경우 return
        return
    
    idx = int(input("\n> "))
    while idx <= 0 or idx > len(student):
        print("Please enter a number between 1 to ", len(student), "!!", sep='')
        idx = int(input("> "))
        
    print('\n')
    for i in range(len(data_index)):
        print(data_index[i], "\t: ", student[idx - 1][i], sep='')

    student.pop(idx - 1)
    
    print('Deleted.\n')
    Retrieve()
    
def Save():
    file = open('pickle.dat', 'wb')
    pickle.dump(student, file)
    file.close()
    
def Load():
    try:
        file = open('pickle.dat', 'rb')
        student.extend(pickle.load(file))
        file.close()
        
        print(student)
    except:
        pass

while True:
    print_menu()
    try:
        num = int(input('> '))
        
        print()
        if num == 7:
            print('Bye!!')
            break
        
        elif num == 1:
            Retrieve()
            
        elif num == 2:
            data = Input()
            student.append(data)
            
        elif num == 3:
            Update()
            
        elif num == 4:
            Delete()
        
        elif num == 5:
            Save()
            
        elif num == 6:
            Load()
        
        else:
            pass
    except:
        pass