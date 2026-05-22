#include <iostream>
#include <string>
using namespace std;

int main()
{
    string products[5] = {"Milk", "Bread", "Cheese", "Eggs", "Juice"};

    int relation[5][5] = {0};

    int bills[4][5] =
    {
        {1,1,1,0,0},
        {1,1,0,1,0},
        {0,1,1,0,1},
        {1,0,1,1,0}
    };

    for(int b = 0; b < 4; b++)
    {
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                if(i != j && bills[b][i] == 1 && bills[b][j] == 1)
                {
                    relation[i][j]++;
                }
            }
        }
    }

    int count = -1;

    while(count != 0)
    {
        cout << "Enter 1 to view products 0 to exit ";
        cin >> count;

        if(count == 1)
        {
            string search;

            cout << "Enter product name: ";
            cin >> search;

            int index = -1;

            for(int i = 0; i < 5; i++)
            {
                if(products[i] == search)
                {
                    index = i;
                }
            }

            if(index == -1)
            {
                cout << "Product not found\n";
            }
            else
            {
                cout << "\nSuggested products with " << search << ":\n";

                for(int count = 4; count >= 1; count--)
                {
                    for(int i = 0; i < 5; i++)
                    {
                        if(relation[index][i] == count)
                        {
                            cout << products[i]
                                 << " (related "
                                 << relation[index][i]
                                 << " times)\n";
                        }
                    }
                }
            }
        }
    }

    return 0;
}
