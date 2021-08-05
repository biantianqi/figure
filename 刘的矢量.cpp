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
	int radius=0;      //�뾶
	int NumberPoint=0;//ͼ�εĵ���
	COLORREF fillColor=  WHITE;    //ͼ�������ɫ
	COLORREF styleColor= WHITE;    //ͼ������ɫ
	int thickness=1;        //�߿�
	int fillstyle1=0;            //�������1
	int fillstyle2=0;            //�������2
	int style1=0;                //����1
	int joint=-1;                //���Ӵ���ʽ
	int endPoint=-1;             //�˵���ʽ
	int LocalX = 0;                 //ͼ�εĺ�����λ��
	int LocalY = 0;                 //ͼ�ε�������λ��
	int color1=0;                    //���ɫ
	int color2=0;                    //����ɫ
	friend class ListPicture;
	friend void OpenInputFile();
	friend void OpenOutFile();
public:
	int Piece;//ͼ������
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
	void ChangeFillStyle1(int n)//�޸��������ʽ
	{
		fillstyle1 = n;
	}
	void ChangeFillStyle2(int n)//�޸��������ʽ
	{
		fillstyle2 = n;
	}
	void ChangeFillColor(COLORREF c)//�޸������ɫ
	{
		fillColor=c;  
	}
	void ChangeStyleColor(COLORREF c)//�޸�����ɫ
	{
		styleColor = c;
	}
	void ChangeThickness(int n)//�޸��߿�
	{
		thickness = n;
	}
	void ChangeStyle1(int n)//�޸�����
	{
		style1 = n;
	}
	void ChangeJoint(int n)//�޸����Ӵ���ʽ
	{
		joint = n;
	}
	void ChangeEndPoint(int n)//�޸Ķ˵���ʽ
	{
		endPoint = n;
	}
	void ChangeLocalX(int x)//�޸�ͼ��ĺ�����
	{
		LocalX = x;
	}
	void ChangeLocalY(int y)//�޸�ͼ���������
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
//�������ݿ�
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
//���ݴ洢
ListPicture listpicture;

//��ʾȫ��ͼ��
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
			cout << "�������" << endl;
		}
		z++;
	}
	cout << endl;
}

//��ʾ����
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
			cout << "�� " << "λ��: " << po->GetX() << "," << po->GetY();
			cout << endl;
			break;
		}
		case 2:
		{
			cout << "�� " << "����λ��: ";
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
			cout << "���� " << "����λ��: ";
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
			cout << "Բ " << "Բ��λ��: ";
			Point* po = pnew.GetPoint();
			cout << po->GetX() << "," << po->GetY() << " ";
			cout << endl;
			break;
		}
		case 5:
		{
			cout << "����" << "����λ��: ";
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
			cout << "�����" << "����λ��: ";
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
			cout << "��Բ" << "����λ��: ";
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

//����༭����ʵ�ֺ���
Picture* EditPicture(Picture* po)
{
	int choose;
	COLORREF* c = new COLORREF;
	COLORREF* c1 = new COLORREF;
	while (1)
	{
		cout << "��ѡ��������еı༭����" << endl;
		cout << "0.�˳��ù���" << endl;
		cout << "1.�༭ͼ�������ɫ" << endl;
		cout << "2.�༭ͼ������" << endl;
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
			cout << "��ѡ����ɫ����" << endl;
			cout << "1.��ɫ" << endl;
			cout << "2.��ɫ" << endl;
			cout << "3.��ɫ" << endl;
			cout << "4.��ɫ" << endl;
			cout << "5.��ɫ" << endl;
			cout << "6.��ɫ" << endl;
			cout << "7.��ɫ" << endl;
			cout << "8.ǳ��" << endl;
			cout << "9.���" << endl;
			cout << "10.����" << endl;
			cout << "11.����" << endl;
			cout << "12.����" << endl;
			cout << "13.����" << endl;
			cout << "14.����" << endl;
			cout << "15.��" << endl;
			cout << "16.��" << endl;
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
				cout << "�������" << endl;
				cout << endl;
			}
			}
			po->ChangeFillColor(*c1);
			ShowAllPicture();
			break;
		}
		case 2:
		{
			cout << "��ѡ����Ҫ���е�ͼ���ߵı༭������" << endl;
			cout << "0.�˳��ù���" << endl;
			cout << "1.�༭��ɫ" << endl;
			cout << "2.�༭����" << endl;
			cout << "3.�༭�˵�" << endl;
			cout << "4.�༭���Ӵ�" << endl;
			cout << "5.�༭ͼ���߿�" << endl;
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
				cout << "��ѡ����ɫ����" << endl;
				cout << "1.��ɫ" << endl;
				cout << "2.��ɫ" << endl;
				cout << "3.��ɫ" << endl;
				cout << "4.��ɫ" << endl;
				cout << "5.��ɫ" << endl;
				cout << "6.��ɫ" << endl;
				cout << "7.��ɫ" << endl;
				cout << "8.ǳ��" << endl;
				cout << "9.���" << endl;
				cout << "10.����" << endl;
				cout << "11.����" << endl;
				cout << "12.����" << endl;
				cout << "13.����" << endl;
				cout << "14.����" << endl;
				cout << "15.��" << endl;
				cout << "16.��" << endl;
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
					cout << "�������" << endl;
					cout << endl;
				}
				}
				po->ChangeStyleColor(*c);
				ShowAllPicture();
				break;
			}
			case 2:
			{
				cout << "��ѡ������:" << endl;
				cout << "0.����Ϊʵ��" << endl;
				cout << "1.����Ϊ��------------" << endl;
				cout << "2.����Ϊ��������������������������" << endl;
				cout << "3.����Ϊ�� - �� - �� - �� - �� - �� - ��" << endl;
				cout << "4.����Ϊ��-����-����-����-����" << endl;
				cout << "5.����Ϊ���ɼ�" << endl;
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
					cout << "�������" << endl;
					cout << endl;
				}
				}
				ShowAllPicture();
				break;
			}
			case 3:
			{
				cout << "��ѡ��˵���ʽ" << endl;
				cout << "0.�˵�ΪԲ��" << endl;
				cout << "1.�˵�Ϊ����" << endl;
				cout << "2.�˵�Ϊƽ̹" << endl;
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
					cout << "�������" << endl;
					cout << endl;
				}
				}
				ShowAllPicture();
				break;
			}
			case 4:
			{
				cout << "��ѡ�����Ӵ���ʽ" << endl;
				cout << "0.���Ӵ�Ϊб��" << endl;
				cout << "1.���Ӵ�Ϊб��" << endl;
				cout << "2.���Ӵ�ΪԲ��" << endl;
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
					cout << "�������" << endl;
				}
				ShowAllPicture();
				break;
			}
			case 5:
			{
				int width;
				cout << "�������߿�" << endl;
				cin >> width;
				po->ChangeThickness(width);
				ShowAllPicture();
				break;
			}
			default:
			{
				cout << "�������" << endl;
				cout << endl;
			}
			}

			break;
		}
		default:
		{
			cout << "�������" << endl;
			cout << endl;
		}
		}
	}
}

//���ͼ���Ƿ�������⹦������
bool TextPicture(Picture pnew)
{
	if (pnew.Piece == 1 || pnew.Piece == 3 || pnew.Piece == 6)
		return false;
	else
		return true;
}

//��ȡͼƬ
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
		cout << "�������" << endl;
		cout << endl;
	}
	}
}

//����ͼ�εĲ˵���
void CreatePicture()
{
	cout << endl;
	int choose;
	while (1)
	{
		cout << "������ͼ�����" << endl;
		cout << "0.�˳��ù���" << endl;
		cout << "1.��" << endl;
		cout << "2.ֱ��" << endl;
		cout << "3.����" << endl;
		cout << "4.Բ" << endl;
		cout << "5.����" << endl;
		cout << "6.�����" << endl;
		cout << "7.��Բ" << endl;
		cout << "��ѡ��ͼ������: ";
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
			cout << "������������:";
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
			cout << "�������������:";
			int x1, y1;
			cin >> x1 >> y1;
			cout << "�������յ�����:";
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
			cout << "�������۵���" << endl;
			cin >> number;
			cout << "��������������" << endl;
			int* m = new int[2 * number];
			Point* a = new Point[number];
			for (int z = 0; z < 2 * number; z++)
			{
				if (z % 2 == 0)
				{
					cout << "����������x:";
				}
				else
				{
					cout << "����������y:";
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
			cout << "������Բ������:";
			cin >> x >> y;
			cout << "������Բ�İ뾶:";
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
			cout << "��������ε�����:" << endl;
			cout << "���������Ͻ�����:" ;
			cin >> x1 >> y1;
			cout << "���������½�����:" ;
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
			cout << "�������۵���" << endl;
			cin >> number;
			cout << "��������������" << endl;
			int* m = new int[2 * number];
			for (int z = 0; z < 2 * number; z++)
			{
				if (z % 2 == 0)
				{
					cout << "����������x:";
				}
				else
				{
					cout << "����������y:";
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
			cout << "��������Բ������" << endl;
			cout << "���������Ͻ�����:" ;
			cin >> x1 >> y1;
			cout << "���������½�����:";
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
			cout << "�������" << endl;
			cout << endl;
		}
		}
	}
}

//�༭ͼƬ�˵�
void EditPictureMenu()
{
	cout << endl;
	ShowLocation();
	cout << endl;
	cout << "����������༭��ͼƬ���: " << endl;
	int choose1;
	cin >> choose1;
	if (choose1<=0&&choose1 > i)
	{
		cout << "ͼƬ�����ڣ�����������" << endl;
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
		cout << "�������" << endl;
		cout << endl;
	}
	}
}

//ͼƬɾ������
void DeletePicture()
{
	cout << endl;
	ShowLocation();
	cout << endl;
	cout << "��������Ҫɾ����ͼƬλ�ã�������иò���������0��" << endl;
	int choose1;
	cin >> choose1;
	if (choose1<0||choose1 > i)
	{
		cout << "ͼƬ�����ڣ�����������" << endl;
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
	cout << "ɾ���ɹ�" << endl;
	cout << endl;
}

//��ɫ�����ֵ�ת��
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

//����ת��Ϊ��ɫ
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

//���⹦�ܺ���
void SpecialAbility()
{
	cout << endl;
	cout << "����������༭��ͼƬ���: " << endl;
	int choose;
	cin >> choose;
	if (choose<=0||choose > i)
	{
		cout << "ͼƬ�����ڣ�����������" << endl;
		return;
	}
	Picture* pnew = new Picture;
	pnew = listpicture.FindPicture(choose);
	cout << "��ѡ������Ҫ�Ĺ���:" << endl;
	cout << "1.�ƶ�" << endl;
	cout << "2.����" << endl;
	cout << "3.����" << endl;
	int choose1;
	cin >> choose1;
	switch (choose1)
	{
	case 1:
	{
		cout << "��ͼ�����ڴ�Ϊԭ�㣬�����������ƶ�����λ�ã�(x,y)" << endl;
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
			cout << "ͼ�β�����Ҫ��" << endl;
			return;
		}
		cout << "����������Ĺ��ܣ�" << endl;
		cout << "1.��С  2.�Ŵ�" << endl;
		int choose;
		cin >> choose;
		switch (choose)
		{
		case 1:
		{
			int n;
			cout << "��������С����:" << endl;
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
			cout << "������Ŵ���:" << endl;
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
			cout << "�������" << endl;
			return;
		}
		}
		break;
	}
	case 3:
	{
		cout << "�Ը���ͼ��Ϊԭ��,������ʾ����ͼ�ε�λ��" << endl;
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
		cout << "�������" << endl;
		cout << endl;
	}
	}
	cout << endl;
}

//д�ļ��򿪺���
void OpenInputFile()
{
	ofstream file1("d:\\Picture.txt");
	if (!file1)
	{
		cout << "���ܴ��ļ�" << endl;
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
	cout << "�ɹ�����"<<i<<"������" << endl;
	int length = i;
	for (int z = 0; z < length; z++)
	{
		listpicture.deletelist(1);
	}
	key=1;
	cout << endl;
}

//���ļ��򿪺���
void OpenOutFile()
{
	int length;
	ifstream file1("d:\\Picture.txt");
	if (!file1)
	{
		cout << "���ܴ��ļ�" << endl;
		exit(1);
	}
	file1 >> length;
	if (length <= 0 || length>100)
	{
		cout << "�ļ�Ϊ��,�����ͼ��" << endl;
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
	cout << "��ȡ�ɹ�" << endl;
	cout <<"�ļ�����"<< length <<"������"<< endl;
	cout << "�Ƿ�չʾȫ��ͼƬ: " << endl;
	cout << "1.Yes 2.No" << endl;
	int choose;
	cin >> choose;
	if (choose == 1)
	{
		ShowAllPicture();
	}
	else if(choose!=1&&choose!=0)
	{
		cout << "������������Ѿ�Ϊ���˳����˵���" << endl;
	}
	cout << endl;
}

//�������༭����
void SpecialEditPicture()
{
	cout << endl;
	cout << "����������༭��ͼƬ���: " << endl;
	int choose;
	cin >> choose;
	if (choose<0||choose > i)
	{
		cout << "ͼƬ�����ڣ�����������" << endl;
		return;
	}
	Picture* pnew= listpicture.FindPicture(choose);
	int choose1;
	cout << "����������Ҫ�����⹦��" << endl;
	cout << "��ȷ������" << endl;
	cout << "0.��ʵ���:" << endl;
	cout << "1.�����  ��" << endl;
	cout << "2.ͼ����䣺" << endl;
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
		cout << "��ѡ��ָ�������ʽ" << endl;
		cout << "��ѡ����ʽ��" << endl;
		cout << "0.����" << endl;
		cout << "1.����" << endl;
		cout << "2.\\б��" << endl;
		cout << "3.//б��" << endl;
		cout << "4.#��" << endl;
		cout << "5.����" << endl;
		int choose2;
		cin >> choose2;
		pnew->ChangeFillStyle2(choose2);
		cleardevice();
		ShowAllPicture();
		break;
	}
	default:
	{
		cout << "�������" << endl;
		cout << endl;
	}
	}
}

//�˵�����
void ShowMenu()
{
	initgraph(WIDTH, HEIGHT, SHOWCONSOLE);
	int choose;
	while (1)
	{
		cout << "��ӭʹ�ü�ʸ��ͼ�δ���ϵͳ" << endl;
		cout << "��ѡ������Ҫ�Ĳ���" << endl;
		cout << "0 - �˳�ϵͳ" << endl;
		cout << "1 - ����ͼ��" << endl;
		cout << "2 - ��ʾͼƬ����" << endl;
		cout << "3 - �༭ͼ��" << endl;
		cout << "4 - ɾ��ͼƬ" << endl;
		cout << "5 - ͼ�ε��ƶ������š����ƹ���" << endl;
		cout << "6 - �洢ĿǰͼƬ����" << endl;
		cout << "7 - ��ȡĿǰͼƬ����" << endl;
		cout << "8 - �����ͼ�α༭������䡢��ʵ���Ͳ���䣩" << endl;
		cout << "9 - ��ʾȫ��ͼƬ" << endl;
		cout << "��ѡ�����:";
		if (!(cin >> choose))
		{
			cout << "��������ˣ���" << endl;
			return;
		}
		switch (choose)
		{
		case 0:
		{
			if (key != 1)
			{
				int choose1;
				cout << "δ����ͼƬ,�Ƿ񲻱����˳��������������1�������˳�������0" << endl;
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
					cout << "���벻��׼" << endl;
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
			cout << "�������" << endl;
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