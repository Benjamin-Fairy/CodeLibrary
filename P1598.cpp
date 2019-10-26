#include <bits/stdc++.h>
using namespace std;
deque<char> digit['Z' + 5];
string a[4];
int maxx;
signed main()
{
    for (int i = 0; i < 4; i++)
        getline(cin, a[i]);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < (int)a[i].length(); j++)
            if (a[i][j] >= 'A' && a[i][j] <= 'Z')
            digit[(int)a[i][j]].push_back('*');
            for(int i='A';i<='Z';i++)
            maxx=max(maxx,(int)digit[i].size());
            for(int i='A';i<='Z';i++)
            while((int)digit[i].size()<maxx)
            digit[i].push_front(' ');
    while (!digit['Z'].empty())
    {
        for (int i = 'A'; i <= 'Z'; i++)
            cout << (char)digit[i].front() << " ", digit[i].pop_front();
        cout << endl;
    }
    cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" << endl;
    system("pause");
    return false;
}