                  /*TASK-03 WEATHER DEPARTMENT TEMPERATURE RECORDS*/
#include <stdio.h>

int main()
{
    FILE *fp;

    int i, cityNo;
    char city[10][11];
    char name[11];
    float temp[10], temperature;
    float highest;
    char hottest[11];

    // Step 1: Take input and write cities
    fp = fopen("temperature.txt", "w");

    for (i = 0; i < 5; i++)
    {
        printf("Enter city name: ");
        scanf("%10s", city[i]);

        printf("Enter temperature: ");
        scanf("%f", &temp[i]);

        fprintf(fp, "%-10s %5.1f\n", city[i], temp[i]);
    }

    fclose(fp);

    // Step 2: Open file
    fp = fopen("temperature.txt", "rb+");

    if (fp == NULL)
    {
        printf("File cannot be opened");
        return 1;
    }

    // Step 3: Search city
    printf("\nCity number: ");
    scanf("%d", &cityNo);

    if (cityNo < 1 || cityNo > 5)
    {
        printf("Invalid city number");
        fclose(fp);
        return 1;
    }

    fseek(fp, (cityNo - 1) * 17, SEEK_SET);

    fscanf(fp, "%s %f", name, &temperature);

    printf("%s %.1f\n", name, temperature);

    // Step 4: Correct temperature
    printf("\nCity number to correct: ");
    scanf("%d", &cityNo);

    printf("New temperature: ");
    scanf("%f", &temperature);

    if (cityNo < 1 || cityNo > 5)
    {
        printf("Invalid city number");
        fclose(fp);
        return 1;
    }

    fseek(fp, (cityNo - 1) * 17, SEEK_SET);

    fscanf(fp, "%s %f", name, &temp[0]);

    fseek(fp, (cityNo - 1) * 17, SEEK_SET);

    fprintf(fp, "%-10s %5.1f\n", name, temperature);

    printf("%s updated to %.1f\n", name, temperature);

    // Step 5: Find hottest city
    rewind(fp);

    for (i = 0; i < 5; i++)
    {
        fscanf(fp, "%s %f", name, &temp[i]);

        if (i == 0 || temp[i] > highest)
        {
            highest = temp[i];
            // Save the city name
            // before reading the next record
            if (i == 0)
                ;
        }
    }

    // Read records again to identify hottest city
    rewind(fp);

    for (i = 0; i < 5; i++)
    {
        fscanf(fp, "%s %f", name, &temperature);

        if (temperature == highest)
        {
            sprintf(hottest, "%s", name);
        }
    }

    printf("\nHottest city: %s (%.1f)\n",
           hottest, highest);

    fclose(fp);

    return 0;
}
