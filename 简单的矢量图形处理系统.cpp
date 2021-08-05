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
int k1 = 0;    //画的图形的个数,即编号
int k2 = 0;
int k3 = 0;
int k4 = 0;
int k5 = 0;
int k6 = 0; 
int k7 = 0;

int n1;//折线点的个数
int n2;//多边形点的个数
#define max 30
using namespace std;
class picture        //用来存放一些图形的属性
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
		setlinestyle(PS_SOLID, width);//设置线型，线宽             //此处还要增加对线型更改的功能
	}
	virtual void setc1(int color1)
	{
		if (color1 == 1)
			setlinecolor(RED);//设置线颜色
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
			setfillcolor(RED); //设置填充颜色
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
	void add();//添加功能
	void save();  //存储数据到文件
	void change();//编辑功能
	void input();//输入功能
	void move();//移动功能
	void copy();//拷贝功能
	void zoom();//缩放功能
	void cut(); //删除图片功能
	void open();//打开文件功能
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

	void add();//添加功能
	void save();  //存储数据到文件
	void change();//编辑功能
	void input();//输入功能
	void move();//移动功能
	void copy();//拷贝功能
	void zoom();//缩放功能
	void cut(); //删除图片功能
	void open();//打开文件功能
};
drawline p2[max];
void drawline::add()
{
	cout << "请输入直线编号，从1开始" << endl;
	int x, y, xx, yy, width, color1, ID;
	cin >> ID;
	cout << "请输入x，y,xx,,yy的坐标" << endl;
	cin >> x >> y >> xx >> yy;
	p2[k2].ID = ID;
	p2[k2].x = x;          //从1开始的
	p2[k2].y = y;
	p2[k2].xx = xx;
	p2[k2].yy = yy;
	cout << "请输入线宽度" << endl;
	cin >> width;
	p2[k2].width = width;
	cout << "请输入线条颜色，1红色   2蓝色   3黄色   4白色" << endl;
	cin >> color1;
	p2[k2].color1 = color1;
}
void drawline::save()
{
	
	ofstream out;
	out.open("线.txt", ios::out);
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

		cout << "保存成功" << endl;
		system("pause");
}
void drawline::input()
{
	cout << "再次确认输入修改的图形的编号" << endl;
	cin >> ID;
	cout << "请输入x，y,xx,,yy的坐标" << endl;
	cin >> x >> y >> xx >> yy;
	cout << "请输入线宽度" << endl;
	cin >> width;
	cout << "请输入线条颜色，1红色   2蓝色   3黄色   4白色" << endl;
	cin >> color1;
}
void drawline::change()
{
	cout << "你正在修改直线的参数,请输入修改第几条直线" << endl;
	int t;
	cin >> t;
	
	this->input();
	p2[t] = *this;
	cout << "编辑成功" << endl;
	save();
	cleardevice();
}
void drawline::move()
{
	cout << "你想移动第几条直线" << endl;
	int t;
	cin >> t;
	cout << "请输入你想将起点位置移到的坐标" << endl;
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
	cout << "你想复制第几条直线" << endl;
	int t;
	cin >> t;
	cout << "请输入将起点移到什么位置，既x,y的坐标" << endl;
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
	cout << "你想缩放第几条直线" << endl;
	int t;
	cin >> t;
	cout << "请输入你的缩放倍数" << endl;
	int time;
	cin >> time;
	int w = abs(p2[t].xx - p2[t].x);
	int h = abs(p2[t].yy - p2[t].y);

	int x1 = (p2[t].x + p2[t].xx) / 2;
	int y1 = (p2[t].y + p2[t].yy) / 2;  //中点坐标
	if (time <= 1)    //有点问题，起点在左侧还是右侧
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
	cout << "你想删除第几条直线" << endl;
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
	cout << "打开全部文件按1，打开部分文件按2" << endl;
	cin >>q;
	ifstream in2;
	in2.open("线.txt", ios::in);
	if (q == 1)
	{
		int i2 = 1;         //关于线的操作
		
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
		cout << "请输入打开直线文件的序号" << endl;
		int t;
		cin >> t;
		if (t > k2)
		{
			cout << "此文件未创建" << endl;
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
	void add();//添加功能
	void save();  //存储数据到文件
	void change();//编辑功能
	void input();//输入功能
	void move();//移动功能
	void copy();//拷贝功能
	void zoom();//缩放功能
	void cut(); //删除图片功能
	void open();//打开文件功能
};
drawbrokenline p3[max];
void drawbrokenline::add()
{
	int ID;
	cout << "请输入折线编号，从1开始" << endl;
	cin >> ID;
	cout << "请输入折点的个数" << endl;
	
	cin >> n1;
	int x, y, width, color1;
	
	for (int i = 1; i <=n1; i++)
	{
		cout << "请输入x，y的坐标" << endl;
		cin >> x >> y;
		p3[k3].ID = ID;
		p3[k3].point[i][0] = x;          //从1开始的
		p3[k3].point[i][1] = y;

		if (i == n1)cout << "录入结束" << endl;
	}
	cout << "请输入线宽度" << endl;
	cin >> width;
	p3[k3].width = width;
	cout << "请输入线条颜色，1红色   2蓝色   3黄色   4白色" << endl;
	cin >> color1;
	p3[k3].color1 = color1;
}
void drawbrokenline::save()
{
	ofstream out;
	out.open("折线.txt", ios::out);
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

	cout << "保存成功" << endl;
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
	void save();  //存储数据到文件
	void change();
	void input();
	void move();
	void copy();
	void zoom();//缩放功能
	void cut(); //删除图片功能
	void open();//打开文件功能
};
drawcircle p4[max];
void drawcircle::add()
{
	cout << "请输入圆形编号，从1开始" << endl;
	cin >> ID;
	int x, y, r, width, color1, color2;
	cout << "请输入x，y,r" << endl;
	cin >> x >> y >> r;
	p4[k4].ID = ID;
	p4[k4].x = x;          //从1开始的
	p4[k4].y = y;
	p4[k4].r = r;
	cout << "请输入线宽度" << endl;
	cin >> width;
	p4[k4].width = width;
	cout << "请输入线条颜色，1红色   2蓝色   3黄色   4白色" << endl;
	cin >> color1;
	p4[k4].color1 = color1;
	cout << "请输入填充颜色，1红色   2蓝色   3黄色   4白色" << endl;
	cin >> color2;
	p4[k4].color2 = color2;
}
void drawcircle::input()
{
	cout << "请确认输入要修改的圆的编号" << endl;
	cin >> ID;
	cout << "请输入x，y,r" << endl;
	cin >> x >> y >> r;
	cout << "请输入线宽度" << endl;
	cin >> width;
	cout << "请输入线条颜色，1红色   2蓝色   3黄色   4白色" << endl;
	cin >> color1;
	cout << "请输入填充颜色，1红色   2蓝色   3黄色   4白色" << endl;
	cin >> color2;
}
void drawcircle::change()
{
	cout << "你正在修改圆的参数,请输入第几个圆" << endl;
	int t;
	cin >> t;
	this->input();
	p4[t] = *this;
	cout << "编辑成功" << endl;
	save();
	cleardevice();
}
void drawcircle::move()
{
	cout << "你想移动第几个圆" << endl;
	int t;
	cin >> t;
	cout << "请输入你想将圆心移到的坐标x,y" << endl;
	int x, y;
	cin >> x >> y;

	p4[t].x = x;
	p4[t].y = y;
	save();
	cleardevice();
}
void drawcircle::zoom()
{
	cout << "你想缩放第几个圆" << endl;
	int t;
	cin >> t;
	cout << "请输入你的缩放倍数" << endl;
	int time;
	cin >> time;
	p4[t].r = p4[t].r * time;
	save();
	cleardevice();
}
void drawcircle::copy()
{
	cout << "你想复制第几个圆" << endl;
	int t;
	cin >> t;
	cout << "请输入复制圆心到什么位置，既x,y的坐标" << endl;
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
	out.open("圆.txt", ios::out);
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

	cout << "保存成功" << endl;
	system("pause");
}
void drawcircle::open()
{
	int q;
	cout << "打开全部文件按1，打开部分文件按2" << endl;
	cin >> q;
	int i4 = 1;         //关于圆的操作
	ifstream in4;
	in4.open("圆.txt", ios::in);
	if (q == 1)
	{
		int i4 = 1;         //关于圆的操作
		ifstream in4;
		in4.open("圆.txt", ios::in);
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
		cout << "请输入打开直线文件的序号" << endl;
		int t;
		cin >> t;
		if (t > k4)
		{
			cout << "此文件未创建" << endl;
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
	cout << "你想删除第几个圆" << endl;
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

	void add();//添加功能
	void save();  //存储数据到文件
	void change();//编辑功能
	void input();//输入功能
	void move();//移动功能
	void copy();//拷贝功能
	void zoom();//缩放功能
	void cut(); //删除图片功能
	void open();//打开文件功能
};
drawellipse p5[max];
void drawellipse::add()
{
	int ID;
	cout << "请输入椭圆次序，从1开始" << endl;
	cin >> ID;
	int x, y, xx,yy, width, color1, color2;
	cout << "请输入x，y,xx,yy" << endl;
	cin >> x >> y >> xx>>yy;
	p5[k5].ID = ID;
	p5[k5].x = x;          //从1开始的
	p5[k5].y = y;
	p5[k5].xx = xx;
	p5[k5].yy = yy;
	cout << "请输入线宽度" << endl;
	cin >> width;
	p5[k5].width = width;
	cout << "请输入线条颜色，1红色   2蓝色   3黄色   4白色" << endl;
	cin >> color1;
	p5[k5].color1 = color1;
	cout << "请输入填充颜色，1红色   2蓝色   3黄色   4白色" << endl;
	cin >> color2;
	p5[k5].color2 = color2;
}
void drawellipse::save()
{
	ofstream out;
	out.open("椭圆.txt", ios::out);
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

	cout << "保存成功" << endl;
	system("pause");
}
void drawellipse::change()
{
	cout << "你正在修改椭圆的参数,请输入第几个椭圆" << endl;
	int t;
	cin >> t;
	this->input();
	p5[t] = *this;
	cout << "编辑成功" << endl;
	save();
	cleardevice();
}
void drawellipse::input()
{

	cout << "请输入x，y,xx,yy" << endl;
	cin >> x >> y >> xx>>yy;

	cout << "请输入线条颜色，1红色   2蓝色   3黄色   4白色" << endl;
	cin >> color1;

	cout << "请输入填充颜色，1红色   2蓝色   3黄色   4白色" << endl;
	cin >> color2;
}
void drawellipse::move()
{
	cout << "你想移动第几个椭圆" << endl;
	int t;
	cin >> t;
	cout << "请输入你想将椭圆的中心移到的坐标x,y" << endl;
	int x, y;
	cin >> x >> y;   //现中点坐标
	
	int x1 = (p5[t].xx + p5[t].x) / 2;//原中点坐标
	int y1 = (p5[t].yy + p5[t].y) / 2;

	if (x1< x&&y1<y) //往右下角动
	{
		int w = abs(p5[t].xx - p5[t].x);
		int h = abs(p5[t].yy - p5[t].y);
		p5[t].x = x - w / 2;
		p5[t].y = y - h / 2;
		p5[t].xx = x + w / 2;
		p5[t].yy = y+ h / 2;
	}
	if (x1> x&& y1>y) //往左上角动
	{
		int w = abs(p5[t].xx - p5[t].x);
		int h = abs(p5[t].yy - p5[t].y);
		p5[t].x = x - w / 2;
		p5[t].y = y - h / 2;
		p5[t].xx = x + w / 2;
		p5[t].yy = y + h / 2;
	}
	if (x1<x && y1 > y) //往右上角动
	{
		int w = abs(p5[t].xx - p5[t].x);
		int h = abs(p5[t].yy - p5[t].y);
		p5[t].x = x - w / 2;
		p5[t].y = y - h / 2;
		p5[t].xx = x + w / 2;
		p5[t].yy= y + h / 2;
	}
	if (x1> x &&y1 < y) //往左下角动
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
	cout << "你想复制第几个椭圆" << endl;
	int t;
	cin >> t;
	cout << "请输入复制中心到什么位置，既x,y的坐标" << endl;
	int x, y;
	cin >> x >> y;
	
	int x1 = (p5[t].xx + p5[t].x) / 2;//原中点坐标
	int y1 = (p5[t].yy + p5[t].y) / 2;

	int w = abs(p5[t].xx - p5[t].x);
	int h = abs(p5[t].yy - p5[t].y);
	if (x1 < x && y1 < y) //往右下角动
	{
		int w = abs(p5[t].xx - p5[t].x);
		int h = abs(p5[t].yy - p5[t].y);
		p5[t].x = x - w / 2;
		p5[t].y = y - h / 2;
		p5[t].xx = x + w / 2;
		p5[t].yy = y + h / 2;
	}
	if (x1 > x && y1 > y) //往左上角动
	{
		int w = abs(p5[t].xx - p5[t].x);
		int h = abs(p5[t].yy - p5[t].y);
		p5[t].x = x - w / 2;
		p5[t].y = y - h / 2;
		p5[t].xx = x + w / 2;
		p5[t].yy = y + h / 2;
	}
	if (x1<x && y1 > y) //往右上角动
	{
		int w = abs(p5[t].xx - p5[t].x);
		int h = abs(p5[t].yy - p5[t].y);
		p5[t].x = x - w / 2;
		p5[t].y = y - h / 2;
		p5[t].xx = x + w / 2;
		p5[t].yy = y + h / 2;
	}
	if (x1 > x && y1 < y) //往左下角动
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
	cout << "你想缩放第几个椭圆" << endl;
	int t;
	cin >> t;
	cout << "请输入你的缩放倍数,仅限于0-5" << endl;
	int time;
	cin >> time;
	int x1 = (p5[t].xx + p5[t].x) / 2;//原中点坐标
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
	cout << "你想删除第几个椭圆" << endl;
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
	cout << "打开全部文件按1，打开部分文件按2" << endl;
	cin >> q;
	int i5 = 1;         //关于圆的操作
	ifstream in5;
	in5.open("椭圆.txt", ios::in);
	if (q == 1)
	{
		int i5 = 1;         //关于椭圆的操作
		ifstream in5;
		in5.open("椭圆.txt", ios::in);
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
		cout << "请输入打开直线文件的序号" << endl;
		int t;
		cin >> t;
		if (t > k5)
		{
			cout << "此文件未创建" << endl;
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
	void add();//添加功能
	void save();  //存储数据到文件
	void change();//编辑功能
	void input();//输入功能
	void move();//移动功能
	void copy();//拷贝功能
	void zoom();//缩放功能
	void cut(); //删除图片功能
	void open();//打开文件功能
};
drawretangle p6[max];
void drawretangle::add()
{
	cout << "请输入矩形的编号，从1开始" << endl;
	int ID;
	cin >> ID;
	int x, y, xx, yy, width, color1, color2;
	cout << "请输入x，y,xx,yy" << endl;
	cin >> x >> y >> xx >> yy;

	p6[k6].ID = ID;
	p6[k6].x = x;          //从1开始的
	p6[k6].y = y;
	p6[k6].xx = xx;
	p6[k6].yy = yy;
	cout << "请输入线宽度" << endl;
	cin >> width;
	p6[k6].width = width;
	cout << "请输入线条颜色，1红色   2蓝色   3黄色   4白色" << endl;
	cin >> color1;
	p6[k6].color1 = color1;
	cout << "请输入填充颜色，1红色   2蓝色   3黄色   4白色" << endl;
	cin >> color2;
	p6[k6].color2 = color2;
}
void drawretangle::save()
{
	ofstream out;
	out.open("矩形.txt", ios::out);
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

	cout << "保存成功" << endl;
	system("pause");
}
void drawretangle::change()
{
	cout << "你正在修改矩形的参数,请输入第几个矩形" << endl;
	int t;
	cin >> t;
	this->input();
	p6[t] = *this;
	cout << "编辑成功" << endl;
	save();
	cleardevice();


}
void drawretangle::input()
{

	cout << "请输入x，y,xx,yy" << endl;
	cin >> x >> y >> xx >> yy;

	cout << "请输入线条颜色，1红色   2蓝色   3黄色   4白色" << endl;
	cin >> color1;

	cout << "请输入填充颜色，1红色   2蓝色   3黄色   4白色" << endl;
	cin >> color2;
}
void drawretangle::move()
{
	cout << "你想移动第几个矩形" << endl;
	int t;
	cin >> t;
	cout << "请输入你想将矩形的中心移到的坐标x,y" << endl;
	int x, y;
	cin >> x >> y;   //现中点坐标

	int x1 = (p6[t].xx + p6[t].x) / 2;//原中点坐标
	int y1 = (p6[t].yy + p6[t].y) / 2;

	if (x1 < x && y1 < y) //往右下角动
	{
		int w = abs(p6[t].xx - p6[t].x);
		int h = abs(p6[t].yy - p6[t].y);
		p6[t].x = x - w / 2;
		p6[t].y = y - h / 2;
		p6[t].xx = x + w / 2;
		p6[t].yy = y + h / 2;
	}
	if (x1 > x && y1 > y) //往左上角动
	{
		int w = abs(p6[t].xx - p6[t].x);
		int h = abs(p6[t].yy - p6[t].y);
		p6[t].x = x - w / 2;
		p6[t].y = y - h / 2;
		p6[t].xx = x + w / 2;
		p6[t].yy = y + h / 2;
	}
	if (x1<x && y1 > y) //往右上角动
	{
		int w = abs(p6[t].xx - p6[t].x);
		int h = abs(p6[t].yy - p6[t].y);
		p6[t].x = x - w / 2;
		p6[t].y = y - h / 2;
		p6[t].xx = x + w / 2;
		p6[t].yy = y + h / 2;
	}
	if (x1 > x && y1 < y) //往左下角动
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
	cout << "你想复制第几个矩形" << endl;
	int t;
	cin >> t;
	cout << "请输入复制中心到什么位置，既x,y的坐标" << endl;
	int x, y;
	cin >> x >> y;

	int x1 = (p6[t].xx + p6[t].x) / 2;//原中点坐标
	int y1 = (p6[t].yy + p6[t].y) / 2;

	int w = abs(p6[t].xx - p6[t].x);
	int h = abs(p6[t].yy - p6[t].y);
	if (x1 < x && y1 < y) //往右下角动
	{
		int w = abs(p6[t].xx - p6[t].x);
		int h = abs(p6[t].yy - p6[t].y);
		p6[t].x = x - w / 2;
		p6[t].y = y - h / 2;
		p6[t].xx = x + w / 2;
		p6[t].yy = y + h / 2;
	}
	if (x1 > x && y1 > y) //往左上角动
	{
		int w = abs(p6[t].xx - p6[t].x);
		int h = abs(p6[t].yy - p6[t].y);
		p6[t].x = x - w / 2;
		p6[t].y = y - h / 2;
		p6[t].xx = x + w / 2;
		p6[t].yy = y + h / 2;
	}
	if (x1<x && y1 > y) //往右上角动
	{
		int w = abs(p6[t].xx - p6[t].x);
		int h = abs(p6[t].yy - p6[t].y);
		p6[t].x = x - w / 2;
		p6[t].y = y - h / 2;
		p6[t].xx = x + w / 2;
		p6[t].yy = y + h / 2;
	}
	if (x1 > x && y1 < y) //往左下角动
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
	cout << "你想缩放第几个矩形" << endl;
	int t;
	cin >> t;
	cout << "请输入你的缩放倍数,仅限于0-5" << endl;
	int time;
	cin >> time;
	int x1 = (p6[t].xx + p6[t].x) / 2;//原中点坐标
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
	cout << "你想删除第几个矩形" << endl;
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
	cout << "打开全部文件按1，打开部分文件按2" << endl;
	cin >> q;
	int i6 = 1;         //关于圆的操作
	ifstream in6;
	in6.open("矩形.txt", ios::in);
	if (q == 1)
	{
		int i6 = 1;         //关于椭圆的操作
		ifstream in6;
		in6.open("矩形.txt", ios::in);
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
		cout << "请输入打开直线文件的序号" << endl;
		int t;
		cin >> t;
		if (t > k6)
		{
			cout << "此文件未创建" << endl;
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
	void add();//添加功能
	void save();  //存储数据到文件
	void change();//编辑功能
	void input();//输入功能
	void move();//移动功能
	void copy();//拷贝功能
	void zoom();//缩放功能
	void cut(); //删除图片功能
	void open();//打开文件功能

};
drawsolidpolygon p7[max];
void  drawsolidpolygon::add()
{
	int ID;
	cout << "请输入折线编号，从1开始" << endl;
	cin >> ID;
	cout << "请输入折点的个数" << endl;

	cin >> n1;
	int x, y, width, color1;

	for (int i = 1; i <= n1; i++)
	{
		cout << "请输入x，y的坐标" << endl;
		cin >> x >> y;
		p3[k3].ID = ID;
		p3[k3].point[i][0] = x;          //从1开始的
		p3[k3].point[i][1] = y;

		if (i == n1)cout << "录入结束" << endl;
	}
	cout << "请输入线宽度" << endl;
	cin >> width;
	p3[k3].width = width;
	cout << "请输入线条颜色，1红色   2蓝色   3黄色   4白色" << endl;
	cin >> color1;
	p3[k3].color1 = color1;
}
void  drawsolidpolygon::save()
{
	ofstream out;
	out.open("折线.txt", ios::out);
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

	cout << "保存成功" << endl;
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
	
	
	
	
	
	int i2 = 1;         //关于线的操作
	ifstream in2;
	in2.open("线.txt", ios::in);
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

	
	
	int i3 = 1;         //关于线的操作
	ifstream in3;
	in3.open("折线.txt", ios::in);
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




	
	
	int i4= 1;         //关于圆的操作
	ifstream in4;
	in4.open("圆.txt", ios::in);
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


	int i5 = 1;         //关于椭圆的操作
	ifstream in5;
	in5.open("椭圆.txt", ios::in);
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


	int i6 = 1;         //关于椭圆的操作
	ifstream in6;
	in6.open("矩形.txt", ios::in);
	if (!in6)
	{
		cerr << "fail" << endl; return;
	}
	while (true)
	{
		in6 >> p6[i6].ID >> p6[i6].x >> p6[i6].y >> p6[i6].xx >> p6[i6].yy >> p6[i6].width >> p6[i6].color1 >> p6[i6].color2;

		cout << "线宽" << p6[i6].width << endl;
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

		cout << "我们可以绘制以下图像，请按照对应的数字输入，例如：圆（4）" << endl;
		cout << "点         （1）" << endl;
		cout << "直线       （2）" << endl;
		cout << "折线       （3）" << endl;
		cout << "圆         （4）" << endl;
		cout << "椭圆形     （5）" << endl;
		cout << "矩形       （6）" << endl;
		cout << "多边形     （7）" << endl;
		int a;
		cout << "请输入您需要绘制(或编辑的)的图像:" << endl;
		cin >> a;

		if (a == 1)
		{
			int x, y;
			cout << "请输入x，y的坐标" << endl;
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
			cout << "是否结束绘图,如果按1退出，如果按2则编辑所画图形" << endl;

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
			cout << "是否结束绘图,如果按1退出，如果按2则编辑所画图形" << endl;

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
			cout << "是否结束绘图,如果按1退出，如果按2则编辑所画图形" << endl;
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
			cout << "是否结束绘图,如果按1退出，如果按2则编辑所画图形" << endl;
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
			cout << "是否结束绘图,如果按1退出，如果按2则编辑所画图形" << endl;
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
				cout << "我们有以下功能：（0）增加其他图形（1）编辑几何参数  （2）移动图片  （3）缩放图片  (4)复制图片  （5）保存到文件  （6）打开文件（7）删除图片  （8）退出系统" << endl;
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
					cout << "请输入你想编辑的图形的编号和次序,例如直线就输入2,圆就输入4" << endl;
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
		
					break;       //破坏switch循环
				}
				case(2):
				{
					cout << "请输入你想移动的图形的编号,例如直线就输入2,圆就输入4" << endl;
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

				break;       //破坏switch循环
				}
				case(3):
				{
					cout << "请输入你想缩放的图形的编号和次序,例如直线就输入2,圆就输入4" << endl;
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
					break;       //破坏switch循环
				}
				case(4):
				{
					cout << "请输入你想复制的图形的编号和次序,例如直线就输入2,圆就输入4" << endl;
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
					break;       //破坏switch循环
				}
				case(5):
				{
					cout << "请输入你保存的图形的编号和次序,例如直线就输入2,圆就输入4" << endl;
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
					break;       //破坏switch循环
				}
				case(6):
				{
					cout << "请输入你想打开的图形的编号,例如直线就输入2,圆就输入4" << endl;
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
					break;       //破坏switch循环
				}
				case(7):
				{
					cout << "请输入你删除的图形的编号和次序,例如直线就输入2,圆就输入4" << endl;
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
					break;       //破坏switch循环
				}
				case(8):
				{
					cout << "您是否保存了文件，如果已经保存按1退出，如果未保存按2保存文件，之后系统会自动帮您退出。" << endl;
					int a;
					cin >> a;
					if (a == 1)
					{
						return 0;
					}
					if (a == 2)
					{
						cout << "保存文件成功" << endl;


					}

					break;
				}
				}
			}
		}
}
