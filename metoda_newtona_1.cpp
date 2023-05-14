#include <iostream>
#include <vector>

using namespace std;
 
int main() {
    double xp;
    double x[5]; 
    double y[5]; 
    int n;
    cout << "Wprowadz n: ";
    cin >> n;
    for (int i=0;i<n;i++)
    {
    	cout << "Wprowadz x[" << i+1 << "]: ";
    	cin >> x[i];
    }
	for (int i=0;i<n;i++)
    {
    	cout << "Wprowadz y[" << i+1 << "]: ";
    	cin >> y[i];
    }
    cout << "Wprowadz punkt interpolowania x: ";
    cin >> xp;
    vector< vector<double> > W;
    W.resize(n);
    for(int i=0;i<n;i++) {
        W[i].resize(n-i);
        W[0][i]=y[i];
    }
    for(int j=0;j<n-1;j++)
	{	
        for(int i=0;i<n-1-j;i++)
        {
        	W[j+1][i] = (W[j][i+1] - W[j][i])/(x[i+1+j]-x[i]);
        } 
    }
    double s=y[0];
    double il;
    for(int i=1;i<n;i++) 
	{
        il=1;
        for(int j=0;j<i;j++)
            il*=(xp-x[j]);
        s+=W[i][0]*il;
    }
    cout << "W(x) = " << s << endl;
}
 
