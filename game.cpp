#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <iomanip>
#include <fstream>
#include <unistd.h>
#include <cmath>
#include <conio.h>
#include <vector>
#define max 100
struct tai_khoan
{
	char accout[100];
	char password[100];
 }a[100],b[100];
using namespace std;
int dang_ki(int &n,int &m);
int dang_nhap(int &n,int &m);
int doan_so(int so);
int do_min(int cap_ma_tran);
void thoat_me_cung(int n);
void day_thung(int n); 
int main()
{
	int n=0,m=0;
	int x1=0;
	do
	{
		if(x1==2)
			{
				break;
			}
		system("cls");
		cout<<"+-----------+             +-------------+\n";
		cout<<"| 1.Dang Ki |             | 2.Dang Nhap |\n";
		cout<<"+-----------+             +-------------+\n";
		cout<<"Nhap Lenh: "; cin>>x1;
		switch (x1)
		{
			case 1:
				dang_ki(n,m);
				break;
			case 2:
				if(dang_nhap(n,m)==-1)
				return -1;
		}
	}
	while(-1);
	int x2;
    do       
    {
    system("cls");
    cout<<"     Moi Ban chon Game\n";
    cout<<"+-------------------------------+\n";
    cout<<"| 1.Doan So                     |\n";
    cout<<"+-------------------------------+\n";
    cout<<"| 2.Do Min                      |\n";
    cout<<"+-------------------------------+\n";
    cout<<"| 3.CHAY TRON KHOI ME CUNG      |\n";
    cout<<"+-------------------------------+\n";
    cout<<"| 4.Day Thung                   |\n";
    cout<<"+-------------------------------+\n";
    cout<<"| 5.EXIT                        |\n";
    cout<<"+-------------------------------+\n";
	cout<<"nhap lenh :"; cin>>x2;
	system("cls");
	int so;
	int cap_ma_tran;
	switch(x2)
		{
			case 1:	
				doan_so(so);
				break;
			case 2:
				cout<<"Nhap cap Ma tran: "; cin>>cap_ma_tran;
				do_min(cap_ma_tran);
				break;
			case 3:
				cout<<"Nhap cap Ma tran: "; cin>>cap_ma_tran;
				thoat_me_cung(cap_ma_tran);
				break;
			case 4:
				cout<<"Nhap cap Ma tran: "; cin>>cap_ma_tran;
				day_thung(cap_ma_tran);
				break;
	    	case 5:
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
				cout<<right<<setw(70)<<"Cam On Ban Da Tham Gia!!!";
				cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
	            return 0;
		}		
   }while(-1);
}
int dang_ki(int &n,int &m)
{
	char str[20];
	n=0, m=0;
	fstream f("game.txt",ios::in);
	f>>n; f>>m; f.getline(str,10);
	for(int i=0;i<n;i++)
		{
			f.getline(a[i].accout,30);
			f.getline(b[i].password,30);
		}
	f.close();
	char c[100];
	system("cls");
	cout<<"accout: "; fflush(stdin); gets(a[n].accout); n++;
	cout<<"passwowd: "; fflush(stdin); gets(b[m].password); m++;
	cout<<"nhap lai password: "; fflush(stdin); gets(c); 
	if(strcmp(b[n-1].password,c)!=0)
		{
			for(int i=3;i>=0;i--)
			{
				system("cls");
				cout<<"Dang Ki That Bai!\n";
				cout<<"Xin Vui Long Cho "<<i<<endl; sleep(1);
			}
		return 0;
		}
	for(int i=0;i<n-1;i++)
		{
			if(strcmp(a[n-1].accout,a[i].accout)==0)
				{
					for(int k=3;k>=0;k--)
					{
						system("cls");
						cout<<"Dang Ki That Bai!\n";
						cout<<"Accout: \""<<a[n-1].accout<<"\" Da Ton Tai\n";
						cout<<"Xin Vui Long Cho "<<k<<endl; sleep(1);
				    }
					return 0;
				}
		}
	for(int i=3;i>=0;i--)
		{
			system("cls");
			cout<<"Accout \""<<a[n-1].accout<<"\" Da Duoc Dang Ki Thanh Cong!\n";
			cout<<"Xin Vui Long Doi "<<i<<endl; sleep(1);
		}

	fstream f1("game.txt",ios::out);
	f1<<n<<"\n";
	f1<<m<<"\n";
	for(int i=0;i<n;i++)
	{
		f1<<a[i].accout<<"\n";
		f1<<b[i].password<<"\n";
	}
	f1.close();

	fstream f2("game1.txt",ios::out);
	f2<<"so luong tai khoan: "<<n<<"\n";
	f2<<"so luong mat khau : "<<m<<"\n";
	f2<<"thong tin accout da duoc dang ki\n";
	f2<<"+---+------------------------------+\n";
	for(int i=0;i<n;i++)
    	{
			f2<<"|"<<left<<setw(3)<<i+1<<"|accout   :"<<left<<setw(20)<<a[i].accout<<"|\n";
			f2<<"|"<<left<<setw(3)<<"   |password :"<<left<<setw(20)<<b[i].password<<"|\n";
			f2<<"+---+------------------------------+\n";
	    }
	f.close();
}
int dang_nhap(int &n,int &m)
{
	char accout[100];
	char password[100];
	char str[100];
	int dem=0;
	fstream f("game.txt",ios::in);
	f>>n;
	f>>m;
	f.getline(str,5);
	for(int i=0;i<n;i++)
		{
			f.getline(a[i].accout,100);
			f.getline(b[i].password,100);
		}
	f.close();
	do
	{
		system("cls");
		if(dem>0)
			{
				cout<<"Ban Da Nhap Sai Accout OR Password\n";
				cout<<"Moi Ban Nhap Lai\n\n";
			}
		cout<<"accout: ";	fflush(stdin); gets(accout);
	    cout<<"password: ";	fflush(stdin); gets(password);
			for(int i=0;i<n;i++)
	    	{
	    		if(strcmp(accout,a[i].accout)==0 && strcmp(password,b[i].password)==0)
		        {
		        	for(int i=3;i>=0;i--)
					{
						system("cls");
						cout<<"Dang Nhap Thanh Cong!\n";
						cout<<"Xin Vui Long Doi "<<i<<endl; sleep(1);
					}
	            	return 0;
	         	}
	     	}
		dem++;
    	if(dem==3)
    		{
    			system("cls");
        		cout<<"Ban Da Nhap Sai Accout and Password Nhieu Lan Moi Ban Thoat Khoi Chuong Trinh!";
				return -1;
			}
	}
	while(-1);
}
/*---------------------------------------------------------------------------------------*/
int doan_so(int so){
		srand(time(NULL));
			   	int dem=0;
			   	system("cls");
			   	int c=rand()%100+1;
			   	cout<<right<<setw(73)<<"DOAN SO NGAU NHIEN TU 1-100 \n";
			   	cout<<right<<setw(50)<<"Ban Chi Doan Duoc 7 lan\n";
		     	do
				{
				  cout<<"nhap so : "; cin>>so;
				  if(so>c)
				    cout<<"so ban vua nhap > so cua may \n\n";
				  else if(so<c)
				   cout<<"so ban vua nhap < so cua may \n\n";
				  else
				  	{
					for(int i=3;i>=0;i--)
						{
							system("cls");
							cout<<"Chuc Mung Ban Da Doan Trung So Cua may la \""<<c<<"\"\n";
							cout<<"Xin Vui Long Doi "<<i<<endl; sleep(1);
						}
					return 0;
				    }
				  dem++;
				  if(dem==7)
					  {
					  	for(int i=3;i>=0;i--)
							{
							system("cls");
						  	cout<<"Ban Da Thua so cua may la "<<c<<"\n";
						  	cout<<"Xin Vui Long Doi "<<i<<endl; sleep(1);
						    }
						return -1;
					  }
				}
				while(c!=so);
}
int do_min(int cap_ma_tran)
{
	int ma_tran[max][max];
	int i,j;
	for(int i=0;i<cap_ma_tran;i++)//khoi tao gia tri tat ca phan tu trong ma tran =0
		{
			for(int j=0;j<cap_ma_tran;j++)
				{
					ma_tran[i][j]=0;
					cout<<"# ";
				}
				cout<<endl;
		}
	int so_min=0;
	if(cap_ma_tran%2!=0)
		{
			so_min=(int)(cap_ma_tran/2)*cap_ma_tran;
		}
	if(cap_ma_tran%2==0)
		{
			so_min=(pow(cap_ma_tran,2)/2)-(cap_ma_tran/2);
		}
	if(cap_ma_tran<4)
		{
			so_min=cap_ma_tran;
		}
	srand(time(NULL));
	for(int t=0;t<so_min;t++) 
		{
			i=rand()%cap_ma_tran;
        	j=rand()%cap_ma_tran;
        	ma_tran[i][j]=-1;
		}
	int dem;
		for(int i=0;i<cap_ma_tran;i++) 
		{
			for(int j=0;j<cap_ma_tran;j++)
				{
					if(ma_tran[i][j]==0)
						{
							dem=0;
							if(ma_tran[i-1][j-1]==-1)
							dem++;
							if(ma_tran[i-1][j]==-1)
							dem++;
							if(ma_tran[i-1][j+1]==-1)
							dem++;
							if(ma_tran[i][j-1]==-1)
							dem++;
							if(ma_tran[i][j+1]==-1)
							dem++;
							if(ma_tran[i+1][j-1]==-1)
							dem++;
							if(ma_tran[i+1][j]==-1)
							dem++;
							if(ma_tran[i+1][j+1]==-1)
							dem++;
							ma_tran[i][j]=dem;
						}
				}
	    }
	    int x[max],y[max];
	    int a=0,b=0;
	    int count=0;
	do
		{
			cout<<"Nhap toa Do (VD Hang 1 Cot 2: 1 2): "; cin>>i>>j;
			count++;//khi chay vong lap do while thi count cong them 1 
			system("cls");
			x[a]=i-1; a++;//luu toa do vua nhap vao mang  
			y[b]=j-1; b++;//luu toa do vua nhap vao mang 
					if(ma_tran[i-1][j-1]==-1)
						{
							for(int k=3;k>=0;k--)
							{
								system("cls");
							for(int i=0;i<cap_ma_tran;i++)
								{
									for(int j=0;j<cap_ma_tran;j++)
										{
											if(ma_tran[i][j]==-1)
												{
													cout<<"x ";
												}
											else
											cout<<ma_tran[i][j]<<" ";
										}
										cout<<endl;
								}
									cout<<"Rat Tiec Ban Da Khong Hoan Thanh Tro choi!\n";
									cout<<"Xin Vui Long Doi "<<k<<endl; sleep(1);
								}
							return -1;
						}
					else
						{
							for(int i=0;i<cap_ma_tran;i++)//duyet mang 
								{
									for(int j=0;j<cap_ma_tran;j++)
										{
											dem=0;
											for(int k=0;k<a;k++)
												{
													if(i==x[k]&&j==y[k])//neu phan tu i j ma bang phan tu mang vua nhap thi in ra man hinh
														{
															cout<<ma_tran[i][j]<<" ";
															dem++;//chay xong vong lap nay "*" thi dem=1
														}
												}
											if(dem!=1)//neu bien dem khac 1(tuc khong chay vong lap tren) thi in ra dau #
												{
													cout<<"# ";
												}
											if(count==pow(cap_ma_tran,2)-so_min)//khi count = (cap_ma_tran)^2 - so min co trong ma tran. thi mo het ma tran ra va chuc mng nguoi choi
												{
													for(int k=3;k>=0;k--)
													{
														system("cls");
														for(int i=0;i<cap_ma_tran;i++)
															{
																for(int j=0;j<cap_ma_tran;j++)
																	{
																		if(ma_tran[i][j]==-1)
																			{
																				cout<<"x ";
																			}
																		else
																			cout<<ma_tran[i][j]<<" ";
																	}
																cout<<endl;
															}
														cout<<"Chuc Mung Da Hoan Thanh Xuat Sac Tro choi!\n";
														cout<<"Xin Vui Long Doi "<<k<<endl; sleep(1);
													}
														return 0;
												}
										}
									cout<<endl;//chay xong 1 hang thi xuong dong de chay hang tiep theo
								}
						}
		}
	while(-1); 
}
void thoat_me_cung(int n)
{
	int me_cung[max][max];
	int x,y;
	int h,c;
	int tn=2,dem=0;
	for(int i=15;i<=n;i++)
		{
			dem++;
			if(dem==5)
				{
					tn++;
					dem=0;
				}
		}
	for(int j=0;j<n;j++)
		{ 
			for(int i=0;i<n;i++)
				{
					me_cung[i][j]=-1;
				}
		}
	x=rand()%(n-2)+1;
	y=rand()%(n-2)+1;
	me_cung[x][y]=1;// vi tri nguoi
	int cot=y, hang=x;
	int t=rand()%4+1;
	if(t==1)//cong thoat
		{
			x=rand()%n;
			me_cung[x][0]=2;
		}
	if(t==2)
		{
			x=rand()%n;
			me_cung[x][n-1]=2;
		}
	if(t==3)
		{
			y=rand()%n;
			me_cung[0][y]=2;
		}
	if(t==4)
		{
			y=rand()%n;
			me_cung[n-1][y]=2;
		}
	/*---------------------*/
	x=n-2,y=n-2;
	if(me_cung[0][0]==2)
		{
			for(int j=0;j<n-1;j++)
				{
					if(me_cung[1][j]==1)
						{
							continue;
						}
					me_cung[1][j]=0;
				}
			for(int i=1;i<n-1;i++)
				{
					if(me_cung[i][n-2]==1)
						{
							continue;
						}
					me_cung[i][n-2]=0;
				}
			do
			{
				if(me_cung[n-2][y]==1)
					{
						break;
					}
				me_cung[n-2][y]=0;
				y--;
			}
			while(y!=cot);
			do
			{
				if(me_cung[x][cot]==1)
						{
							break;
						}
				me_cung[x][cot]=0;
				x--;
			}
			while(x!=hang);
			for(int z=0;z<tn;z++)
				{
					h=rand()%(n-2)+1;
					c=rand()%(n-2)+1;
					for(int i=1;i<n-1;i++)
						{
							if(me_cung[h][i]==1||me_cung[i][c]==1)
								{
									continue;
								}
							me_cung[h][i]=0;
							me_cung[i][c]=0;
						}
				}
		}
	x=1,y=1;
	if(me_cung[n-1][n-1]==2)
		{
			for(int i=1;i<n;i++)
				{
					if(me_cung[i][n-2]==1)
						{
							continue;
						}
					me_cung[i][n-2]=0;
				}
			for(int j=1;j<n-1;j++)
				{
					if(me_cung[1][j]==1)
						{
							continue;
						}
					me_cung[1][j]=0;
				}
			do
			{
				if(me_cung[x][1]==1)
						{
							break;
						}
				me_cung[x][1]=0;
				x++;
			}
			while(x!=hang);
			do
			{
				if(me_cung[hang][y]==1)
						{
							break;
						}
				me_cung[hang][y]=0;
				y++;
			}
			while(y!=cot);
			for(int z=0;z<tn;z++)
				{
					h=rand()%(n-2)+1;
					c=rand()%(n-2)+1;
					for(int i=1;i<n-1;i++)
						{
							if(me_cung[h][i]==1||me_cung[i][c]==1)
								{
									continue;
								}
							me_cung[h][i]=0;
							me_cung[i][c]=0;
						}
				}
		}
	x=n-2,y=1;
	if(me_cung[0][n-1]==2)
		{
			for(int j=1;j<n;j++)
				{
					if(me_cung[1][j]==1)
						{
							continue;
						}
					me_cung[1][j]=0;
				}
			for(int i=1;i<n-1;i++)
				{
					if(me_cung[i][1]==1)
						{
							continue;
						}
					me_cung[i][1]=0;
				}
			do
			{
				if(me_cung[n-2][y]==1)
						{
							break;
						}
				me_cung[n-2][y]=0;
				y++;
			}
			while(y!=cot);
			do
			{
				if(me_cung[x][cot]==1)
						{
							break;
						}
				me_cung[x][cot]=0;
				x--;
			}
			while(x!=hang);
			for(int z=0;z<tn;z++)
				{
					h=rand()%(n-2)+1;
					c=rand()%(n-2)+1;
					for(int i=1;i<n-1;i++)
						{
							if(me_cung[h][i]==1||me_cung[i][c]==1)
								{
									continue;
								}
							me_cung[h][i]=0;
							me_cung[i][c]=0;
						}
				}
		}
	x=1,y=n-2;
	if(me_cung[n-1][0]==2)
		{
			for(int i=1;i<n;i++)
				{
					if(me_cung[i][1]==1)
						{
							continue;
						}
					me_cung[i][1]=0;
				}
			for(int j=1;j<n-1;j++)
				{
					if(me_cung[1][j]==1)
						{
							continue;
						}
					me_cung[1][j]=0;
				}
			do
			{
				if(me_cung[x][n-2]==1)
						{
							break;
						}
				me_cung[x][n-2]=0;
				x++;
			}
			while(x!=hang);
			do
			{
				if(me_cung[hang][y]==1)
					{
						break;
					}
				me_cung[hang][y]=0;
				y--;
			}
			while(y!=cot);
			for(int z=0;z<tn;z++)
				{
					h=rand()%(n-2)+1;
					c=rand()%(n-2)+1;
					for(int i=1;i<n-1;i++)
						{
							if(me_cung[h][i]==1||me_cung[i][c]==1)
								{
									continue;
								}
							me_cung[h][i]=0;
							me_cung[i][c]=0;
						}
				}
		}
	for(int h1=1;h1<n-1;h1++)
	{
		if(me_cung[0][h1]==2)
			{
				for(int i=1;i<n-1;i++)
					{
						if(me_cung[i][h1]==1)
							{
								continue;
							}
						me_cung[i][h1]=0;
					}
				for(int j=1;j<h1;j++)
					{
						if(me_cung[n-2][j]==1)
							{
								continue;
							}
						me_cung[n-2][j]=0;
					}
				x=n-2,y=1;
				do
					{
						if(me_cung[x][1]==1)
							{
								break;
							}
						me_cung[x][1]=0;
						x--;
					}
				while(x!=hang);
				do
					{
						if(me_cung[hang][y]==1)
							{
								break;
							}
						me_cung[hang][y]=0;
						y++;
					}
				while(y!=cot);
				for(int z=0;z<tn;z++)
				{
					h=rand()%(n-2)+1;
					c=rand()%(n-2)+1;
					for(int i=1;i<n-1;i++)
						{
							if(me_cung[h][i]==1||me_cung[i][c]==1)
								{
									continue;
								}
							me_cung[h][i]=0;
							me_cung[i][c]=0;
						}
				}
			}
	}
	for(int h2=1;h2<n-1;h2++)
		{
			if(me_cung[n-1][h2]==2)
				{
					for(int i=1;i<n-1;i++)
					{
						if(me_cung[i][h2]==1)
							{
								continue;
							}
						me_cung[i][h2]=0;
					}
				for(int j=1;j<h2;j++)
					{
						if(me_cung[1][j]==1)
							{
								continue;
							}
						me_cung[1][j]=0;
					}
				x=1,y=1;
				do
					{
						if(me_cung[x][1]==1)
							{
								break;
							}
						me_cung[x][1]=0;
						x++;
					}
				while(x!=hang);
				do
					{
						if(me_cung[hang][y]==1)
							{
								break;
							}
						me_cung[hang][y]=0;
						y++;
					}
				while(y!=cot);
				for(int z=0;z<tn;z++)
					{
					h=rand()%(n-2)+1;
					c=rand()%(n-2)+1;
					for(int i=1;i<n-1;i++)
						{
							if(me_cung[h][i]==1||me_cung[i][c]==1)
								{
									continue;
								}
							me_cung[h][i]=0;
							me_cung[i][c]=0;
						}
					}
				}
		}
		for(int c1=1;c1<n-1;c1++)
		{
			if(me_cung[c1][0]==2)
				{
					for(int i=1;i<n-1;i++)
					{
						if(me_cung[c1][i]==1)
							{
								continue;
							}
						me_cung[c1][i]=0;
					}
				for(int i=c1;i<n-1;i++)
					{
						if(me_cung[i][n-2]==1)
							{
								continue;
							}
						me_cung[i][n-2]=0;
					}
				x=n-2,y=n-2;
				do
					{
						if(me_cung[n-2][y]==1)
							{
								break;
							}
						me_cung[n-2][y]=0;
						y--;
					}
				while(y!=cot);
				do
					{
						if(me_cung[x][cot]==1)
							{
								break;
							}
						me_cung[x][cot]=0;
						x--;
					}
				while(x!=hang);
				for(int z=0;z<tn;z++)
					{
					h=rand()%(n-2)+1;
					c=rand()%(n-2)+1;
					for(int i=1;i<n-1;i++)
						{
							if(me_cung[h][i]==1||me_cung[i][c]==1)
								{
									continue;
								}
							me_cung[h][i]=0;
							me_cung[i][c]=0;
						}
					}
				}
		}
		for(int c2=1;c2<n-1;c2++)
		{
			if(me_cung[c2][n-1]==2)
				{
					for(int i=1;i<n-1;i++)
					{
						if(me_cung[c2][i]==1)
							{
								continue;
							}
						me_cung[c2][i]=0;
					}
				for(int i=c2;i<n-1;i++)
					{
						if(me_cung[i][1]==1)
							{
								continue;
							}
						me_cung[i][1]=0;
					}
				x=n-2,y=1;
				do
					{
						if(me_cung[n-2][y]==1)
							{
								break;
							}
						me_cung[n-2][y]=0;
						y++;
					}
				while(y!=cot);
				do
					{
						if(me_cung[x][cot]==1)
							{
								break;
							}
						me_cung[x][cot]=0;
						x--;
					}
				while(x!=hang);
				for(int z=0;z<tn;z++)
					{
					h=rand()%(n-2)+1;
					c=rand()%(n-2)+1;
					for(int i=1;i<n-1;i++)
						{
							if(me_cung[h][i]==1||me_cung[i][c]==1)
								{
									continue;
								}
							me_cung[h][i]=0;
							me_cung[i][c]=0;
						}
					}
				}
		}
	int m;
	do
	{
		system("cls");
		for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
					{
						if(me_cung[i][j]==2)
							{
								cout<<"O ";
							}
						if(me_cung[i][j]==1)
							{
								cout<<"A ";
							}
						if(me_cung[i][j]==-1)
							{
								cout<<"X ";
							}
						if(me_cung[i][j]==0)
							{
								cout<<". ";
							}
					}
				cout<<endl;
			}
		cout<<"+----------+   +-----------+   +-----------+   +-----------+   +----------+\n";
		cout<<"|  1.left  |   |  2.Right  |   |   3.Top   |   | 4.Bottom  |   |  5.EXIT  |\n";
		cout<<"+----------+   +-----------+   +-----------+   +-----------+   +----------+\n";
		cout<<"Huong Di: "; cin>>m;
		switch(m)
		{
			case 2:
				{
					me_cung[hang][cot]=0;
					if(me_cung[hang][cot+1]==-1)
						{
							me_cung[hang][cot]=1;
							break;
						}
					if(me_cung[hang][cot+1]==2)
						{
							for(int i=3;i>=0;i--)
								{
									system("cls");
									cout<<"Chuc Mung Ban Da Thoat Khoi Me Cung!\n";
									cout<<"Xin Vui Long Doi "<<i<<endl; sleep(1);
								}
							return;
						}
					cot+=1;
					me_cung[hang][cot]=1;
					break;
				}
			case 1:
				{
					me_cung[hang][cot]=0;
					if(me_cung[hang][cot-1]==-1)
						{
							me_cung[hang][cot]=1;
							break;
						}
					if(me_cung[hang][cot-1]==2)
						{
							for(int i=3;i>=0;i--)
								{
									system("cls");
									cout<<"Chuc Mung Ban Da Thoat Khoi Me Cung!\n";
									cout<<"Xin Vui Long Doi "<<i<<endl; sleep(1);
								}
							return;
						}
					cot-=1;
					me_cung[hang][cot]=1;
					break;
				}
			case 4:
				{
					me_cung[hang][cot]=0;
					if(me_cung[hang+1][cot]==-1)
						{
							me_cung[hang][cot]=1;
							break;
						}
					if(me_cung[hang+1][cot]==2)
						{
							for(int i=3;i>=0;i--)
								{
									system("cls");
									cout<<"Chuc Mung Ban Da Thoat Khoi Me Cung!\n";
									cout<<"Xin Vui Long Doi "<<i<<endl; sleep(1);
								}
							return;
						}
					hang+=1;
					me_cung[hang][cot]=1;
					break;
				}
			case 3:
				{
					me_cung[hang][cot]=0;
					if(me_cung[hang-1][cot]==-1)
						{
							me_cung[hang][cot]=1;
							break;
						}
					if(me_cung[hang-1][cot]==2)
						{
							for(int i=3;i>=0;i--)
								{
									system("cls");
									cout<<"Chuc Mung Ban Da Thoat Khoi Me Cung!\n";
									cout<<"Xin Vui Long Doi "<<i<<endl; sleep(1);
								}
							return;
						}
					hang-=1;
					me_cung[hang][cot]=1;
					break;
				}
			case 5:
				{
					return;
				}
			default:
				{
					cout<<"Huong Di Khong Ton Tai\n";
					cout<<"Nhan \"ENTER\" De Chon Lai\n";
					getch();
				}
		}
	}
	while(1);
}
void day_thung(int n)
{
	vector<int> thung1,thung2,dich1,dich2;
	int so_thung=3;
	int a,b;
	int day_thung[max][max];
	int hang,cot;
	int dem=0;
	for(int i=15;i<=n;i++)
		{
			dem++;
			if(dem==2)
				{
					so_thung++;
					dem=0;
				}
		}
	for(int i=0;i<n;i++)//tao tuong
		{
			for(int j=0;j<n;j++)
			{
				day_thung[i][j]=-1;
			}
		}
	a=rand()%n; hang=a;
	b=rand()%n; cot=b;
	day_thung[a][b]=0;//tao nv
	for(int i=0;i<so_thung;i++)//tao thung
		{
			a=rand()%(n-4)+2;
			b=rand()%(n-4)+2;
			thung1.push_back(a);
			thung2.push_back(b);
			day_thung[a][b]=2;
	    }
	for(int i=0;i<so_thung;i++)//tao dich den
		{
			a=rand()%n;
			b=rand()%n;
			dich1.push_back(a);
			dich2.push_back(b);
			day_thung[a][b]=-2;
		}
	for(int i=0;i<n;i++)//duong di canh tren
		{
			if(day_thung[0][i]==2||day_thung[0][i]==0||day_thung[0][i]==-2)
				{
					continue;
				}
			day_thung[0][i]=1;
		}
	for(int i=0;i<n;i++)//duong di canh duoi
		{
			if(day_thung[n-1][i]==2||day_thung[n-1][i]==0||day_thung[n-1][i]==-2)
				{
					continue;
				}
			day_thung[n-1][i]=1;
		}
	for(int i=0;i<n;i++)//duong di canh trai
		{
			if(day_thung[i][0]==2||day_thung[i][0]==0||day_thung[i][0]==-2)
				{
					continue;
				}
			day_thung[i][0]=1;
		}
	for(int i=0;i<n;i++)//duong di canh phai
		{
			if(day_thung[i][n-1]==2||day_thung[i][n-1]==0||day_thung[i][n-1]==-2)
				{
					continue;
				}
			day_thung[i][n-1]=1;
		}
	for(int i=0;i<n;i++)//duong di cho nhan vat
		{
			if(i==hang)
				{
					for(int x=0;x<n;x++)
					{
						if(day_thung[hang][x]==2||day_thung[hang][x]==0||day_thung[hang][x]==-2)
							{
								continue;
							}
						day_thung[hang][x]=1;
					}
				}
		}
	for(int i=0;i<n;i++)//tao duong di cho thung
		{
			for(int k=0;k<so_thung;k++)
				{
					if(i==thung2[k])
						{
							for(int x=0;x<n;x++)
								{
									if(day_thung[x][i]==2||day_thung[x][i]==0||day_thung[x][i]==-2)
										{ 
											continue;
										}
									day_thung[x][i]=1;
								}
						}
				}
		}
	for(int i=0;i<n;i++)//tao duong di cho dich
		{
			for(int k=0;k<so_thung;k++)
				{
				if(i==dich1[k])
					{
						for(int x=0;x<n;x++)
							{
								if(day_thung[i][x]==-2||day_thung[i][x]==0||day_thung[i][x]==-2)
									{
										continue;
									}
								day_thung[i][x]=1;
							}
					}
				}
		}
	do	
	{
		int dem1=0,dem2=0;
		system("cls");
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<n;j++)
				{
					if(day_thung[i][j]==-1)//tuong
					cout<<"X ";
					if(day_thung[i][j]==1)//duong di
					cout<<". ";
					if(day_thung[i][j]==0)//nhan vat
					cout<<"A ";
					if(day_thung[i][j]==-2)//dich den
						{
							dem1++;
							cout<<"O ";
						}
					if(day_thung[i][j]==2)//thung
						{
							dem2++;
							cout<<"! ";
						}
					if(day_thung[i][j]==3)//thung va dich trung nhau
					cout<<"W ";
				}
				cout<<endl;
			}
		if(dem1==0||dem2==0)
			{
				for(int i=3;i>=0;i--)
					{
						system("cls");
						cout<<"Chuc Mung Ban Da Hoan Thanh Xuat Sac Tro Choi!\n";
						cout<<"Xin Vui Long Doi "<<i<<endl; sleep(1);
					}
	            	return ;
			}
		cout<<"+----------+   +-----------+   +-----------+   +-----------+   +----------+\n";
		cout<<"|  1.left  |   |  2.Right  |   |   3.Top   |   | 4.Bottom  |   |  5.EXIT  |\n";
		cout<<"+----------+   +-----------+   +-----------+   +-----------+   +----------+\n";
		int m;
		cout<<"Huong Di: "; cin>>m;
		switch(m)
		{
			case 1:
				{
					if(day_thung[hang][cot-1]==-1||day_thung[hang][cot-1]==-2||day_thung[hang][cot-1]==3)
						{
							break;
						}
					if(day_thung[hang][cot-1]==2 && day_thung[hang][cot-2]==2)
						{
							break;
						}
					if(day_thung[hang][cot-1]==2 && day_thung[hang][cot-2]==3)
						{
							break;
						}
					if(day_thung[hang][cot-1]==2 && day_thung[hang][cot-2]==-2)
						{
							day_thung[hang][cot-2]=3;
							day_thung[hang][cot]=1;
							cot-=1;
							day_thung[hang][cot]=0;
							break;
						}
					if(day_thung[hang][cot-1]==2)
						{
							day_thung[hang][cot-2]=2;
						}
					day_thung[hang][cot]=1;
					cot-=1;
					day_thung[hang][cot]=0;
					break;
				}
			case 2:
				{
					if(day_thung[hang][cot+1]==-1||day_thung[hang][cot+1]==-2||day_thung[hang][cot+1]==3)
						{
							break;
						}
					if(day_thung[hang][cot+1]==2 && day_thung[hang][cot+2]==2)
						{
							break;
						}
					if(day_thung[hang][cot+1]==2 && day_thung[hang][cot+2]==3)
						{
							break;
						}
					if(day_thung[hang][cot+1]==2 && day_thung[hang][cot+2]==-2)
						{
							day_thung[hang][cot+2]=3;
							day_thung[hang][cot]=1;
							cot+=1;
							day_thung[hang][cot]=0;
							break;
						}
					if(day_thung[hang][cot+1]==2)
						{
							day_thung[hang][cot+2]=2;
						}
					day_thung[hang][cot]=1;
					cot+=1;
					day_thung[hang][cot]=0;
					break;
				}
			case 3:
				{
					if(day_thung[hang-1][cot]==-1||day_thung[hang-1][cot]==-2||day_thung[hang-1][cot]==3)
						{
							break;
						}
					if(day_thung[hang-1][cot]==2 && day_thung[hang-2][cot]==2)
						{
							break;
						}
					if(day_thung[hang-1][cot]==2 && day_thung[hang-2][cot]==3)
						{
							break;
						}
					if(day_thung[hang-1][cot]==2 && day_thung[hang-2][cot]==-2)
						{
							day_thung[hang-2][cot]=3;
							day_thung[hang][cot]=1;
							hang-=1;
							day_thung[hang][cot]=0;
							break;
						}
					if(day_thung[hang-1][cot]==2)
						{
							day_thung[hang-2][cot]=2;
						}
					day_thung[hang][cot]=1;
					hang-=1;
					day_thung[hang][cot]=0;
					break;
				}
			case 4:
				{
				if(day_thung[hang+1][cot]==-1||day_thung[hang+1][cot]==-2||day_thung[hang+1][cot]==3)
					{
						break;
					}
				if(day_thung[hang+1][cot]==2 && day_thung[hang+2][cot]==2)
					{
						break;
					}
				if(day_thung[hang+1][cot]==2 && day_thung[hang+2][cot]==3)
					{
						break;
					}	
				if(day_thung[hang+1][cot]==2 && day_thung[hang+2][cot]==-2)
					{
						day_thung[hang+2][cot]=3;
						day_thung[hang][cot]=1;
						hang+=1;
						day_thung[hang][cot]=0;
						break;
					}	
				if(day_thung[hang+1][cot]==2)
					{
						day_thung[hang+2][cot]=2;
					}
				day_thung[hang][cot]=1;
				hang+=1;
				day_thung[hang][cot]=0;
				break;
				}
			case 5:
				{
					return;
			    }
			default :
				{
					cout<<"Huong Di Khong Ton Tai\n";
					cout<<"Nhan \"ENTER\" De Chon Lai\n";
					getch();
				}
		}
	}
	while(1);
}
