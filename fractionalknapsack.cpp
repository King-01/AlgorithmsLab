#include<iostream>
#include<queue>
using namespace std;

struct data{
    float a;
    float b;

    data(float a, float b)
        : a(a), b(b)
    {
    }
};
struct compare{
    bool operator()(data const& p1, data const& p2)
    {
        return ((p1.a)(p2.b))<((p2.a)(p1.b));
    }
};
int main()
{
    priority_queue<data, vector<data>, compare> e;
    int n;
    cin>>n;
    float w,price=0;
    cin>>w;
    for(int i=0;i<n;i++)
    {
        float f,g;
        cin>>f>>g;
        e.push(data(f,g));
    }
    while (!e.empty() && w>0) {
        data p = e.top();
        e.pop();
        if(p.b<=w)
        {
           price+=p.a;
           w-=p.b;
        }
        else
        {
            price+=(w*(p.a))/(p.b);
            w=0;
        }
    }
    cout<<price;
    return 0;
}