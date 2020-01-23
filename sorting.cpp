#include<iostream>

using namespace std;

struct linklist{
	int val;
	linklist *next;
	linklist(int a){
		val = a;
		next = NULL;
	}
};

class sorts{
	private:
	int prim[101];
	linklist *head;
	public:
	sorts(){
		for(int i=0;i < 101; i++)
		{
			prim[i] = -10000;
		}
	}
	bool checker()
	{

		if(prim[0] == -10000)
		{
			cout << "Please Insert An Element!" << endl;
			return true;
		}
		return false;
	}
	void listmaker()
	{
		if(checker())return;
		head = NULL;
		linklist *temp = new linklist(prim[0]);
		head = temp;
		int  i = 1;
		linklist *ptr = head;
		while(i < 101 && prim[i] != -10000)
		{
			linklist *temp1 = new linklist(prim[i]);
			ptr->next = temp1;
			ptr = ptr->next;
			i++;
		}
		return;
	}
	void insert()
	{
		cout << "Value to Insert-";
		int val;
		cin >> val;
		for(int i = 0; i < 101; i++)
		{
			if(prim[i] == -10000)
			{
				prim[i] = val;
				cout << "Insertion Successful!" << endl;
				return;
			}
		}
		cout << "Max Insertion Limit Reached!" << endl;
		return;
	}
	void printlist()
	{
		linklist *temp = head;
		cout << "Sorted Array-" << endl;
		while(temp != NULL)
		{
			cout << temp->val << " ";
			temp = temp->next;
		}
		cout << endl;
		return;
	}
	void bubblesort()
	{
		listmaker();
		linklist *temp = head;
		linklist *temp1 = head;
		while(temp != NULL)
		{
			linklist *temp2 = temp1->next;
			if(temp2 == NULL)
			{
				temp1 = head;
				temp = temp->next;
				continue;
			}
			if(temp2->val < temp1->val)
			{
				int k = temp2->val;
				temp2->val = temp1->val;
				temp1->val = k;
			}
			temp1 = temp1->next;
		}
		printlist();
	}
	void selectionsort()
	{
		listmaker();
		linklist *temp = head;
		while(temp != NULL)
		{
			linklist *min = temp;
			linklist *nex = temp->next;
			while(nex != NULL)
			{
				if(nex->val < min->val)
					min = nex;
				nex = nex->next;
			}
			int k = min->val;
			min->val = temp->val;
			temp->val = k;
			temp = temp->next;
		}
		printlist();
	}
	void insertionsort()
	{
		listmaker();
		linklist *temp = head;
		while(temp != NULL)
		{
			linklist *temp1 = temp->next;
			if(temp1 == NULL)
			{
				break;
			}
			int k = temp1->val;
			linklist *temp2 = temp;
			if(temp1->val >= temp2->val){
				temp = temp->next;
				continue;
			}
			else
			{
				while(temp2->val > k)
				{
					temp1->val = temp2->val;
					if(temp2 == head)break;
					linklist *ko = head;
					while(temp2 != head && ko->next != temp2)
					{
						ko = ko->next;
					}
					temp1 = temp2;
					temp2 = ko;
				}
				if(temp2 == head)
				{
					if(temp2->val > k){
						temp1->val = temp2->val;
						temp2->val = k;
					}
					else temp1->val = k;
				}
			}
			temp = temp->next;
		}
		printlist();
	}
	void shellsort()
	{
		if(checker())return;
		int n = 0;
		while(prim[n] != -10000)
		{
			n++;
		}
		int a[n+1];
		for(int i = 0; i < n; i++)a[i] = prim[i];
		for(int i = n/2;i > 0; i /=2)
		{
			for(int j = i;j < n; j++)
			{
				int temp = a[j];
				int k;
				for(k = j; k >= i && a[k-i] > temp; k-=i)
				{
					a[k] = a[k-i];
				}
				a[k] = temp;
			}
		}
		cout << "Sorted Array-" << endl;
		for(int i = 0; i < n; i++)
			cout << a[i] << " ";
		cout << endl;
	}
	void radixsort()
	{
		if(checker())return;
		int n = 0;
		while(prim[n] != -10000)
		{
			n++;
		}
		int mex = 0, a[n+1];
		for(int i = 0; i < n; i++){
			a[i] = prim[i];
			mex = max(mex, prim[i]);
		}
		int output[n];
		for(int i = 1;mex/i > 0; i*=10)
		{
			int count[10] = {0};
			for(int j = 0; j < n;j++)
			{
				count[(a[j]/i)%10]++;
			}
			for(int j = 1;j < 10; j++)
				count[j] += count[j-1];
			for(int j = n-1; j >= 0; j--)
			{
				output[count[(a[j]/i)%10] - 1] = a[j];
				count[(a[j]/i)%10]--;
			}
			for(int j = 0; j < n; j++)
				a[j] = output[j]; 
		}
		cout << "Sorted Array-" << endl;
		for(int i = 0; i < n;i++)
			cout << a[i] << " ";
		cout << endl;
		return;
	}
	void show()
	{
		cout << "Array without any operations-" << endl;
		for(int i = 0;i < 101 && prim[i] != -1000; i++)
		{
			if(prim[i] == -10000)break;
			cout << prim[i] << " ";
		}
		cout << endl;
	}
	void assigner(int i)
	{
		if(i == 1)insert();
		else if(i == 2)show();
		else if(i == 3)bubblesort();
		else if(i == 4)selectionsort();
		else if(i == 5)insertionsort();
		else if(i == 6)shellsort();
		else if(i == 7)radixsort();
		else{
			cout << "Invalid Input" << endl;
		}
		return;
	}
};




int main()
{
	int input;
	sorts s;
	cout << "--------------------Welcome--------------------" << endl;
	cout <<"Choose one of the following operations:" << endl;
	cout << "1. Insert." << endl;
	cout << "2. Show the entered elements." << endl;
	cout << "3. Sort usnig Bubble Sort." << endl;
	cout << "4. Sort using Selection Sort." << endl;
	cout << "5. Sort using Insertion Sort." << endl;
	cout << "6. Sort using Shell Sort." << endl;
	cout << "7. Sort using Radix Sort." << endl;
	cout << "8. Quit." << endl;
	while(1)
	{
		cin >> input;
		if(input == 8)break;
		else
		{
			s.assigner(input);
		}
		cout << "Select Again-";
	}
	cout << "Thank You!" << endl;
	return 0;
}