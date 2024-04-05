#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#define UNDERWEIGHT_THRESHOLD 18.5
#define NORMAL_WEIGHT_THRESHOLD 25
#define OVERWEIGHT_THRESHOLD 30
#define MAX_USERS 10
#define MAX_NAME_LENGTH 50

#define PASSAGE "This is our PDS Project."
#define MAX_LENGTH 1000
#define TIME_LIMIT 60 
int main();
char cont;


long long toDecimal(char *num, int baseFrom);
void fromDecimal(long long decimalNum, int baseTo, char *result);

int case1() {
    char num[65]; 
    int baseFrom, baseTo;
    char result[65]; 

    printf("Enter the number: ");
    scanf("%s", &num);

    printf("Enter the base of the number: ");
    scanf("%d", &baseFrom);

    printf("Enter the base to convert to: ");
    scanf("%d", &baseTo);

    
    long long decimalNum = toDecimal(num, baseFrom);

   
    fromDecimal(decimalNum, baseTo, result);

    printf("The number in base %d is: %s\n", baseTo, result);
  
    main();
    return 0;
    
}

long long toDecimal(char *num, int baseFrom) {
    int len = strlen(num);
    long long decimalNum = 0;
    int power = 0; 

    
    for (int i = len - 1; i >= 0; i--) {
        int digit = (isdigit(num[i])) ? (num[i] - '0') : (toupper(num[i]) - 'A' + 10);
        decimalNum += digit * pow(baseFrom, power++);
    }

    return decimalNum;
}


void fromDecimal(long long decimalNum, int baseTo, char *result) {
    char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int i = 0;
    while (decimalNum > 0) {
        int remainder = decimalNum % baseTo;
        result[i++] = digits[remainder];
        decimalNum /= baseTo;
    }
    result[i] = '\0';

    
    int len = strlen(result);
    for (int j = 0; j < len / 2; j++) {
        char temp = result[j];
        result[j] = result[len - j - 1];
        result[len - j - 1] = temp;
    }

    
    if (i == 0) {
        strcpy(result, "0");
    }
}



float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

int case2() {
    float weight, height;
    
    printf("Enter your weight in kilograms: ");
    scanf("%f", &weight);
    
    printf("Enter your height in meters: ");
    scanf("%f", &height);
    
    
    if (height == 0) {
        printf("Error: Height cannot be zero.\n");
        return 1;
    }
    
    
    float bmi = calculateBMI(weight, height);
    
    printf("Your BMI is: %.2f\n", bmi);
    
    // Interpretation of BMI
    if (bmi < UNDERWEIGHT_THRESHOLD) {
        printf("You are underweight.\n");
    } else if (bmi >= UNDERWEIGHT_THRESHOLD && bmi < NORMAL_WEIGHT_THRESHOLD) {
        printf("You have a normal weight.\n");
    } else if (bmi >= NORMAL_WEIGHT_THRESHOLD && bmi < OVERWEIGHT_THRESHOLD) {
        printf("You are overweight.\n");
    } else {
        printf("You are obese.\n");
    }
    main();
    
    return 0;
}




#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265359

int case3() {
    char o;
    double num, result;
    char choice;
    int isDegree = 1;

    printf("Welcome to Advanced Calculator\n");

    while (1) {
        printf("\nEnter an operator (+, -, *, /, ^, sqrt, mod, sin, cos, tan, asin, acos, atan, deg, rad): ");
        scanf(" %c", &o);

        if (o == '+' || o == '-' || o == '*' || o == '/') {
            printf("Enter numbers (enter 'q' to finish input):\n");
            if (o == '+') {
                result = 0;
            } else if (o == '*') {
                result = 1;
            }
        } else if (o == 's' || o == 'S' || o == 'c' || o == 'C' || o == 't' || o == 'T' || o == 'a' || o == 'A') {
            printf("Enter a number: ");
            scanf("%lf", &num);
            if (isDegree && (o == 's' || o == 'S' || o == 'c' || o == 'C' || o == 't' || o == 'T')) {
                printf("Do you want to enter degrees (y/n)? ");
                scanf(" %c", &choice);
                if (choice == 'y' || choice == 'Y') {
                    printf("Enter degrees: ");
                    double degrees;
                    scanf("%lf", &degrees);
                    num = degrees * PI / 180; // Convert degrees to radians
                }
            }
        }

        while (1) {
            if (o == '+' || o == '-' || o == '*' || o == '/') {
                scanf("%lf", &num);
                if (getchar() == 'q') {
                    break;
                }
            } else if (o == 's' || o == 'S' || o == 'c' || o == 'C' || o == 't' || o == 'T' || o == 'a' || o == 'A') {
                if (o == 's' || o == 'S' || o == 'c' || o == 'C' || o == 't' || o == 'T') {
                    break;
                } else {
                    printf("Enter an operator (s, c, t) for asin, acos, atan, respectively: ");
                    scanf(" %c", &o);
                    switch(o) {
                        case 's':
                        case 'S':
                            result = asin(num) * (isDegree ? 180 / PI : 1);
                            break;
                        case 'c':
                        case 'C':
                            result = acos(num) * (isDegree ? 180 / PI : 1);
                            break;
                        case 't':
                        case 'T':
                            result = atan(num) * (isDegree ? 180 / PI : 1);
                            break;
                        default:
                            printf("Error! Invalid operator.\n");
                            break;
                    }
                    printf("Result: %.2lf\n", result);
                }
            }

            switch(o) {
                case '+':
                    result += num;
                    break;
                case '-':
                    result -= num;
                    break;
                case '*':
                    result *= num;
                    break;
                case '/':
                    if (num == 0) {
                        printf("Error! Division by zero.\n");
                    } else {
                        result /= num;
                    }
                    break;
                case '^':
                    result = pow(result, num);
                    break;
                case 'm':
                case 'M':
                    if (num == 0) {
                        printf("Error! Modulus by zero.\n");
                    } else {
                        result = fmod(result, num);
                    }
                    break;
                case 'd':
                case 'D':
                    isDegree = 1;
                    printf("Switched to Degree mode.\n");
                    break;
                case 'r':
                case 'R':
                    isDegree = 0;
                    printf("Switched to Radian mode.\n");
                    break;
                default:
                    printf("Error! Invalid operator.\n");
                    break;
            }

            if (o == '+' || o == '-' || o == '*' || o == '/') {
                printf("Result so far: %.2lf\n", result);
                printf("Enter next operator (+, -, *, /, ^, sqrt, mod, sin, cos, tan, asin, acos, atan, deg, rad): ");
                scanf(" %c", &o);
                if (o == '+' || o == '-' || o == '*' || o == '/') {
                    printf("Enter next number (enter 'q' to finish input): ");
                } else {
                    printf("Enter a number: ");
                }
            }
        }

        printf("Result: %.2lf\n", result);

        printf("Do you want to continue (y/n)? ");
        scanf(" %c", &choice);

        if (choice != 'y' && choice != 'Y')
            break;
    }

    printf("\nThank you for using Advanced Calculator. Goodbye!\n");
    main();
    return 0;
}



int isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

// Function to get the name of the month
const char* getMonthName(int month) {
    const char* monthNames[] = {"January", "February", "March", "April", "May", "June",
                                "July", "August", "September", "October", "November", "December"};
    return monthNames[month - 1];
}

int case4() {
    int year, month, daysInMonth, startingDay, day;

    // Input year and month
    printf("Enter the year: ");
    scanf("%d", &year);
    printf("Enter the month (1-12): ");
    scanf("%d", &month);

    // Validate input
    if (month < 1 || month > 12) {
        printf("Invalid month input.\n");
        return 1;
    }

    // Calculate days in month
    if (month == 2) {
        if (isLeapYear(year))
            daysInMonth = 29;
        else
            daysInMonth = 28;
    } else if (month == 4 || month == 6 || month == 9 || month == 11)
        daysInMonth = 30;
    else
        daysInMonth = 31;

    // Calculate starting day
    startingDay = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
    for (int i = 1; i < month; i++) {
        if (i == 2) {
            if (isLeapYear(year))
                startingDay += 29;
            else
                startingDay += 28;
        } else if (i == 4 || i == 6 || i == 9 || i == 11)
            startingDay += 30;
        else
            startingDay += 31;
    }
    startingDay %= 7;

    // Print calendar header
    printf("\n====================================\n");
    printf("\t%s %d\n", getMonthName(month), year);
    printf("====================================\n");
    printf(" Sun Mon Tue Wed Thu Fri Sat\n");
    printf("====================================\n");

    // Print leading spaces
    for (int i = 0; i < startingDay; i++) {
        printf("    ");
    }

    // Print days
    for (day = 1; day <= daysInMonth; day++) {
        printf("%4d", day);
        startingDay++;
        if (startingDay > 6) {
            startingDay = 0;
            printf("\n");
        }
    }

    // Print new line at the end if necessary
    if (startingDay != 0)
        printf("\n");

    printf("====================================\n");
    main();
    return 0;
}



struct User {
    char name[MAX_NAME_LENGTH];
    float balance;
};

struct Expense {
    char description[100];
    float amount;
    int num_users;
    struct User *users[MAX_USERS];
};

// Function to add a user
void addUser(struct User *users[], int *num_users) {
    if (*num_users < MAX_USERS) {
        struct User *newUser = (struct User *)malloc(sizeof(struct User));
        printf("Enter user name: ");
        scanf("%s", newUser->name);
        newUser->balance = 0.0;
        users[*num_users] = newUser;
        (*num_users)++;
        printf("User added successfully.\n");
    } else {
        printf("Maximum number of users reached.\n");
    }
}

// Function to create a new expense
void createExpense(struct Expense *expenses[], int *num_expenses, struct User *users[], int num_users) {
    if (*num_expenses < MAX_USERS) {
        struct Expense *newExpense = (struct Expense *)malloc(sizeof(struct Expense));
        printf("Enter expense description: ");
        scanf("%s", newExpense->description);
        printf("Enter expense amount: ");
        scanf("%f", &(newExpense->amount));

        newExpense->num_users = 0;
        for (int i = 0; i < num_users; i++) {
            char response;
            printf("Did %s participate in this expense? (y/n): ", users[i]->name);
            scanf(" %c", &response);
            if (response == 'y' || response == 'Y') {
                newExpense->users[newExpense->num_users++] = users[i];
            }
        }

        expenses[*num_expenses] = newExpense;
        (*num_expenses)++;
        printf("Expense created successfully.\n");
    } else {
        printf("Maximum number of expenses reached.\n");
    }
}

// Function to settle debts
void settleExpenses(struct User *users[], int num_users, struct Expense *expenses[], int num_expenses) {
    for (int i = 0; i < num_users; i++) {
        float total_owed = 0.0;
        for (int j = 0; j < num_expenses; j++) {
            for (int k = 0; k < expenses[j]->num_users; k++) {
                if (strcmp(users[i]->name, expenses[j]->users[k]->name) == 0) {
                    total_owed += expenses[j]->amount / expenses[j]->num_users;
                }
            }
        }
        users[i]->balance = total_owed;
    }
}

// Function to display balances
void displayBalances(struct User *users[], int num_users) {
    printf("User Balances:\n");
    for (int i = 0; i < num_users; i++) {
        printf("%s: %.2f\n", users[i]->name, users[i]->balance);
    }
}

int case5() {
    struct User *users[MAX_USERS];
    struct Expense *expenses[MAX_USERS];
    int num_users = 0;
    int num_expenses = 0;

    int choice;
    do {
        printf("\nSplit Wise App\n");
        printf("1. Add User\n");
        printf("2. Create Expense\n");
        printf("3. Settle Expenses\n");
        printf("4. Display Balances\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addUser(users, &num_users);
                break;
            case 2:
                createExpense(expenses, &num_expenses, users, num_users);
                break;
            case 3:
                settleExpenses(users, num_users, expenses, num_expenses);
                printf("Expenses settled.\n");
                break;
            case 4:
                displayBalances(users, num_users);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    // Free allocated memory
    for (int i = 0; i < num_users; i++) {
        free(users[i]);
    }
    for (int i = 0; i < num_expenses; i++) {
        free(expenses[i]);
    }
    main();
    return 0;
}



int case6() {
    char input[MAX_LENGTH];
    time_t start_time, end_time;
    double elapsed_time;
    int correct_chars = 0, total_chars = 0;

    printf("Type the following passage:\n%s\n", PASSAGE);
    printf("Press Enter when you are ready to start.");

    // Wait for user to press Enter
    getchar();

    // Start the timer
    start_time = time(NULL);

    printf("Start typing:\n");

    // Read user input
    fgets(input, MAX_LENGTH, stdin);

    // End the timer
    end_time = time(NULL);

    // Calculate elapsed time
    elapsed_time = difftime(end_time, start_time);

    // Calculate number of correct characters
    for (int i = 0; i < strlen(PASSAGE) && i < strlen(input); i++) {
        if (PASSAGE[i] == input[i]) {
            correct_chars++;
        }
        total_chars++;
    }

    // Display results
    printf("\nTyping test results:\n");
    printf("Time taken: %.2f seconds\n", elapsed_time);
    printf("Total characters typed: %d\n", total_chars);
    printf("Correct characters: %d\n", correct_chars);
    printf("Accuracy: %.2f%%\n", (double)correct_chars / total_chars * 100);
    printf("Typing speed: %.2f characters per minute\n", (double)total_chars / elapsed_time * 60);
    main();
    return 0;
}



void lengthConversion();
void weightConversion();
void temperatureConversion();

int case7() {
    int choice;

    printf("Unit Conversion Program\n");
    printf("1. Length Conversion\n");
    printf("2. Weight Conversion\n");
    printf("3. Temperature Conversion\n");
    printf("Enter your choice (1, 2, 3): ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            lengthConversion();
            break;
        case 2:
            weightConversion();
            break;
        case 3:
            temperatureConversion();
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }
    main();
    return 0;
}

// Function to perform length conversion
void lengthConversion() {
    double value;
    int choice;

    printf("Length Conversion\n");
    printf("1. Meters to Kilometers\n");
    printf("2. Kilometers to Meters\n");
    printf("3. Inches to Centimeters\n");
    printf("4. Feet to Meters\n");
    printf("5. Yards to Meters\n");
    printf("Enter your choice (1-5): ");
    scanf("%d", &choice);

    printf("Enter the value: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            printf("%.2lf meters = %.2lf kilometers\n", value, value / 1000);
            break;
        case 2:
            printf("%.2lf kilometers = %.2lf meters\n", value, value * 1000);
            break;
        case 3:
            printf("%.2lf inches = %.2lf centimeters\n", value, value * 2.54);
            break;
        case 4:
            printf("%.2lf feet = %.2lf meters\n", value, value * 0.3048);
            break;
        case 5:
            printf("%.2lf yards = %.2lf meters\n", value, value * 0.9144);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

// Function to perform weight conversion
void weightConversion() {
    double value;
    int choice;

    printf("Weight Conversion\n");
    printf("1. Grams to Kilograms\n");
    printf("2. Kilograms to Grams\n");
    printf("3. Ounces to Grams\n");
    printf("4. Pounds to Kilograms\n");
    printf("Enter your choice (1-4): ");
    scanf("%d", &choice);

    printf("Enter the value: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            printf("%.2lf grams = %.2lf kilograms\n", value, value / 1000);
            break;
        case 2:
            printf("%.2lf kilograms = %.2lf grams\n", value, value * 1000);
            break;
        case 3:
            printf("%.2lf ounces = %.2lf grams\n", value, value * 28.3495);
            break;
        case 4:
            printf("%.2lf pounds = %.2lf kilograms\n", value, value * 0.453592);
            break;
        default:
            printf("Invalid choice!\n");
    }
}

// Function to perform temperature conversion
void temperatureConversion() {
    double value;
    int choice;

    printf("Temperature Conversion\n");
    printf("1. Celsius to Fahrenheit\n");
    printf("2. Fahrenheit to Celsius\n");
    printf("Enter your choice (1-2): ");
    scanf("%d", &choice);

    printf("Enter the value: ");
    scanf("%lf", &value);

    switch (choice) {
        case 1:
            printf("%.2lf Celsius = %.2lf Fahrenheit\n", value, (value * 9 / 5) + 32);
            break;
        case 2:
            printf("%.2lf Fahrenheit = %.2lf Celsius\n", value, (value - 32) * 5 / 9);
            break;
        default:
            printf("Invalid choice!\n");
    }
}





int main()
{
    int ch;
    printf("\nMenu Available to the User:");
    printf("\n1.Base System Converter");
    printf("\n2.Body Mass Index Calculator");
    printf("\n3.Calculator");
    printf("\n4.Calendar");
    printf("\n5.Splitwise Application");
    printf("\n6.Typing Speed Test");
    printf("\n7.Unit Converter");
    printf("\nEnter your choice:");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:
        {
            case1();
            break;
        }

        case 2:
        {
            case2();
            break;
        }
        case 3:{

            case3();
            break;

        }
        case 4:{
            case4();
            break;
        }
        case 5:{
            case5();
            break;
        }
        case 6:{
            case6();
            break;
        }
        case 7:{
            case7();
            break;
        }
        default:
        {
            printf("M");
        }
    }
}