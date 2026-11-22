                         /*TASK-04 HOTEL ROOM MANAGEMENT SYSTEM*/
#include <stdio.h>
#include <string.h>

int main()
{
    FILE *fp;

    int i, roomNo, nights;
    int room, bookedNights;
    int rooms[10];

    char status;
    char name[21];
    char guestName[21];
    char guests[10][21];

    float rate, bill;

    // Step 1: Create 10 free rooms
    fp = fopen("hotel.txt", "w");

    for (i = 0; i < 10; i++)
    {
        fprintf(fp, "%3d %c %-20s %2d %8.2f\n",
                101 + i, 'F', "-", 0, 8000.00);
    }

    fclose(fp);

    // Step 2: Open file
    fp = fopen("hotel.txt", "rb+");

    if (fp == NULL)
    {
        printf("File cannot be opened");
        return 1;
    }

    // Step 3: Check-in
    printf("Check-in room: ");
    scanf("%d", &roomNo);

    printf("Name: ");
    scanf("%20s", name);

    printf("Nights: ");
    scanf("%d", &nights);

    if (roomNo < 101 || roomNo > 110 || nights <= 0)
    {
        printf("Invalid input");
        fclose(fp);
        return 1;
    }

    fseek(fp, (roomNo - 101) * 39, SEEK_SET);

    fscanf(fp, "%d %c %s %d %f",
           &room, &status, guestName,
           &bookedNights, &rate);

    if (status == 'F')
    {
        fseek(fp, (roomNo - 101) * 39, SEEK_SET);

        fprintf(fp, "%3d %c %-20s %2d %8.2f\n",
                roomNo, 'B', name, nights, 8000.00);

        printf("Room %d booked\n", roomNo);
    }
    else
    {
        printf("Room already booked\n");
    }

    // Step 4: Search guest
    rewind(fp);

    for (i = 0; i < 10; i++)
    {
        fscanf(fp, "%d %c %s %d %f",
               &rooms[i], &status, guests[i],
               &bookedNights, &rate);
    }

    printf("\nSearch name: ");
    scanf("%20s", name);

    for (i = 0; i < 10; i++)
    {
        if (strcmp(guests[i], name) == 0)
        {
            printf("%s is in room %d\n", name, rooms[i]);
            break;
        }
    }

    if (i == 10)
    {
        printf("Guest not found\n");
    }

    // Step 5: Check-out
    printf("\nCheck-out room: ");
    scanf("%d", &roomNo);

    if (roomNo < 101 || roomNo > 110)
    {
        printf("Invalid room number");
        fclose(fp);
        return 1;
    }

    fseek(fp, (roomNo - 101) * 39, SEEK_SET);

    fscanf(fp, "%d %c %s %d %f",
           &room, &status, guestName,
           &bookedNights, &rate);

    if (status == 'B')
    {
        bill = bookedNights * rate;

        printf("Bill: %d x %.2f = %.2f\n",
               bookedNights, rate, bill);

        fseek(fp, (roomNo - 101) * 39, SEEK_SET);

        fprintf(fp, "%3d %c %-20s %2d %8.2f\n",
                roomNo, 'F', "-", 0, 8000.00);
    }
    else
    {
        printf("Room is already free\n");
    }

    fclose(fp);

    return 0;
}
