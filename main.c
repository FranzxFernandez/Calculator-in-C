#include <stdio.h>

typedef struct {
    const char *name;
    int op_code;
    double (*operation)(const double, const double);
} Operation;

double add(const double x, const double y)
{
    return x + y;
}

double subtract(const double x, const double y)
{
    return x - y;
}

double multiply(const double x, const double y)
{
    return x * y;
}

double divide(const double x, const double y)
{
    return (y != 0) ? (x / y) : (-1);
}

void print_menu()
{
    printf("\n=============================================\n");
    printf("|                                           |\n");
    printf("|       ----------------------              |\n");
    printf("|             Calculator                    |\n");
    printf("|       ----------------------              |\n");
    printf("|                                           |\n");
    printf("|       1. Add                              |\n");
    printf("|       2. Subtract                         |\n");
    printf("|       3. Multiply                         |\n");
    printf("|       4. Division                         |\n");
    printf("|       0. Exit                             |\n");
    printf("|                                           |\n");
    printf("=============================================\n");
}

int get_operation()
{
    int selected_operation = 0;
    printf("\nEnter the operation number (0 for exit):  ");
    scanf("%d", &selected_operation);
    return selected_operation;
}

double get_number(int index)
{
    double number = 0;
    printf("\nPlease enter %d number: ", index);
    scanf("%lf", &number);
    return number;
}

void perform_operation(Operation *operations, int selected_operation, double a, double b)
{
    if (selected_operation >= 1 && selected_operation <= 4)
    {
        double result = operations[selected_operation - 1].operation(a, b);
        printf("The result is: %.2lf\n", result);
    }
    else if (selected_operation == 0)
    {
        printf("\nClosing the program..\n");
    }
    else
    {
        printf("Invalid choice\n");
    }
}

int main()
{
    Operation operations[] = {
        {"Add", 1, add},
        {"Subtract", 2, subtract},
        {"Multiply", 3, multiply},
        {"Divide", 4, divide}};

    int selected_operation = 0;
    do
    {
        print_menu();

        double a = get_number(1);
        double b = get_number(2);
        selected_operation = get_operation();

        perform_operation(operations, selected_operation, a, b);

    } while (selected_operation != 0);

    return 0;
}
