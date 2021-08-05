#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include<cstring>
#include<fstream>
#include<cmath>
#define W 1000
#define H 1000
#include<iostream>
int z = 1;
int gg = 1;
int flag = 1;
int k1 = 0;    //����ͼ�εĸ���,�����
int k2 = 0;
int k3 = 0;
int k4 = 0;
int k5 = 0;
int k6 = 0; 
int k7 = 0;

int n1;//���ߵ�ĸ���
int n2;//����ε�ĸ���
#define max 30
using namespace std;
class picture        //�������һЩͼ�ε�����
{
protected:
	double width;
	int color1, color2;
public:
	picture() {}
	picture(int color1, int color2) : color1(color1), color2(color2) {}
	picture(int color1) :color1(color1) {}
	virtual void open()
	{
		initgraph(W, H, SHOWCONSOLE);
	}
	virtual void setw(double width)
	{
		setlinestyle(PS_SOLID, width);//�������ͣ��߿�             //�˴���Ҫ���Ӷ����͸��ĵĹ���
	}
	virtual void setc1(int color1)
	{
		if (color1 == 1)
			setlinecolor(RED);//��������ɫ
		if (color1 == 2)
			setlinecolor(BLUE);
		if (color1 == 3)
			setlinecolor(YELLOW);
		if (color1 == 4)
			setlinecolor(WHITE);
	}
	virtual void setc2(int color2)
	{
		if (color2 == 1)
			setfillcolor(RED); //���������ɫ
		if (color2 == 2)
			setfillcolor(BLUE);
		if (color2 == 3)
			setfillcolor(YELLOW);
		if (color2 == 4)
			setfillcolor(WHITE);
	}
};










class drawpoint: public picture
{
public:
	int x, y;
	int color;
	drawpoint() {};
	drawpoint(int x,int y):x(x),y(y){}
	void add();//��ӹ���
	void save();  //�洢���ݵ��ļ�
	void change();//�༭����
	void input();//���빦��
	void move();//�ƶ�����
	void copy();//��������
	void zoom();//���Ź���
	void cut(); //ɾ��ͼƬ����
	void open();//���ļ�����
};
drawpoint p1[max];
void drawpoint::add()
{

}
void drawpoint::save()
{

}
void drawpoint::change()
{

}
void drawpoint::input()
{

}
void drawpoint::move()
{

}
void drawpoint::copy()
{

}
void drawpoint::zoom()
{

}
void drawpoint::cut()
{

}
void drawpoint::open()
{

}




class drawline :public picture
{
	
public:
	int x, y, xx, yy, width;
	int color1, ID;

	drawline() {};
	drawline(int ID,int x,int y,int xx,int yy,int width, int color1):ID(ID),x(x),y(y),xx(xx),yy(yy), width(width),color1(color1){}

	void add();//��ӹ���
	void save();  //�洢���ݵ��ļ�
	void change();//�༭����
	void input();//���빦��
	void move();//�ƶ�����
	void copy();//��������
	void zoom();//���Ź���
	void cut(); //ɾ��ͼƬ����
	void open();//���ļ�����
};
drawline p2[max];
void drawline::add()
{
	cout << "������ֱ�߱�ţ���1��ʼ" << endl;
	int x, y, xx, yy, width, color1, ID;
	cin >> ID;
	cout << "������x��y,xx,,yy������" << endl;
	cin >> x >> y >> xx >> yy;
	p2[k2].ID = ID;
	p2[k2].x = x;          //��1��ʼ��
	p2[k2].y = y;
	p2[k2].xx = xx;
	p2[k2].yy = yy;
	cout << "�������߿��" << endl;
	cin >> width;
	p2[k2].width = width;
	cout << "������������ɫ��1��ɫ   2��ɫ   3��ɫ   4��ɫ" << endl;
	cin >> color1;
	p2[k2].color1 = color1;
}
void drawline::save()
{
	
	ofstream out;
	out.open("��.txt", ios::out);
		if (!out)
		{
			cerr << "fail" << endl;
			return ;
		}
		for (int i = 1;i<=k2;i++)
		{
			out <<p2[i].ID<<" "<< p2[i].x << " " << p2[i].y << " " << p2[i].xx << " " << p2[i].yy << " "  << p2[i].width << " " << p2[i].color1 << endl;
		}
		out.close();

		cout << "����ɹ�" << endl;
		system("pause");
}
void drawline::input()
{
	cout << "�ٴ�ȷ�������޸ĵ�ͼ�εı��" << endl;
	cin >> ID;
	cout << "������x��y,xx,,yy������" << endl;
	cin >> x >> y >> xx >> yy;
	cout << "�������߿��" << endl;
	cin >> width;
	cout << "������������ɫ��1��ɫ   2��ɫ   3��ɫ   4��ɫ" << endl;
	cin >> color1;
}
void drawline::change()
{
	cout << "�������޸�ֱ�ߵĲ���,�������޸ĵڼ���ֱ��" << endl;
	int t;
	cin >> t;
	
	this->input();
	p2[t] = *this;
	cout << "�༭�ɹ�" << endl;
	save();
	cleardevice();
}
void drawline::move()
{
	cout << "�����ƶ��ڼ���ֱ��" << endl;
	int t;
	cin >> t;
	cout << "���������뽫���λ���Ƶ�������" << endl;
	int x, y;
	cin >> x >> y;
	int w = abs(p2[t].xx - p2[t].x);
	int h = abs(p2[t].yy - p2[t].y);
	p2[t].x = x;
	p2[t].y = y;
	p2[t].xx = p2[t].x+w;
	p2[t].yy = p2[t].y + h;
	save();
	cleardevice();
}
void drawline::copy()
{
	cout << "���븴�Ƶڼ���ֱ��" << endl;
	int t;
	cin >> t;
	cout << "�����뽫����Ƶ�ʲôλ�ã���x,y������" << endl;
	int x, y;
	cin >> x >> y;
	k2++;
	p2[k2].ID = k2;
	int w = abs(p2[t].xx - p2[t].x);
	int h = abs(p2[t].yy - p2[t].y);
	p2[k2].x = x;
	p2[k2].y = y;
	p2[k2].xx = p2[t].x + w;
	p2[k2].yy = p2[t].y + h;
	p2[k2].width = p2[t].width;
	p2[k2].color1 = p2[k2].color1;
	save();
	cleardevice();
}
void drawline::zoom()
{
	cout << "�������ŵڼ���ֱ��" << endl;
	int t;
	cin >> t;
	cout << "������������ű���" << endl;
	int time;
	cin >> time;
	int w = abs(p2[t].xx - p2[t].x);
	int h = abs(p2[t].yy - p2[t].y);

	int x1 = (p2[t].x + p2[t].xx) / 2;
	int y1 = (p2[t].y + p2[t].yy) / 2;  //�е�����
	if (time <= 1)    //�е����⣬�������໹���Ҳ�
	{
		p2[t].x = p2[t].x + w / 2 * (1 - time);
		p2[t].y = p2[t].y + h / 2 * (1 - time);
		p2[t].xx = p2[t].xx - w / 2 * (1 - time);
		p2[t].yy = p2[t].yy -h / 2 * (1 - time);
	}
	if (time > 1)
	{
		p2[t].x = p2[t].x - w / 2 * (time - 1);
		p2[t].y = p2[t].y - h / 2 * (time - 1);
		p2[t].xx = p2[t].xx + w / 2 * (time - 1);
		p2[t].yy = p2[t].yy - h / 2 * (time - 1);
	}
	save();
	cleardevice();
}
void drawline::cut()
{
	cout << "����ɾ���ڼ���ֱ��" << endl;
	int t;
	cin >> t;
	p2[t].ID = 0;
	p2[t].x = 0;
	p2[t].y = 0;
	p2[t].xx = 0;
	p2[t].yy = 0;
	p2[t].width = 0;
	p2[t].color1 = 0;
	save();
	cleardevice();
}
void drawline::open()
{
	int q;
	cout << "��ȫ���ļ���1���򿪲����ļ���2" << endl;
	cin >>q;
	ifstream in2;
	in2.open("��.txt", ios::in);
	if (q == 1)
	{
		int i2 = 1;         //�����ߵĲ���
		
		if (!in2)
		{
			cerr << "fail" << endl; return;
		}
		while (true)
		{
			in2 >> p2[i2].ID >> p2[i2].x >> p2[i2].y >> p2[i2].xx >> p2[i2].yy >> p2[i2].width >> p2[i2].color1;
			picture p;
			p.setc1(p2[i2].color1);
			p.setw(p2[i2].width);
			line(p2[i2].x, p2[i2].y, p2[i2].xx, p2[i2].yy);
			if (in2.eof())break;

			i2++;
		}
	}
	if (q == 2)
	{
		cout << "�������ֱ���ļ������" << endl;
		int t;
		cin >> t;
		if (t > k2)
		{
			cout << "���ļ�δ����" << endl;
		}
		else
		{
			in2 >> p2[t].ID >> p2[t].x >> p2[t].y >> p2[t].xx >> p2[t].yy >> p2[t].width >> p2[t].color1;
			picture p;
			p.setc1(p2[t].color1);
			p.setw(p2[t].width);
			line(p2[t].x, p2[t].y, p2[t].xx, p2[t].yy);
		}
	}
}
















class drawbrokenline:public picture
{
public:
	int ID, point[10][2];
	int width, color1;
	void add();//��ӹ���
	void save();  //�洢���ݵ��ļ�
	void change();//�༭����
	void input();//���빦��
	void move();//�ƶ�����
	void copy();//��������
	void zoom();//���Ź���
	void cut(); //ɾ��ͼƬ����
	void open();//���ļ�����
};
drawbrokenline p3[max];
void drawbrokenline::add()
{
	int ID;
	cout << "���������߱�ţ���1��ʼ" << endl;
	cin >> ID;
	cout << "�������۵�ĸ���" << endl;
	
	cin >> n1;
	int x, y, width, color1;
	
	for (int i = 1; i <=n1; i++)
	{
		cout << "������x��y������" << endl;
		cin >> x >> y;
		p3[k3].ID = ID;
		p3[k3].point[i][0] = x;          //��1��ʼ��
		p3[k3].point[i][1] = y;

		if (i == n1)cout << "¼�����" << endl;
	}
	cout << "�������߿��" << endl;
	cin >> width;
	p3[k3].width = width;
	cout << "������������ɫ��1��ɫ   2��ɫ   3��ɫ   4��ɫ" << endl;
	cin >> color1;
	p3[k3].color1 = color1;
}
void drawbrokenline::save()
{
	ofstream out;
	out.open("����.txt", ios::out);
	if (!out)
	{
		cerr << "fail" << endl;
		return;
	}
	for (int i = 1; i <= k3; i++)
	{
		out << p3[i].ID << " ";
		for (int t = 1; t <= n1; t++)
		{
			out << p3[i].point[t][0] << " " << p3[i].point[t][1]<<" ";
		}
		out<< " " << p3[i].width << " " << p3[i].color1 << endl;
	}
	out.close();

	cout << "����ɹ�" << endl;
	system("pause");
}
void drawbrokenline::change()
{

}
void drawbrokenline::input()
{

}
void drawbrokenline::move()
{

}
void drawbrokenline::copy()
{

}
void drawbrokenline::cut()
{

}
void drawbrokenline::zoom()
{

}
void drawbrokenline::open()
{

}





class drawcircle :public picture
{
public:
	int x, y, r, width;
	int color1;
	int color2;
	int ID;
	drawcircle() {};
	drawcircle(int ID,int x, int y, int r, int width, int color1) :ID(ID),x(x), y(y), r(r), width(width), color1(color1), color2(color2){}

	void add();
	void save();  //�洢���ݵ��ļ�
	void change();
	void input();
	void move();
	void copy();
	void zoom();//���Ź���
	void cut(); //ɾ��ͼƬ����
	void open();//���ļ�����
};
drawcircle p4[max];
void drawcircle::add()
{
	cout << "������Բ�α�ţ���1��ʼ" << endl;
	cin >> ID;
	int x, y, r, width, color1, color2;
	cout << "������x��y,r" << endl;
	cin >> x >> y >> r;
	p4[k4].ID = ID;
	p4[k4].x = x;          //��1��ʼ��
	p4[k4].y = y;
	p4[k4].r = r;
	cout << "�������߿��" << endl;
	cin >> width;
	p4[k4].width = width;
	cout << "������������ɫ��1��ɫ   2��ɫ   3��ɫ   4��ɫ" << endl;
	cin >> color1;
	p4[k4].color1 = color1;
	cout << "�����������ɫ��1��ɫ   2��ɫ   3��ɫ   4��ɫ" << endl;
	cin >> color2;
	p4[k4].color2 = color2;
}
void drawcircle::input()
{
	cout << "��ȷ������Ҫ�޸ĵ�Բ�ı��" << endl;
	cin >> ID;
	cout << "������x��y,r" << endl;
	cin >> x >> y >> r;
	cout << "�������߿��" << endl;
	cin >> width;
	cout << "������������ɫ��1��ɫ   2��ɫ   3��ɫ   4��ɫ" << endl;
	cin >> color1;
	cout << "�����������ɫ��1��ɫ   2��ɫ   3��ɫ   4��ɫ" << endl;
	cin >> color2;
}
void drawcircle::change()
{
	cout << "�������޸�Բ�Ĳ���,������ڼ���Բ" << endl;
	int t;
	cin >> t;
	this->input();
	p4[t] = *this;
	cout << "�༭�ɹ�" << endl;
	save();
	cleardevice();
}
void drawcircle::move()
{
	cout << "�����ƶ��ڼ���Բ" << endl;
	int t;
	cin >> t;
	cout << "���������뽫Բ���Ƶ�������x,y" << endl;
	int x, y;
	cin >> x >> y;

	p4[t].x = x;
	p4[t].y = y;
	save();
	cleardevice();
}
void drawcircle::zoom()
{
	cout << "�������ŵڼ���Բ" << endl;
	int t;
	cin >> t;
	cout << "������������ű���" << endl;
	int time;
	cin >> time;
	p4[t].r = p4[t].r * time;
	save();
	cleardevice();
}
void drawcircle::copy()
{
	cout << "���븴�Ƶڼ���Բ" << endl;
	int t;
	cin >> t;
	cout << "�����븴��Բ�ĵ�ʲôλ�ã���x,y������" << endl;
	int time;
	int x, y;
	cin >> x >> y;
	k4++;
	p4[k4].ID = k4;
	p4[k4].x = x;
	p4[k4].y = y;
	p4[k4].r = p4[t].r;
	p4[k4].width = p4[t].width;
	p4[k4].color1 = p4[k4].color1;
	p4[k4].color2 = p4[k4].color2;
	save();
	cleardevice();
}
void drawcircle::save()
{
	ofstream out;
	out.open("Բ.txt", ios::out);
	if (!out)
	{
		cerr << "fail" << endl;
		return;
	}
	for (int i = 1; i <= k4; i++)
	{
		out << p4[i].ID << " " << p4[i].x << " " << p4[i].y << " " << p4[i].r << " " << p4[i].width << " " << p4[i].color1 << " " << p4[i].color2 << endl;
	}
	out.close();

	cout << "����ɹ�" << endl;
	system("pause");
}
void drawcircle::open()
{
	int q;
	cout << "��ȫ���ļ���1���򿪲����ļ���2" << endl;
	cin >> q;
	int i4 = 1;         //����Բ�Ĳ���
	ifstream in4;
	in4.open("Բ.txt", ios::in);
	if (q == 1)
	{
		int i4 = 1;         //����Բ�Ĳ���
		ifstream in4;
		in4.open("Բ.txt", ios::in);
		if (!in4)
		{
			cerr << "fail" << endl; return;
		}
		while (true)
		{
			in4 >> p4[i4].ID >> p4[i4].x >> p4[i4].y >> p4[i4].r >> p4[i4].width >> p4[i4].color1 >> p4[i4].color2;
			picture p;
			p.setc1(p4[i4].color1);
			p.setc2(p4[i4].color2);
			p.setw(p4[i4].width);
			fillcircle(p4[i4].x, p4[i4].y, p4[i4].r);
			if (in4.eof())break;

			i4++;
		}

		}
	
	if (q == 2)
	{
		cout << "�������ֱ���ļ������" << endl;
		int t;
		cin >> t;
		if (t > k4)
		{
			cout << "���ļ�δ����" << endl;
		}
		else
		{
			in4 >> p4[t].ID >> p4[t].x >> p4[t].y >> p4[t].r >> p4[t].width >> p4[t].color1 >> p4[t].color2;
			picture p;
			p.setc1(p4[t].color1);
			p.setw(p4[t].width);
			fillcircle(p4[t].x, p4[t].y, p4[t].r);
		}
	}
}
void drawcircle::cut()
{
	cout << "����ɾ���ڼ���Բ" << endl;
	int t;
	cin >> t;
	p4[t].ID = 0;
	p4[t].x = 0;
	p4[t].y =0;
	p4[t].r = 0;
	p4[t].width = 0;
	p4[t].color1 = 0;
	p4[t].color2 = 0;
	save();
	cleardevice();
}



class drawellipse:public picture
{
public:
	int x, y, xx,yy, width;
	int color1;
	int color2;
	int ID;
	drawellipse() {};
	drawellipse(int ID,int x, int y, int xx,int yy ,int width, int color1, int color2) : ID(ID), x(x), y(y), xx(xx),yy(yy), width(width), color1(color1), color2(color2) {}

	void add();//��ӹ���
	void save();  //�洢���ݵ��ļ�
	void change();//�༭����
	void input();//���빦��
	void move();//�ƶ�����
	void copy();//��������
	void zoom();//���Ź���
	void cut(); //ɾ��ͼƬ����
	void open();//���ļ�����
};
drawellipse p5[max];
void drawellipse::add()
{
	int ID;
	cout << "��������Բ���򣬴�1��ʼ" << endl;
	cin >> ID;
	int x, y, xx,yy, width, color1, color2;
	cout << "������x��y,xx,yy" << endl;
	cin >> x >> y >> xx>>yy;
	p5[k5].ID = ID;
	p5[k5].x = x;          //��1��ʼ��
	p5[k5].y = y;
	p5[k5].xx = xx;
	p5[k5].yy = yy;
	cout << "�������߿��" << endl;
	cin >> width;
	p5[k5].width = width;
	cout << "������������ɫ��1��ɫ   2��ɫ   3��ɫ   4��ɫ" << endl;
	cin >> color1;
	p5[k5].color1 = color1;
	cout << "�����������ɫ��1��ɫ   2��ɫ   3��ɫ   4��ɫ" << endl;
	cin >> color2;
	p5[k5].color2 = color2;
}
void drawellipse::save()
{
	ofstream out;
	out.open("��Բ.txt", ios::out);
	if (!out)
	{
		cerr << "fail" << endl;
		return;
	}
	for (int i = 1;i<=k5;i++)
	{
		out <<p5[i].ID<<" "<< p5[i].x << " " << p5[i].y << " " << p5[i].xx << " " << p5[i].yy <<" "<<p5[i].width << " " << p5[i].color1 << " " << p5[i].color2 << endl;
		
	}
	out.close();

	cout << "����ɹ�" << endl;
	system("pause");
}
void drawellipse::change()
{
	cout << "�������޸���Բ�Ĳ���,������ڼ�����Բ" << endl;
	int t;
	cin >> t;
	this->input();
	p5[t] = *this;
	cout << "�༭�ɹ�" << endl;
	save();
	cleardevice();
}
void drawellipse::input()
{

	cout << "������x��y,xx,yy" << endl;
	cin >> x >> y >> xx>>yy;

	cout << "������������ɫ��1��ɫ   2��ɫ   3��ɫ   4��ɫ" << endl;
	cin >> color1;

	cout << "�����������ɫ��1��ɫ   2��ɫ   3��ɫ   4��ɫ" << endl;
	cin >> color2;
}
void drawellipse::move()
{
	cout << "�����ƶ��ڼ�����Բ" << endl;
	int t;
	cin >> t;
	cout << "���������뽫��Բ�������Ƶ�������x,y" << endl;
	int x, y;
	cin >> x >> y;   //���е�����
	
	int x1 = (p5[t].xx + p5[t].x) / 2;//ԭ�е�����
	int y1 = (p5[t].yy + p5[t].y) / 2;

	if (x1< x&&y1<y) //�����½Ƕ�
	{
		int w = abs(p5[t].xx - p5[t].x);
		int h = abs(p5[t].yy - p5[t].y);
		p5[t].x = x - w / 2;
		p5[t].y = y - h / 2;
		p5[t].xx = x + w / 2;
		p5[t].yy = y+ h / 2;
	}
	if (x1> x&& y1>y) //�����ϽǶ�
	{
		int w = abs(p5[t].xx - p5[t].x);
		int h = abs(p5[t].yy - p5[t].y);
		p5[t].x = x - w / 2;
		p5[t].y = y - h / 2;
		p5[t].xx = x + w / 2;
		p5[t].yy = y + h / 2;
	}
	if (x1<x && y1 > y) //�����ϽǶ�
	{
		int w = abs(p5[t].xx - p5[t].x);
		int h = abs(p5[t].yy - p5[t].y);
		p5[t].x = x - w / 2;
		p5[t].y = y - h / 2;
		p5[t].xx = x + w / 2;
		p5[t].yy= y + h / 2;
	}
	if (x1> x &&y1 < y) //�����½Ƕ�
	{
		int w = abs(p5[t].xx - p5[t].x);
		int h = abs(p5[t].yy - p5[t].y);
		p5[t].x = x - w / 2;
		p5[t].y = y - h / 2;
		p5[t].xx = x + w / 2;
		p5[t].yy = y + h / 2;
	}
	save();
	cleardevice();
}
void drawellipse::copy()
{
	cout << "���븴�Ƶڼ�����Բ" << endl;
	int t;
	cin >> t;
	cout << "�����븴�����ĵ�ʲôλ�ã���x,y������" << endl;
	int x, y;
	cin >> x >> y;
	
	int x1 = (p5[t].xx + p5[t].x) / 2;//ԭ�е�����
	int y1 = (p5[t].yy + p5[t].y) / 2;

	int w = abs(p5[t].xx - p5[t].x);
	int h = abs(p5[t].yy - p5[t].y);
	if (x1 < x && y1 < y) //�����½Ƕ�
	{
		int w = abs(p5[t].xx - p5[t].x);
		int h = abs(p5[t].yy - p5[t].y);
		p5[t].x = x - w / 2;
		p5[t].y = y - h / 2;
		p5[t].xx = x + w / 2;
		p5[t].yy = y + h / 2;
	}
	if (x1 > x && y1 > y) //�����ϽǶ�
	{
		int w = abs(p5[t].xx - p5[t].x);
		int h = abs(p5[t].yy - p5[t].y);
		p5[t].x = x - w / 2;
		p5[t].y = y - h / 2;
		p5[t].xx = x + w / 2;
		p5[t].yy = y + h / 2;
	}
	if (x1<x && y1 > y) //�����ϽǶ�
	{
		int w = abs(p5[t].xx - p5[t].x);
		int h = abs(p5[t].yy - p5[t].y);
		p5[t].x = x - w / 2;
		p5[t].y = y - h / 2;
		p5[t].xx = x + w / 2;
		p5[t].yy = y + h / 2;
	}
	if (x1 > x && y1 < y) //�����½Ƕ�
	{
		int w = abs(p5[t].xx - p5[t].x);
		int h = abs(p5[t].yy - p5[t].y);
		p5[t].x = x - w / 2;
		p5[t].y = y - h / 2;
		p5[t].xx = x + w / 2;
		p5[t].yy = y + h / 2;
	}
	
	
	p5[k5].width = p5[t].width;
	p5[k5].color1 = p5[k5].color1;
	p5[k5].color2 = p5[k5].color2;
	save();
	cleardevice();
}
void  drawellipse::zoom()
{
	cout << "�������ŵڼ�����Բ" << endl;
	int t;
	cin >> t;
	cout << "������������ű���,������0-5" << endl;
	int time;
	cin >> time;
	int x1 = (p5[t].xx + p5[t].x) / 2;//ԭ�е�����
	int y1 = (p5[t].yy + p5[t].y) / 2;
	int w = abs(p5[t].xx - p5[t].x);
	int h = abs(p5[t].yy - p5[t].y);
	if (time >= 1)
	{
		p5[t].x = x1 - (time - 1) * w / 2;
		p5[5].y = y1 - (time - 1) * h / 2;
		p5[t].xx = x1 + (time - 1) * w / 2;
		p5[5].yy = y1 + (time - 1) * h / 2;
	}

	if (time < 1)
	{
		p5[t].x = x1 -time * w / 2;
		p5[t].y = y1 - time * h / 2;
		p5[t].xx = x1 + time * w / 2;
		p5[t].yy = y1 + time * h/ 2;
	}

	save();
	cleardevice();
}
void drawellipse::cut()
{
	cout << "����ɾ���ڼ�����Բ" << endl;
	int t;
	cin >> t;
	p5[t].ID = 0;
	p5[t].x = 0;
	p5[t].y = 0;
	p5[t].xx = 0;
	p5[t].yy = 0;
	p5[t].width = 0;
	p5[t].color1 = 0;
	p5[t].color2 = 0;
	save();
	cleardevice();
}
void drawellipse::open()
{
	int q;
	cout << "��ȫ���ļ���1���򿪲����ļ���2" << endl;
	cin >> q;
	int i5 = 1;         //����Բ�Ĳ���
	ifstream in5;
	in5.open("��Բ.txt", ios::in);
	if (q == 1)
	{
		int i5 = 1;         //������Բ�Ĳ���
		ifstream in5;
		in5.open("��Բ.txt", ios::in);
		if (!in5)
		{
			cerr << "fail" << endl; return;
		}
		while (true)
		{
			in5 >> p5[i5].ID >> p5[i5].x >> p5[i5].y >> p5[i5].xx >> p5[i5].yy >> p5[i5].width >> p5[i5].color1 >> p5[i5].color2;
			picture p;
			p.setc1(p5[i5].color1);
			p.setc2(p5[i5].color2);
			p.setw(p5[i5].width);
			fillellipse(p5[i5].x, p5[i5].y, p5[i5].xx, p5[i5].yy);
			if (in5.eof())break;

			i5++;

		}

	}

	if (q == 2)
	{
		cout << "�������ֱ���ļ������" << endl;
		int t;
		cin >> t;
		if (t > k5)
		{
			cout << "���ļ�δ����" << endl;
		}
		else
		{
			in5 >> p5[t].ID >> p5[t].x >> p5[t].y >> p5[t].xx >> p5[t].yy >> p5[t].width >> p5[t].color1 >> p5[t].color2;
			picture p;
			p.setc1(p5[t].color1);
			p.setc2(p5[t].color2);
			p.setw(p5[t].width);
			fillellipse(p5[t].x, p5[t].y, p5[t].xx, p5[t].yy);
		}
	}
}




class drawretangle :public picture
{
public:
	int x, y, xx, yy;
	double width;
	int color1, color2;
	int ID;

	drawretangle() {};
	drawretangle(int ID, int x, int y, int xx, int yy, double width, char color1, char  color2) :ID(ID),x(x), y(y), xx(xx), yy(yy), color1(color1), color2(color2), width(width)
	{}
	void add();//��ӹ���
	void save();  //�洢���ݵ��ļ�
	void change();//�༭����
	void input();//���빦��
	void move();//�ƶ�����
	void copy();//��������
	void zoom();//���Ź���
	void cut(); //ɾ��ͼƬ����
	void open();//���ļ�����
};
drawretangle p6[max];
void drawretangle::add()
{
	cout << "��������εı�ţ���1��ʼ" << endl;
	int ID;
	cin >> ID;
	int x, y, xx, yy, width, color1, color2;
	cout << "������x��y,xx,yy" << endl;
	cin >> x >> y >> xx >> yy;

	p6[k6].ID = ID;
	p6[k6].x = x;          //��1��ʼ��
	p6[k6].y = y;
	p6[k6].xx = xx;
	p6[k6].yy = yy;
	cout << "�������߿��" << endl;
	cin >> width;
	p6[k6].width = width;
	cout << "������������ɫ��1��ɫ   2��ɫ   3��ɫ   4��ɫ" << endl;
	cin >> color1;
	p6[k6].color1 = color1;
	cout << "�����������ɫ��1��ɫ   2��ɫ   3��ɫ   4��ɫ" << endl;
	cin >> color2;
	p6[k6].color2 = color2;
}
void drawretangle::save()
{
	ofstream out;
	out.open("����.txt", ios::out);
	if (!out)
	{
		cerr << "fail" << endl;
		return;
	}
	for (int i = 1; i <= k6; i++)
	{
		out << p6[i].ID << " " << p6[i].x << " " << p6[i].y << " " << p6[i].xx << " " << p6[i].yy <<" "<< p6[i].width << " " << p6[i].color1 << " " << p6[i].color2 << endl;

	}
	out.close();

	cout << "����ɹ�" << endl;
	system("pause");
}
void drawretangle::change()
{
	cout << "�������޸ľ��εĲ���,������ڼ�������" << endl;
	int t;
	cin >> t;
	this->input();
	p6[t] = *this;
	cout << "�༭�ɹ�" << endl;
	save();
	cleardevice();


}
void drawretangle::input()
{

	cout << "������x��y,xx,yy" << endl;
	cin >> x >> y >> xx >> yy;

	cout << "������������ɫ��1��ɫ   2��ɫ   3��ɫ   4��ɫ" << endl;
	cin >> color1;

	cout << "�����������ɫ��1��ɫ   2��ɫ   3��ɫ   4��ɫ" << endl;
	cin >> color2;
}
void drawretangle::move()
{
	cout << "�����ƶ��ڼ�������" << endl;
	int t;
	cin >> t;
	cout << "���������뽫���ε������Ƶ�������x,y" << endl;
	int x, y;
	cin >> x >> y;   //���е�����

	int x1 = (p6[t].xx + p6[t].x) / 2;//ԭ�е�����
	int y1 = (p6[t].yy + p6[t].y) / 2;

	if (x1 < x && y1 < y) //�����½Ƕ�
	{
		int w = abs(p6[t].xx - p6[t].x);
		int h = abs(p6[t].yy - p6[t].y);
		p6[t].x = x - w / 2;
		p6[t].y = y - h / 2;
		p6[t].xx = x + w / 2;
		p6[t].yy = y + h / 2;
	}
	if (x1 > x && y1 > y) //�����ϽǶ�
	{
		int w = abs(p6[t].xx - p6[t].x);
		int h = abs(p6[t].yy - p6[t].y);
		p6[t].x = x - w / 2;
		p6[t].y = y - h / 2;
		p6[t].xx = x + w / 2;
		p6[t].yy = y + h / 2;
	}
	if (x1<x && y1 > y) //�����ϽǶ�
	{
		int w = abs(p6[t].xx - p6[t].x);
		int h = abs(p6[t].yy - p6[t].y);
		p6[t].x = x - w / 2;
		p6[t].y = y - h / 2;
		p6[t].xx = x + w / 2;
		p6[t].yy = y + h / 2;
	}
	if (x1 > x && y1 < y) //�����½Ƕ�
	{
		int w = abs(p6[t].xx - p6[t].x);
		int h = abs(p6[t].yy - p6[t].y);
		p6[t].x = x - w / 2;
		p6[t].y = y - h / 2;
		p6[t].xx = x + w / 2;
		p6[t].yy = y + h / 2;
	}
	save();
	cleardevice();
}
void drawretangle::copy()
{
	cout << "���븴�Ƶڼ�������" << endl;
	int t;
	cin >> t;
	cout << "�����븴�����ĵ�ʲôλ�ã���x,y������" << endl;
	int x, y;
	cin >> x >> y;

	int x1 = (p6[t].xx + p6[t].x) / 2;//ԭ�е�����
	int y1 = (p6[t].yy + p6[t].y) / 2;

	int w = abs(p6[t].xx - p6[t].x);
	int h = abs(p6[t].yy - p6[t].y);
	if (x1 < x && y1 < y) //�����½Ƕ�
	{
		int w = abs(p6[t].xx - p6[t].x);
		int h = abs(p6[t].yy - p6[t].y);
		p6[t].x = x - w / 2;
		p6[t].y = y - h / 2;
		p6[t].xx = x + w / 2;
		p6[t].yy = y + h / 2;
	}
	if (x1 > x && y1 > y) //�����ϽǶ�
	{
		int w = abs(p6[t].xx - p6[t].x);
		int h = abs(p6[t].yy - p6[t].y);
		p6[t].x = x - w / 2;
		p6[t].y = y - h / 2;
		p6[t].xx = x + w / 2;
		p6[t].yy = y + h / 2;
	}
	if (x1<x && y1 > y) //�����ϽǶ�
	{
		int w = abs(p6[t].xx - p6[t].x);
		int h = abs(p6[t].yy - p6[t].y);
		p6[t].x = x - w / 2;
		p6[t].y = y - h / 2;
		p6[t].xx = x + w / 2;
		p6[t].yy = y + h / 2;
	}
	if (x1 > x && y1 < y) //�����½Ƕ�
	{
		int w = abs(p6[t].xx - p6[t].x);
		int h = abs(p6[t].yy - p6[t].y);
		p6[t].x = x - w / 2;
		p6[t].y = y - h / 2;
		p6[t].xx = x + w / 2;
		p6[t].yy = y + h / 2;
	}


	p6[k5].width = p6[t].width;
	p6[k5].color1 = p6[k5].color1;
	p6[k5].color2 = p6[k5].color2;
	save();
	cleardevice();
}
void drawretangle::zoom()
{
	cout << "�������ŵڼ�������" << endl;
	int t;
	cin >> t;
	cout << "������������ű���,������0-5" << endl;
	int time;
	cin >> time;
	int x1 = (p6[t].xx + p6[t].x) / 2;//ԭ�е�����
	int y1 = (p6[t].yy + p6[t].y) / 2;
	int w = abs(p6[t].xx - p6[t].x);
	int h = abs(p6[t].yy - p6[t].y);
	if (time >= 1)
	{
		p6[t].x = x1 - (time - 1) * w / 2;
		p6[5].y = y1 - (time - 1) * h / 2;
		p6[t].xx = x1 + (time - 1) * w / 2;
		p6[5].yy = y1 + (time - 1) * h / 2;
	}

	if (time < 1)
	{
		p6[t].x = x1 - time * w / 2;
		p6[t].y = y1 - time * h / 2;
		p6[t].xx = x1 + time * w / 2;
		p6[t].yy = y1 + time * h / 2;
	}

	save();
	cleardevice();
}
void drawretangle::cut()
{
	cout << "����ɾ���ڼ�������" << endl;
	int t;
	cin >> t;
	p6[t].ID = 0;
	p6[t].x = 0;
	p6[t].y = 0;
	p6[t].xx = 0;
	p6[t].yy = 0;
	p6[t].width = 0;
	p6[t].color1 = 0;
	p6[t].color2 = 0;
	save();
	cleardevice();
}
void drawretangle::open()
{
	int q;
	cout << "��ȫ���ļ���1���򿪲����ļ���2" << endl;
	cin >> q;
	int i6 = 1;         //����Բ�Ĳ���
	ifstream in6;
	in6.open("����.txt", ios::in);
	if (q == 1)
	{
		int i6 = 1;         //������Բ�Ĳ���
		ifstream in6;
		in6.open("����.txt", ios::in);
		if (!in6)
		{
			cerr << "fail" << endl; return;
		}
		while (true)
		{
			in6 >> p6[i6].ID >> p6[i6].x >> p6[i6].y >> p6[i6].xx >> p6[i6].yy >> p6[i6].width >> p6[i6].color1 >> p6[i6].color2;
			picture p;
			p.setc1(p6[i6].color1);
			p.setc2(p6[i6].color2);
			p.setw(p6[i6].width);
			fillellipse(p6[i6].x, p6[i6].y, p6[i6].xx, p6[i6].yy);
			if (in6.eof())break;

			i6++;

		}

	}

	if (q == 2)
	{
		cout << "�������ֱ���ļ������" << endl;
		int t;
		cin >> t;
		if (t > k6)
		{
			cout << "���ļ�δ����" << endl;
		}
		else
		{
			in6 >> p6[t].ID >> p6[t].x >> p6[t].y >> p6[t].xx >> p6[t].yy >> p6[t].width >> p6[t].color1 >> p6[t].color2;
			picture p;
			p.setc1(p6[t].color1);
			p.setc2(p6[t].color2);
			p.setw(p6[t].width);
			fillellipse(p6[t].x, p6[t].y, p6[t].xx, p6[t].yy);
		}
	}
}








class drawsolidpolygon:public picture
{
public:
	int ID, point[10][2];
	int width, color1;
	void add();//��ӹ���
	void save();  //�洢���ݵ��ļ�
	void change();//�༭����
	void input();//���빦��
	void move();//�ƶ�����
	void copy();//��������
	void zoom();//���Ź���
	void cut(); //ɾ��ͼƬ����
	void open();//���ļ�����

};
drawsolidpolygon p7[max];
void  drawsolidpolygon::add()
{
	int ID;
	cout << "���������߱�ţ���1��ʼ" << endl;
	cin >> ID;
	cout << "�������۵�ĸ���" << endl;

	cin >> n1;
	int x, y, width, color1;

	for (int i = 1; i <= n1; i++)
	{
		cout << "������x��y������" << endl;
		cin >> x >> y;
		p3[k3].ID = ID;
		p3[k3].point[i][0] = x;          //��1��ʼ��
		p3[k3].point[i][1] = y;

		if (i == n1)cout << "¼�����" << endl;
	}
	cout << "�������߿��" << endl;
	cin >> width;
	p3[k3].width = width;
	cout << "������������ɫ��1��ɫ   2��ɫ   3��ɫ   4��ɫ" << endl;
	cin >> color1;
	p3[k3].color1 = color1;
}
void  drawsolidpolygon::save()
{
	ofstream out;
	out.open("����.txt", ios::out);
	if (!out)
	{
		cerr << "fail" << endl;
		return;
	}
	for (int i = 1; i <= k3; i++)
	{
		out << p3[i].ID << " ";
		for (int t = 1; t <= n1; t++)
		{
			out << p3[i].point[t][0] << " " << p3[i].point[t][1] << " ";
		}
		out << " " << p3[i].width << " " << p3[i].color1 << endl;
	}
	out.close();

	cout << "����ɹ�" << endl;
	system("pause");
}
void  drawsolidpolygon::change()
{

}
void  drawsolidpolygon::input()
{

}
void  drawsolidpolygon::move()
{

}
void  drawsolidpolygon::copy()
{

}
void  drawsolidpolygon::cut()
{

}
void  drawsolidpolygon::zoom()
{

}
void  drawsolidpolygon::open()
{

}






void rad()
{
	
	
	
	
	
	int i2 = 1;         //�����ߵĲ���
	ifstream in2;
	in2.open("��.txt", ios::in);
	if (!in2)
	{
		cerr << "fail" << endl; return;
	}
	while (true)
	{
		in2 >>p2[i2].ID>> p2[i2].x >> p2[i2].y >> p2[i2].xx >> p2[i2].yy >> p2[i2].width >> p2[i2].color1;
		picture p;
		p.setc1(p2[i2].color1);
		p.setw(p2[i2].width);
		line(p2[i2].x, p2[i2].y, p2[i2].xx, p2[i2].yy);
		if (in2.eof())break;

		i2++;
	}

	
	
	int i3 = 1;         //�����ߵĲ���
	ifstream in3;
	in3.open("����.txt", ios::in);
	if (!in3)
	{
		cerr << "fail" << endl; return;
	}
	while (true)
	{
		in3 >> p3[i3].ID;
		for (int t = 1; t <= n1; t++)
		{
			in3 >> p3[i3].point[t][0] >> p3[i3].point[t][1];
		}
		in3>>p3[i3].width >> p3[i3].color1;
		picture p;
		p.setc1(p3[i3].color1);
		p.setw(p3[i3].width);
		
		for (int t = 1; t <= n1; t++)
		{
			line(p3[i3].point[t][0], p3[i3].point[t][1], p3[i3].point[t + 1][0], p3[i3].point[t + 1][1]);

		}

		if (in3.eof())break;

		i3++;
	}




	
	
	int i4= 1;         //����Բ�Ĳ���
	ifstream in4;
	in4.open("Բ.txt", ios::in);
	if (!in4)
	{
		cerr << "fail" << endl; return;
	}
	while (true)
	{
		in4 >>p4[i4].ID>> p4[i4].x >> p4[i4].y >> p4[i4].r >> p4[i4].width >> p4[i4].color1>> p4[i4].color2;
		picture p;
		p.setc1(p4[i4].color1);
		p.setc2(p4[i4].color2);
		p.setw(p4[i4].width);
		fillcircle(p4[i4].x, p4[i4].y,p4[i4].r);
		if (in4.eof())break;

		i4++;
	}


	int i5 = 1;         //������Բ�Ĳ���
	ifstream in5;
	in5.open("��Բ.txt", ios::in);
	if (!in5)
	{
		cerr << "fail" << endl; return;
	}
	while (true)
	{
		in5 >> p5[i5].ID >> p5[i5].x >> p5[i5].y >> p5[i5].xx >> p5[i5].yy >> p5[i5].width >> p5[i5].color1 >> p5[i5].color2;
		picture p;
		p.setc1(p5[i5].color1);
		p.setc2(p5[i5].color2);
		p.setw(p5[i5].width);
		fillellipse(p5[i5].x, p5[i5].y, p5[i5].xx, p5[i5].yy);
		if (in5.eof())break;

		i5++;
	}


	int i6 = 1;         //������Բ�Ĳ���
	ifstream in6;
	in6.open("����.txt", ios::in);
	if (!in6)
	{
		cerr << "fail" << endl; return;
	}
	while (true)
	{
		in6 >> p6[i6].ID >> p6[i6].x >> p6[i6].y >> p6[i6].xx >> p6[i6].yy >> p6[i6].width >> p6[i6].color1 >> p6[i6].color2;

		cout << "�߿�" << p6[i6].width << endl;
		picture p;
		p.setw(p6[i6].width);
		p.setc1(p6[i6].color1);
		p.setc2(p6[i6].color2);
		fillrectangle(p6[i6].x, p6[i6].y, p6[i6].xx, p6[i6].yy);
		if (in6.eof())break;

		i6++;

	}


}

int main()
{
	initgraph(W, H, SHOWCONSOLE);
	
	label:

		cout << "���ǿ��Ի�������ͼ���밴�ն�Ӧ���������룬���磺Բ��4��" << endl;
		cout << "��         ��1��" << endl;
		cout << "ֱ��       ��2��" << endl;
		cout << "����       ��3��" << endl;
		cout << "Բ         ��4��" << endl;
		cout << "��Բ��     ��5��" << endl;
		cout << "����       ��6��" << endl;
		cout << "�����     ��7��" << endl;
		int a;
		cout << "����������Ҫ����(��༭��)��ͼ��:" << endl;
		cin >> a;

		if (a == 1)
		{
			int x, y;
			cout << "������x��y������" << endl;
			cin >> x >> y;
		}
		if (a == 2)
		{
			k2 = k2 + 1;
			drawline p;
			p.add();
			p.save();
			rad();
			int flag = 1;
			cout << "�Ƿ������ͼ,�����1�˳��������2��༭����ͼ��" << endl;

			cin >> z;

			if (z == 1)
			{
				return 0;
			}
		}
		if (a == 3)
		{
			k3 = k3 + 1;
			drawbrokenline p;
			p.add();
			p.save();
			rad();
			int flag = 1;
			cout << "�Ƿ������ͼ,�����1�˳��������2��༭����ͼ��" << endl;

			cin >> z;

			if (z == 1)
			{
				return 0;
			}
		}
		if (a == 4)
		{
			k4 = k4 + 1;
			drawcircle p;
			p.add();
			p.save();
			rad();
			int flag = 1;
			cout << "�Ƿ������ͼ,�����1�˳��������2��༭����ͼ��" << endl;
			cin >> z;
			if (z == 1)
			{
				return 0;
			}
		}
		if (a == 5)
		{
			k5 = k5 + 1;
			drawellipse p;
			p.add();
			p.save();
			rad();
			int flag = 1;
			cout << "�Ƿ������ͼ,�����1�˳��������2��༭����ͼ��" << endl;
			cin >> z;
			if (z == 1)
			{
				return 0;
			}

		}
		if (a == 6)
		{
			k6 = k6 + 1;
			drawretangle p;
			p.add();
			p.save();
			rad();
			int flag = 1;
			cout << "�Ƿ������ͼ,�����1�˳��������2��༭����ͼ��" << endl;
			cin >> z;
			if (z == 1)
			{
				return 0;
			}
		}
		if (a == 7)
		{

		}

		if (z == 2)
		{


			while (1)
			{
				cout << "���������¹��ܣ���0����������ͼ�Σ�1���༭���β���  ��2���ƶ�ͼƬ  ��3������ͼƬ  (4)����ͼƬ  ��5�����浽�ļ�  ��6�����ļ���7��ɾ��ͼƬ  ��8���˳�ϵͳ" << endl;
				int t;
				cin >> t;
				switch (t)
				{
				case(0):
				{
					goto label;
				}
				case(1):
				{
					cout << "����������༭��ͼ�εı�źʹ���,����ֱ�߾�����2,Բ������4" << endl;
					int a;
					cin >> a;
					
					if(a==1)
					{
					drawpoint p;
						p.change();
						
						rad();
						break;

					}
					if(a==2){
						
						drawline p;
						p.change();
						rad();
						break;
					}
					if(a==3)
					{
						break;
					}
					if(a==4){
						drawcircle p;
						p.change();
						rad();
						break;
					}
					if(a==5)
					{
						drawellipse p;
						p.change();
						p.save();
						rad();
						break;
					}
					if(a==6)
					{
						drawretangle p;
						p.change();
						p.save();
						rad();
						break;
					}
					if(a==7){
						drawsolidpolygon p;
						p.change();
						rad();
						break;
					}
		
					break;       //�ƻ�switchѭ��
				}
				case(2):
				{
					cout << "�����������ƶ���ͼ�εı��,����ֱ�߾�����2,Բ������4" << endl;
				int a;
				cin >> a;
				
				
				if (a == 1)
				{
					drawpoint p;
					p.move();
					rad();
				}
				if (a == 2)
				{
					drawline p;
					p.move();
					rad();
				}
				if (a == 3)
				{
					drawbrokenline p;
					p.move();
					rad();
				}
				if (a == 4)
				{
					drawcircle p;
					p.move();
					rad();
					
				}
				if (a == 5)
				{
					drawellipse p;
					p.move();
					rad();
				}
				if (a == 6)
				{
					drawretangle p;
					p.move();
					rad();
				}
				if (a == 7)
				{
					drawsolidpolygon p;
					p.move();
					rad();
				}

				break;       //�ƻ�switchѭ��
				}
				case(3):
				{
					cout << "�������������ŵ�ͼ�εı�źʹ���,����ֱ�߾�����2,Բ������4" << endl;
					int q;
					cin >> q;
					if (q == 1)
					{
						drawpoint p;
						p.zoom();
						rad();
					}
					if (q == 2)
					{
						drawline p;
						p.zoom();
						rad();
					}
					if (q == 3)
					{
						drawbrokenline p;
						p.zoom();
						rad();
					}
					if (q == 4)
					{
						drawcircle p;
						p.zoom();
						rad();

					}
					if (q == 5)
					{
						drawellipse p;
						p.zoom();
						rad();
					}
					if (q == 6)
					{
						drawretangle p;
						p.zoom();
						rad();
					}
					if (q == 7)
					{
						drawsolidpolygon p;
						p.zoom();
						rad();
					}
					break;       //�ƻ�switchѭ��
				}
				case(4):
				{
					cout << "���������븴�Ƶ�ͼ�εı�źʹ���,����ֱ�߾�����2,Բ������4" << endl;
					int a;
					cin >> a;
					if (a == 1)
					{
						drawpoint p;
						p.copy();
						rad();
					}
					if (a == 2)
					{
						drawline p;
						p.copy();
						rad();
					}
					if (a == 3)
					{
						drawbrokenline p;
						p.copy();
						rad();
					}
					if (a == 4)
					{
						drawcircle p;
						p.copy();
						rad();
					}
					if (a == 5)
					{
						drawellipse p;
						p.copy();
						rad();
					}
					if (a == 6)
					{
						drawretangle p;
							p.copy();
						rad();
					}
					if (a == 7)
					{
						drawsolidpolygon p;
						p.copy();
						rad();
					}
					break;       //�ƻ�switchѭ��
				}
				case(5):
				{
					cout << "�������㱣���ͼ�εı�źʹ���,����ֱ�߾�����2,Բ������4" << endl;
					int a;
					cin >> a;
					if (a == 1)
					{
						drawpoint p;
						p.save();
						rad();
					}
					if (a == 2)
					{
						drawline p;
						p.save();
						rad();
					}
					if (a == 3)
					{
						drawbrokenline p;
						p.save();
						rad();
					}
					if (a == 4)
					{
						drawcircle p;
						p.save();
						rad();
					}
					if (a == 5)
					{
						drawellipse p;
						p.save();
						rad();
					}
					if (a == 6)
					{
						drawretangle p;
						p.save();
						rad();
					}
					if (a == 7)
					{
						drawsolidpolygon p;
						p.save();
						rad();
					}
					break;       //�ƻ�switchѭ��
				}
				case(6):
				{
					cout << "����������򿪵�ͼ�εı��,����ֱ�߾�����2,Բ������4" << endl;
					int a;
					cin >> a;
					if (a == 1)
					{
						drawpoint p;
						p.open();
					}
					if (a == 2)
					{
						drawline p;
						p.open();
					}
					if (a == 3)
					{
						drawbrokenline p;
						p.open();
					}
					if (a == 4)
					{
						drawcircle p;
						p.open();

					}
					if (a == 5)
					{
						drawellipse p;
						p.open();
					}
					if (a == 6)
					{
						drawretangle p;
						p.open();
					}
					if (a == 7)
					{
						drawsolidpolygon p;
						p.open();
					}
					break;       //�ƻ�switchѭ��
				}
				case(7):
				{
					cout << "��������ɾ����ͼ�εı�źʹ���,����ֱ�߾�����2,Բ������4" << endl;
					int a;
					cin >> a;
					if (a == 1)
					{
						drawpoint p;
						p.cut();
						rad();
					}
					if (a == 2)
					{
						drawline p;
						p.cut();
						rad();
					}
					if (a == 3)
					{
						drawbrokenline p;
						p.cut();
						rad();
					}
					if (a == 4)
					{
						drawcircle p;
						p.cut();
						rad();
					}
					if (a == 5)
					{
						drawellipse p;
						p.cut();
						rad();
					}
					if (a == 6)
					{
						drawretangle p;
						p.cut();
						rad();
					}
					if (a == 7)
					{
						drawsolidpolygon p;
						p.cut();
						rad();
					}
					break;       //�ƻ�switchѭ��
				}
				case(8):
				{
					cout << "���Ƿ񱣴����ļ�������Ѿ����水1�˳������δ���水2�����ļ���֮��ϵͳ���Զ������˳���" << endl;
					int a;
					cin >> a;
					if (a == 1)
					{
						return 0;
					}
					if (a == 2)
					{
						cout << "�����ļ��ɹ�" << endl;


					}

					break;
				}
				}
			}
		}
}
