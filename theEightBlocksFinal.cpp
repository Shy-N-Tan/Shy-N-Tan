#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<sstream>
#include<chrono>
//decisionMaking is intelligent direction identifier
//decisionMaking2 is intelligent preferrential direction identifier
using namespace std;
using namespace std::chrono;
char temp,lastMove,x;
int a=2,b=2,r,c,i,j,p=0,q=0;
char arr[3][3]={{'5', '4', '7'}, {'2', '3', '1'}, {'8', '6', ' '}};
int diffi,diffj,diffi1,diffj1;
int vi,vj;
bool movementMatrix(int vi,int vj) //the matrix on which the elements are allowed to move
{
		if(x=='1'||x=='3')
		return true;
	else if(x=='2')
	{
		if(vi!=0&&vj!=0)
		return true;
		else return false;
	}
	else if(x=='4')
	{
		if(vi>0)
		return true;
		else return false;
	}
	else if(x=='5')
	{
		if(vi>0&&vj!=1)
		return true;
		else return false;
	}
	else if(x=='6')
	{
		if(vj>0)
		return true;
		else return false;
	}
}
int absoluteDiff(int f,int g)
{
	if(f>g)
	return (f-g);
	else
	return (g-f);
}
int output()
{
	//	system("CLS");
		cout<<"\n";
			for(int k=0;k<3;k++)
		{
			for(int l=0;l<3;l++)
			{
			cout<<arr[k][l]<<" ";
			}
			cout<<"\n";
		}
	return 0;
}
int down()
{
	vi=a-1;vj=b;
	if(movementMatrix(vi,vj)==true)
	{
		temp=arr[a-1][b];
	arr[a-1][b]=arr[a][b];
	arr[a][b]=temp;
	a--;
	cout<<"\ndown";
	output();
	lastMove='s';
	diffi=absoluteDiff(i,p);
	diffj=absoluteDiff(j,q);
	}
	else return 0;
	return 0;
}

int left()
{
	vi=a;vj=b+1;
	if(movementMatrix(vi,vj)==true)
	{
	temp=arr[a][b+1];
	arr[a][b+1]=arr[a][b];
	arr[a][b]=temp;
	b++;
	cout<<"\nleft";
	output();
	lastMove='a';
	diffi=absoluteDiff(i,p);
	diffj=absoluteDiff(j,q);
	}
	else return 0;
	return 0;
}

int up()
{
	vi=a+1;vj=b;
	if(movementMatrix(vi,vj)==true)
	{
	temp=arr[a+1][b];
	arr[a+1][b]=arr[a][b];
	arr[a][b]=temp;
	a++;
	cout<<"\nup";
	output();
	lastMove='w';
	diffi=absoluteDiff(i,p);
	diffj=absoluteDiff(j,q);
	}
	else return 0;
	return 0;
}

int right()
{
	vi=a;vj=b-1;
	if(movementMatrix(vi,vj)==true)
	{
	temp=arr[a][b-1];
	arr[a][b-1]=arr[a][b];
	arr[a][b]=temp;
	b--;
	cout<<"\nright";
	output();
	lastMove='d';
	diffi=absoluteDiff(i,p);
	diffj=absoluteDiff(j,q);
	}
	else return 0;
	return 0;
}

int decisionMaking()
{
	if(a==(i+1)&&b==j)
	{
		i++;down();
	}
	else if((a==(i-1))&&b==j)
	{
		i--;up();
	}
	else if(a==i&&(b==(j-1)))
	{
		j--;left();
	}
	else if(a==i&&(b==(j+1)))
	{
		j++;right();
	}
	else
	return 0;
	//output();
	
	return 0;
}

int zero(int y)
{
	//for spaces, increase to 1
	y++;
	return y;
	//for index, reduce to 0
}
int two(int y)
{
	//for spaces, reduce to 1
	y--;
	return y;
	//for indices, increase to 2
}
int checkRow()
{
	if(a==2)
	return two(a);
	else if(a==1)
	return two(a);
	else
	return zero(a);
}

int checkColumn()
{
	if(b==2)
	return two(b);
	else if(b==1)
	return two(b);
	else
	return zero(b);
}
int checkRow1()
{
	if(a==2)
	return two(a);
	else if(a==1)
	return zero(a);
	else
	return zero(a);
}
int checkColumn1()
{
	if(b==2)
	return two(b);
	else if(b==1)
	return zero(b);
	else
	return zero(b);
}
bool cornerSpace()
{
	if(a==2&&b==2)
	return true;
	else if(a==2&&b==0)
	return true;
	else if(a==0&&b==0)
	return true;
	else if(a==0&&b==2)
	return true;
	else return false;
}
bool edgeSpace()
{
	if(a==1&&b==0)
	return true;
	else if(a==0&&b==1)
	return true;
	else if(a==1&&b==2)
	return true;
	else if(a==2&&b==1)
	return true;
	else return false;
}
bool centerSpace()
{
	if(a==1&&b==1)
	return true;
	else return false;
}

bool isItMovable()
{
	int p1,p2,q1,q2;
	p1=checkRow();
	q1=checkColumn();
	p2=checkRow1();
	q2=checkColumn1();
	
	if(cornerSpace()==true)
	{
		if((i==p1&&j==b)||(i==a&&j==q1))
		return true;
		else return false;
	}
	else if(edgeSpace()==true)
	{
		if(b==1)
		{
			if((i==1&&j==1)||(i==a&&j==q1)||(i==a&&j==q2))
			return true;
			else return false;
		}
		else if(a==1)
		{
			if((i==1&&j==1)||(i==p2&&j==b)||(i==p1&&j==b))
			return true;
			else return false;
		}
		else return false;
	}
	else
	{
		if((i==p1&&j==b)||(i==a&&j==q1)||(i==p2&&j==b)||(i==a&&j==q2))
		return true;
		else return false;//a=1
	}
}


char whichSide()
{
	if(a==(i+1)&&b==j)
	return 's';
	else if((a==(i-1))&&b==j)
	return 'w';
	else if(a==i&&(b==(j-1)))
	return 'a';
	else if(a==i&&(b==(j+1)))
	return 'd';
	else
	return 0;
}

int target()
{
	switch(x)
	{
		case '1': p=0; q=0; break;
		case '2': p=0; q=1; break;
		case '3': p=0; q=2; break;
		case '4': p=1; q=0; break;
		case '5': p=1; q=1; break;
		case '6': p=1; q=2; break;
		case '7': p=2; q=0; break;
		case '8': p=2; q=1; break;
	}
	return 0;
}

char isItPreferrable()
{
	//if preferrable, then use decisionMaking()
	//aim is to try and reach the target
	target();
	if(i>p&&j>q)
	return 'w';
	else if(i>p&&j<q)
	return 'w';
	else if(i<p&&j>q)
	return 's';
	else if(i<p&&j<q)
	return 's';
	else if(i==p&&j>q)
	return 'a';
	else if(i==p&&j<q)
	return 'd';
	else if(i>p&&j==q)
	return 'w';
	else if(i<p&&j==q)
	return 's';
	else return 'x';
}
char isItPreferrable1()
{
	//if preferrable, then use decisionMaking()
	//aim is to try and reach the target
	target();
	if(i>p&&j>q)
	return 'a';
	else if(i>p&&j<q)
	return 'd';
	else if(i<p&&j>q)
	return 'a';
	else if(i<p&&j<q)
	return 'd';
	else if(i==p&&j>q)
	return 'a';
	else if(i==p&&j<q)
	return 'd';
	else if(i>p&&j==q)
	return 'w';
	else if(i<p&&j==q)
	return 's';
	else return 'x';
}

bool decisionMaking2()//means it is aiming at moving 1 according to its conditions
{
	char side;
	side=whichSide();
	if((side==isItPreferrable())||(side==isItPreferrable1()))
	{
		decisionMaking();
		return true;
	}
	else
	return false;
}

int uDown(char z)//to not disturb the preferrence
{
		switch(z)
		{
			case 'a':if(a==1&&b==2)
					{
						up();
						right();
						right();
						down();
					}
					else if(a==0&&b==2)
					{
						up();
						right();
						right();
						down();
					}
					
					else if(a==2&&b==2)
					{
						down();
						right();
						right();
						up();
					}
					
					break;
			case 'd': if(a==1&&b==0)
					{
						up();
						left();
						left();
						down();
					}
					else if(a==0&&b==0)
					{
						up();
						left();
						left();
						down();
					}
				
					else if(a==2&&b==0)
					{
						down();
						left();
						left();
						up();
					}
					break;
			case 'w':if(a==2&&b==1)
					{
						left();
						down();
						down();
						right();
					}
					else if(a==2&&b==0)
					{
						left();
						down();
						down();
						right();
					}
					else if(a==2&&b==2)
					{
						right();
						down();
						down();
						left();
					}
					break;
			case 's':if(a==0&&b==1)
					{
						left();
						up();
						up();
						right();
					}
					else if(a==0&&b==0)
					{
						left();
						up();
						up();
						right();
					}
					else if(a==0&&b==2)
					{
						right();
						up();
						up();
						left();
					}
					break;
		}
		return 0;
}
int moveBack1()
{
	switch(lastMove)
	{
		case 'w': down(); break;
		case 's': up(); break;
		case 'a': right(); break;
		case 'd': left(); break;
	}	
	return 0;
}

bool breakPreferrence()
{
	//difference between target and present tile should be reduced or remain the same. it can't increase
	//if ((y==isItPreferrable())||(y==isItPreferrable1()))
	
	for(int k=0;k<3;k++)
		{
			for(int l=0;l<3;l++)
			{
				if(x==arr[k][l])
				{
					diffi1=absoluteDiff(k,p);
					diffj1=absoluteDiff(l,q);
				}
			}
		}
	if((diffi1<diffi)&&(diffj1<diffj)||(diffi1==diffi)&&(diffj1==diffj)||(diffi1<diffi)&&(diffj1==diffj)||(diffi1==diffi)&&(diffj1<diffj))
	return false;
	else return true;
}
int moveSpace()//the one block in each direction, it's a part of the uDown
{
	if(a>r&&b>c)
	{
			right();
			if(breakPreferrence()==true)
			{
				moveBack1();
				down();
				right();
				if(breakPreferrence()==true)
				moveBack1();
			}
			else
			{
				down();
				if(breakPreferrence()==true)
			moveBack1();
			//down();
			//right();
			}
		
		
	}	
	else if(a>r&&b<c)
	{
		left();
		if(breakPreferrence()==true)
		{
			moveBack1();
			down();
			left();
			if(breakPreferrence()==true)
			moveBack1();
		}
		else
		{
			down();
		if(breakPreferrence()==true)
			moveBack1();
		}
		
	}
	else if(a<r&&b>c)
	{
		right();
		if(breakPreferrence()==true)
		{
			moveBack1();
			up();
			right();
			if(breakPreferrence()==true)
			moveBack1();
		}
		else 
		{
			up();
		if(breakPreferrence()==true)
			moveBack1();
		}
	}
	else if(a<r&&b<c)
	{
		left();
		if(breakPreferrence()==true)
		{
			moveBack1();
			up();
			left();
			if(breakPreferrence()==true)
			moveBack1();
		}
		else 
		{
			up();
		if(breakPreferrence()==true)
			moveBack1();
		}
	}
	
	else if(a==r&&b>c)
	{
		right();
		if(breakPreferrence()==true)
		{
			moveBack1();
			uDown('a');
		}
	}
	else if(a==r&&b<c)
	{
		left();
		if(breakPreferrence()==true)
		{
			moveBack1();
			uDown('d');
		}
	}
	else if(a>r&&b==c)
	{
		down();
		if(breakPreferrence()==true)
		{
			moveBack1();
			uDown('w');
		}
	}
	else if(a<r&&b==c)
	{
		up();
		if(breakPreferrence()==true)
		{
			moveBack1();
			uDown('s');
		}
		
	}
	return 0;
}

targetSpace()
{
	//space to the left or up for 1
	switch(x)
	{
		case '1': if(j>0) //giving preference to the left over up
				{
					r=i;c=j-1;
				}
				else if(i>0)
				{
					r=i-1;c=j;
				}
				else
				cout<<"1 has reached its place";
				break;
		case '2':if(i>0)
				{
					r=i-1;c=j;
				}
				else if(j!=2)
				{
					r=i;c=1;
				}
				break;
		case '4': if(j>0) //giving preference to the left over up
				{
					r=i;c=j-1;
				}
				else if(i>1)
				{
					r=i-1;c=j;
				}
				break;
		case '5':if(i>0)
				{
					r=i-1;c=j;
				}
				else if(j==0||j==2)
				{
					r=i;c=1;
				}break;
				
	}
	
}
int makeSpace()
{
	//create spaces without disturbing the preferrence of the tile choosing the shortest path possible
	//r=a;c=b;
	targetSpace();
	moveSpace();
	return 0;
}
int possibleChoices()
{
	int f=1,f1,k=49;
	bool yon;
	x='1';
	while(x<='2')
	{
		f1=0;
		for(int k=0;k<3;k++)
		{
			for(int l=0;l<3;l++)
			{
				if(x==arr[k][l])
				{
					auto start=high_resolution_clock::now();
					i=k;j=l;
					target();
					diffi=absoluteDiff(i,p);
					diffj=absoluteDiff(j,q);
					if((absoluteDiff(i,p)==0)&&(absoluteDiff(j,q)==0))
					{
						output();
						cout<<"Target reached";
						auto stop=high_resolution_clock::now();
						auto duration=duration_cast<microseconds>(stop-start);
						cout<<"\nTime taken: "<<duration.count()<<" microseconds";
						x++;
						f1=1;break;
					}
					else
					{
						if(isItMovable()==true)
						{
						yon=decisionMaking2();
						if (yon==false)
						{
							makeSpace(); f1=1;break;
						}
						else
							{
								f1=1;break;
							}
						}
					else
						{
						makeSpace();f1=1;break;
						}
					}
					
				}
					
			}
			if(f1==1)
			break;
		}
	}
}
int main()
{
	int n,f=1;
	char seq;
	cout<<"THE 8 TILES GAME!\n";
	cout<<"Enter side of square. Available value is 3.\n";
	cin>>n;
	switch(n)	
	{
		case 3: 
	/*	int ar[8],a,num;
		//
		char x;
		for(int k=0;k<8;k++)
	{
		
		a=rand()%8 + 1;//random number generating function, 1 being lower bound, 8 being upper bound
		ar[k]=a;
	//	cout<<ar[i];
		for(int l=0;l<i;l++)
		{
			if(ar[l]==a)
			{
				k--; break;
			}
		}
	}
	for(int k=0;k<8;k++)
	num=num*10+ar[i];
	ostringstream str1; 
    str1 << num;
    string thenum= str1.str(); 
	char ar1[8]; 
	strcpy(ar1, thenum.c_str()); 
	for(int k=0;k<8;k++)
	cout<<ar1[k]<<" ";
	for(int i=0;i<3;i++)
	{
		
		for(int j=0;j<3;j++)
		{
			if(i==2&&j==2)
			arr[i][j]=' ';
			else
			arr[i][j]=ar1[(3*i)+j];
		}
	}*/
	//char arr[3][3]={{'2', '4', '7'}, {'5', '3', '1'}, {'8', '6', ' '}};
	//do
	//{
		output();
		possibleChoices();
		
	/*	for(int k=49;k<51;k++)
		{
			x=(char)k;
			possibleChoices();
			cout<<"\nyes";
		}*/
		
	//	cout<<"\n";
		/*This is the game playing part
		/*cin>>seq;
		switch(seq)
		{
			case 's': down(); break;
			case 'a': left(); break;
			case 'w': up(); break;
			case 'd': right(); break;
			//
			case 'x': f=0; break;
			default: f=0; cout<<"Error";
		}*/
	
	//}while(f==1);
}
	return 0;
	}


















