/*lsferreira programming */
#include <iostream>
using namespace std;

int main() {
    int num=0;
	for(int i=1;i<1000;i++)
        {
            	if (i % 5 == 0)
                {
                    cout << i << "; ";
                    num=num+i;
                }
                else if (i % 3 == 0)
                {
                    cout << i << "; ";
                    num=num+i;
                }
        }
        cout << endl << "===" << endl;
        cout << num << endl;
	return 0;
}
