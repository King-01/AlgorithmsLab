#include<iostream>


using namespace std;

void merge(int a[], int l, int mid, int r)
{
	int i, j, k;
	int n1 = mid - l + 1;
	int n2 = r - mid;
	int copy1[n1], copy2[n2];
	for(i = 0; i < n1 ; i++)
		copy1[i] = a[i+l];
	for(i = 0; i < n2; i++)
		copy2[i] = a[i+mid+1];
	i = j = 0;
	k = l;
	while(i < n1 && j < n2)
	{
		if(copy1[i] <= copy2[j])
		{
			a[k] = copy1[i];
			i++;
		}
		else
		{
			a[k] = copy2[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		a[k] = copy1[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		a[k] = copy2[j];
		j++;
		k++;
	}
}

void mergesortrecursive(int a[], int l, int r)
{
	if(l < r)
	{
		int mid = l + (r-l)/2;
		mergesortrecursive(a, l, mid);
		mergesortrecursive(a, mid+1, r);
		merge(a, l, mid, r);
	}
}
void mergesortiterative(int a[], int n)
{
	int i, j;
	for(i = 1; i < n; i *= 2)
	{
		for(j = 0; j < n-1 ; j+= 2*i)
		{
			int mid = min(j+i-1, n-1);
			int right = min(j+2*i-1, n-1);
			merge(a, j, mid, right);
		}
	}
}

int main()
{
	int n;
	while(true)
	{
		cout << "Enter number of elements in the array-";
		cin >> n;
		if(n>0)break;
		else
		{
			cout << "Enter a valid number of elements!" << endl;
		}
	}
	cout << "Enter the array-" << endl;
	int a[n];
	for(int i = 0;i < n; i++)
		cin >> a[i];
	cout << "1.For Recursive Sorting\n2.For Iterative Sorting" << endl;
	int key;
	while(true){
		cout << "Enter your Choice-";
		cin >> key;
		if(key == 1)
		{
			mergesortrecursive(a, 0, n-1);
			cout << "Sorted Array-" << endl;
			for(int i = 0;i < n; i++)
				cout << a[i] << " ";
			cout << endl;
			break;
		}
		else if(key == 2)
		{
			mergesortiterative(a, n);
			cout << "Sorted Array-" << endl;
			for(int i = 0;i < n; i++)
				cout << a[i] << " ";
			cout << endl;
			break;
		}
		else{
			cout << "Enter valid choice!" << endl;
			continue;
		}
	}
	cout << "Thank You!" << endl;
	return 0;
}