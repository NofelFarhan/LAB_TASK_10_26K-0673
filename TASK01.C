             /*task 01--freshmart grocery store*/
#include <stdio.h>

int main()
{
    FILE *fp;

    int itemNo, quantity;
    int number, stock;
    char name[20];
    float price, bill, total = 0;

    // Step 1: Create file and write items
    fp = fopen("items.txt", "w");

    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 1, "Rice", 250.00, 40);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 2, "Sugar", 160.00, 25);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 3, "Milk", 220.00, 30);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 4, "CookingOil", 560.00, 12);
    fprintf(fp, "%-4d %-20s %9.2f %5d\n", 5, "Tea", 450.00, 18);

    fclose(fp);

    // Step 2: Open file for reading and writing
    fp = fopen("items.txt", "rb+");

    if (fp == NULL)
    {
        printf("File cannot be opened");
        return 1;
    }

    while (1)
    {
        printf("\nItem no (0 to stop): ");
        scanf("%d", &itemNo);

        if (itemNo == 0)
            break;

        printf("Quantity: ");
        scanf("%d", &quantity);

        if (itemNo < 1 || itemNo > 5 || quantity <= 0)
        {
            printf("Invalid input\n");
            continue;
        }

        // Step 3: Move to required item
        fseek(fp, (itemNo - 1) * 42, SEEK_SET);

        fscanf(fp, "%d %s %f %d",
               &number, name, &price, &stock);

        // Step 4: Check stock
        if (stock >= quantity)
        {
            bill = price * quantity;
            total = total + bill;

            printf("%s %d x %.2f = %.2f\n",
                   name, quantity, price, bill);

            stock = stock - quantity;

            // Step 5: Update record
            fseek(fp, (itemNo - 1) * 42, SEEK_SET);

            fprintf(fp, "%-4d %-20s %9.2f %5d\n",
                    number, name, price, stock);
        }
        else
        {
            printf("Only %d %s in stock\n", stock, name);
        }
    }

    printf("\nTotal bill: %.2f\n", total);

    fclose(fp);

    return 0;
}
