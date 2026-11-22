               /*TASK-05 PERSONAL EXPENSE MANAGEMENT*/
#include <stdio.h>

int main()
{
    FILE *fp;

    int i, entryNo;
    char category[13];
    float amount, total = 0;

    // Step 1: Add new expense
    fp = fopen("expenses.txt", "ab");

    if (fp == NULL)
    {
        printf("File cannot be opened");
        return 1;
    }

    printf("Category: ");
    scanf("%12s", category);

    printf("Amount: ");
    scanf("%f", &amount);

    fprintf(fp, "%-12s %9.2f\n", category, amount);

    fclose(fp);

    // Step 2: Open file
    fp = fopen("expenses.txt", "rb+");

    if (fp == NULL)
    {
        printf("File cannot be opened");
        return 1;
    }

    // Step 3: Print latest two expenses
    fseek(fp, -2 * 23, SEEK_END);

    printf("\nLatest two expenses:\n");

    for (i = 0; i < 2; i++)
    {
        fscanf(fp, "%s %f", category, &amount);

        printf("%s %.2f\n", category, amount);
    }

    // Step 4: Correct an expense
    printf("\nEntry to fix: ");
    scanf("%d", &entryNo);

    printf("Correct amount: ");
    scanf("%f", &amount);

    if (entryNo < 1 || entryNo > 5)
    {
        printf("Invalid entry number");
        fclose(fp);
        return 1;
    }

    fseek(fp, (entryNo - 1) * 23, SEEK_SET);

    fscanf(fp, "%s %f", category, &total);

    fseek(fp, (entryNo - 1) * 23, SEEK_SET);

    fprintf(fp, "%-12s %9.2f\n", category, amount);

    // Step 5: Print all expenses and total
    rewind(fp);

    total = 0;

    printf("\nAll expenses:\n");

    for (i = 0; i < 5; i++)
    {
        fscanf(fp, "%s %f", category, &amount);

        printf("%s %.2f\n", category, amount);

        total = total + amount;
    }

    printf("\nTotal: %.2f\n", total);

    fclose(fp);

    return 0;
}
