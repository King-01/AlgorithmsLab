	#include<iostream>
	#include<queue>
	#include<algorithm>

	using namespace std;


	int main()
	{
		cout << "Enter number of elements-";
		int weight, n;
		cin >> n;
		cout << "Enter Maximum weight that the bag can accomodate- ";
		cin >> weight;
		pair<float, float> v[n];
		priority_queue<pair<float, float>> q;
		for(int i = 0; i < n; i++ )
		{
			cout << "Enter price of item " << i+1 << endl;
			int weight1, price1;
			cin >> price1;
			cout << "Enter weight of item " << i+1 << endl;
			cin >> weight1;
			v[i].second = weight1;
			v[i].first = (price1*1.000000000000) / weight1;
			q.push(v[i]);
		}
		float weightrem = weight, price = 0;
		while(!q.empty())
		{
			pair<float, float> p1 = q.top();
			q.pop();
			if(weightrem > p1.second)
			{
				price += p1.first * p1.second;
				weightrem -= p1.second;
			}
			else
			{
				price += weightrem * p1.first;
				break;
			}
		}
		cout << "Maximum value that can be accomodated in the bag is-" << price << endl;
		return 0;
	}


	