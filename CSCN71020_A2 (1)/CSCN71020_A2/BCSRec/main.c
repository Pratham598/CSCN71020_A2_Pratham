#include <stdio.h>
#include <stdbool.h>

// Function prototypes
void setLength(int input, int* length);
void setWidth(int input, int* width);
int getPerimeter(int* length, int* width);
int getArea(int* length, int* width);
void printWelcomeMenu();
void printOptions();
int getIntInput(char message[]);

// Main function
int main()
{
    int length = 5;  // Updated default length
    int width = 3;   // Updated default width
    bool continueProgram = true;  // Control variable for the main loop

    // Main program loop
    while (continueProgram) {
        printWelcomeMenu();  // Display welcome message
        printOptions();      // Display user options

        // Get user input for menu selection
        int menuInput = getIntInput("Enter your menu option:");

        // Handle user input
        switch (menuInput)
        {
        case 1:
            // Display current length and width
            printf("\nRectangle dimensions: Length = %d, Width = %d\n\n", length, width);
            break;
        case 2:
            // Update the length of the rectangle
            setLength(getIntInput("Enter the new length (1 - 100):"), &length);
            break;
        case 3:
            // Update the width of the rectangle
            setWidth(getIntInput("Enter the new width (1 - 100):"), &width);
            break;
        case 4:
            // Display the perimeter of the rectangle
            printf("\nThe perimeter of the rectangle is %d units.\n\n", getPerimeter(&length, &width));
            break;
        case 5:
            // Display the area of the rectangle
            printf("\nThe area of the rectangle is %d square units.\n\n", getArea(&length, &width));
            break;
        case 6:
            // Exit the program
            continueProgram = false;
            printf("Thank you for using the program. Goodbye!\n");
            break;
        default:
            // Handle invalid input
            printf("\nInvalid option. Please select a valid menu option (1-6).\n\n");
            break;
        }
    }

    return 0;
}

// Function to get integer input from the user
int getIntInput(char message[])
{
    int input;
    int scannedValues;
    do {
        printf("\n%s\n", message);
        scannedValues = scanf_s("%d", &input);
        int buf;
        // Clear input buffer
        while ((buf = getchar()) != '\n' && buf != EOF);
    } while (scannedValues != 1);  // Repeat until valid input is received
    return input;
}

// Function to set the length of the rectangle
void setLength(int input, int* length)
{
    if (input >= 1 && input <= 100) {
        *length = input;
        printf("\nLength updated successfully to %d.\n", *length);
    }
    else {
        printf("\nInvalid input. Please enter a value between 1 and 100.\n");
    }
}

// Function to set the width of the rectangle
void setWidth(int input, int* width)
{
    if (input >= 1 && input <= 100) {
        *width = input;
        printf("\nWidth updated successfully to %d.\n", *width);
    }
    else {
        printf("\nInvalid input. Please enter a value between 1 and 100.\n");
    }
}

// Function to calculate the perimeter of the rectangle
int getPerimeter(int* length, int* width)
{
    return 2 * (*length + *width);
}

// Function to calculate the area of the rectangle
int getArea(int* length, int* width)
{
    return (*length) * (*width);
}

// Function to display the welcome menu
void printWelcomeMenu()
{
    printf("\n==============================\n");
    printf("   WELCOME TO RECTANGLE TOOL\n");
    printf("==============================\n");
}

// Function to display the available options
void printOptions()
{
    printf("\nChoose an option:\n");
    printf("1. Display current dimensions\n");
    printf("2. Change rectangle length\n");
    printf("3. Change rectangle width\n");
    printf("4. Calculate perimeter\n");
    printf("5. Calculate area\n");
    printf("6. Exit\n");
}

