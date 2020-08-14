#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
long long inv = 0;
// Complete the countInversions function below.
void merge(int *arr, int i, int j) {
    int endi = 1 + ((i + j) / 2);
    int endj = j + 1;
    
    int *temp = new int[j - i + 1];
    j = endi;
    int k = 0;
    int start = i;

    while(i < endi && j < endj) {
        if(arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;        
        }
        else {
            temp[k] = arr[j];
            inv += endi - i;
            j++;
        }
        k++;
    }

    while(i < endi) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while(j < endj) {
        temp[k] = arr[j];
        j++, k++;
    }
    
    k = 0;
    while(start < endj) {
        arr[start] = temp[k];
        start++, k++;
    }

    delete []temp;
}

void m_sort(int *arr, int si, int ei) {
    if(si >= ei) {
        return;
    }
    int mid = (si + ei) / 2;
    m_sort(arr, si, mid);
    m_sort(arr, mid + 1, ei);
    merge(arr, si, ei);

}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        inv=0;
        scanf("%d",&n);
        int * a = new int[n];
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        m_sort(a,0,n-1);
        cout<<inv<<endl;
    }
    return 0;
}
