/* 
 * 2014 Google Code Jam - Qualification Round
 * Problem A
 * https://code.google.com/codejam/contest/2974486/dashboard#s=p0
*/

#include <iostream>

using namespace std;

int main(){
    int count = 0, cases;
    cin >> cases;

    while (count < cases) {
        int r1, r2, t1[4][4], t2[4][4], h[16] = {0};
        cin >> r1;
        for (int i=0; i<4; i++)
            for (int j=0; j<4; j++)
                cin >> t1[i][j];
        cin >> r2;
        for (int i=0; i<4; i++)
            for (int j=0; j<4; j++)
                cin >> t2[i][j];

        for (int i=0; i<4; i++) {
            h[t1[r1-1][i]-1]++;
            h[t2[r2-1][i]-1]++;
        }

        int f = 0, idx = -1;
        for (int i=0; i<16; i++)
            if (h[i] > 1) {
                f++;
                idx = i+1;
            }

        if (f == 1)
            cout << "Case #" << ++count << ": " << idx << endl;
        else if (f > 1)
            cout << "Case #" << ++count << ": Bad magician!" << endl;
        else
            cout << "Case #" << ++count << ": Volunteer cheated!" << endl;
    }

    return 0;
}