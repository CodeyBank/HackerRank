#include <iostream>
#include <stdint.h>

using namespace std;

class Box {
    public:
        int getLength() {return l;} // Return box's length
        int getBreadth () {return b;} // Return box's breadth
        int getHeight () {return h;}  //Return box's height
        long long CalculateVolume() {return (long long)l*b*h;} // Return the volume of the box

        // Default constructor
        Box(){
            l = 0;
            b = 0;
            h = 0;
        }

        // Copy constructor
        Box (const Box& B){
            this->l = B.l;
            this->b = B.b;
            this->h = B.h;
        }

        // delegated constructor
        Box(int length, int breadth, int height)
            : l(length), b(breadth), h(height){}

    bool operator<(const Box& B){
        if(this->l < B.l){ return true;}
        if((this->b < B.b) && (this->l == B.l)){ return true;}
        if ((this->h < B.h)&&(this->b == B.b)&&(this->l == B.l)){return true;}

        return false;
    }

    // standard output redirection
    friend ostream& operator<<(ostream& os, const Box& B);

    private:
        int l, b, h;

};

ostream& operator<<(ostream& os, const Box& B){
    os<<B.l<<" "<<B.b<<" "<<B.h;
    return os;
}

void check2()
{
	int n;
	cin>>n;
	Box temp;
	for(int i=0;i<n;i++)
	{
		int type;
		cin>>type;
		if(type ==1)
		{
			cout<<temp<<endl;
		}
		if(type == 2)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			temp=NewBox;
			cout<<temp<<endl;
		}
		if(type==3)
		{
			int l,b,h;
			cin>>l>>b>>h;
			Box NewBox(l,b,h);
			if(NewBox<temp)
			{
				cout<<"Lesser\n";
			}
			else
			{
				cout<<"Greater\n";
			}
		}
		if(type==4)
		{
			cout<<temp.CalculateVolume()<<endl;
		}
		if(type==5)
		{
			Box NewBox(temp);
			cout<<NewBox<<endl;
		}

	}
}

int main()
{
    check2();
    return 0;
}
