                            /*TASK-08 HOSPITAL PATIENT HEALTH SCORE*/
#include <stdio.h>

// Function to calculate daily scores
void buildScores(int change[], int score[], int i, int n, int current)
{
    if (i == n)
        return;

    current = current + change[i];
    score[i] = current;

    buildScores(change, score, i + 1, n, current);
}

// Function to count scores below 50
int countLow(int score[], int n)
{
    if (n == 0)
        return 0;

    if (score[n - 1] < 50)
        return 1 + countLow(score, n - 1);
    else
        return countLow(score, n - 1);
}

// Function to reverse the array
void reverse(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int temp;

    temp = arr[left];
    arr[left] = arr[right];
    arr[right] = temp;

    reverse(arr, left + 1, right - 1);
}

int main()
{
    int start = 70;

    int change[10] = {5, -8, -10, -12, 4, 6, 3, 7, -2, 5};

    int score[10];
    int i, total;

    buildScores(change, score, 0, 10, start);

    printf("Daily Scores: ");

    for (i = 0; i < 10; i++)
    {
        printf("%d ", score[i]);
    }

    total = countLow(score, 10);

    printf("\nDays below 50: %d", total);

    reverse(score, 0, 9);

    printf("\nLatest First: ");

    for (i = 0; i < 10; i++)
    {
        printf("%d ", score[i]);
    }

    return 0;
}
