#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    int num;
    cin >> num;

    int count[10001];
    fill_n(count, 10001, 0);

    for (int i = 0; i < num; i++)
    {
        int d;
        cin >> d;
        count[d]++;
    }

    for (int i = 0; i < 10001; i++)
    {
        if (i != 0)
            count[i] += count[i - 1];
    }

    for (int i = 0; i < 10001; i++)
    {
        if (i == 0)
        {
            if (count[i] != 0)
                cout << count[i] << endl;
        }
        else
        {
            if (count[i - 1] != count[i])
            {
                for (int j = 0; j < (count[i] - count[i - 1]); j++)
                {
                    cout << i << endl;
                }
            }
        }
    }
}


//#include <iostream>
//using namespace std;
//
//main()
//{
//    cin.tie(NULL);
//    int num;
//    cin >> num;
//
//    int* data = new int[num];
//    int max = 0;
//    for (int i = 0; i < num; i++)
//    {
//        int d;
//        cin >> d;
//        data[i] = d;
//
//        if (data[i] > max)
//            max = data[i];
//    }
//
//    int* count = new int[max + 1];
//    fill_n(count, max + 1, 0);
//    for (int i = 0; i < num; i++)
//    {
//        count[data[i]]++;
//    }
//
//
//    int* count2 = new int[max + 1];
//    fill_n(count2, max + 1, 0);
//    for (int i = 0; i < max + 1; i++)
//    {
//        if (i == 0)
//            count2[i] = count[i];
//        else
//            count2[i] = count2[i - 1] + count[i];
//    }
//
//    int* sort = new int[num];
//    for (int i = num - 1; i >= 0; i--)
//    {
//        int k = count2[data[i]] - 1;
//        count2[data[i]]--;
//        sort[k] = data[i];
//    }
//
//    for (int i = 0; i < num; i++)
//        cout << sort[i] << endl;
//
//    delete[] data;
//    delete[] count;
//    delete[] count2;
//    delete[] sort;
//}
