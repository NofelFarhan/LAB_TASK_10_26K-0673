                        /*TASK-06 CONSTRUCTION COMPANY- TOWER HEIGHTS*/
#include <stdio.h>

void grow(int heights[], int n)
{
    if (n == 0)
        return;

    heights[n - 1] = heights[n - 1] +(int)(heights[n - 1] * 0.10);

    grow(heights, n - 1);
}

int tallest(int heights[], int n)
{
    if (n == 1)
        return 0;

    int p = tallest(heights, n - 1);

    if (heights[n - 1] > heights[p])
        return n - 1;
    else
        return p;
}

int search(int heights[], int n, int target)
{
    if (n == 0)
        return -1;

    if (heights[n - 1] == target)
        return n - 1;

    return search(heights, n - 1, target);
}

int main()
{
    int ids[6] = {101, 102, 103, 104, 105, 106};
    int heights[6] = {45, 120, 78, 200, 95, 150};

    int i, p, target;

    grow(heights, 6);

    printf("New heights: ");

    for (i = 0; i < 6; i++)
        printf("%d ", heights[i]);

    p = tallest(heights, 6);

    printf("\nTallest tower: %d (%d m)",
           ids[p], heights[p]);

    printf("\nEnter height to search: ");
    scanf("%d", &target);

    p = search(heights, 6, target);

    if (p == -1)
        printf("Height not found");
    else
        printf("Tower %d has height %d m",ids[p], heights[p]);

    return 0;
}