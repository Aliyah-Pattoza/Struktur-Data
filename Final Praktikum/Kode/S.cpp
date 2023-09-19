#include <iostream>
#include <unordered_map>
using namespace std;

bool divisible(int x, int y, int z)
{
    int temp = y;

    while (temp > 0)
    {
        x *= 10;
        temp /= 10;
    }
    int sum = x + y;
    return (sum % z == 0);
}

int pairs(int arr[], int n, int k)
{
    int pair = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (divisible(arr[i], arr[j], k))
                pair++;

            if (divisible(arr[j], arr[i], k))
                pair++;
        }
    }
    return pair;
}

int main()
{
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int result = pairs(arr, n, k);
    cout << result << endl;

    return 0;
}
