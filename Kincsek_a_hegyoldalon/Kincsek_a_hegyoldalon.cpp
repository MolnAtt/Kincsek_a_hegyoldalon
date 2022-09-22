#include <iostream>
#include <vector>
#include <algorithm> //Al-Khwarizmi 
#include <stack>

using namespace std;
int main()
{
    cout << "Hello World!\n";
    int N, K, L;
    cin >> N;
    cin >> K;
    cin >> L;

    vector<vector<int>> m(N,vector<int>(K));



    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            cin >> m[i][j];
        }
    }

    // beolvasás vége
    

    vector<vector<int>> a_kincsek_titkos_terkepkeje(N, vector<int>(K));

    // 0. bal felsõ sarok
    a_kincsek_titkos_terkepkeje[0][0] = m[0][0];
    // 1. elsõ sor
    for (int i = 1; i < N; i++)
    {
        a_kincsek_titkos_terkepkeje[i][0] = a_kincsek_titkos_terkepkeje[i - 1][0] + m[i][0] - L;
    }
    // 2. elsõ oszlop
    for (int i = 1; i < K; i++)
    {
        a_kincsek_titkos_terkepkeje[0][i] = a_kincsek_titkos_terkepkeje[0][i - 1] + m[0][i] - L;
    }

    // 3. minden más (belseje)
    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < K; j++)
        {
            a_kincsek_titkos_terkepkeje[i][j] = max(
                a_kincsek_titkos_terkepkeje[i - 1][j],max(
                a_kincsek_titkos_terkepkeje[i][j - 1],
                a_kincsek_titkos_terkepkeje[i - 1][j - 1])) - L + m[i][j];
        }
    }

    // teszt
    /**/
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < K; j++)
        {
            cout << a_kincsek_titkos_terkepkeje[i][j] << " ";
        }
        cout << endl;
    }
    /**/

    cout << a_kincsek_titkos_terkepkeje[N - 1][K - 1] << endl;



    string result = "";
    stack<char> verem;
    int i = N - 1;
    int j = K - 1;
    
    while (0 < i && 0 < j)
    {
        if (a_kincsek_titkos_terkepkeje[i - 1][j] == a_kincsek_titkos_terkepkeje[i][j] - m[i][j] + L)
        {
            verem.push('L');
            i--;
        }
        else if (a_kincsek_titkos_terkepkeje[i][j - 1] == a_kincsek_titkos_terkepkeje[i][j] - m[i][j] + L)
        {
            verem.push('J');
            j--;
        }
        else
        {
            verem.push('A');
            i--;
            j--;
        }
    }

    // itt már a mátrix szélén vagyunk. Az elsõ sorban és/vagy az elsõ oszlopban.
    
    while (0 < i)
    {
        verem.push('L');
        i--;
    }

    while (0 < j)
    {
        verem.push('J');
        j--;
    }

    while (!verem.empty())
    {
        cout << verem.top();
        verem.pop();
    }
    cout << endl;


}
