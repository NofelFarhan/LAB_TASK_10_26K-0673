                       /*TASK-07 BANK TRANSACTION MANAGEMENT*/
#include <stdio.h>

// Function to calculate final balance
int finalBalance(int trans[], int n, int balance)
{
    if (n == 0)
        return balance;

    balance = balance + trans[n - 1];

    return finalBalance(trans, n - 1, balance);
}

// Function to calculate total deposits
int totalDeposits(int trans[], int n)
{
    if (n == 0)
        return 0;

    if (trans[n - 1] > 0)
        return trans[n - 1] + totalDeposits(trans, n - 1);
    else
        return totalDeposits(trans, n - 1);
}

// Function to copy large withdrawals
int copyLarge(int trans[], int i, int n, int large[], int k)
{
    if (i == n)
        return k;

    if (trans[i] <= -10000)
    {
        large[k] = trans[i];
        k++;
    }

    return copyLarge(trans, i + 1, n, large, k);
}

int main()
{
    int balance = 20000;

    int trans[7] = {20000, -5000, -12000, 8000,-25000, -2500, 15000};

    int large[7];
    int i, count;

    printf("Final Balance: %d\n",finalBalance(trans, 7, balance));

    printf("Total Deposits: %d\n", totalDeposits(trans, 7));

    count = copyLarge(trans, 0, 7, large, 0);

    printf("Large Withdrawals: ");

    for (i = 0; i < count; i++)
    {
        printf("%d ", large[i]);
    }

    return 0;
}
