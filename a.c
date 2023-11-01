void insercion(int arr[], int tam)
{
    for (int i = 1; i < tam; i++)
    {
        int valor = arr[i];
        int j = i;
        while (j > 0 && valor < arr[j + 1])
        {
            intercambia(&arr[j], &arr[j + 1]);
            j--;
        }
    }
}

void intercambia(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}