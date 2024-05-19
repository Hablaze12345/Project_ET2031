#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define MAX_LINE_LENGTH 1000
struct user {
    char fname[20];
    char lname[20];
    char sex[20];
    char id[20];
    char email[30];
    char phone[20];
    char username[30];
    char password[30];

};

void signup() {
    struct user us;
    FILE *fp;
    fp = fopen("C:\\Users\\Nguyen Ha\\OneDrive - Hanoi University of Science and Technology\\Project ET2031\\library_management_system\\userdata.txt", "a");
    // Inputs
    system("CLS");
    printf("\n\nCREATE ACCOUNT!!!!");
    printf("\nFirst Name: ");
    scanf("%s", &us.fname);
    printf("\nLast Name: ");
    scanf("%s", &us.lname);
    printf("\nId: ");
    scanf("%s", &us.id);
    printf("\nSex: ");
    scanf("%s", &us.sex);
    printf("\nPhone Number: ");
    scanf("%s", &us.phone);
    printf("\nEmail: ");
    scanf("%s", &us.email);
    printf("Thank you\nNow, Let's create your own Username and Password for your account!!!");
    printf("\nUsername: ");
    scanf("%s", &us.username);
    printf("\nPassword: ");
    scanf("%s", &us.password);
    if(fp== NULL) {
        fprintf(stderr, "\t\t\tCan't open file\n");
    }else {
        printf("\t\t\tRecord stored successfully\n");
    }
    fwrite(&us, sizeof(us),1, fp);
    fclose(fp);
    printf("Signup Successfull!\n");
    printf("Press Enter to continue: ");
    getch();
}
void signin() {
    struct user us;
    char username[50];
    char password[50];
    FILE *fp;

    // M? file c?n dùng
    fp = fopen("C:\\Users\\Nguyen Ha\\OneDrive - Hanoi University of Science and Technology\\Project ET2031\\library_management_system\\userdata.txt", "r");
    if (fp == NULL) {
        fputs("Error in opening file\n", stderr);
        exit(1); // Thoát hàm khi file không du?c m?
    }

    int loginSuccess = 0; // Ðánh d?u dang nh?p thành công

    while (!loginSuccess) {
        printf("ACCOUNT LOGIN\n");
        printf("USERNAME: ");
        scanf("%s", username);
        printf("PASSWORD: ");
        scanf("%s", password);

        system("CLS");

        // Ki?m tra username và password
        while (fread(&us, sizeof(struct user), 1, fp)) {
            if (strcmp(username, us.username) == 0 && strcmp(password, us.password) == 0) {
                printf("Login Successful\n");
                loginSuccess = 1; // Ðánh d?u dang nh?p thành công
                break; // Thoát vòng l?p bên trong
            }
        }

        if (!loginSuccess) {
            printf("Invalid username or password. Please try again.\n");
        }

        // Quay l?i d?u file cho vòng l?p m?i
        rewind(fp);
    }

    fclose(fp);
}

void update_user() {
    struct user us;
    FILE *fp;
    fp = fopen("C:\\Users\\Nguyen Ha\\OneDrive - Hanoi University of Science and Technology\\Project ET2031\\library_management_system\\userdata.txt", "r+");
    // Inputs
    system("CLS");
    printf("\n\nUPDATE ACCOUNT!!!!");
    char id1[20];
    printf("\nEnter your ID: ");
    scanf("%s", &id1);
    while (fread(&us, sizeof(us), 1, fp) == 1) {
        if (strcmp(us.id, id1) == 0) {
            printf("\nNew Phone Number: ");
            scanf("%s", &us.phone);
            printf("\nNew Email: ");
            scanf("%s", &us.email);
            printf("\nNew Username: ");
            scanf("%s", &us.username);
            printf("\nNew Password: ");
            scanf("%s", &us.password);
            fseek(fp, -sizeof(us), SEEK_CUR);
            fwrite(&us, sizeof(us), 1, fp);
            printf("\t\t\tRecord updated successfully\n");
            break;
        }
    }
    fclose(fp);
    printf("Update Successfull!\n");
    printf("Press Enter to continue: ");
    getch();
}
void userrecord(){
    FILE *fp;
    struct user us;
    fp = fopen("C:\\Users\\Nguyen Ha\\OneDrive - Hanoi University of Science and Technology\\Project ET2031\\library_management_system\\userdata.txt", "r");
    printf("\t\t\t\t=====User Record=====\n\n");
    if (fp == NULL) {
        fprintf(stderr, "\t\t\tCan't open");
    }else {
        printf("\t\t\tRecords\n");
        printf("\t\t\t\t___________________\n");
    }
    while(fread(&us, sizeof(us),1,fp)){
        printf("\n\t\t\tName: %s %s", us.lname, us.fname);
        printf("\n\t\t\tId: %s", us.id);
        printf("\n\t\t\tUsername: %s", us.username);
        printf("\n\t\t\tPassword: %s",us.password);
        printf("\n\t\t\t\t______________________");
    }
    fclose(fp);
    printf("\nEnter an username to see more info:");
    printf("\nPress Enter to continue...");
    getch();

}
void display() {
    struct user us;
    char username[50];
    char password[50];
    FILE *fp;

    // Open the user data file
    fp = fopen("C:\\Users\\Nguyen Ha\\OneDrive - Hanoi University of Science and Technology\\Project ET2031\\library_management_system\\userdata.txt", "r");
    if (fp == NULL) {
        fputs("Error in opening file\n", stderr);
        exit(1); // Thoát hàm khi không d?c du?c file
    }

    int loginSuccess = 0; //  Ðánh d?u khi di?n dúng

    while (!loginSuccess) {
        printf("Enter your username:\n");
        printf("USERNAME: ");
        scanf("%s", username);

        system("CLS");

        // Ki?m tra username có dúng không.
        while (fread(&us, sizeof(struct user), 1, fp)) {
            if (strcmp(username, us.username) == 0) {
                printf("...............................\n");
                printf("=====ACCOUNT INFORMATION=====\n");
                printf("******************************\n");
                printf("Welcome to Library Management System (*-*)\n");
                printf("Hello, Hope you have a good day!!\n");
                printf("This is %s account:\n ", us.username);
                printf("First name: %s\n", us.fname);
                printf("Last name: %s\n", us.lname);
                printf("Sex: %s\n", us.sex);
                printf("Id: %s\n", us.id);
                printf("Email: %s\n", us.email);
                printf("Phone number: %s\n", us.phone);
                printf("Username: %s\n", us.username);
                printf("Password: %s", us.password);
                loginSuccess = 1; // Ðánh d?u khi di?n dúng
                fclose(fp);
                break; // Thoát vòng l?p
            }
        }

        if (!loginSuccess) {
            printf("Invalid username. Please try again.\n");
        }

        // Quay l?i d?u file cho vòng l?p ti?p theo
        rewind(fp);
    }

    fclose(fp);
}
void delete_user(){
    FILE *fp, *fp1;
    struct user us;
    char username[30];
    int found = 0;

    printf("\t\t\t\t======User Record======\n\n\n");
    fp = fopen("C:\\Users\\Nguyen Ha\\OneDrive - Hanoi University of Science and Technology\\Project ET2031\\library_management_system\\userdata.txt","r");
    fp1 = fopen("temp.txt","w");

    if (fp == NULL || fp1 == NULL) {
        fprintf(stderr, "\t\t\tCan't open file\n");
        exit(1);
    }
    printf("\t\tEnter username: ");
    scanf("%s", username);
    
    while (fread(&us, sizeof(struct user),1,fp)){
        if(strcmp(us.username,username)==0){
            found = 1;
        }else {
            fwrite(&us, sizeof(struct user),1,fp1);
        }
    }
    fclose(fp);
    fclose(fp1);

    if(found) {
        remove("C:\\Users\\Nguyen Ha\\OneDrive - Hanoi University of Science and Technology\\Project ET2031\\library_management_system\\userdata.txt");
        rename("temp.txt", "userdata.txt");
        printf("\n\t\t\tRecord deleted successfully\n");
    }
    if (!found){
        printf("\n\t\t\tRecord not found\n");
    }
    getch();
}
void displayBookInfo(const char *bookInfo) {
    printf("%s\n", bookInfo);
}
void addBook() {
    char newBookInfo[MAX_LINE_LENGTH];
    printf("Enter book information (STT, Title, Author, Genre, Origin, Publisher, Pages, Volume, Price, Quantity): ");
    fgets(newBookInfo, sizeof(newBookInfo), stdin);

    // Them dong moi vao file CSV
    FILE *file = fopen("C:\\Users\\Nguyen Ha\\OneDrive\\Project ET2031\\Books_Data_C_Cpp.csv", "a");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }
    fprintf(file, "%s", newBookInfo);
    fclose(file);
}
void editBook() {
    int lineNumber;
    printf("Enter the line number of the book you want to edit: ");
    scanf("%d", &lineNumber);
    getchar(); // Doc ky tu new line tu bo dem stdin

    // Hien thi thong tin sach hien tai tai dong lineNumber
    FILE *file = fopen("C:\\Users\\Nguyen Ha\\OneDrive\\Project ET2031\\Books_Data_C_Cpp.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int count = 0;
    while (fgets(line, sizeof(line), file)) {
        count++;
        if (count == lineNumber) {
            displayBookInfo(line);
            break;
        }
    }
    fclose(file);

    // Nhap thong tin moi va ghi vao file
    char newBookInfo[MAX_LINE_LENGTH];
    printf("Enter new book information (STT, Title, Author, Genre, Origin, Publisher, Pages, Volume, Price, Quantity): ");
    fgets(newBookInfo, sizeof(newBookInfo), stdin);

    // Sua thong tin sach trong file CSV
    file = fopen("C:\\Users\\Nguyen Ha\\OneDrive\\Project ET2031\\Books_Data_C_Cpp.csv", "r+");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    count = 0;
    long int offset = 0;
    while (fgets(line, sizeof(line), file)) {
        count++;
        if (count == lineNumber) {
            fseek(file, offset, SEEK_SET);
            fprintf(file, "%s", newBookInfo);
            break;
        }
        offset = ftell(file);
    }
    fclose(file);
}
void deleteBook() {
    int lineNumber;
    printf("Enter the line number of the book you want to delete: ");
    scanf("%d", &lineNumber);
    getchar(); // Doc ky tu new line tu bo dem stdin

    // Xoa thong tin sach tu file CSV
    FILE *file = fopen("C:\\Users\\Nguyen Ha\\OneDrive\\Project ET2031\\Books_Data_C_Cpp.csv", "r");
    FILE *tempFile = fopen("temp.csv", "w");
    if (file == NULL || tempFile == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int count = 0;
    while (fgets(line, sizeof(line), file)) {
        count++;
        if (count != lineNumber) {
            fprintf(tempFile, "%s", line);
    	}
	}
	fclose(file) ;
	fclose(tempFile) ;
	remove("C:\\Users\\Nguyen Ha\\OneDrive\\Project ET2031\\Books_Data_C_Cpp.csv") ;
	rename("temp.csv","C:\\Users\\Nguyen Ha\\OneDrive\\Project ET2031\\Books_Data_C_Cpp.csv") ;
}
void librarianMenu() {
	int choice;
	while(1) {
		printf("Librarian Menu :\n") ;
		printf("Enter '1': Personal Information\n ");
	    printf("Enter '2': Update Personal Information\n ");
	    printf("Enter '3': User Account\n ");
	    printf("Enter '4': Delete User Account\n");
		printf("Enter '5': Add Book\n") ;
		printf("Enter '6': Edit Book\n") ;
		printf("Enter '7': Delete Book\n") ;
		printf("Enter '8': Exit the program\n") ;
		printf("Enter your choice : ") ;
		scanf("%d",&choice) ;
		getchar() ;
		switch (choice) {
			case 1 :
				display() ;
				break ;
			case 2 :
				update_user() ;
				break ;
			case 3 :
				userrecord() ;
				break ;
			case 4 :
				delete_user() ;
				break ;
			case 5 : 
				addBook() ;
				break ;
			case 6 :
				editBook() ;
				break ;
			case 7 : 
				deleteBook() ;
				break;
			case 8 :
				printf("Exiting the program...\n") ;
				return 0;
			default :
				printf("Invalid choice!\n") ;
				break ;
		}
		printf("\nBack to menu? (1 for yes, 0 for no)\n") ;
		int conts ;
		scanf("%d",&conts) ;
		if(conts==0) {
			printf("Exiting the program...\n") ;
			return 0;
		}
	}
}
void readerMenu() {
	while(1) {
		int choice ;
		printf("Reader Menu :\n") ;
		printf("Enter '1' : Search Book\n") ;
		printf("Enter '2' : Borrow Books\n") ;
		printf("Enter '3' : Return Books\n") ;
		printf("Enter '4' : Exit Program\n") ;
		printf("Enter your choice : ") ;
		scanf("%d", &choice) ;
		getchar() ;
		switch (choice) {
			case 1 :
				searchBook() ;
				break ;
			case 2 :
				borrowBook() ;
				break ;
			case 3 :
				returnBook() ;
				break ;
			case 4 :
				printf("Exiting the program...\n") ;
				return 0;
			default :
				printf("Invalid choice!\n") ;
				break ;
	}
	printf("\nBack to menu? (1 for yes, 0 for no)\n") ;
	int cont ;
	scanf("%d",&cont) ;
	if (cont==0) {
		printf("Exiting the program...\n");
		return 0;
	}
}
}
void menu() {
    int ch1;
    printf("\nEnter '1': Signup\n");
    printf("Enter '2': Signin\n");
    printf("Enter your choice:  ");
    scanf("%d", &ch1);
    switch(ch1) {
        case 1: 
        signup();
        signin(); 
        role() ;
        break;
        case 2:
        signin();
        role();
        break;
        default:
        printf("Invalid choice!");
    }
}
void role() {
    int ch4;
    printf("Enter '1': User\n ");
    printf("Enter '2': Librarian\n ");
    printf("Enter your choice:  ");
    scanf("%d", &ch4);
    switch(ch4) {
        case 1:
        readerMenu();
        break;
        case 2:
        librarianMenu();
        break;
        default:
        printf("Invalid choice!");
    }    
}
// Ham tim kiem chuoi con(khong phan biet hoa thuong)
char *strcasestr_custom(const char *haystack, const char *needle) {
    if (!haystack || !needle)
        return NULL;

    size_t haystack_len = strlen(haystack);
    size_t needle_len = strlen(needle);

    for (size_t i = 0; i <= haystack_len - needle_len; ++i) {
        size_t j;
        for (j = 0; j < needle_len; ++j) {
            if (tolower(haystack[i + j]) != tolower(needle[j]))
                break;
        }
        if (j == needle_len) // Tìm thay
            return (char *)(haystack + i);
    }

    return NULL; // Khong tim thay
}

// Ham de tim kiem sach theo ten
void searchBook() {
    char searchQuery[MAX_LINE_LENGTH];
    printf("Enter search query (book title): ");
    fgets(searchQuery, sizeof(searchQuery), stdin);
    searchQuery[strcspn(searchQuery, "\n")] = 0; // Xóa ký t? new line n?u có

    // Mo file de doc
    FILE *file = fopen("C:\\Users\\Nguyen Ha\\OneDrive\\Project ET2031\\Books_Data_C_Cpp.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int found = 0;
    while (fgets(line, sizeof(line), file)) {
        if (strcasestr_custom(line, searchQuery) != NULL) {
            displayBookInfo(line);
            found = 1;
        }
    }

    if (!found) {
        printf("Book not found.\n");
    }

    fclose(file);
}
int searchBooks(const char *searchQuery) {
    FILE *file = fopen("C:\\Users\\Nguyen Ha\\OneDrive\\Project ET2031\\Books_Data_C_Cpp.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        if (strcasestr_custom(line, searchQuery) != NULL) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);
    return 0;
}

// Ham muon sach
void borrowBook() {
    char searchQuery[MAX_LINE_LENGTH];
    printf("Enter the title of the book you want to borrow: ");
    fgets(searchQuery, sizeof(searchQuery), stdin);

    // Loai bo ky tu newline tu bo dem stdin
    size_t len = strlen(searchQuery);
    if (len > 0 && searchQuery[len - 1] == '\n') {
        searchQuery[len - 1] = '\0';
    }

    // Kiem tra xem sach co ton tai trong kho du lieu khong
    if (!searchBooks(searchQuery)) {
        printf("Book not found in library. Please enter a valid book title.\n");
        return;
    }

    // Luu thông tin mu?n sách vào borrow_data.csv
    FILE *borrowFile = fopen("C:\\Users\\Nguyen Ha\\OneDrive\\Project ET2031\\borrow_data.txt", "a");
    if (borrowFile == NULL) {
        printf("Error opening borrow_data.csv\n");
        return;
    }

    // Lay ngay hien thi
    time_t t = time(NULL);
    struct tm *dueDate = localtime(&t);
    dueDate->tm_mday += 30; // Gan han tra la 30 ngay sau khi muon
    mktime(dueDate);

    fprintf(borrowFile, "%s,%d-%d-%d,%s\n", searchQuery, dueDate->tm_year + 1900, dueDate->tm_mon + 1, dueDate->tm_mday, "Not Returned");

    fclose(borrowFile);

    printf("Book borrowed successfully!\n");
}
void displayBorrowedBooks() {
    printf("Books borrowed:\n");

    FILE *file = fopen("C:\\Users\\Nguyen Ha\\OneDrive\\Project ET2031\\borrow_data.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    fclose(file);
}

// Ham tra sach

void returnBook() {
    // Hien thi danh sach sach da muon
    displayBorrowedBooks();

    // Yeu cau nguoi dung nhap ten sach can tra
    char returnBookName[MAX_LINE_LENGTH];
    printf("Enter the name of the book you want to return: ");
    fgets(returnBookName, sizeof(returnBookName), stdin);

    // Loai bo ky tu newline tu chuoi nhap
    size_t len = strlen(returnBookName);
    if (returnBookName[len - 1] == '\n') {
        returnBookName[len - 1] = '\0';
    }

    // Kiem tra xem ten sach can tra co trong danh sach muon khong
    FILE *file = fopen("C:\\Users\\Nguyen Ha\\OneDrive\\Project ET2031\\borrow_data.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int found = 0;
    int borrowedCount = 0; // Bien dem so luong sach da muon
    FILE *tempFile = fopen("temp_borrow_data.txt", "w");
    if (tempFile == NULL) {
        printf("Error opening temporary file.\n");
        fclose(file);
        return;
    }

    while (fgets(line, sizeof(line), file)) {
        char originalLine[MAX_LINE_LENGTH];
        strcpy(originalLine, line); // Sao chep dong goc de ghi lai neu can thiet

        char *token = strtok(line, ",");
        if (token != NULL && strcmp(token, returnBookName) == 0) {
            if (strstr(originalLine, "Not Returned") != NULL) {
                found = 1;
                borrowedCount++;
                // Danh dau sach la da tra
                char *pos = strstr(originalLine, "Not Returned");
                if (pos != NULL) {
                    strncpy(pos, "Returned    ", 12); // Ghi de "Not Returned" bang "Returned"
                }
            }
        }
        if (strstr(originalLine, "Not Returned") != NULL) {
            borrowedCount++;
        }
        fprintf(tempFile, "%s", originalLine);
    }

    fclose(file);
    fclose(tempFile);

    // Xóa file cu và d?i tên file t?m thành file m?i
    remove("C:\\Users\\Nguyen Ha\\OneDrive\\Project ET2031\\borrow_data.txt");
    rename("temp_borrow_data.txt", "C:\\Users\\Nguyen Ha\\OneDrive\\Project ET2031\\borrow_data.txt");

    if (!found) {
        printf("Book \"%s\" not found in your borrowed list or already returned. Please try again.\n", returnBookName);
    } else {
        printf("Book \"%s\" returned successfully.\n", returnBookName);
    }

    if (borrowedCount == 0) {
        printf("You don't have any borrowed books.\n");
    }
}
void printMessageCenter(const char* message)
{
    int len =0;
    int pos = 0;
    //calculate how many space need to print
    len = (78 - strlen(message))/2;
    printf("\t\t\t");
    for(pos =0 ; pos < len ; pos++)
    {
        //print space
        printf(" ");
    }
    //print message
    printf("%s",message);
}
void headMessage(const char *message)
{
    system("cls");
    printf("\t\t\t###########################################################################");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t############      Library management System Project in C       ############");
    printf("\n\t\t\t############                                                   ############");
    printf("\n\t\t\t###########################################################################");
    printf("\n\t\t\t---------------------------------------------------------------------------\n");
    printMessageCenter(message);
    printf("\n\t\t\t----------------------------------------------------------------------------");
}
void welcomeMessage()
{
    headMessage("Nguyen Nguyen Ha and Luu Duy Truong");
    printf("\n\n\n\n\n");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t        =                 WELCOME                   =");
    printf("\n\t\t\t        =                   TO                      =");
    printf("\n\t\t\t        =                 LIBRARY                   =");
    printf("\n\t\t\t        =               MANAGEMENT                  =");
    printf("\n\t\t\t        =                 SYSTEM                    =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\n\n\t\t\t Enter any key to continue.....");
    getch();
}
