#include<iostream>
#include<graphics.h>
#include <conio.h>
#include<cmath>
#include<fstream>

using namespace std;
#define WIDTH 800
#define HEIGHT 720
static int i = 0;
class Point
{
	int X, Y;
	friend void OpenOutFile();
public:
	Point(int a, int b)
	{
		X = a;
		Y = b;
	}
	Point()
	{
		X = 0;
		Y = 0;
	}
	Point(Point& po)
	{
		X = po.X;
		Y = po.Y;
	}
	void ChangeX(int a)
	{
		X = a;
	}
	void ChangeY(int b)
	{
		Y = b;
	}
	int MoveX(int n)
	{
		X += n;
		return X;
	}
	int MoveY(int n)
	{
		Y += n;
		return Y;
	}
	int GetX()
	{
		return X;
	}
	int GetY()
	{
		return Y;
	}
};
class Picture
{
private:
	Point* p1=NULL;
	Picture* next = NULL;
	int radius=0;      //半径
	int NumberPoint=0;//图形的点数
	COLORREF fillColor=  WHITE;    //图形填充颜色
	COLORREF styleColor= WHITE;    //图形线颜色
	int thickness=1;        //线宽
	int fillstyle1=0;            //填充线形1
	int fillstyle2=0;            //填充线形2
	int style1=0;                //线形1
	int joint=-1;                //连接处样式
	int endPoint=-1;             //端点样式
	int LocalX = 0;                 //图形的横坐标位置
	int LocalY = 0;                 //图形的纵坐标位置
	int color1=0;                    //填充色
	int color2=0;                    //线形色
	friend class ListPicture;
	friend void OpenInputFile();
	friend void OpenOutFile();
public:
	int Piece;//图形种类
	Picture()
	{

	}
	Picture(Point* z, int l,int m)
	{
		NumberPoint = l;
		p1 = new Point[NumberPoint];
		for (int s = 0; s < l; s++)
		{
			p1[s] = z[s];
		}
		Piece = m;
	}
	Picture(Point* z, int l, int r, int m)
	{
		NumberPoint = l;
		radius = r;
		p1 = new Point[NumberPoint];
		p1 = z;
		Piece = m;
	}
	void ChangeFillStyle1(int n)//修改填充线样式
	{
		fillstyle1 = n;
	}
	void ChangeFillStyle2(int n)//修改填充线样式
	{
		fillstyle2 = n;
	}
	void ChangeFillColor(COLORREF c)//修改填充颜色
	{
		fillColor=c;  
	}
	void ChangeStyleColor(COLORREF c)//修改线颜色
	{
		styleColor = c;
	}
	void ChangeThickness(int n)//修改线宽
	{
		thickness = n;
	}
	void ChangeStyle1(int n)//修改线形
	{
		style1 = n;
	}
	void ChangeJoint(int n)//修改连接处样式
	{
		joint = n;
	}
	void ChangeEndPoint(int n)//修改端点样式
	{
		endPoint = n;
	}
	void ChangeLocalX(int x)//修改图象的横坐标
	{
		LocalX = x;
	}
	void ChangeLocalY(int y)//修改图像的纵坐标
	{
		LocalY = y;
	}
	void ChangeRadius(int n)
	{
		radius = n;
	}
	Point* GetPoint()
	{
		return p1;
	}
	int Getradius()
	{
		return radius;
	}
	int GetNumberPoint()
	{
		return NumberPoint;
	}
	Point GetPoint(int z)
	{
		return p1[z];
	}
	COLORREF GetFillColor()
	{
		return fillColor;
	}
	COLORREF GetStyleColor()
	{
		return styleColor;
	}
	int GetThickness()
	{
		return thickness;
	}
	int GetFillStyle1()
	{
		return fillstyle1;
	}
	int GetFillStyle2()
	{
		return fillstyle2;
	}
	int GetStyle1()
	{
		return style1;
	}
	int GetEndPoint()
	{
		return endPoint;
	}
	int GetJoint()
	{
		return joint;
	}
	int GetLocalX()
	{
		return LocalX;
	}
	int GetLocalY()
	{
		return LocalY;
	}
	Point MovePoint(int n,int x1, int y1)
	{
		p1[n].MoveX(x1);
		p1[n].MoveY(y1);
		return p1[n];
	}
};
//链表数据库
class ListPicture
{
private:
	Picture* head=NULL ;
public:
	void tialinsert(Picture *p2)
	{
		if (head == NULL)
		{
			head = p2;
			head->next = NULL;
		}
		else
		{
			Picture* pcur = head;
			while (pcur->next != NULL)
			{
				pcur = pcur->next;
			}
			pcur->next = p2;
			p2->next = NULL;
		}
		i++;
	}
	Picture* FindPicture(int n)
	{
		Picture *pnew = head;
		for (int l = 1; l < n; l++)
			pnew = pnew->next;
		return pnew;
	}
	void deletelist(int n)
	{
		if (n == 1)
		{
			if (head->next == NULL)
			{
				Picture* pnew = head;
				head = NULL;
				delete[] pnew;
			}
			else
			{
				Picture* pnew = head;
				head = head->next;
				delete[] pnew;
			}
			i--;
			return;
		}
		if(n==i)
		{
			Picture* pnew = head;
			Picture* pnew1 = NULL;
			while (pnew->next != NULL)
			{
				pnew1 = pnew;
				pnew = pnew->next;
			}
			delete pnew;
			pnew1 = NULL;
			i--;
			return;
		}
		Picture* pnew = head;
		Picture* pfr = NULL;
		for (int z = 1; z < n; z++)
		{
			pfr = pnew;
			pnew = pnew->next;
		}
		pfr->next = pnew->next;
		delete pnew;
		i--;
	}
};

int key = 1;
//数据存储
ListPicture listpicture;

//显示全部图形
void ShowAllPicture()
{
	int z = 1;
	while (z <= i)
	{
		Picture pnew = *(listpicture.FindPicture(z));
		switch (pnew.Piece)
		{
		case 1:
		{
			setfillcolor(pnew.GetFillColor());
			setlinecolor(pnew.GetStyleColor());
			if ((pnew.GetEndPoint() > 0) && (pnew.GetJoint() > 0))
			{
				setlinestyle(pnew.GetStyle1() | pnew.GetEndPoint() | pnew.GetJoint(), pnew.GetThickness());
			}
			else if (pnew.GetEndPoint() > 0)
			{
				setlinestyle(pnew.GetStyle1() | pnew.GetEndPoint(), pnew.GetThickness());
			}
			else if (pnew.GetJoint() > 0)
			{
				setlinestyle(pnew.GetStyle1() | pnew.GetJoint(), pnew.GetThickness());
			}
			else { setlinestyle(pnew.GetStyle1(), pnew.GetThickness()); }
			Point* po = pnew.GetPoint();
			putpixel(po->GetX(), po->GetY(), RED);
			break;
		}
		case 2:
		{
			setfillcolor(pnew.GetFillColor());
			setlinecolor(pnew.GetStyleColor());
			if ((pnew.GetEndPoint() > 0) && (pnew.GetJoint() > 0))
			{
				setlinestyle(pnew.GetStyle1() | pnew.GetEndPoint() | pnew.GetJoint(), pnew.GetThickness());
			}
			else if (pnew.GetEndPoint() > 0)
			{
				setlinestyle(pnew.GetStyle1() | pnew.GetEndPoint(), pnew.GetThickness());
			}
			else if (pnew.GetJoint() > 0)
			{
				setlinestyle(pnew.GetStyle1() | pnew.GetJoint(), pnew.GetThickness());
			}
			else
			{
				setlinestyle(pnew.GetStyle1(), pnew.GetThickness());
			}
			if (pnew.GetFillStyle1() == NULL)
				setfillstyle(BS_SOLID);
			else if (pnew.GetFillStyle1() == 1)
			{
				setfillstyle(BS_NULL);
			}
			else if (pnew.GetFillStyle1() == 2)
			{
				setfillstyle(2, pnew.GetFillStyle2());
			}
			int n = pnew.GetNumberPoint();
			Point* po = new Point[n];
			for (int z = 0; z < n; z++)
			{
				po[z] = pnew.GetPoint(z);
			}
			line(po[0].GetX(), po[0].GetY(), po[1].GetX(), po[1].GetY());
			break;
		}
		case 3:
		{
			setfillcolor(pnew.GetFillColor());
			setlinecolor(pnew.GetStyleColor());
			if ((pnew.GetEndPoint() > 0) && (pnew.GetJoint() > 0))
			{
				setlinestyle(pnew.GetStyle1() | pnew.GetEndPoint() | pnew.GetJoint(), pnew.GetThickness());
			}
			else if (pnew.GetEndPoint() > 0)
			{
				setlinestyle(pnew.GetStyle1() | pnew.GetEndPoint(), pnew.GetThickness());
			}
			else if (pnew.GetJoint() > 0)
			{
				setlinestyle(pnew.GetStyle1() | pnew.GetJoint(), pnew.GetThickness());
			}
			else
			{
				setlinestyle(pnew.GetStyle1(), pnew.GetThickness());
			}
			if (pnew.GetFillStyle1() == NULL)
				setfillstyle(BS_SOLID);
			else if (pnew.GetFillStyle1() == 1)
			{
				setfillstyle(BS_NULL);
			}
			else if (pnew.GetFillStyle1() == 2)
			{
				setfillstyle(2, pnew.GetFillStyle2());
			}
			int n = pnew.GetNumberPoint();
			Point* po = new Point[n];
			int* m1 = new int[2 * n];
			for (int z = 0; z < n; z++)
			{
				po[z] = pnew.GetPoint(z);
			}
			for (int z = 0; z < 2 * n; z += 2)
			{
				int s = z / 2;
				m1[z] = po[s].GetX();
				m1[z + 1] = po[s].GetY();
			}
			polyline((POINT*)m1, n);
			break;
		}
		case 4:
		{
			setfillcolor(pnew.GetFillColor());
			setlinecolor(pnew.GetStyleColor());
			if ((pnew.GetEndPoint() > 0) && (pnew.GetJoint() > 0))
			{
				setlinestyle(pnew.GetStyle1() | pnew.GetEndPoint() | pnew.GetJoint(), pnew.GetThickness());
			}
			else if (pnew.GetEndPoint() > 0)
			{
				setlinestyle(pnew.GetStyle1() | pnew.GetEndPoint(), pnew.GetThickness());
			}
			else if (pnew.GetJoint() > 0)
			{
				setlinestyle(pnew.GetStyle1() | pnew.GetJoint(), pnew.GetThickness());
			}
			else
			{
				setlinestyle(pnew.GetStyle1(), pnew.GetThickness());
			}
			if (pnew.GetFillStyle1() == NULL)
				setfillstyle(BS_SOLID);
			else if (pnew.GetFillStyle1() == 1)
			{
				setfillstyle(BS_NULL);
			}
			else if (pnew.GetFillStyle1() == 2)
			{
				setfillstyle(2, pnew.GetFillStyle2());
			}
			Point* po = pnew.GetPoint();
			fillcircle(po->GetX(), po->GetY(), pnew.Getradius());
			break;
		}
		case 5:
		{
			setfillcolor(pnew.GetFillColor());
			setlinecolor(pnew.GetStyleColor());
			if ((pnew.GetEndPoint() > 0) && (pnew.GetJoint() > 0))
			{
				setlinestyle(pnew.GetStyle1() | pnew.GetEndPoint() | pnew.GetJoint(), pnew.GetThickness());
			}
			else if (pnew.GetEndPoint() > 0)
			{
				setlinestyle(pnew.GetStyle1() | pnew.GetEndPoint(), pnew.GetThickness());
			}
			else if (pnew.GetJoint() > 0)
			{
				setlinestyle(pnew.GetStyle1() | pnew.GetJoint(), pnew.GetThickness());
			}
			else
			{
				setlinestyle(pnew.GetStyle1(), pnew.GetThickness());
			}
			if (pnew.GetFillStyle1() == NULL)
				setfillstyle(BS_SOLID);
			else if (pnew.GetFillStyle1() == 1)
			{
				setfillstyle(BS_NULL);
			}
			else if (pnew.GetFillStyle1() == 2)
			{
				setfillstyle(2, pnew.GetFillStyle2());
			}
			int n = pnew.GetNumberPoint();
			Point* po = new Point[n];
			for (int z = 0; z < n; z++)
			{
				po[z] = pnew.GetPoint(z);
			}
			fillrectangle(po[0].GetX(), po[0].GetY(), po[1].GetX(), po[1].GetY());
			break;
		}
		case 6:
		{
			setfillcolor(pnew.GetFillColor());
			setlinecolor(pnew.GetStyleColor());
			if ((pnew.GetEndPoint() > 0) && (pnew.GetJoint() > 0))
			{
				setlinestyle(pnew.GetStyle1() | pnew.GetEndPoint() | pnew.GetJoint(), pnew.GetThickness());
			}
			else if (pnew.GetEndPoint() > 0)
			{
				setlinestyle(pnew.GetStyle1() | pnew.GetEndPoint(), pnew.GetThickness());
			}
			else if (pnew.GetJoint() > 0)
			{
				setlinestyle(pnew.GetStyle1() | pnew.GetJoint(), pnew.GetThickness());
			}
			else
			{
				setlinestyle(pnew.GetStyle1(), pnew.GetThickness());
			}
			if (pnew.GetFillStyle1() == NULL)
				setfillstyle(BS_SOLID);
			else if (pnew.GetFillStyle1() == 1)
			{
				setfillstyle(BS_NULL);
			}
			else if (pnew.GetFillStyle1() == 2)
			{
				setfillstyle(2, pnew.GetFillStyle2());
			}
			int n = pnew.GetNumberPoint();
			Point* po = new Point[n];
			int* m1 = new int[2 * n];
			for (int z = 0; z < n; z++)
			{
				po[z] = pnew.GetPoint(z);
			}
			for (int z = 0; z < 2 * n; z += 2)
			{
				int s = z / 2;
				m1[z] = po[s].GetX();
				m1[z + 1] = po[s].GetY();
			}
			fillpolygon((POINT*)m1, n);
			break;
		}
		case 7:
		{
			setfillcolor(pnew.GetFillColor());
			setlinecolor(pnew.GetStyleColor());
			if ((pnew.GetEndPoint() > 0) && (pnew.GetJoint() > 0))
			{
				setlinestyle(pnew.GetStyle1() | pnew.GetEndPoint() | pnew.GetJoint(), pnew.GetThickness());
			}
			else if (pnew.GetEndPoint() > 0)
			{
				setlinestyle(pnew.GetStyle1() | pnew.GetEndPoint(), pnew.GetThickness());
			}
			else if (pnew.GetJoint() > 0)
			{
				setlinestyle(pnew.GetStyle1() | pnew.GetJoint(), pnew.GetThickness());
			}
			else
			{
				setlinestyle(pnew.GetStyle1(), pnew.GetThickness());
			}
			if (pnew.GetFillStyle1() == NULL)
				setfillstyle(BS_SOLID);
			else if (pnew.GetFillStyle1() == 1)
			{
				setfillstyle(BS_NULL);
			}
			else if (pnew.GetFillStyle1() == 2)
			{
				setfillstyle(2, pnew.GetFillStyle2());
			}
			int n = pnew.GetNumberPoint();
			Point* po = new Point[n];
			for (int z = 0; z < n; z++)
			{
				po[z] = pnew.GetPoint(z);
			}
			fillellipse(po[0].GetX(), po[0].GetY(), po[1].GetX(), po[1].GetY());
			break;
		}
		default:
			cout << "输入错误" << endl;
		}
		z++;
	}
	cout << endl;
}

//显示数据
void ShowLocation()
{
	int z = 1;
	while (z <= i)
	{
		Picture pnew = *(listpicture.FindPicture(z));
		cout << z << ": ";
		switch (pnew.Piece)
		{
		case 1:
		{
			Point* po = pnew.GetPoint();
			cout << "点 " << "位置: " << po->GetX() << "," << po->GetY();
			cout << endl;
			break;
		}
		case 2:
		{
			cout << "线 " << "各点位置: ";
			int n = pnew.GetNumberPoint();
			Point* po = new Point[n];
			for (int z = 0; z < n; z++)
			{
				po[z] = pnew.GetPoint(z);
				cout << po[z].GetX() << "," << po[z].GetY() << " ";
			}
			cout << endl;
			break;
		}
		case 3:
		{
			cout << "折线 " << "各点位置: ";
			int n = pnew.GetNumberPoint();
			Point* po = new Point[n];
			for (int z = 0; z < n; z++)
			{
				po[z] = pnew.GetPoint(z);
				cout << po[z].GetX() << "," << po[z].GetY() << " ";
			}
			cout << endl;
			break;
		}
		case 4:
		{
			cout << "圆 " << "圆心位置: ";
			Point* po = pnew.GetPoint();
			cout << po->GetX() << "," << po->GetY() << " ";
			cout << endl;
			break;
		}
		case 5:
		{
			cout << "矩形" << "各点位置: ";
			int n = pnew.GetNumberPoint();
			Point* po = new Point[n];
			for (int z = 0; z < n; z++)
			{
				po[z] = pnew.GetPoint(z);
				cout << po[z].GetX() << "," << po[z].GetY() << " ";
			}
			cout << endl;
			break;
		}
		case 6:
		{
			cout << "多边形" << "各点位置: ";
			int n = pnew.GetNumberPoint();
			Point* po = new Point[n];
			for (int z = 0; z < n; z++)
			{
				po[z] = pnew.GetPoint(z);
				cout << po[z].GetX() << "," << po[z].GetY() << " ";
			}
			cout << endl;
			break;
		}
		case 7:
		{
			cout << "椭圆" << "各点位置: ";
			int n = pnew.GetNumberPoint();
			Point* po = new Point[n];
			for (int z = 0; z < n; z++)
			{
				po[z] = pnew.GetPoint(z);
				cout << po[z].GetX() << "," << po[z].GetY() << " ";
			}
			cout << endl;
			break;
		}
		}
		z++;
	}
}

//常规编辑功能实现函数
Picture* EditPicture(Picture* po)
{
	int choose;
	COLORREF* c = new COLORREF;
	COLORREF* c1 = new COLORREF;
	while (1)
	{
		cout << "请选择你想进行的编辑操作" << endl;
		cout << "0.退出该功能" << endl;
		cout << "1.编辑图形填充颜色" << endl;
		cout << "2.编辑图形线型" << endl;
		cin >> choose;
		if (choose == 0)
		{
			cout << endl;
			return po;
		}
		switch (choose)
		{
		case 1:
		{
			cout << endl;
			cout << "请选择颜色变量" << endl;
			cout << "1.蓝色" << endl;
			cout << "2.绿色" << endl;
			cout << "3.红色" << endl;
			cout << "4.黑色" << endl;
			cout << "5.青色" << endl;
			cout << "6.紫色" << endl;
			cout << "7.棕色" << endl;
			cout << "8.浅灰" << endl;
			cout << "9.深灰" << endl;
			cout << "10.亮蓝" << endl;
			cout << "11.亮绿" << endl;
			cout << "12.亮青" << endl;
			cout << "13.亮红" << endl;
			cout << "14.亮紫" << endl;
			cout << "15.黄" << endl;
			cout << "16.白" << endl;
			int choose1;
			cin >> choose1;
			switch (choose1)
			{
			case 1:
			{
				*c1 = BLUE;
				break;
			}
			case 2:
			{
				*c1 = GREEN;
				break;
			}
			case 3:
			{
				*c1 = RED;
				break;
			}
			case 4:
			{
				*c1 = BLACK;
				break;
			}
			case 5:
			{
				*c1 = CYAN;
				break;
			}
			case 6:
			{
				*c1 = MAGENTA;
				break;
			}
			case 7:
			{
				*c1 =BROWN ;
				break;
			}
			case 8:
			{
				*c1 =LIGHTGRAY ;
				break;
			}
			case 9:
			{
				*c1 = DARKGRAY;
				break;
			}
			case 10:
			{
				*c1 = LIGHTBLUE;
				break;
			}
			case 11:
			{
				*c1 = LIGHTGREEN;
				break;
			}
			case 12:
			{
				*c1 =LIGHTCYAN ;
				break;
			}
			case 13:
			{
				*c1 =LIGHTRED ;
				break;
			}
			case 14:
			{
				*c1 = LIGHTMAGENTA;
				break;
			}
			case 15:
			{
				*c1 = YELLOW;
				break;
			}
			case 16:
			{
				*c1 = WHITE;
				break;
			}
			default:
			{
				cout << "输入错误" << endl;
				cout << endl;
			}
			}
			po->ChangeFillColor(*c1);
			ShowAllPicture();
			break;
		}
		case 2:
		{
			cout << "请选择想要进行的图形线的编辑操作：" << endl;
			cout << "0.退出该功能" << endl;
			cout << "1.编辑线色" << endl;
			cout << "2.编辑线形" << endl;
			cout << "3.编辑端点" << endl;
			cout << "4.编辑连接处" << endl;
			cout << "5.编辑图形线宽" << endl;
			int choose2;
			cin >> choose2;
			if (choose2 == 0)
			{
				cout << endl;
				return po;
			}
			switch (choose2)
			{
			case 1:
			{
				cout << endl;
				cout << "请选择颜色变量" << endl;
				cout << "1.蓝色" << endl;
				cout << "2.绿色" << endl;
				cout << "3.红色" << endl;
				cout << "4.黑色" << endl;
				cout << "5.青色" << endl;
				cout << "6.紫色" << endl;
				cout << "7.棕色" << endl;
				cout << "8.浅灰" << endl;
				cout << "9.深灰" << endl;
				cout << "10.亮蓝" << endl;
				cout << "11.亮绿" << endl;
				cout << "12.亮青" << endl;
				cout << "13.亮红" << endl;
				cout << "14.亮紫" << endl;
				cout << "15.黄" << endl;
				cout << "16.白" << endl;
				int choose1;
				cin >> choose1;
				switch (choose1)
				{
				case 1:
				{
					*c = BLUE;
					break;
				}
				case 2:
				{
					*c = GREEN;
					break;
				}
				case 3:
				{
					*c1 = RED;
					break;
				}
				case 4:
				{
					*c = BLACK;
					break;
				}
				case 5:
				{
					*c = CYAN;
					break;
				}
				case 6:
				{
					*c = MAGENTA;
					break;
				}
				case 7:
				{
					*c = BROWN;
					break;
				}
				case 8:
				{
					*c = LIGHTGRAY;
					break;
				}
				case 9:
				{
					*c = DARKGRAY;
					break;
				}
				case 10:
				{
					*c = LIGHTBLUE;
					break;
				}
				case 11:
				{
					*c = LIGHTGREEN;
					break;
				}
				case 12:
				{
					*c = LIGHTCYAN;
					break;
				}
				case 13:
				{
					*c = LIGHTRED;
					break;
				}
				case 14:
				{
					*c = LIGHTMAGENTA;
					break;
				}
				case 15:
				{
					*c = YELLOW;
					break;
				}
				case 16:
				{
					*c = WHITE;
					break;
				}
				default:
				{
					cout << "输入错误" << endl;
					cout << endl;
				}
				}
				po->ChangeStyleColor(*c);
				ShowAllPicture();
				break;
			}
			case 2:
			{
				cout << "请选择线形:" << endl;
				cout << "0.线形为实线" << endl;
				cout << "1.线形为：------------" << endl;
				cout << "2.线形为：············" << endl;
				cout << "3.线形为： - · - · - · - · - · - ·" << endl;
				cout << "4.线形为：-··-··-··-··" << endl;
				cout << "5.线形为不可见" << endl;
				int choose3;
				cin >> choose3;
				switch (choose3)
				{
				case 0:
				{
					po->ChangeStyle1(choose3);
					break;
				}
				case 1:
				{
					po->ChangeStyle1(choose3);
					break;
				}
				case 2:
				{
					po->ChangeStyle1(choose3);
					break;
				}
				case 3:
				{
					po->ChangeStyle1(choose3);
					break;
				}
				case 4:
				{
					po->ChangeStyle1(choose3);
					break;
				}
				case 5:
				{
					po->ChangeStyle1(choose3);
					break;
				}
				default:
				{
					cout << "输入错误" << endl;
					cout << endl;
				}
				}
				ShowAllPicture();
				break;
			}
			case 3:
			{
				cout << "请选择端点样式" << endl;
				cout << "0.端点为圆形" << endl;
				cout << "1.端点为方形" << endl;
				cout << "2.端点为平坦" << endl;
				int choose4;
				cin >> choose4;
				switch (choose4)
				{
				case 0:
				{
					po->ChangeEndPoint(choose4);
					break;
				}
				case 1:
				{
					po->ChangeEndPoint(choose4);
					break;
				}
				case 2:
				{
					po->ChangeEndPoint(choose4);
					break;
				}
				default:
				{
					cout << "输入错误" << endl;
					cout << endl;
				}
				}
				ShowAllPicture();
				break;
			}
			case 4:
			{
				cout << "请选择连接处样式" << endl;
				cout << "0.连接处为斜面" << endl;
				cout << "1.连接处为斜接" << endl;
				cout << "2.连接处为圆弧" << endl;
				int choose5;
				cin >> choose5;
				switch (choose5)
				{
				case 0:
				{
					po->ChangeJoint(choose5);
					break;
				}
				case 1:
				{
					po->ChangeJoint(choose5);
					break;
				}
				case 2:
				{
					po->ChangeJoint(choose5);
					break;
				}
				default:
					cout << "输入错误" << endl;
				}
				ShowAllPicture();
				break;
			}
			case 5:
			{
				int width;
				cout << "请输入线宽" << endl;
				cin >> width;
				po->ChangeThickness(width);
				ShowAllPicture();
				break;
			}
			default:
			{
				cout << "输入错误" << endl;
				cout << endl;
			}
			}

			break;
		}
		default:
		{
			cout << "输入错误" << endl;
			cout << endl;
		}
		}
	}
}

//检测图形是否符合特殊功能条件
bool TextPicture(Picture pnew)
{
	if (pnew.Piece == 1 || pnew.Piece == 3 || pnew.Piece == 6)
		return false;
	else
		return true;
}

//读取图片
void ReadPicture(Picture* pnew,int x1,int y1)
{
	switch (pnew->Piece)
	{
	case 1:
	{
		Point* po = pnew->GetPoint();
		po->MoveX(x1); po->MoveY(y1);
		break;
	}
	case 2:
	{
		int n = pnew->GetNumberPoint();
		Point* po = new Point[n];
		for (int z = 0; z < n; z++)
		{
			po[z] = pnew->GetPoint(z);
		}
		po[0].MoveX(x1), po[0].MoveY(y1), po[1].MoveX(x1), po[1].MoveY(y1);
		cout << endl;
		break;
	}
	case 3:
	{
		int n = pnew->GetNumberPoint();
		Point* po = new Point[n];
		int* m1 = new int[2 * n];
		for (int z = 0; z < n; z++)
		{
			po[z] = pnew->MovePoint(z,x1,y1);
		}
		cout << endl;
		break;
	}
	case 4:
	{
		Point* po = pnew->GetPoint();
		po->MoveX(x1), po->MoveY(y1), pnew->Getradius();
		cout << endl;
		break;
	}
	case 5:
	{
		int n = pnew->GetNumberPoint();
		Point* po = new Point[n];
		for (int z = 0; z < n; z++)
		{
			po[z] = pnew->MovePoint(z,x1,y1);
		}
		cout << endl;
		break;
	}
	case 6:
	{
		int n = pnew->GetNumberPoint();
		Point* po = new Point[n];
		int* m1 = new int[2 * n];
		for (int z = 0; z < n; z++)
		{
			po[z] = pnew->MovePoint(z,x1,y1);
		}
		cout << endl;
		break;
	}
	case 7:
	{
		int n = pnew->GetNumberPoint();
		Point* po = new Point[n];
		for (int z = 0; z < n; z++)
		{
			po[z] = pnew->MovePoint(z,x1,y1);
		}
		cout << endl;
		break;
	}
	default:
	{
		cout << "输入错误" << endl;
		cout << endl;
	}
	}
}

//绘制图形的菜单栏
void CreatePicture()
{
	cout << endl;
	int choose;
	while (1)
	{
		cout << "请输入图形类别：" << endl;
		cout << "0.退出该功能" << endl;
		cout << "1.点" << endl;
		cout << "2.直线" << endl;
		cout << "3.折线" << endl;
		cout << "4.圆" << endl;
		cout << "5.矩形" << endl;
		cout << "6.多边形" << endl;
		cout << "7.椭圆" << endl;
		cout << "请选择图形种类: ";
		cin >> choose;
		if (choose == 0)
		{
			cout << endl;
			return;
		}
		switch (choose)
		{
		case 1:
		{ 
			cout << "请输入点的坐标:";
			int x, y;
			cin >> x >> y;
			Point* a = new Point(x, y);
			Picture* b = new Picture(a,1, choose);
			listpicture.tialinsert(b);
			ShowAllPicture();
			b = EditPicture(b);
			ShowAllPicture();
			cout << endl;
			break;
		}
		case 2:
		{
			cout << "请输入起点坐标:";
			int x1, y1;
			cin >> x1 >> y1;
			cout << "请输入终点坐标:";
			int x2, y2;
			cin >> x2 >> y2;
			Point* a = new Point[2];
			a[0] = { x1,y1 };
			a[1] = { x2,y2 };
			Picture* b = new Picture(a, 2, choose);
			listpicture.tialinsert(b);
			ShowAllPicture();
			b = EditPicture(b);
			ShowAllPicture();
			cout << endl;
			break;
		}
		case 3:
		{
			int number;
			cout << "请输入折点数" << endl;
			cin >> number;
			cout << "请输入各点的坐标" << endl;
			int* m = new int[2 * number];
			Point* a = new Point[number];
			for (int z = 0; z < 2 * number; z++)
			{
				if (z % 2 == 0)
				{
					cout << "请输入坐标x:";
				}
				else
				{
					cout << "请输入坐标y:";
				}
				cin >> m[z];
			}
			for (int z = 0; z < 2 * number; z += 2)
			{
				a[z / 2] = { m[z],m[z + 1] };
			}
			Picture* b = new Picture(a, number, choose);
			listpicture.tialinsert(b);
			ShowAllPicture();
			b = EditPicture(b);
			ShowAllPicture();
			cout << endl;
			break;
			break;
		}
		case 4:
		{
			int x, y, r;
			cout << "请输入圆心坐标:";
			cin >> x >> y;
			cout << "请输入圆的半径:";
			cin>> r;
			Point* a = new Point(x, y);
			Picture* b = new Picture(a, 1, r, choose);
			listpicture.tialinsert(b);
			ShowAllPicture();
			b = EditPicture(b);
			ShowAllPicture();
			cout << endl;
			break;
		}
		case 5:
		{
			int x1, y1, x2, y2;
			cout << "请输入矩形的数据:" << endl;
			cout << "请输入左上角坐标:" ;
			cin >> x1 >> y1;
			cout << "请输入右下角坐标:" ;
			cin>> x2 >> y2;
			Point* a = new Point[2];
			a[0] = { x1,y1 };
			a[1] = { x2,y2 };
			Picture* b = new Picture(a, 2, choose);
			listpicture.tialinsert(b);
			ShowAllPicture();
			b = EditPicture(b);
			ShowAllPicture();
			cout << endl;
			break;
		}
		case 6:
		{
			int number;
			cout << "请输入折点数" << endl;
			cin >> number;
			cout << "请输入各点的坐标" << endl;
			int* m = new int[2 * number];
			for (int z = 0; z < 2 * number; z++)
			{
				if (z % 2 == 0)
				{
					cout << "请输入坐标x:";
				}
				else
				{
					cout << "请输入坐标y:";
				}
				cin >> m[z];
			}
			Point* a = new Point[number];
			for (int z = 0; z < 2 * number; z += 2)
			{
				a[z / 2] = { m[z],m[z + 1] };
			}
			Picture* b = new Picture(a, number, choose);
			listpicture.tialinsert(b);
			ShowAllPicture();
			b = EditPicture(b);
			ShowAllPicture();
			cout << endl;
			break;
		}
		case 7:
		{
			int x1, y1, x2, y2;
			cout << "请输入椭圆的数据" << endl;
			cout << "请输入左上角坐标:" ;
			cin >> x1 >> y1;
			cout << "请输入右下角坐标:";
				cin>> x2 >> y2;
			Point* a = new Point[2];
			a[0] = { x1,y1 };
			a[1] = { x2,y2 };
			Picture* b = new Picture(a, 2, choose);
			listpicture.tialinsert(b);
			ShowAllPicture();
			b = EditPicture(b);
			ShowAllPicture();
			cout << endl;
			break;
		}
		default:
		{
			cout << "输入错误" << endl;
			cout << endl;
		}
		}
	}
}

//编辑图片菜单
void EditPictureMenu()
{
	cout << endl;
	ShowLocation();
	cout << endl;
	cout << "请输入你想编辑的图片序号: " << endl;
	int choose1;
	cin >> choose1;
	if (choose1<=0&&choose1 > i)
	{
		cout << "图片不存在，请重新输入" << endl;
		return;
	}
	Picture * pnew=listpicture.FindPicture(choose1); 
	switch (pnew->Piece)
	{
	case 1:
	{
		pnew = EditPicture(pnew);
		cleardevice();
		ShowAllPicture();
		cout << endl;
		break;
	}
	case 2:
	{
		pnew = EditPicture(pnew);
		cleardevice();
		ShowAllPicture();
		cout << endl;
		break;
	}
	case 3:
	{
		pnew = EditPicture(pnew);
		cleardevice();
		ShowAllPicture();
		cout << endl;
		break;
	}
	case 4:
	{
		pnew=EditPicture(pnew);
		cleardevice();
		ShowAllPicture();
		cout << endl;
		break;
	}
	case 5:
	{
		pnew = EditPicture(pnew);
		cleardevice();
		ShowAllPicture();
		break;
	}
	case 6:
	{
		pnew = EditPicture(pnew);
		cleardevice();
		ShowAllPicture();
		cout << endl;
		break;
	}
	case 7:
	{
		pnew = EditPicture(pnew);
		cleardevice();
		ShowAllPicture();
		break;
	}
	default:
	{
		cout << "输入错误" << endl;
		cout << endl;
	}
	}
}

//图片删除函数
void DeletePicture()
{
	cout << endl;
	ShowLocation();
	cout << endl;
	cout << "请输入想要删除的图片位置，不想进行该操作请输入0：" << endl;
	int choose1;
	cin >> choose1;
	if (choose1<0||choose1 > i)
	{
		cout << "图片不存在，请重新输入" << endl;
		cout << endl;
		return;
	}
	else if (choose1 == 0)
	{
		return;
	}
	listpicture.deletelist(choose1);
	cleardevice();
	ShowAllPicture();
	cout << "删除成功" << endl;
	cout << endl;
}

//颜色到数字的转化
int ColorToInt(COLORREF c)
{
	if (c == BLUE)
	{
		return 1;
	}
	else if (c == GREEN)
	{
		return 2;
	}
	else if (c == RED)
	{
		return 3;
	}
	else if (c == BLACK)
	{
		return 4;
	}
	else if (c == CYAN)
	{
		return 5;
	}
	else if (c == MAGENTA)
	{
		return 6;
	}
	else if (c == BROWN)
	{
		return 7;
	}
	else if (c == LIGHTGRAY)
	{
		return 8;
	}
	else if (c == DARKGRAY)
	{
		return 9;
	}
	else if (c == LIGHTBLUE)
	{
		return 10;
	}
	else if (c == LIGHTGREEN)
	{
		return 11;
	}
	else if (c == LIGHTCYAN)
	{
		return 12;
	}
	else if (c==LIGHTRED)
	{
		return 13;
	}
	else if (c == LIGHTMAGENTA)
	{
		return 14;
	}
	else if (c == YELLOW)
	{
		return 15;
	}
	else
	{
		return 16;
	}
}

//数字转化为颜色
COLORREF IntToColor(int n)
{
	if (n == 1)
	{
		return BLUE;
	}
	else if (n == 2)
	{
		return GREEN;
	}
	else if (n == 3)
	{
		return RED;
	}
	else if (n == 4)
	{
		return BLACK;
	}
	else if (n == 5)
	{
		return CYAN;
	}
	else if (n == 6)
	{
		return MAGENTA;
	}
	else if (n == 7)
	{
		return BROWN;
	}
	else if (n == 8)
	{
		return LIGHTGRAY;
	}
	else if (n == 9)
	{
		return DARKGRAY;
	}
	else if (n == 10)
	{
		return LIGHTBLUE;
	}
	else if (n == 11)
	{
		return LIGHTGREEN;
	}
	else if (n == 12)
	{
		return LIGHTCYAN;
	}
	else if (n == 13)
	{
		return LIGHTRED;
	}
	else if (n == 14)
	{
		return LIGHTMAGENTA;
	}
	else if (n == 15)
	{
		return YELLOW;
	}
	else 
	{
		return WHITE;
	}
}

//特殊功能函数
void SpecialAbility()
{
	cout << endl;
	cout << "请输入你想编辑的图片序号: " << endl;
	int choose;
	cin >> choose;
	if (choose<=0||choose > i)
	{
		cout << "图片不存在，请重新输入" << endl;
		return;
	}
	Picture* pnew = new Picture;
	pnew = listpicture.FindPicture(choose);
	cout << "请选择你想要的功能:" << endl;
	cout << "1.移动" << endl;
	cout << "2.缩放" << endl;
	cout << "3.复制" << endl;
	int choose1;
	cin >> choose1;
	switch (choose1)
	{
	case 1:
	{
		cout << "以图形所在处为原点，请输入你想移动到的位置：(x,y)" << endl;
		int x, y;
		cin >> x >> y;
		cleardevice();
		ReadPicture(pnew, x, y);
		ShowAllPicture();
		break;
	}
	case 2:
	{ 
		bool key = TextPicture(*pnew);
		if (key == false)
		{
			cout << "图形不符合要求" << endl;
			return;
		}
		cout << "请输入你想的功能：" << endl;
		cout << "1.缩小  2.放大" << endl;
		int choose;
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			int n;
			cout << "请输入缩小倍数:" << endl;
			cin >> n;
			if (pnew->Piece == 4)
			{
				pnew->ChangeRadius(pnew->Getradius()/n);
				cleardevice();
				ReadPicture(pnew, 0, 0);
				ShowAllPicture();

			}
			if (pnew->Piece == 2 || pnew->Piece == 5||pnew->Piece==7)
			{
				int n = pnew->GetNumberPoint();
				Point* po = new Point[n];
				for (int z = 0; z < n; z++)
				{
					po[z] = pnew->GetPoint(z);
				}
				int a=abs(po[0].GetX() - po[1].GetX());
				int b=abs(po[0].GetY() - po[1].GetY());
				po[1].ChangeX(po[0].GetX() + a / n);
				po[1].ChangeY(po[0].GetY() + b / n);
				Picture* pnew2 = new Picture(po, 2, pnew->Piece);
				cleardevice();
				ReadPicture(pnew2, 0, 0);
				ShowAllPicture();
			}
			break;
		}
		case 2:
		{
			int n;
			cout << "请输入放大倍数:" << endl;
			cin >> n;
			if (pnew->Piece == 4)
			{
				pnew->ChangeRadius(pnew->Getradius() * n);
				ReadPicture(pnew, 0, 0);
			}
			if (pnew->Piece == 2 || pnew->Piece == 5 || pnew->Piece == 7)
			{
				int n = pnew->GetNumberPoint();
				Point* po = new Point[n];
				for (int z = 0; z < n; z++)
				{
					po[z] = pnew->GetPoint(z);
				}
				int a = abs(po[0].GetX() - po[1].GetX());
				int b = abs(po[0].GetY() - po[1].GetY());
				po[1].ChangeX(po[0].GetX() + a * n);
				po[1].ChangeY(po[0].GetY() + b * n);
				Picture* pnew2 = new Picture(po, 2, pnew->Piece);
				cleardevice();
				ReadPicture(pnew2, 0, 0);
				ShowAllPicture();
			}
			break;
		}
		default:
		{
			cout << "输入错误" << endl;
			return;
		}
		}
		break;
	}
	case 3:
	{
		cout << "以复制图形为原点,设置显示复制图形的位置" << endl;
		int x, y;
		cin >> x >> y;
			int n = pnew->GetNumberPoint();
			int l = pnew->Piece;
			Point* po = new Point[n];
			for (int z = 0; z < n; z++)
			{
				po[z] = pnew->GetPoint(z);
			}
			for (int z = 0; z < n; z++)
			{
				po[z].ChangeX(po[z].MoveX(x));
				po[z].ChangeY(po[z].MoveY(y));
			}
			if (l == 4)
			{
				int r = pnew->Getradius();
				Picture *b = new Picture(po, n, r,l);
				b->ChangeFillColor(pnew->GetFillColor());
				b->ChangeStyleColor(pnew->GetStyleColor());
				b->ChangeThickness(pnew->GetThickness());
				b->ChangeFillStyle1(pnew->GetFillStyle1());
				b->ChangeFillStyle2(pnew->GetFillStyle2());
				b->ChangeJoint(pnew->GetJoint());
				b->ChangeEndPoint(pnew->GetEndPoint());
				listpicture.tialinsert(b);
			}
			else
			{
				Picture* b = new Picture(po, n, l);
				b->ChangeFillColor(pnew->GetFillColor());
				b->ChangeStyleColor(pnew->GetStyleColor());
				b->ChangeThickness(pnew->GetThickness());
				b->ChangeFillStyle1(pnew->GetFillStyle1());
				b->ChangeFillStyle2(pnew->GetFillStyle2());
				b->ChangeJoint(pnew->GetJoint());
				b->ChangeEndPoint(pnew->GetEndPoint());
				listpicture.tialinsert(b);
			}
			cleardevice();
			ShowAllPicture();
		break;
	}
	default:
	{
		cout << "输入错误" << endl;
		cout << endl;
	}
	}
	cout << endl;
}

//写文件打开函数
void OpenInputFile()
{
	ofstream file1("d:\\Picture.txt");
	if (!file1)
	{
		cout << "不能打开文件" << endl;
		exit(1);
	}
	file1 << i << endl;
	for (int z = 0; z < i; z++)
	{
		Picture* pnew = listpicture.FindPicture(z+1);
		file1 << pnew->Piece<<" ";
		int n1= ColorToInt(pnew->GetFillColor());
		file1 << n1 << " ";
		int n2 = ColorToInt(pnew->GetStyleColor());
		file1 << n2 << " ";
		file1 << pnew->GetThickness() << " " << pnew->LocalX << " " << pnew->LocalY << " " << pnew->endPoint << " ";
		file1 << pnew->joint << " " << pnew->NumberPoint<<" "<<pnew->GetFillStyle1()<<" "<<pnew->GetFillStyle2()<<" ";
		Point* po = new Point[pnew->NumberPoint];
		for (int l = 0; l < pnew->NumberPoint; l++)
		{
			po[l] = pnew->GetPoint(l);
		}
		for (int l = 0; l < pnew->NumberPoint; l++)
		{
			file1 << po[l].GetX() << " " << po[l].GetY() << " ";
		}
		if (pnew->Piece == 4)
		{
			file1 << pnew->radius;
		}
		file1<<'\n';
	}
	cout << "成功存入"<<i<<"个数据" << endl;
	int length = i;
	for (int z = 0; z < length; z++)
	{
		listpicture.deletelist(1);
	}
	key=1;
	cout << endl;
}

//读文件打开函数
void OpenOutFile()
{
	int length;
	ifstream file1("d:\\Picture.txt");
	if (!file1)
	{
		cout << "不能打开文件" << endl;
		exit(1);
	}
	file1 >> length;
	if (length <= 0 || length>100)
	{
		cout << "文件为空,请绘制图形" << endl;
		cout << endl;
		return;
	}
	for (int z = 0; z < length; z++)
	{
		Picture* pnew = new Picture;
		file1 >> pnew->Piece >> pnew->color1>>pnew->color2>>pnew->thickness>>pnew->LocalX>>pnew->LocalY;
		file1 >> pnew->endPoint >> pnew->joint >> pnew->NumberPoint>>pnew->fillstyle1>>pnew->fillstyle2;
		Point* po = new Point[pnew->NumberPoint];
		for (int l = 0; l < pnew->NumberPoint; l++)
		{
			file1 >> po[l].X >> po[l].Y;
		}
		pnew->p1 = new Point[pnew->NumberPoint];
		for (int l = 0; l < pnew->NumberPoint; l++)
		{
			pnew->p1[l] = po[l];
		}
		pnew->fillColor=IntToColor(pnew->color1);
		pnew->styleColor = IntToColor(pnew->color2);
		if (pnew->Piece == 4)
		{
			file1 >> pnew->radius;
		}
		listpicture.tialinsert(pnew);
	}
	cout << "读取成功" << endl;
	cout <<"文件流出"<< length <<"个数据"<< endl;
	cout << "是否展示全部图片: " << endl;
	cout << "1.Yes 2.No" << endl;
	int choose;
	cin >> choose;
	if (choose == 1)
	{
		ShowAllPicture();
	}
	else if(choose!=1&&choose!=0)
	{
		cout << "您的输入错误，已经为您退出到菜单栏" << endl;
	}
	cout << endl;
}

//特殊填充编辑功能
void SpecialEditPicture()
{
	cout << endl;
	cout << "请输入你想编辑的图片序号: " << endl;
	int choose;
	cin >> choose;
	if (choose<0||choose > i)
	{
		cout << "图片不存在，请重新输入" << endl;
		return;
	}
	Picture* pnew= listpicture.FindPicture(choose);
	int choose1;
	cout << "请输入你想要的特殊功能" << endl;
	cout << "请确定线型" << endl;
	cout << "0.固实填充:" << endl;
	cout << "1.不填充  ：" << endl;
	cout << "2.图案填充：" << endl;
	cin >> choose1;
	switch (choose1)
	{
	case 0:
	{
		pnew->ChangeFillStyle1(choose1);
		pnew->ChangeFillStyle2(NULL);
		cleardevice();
		ShowAllPicture();
		break;
	}
	case 1:
	{
		pnew->ChangeFillStyle1(choose1);
		pnew->ChangeFillStyle2(NULL);
		cleardevice();
		ShowAllPicture();
		break;
	}
	case 2:
	{
		pnew->ChangeFillStyle1(choose1);
		cout << "请选择指定填充样式" << endl;
		cout << "请选择样式：" << endl;
		cout << "0.横线" << endl;
		cout << "1.竖线" << endl;
		cout << "2.\\斜线" << endl;
		cout << "3.//斜线" << endl;
		cout << "4.#线" << endl;
		cout << "5.栏线" << endl;
		int choose2;
		cin >> choose2;
		pnew->ChangeFillStyle2(choose2);
		cleardevice();
		ShowAllPicture();
		break;
	}
	default:
	{
		cout << "输入错误" << endl;
		cout << endl;
	}
	}
}

//菜单函数
void ShowMenu()
{
	initgraph(WIDTH, HEIGHT, SHOWCONSOLE);
	int choose;
	while (1)
	{
		cout << "欢迎使用简单矢量图形处理系统" << endl;
		cout << "请选择您想要的操作" << endl;
		cout << "0 - 退出系统" << endl;
		cout << "1 - 绘制图形" << endl;
		cout << "2 - 显示图片数据" << endl;
		cout << "3 - 编辑图形" << endl;
		cout << "4 - 删除图片" << endl;
		cout << "5 - 图形的移动、缩放、复制功能" << endl;
		cout << "6 - 存储目前图片数据" << endl;
		cout << "7 - 读取目前图片数据" << endl;
		cout << "8 - 特殊的图形编辑（线填充、固实填充和不填充）" << endl;
		cout << "9 - 显示全部图片" << endl;
		cout << "请选择操作:";
		if (!(cin >> choose))
		{
			cout << "输入错误了，亲" << endl;
			return;
		}
		switch (choose)
		{
		case 0:
		{
			if (key != 1)
			{
				int choose1;
				cout << "未保存图片,是否不保存退出，如果是请输入1，保存退出请输入0" << endl;
				cin >> choose1;
				if (choose1 == 1)
				{
					return;
				}
				else if (choose1 == 0)
				{
					OpenInputFile();
					cout << endl;
					return;
				}
				else
				{
					cout << "输入不标准" << endl;
					break;
				}
			}
			else
				return;
		}
		case 1:
		{
			CreatePicture();
			if (i > 0)
				key--;
			break;
		}
		case 2:
		{
			key--;
			ShowLocation();
			break;
		}
		case 3:
		{
			EditPictureMenu();
			key--;
			break;
		}
		case 4:
		{
			key--;
			DeletePicture();
			break;
		}
		case 5:
		{
			key--;
			SpecialAbility();
			break;
		}
		case 6:
		{
			key--;
			OpenInputFile();
			break;
		}
		case 7:
		{
			key--;
			OpenOutFile();
			break;
		}
		case 8:
		{
			key--;
			SpecialEditPicture();
			break;
		}
		case 9:
		{
			key--;
			cleardevice();
			ShowAllPicture();
			break;
		}
		default:
		{
			cout << "输入错误" << endl;
			cout << endl;
		}
		}
	}
};
int main()
{
	ShowMenu();
	return 0;
}