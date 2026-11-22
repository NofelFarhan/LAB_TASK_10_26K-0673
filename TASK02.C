                     /*TASK-02 COLLEGE ATTENDENCE MANAGEMENT*/
#include <stdio.h>

int main()
{
    FILE *fp;

    int roll, lectures;
    int number, attended;
    char name[15];
    float percentage;

    // Step 1: Create file
    fp = fopen("attendance.txt", "w");

    fprintf(fp, "%-3d %-15s %3d\n", 1, "Ayesha", 18);
    fprintf(fp, "%-3d %-15s %3d\n", 2, "Bilal", 14);
    fprintf(fp, "%-3d %-15s %3d\n", 3, "Hamza", 20);
    fprintf(fp, "%-3d %-15s %3d\n", 4, "Sana", 12);
    fprintf(fp, "%-3d %-15s %3d\n", 5, "Zainab", 16);

    fclose(fp);

    // Step 2: Open file
    fp = fopen("attendance.txt", "rb+");

    if (fp == NULL)
    {
        printf("File cannot be opened");
        return 1;
    }

    // Step 3: Search student
    printf("Roll number: ");
    scanf("%d", &roll);

    if (roll < 1 || roll > 5)
    {
        printf("Invalid roll number");
        fclose(fp);
        return 1;
    }

    fseek(fp, (roll - 1) * 24, SEEK_SET);

    fscanf(fp, "%d %s %d", &number, name, &attended);

    percentage = (attended / 20.0) * 100;

    printf("%s: %d / 20 (%.1f%%)",
           name, attended, percentage);

    if (percentage < 75)
    {
        printf(" Short attendance");
    }

    // Step 4: Add leave lectures
    printf("\n\nRoll number for leave: ");
    scanf("%d", &roll);

    printf("Lectures: ");
    scanf("%d", &lectures);

    if (roll < 1 || roll > 5 || lectures < 0)
    {
        printf("Invalid input");
        fclose(fp);
        return 1;
    }

    fseek(fp, (roll - 1) * 24, SEEK_SET);

    fscanf(fp, "%d %s %d", &number, name, &attended);

    attended = attended + lectures;

    fseek(fp, (roll - 1) * 24, SEEK_SET);

    fprintf(fp, "%-3d %-15s %3d\n",
            number, name, attended);

    percentage = (attended / 20.0) * 100;

    printf("\n%s: now %d / 20 (%.1f%%)\n",
           name, attended, percentage);

    // Step 5: Print last student's record
    fseek(fp, -24, SEEK_END);

    fscanf(fp, "%d %s %d", &number, name, &attended);

    printf("\nLast record: %d %s %d\n",
           number, name, attended);

    fclose(fp);

    return 0;
}
