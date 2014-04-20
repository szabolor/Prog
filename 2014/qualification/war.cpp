/* 
 * 2014 Google Code Jam - Qualification Round
 * Problem D
 * https://code.google.com/codejam/contest/2974486/dashboard#s=p3
*/ 


#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int count = 0, cases;
    cin >> cases;

    while (count < cases) {
        int n;
        cin >> n;
        double m0[n], m1[n];
        
        for (int i=0; i<n; i++)
            cin >> m0[i];
        for (int i=0; i<n; i++)
            cin >> m1[i];

        sort(m0, m0 + n);
        sort(m1, m1 + n);

        // Deceitful War
        int dw[n], s0 = 0;
        for (int i=0; i<n; i++)
            dw[i] = 0;
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (m0[i] > m1[j] && dw[j] != 1) {
                    dw[j] = 1;
                    s0++;
                    break;
                }

        // War
        int w[n];
        int s1 = n;
        for (int i=0; i<n; i++)
            w[i] = 0;
        for (int i=0; i<n; i++)
            for (int j=0; j<n; j++)
                if (m1[j] > m0[i] && w[j] != 1) {
                    w[j] = 1;
                    s1--;
                    break;
                }

        cout << "Case #" << ++count << ": " << s0 << " " << s1 << endl;
    }

    return 0;
}