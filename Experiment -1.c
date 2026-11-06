
#include <stdio.h>

#define MAX 100

void create(int a[], int *n)
{
    int i;
    printf("Enter number of elements: ");
    scanf("%d", n);

    if (*n < 0 || *n > MAX)
    {
        printf("Invalid size!\n");
        *n = 0;
        return;
    }

    printf("Enter array elements:\n");
    for (i = 0; i < *n; i++)
    {
        scanf("%d", &a[i]);
    }
}

void display(int a[], int n)
{
    int i;

    if (n == 0)
    {
        printf("Array is empty!\n");
        return;
    }

    printf("Array elements are:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void insert(int a[], int *n)
{
    int pos, item, i;

    if (*n == MAX)
    {
        printf("Array is full!\n");
        return;
    }

    printf("Enter position: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > *n + 1)
    {
        printf("Invalid position!\n");
        return;
    }

    printf("Enter element to insert: ");
    scanf("%d", &item);

    for (i = *n; i >= pos; i--)
    {
        a[i] = a[i - 1];
    }

    a[pos - 1] = item;
    (*n)++;

    printf("Element inserted successfully!\n");
}

void delete(int a[], int *n)
{
    int pos, i;

    if (*n == 0)
    {
        printf("Array is empty!\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > *n)
    {
        printf("Invalid position!\n");
        return;
    }

    for (i = pos - 1; i < *n - 1; i++)
    {
        a[i] = a[i + 1];
    }

    (*n)--;

    printf("Element deleted successfully!\n");
}

int main()
{
    int a[MAX], n = 0, choice;

    while (1)
    {
        printf("\n1. Create Array");
        printf("\n2. Display Array");
        printf("\n3. Insert Element");
        printf("\n4. Delete Element");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                create(a, &n);
                break;

            case 2:
                display(a, n);
                break;

            case 3:
                insert(a, &n);
                break;

            case 4:
                delete(a, &n);
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
