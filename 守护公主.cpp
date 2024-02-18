/*
首先先通过定义多个数组实现气球的定向移动，然后通过两个flag实现猴塔的选择与放置，
加入距离判定实现猴塔的攻击范围，通过两层逻辑判断实现猴塔对气球的判定击杀，最后再通
过血量实现气球的爆炸图和音效的输出，气球短暂的音效需用playsound函数播放，才不会出现卡顿
*/
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"Winmm.lib")

#define N 50		//气球数量
#define r1 120		//猴塔-1半径
#define r2 90		//猴塔-2半径
#define r3 800      //猴塔-3半径 全图
#define r4 100      //猴塔-4半径
#define r5 120		//猴塔-5半径
#define r6 90		//猴塔-6半径
#define r7 150		//猴塔-7半径
#define r8 170		//猴塔-8半径
#define buildhouta1	150		//猴塔-1所需的金钱
#define buildhouta2 200		//猴塔-2所需的金钱
#define buildhouta3 500		//猴塔-3所需的金钱
#define buildhouta4 200		//猴塔-4所需的金钱
#define buildhouta5 150		//猴塔-5所需的金钱
#define buildhouta6 250		//猴塔-6所需的金钱
#define buildhouta7 400		//猴塔-7所需的金钱
#define buildhouta8 1000	//猴塔-8所需的金钱


IMAGE img_bk;		//背景图
IMAGE img_jt1;		//箭头遮罩图
IMAGE img_jt2;		//箭头原图
IMAGE img_start11;	//开始按钮遮罩图
IMAGE img_start12;	//开始按钮原图
IMAGE img_start21;	//开始按钮遮罩图
IMAGE img_start22;	//开始按钮原图


IMAGE img_blockMask[N];			//气球爆炸图
IMAGE img_block[N];
IMAGE img_blockMask1;			//BOSS爆炸图
IMAGE img_block1;


IMAGE img_redup[N];				//第一波气球图
IMAGE img_redupMask[N];
IMAGE img_reddown[N];
IMAGE img_reddownMask[N];

IMAGE img_redup2[N];			//第二波气球图
IMAGE img_redup2Mask[N];
IMAGE img_reddown2[N];
IMAGE img_reddown2Mask[N];

IMAGE img_blueup[N];			//第三波气球图
IMAGE img_blueupMask[N];
IMAGE img_bluedown[N];
IMAGE img_bluedownMask[N];

IMAGE img_greenup[N];			//第四波气球图
IMAGE img_greenupMask[N];
IMAGE img_greendown[N];
IMAGE img_greendownMask[N];

IMAGE img_micaiup[N];			//第五波气球图
IMAGE img_micaiupMask[N];
IMAGE img_micaidown[N];
IMAGE img_micaidownMask[N];

IMAGE img_gangup[N];			//第六波气球图
IMAGE img_gangupMask[N];
IMAGE img_gangdown[N];
IMAGE img_gangdownMask[N];

IMAGE img_xinup[N];				//第七波气球图
IMAGE img_xinupMask[N];
IMAGE img_xindown[N];
IMAGE img_xindownMask[N];

IMAGE img_moya;					//第八波气球图
IMAGE img_moyaMask;


//飞镖图---------------//
IMAGE img_bart1[N];
IMAGE img_bart1Mask[N];
IMAGE img_bart2[N];
IMAGE img_bart2Mask[N];
IMAGE img_bart3[N];
IMAGE img_bart3Mask[N];
IMAGE img_bart4[N];
IMAGE img_bart4Mask[N];
IMAGE img_bart11;
IMAGE img_bart11Mask;
IMAGE img_bart22;
IMAGE img_bart22Mask;
IMAGE img_bart33;
IMAGE img_bart33Mask;
IMAGE img_bart44;
IMAGE img_bart44Mask;

IMAGE img_huixuan;		//回旋镖图
IMAGE img_huixuanMask;


IMAGE img_bian;			//边框图
IMAGE img_houta11;		//猴塔-1遮罩图
IMAGE img_houta12;		//猴塔-1原图
IMAGE img_houta1red1;	//猴塔-1的红色图
IMAGE img_houta1red2;	//猴塔-1的红色遮罩图


IMAGE img_houta21;		//猴塔-2遮罩图
IMAGE img_houta22;		//猴塔-2原图
IMAGE img_houta2red1;	//猴塔-2的红色图
IMAGE img_houta2red2;	//猴塔-2的红色遮罩图


IMAGE img_houta31;		//猴塔-3遮罩图
IMAGE img_houta32;		//猴塔-3原图
IMAGE img_houta33;		//猴塔-3遮罩图
IMAGE img_houta34;		//猴塔-3原图
IMAGE img_houta3red1;	//猴塔-3的红色图
IMAGE img_houta3red2;	//猴塔-3的红色遮罩图

IMAGE img_houta41;		//猴塔-4遮罩图
IMAGE img_houta42;		//猴塔-4原图
IMAGE img_houta4red1;   //猴塔-4灰色遮罩图
IMAGE img_houta4red2;	//猴塔-4灰色原图

IMAGE img_houta51;		//猴塔-5遮罩图
IMAGE img_houta52;		//猴塔-5原图
IMAGE img_houta5red1;	//猴塔-5灰色遮罩图
IMAGE img_houta5red2;	//猴塔-5灰色原图

IMAGE img_houta61;		//猴塔-6遮罩图
IMAGE img_houta62;		//猴塔-6原图
IMAGE img_houta6red1;   //猴塔-6灰色遮罩图
IMAGE img_houta6red2;	//猴塔-6灰色原图

IMAGE img_houta71;		//猴塔-7遮罩图
IMAGE img_houta72;		//猴塔-7原图
IMAGE img_houta7red1;	//猴塔-7灰色遮罩图
IMAGE img_houta7red2;	//猴塔-7灰色原图

IMAGE img_houta81;		//猴塔-8遮罩图
IMAGE img_houta82;		//猴塔-8原图
IMAGE img_houta8red1;	//猴塔-8灰色遮罩图
IMAGE img_houta8red2;	//猴塔-8灰色原图

						//定义若干组气球

int redup_x[N];		//上路第一波气球横坐标
int redup_y[N];		//上路第一波气球纵坐标
int reddown_x[N];	//下路第一波气球横坐标
int reddown_y[N];	//下路第一波气球纵坐标

int redup2_x[N];	//上路第二波气球横坐标
int redup2_y[N];	//上路第二波气球纵坐标
int reddown2_x[N];	//下路第二波气球横坐标
int reddown2_y[N];	//下路第二波气球纵坐标

int blueup_x[N];	//上路第三波气球横坐标
int blueup_y[N];	//上路第三波气球纵坐标
int bluedown_x[N];	//下路第三波气球横坐标
int bluedown_y[N];	//下路第三波气球纵坐标

int greenup_x[N];	 //上路第四波气球横坐标
int greenup_y[N];	 //上路第四波气球纵坐标
int greendown_x[N];	 //下路第四波气球横坐标
int greendown_y[N];	 //下路第四波气球纵坐标

int micaiup_x[N];	//上路第五波气球横坐标
int micaiup_y[N];	//上路第五波气球纵坐标
int micaidown_x[N]; //下路第五波气球横坐标
int micaidown_y[N]; //下路第五波气球纵坐标

int gangup_x[N];	 //上路第六波气球横坐标
int gangup_y[N];	 //上路第六波气球纵坐标
int gangdown_x[N];	 //下路第六波气球横坐标
int gangdown_y[N];	 //下路第六波气球纵坐标

int xinup_x[N];		//上路第七波气球横坐标
int xinup_y[N];		//上路第七波气球纵坐标
int xindown_x[N];	//下路第七波气球横坐标
int xindown_y[N];   //下路第七波气球纵坐标

int moya_x;			//摩压横坐标
int moya_y;			//摩压纵坐标

float huixuan_x;	//回旋镖的横坐标
float huixuan_y;	//回旋镖的纵坐标
float vx = -1;		//回旋镖的速度

					//定义气球生命-------------------------------------------//

float HP[8] = { 10,10,10,10,10,10,10,10 };		//上面第一波气球的生命

float HPdown1[8] = { 10,10,10,10,10,10,10,10 };	//下面第一波气球的生命

float HPup2[8] = { 20,20,20,20,20,20,20,20 };   //上面第二波气球的生命

float HPdown2[8] = { 20,20,20,20,20,20,20,20 };	//下面第二波气球的生命

float HPup3[8] = { 20,20,20,20,20,20,20,20 };  //上面第三波气球的生命

float HPdown3[8] = { 20,20,20,20,20,20,20,20 };//下面第三波气球的生命

float HPup4[8] = { 30,30,30,30,30,30,30,30 };  //上面第四波气球的生命

float HPdown4[8] = { 30,30,30,30,30,30,30,30 };//下面第四波气球的生命

float HPup5[8] = { 10,10,10,10,10,10,10,10 };  //上面第五波气球的生命

float HPdown5[8] = { 10,10,10,10,10,10,10,10 };//下面第五波气球的生命

float HPup6[8] = { 40,40,40,40,40,40,40,40 };  //上面第六波气球的生命

float HPdown6[8] = { 40,40,40,40,40,40,40,40 };//下面第六波气球的生命

float HPup7[8] = { 50,50,50,50,50,50,50,50 };  //上面第七波气球的生命

float HPdown7[8] = { 50,50,50,50,50,50,50,50 };//下面第七波气球的生命

int HP8 = 800;//摩压的生命

int money;		//总金钱
int life;   //总生命
int count1;
int count2;

int monkey1_x;		//猴塔-1坐标
int monkey1_y;

int monkey2_x;		//猴塔-2坐标
int monkey2_y;

int monkey3_x;		//猴塔-3坐标
int monkey3_y;

int monkey4_x;		//猴塔-4坐标
int monkey4_y;

int monkey5_x;		//猴塔-5坐标
int monkey5_y;

int monkey6_x;		//猴塔-6坐标
int monkey6_y;

int monkey7_x;		//猴塔-7坐标
int monkey7_y;

int monkey8_x;		//猴塔-8坐标
int monkey8_y;

int speed;			//定义气球速度
int speed2;         //BOSS速度
int Begin = 1;	//点击开始之后
int BeginChange = 1;	//控制开始按钮的变化

int gamestart = 1;			//开始界面
int menu_start = 1;			//开始游戏
int menu_instruction = 1;	//游戏说明
int menu_person = 1;		//制作人员
int menu_exit = 1;			//退出游戏
int menu_tower = 1;

int gameover_control = 1;   //游戏失败
int success_control = 1;
int over_exit = 1;

int Houta_1_IsPutdown = 1;	//右击之后放下猴塔-1
int Houta_1_IsChose = 1;	//选择边框猴塔-1之后

int Houta_2_IsPutdown = 1;	//右击之后放下猴塔-2
int Houta_2_IsChose = 1;	//选择边框猴塔-2之后


int Houta_3_IsChose = 1;	//右击之后放下猴塔-3
int Houta_3_IsPutdown = 1;	//选择边框猴塔-3之后


int Houta_4_IsChose = 1;	//右击之后放下猴塔-4
int Houta_4_IsPutdown = 1;	//选择边框猴塔-4之后


int Houta_5_IsChose = 1;	//右击之后放下猴塔-5
int Houta_5_IsPutdown = 1;	//选择边框猴塔-5之后


int Houta_6_IsChose = 1;	//右击之后放下猴塔-6
int Houta_6_IsPutdown = 1;	//选择边框猴塔-6之后

int Houta_7_IsChose = 1;	//右击之后放下猴塔-7
int Houta_7_IsPutdown = 1;	//选择边框猴塔-7之后

int Houta_8_IsChose = 1;	//右击之后放下猴塔-8
int Houta_8_IsPutdown = 1;	//选择边框猴塔-8之后

							//游戏说明*******************
void instruction()
{
	IMAGE img_j;
	loadimage(&img_j, L"说明界面.jpg");
	putimage(0, 0, &img_j);
	IMAGE img_red1;
	IMAGE img_red2;
	IMAGE img_green1;
	IMAGE img_green2;
	IMAGE img_blue1;
	IMAGE img_blue2;
	IMAGE img_qiqiu41;
	IMAGE img_qiqiu42;
	IMAGE img_qiqiu51;
	IMAGE img_qiqiu52;
	IMAGE img_qiqiu61;
	IMAGE img_qiqiu62;
	IMAGE img_qiqiu71;
	IMAGE img_qiqiu72;
	loadimage(&img_red1, L"red1.jpg");
	loadimage(&img_red2, L"red2.jpg");
	loadimage(&img_green1, L"green1.jpg");
	loadimage(&img_green2, L"green.jpg");
	loadimage(&img_blue1, L"blue_mask.jpg");
	loadimage(&img_blue2, L"blue.jpg");
	loadimage(&img_qiqiu41, L"迷彩气球_mask.jpg");
	loadimage(&img_qiqiu42, L"迷彩气球.jpg");
	loadimage(&img_qiqiu51, L"爱心气球_mask.jpg");
	loadimage(&img_qiqiu52, L"爱心气球.jpg");
	loadimage(&img_qiqiu61, L"钢气球_mask.jpg");
	loadimage(&img_qiqiu62, L"钢气球.jpg");
	loadimage(&img_qiqiu71, L"摩压_mask.bmp");
	loadimage(&img_qiqiu72, L"摩压.bmp");
	putimage(65, 50, &img_red1, SRCAND);	//显示红气球
	putimage(65, 50, &img_red2, SRCPAINT);
	putimage(60, 100, &img_blue1, SRCAND);	//显示蓝气球
	putimage(60, 100, &img_blue2, SRCPAINT);
	putimage(60, 150, &img_green1, SRCAND);	//显示绿气球
	putimage(60, 150, &img_green2, SRCPAINT);
	putimage(305, 40, &img_qiqiu41, SRCAND);	//显示迷彩气球
	putimage(305, 40, &img_qiqiu42, SRCPAINT);
	putimage(300, 90, &img_qiqiu51, SRCAND);	//显示爱心气球
	putimage(300, 90, &img_qiqiu52, SRCPAINT);
	putimage(300, 150, &img_qiqiu61, SRCAND);	//显示钢气球
	putimage(300, 150, &img_qiqiu62, SRCPAINT);
	putimage(450, 20, &img_qiqiu71, SRCAND);	//显示摩压
	putimage(450, 20, &img_qiqiu72, SRCPAINT);

	//输出游戏说明************************************

	setcolor(YELLOW);

	settextstyle(25, 0, L"黑体");

	setbkmode(TRANSPARENT);

	outtextxy(100, 60, L"最初始的怪物");

	outtextxy(100, 110, L"升级版的怪物");

	outtextxy(100, 160, L"不简单的怪物");

	outtextxy(350, 60, L"只能用忍者雪人阻止");
	outtextxy(350, 110, L"小心点");
	outtextxy(350, 160, L"危险");
	setcolor(RED);
	settextstyle(45, 0, L"黑体");
	outtextxy(550, 120, L"BOSS");
	setcolor(YELLOW);
	settextstyle(25, 0, L"黑体");
	outtextxy(60, 220, L"每个雪人只能存在一种，可以再次点击换位置，但原来的会消失");
	outtextxy(60, 270, L"别让怪物跑掉，你的生命会减少");
	outtextxy(60, 320, L"鼠标移动雪人的位置，单击右键放下");
	outtextxy(60, 370, L"每个雪人有不同的功能，用它们来阻止气球");
	setcolor(RED);
	outtextxy(60, 320, L"鼠标移动雪人的位置，单击右键放下");
	setcolor(YELLOW);
	outtextxy(60, 320, L"鼠标移动雪人的位置，单击    放下");
	settextstyle(35, 0, L"华文新魏");
	outtextxy(310, 420, L"祝你好运");
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, L"黑体");
	setcolor(RGB(255, 20, 25));//颜色
	outtextxy(300, 500, L"按任意键返回");
	if (_getch() == ' ')
	{
		gamestart = 1;
	}
	setcolor(RGB(255, 255, 255));//颜色



}

//防御塔说明******************
void tower()
{
	cleardevice();
	IMAGE img_j;
	loadimage(&img_j, L"塔图背景.jpg");
	putimage(0, 0, &img_j);
	IMAGE img_hou_11;
	IMAGE img_hou_12;
	IMAGE img_hou_21;
	IMAGE img_hou_22;
	IMAGE img_hou_31;
	IMAGE img_hou_32;
	IMAGE img_hou_41;
	IMAGE img_hou_42;
	IMAGE img_hou_51;
	IMAGE img_hou_52;
	IMAGE img_hou_61;
	IMAGE img_hou_62;
	IMAGE img_hou_71;
	IMAGE img_hou_72;
	IMAGE img_hou_81;
	IMAGE img_hou_82;
	loadimage(&img_hou_11, L"普通猴1_mask.jpg");
	loadimage(&img_hou_12, L"普通猴1.jpg");
	loadimage(&img_hou_21, L"针塔1_mask.jpg");
	loadimage(&img_hou_22, L"针塔1.jpg");
	loadimage(&img_hou_31, L"狙击猴1_mask.jpg");
	loadimage(&img_hou_32, L"狙击猴1.jpg");
	loadimage(&img_hou_41, L"飞镖猴1_mask.jpg");
	loadimage(&img_hou_42, L"飞镖猴1.jpg");
	loadimage(&img_hou_51, L"忍者猴1_mask.jpg");
	loadimage(&img_hou_52, L"忍者猴1.jpg");
	loadimage(&img_hou_61, L"冰猴1_mask.jpg");
	loadimage(&img_hou_62, L"冰猴1.jpg");
	loadimage(&img_hou_71, L"炮塔1_mask.jpg");
	loadimage(&img_hou_72, L"炮塔1.jpg");
	loadimage(&img_hou_81, L"超人猴1_mask.jpg");
	loadimage(&img_hou_82, L"超人猴1.jpg");
	putimage(60, 100, &img_hou_11, SRCAND);	//显示猴子1
	putimage(60, 100, &img_hou_12, SRCPAINT);
	putimage(60, 200, &img_hou_21, SRCAND);	//显示猴子2
	putimage(60, 200, &img_hou_22, SRCPAINT);
	putimage(60, 300, &img_hou_31, SRCAND);	//显示猴子3
	putimage(60, 300, &img_hou_32, SRCPAINT);
	putimage(60, 400, &img_hou_41, SRCAND);	//显示猴子4
	putimage(60, 400, &img_hou_42, SRCPAINT);
	putimage(460, 200, &img_hou_51, SRCAND);	//显示猴子5
	putimage(460, 200, &img_hou_52, SRCPAINT);
	putimage(460, 100, &img_hou_61, SRCAND);	//显示猴子6
	putimage(460, 100, &img_hou_62, SRCPAINT);
	putimage(460, 300, &img_hou_71, SRCAND);	//显示猴子7
	putimage(460, 300, &img_hou_72, SRCPAINT);
	putimage(460, 400, &img_hou_81, SRCAND);	//显示猴子8
	putimage(460, 400, &img_hou_82, SRCPAINT);

	setbkmode(TRANSPARENT);
	setcolor(YELLOW);
	settextstyle(25, 0, L"黑体");
	outtextxy(110, 120, L"普通雪人(120)：就是一种塔");
	outtextxy(110, 220, L"多重雪人(200)：很好用的一种塔");
	outtextxy(110, 320, L"狙击雪人(500)：可以全图攻击");
	outtextxy(110, 420, L"飞镖雪人(130)：只能放在路上");
	outtextxy(510, 220, L"忍者雪人(130)：可以打破迷彩气球");
	outtextxy(510, 120, L"冰雪人(100)：有神奇的功能");
	outtextxy(510, 320, L"活力雪人(400)：火力更猛");
	outtextxy(510, 420, L"超人雪人(800)：这是bug级别的塔");

	setbkmode(TRANSPARENT);
	settextstyle(30, 0, L"楷体");
	setcolor(RGB(255, 20, 25));//颜色
	outtextxy(300, 500, L"按任意键返回");
	if (_getch() == ' ')
	{
		gamestart = 1;
	}

}

//游戏制作人员****************
void person()
{
	cleardevice();
	IMAGE img_person;
	loadimage(&img_person, L"人员界面.jpg");
	putimage(0, 0, &img_person);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, L"黑体");
	setcolor(RED);//颜色
	outtextxy(730, 550, L"按任意键返回");

	settextstyle(33, 0, L"黑体");
	setcolor(BLACK);//颜色
	outtextxy(250, 30, L"19070707班");
	outtextxy(431, 450, L"1907040735王纪超");
	
	if (_getch() == ' ')
	{
		gamestart = 1;
	}
}


//菜单界面*********************
void  menu()
{
	//-----------------------------菜单音乐------------------------------//
	mciSendString(L"close bkmusic", NULL, 0, NULL); // 先把前面一次的音乐关闭
	mciSendString(L"open 背景音乐.mp3 alias menumusic", NULL, 0, NULL);//打开背景音乐

	mciSendString(L"play menumusic repeat", NULL, 0, NULL);  // 循环播放
	IMAGE img_Start;
	loadimage(&img_Start, L"开始背景.jpg");
	putimage(0, 0, &img_Start);
	setbkmode(TRANSPARENT);
	setcolor(WHITE);
	settextstyle(25, 0, L"黑体");
	outtextxy(750, 414, L"开  始");
	outtextxy(410, 290, L"防御塔");
	outtextxy(459, 334, L"游戏说明");
	outtextxy(745, 150, L"制作人员");
	outtextxy(74, 275, L"退  出");
	if (menu_start == 0)
	{
		setcolor(YELLOW);
		outtextxy(750, 414, L"开  始");
	}
	if (menu_tower == 0)
	{
		setcolor(YELLOW);
		outtextxy(410, 290, L"防御塔");
	}
	if (menu_instruction == 0)
	{
		setcolor(YELLOW);
		outtextxy(459, 334, L"游戏说明");
	}
	if (menu_person == 0)
	{
		setcolor(YELLOW);
		outtextxy(745, 150, L"制作人员");
	}
	if (menu_exit == 0)
	{
		setcolor(YELLOW);
		outtextxy(74, 275, L"退  出");
	}

	FlushBatchDraw();
	Sleep(20);
	MOUSEMSG m;		// 定义鼠标消息
	while (MouseHit())  //这个函数用于检测当前是否有鼠标消息
	{
		m = GetMouseMsg();

		if (m.x >= 750 && m.x <= 850 && m.y >= 400 && m.y <= 480)
		{
			menu_start = 0;
		}
		else if (m.x <= 750 || m.x >= 850 || m.y <= 400 || m.y >= 480)
		{
			menu_start = 1;
		}
		if (m.x >= 420 && m.x <= 520 && m.y >= 330 && m.y <= 380)
		{
			menu_instruction = 0;
		}
		else if (m.x <= 420 || m.x >= 520 || m.y <= 330 || m.y >= 380)
		{
			menu_instruction = 1;
		}
		if (m.x >= 360 && m.x <= 460 && m.y >= 280 && m.y <= 345)
		{
			menu_tower = 0;
		}
		else if (m.x <= 360 || m.x >= 460 || m.y <= 280 || m.y >= 345)
		{
			menu_tower = 1;
		}
		if (m.x >= 760 && m.x <= 860 && m.y >= 150 && m.y <= 205)
		{
			menu_person = 0;
		}
		else if (m.x <= 760 || m.x >= 860 || m.y <= 150 || m.y >= 205)
		{
			menu_person = 1;
		}
		if (m.x >= 70 && m.x <= 180 && m.y >= 240 && m.y <= 300)
		{
			menu_exit = 0;
		}
		else if (m.x <= 70 || m.x >= 180 || m.y <= 240 || m.y >= 300)
		{
			menu_exit = 1;
		}



		if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 750 && m.x <= 850 && m.y >= 400 && m.y <= 480)//鼠标点击开始游戏
		{
			gamestart = 0;
		}
		else if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 420 && m.x <= 520 && m.y >= 330 && m.y <= 380)//鼠标点击进入游戏说明界面
		{
			instruction();
		}
		else if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 360 && m.x <= 460 && m.y >= 280 && m.y <= 345)//鼠标点击进入防御塔介绍
		{
			tower();
		}
		else if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 760 && m.x <= 860 && m.y >= 150 && m.y <= 205)//鼠标点击进入制作组界面
		{
			person();
		}
		else if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 70 && m.x <= 180 && m.y >= 240 && m.y <= 300)
		{
			exit(0);
		}
	}
}

//成功界面*********************
void success()
{
	cleardevice();
	IMAGE img_success;
	loadimage(&img_success, L"游戏成功.jpg");

	putimage(0, 0, &img_success);
	mciSendString(L"close bkmusic", NULL, 0, NULL); // 先把前面一次的音乐关闭

	mciSendString(L"open 成功音乐.mp3 alias successmusic", NULL, 0, NULL);//打开失败音乐

	mciSendString(L"play successmusic ", NULL, 0, NULL);  // 播放一次
	settextcolor(BLUE);//字体颜色
	settextstyle(30, 0, L"黑体");//字体类型
	outtextxy(410, 400, L"退出游戏");
	if (over_exit == 0)
	{
		setcolor(YELLOW);
		outtextxy(410, 400, L"退出游戏");
	}
	//显示游戏界面文字
	FlushBatchDraw();
	Sleep(2);
	MOUSEMSG m;		// 定义鼠标消息
	while (MouseHit())  //这个函数用于检测当前是否有鼠标消息
	{
		m = GetMouseMsg();
		if (m.x >= 335 && m.x <= 485 && m.y >= 380 && m.y <= 420)
		{
			over_exit = 0;
		}
		else if (m.x <= 335 || m.x >= 485 || m.y <= 380 || m.y >= 420)
		{
			over_exit = 1;
		}


		if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 335 && m.x <= 485 && m.y >= 375 && m.y <= 425)//鼠标点击退出游戏
		{
			exit(0);
		}
	}
}

//死亡界面**********************
void die()
{
	cleardevice();
	IMAGE img_over;
	loadimage(&img_over, L"游戏失败.jpg");

	putimage(0, 0, &img_over);
	mciSendString(L"close bkmusic", NULL, 0, NULL); // 先把前面一次的音乐关闭

	mciSendString(L"open 失败音乐.mp3 alias overmusic", NULL, 0, NULL);//打开失败音乐

	mciSendString(L"play overmusic ", NULL, 0, NULL);  // 播放一次
	settextcolor(RED);//字体颜色
	settextstyle(30, 0, L"黑体");//字体类型
	outtextxy(350, 400, L"退出游戏");
	if (over_exit == 0)
	{
		setcolor(YELLOW);
		outtextxy(350, 400, L"退出游戏");
	}
	//显示游戏界面文字
	FlushBatchDraw();
	Sleep(2);
	MOUSEMSG m;		// 定义鼠标消息
	while (MouseHit())  //这个函数用于检测当前是否有鼠标消息
	{
		m = GetMouseMsg();
		if (m.x >= 275 && m.x <= 425 && m.y >= 380 && m.y <= 420)
		{
			over_exit = 0;
		}
		else if (m.x <= 275 || m.x >= 425 || m.y <= 380 || m.y >= 420)
		{
			over_exit = 1;
		}


		if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 275 && m.x <= 425 && m.y >= 375 && m.y <= 425)//鼠标点击退出游戏
		{
			exit(0);
		}
	}
}

//初始定义******************
void startup()
{
	int i;
	//初始化金钱，生命，气球速度，boss的速度
	money = 1000;
	life = 20;
	speed = 5;
	speed2 = 2;

	//定义猴塔初始坐标
	monkey1_x = 820;
	monkey1_y = 120;

	monkey2_x = 870;
	monkey2_y = 120;

	monkey3_x = 825;
	monkey3_y = 155;

	monkey4_x = 870;
	monkey4_y = 155;

	monkey5_x = 820;
	monkey5_y = 190;

	monkey6_x = 870;
	monkey6_y = 190;

	monkey7_x = 820;
	monkey7_y = 255;

	monkey8_x = 870;
	monkey8_y = 255;

	initgraph(914, 580);		//初始画布

	loadimage(&img_bk, L"bk.jpg");
	loadimage(&img_jt1, L"1.jpg");
	loadimage(&img_jt2, L"2.jpg");
	loadimage(&img_start11, L"start11.bmp");
	loadimage(&img_start12, L"start12.bmp");
	loadimage(&img_start21, L"start21.bmp");
	loadimage(&img_start22, L"start22.bmp");



	//第一波气球

	for (i = 0; i < 8; i++)

	{
		loadimage(&img_redupMask[i], L"red1.jpg");
		loadimage(&img_redup[i], L"red2.jpg");
	}
	for (i = 0; i < 8; i++)
	{
		loadimage(&img_reddownMask[i], L"red1.jpg");
		loadimage(&img_reddown[i], L"red2.jpg");
	}

	//第二波气球

	for (i = 0; i < 8; i++)

	{
		loadimage(&img_redup2Mask[i], L"red1.jpg");
		loadimage(&img_redup2[i], L"red2.jpg");
	}
	for (i = 0; i < 8; i++)
	{
		loadimage(&img_reddown2Mask[i], L"red1.jpg");
		loadimage(&img_reddown2[i], L"red2.jpg");
	}

	//第三波气球

	for (i = 0; i < 8; i++)

	{
		loadimage(&img_blueupMask[i], L"blue_mask.jpg");
		loadimage(&img_blueup[i], L"blue.jpg");
	}
	for (i = 0; i < 8; i++)
	{
		loadimage(&img_bluedownMask[i], L"blue_mask.jpg");
		loadimage(&img_bluedown[i], L"blue.jpg");
	}

	//第四波气球


	for (i = 0; i < 8; i++)

	{
		loadimage(&img_greenupMask[i], L"green_mask.jpg");
		loadimage(&img_greenup[i], L"green.jpg");
	}
	for (i = 0; i < 8; i++)
	{
		loadimage(&img_greendownMask[i], L"green_mask.jpg");
		loadimage(&img_greendown[i], L"green.jpg");
	}

	//第五波气球


	for (i = 0; i < 8; i++)

	{
		loadimage(&img_micaiupMask[i], L"迷彩气球_mask.jpg");
		loadimage(&img_micaiup[i], L"迷彩气球.jpg");
	}
	for (i = 0; i < 8; i++)
	{
		loadimage(&img_micaidownMask[i], L"迷彩气球_mask.jpg");
		loadimage(&img_micaidown[i], L"迷彩气球.jpg");
	}

	//第六波气球


	for (i = 0; i < 8; i++)

	{
		loadimage(&img_gangupMask[i], L"钢气球_mask.jpg");
		loadimage(&img_gangup[i], L"钢气球.jpg");
	}
	for (i = 0; i < 8; i++)
	{
		loadimage(&img_gangdownMask[i], L"气球_mask.jpg");
		loadimage(&img_gangdown[i], L"气球.jpg");
	}

	//第七波气球


	for (i = 0; i < 8; i++)

	{
		loadimage(&img_xinupMask[i], L"爱心气球_mask.jpg");
		loadimage(&img_xinup[i], L"爱心气球.jpg");
	}
	for (i = 0; i < 8; i++)
	{
		loadimage(&img_xindownMask[i], L"爱心气球_mask.jpg");
		loadimage(&img_xindown[i], L"爱心气球.jpg");
	}

	//第八波摩压

	loadimage(&img_moyaMask, L"摩压_mask.bmp");
	loadimage(&img_moya, L"摩压.bmp");

	//气球爆炸

	for (i = 0; i < 8; i++)

	{
		loadimage(&img_blockMask[i], L"爆炸_mask.bmp");
		loadimage(&img_block[i], L"爆炸.bmp");
	}

	//爆炸图

	for (i = 0; i < 8; i++)

	{
		loadimage(&img_blockMask[i], L"爆炸_mask.bmp");
		loadimage(&img_block[i], L"爆炸.bmp");
	}

	loadimage(&img_blockMask1, L"爆炸_mask.bmp");
	loadimage(&img_block1, L"爆炸.bmp");

	//飞镖

	for (i = 0; i < 8; i++)

	{
		loadimage(&img_bart1Mask[i], L"普通猴武器_mask.bmp");
		loadimage(&img_bart1[i], L"普通猴武器.bmp");
	}
	for (i = 0; i < 8; i++)
	{
		loadimage(&img_bart2Mask[i], L"普通猴武器2_mask.bmp");
		loadimage(&img_bart2[i], L"普通猴武器2.bmp");
	}
	for (i = 0; i < 8; i++)
	{
		loadimage(&img_bart3Mask[i], L"普通猴武器3_mask.bmp");
		loadimage(&img_bart3[i], L"普通猴武器3.bmp");
	}
	for (i = 0; i < 8; i++)
	{
		loadimage(&img_bart4Mask[i], L"普通猴武器4_mask.bmp");
		loadimage(&img_bart4[i], L"普通猴武器4.bmp");
	}
	//BOSS
	loadimage(&img_bart11Mask, L"普通猴武器_mask.bmp");
	loadimage(&img_bart11, L"普通猴武器.bmp");
	loadimage(&img_bart22Mask, L"普通猴武器_mask.bmp");
	loadimage(&img_bart22, L"普通猴武器.bmp");
	loadimage(&img_bart33Mask, L"普通猴武器_mask.bmp");
	loadimage(&img_bart33, L"普通猴武器.bmp");
	loadimage(&img_bart44Mask, L"普通猴武器_mask.bmp");
	loadimage(&img_bart44, L"普通猴武器.bmp");
	loadimage(&img_huixuanMask, L"飞镖_mask.bmp");
	loadimage(&img_huixuan, L"飞镖.bmp");


	//边框
	loadimage(&img_bian, L"bian.jpg");


	//加载猴塔的图片和灰色图片*************************************

	loadimage(&img_houta11, L"普通猴1_mask.jpg");
	loadimage(&img_houta12, L"普通猴1.jpg");
	loadimage(&img_houta1red1, L"普通猴2_mask.jpg");
	loadimage(&img_houta1red2, L"普通猴2.jpg");


	loadimage(&img_houta21, L"针塔1_mask.jpg");
	loadimage(&img_houta22, L"针塔1.jpg");
	loadimage(&img_houta2red1, L"针塔2_mask.jpg");
	loadimage(&img_houta2red2, L"针塔2.jpg");


	loadimage(&img_houta31, L"狙击猴1_mask.jpg");
	loadimage(&img_houta32, L"狙击猴1.jpg");
	loadimage(&img_houta3red1, L"狙击猴2_mask.jpg");
	loadimage(&img_houta3red2, L"狙击猴2.jpg");


	loadimage(&img_houta41, L"飞镖猴1_mask.jpg");
	loadimage(&img_houta42, L"飞镖猴1.jpg");
	loadimage(&img_houta4red1, L"飞镖猴2_mask.jpg");
	loadimage(&img_houta4red2, L"飞镖猴2.jpg");


	loadimage(&img_houta51, L"忍者猴1_mask.jpg");
	loadimage(&img_houta52, L"忍者猴1.jpg");
	loadimage(&img_houta5red1, L"忍者猴2_mask.jpg");
	loadimage(&img_houta5red2, L"忍者猴2.jpg");


	loadimage(&img_houta61, L"冰猴1_mask.jpg");
	loadimage(&img_houta62, L"冰猴1.jpg");
	loadimage(&img_houta6red1, L"冰猴2_mask.jpg");
	loadimage(&img_houta6red2, L"冰猴2.jpg");

	loadimage(&img_houta71, L"炮塔1_mask.jpg");
	loadimage(&img_houta72, L"炮塔1.bmp");
	loadimage(&img_houta7red1, L"炮塔2_mask.jpg");
	loadimage(&img_houta7red2, L"炮塔2.jpg");

	loadimage(&img_houta81, L"超人猴1_mask.jpg");
	loadimage(&img_houta82, L"超人猴1.jpg");
	loadimage(&img_houta8red1, L"超人猴2_mask.jpg");
	loadimage(&img_houta8red2, L"超人猴2.jpg");


	//第一波气球坐标

	for (i = 0; i < 8; i++)

	{
		redup_x[i] = 0;
	}
	for (i = 0; i < 8; i++)
	{
		redup_y[i] = 255;
	}

	for (i = 0; i < 8; i++)
	{
		reddown_x[i] = 0;
	}
	for (i = 0; i < 8; i++)
	{
		reddown_y[i] = 280;
	}

	//第二波气球坐标

	for (i = 0; i < 8; i++)

	{
		redup2_x[i] = 0;
	}
	for (i = 0; i < 8; i++)
	{
		redup2_y[i] = 255;
	}

	for (i = 0; i < 8; i++)
	{
		reddown2_x[i] = 0;
	}
	for (i = 0; i < 8; i++)
	{
		reddown2_y[i] = 280;
	}

	//第三波气球坐标

	for (i = 0; i < 8; i++)

	{
		blueup_x[i] = 0;
	}
	for (i = 0; i < 8; i++)
	{
		blueup_y[i] = 255;
	}

	for (i = 0; i < 8; i++)
	{
		bluedown_x[i] = 0;
	}
	for (i = 0; i < 8; i++)
	{
		bluedown_y[i] = 280;
	}

	//第四波气球坐标

	for (i = 0; i < 8; i++)

	{
		greenup_x[i] = 0;
	}
	for (i = 0; i < 8; i++)
	{
		greenup_y[i] = 255;
	}

	for (i = 0; i < 8; i++)
	{
		greendown_x[i] = 0;
	}
	for (i = 0; i < 8; i++)
	{
		greendown_y[i] = 280;
	}

	//第五波气球坐标

	for (i = 0; i < 8; i++)

	{
		micaiup_x[i] = 0;
	}
	for (i = 0; i < 8; i++)
	{
		micaiup_y[i] = 255;
	}

	for (i = 0; i < 8; i++)
	{
		micaidown_x[i] = 0;
	}
	for (i = 0; i < 8; i++)
	{
		micaidown_y[i] = 280;
	}

	//第六波气球坐标

	for (i = 0; i < 8; i++)

	{
		gangup_x[i] = 0;
	}
	for (i = 0; i < 8; i++)
	{
		gangup_y[i] = 255;
	}

	for (i = 0; i < 8; i++)
	{
		gangdown_x[i] = 0;
	}
	for (i = 0; i < 8; i++)
	{
		gangdown_y[i] = 280;
	}

	//第七波气球坐标

	for (i = 0; i < 8; i++)

	{
		xinup_x[i] = 0;
	}
	for (i = 0; i < 8; i++)
	{
		xinup_y[i] = 255;
	}

	for (i = 0; i < 8; i++)
	{
		xindown_x[i] = 0;
	}
	for (i = 0; i < 8; i++)
	{
		xindown_y[i] = 280;
	}

	//摩压初始坐标
	moya_x = 0;
	moya_y = 180;
}

//输出图片*****************
void show()
{

	while (gamestart == 1)//显示菜单
	{
		
		menu();
	}
	while (gameover_control == 0)
	{
		die();
	}
	while (success_control == 0)
	{
		success();
	}

	BeginBatchDraw();//这个函数用于开始批量绘图。执行后，任何绘图操作都将暂时不输出到屏幕上，直到执行 FlushBatchDraw 或 EndBatchDraw 才将之前的绘图输出。
	int i;
	//--------------------------------战斗音乐---------------------------------------//
	mciSendString(L"close menumusic", NULL, 0, NULL);// 先把前面的音乐关闭  
	mciSendString(L"open 战斗音乐.mp3 alias bkmusic", NULL, 0, NULL);//打开背景音乐
	mciSendString(L"play bkmusic repeat", NULL, 0, NULL); // 循环播放

														  //-------------------------------------------显示动态箭头-------------------------------------//


	if (Begin != 0 && BeginChange == 1)
	{
		putimage(0, 0, &img_bk);	// 显示背景
		putimage(340, 240, &img_start11, SRCAND); //显示开始
		putimage(340, 240, &img_start12, SRCPAINT);
		putimage(800, 0, &img_bian);
		if (Begin % 2 == 1)
		{
			putimage(50, 245, &img_jt1, SRCAND);	// 显示箭头
			putimage(50, 245, &img_jt2, SRCPAINT);
			Begin++;
		}
		else if (Begin % 2 == 0)
		{
			putimage(45, 245, &img_jt1, SRCAND);	// 显示箭头
			putimage(45, 245, &img_jt2, SRCPAINT);
			Begin++;
		}
		Sleep(20);
	}
	//鼠标悬停在开始按钮上继续显示动态箭头
	else if (BeginChange == 0 && Begin != 0)

	{
		putimage(0, 0, &img_bk);	// 显示背景
		putimage(340, 240, &img_start21, SRCAND); //显示开始
		putimage(340, 240, &img_start22, SRCPAINT);
		putimage(800, 0, &img_bian);
		if (Begin % 2 == 1)
		{
			putimage(50, 245, &img_jt1, SRCAND);	// 显示箭头
			putimage(50, 245, &img_jt2, SRCPAINT);
			Begin++;
		}
		else if (Begin % 2 == 0)
		{
			putimage(45, 245, &img_jt1, SRCAND);	// 显示箭头
			putimage(45, 245, &img_jt2, SRCPAINT);
			Begin++;
		}
		Sleep(20);
		//---------------------------------------------显示动态箭头-------------------------------------//

	}



	else if (Begin == 0)

	{
		putimage(0, 0, &img_bk);	// 显示背景
		putimage(800, 0, &img_bian);	//放置边界框


										//输出金钱-----------------------------------------------------//

		LOGFONT f1;
		gettextstyle(&f1);                     // 获取当前字体设置
		f1.lfHeight = 20;                      // 设置字体高度为 48
		_tcscpy(f1.lfFaceName, _T("黑体"));    // 设置字体为“黑体”
		f1.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
		settextstyle(&f1);                     // 设置字体样式
		settextcolor(YELLOW);
		wchar_t s1[20];
		_stprintf(s1, L"   %d", money);
		outtextxy(800, 5, s1);
		setbkmode(TRANSPARENT);

		//输出生命---------------------------------------------------//

		LOGFONT f2;
		gettextstyle(&f2);                     // 获取当前字体设置
		f2.lfHeight = 20;                      // 设置字体高度为 48
		_tcscpy(f2.lfFaceName, _T("黑体"));    // 设置字体为“黑体”
		f2.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
		settextstyle(&f2);                     // 设置字体样式
		settextcolor(YELLOW);
		wchar_t s2[20];
		_stprintf(s2, L"   %d", life);
		outtextxy(800, 33, s2);
		setbkmode(TRANSPARENT);

		//显示上路第几波---------------------------------------------------//

		LOGFONT f3;
		gettextstyle(&f3);                     // 获取当前字体设置
		f3.lfHeight = 20;                      // 设置字体高度为 48
		_tcscpy(f3.lfFaceName, _T("黑体"));    // 设置字体为“黑体”
		f2.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
		settextstyle(&f3);                     // 设置字体样式
		settextcolor(YELLOW);
		wchar_t s3[20];
		_stprintf(s3, L"上路第%d波", count1);
		setcolor(RED);
		outtextxy(50, 30, s3);
		setbkmode(TRANSPARENT);

		//显示下路第几波---------------------------------------------------//

		LOGFONT f4;
		gettextstyle(&f4);                     // 获取当前字体设置
		f4.lfHeight = 20;                      // 设置字体高度为 48
		_tcscpy(f4.lfFaceName, _T("黑体"));    // 设置字体为“黑体”
		f4.lfQuality = ANTIALIASED_QUALITY;    // 设置输出效果为抗锯齿  
		settextstyle(&f4);                     // 设置字体样式
		settextcolor(YELLOW);
		wchar_t s4[20];
		_stprintf(s4, L"下路第%d波", count2);
		setcolor(RED);
		outtextxy(50, 530, s4);
		setbkmode(TRANSPARENT);

		//判断上路第几波
		if (redup_x[0] == 50)
		{
			count1++;
		}
		else if (redup2_x[0] == 50)
		{
			count1++;
		}
		else if (blueup_x[0] == 50)
		{
			count1++;
		}
		else if (greenup_x[0] == 50)
		{
			count1++;
		}
		else if (micaiup_x[0] == 50)
		{
			count1++;
		}
		else if (gangup_x[0] == 50)
		{
			count1++;
		}
		else if (xinup_x[0] == 50)
		{
			count1++;
		}
		else if (moya_x == 50)
		{
			count1++;
			count2++;
		}

		//判断下路第几波
		if (reddown_x[0] == 50)
		{
			count2++;
		}
		else if (reddown2_x[0] == 50)
		{
			count2++;
		}
		else if (bluedown_x[0] == 50)
		{
			count2++;
		}
		else if (greendown_x[0] == 50)
		{
			count2++;
		}
		else if (micaidown_x[0] == 50)
		{
			count2++;
		}
		else if (gangdown_x[0] == 50)
		{
			count2++;
		}
		else if (xindown_x[0] == 50)
		{
			count2++;
		}


		//输出回旋镖--------------------------------------------//
		if (Houta_4_IsPutdown == 0)
		{
			putimage(huixuan_x, huixuan_y, &img_huixuanMask, SRCAND);	//回旋镖
			putimage(huixuan_x, huixuan_y, &img_huixuan, SRCPAINT);
		}

		//输出气球图片-----------------------------------------//

		if (HP[0]>0)
		{
			putimage(redup_x[0], redup_y[0], &img_redupMask[0], SRCAND);	//显示第一波上气球
			putimage(redup_x[0], redup_y[0], &img_redup[0], SRCPAINT);
		}
		if (HPdown1[0]>0)
		{
			putimage(reddown_x[0], reddown_y[0], &img_reddownMask[0], SRCAND);	//显示第一波下气球
			putimage(reddown_x[0], reddown_y[0], &img_reddown[0], SRCPAINT);
		}

		for (i = 1; i < 8; i++)
		{
			if (HP[i] > 0)
			{
				if (redup_x[i - 1] >= 50)
				{
					putimage(redup_x[i], redup_y[i], &img_redupMask[i], SRCAND);	//显示第一波上气球
					putimage(redup_x[i], redup_y[i], &img_redup[i], SRCPAINT);
				}
			}
		}

		for (i = 1; i < 8; i++)
		{
			if (HPdown1[i] > 0)
			{
				if (reddown_x[i - 1] >= 50)
				{
					putimage(reddown_x[i], reddown_y[i], &img_reddownMask[i], SRCAND);	//显示第一波上气球
					putimage(reddown_x[i], reddown_y[i], &img_reddown[i], SRCPAINT);
				}
			}

		}

		if (HPup2[0]>0 && HP[7] <= 0)
		{
			putimage(redup2_x[0], redup2_y[0], &img_redup2Mask[0], SRCAND);	//显示第二波上气球
			putimage(redup2_x[0], redup2_y[0], &img_redup2[0], SRCPAINT);
		}

		if (HPdown2[0]>0 && HPdown1[7] <= 0)
		{
			putimage(reddown2_x[0], reddown2_y[0], &img_reddown2Mask[0], SRCAND);	//显示第二波下气球
			putimage(reddown2_x[0], reddown2_y[0], &img_reddown2[0], SRCPAINT);
		}

		for (i = 1; i < 8; i++)
		{
			if (HPup2[i] > 0 && HP[7] <= 0)
			{
				if (redup2_x[i - 1] >= 50)
				{
					putimage(redup2_x[i], redup2_y[i], &img_redup2Mask[i], SRCAND);	//显示第二波上气球
					putimage(redup2_x[i], redup2_y[i], &img_redup2[i], SRCPAINT);
				}
			}
		}
		for (i = 1; i < 8; i++)
		{
			if (HPdown2[i] > 0 && HPdown1[7] <= 0)
			{
				if (reddown2_x[i - 1] >= 50)
				{
					putimage(reddown2_x[i], reddown2_y[i], &img_reddown2Mask[i], SRCAND);	//显示第二波下气球
					putimage(reddown2_x[i], reddown2_y[i], &img_reddown2[i], SRCPAINT);
				}
			}

		}

		//显示第三波气球
		if (HPup3[0]>0 && HPup2[7] <= 0)

		{
			putimage(blueup_x[0], blueup_y[0], &img_blueupMask[0], SRCAND);	//显示第三波第一个上气球
			putimage(blueup_x[0], blueup_y[0], &img_blueup[0], SRCPAINT);
		}

		if (HPdown3[0]>0 && HPdown2[7] <= 0)
		{
			putimage(bluedown_x[0], bluedown_y[0], &img_bluedownMask[0], SRCAND);	//显示第三波第一个下气球
			putimage(bluedown_x[0], bluedown_y[0], &img_bluedown[0], SRCPAINT);
		}

		for (i = 1; i < 8; i++)
		{
			if (HPup3[i] > 0 && HPup2[7] <= 0)
			{
				if (blueup_x[i - 1] >= 50)
				{
					putimage(blueup_x[i], blueup_y[i], &img_blueupMask[i], SRCAND);	//显示第三波上气球
					putimage(blueup_x[i], blueup_y[i], &img_blueup[i], SRCPAINT);
				}
			}
		}
		for (i = 1; i < 8; i++)
		{
			if (HPdown3[i] > 0 && HPdown2[7] <= 0)
			{
				if (bluedown_x[i - 1] >= 50)
				{
					putimage(bluedown_x[i], bluedown_y[i], &img_bluedownMask[i], SRCAND);	//显示第三波下气球
					putimage(bluedown_x[i], bluedown_y[i], &img_bluedown[i], SRCPAINT);
				}
			}

		}
		//显示第四波气球
		if (HPup4[0]>0 && HPup3[7] <= 0)

		{
			putimage(greenup_x[0], greenup_y[0], &img_greenupMask[0], SRCAND);	//显示第四波第一个上气球
			putimage(greenup_x[0], greenup_y[0], &img_greenup[0], SRCPAINT);
		}

		if (HPdown4[0]>0 && HPdown3[7] <= 0)
		{
			putimage(greendown_x[0], greendown_y[0], &img_greendownMask[0], SRCAND);	//显示第四波第一个下气球
			putimage(greendown_x[0], greendown_y[0], &img_greendown[0], SRCPAINT);
		}

		for (i = 1; i < 8; i++)
		{
			if (HPup4[i] > 0 && HPup3[7] <= 0)
			{
				if (greenup_x[i - 1] >= 50)
				{
					putimage(greenup_x[i], greenup_y[i], &img_greenupMask[i], SRCAND);	//显示第四波上气球
					putimage(greenup_x[i], greenup_y[i], &img_greenup[i], SRCPAINT);
				}
			}
		}
		for (i = 1; i < 8; i++)
		{
			if (HPdown4[i] > 0 && HPdown3[7] <= 0)
			{
				if (greendown_x[i - 1] >= 50)
				{
					putimage(greendown_x[i], greendown_y[i], &img_greendownMask[i], SRCAND);	//显示第四波下气球
					putimage(greendown_x[i], greendown_y[i], &img_greendown[i], SRCPAINT);
				}
			}

		}

		//显示第五波气球

		if (HPup5[0]>0 && HPup4[7] <= 0)

		{
			putimage(micaiup_x[0], micaiup_y[0], &img_micaiupMask[0], SRCAND);	//显示第五波第一个上气球
			putimage(micaiup_x[0], micaiup_y[0], &img_micaiup[0], SRCPAINT);
		}

		if (HPdown5[0]>0 && HPdown4[7] <= 0)
		{
			putimage(micaidown_x[0], micaidown_y[0], &img_micaidownMask[0], SRCAND);	//显示第五波第一个下气球
			putimage(micaidown_x[0], micaidown_y[0], &img_micaidown[0], SRCPAINT);
		}

		for (i = 1; i < 8; i++)
		{
			if (HPup5[i] > 0 && HPup4[7] <= 0)
			{
				if (micaiup_x[i - 1] >= 50)
				{
					putimage(micaiup_x[i], micaiup_y[i], &img_micaiupMask[i], SRCAND);	//显示第五波上气球
					putimage(micaiup_x[i], micaiup_y[i], &img_micaiup[i], SRCPAINT);
				}
			}
		}
		for (i = 1; i < 8; i++)
		{
			if (HPdown5[i] > 0 && HPdown4[7] <= 0)
			{
				if (micaidown_x[i - 1] >= 50)
				{
					putimage(micaidown_x[i], micaidown_y[i], &img_micaidownMask[i], SRCAND);	//显示第五波下气球
					putimage(micaidown_x[i], micaidown_y[i], &img_micaidown[i], SRCPAINT);
				}
			}

		}

		//显示第六波气球
		if (HPup6[0]>0 && HPup5[7] <= 0)

		{
			putimage(gangup_x[0], gangup_y[0], &img_gangupMask[0], SRCAND);	//显示第六波第一个上气球
			putimage(gangup_x[0], gangup_y[0], &img_gangup[0], SRCPAINT);
		}

		if (HPdown6[0]>0 && HPdown5[7] <= 0)
		{
			putimage(gangdown_x[0], gangdown_y[0], &img_gangdownMask[0], SRCAND);	//显示第六波第一个下气球
			putimage(gangdown_x[0], gangdown_y[0], &img_gangdown[0], SRCPAINT);
		}

		for (i = 1; i < 8; i++)
		{
			if (HPup6[i] > 0 && HPup5[7] <= 0)
			{
				if (gangup_x[i - 1] >= 50)
				{
					putimage(gangup_x[i], gangup_y[i], &img_gangupMask[i], SRCAND);	//显示第六波上气球
					putimage(gangup_x[i], gangup_y[i], &img_gangup[i], SRCPAINT);
				}
			}
		}
		for (i = 1; i < 8; i++)
		{
			if (HPdown6[i] > 0 && HPdown5[7] <= 0)
			{
				if (gangdown_x[i - 1] >= 50)
				{
					putimage(gangdown_x[i], gangdown_y[i], &img_gangdownMask[i], SRCAND);	//显示第六波下气球
					putimage(gangdown_x[i], gangdown_y[i], &img_gangdown[i], SRCPAINT);
				}
			}

		}

		//显示第七波气球

		if (HPup7[0]>0 && HPup6[7] <= 0)

		{
			putimage(xinup_x[0], xinup_y[0], &img_xinupMask[0], SRCAND);	//显示第七波第一个上气球
			putimage(xinup_x[0], xinup_y[0], &img_xinup[0], SRCPAINT);
		}

		if (HPdown7[0]>0 && HPdown6[7] <= 0)
		{
			putimage(xindown_x[0], xindown_y[0], &img_xindownMask[0], SRCAND);	//显示第七波第一个下气球
			putimage(xindown_x[0], xindown_y[0], &img_xindown[0], SRCPAINT);
		}

		for (i = 1; i < 8; i++)
		{
			if (HPup7[i] > 0 && HPup6[7] <= 0)
			{
				if (xinup_x[i - 1] >= 50)
				{
					putimage(xinup_x[i], xinup_y[i], &img_xinupMask[i], SRCAND);	//显示第七波上气球
					putimage(xinup_x[i], xinup_y[i], &img_xinup[i], SRCPAINT);
				}
			}
		}
		for (i = 1; i < 8; i++)
		{
			if (HPdown7[i] > 0 && HPdown6[7] <= 0)
			{
				if (xindown_x[i - 1] >= 50)
				{
					putimage(xindown_x[i], xindown_y[i], &img_xindownMask[i], SRCAND);	//显示第七波下气球
					putimage(xindown_x[i], xindown_y[i], &img_xindown[i], SRCPAINT);
				}
			}

		}

		//显示BOSS

		if (HPup7[7] <= 0 && HPdown7[7] <= 0 && HP8 >0)
		{
			putimage(moya_x, moya_y, &img_moyaMask, SRCAND);	//显示BOSS
			putimage(moya_x, moya_y, &img_moya, SRCPAINT);
		}

		//第一波上方气球的爆炸--------------------------------//
		for (i = 0; i < 8; i++)

		{
			if (HP[i] == 0)
			{

				putimage(redup_x[i], redup_y[i], &img_blockMask[i], SRCAND);	//气球爆炸图
				putimage(redup_x[i], redup_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"气球爆炸.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);		//气球爆炸声
			}

			if ((HP[i] == 0 || HP[i] == 2 || HP[i] == 4) && (monkey1_x - redup_x[i])*(monkey1_x - redup_x[i]) + (monkey1_y - redup_y[i])*(monkey1_y - redup_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				//下面代码多次重复用于判断飞镖输出方向************************************

				if (redup_x[i] <= monkey1_x && redup_y[i] <= monkey1_y)

				{
					putimage((redup_x[i] + monkey1_x) / 2, (redup_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//飞镖图
					putimage((redup_x[i] + monkey1_x) / 2, (redup_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (redup_x[i] > monkey1_x && redup_y[i] <= monkey1_y)
				{
					putimage((redup_x[i] + monkey1_x) / 2, (redup_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//飞镖图
					putimage((redup_x[i] + monkey1_x) / 2, (redup_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (redup_x[i] <= monkey1_x && redup_y[i] > monkey1_y)
				{
					putimage((redup_x[i] + monkey1_x) / 2, (redup_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//飞镖图
					putimage((redup_x[i] + monkey1_x) / 2, (redup_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (redup_x[i] > monkey1_x && redup_y[i] > monkey1_y)
				{
					putimage((redup_x[i] + monkey1_x) / 2, (redup_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//飞镖图
					putimage((redup_x[i] + monkey1_x) / 2, (redup_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}

			}
			
		}
		//第一波下方气球的爆炸
		for (i = 0; i < 8; i++)

		{
			if (HPdown1[i] == 0)
			{

				putimage(reddown_x[i], reddown_y[i], &img_blockMask[i], SRCAND);	//气球爆炸图
				putimage(reddown_x[i], reddown_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"气球爆炸.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}
			if ((HP[i] == 0 || HP[i] == 2 || HP[i] == 4) && (monkey1_x - reddown_x[i])*(monkey1_x - reddown_x[i]) + (monkey1_y - reddown_y[i])*(monkey1_y - reddown_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (reddown_x[i] <= monkey1_x && reddown_y[i] <= monkey1_y)

				{
					putimage((reddown_x[i] + monkey1_x) / 2, (reddown_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//飞镖图
					putimage((reddown_x[i] + monkey1_x) / 2, (reddown_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (reddown_x[i] > monkey1_x && reddown_y[i] <= monkey1_y)
				{
					putimage((reddown_x[i] + monkey1_x) / 2, (reddown_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//飞镖图
					putimage((reddown_x[i] + monkey1_x) / 2, (reddown_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (reddown_x[i] < monkey1_x && reddown_y[i] >= monkey1_y)
				{
					putimage((reddown_x[i] + monkey1_x) / 2, (reddown_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//飞镖图
					putimage((reddown_x[i] + monkey1_x) / 2, (reddown_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (reddown_x[i] > monkey1_x && reddown_y[i] > monkey1_y)
				{
					putimage((reddown_x[i] + monkey1_x) / 2, (reddown_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//飞镖图
					putimage((reddown_x[i] + monkey1_x) / 2, (reddown_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}
			}
		}
		//第二波上方气球的爆炸
		for (i = 0; i < 8; i++)

		{
			if (HPup2[i] == 0)
			{

				putimage(redup2_x[i], redup2_y[i], &img_blockMask[i], SRCAND);	//气球爆炸图
				putimage(redup2_x[i], redup2_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"气球爆炸.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}

			if (HPup2[i] == 0 && (monkey1_x - redup2_x[i])*(monkey1_x - redup2_x[i]) + (monkey1_y - redup2_y[i])*(monkey1_y - redup2_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (redup2_x[i] <= monkey1_x && redup2_y[i] <= monkey1_y)

				{
					putimage((redup2_x[i] + monkey1_x) / 2, (redup2_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//飞镖图
					putimage((redup2_x[i] + monkey1_x) / 2, (redup2_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (redup2_x[i] > monkey1_x && redup2_y[i] <= monkey1_y)
				{
					putimage((redup2_x[i] + monkey1_x) / 2, (redup2_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//飞镖图
					putimage((redup2_x[i] + monkey1_x) / 2, (redup2_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (redup2_x[i] <= monkey1_x && redup2_y[i] > monkey1_y)
				{
					putimage((redup2_x[i] + monkey1_x) / 2, (redup2_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//飞镖图
					putimage((redup2_x[i] + monkey1_x) / 2, (redup2_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (redup2_x[i] > monkey1_x && redup2_y[i] > monkey1_y)
				{
					putimage((redup2_x[i] + monkey1_x) / 2, (redup2_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//飞镖图
					putimage((redup2_x[i] + monkey1_x) / 2, (redup2_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}
			}
		}
		//第二波下方气球的爆炸
		for (i = 0; i < 8; i++)

		{
			if (HPdown2[i] == 0)
			{

				putimage(reddown2_x[i], reddown2_y[i], &img_blockMask[i], SRCAND);	//气球爆炸图
				putimage(reddown2_x[i], reddown2_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"气球爆炸.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}
			if (HPdown2[i] == 0 && (monkey1_x - reddown2_x[i])*(monkey1_x - reddown2_x[i]) + (monkey1_y - reddown2_y[i])*(monkey1_y - reddown2_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (reddown2_x[i] <= monkey1_x && reddown2_y[i] <= monkey1_y)

				{
					putimage((reddown2_x[i] + monkey1_x) / 2, (reddown2_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//飞镖图
					putimage((reddown2_x[i] + monkey1_x) / 2, (reddown2_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (reddown2_x[i] > monkey1_x && reddown2_y[i] <= monkey1_y)
				{
					putimage((reddown2_x[i] + monkey1_x) / 2, (reddown2_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//飞镖图
					putimage((reddown2_x[i] + monkey1_x) / 2, (reddown2_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (reddown2_x[i] < monkey1_x && reddown2_y[i] > monkey1_y)
				{
					putimage((reddown2_x[i] + monkey1_x) / 2, (reddown2_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//飞镖图
					putimage((reddown2_x[i] + monkey1_x) / 2, (reddown2_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (reddown2_x[i] > monkey1_x && reddown2_y[i] > monkey1_y)
				{
					putimage((reddown2_x[i] + monkey1_x) / 2, (reddown2_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//飞镖图
					putimage((reddown2_x[i] + monkey1_x) / 2, (reddown2_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}

			}
		}

		//第三波上方气球的爆炸
		for (i = 0; i < 8; i++)

		{
			if (HPup3[i] == 0)
			{

				putimage(blueup_x[i], blueup_y[i], &img_blockMask[i], SRCAND);	//气球爆炸图
				putimage(blueup_x[i], blueup_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"气球爆炸.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}

			if (HPup3[i] == 0 && (monkey1_x - blueup_x[i])*(monkey1_x - blueup_x[i]) + (monkey1_y - blueup_y[i])*(monkey1_y - blueup_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (blueup_x[i] <= monkey1_x && blueup_y[i] <= monkey1_y)

				{
					putimage((blueup_x[i] + monkey1_x) / 2, (blueup_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//飞镖图
					putimage((blueup_x[i] + monkey1_x) / 2, (blueup_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (blueup_x[i] > monkey1_x && blueup_y[i] <= monkey1_y)
				{
					putimage((blueup_x[i] + monkey1_x) / 2, (blueup_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//飞镖图
					putimage((blueup_x[i] + monkey1_x) / 2, (blueup_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (blueup_x[i] < monkey1_x && blueup_y[i] > monkey1_y)
				{
					putimage((blueup_x[i] + monkey1_x) / 2, (blueup_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//飞镖图
					putimage((blueup_x[i] + monkey1_x) / 2, (blueup_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (blueup_x[i] > monkey1_x && blueup_y[i] > monkey1_y)
				{
					putimage((blueup_x[i] + monkey1_x) / 2, (blueup_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//飞镖图
					putimage((blueup_x[i] + monkey1_x) / 2, (blueup_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}

			}
		}
		//第三波下方气球的爆炸
		for (i = 0; i < 8; i++)

		{
			if (HPdown3[i] == 0)
			{

				putimage(bluedown_x[i], bluedown_y[i], &img_blockMask[i], SRCAND);	//气球爆炸图
				putimage(bluedown_x[i], bluedown_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"气球爆炸.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}
			if (HPdown3[i] == 0 && (monkey1_x - bluedown_x[i])*(monkey1_x - bluedown_x[i]) + (monkey1_y - bluedown_y[i])*(monkey1_y - bluedown_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (bluedown_x[i] <= monkey1_x && bluedown_y[i] <= monkey1_y)

				{
					putimage((bluedown_x[i] + monkey1_x) / 2, (bluedown_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//飞镖图
					putimage((bluedown_x[i] + monkey1_x) / 2, (bluedown_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (bluedown_x[i] > monkey1_x && bluedown_y[i] <= monkey1_y)
				{
					putimage((bluedown_x[i] + monkey1_x) / 2, (bluedown_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//飞镖图
					putimage((bluedown_x[i] + monkey1_x) / 2, (bluedown_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (bluedown_x[i] < monkey1_x && bluedown_y[i] > monkey1_y)
				{
					putimage((bluedown_x[i] + monkey1_x) / 2, (bluedown_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//飞镖图
					putimage((bluedown_x[i] + monkey1_x) / 2, (bluedown_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (bluedown_x[i] > monkey1_x && bluedown_y[i] > monkey1_y)
				{
					putimage((bluedown_x[i] + monkey1_x) / 2, (bluedown_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//飞镖图
					putimage((bluedown_x[i] + monkey1_x) / 2, (bluedown_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}

			}
		}

		//第四波上方气球的爆炸
		for (i = 0; i < 8; i++)

		{
			if (HPup4[i] == 0)
			{

				putimage(greenup_x[i], greenup_y[i], &img_blockMask[i], SRCAND);	//气球爆炸图
				putimage(greenup_x[i], greenup_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"气球爆炸.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}

			if (HPup4[i] == 0 && (monkey1_x - greenup_x[i])*(monkey1_x - greenup_x[i]) + (monkey1_y - greenup_y[i])*(monkey1_y - greenup_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (greenup_x[i] <= monkey1_x && greenup_y[i] <= monkey1_y)

				{
					putimage((greenup_x[i] + monkey1_x) / 2, (greenup_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//飞镖图
					putimage((greenup_x[i] + monkey1_x) / 2, (greenup_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (greenup_x[i] > monkey1_x && greenup_y[i] <= monkey1_y)
				{
					putimage((greenup_x[i] + monkey1_x) / 2, (greenup_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//飞镖图
					putimage((greenup_x[i] + monkey1_x) / 2, (greenup_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (greenup_x[i] < monkey1_x && greenup_y[i] > monkey1_y)
				{
					putimage((greenup_x[i] + monkey1_x) / 2, (greenup_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//飞镖图
					putimage((greenup_x[i] + monkey1_x) / 2, (greenup_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (greenup_x[i] > monkey1_x && greenup_y[i] > monkey1_y)
				{
					putimage((greenup_x[i] + monkey1_x) / 2, (greenup_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//飞镖图
					putimage((greenup_x[i] + monkey1_x) / 2, (greenup_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}

			}
		}
		//第四波下方气球的爆炸
		for (i = 0; i < 8; i++)

		{
			if (HPdown4[i] == 0)
			{

				putimage(greendown_x[i], greendown_y[i], &img_blockMask[i], SRCAND);	//气球爆炸图
				putimage(greendown_x[i], greendown_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"气球爆炸.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}
			if (HPdown4[i] == 0 && (monkey1_x - greendown_x[i])*(monkey1_x - greendown_x[i]) + (monkey1_y - greendown_y[i])*(monkey1_y - greendown_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (greendown_x[i] <= monkey1_x && greendown_y[i] <= monkey1_y)

				{
					putimage((greendown_x[i] + monkey1_x) / 2, (greendown_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//飞镖图
					putimage((greendown_x[i] + monkey1_x) / 2, (greendown_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (greendown_x[i] > monkey1_x && greendown_y[i] <= monkey1_y)
				{
					putimage((greendown_x[i] + monkey1_x) / 2, (greendown_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//飞镖图
					putimage((greendown_x[i] + monkey1_x) / 2, (greendown_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (greendown_x[i] < monkey1_x && greendown_y[i] > monkey1_y)
				{
					putimage((greendown_x[i] + monkey1_x) / 2, (greendown_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//飞镖图
					putimage((greendown_x[i] + monkey1_x) / 2, (greendown_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (greendown_x[i] > monkey1_x && greendown_y[i] > monkey1_y)
				{
					putimage((greendown_x[i] + monkey1_x) / 2, (greendown_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//飞镖图
					putimage((greendown_x[i] + monkey1_x) / 2, (greendown_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}


			}
		}

		//第五波上方气球的爆炸

		for (i = 0; i < 8; i++)

		{
			if (HPup5[i] == 0)
			{

				putimage(micaiup_x[i], micaiup_y[i], &img_blockMask[i], SRCAND);	//气球爆炸图
				putimage(micaiup_x[i], micaiup_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"气球爆炸.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}

			if (HPup5[i] == 0 && (monkey1_x - micaiup_x[i])*(monkey1_x - micaiup_x[i]) + (monkey1_y - micaiup_y[i])*(monkey1_y - micaiup_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (micaiup_x[i] <= monkey1_x && micaiup_y[i] <= monkey1_y)

				{
					putimage((micaiup_x[i] + monkey1_x) / 2, (micaiup_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//飞镖图
					putimage((micaiup_x[i] + monkey1_x) / 2, (micaiup_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (micaiup_x[i] > monkey1_x && micaiup_y[i] <= monkey1_y)
				{
					putimage((micaiup_x[i] + monkey1_x) / 2, (micaiup_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//飞镖图
					putimage((micaiup_x[i] + monkey1_x) / 2, (micaiup_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (micaiup_x[i] < monkey1_x && micaiup_y[i] > monkey1_y)
				{
					putimage((micaiup_x[i] + monkey1_x) / 2, (micaiup_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//飞镖图
					putimage((micaiup_x[i] + monkey1_x) / 2, (micaiup_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (micaiup_x[i] > monkey1_x && micaiup_y[i] > monkey1_y)
				{
					putimage((micaiup_x[i] + monkey1_x) / 2, (micaiup_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//飞镖图
					putimage((micaiup_x[i] + monkey1_x) / 2, (micaiup_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}

			}
		}
		//第五波下方气球的爆炸

		for (i = 0; i < 8; i++)

		{
			if (HPdown5[i] == 0)
			{

				putimage(micaidown_x[i], micaidown_y[i], &img_blockMask[i], SRCAND);	//气球爆炸图
				putimage(micaidown_x[i], micaidown_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"气球爆炸.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}
			if (HPdown5[i] == 0 && (monkey1_x - micaidown_x[i])*(monkey1_x - micaidown_x[i]) + (monkey1_y - micaidown_y[i])*(monkey1_y - micaidown_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (micaidown_x[i] <= monkey1_x && micaidown_y[i] <= monkey1_y)

				{
					putimage((micaidown_x[i] + monkey1_x) / 2, (micaidown_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//飞镖图
					putimage((micaidown_x[i] + monkey1_x) / 2, (micaidown_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (micaidown_x[i] > monkey1_x && micaidown_y[i] <= monkey1_y)
				{
					putimage((micaidown_x[i] + monkey1_x) / 2, (micaidown_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//飞镖图
					putimage((micaidown_x[i] + monkey1_x) / 2, (micaidown_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (micaidown_x[i] < monkey1_x && micaidown_y[i] > monkey1_y)
				{
					putimage((micaidown_x[i] + monkey1_x) / 2, (micaidown_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//飞镖图
					putimage((micaidown_x[i] + monkey1_x) / 2, (micaidown_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (micaidown_x[i] > monkey1_x && micaidown_y[i] > monkey1_y)
				{
					putimage((micaidown_x[i] + monkey1_x) / 2, (micaidown_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//飞镖图
					putimage((micaidown_x[i] + monkey1_x) / 2, (micaidown_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}


			}
		}

		//第六波上方气球的爆炸

		for (i = 0; i < 8; i++)

		{
			if (HPup6[i] == 0)
			{

				putimage(gangup_x[i], gangup_y[i], &img_blockMask[i], SRCAND);	//气球爆炸图
				putimage(gangup_x[i], gangup_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"气球爆炸.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}

			if (HPup6[i] == 0 && (monkey1_x - gangup_x[i])*(monkey1_x - gangup_x[i]) + (monkey1_y - gangup_y[i])*(monkey1_y - gangup_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (gangup_x[i] <= monkey1_x && gangup_y[i] <= monkey1_y)

				{
					putimage((gangup_x[i] + monkey1_x) / 2, (gangup_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//飞镖图
					putimage((gangup_x[i] + monkey1_x) / 2, (gangup_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (gangup_x[i] > monkey1_x && gangup_y[i] <= monkey1_y)
				{
					putimage((gangup_x[i] + monkey1_x) / 2, (gangup_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//飞镖图
					putimage((gangup_x[i] + monkey1_x) / 2, (gangup_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (gangup_x[i] < monkey1_x && gangup_y[i] > monkey1_y)
				{
					putimage((gangup_x[i] + monkey1_x) / 2, (gangup_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//飞镖图
					putimage((gangup_x[i] + monkey1_x) / 2, (gangup_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (gangup_x[i] > monkey1_x && gangup_y[i] > monkey1_y)
				{
					putimage((gangup_x[i] + monkey1_x) / 2, (gangup_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//飞镖图
					putimage((gangup_x[i] + monkey1_x) / 2, (gangup_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}

			}
		}

		//第六波下方气球的爆炸

		for (i = 0; i < 8; i++)

		{
			if (HPdown6[i] == 0)
			{

				putimage(gangdown_x[i], gangdown_y[i], &img_blockMask[i], SRCAND);	//气球爆炸图
				putimage(gangdown_x[i], gangdown_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"气球爆炸.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}
			if (HPdown6[i] == 0 && (monkey1_x - gangdown_x[i])*(monkey1_x - gangdown_x[i]) + (monkey1_y - gangdown_y[i])*(monkey1_y - gangdown_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (gangdown_x[i] <= monkey1_x && gangdown_y[i] <= monkey1_y)

				{
					putimage((gangdown_x[i] + monkey1_x) / 2, (gangdown_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//飞镖图
					putimage((gangdown_x[i] + monkey1_x) / 2, (gangdown_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (gangdown_x[i] > monkey1_x && gangdown_y[i] <= monkey1_y)
				{
					putimage((gangdown_x[i] + monkey1_x) / 2, (gangdown_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//飞镖图
					putimage((gangdown_x[i] + monkey1_x) / 2, (gangdown_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (gangdown_x[i] < monkey1_x && gangdown_y[i] > monkey1_y)
				{
					putimage((gangdown_x[i] + monkey1_x) / 2, (gangdown_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//飞镖图
					putimage((gangdown_x[i] + monkey1_x) / 2, (gangdown_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (gangdown_x[i] > monkey1_x && gangdown_y[i] > monkey1_y)
				{
					putimage((gangdown_x[i] + monkey1_x) / 2, (gangdown_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//飞镖图
					putimage((gangdown_x[i] + monkey1_x) / 2, (gangdown_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}

			}
		}
		//第七波上方气球的爆炸

		for (i = 0; i < 8; i++)

		{
			if (HPup7[i] == 0)
			{
				putimage(xinup_x[i], xinup_y[i], &img_blockMask[i], SRCAND);	//气球爆炸图
				putimage(xinup_x[i], xinup_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"气球爆炸.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}

			if (HPup7[i] == 0 && (monkey1_x - xinup_x[i])*(monkey1_x - xinup_x[i]) + (monkey1_y - xinup_y[i])*(monkey1_y - xinup_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (xinup_x[i] <= monkey1_x && xinup_y[i] <= monkey1_y)

				{
					putimage((xinup_x[i] + monkey1_x) / 2, (xinup_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//飞镖图
					putimage((xinup_x[i] + monkey1_x) / 2, (xinup_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (xinup_x[i] > monkey1_x && xinup_y[i] <= monkey1_y)
				{
					putimage((xinup_x[i] + monkey1_x) / 2, (xinup_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//飞镖图
					putimage((xinup_x[i] + monkey1_x) / 2, (xinup_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (xinup_x[i] < monkey1_x && xinup_y[i] > monkey1_y)
				{
					putimage((xinup_x[i] + monkey1_x) / 2, (xinup_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//飞镖图
					putimage((xinup_x[i] + monkey1_x) / 2, (xinup_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (xinup_x[i] > monkey1_x && xinup_y[i] > monkey1_y)
				{
					putimage((xinup_x[i] + monkey1_x) / 2, (xinup_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//飞镖图
					putimage((xinup_x[i] + monkey1_x) / 2, (xinup_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}

			}
		}
		//第七波下方气球的爆炸

		for (i = 0; i < 8; i++)

		{
			if (HPdown7[i] == 0)
			{
				putimage(xindown_x[i], xindown_y[i], &img_blockMask[i], SRCAND);	//气球爆炸图
				putimage(xindown_x[i], xindown_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"气球爆炸.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}
			if (HPdown7[i] == 0 && (monkey1_x - xindown_x[i])*(monkey1_x - xindown_x[i]) + (monkey1_y - xindown_y[i])*(monkey1_y - xindown_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (xindown_x[i] <= monkey1_x && xindown_y[i] <= monkey1_y)

				{
					putimage((xindown_x[i] + monkey1_x) / 2, (xindown_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//飞镖图
					putimage((xindown_x[i] + monkey1_x) / 2, (xindown_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (xindown_x[i] > monkey1_x && xindown_y[i] <= monkey1_y)
				{
					putimage((xindown_x[i] + monkey1_x) / 2, (xindown_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//飞镖图
					putimage((xindown_x[i] + monkey1_x) / 2, (xindown_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (xindown_x[i] < monkey1_x && xindown_y[i] > monkey1_y)
				{
					putimage((xindown_x[i] + monkey1_x) / 2, (xindown_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//飞镖图
					putimage((xindown_x[i] + monkey1_x) / 2, (xindown_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (xindown_x[i] > monkey1_x && xindown_y[i] > monkey1_y)
				{
					putimage((xindown_x[i] + monkey1_x) / 2, (xindown_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//飞镖图
					putimage((xindown_x[i] + monkey1_x) / 2, (xindown_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}
			}
		}

		//BOSS爆炸
		if (HP8 == 0 || HP8 == 50 || HP8 == 100 || HP8 == 150 || HP8 == 200 || HP8 == 250 || HP8 == 300 || HP8 == 350 || HP8 == 400 || HP8 == 450 || HP8 == 500)
		{
			putimage(moya_x + 10, moya_y + 20, &img_blockMask1, SRCAND);	//气球爆炸图
			putimage(moya_x + 10, moya_y + 20, &img_block1, SRCPAINT);
			PlaySound(L"气球爆炸.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);

		}
		if ((HP8 == 0 || HP8 == 50 || HP8 == 100 || HP8 == 150 || HP8 == 200 || HP8 == 250 || HP8 == 300 || HP8 == 350 || HP8 == 400 || HP8 == 450 || HP8 == 500) && (monkey1_x - moya_x)*(monkey1_x - moya_x) + (monkey1_y - moya_y)*(monkey1_y - moya_y) <= r1*r1&&Houta_1_IsPutdown == 0)
		{
			if (moya_x <= monkey1_x && moya_y <= monkey1_y)

			{
				putimage((moya_x + monkey1_x) / 2, (moya_y + monkey1_y) / 2, &img_bart11Mask, SRCAND);	//飞镖图
				putimage((moya_x + monkey1_x) / 2, (moya_y + monkey1_y) / 2, &img_bart11, SRCPAINT);
			}
			else if (moya_x > monkey1_x && moya_y <= monkey1_y)
			{
				putimage((moya_x + monkey1_x) / 2, (moya_y + monkey1_y) / 2, &img_bart22Mask, SRCAND);	//飞镖图
				putimage((moya_x + monkey1_x) / 2, (moya_y + monkey1_y) / 2, &img_bart22, SRCPAINT);
			}
			else if (moya_x < monkey1_x && moya_y > monkey1_y)
			{
				putimage((moya_x + monkey1_x) / 2, (moya_y + monkey1_y) / 2, &img_bart33Mask, SRCAND);	//飞镖图
				putimage((moya_x + monkey1_x) / 2, (moya_y + monkey1_y) / 2, &img_bart33, SRCPAINT);
			}
			else if (moya_x > monkey1_x && moya_y > monkey1_y)
			{
				putimage((moya_x + monkey1_x) / 2, (moya_y + monkey1_y) / 2, &img_bart44Mask, SRCAND);	//飞镖图
				putimage((moya_x + monkey1_x) / 2, (moya_y + monkey1_y) / 2, &img_bart44, SRCPAINT);
			}
		}
		//当金钱不够时输出黑色图****************************************
		//当金钱比第一个猴塔的所需金钱少时
		if (money<buildhouta1)
		{
			putimage(804, 95, &img_houta1red1, SRCAND);
			putimage(804, 95, &img_houta1red2, SRCPAINT);
		}
		//当金钱比第二个猴塔的所需金钱少时
		if (money < buildhouta2)
		{
			putimage(860, 93, &img_houta2red1, SRCAND);
			putimage(860, 93, &img_houta2red2, SRCPAINT);
		}
		//当金钱比第三个猴塔的所需金钱少时
		if (money<buildhouta3)
		{
			putimage(804, 140, &img_houta3red1, SRCAND);
			putimage(804, 140, &img_houta3red2, SRCPAINT);
		}
		//当金钱比第四个猴塔的所需金钱少时
		if (money<buildhouta4)

		{
			putimage(862, 148, &img_houta4red1, SRCAND);
			putimage(862, 148, &img_houta4red2, SRCPAINT);
		}
		//当金钱比第五个猴塔的所需金钱少时
		if (money<buildhouta5)

		{
			putimage(804, 200, &img_houta5red1, SRCAND);
			putimage(804, 200, &img_houta5red2, SRCPAINT);
		}
		//当金钱比第六个猴塔的所需金钱少时
		if (money<buildhouta6)

		{
			putimage(860, 204, &img_houta6red1, SRCAND);
			putimage(860, 204, &img_houta6red2, SRCPAINT);
		}
		//当金钱比第七个猴塔的所需金钱少时
		if (money<buildhouta7)

		{
			putimage(805, 255, &img_houta7red1, SRCAND);
			putimage(805, 255, &img_houta7red2, SRCPAINT);
		}
		//当金钱比第八个猴塔的所需金钱少时
		if (money<buildhouta8)

		{
			putimage(860, 255, &img_houta8red1, SRCAND);
			putimage(860, 255, &img_houta8red2, SRCPAINT);
		}

		//鼠标点击了第一个猴塔，输出猴塔随鼠标位置移动*********************

		if (Houta_1_IsChose == 0)
		{
			//只有当猴塔放在指定的位置时才会输出黑色攻击范围，否则输出红色攻击范围
			if ((monkey1_x >= 155 && monkey1_x <= 629 && monkey1_y >= 144 && monkey1_y <= 452))
			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(190, 190, 190));
				circle(monkey1_x, monkey1_y, r1);
				putimage(monkey1_x - 25, monkey1_y - 24, &img_houta11, SRCAND);
				putimage(monkey1_x - 25, monkey1_y - 24, &img_houta12, SRCPAINT);
			}
			//当塔处于不可放置区域时输出红色半径
			else
			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(255, 0, 0));		//红色 
				circle(monkey1_x, monkey1_y, r1);
				putimage(monkey1_x - 25, monkey1_y - 24, &img_houta11, SRCAND);
				putimage(monkey1_x - 25, monkey1_y - 24, &img_houta12, SRCPAINT);
			}
		}
		//点击右键放下第一个猴塔
		if (Houta_1_IsPutdown == 0)

		{
			putimage(monkey1_x - 25, monkey1_y - 24, &img_houta11, SRCAND);
			putimage(monkey1_x - 25, monkey1_y - 24, &img_houta12, SRCPAINT);

		}


		//鼠标点击了第二个猴塔，猴塔随鼠标位置移动******************

		if (Houta_2_IsChose == 0)

		{
			//同猴塔1
			if ((monkey2_x >= 155 && monkey2_x <= 629 && monkey2_y >= 144 && monkey2_y <= 452))
			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(190, 190, 190));
				circle(monkey2_x, monkey2_y, r2);
				putimage(monkey2_x - 25, monkey2_y - 24, &img_houta21, SRCAND);
				putimage(monkey2_x - 25, monkey2_y - 24, &img_houta22, SRCPAINT);
			}
			//当塔处于不可放置区域时
			else

			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(255, 0, 0));
				circle(monkey2_x, monkey2_y, r2);
				putimage(monkey2_x - 25, monkey2_y - 24, &img_houta21, SRCAND);
				putimage(monkey2_x - 25, monkey2_y - 24, &img_houta22, SRCPAINT);
			}
		}

		//点击右键放下第二个猴塔
		if (Houta_2_IsPutdown == 0)

		{
			putimage(monkey2_x - 25, monkey2_y - 24, &img_houta21, SRCAND);
			putimage(monkey2_x - 25, monkey2_y - 24, &img_houta22, SRCPAINT);
		}


		//点击第三个猴塔**************************
		if (Houta_3_IsChose == 0)

		{
			//同猴塔1
			if ((monkey3_x >= 155 && monkey3_x <= 629 && monkey3_y >= 144 && monkey3_y <= 452))
			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(190, 190, 190));
				circle(monkey3_x, monkey3_y, r3);
				putimage(monkey3_x - 25, monkey3_y - 24, &img_houta31, SRCAND);
				putimage(monkey3_x - 25, monkey3_y - 24, &img_houta32, SRCPAINT);
			}
			//当塔处于不可放置区域时
			else

			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(255, 0, 0));
				circle(monkey3_x, monkey3_y, r3);
				putimage(monkey3_x - 25, monkey3_y - 24, &img_houta31, SRCAND);
				putimage(monkey3_x - 25, monkey3_y - 24, &img_houta32, SRCPAINT);
			}
		}

		//点击右键放下第三个猴塔
		if (Houta_3_IsPutdown == 0)

		{
			putimage(monkey3_x - 25, monkey3_y - 24, &img_houta31, SRCAND);
			putimage(monkey3_x - 25, monkey3_y - 24, &img_houta32, SRCPAINT);
		}

		//点击第四个猴塔，猴塔随鼠标位置移动*******************
		if (Houta_4_IsChose == 0)
		{
			if ((monkey4_x >= 105 && monkey4_x <= 754 && monkey4_y >= 100 && monkey4_y <= 150) || (monkey4_x >= 105 && monkey4_x <= 750 && monkey4_y >= 483 && monkey4_y <= 532) || (monkey4_x >= 105 && monkey4_x <= 754 && monkey4_y >= 280 && monkey4_y <= 330))
			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(190, 190, 190));
				circle(monkey4_x, monkey4_y, r4);
				putimage(monkey4_x - 25, monkey4_y - 24, &img_houta41, SRCAND);
				putimage(monkey4_x - 25, monkey4_y - 24, &img_houta42, SRCPAINT);
			}

			//当塔处于不可放置区域时
			else
			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(255, 0, 0));
				circle(monkey4_x, monkey4_y, r4);
				putimage(monkey4_x - 25, monkey4_y - 24, &img_houta41, SRCAND);
				putimage(monkey4_x - 25, monkey4_y - 24, &img_houta42, SRCPAINT);
			}
		}
		//点击右键放下第四个猴塔
		if (Houta_4_IsPutdown == 0)
		{
			putimage(monkey4_x - 25, monkey4_y - 24, &img_houta41, SRCAND);
			putimage(monkey4_x - 25, monkey4_y - 24, &img_houta42, SRCPAINT);
		}

		//鼠标点击了第五个猴塔，猴塔随鼠标位置移动************************
		if (Houta_5_IsChose == 0)
		{
			if ((monkey5_x >= 155 && monkey5_x <= 629 && monkey5_y >= 144 && monkey5_y <= 452))
			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(190, 190, 190));
				circle(monkey5_x, monkey5_y, r5);
				putimage(monkey5_x - 25, monkey5_y - 24, &img_houta51, SRCAND);
				putimage(monkey5_x - 25, monkey5_y - 24, &img_houta52, SRCPAINT);
			}
			//当塔处于不可放置区域时
			else

			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(255, 0, 0));		//红色 
				circle(monkey5_x, monkey5_y, r1);
				putimage(monkey5_x - 25, monkey5_y - 24, &img_houta51, SRCAND);
				putimage(monkey5_x - 25, monkey5_y - 24, &img_houta52, SRCPAINT);
			}
		}
		//点击右键放下第五个猴塔
		if (Houta_5_IsPutdown == 0)

		{
			putimage(monkey5_x - 25, monkey5_y - 24, &img_houta51, SRCAND);
			putimage(monkey5_x - 25, monkey5_y - 24, &img_houta52, SRCPAINT);

		}


		//鼠标点击了第六猴塔，猴塔随鼠标位置移动************************
		if (Houta_6_IsChose == 0)
		{
			if ((monkey6_x >= 155 && monkey6_x <= 629 && monkey6_y >= 144 && monkey6_y <= 452))
			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(190, 190, 190));
				circle(monkey6_x, monkey6_y, r6);
				putimage(monkey6_x - 25, monkey6_y - 24, &img_houta61, SRCAND);
				putimage(monkey6_x - 25, monkey6_y - 24, &img_houta62, SRCPAINT);
			}
			//当塔处于不可放置区域时
			else

			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(255, 0, 0));		//红色 
				circle(monkey6_x, monkey6_y, r6);
				putimage(monkey6_x - 25, monkey6_y - 24, &img_houta61, SRCAND);
				putimage(monkey6_x - 25, monkey6_y - 24, &img_houta62, SRCPAINT);
			}
		}

		//点击右键放下第六猴塔
		if (Houta_6_IsPutdown == 0)

		{
			putimage(monkey6_x - 25, monkey6_y - 24, &img_houta61, SRCAND);
			putimage(monkey6_x - 25, monkey6_y - 24, &img_houta62, SRCPAINT);

		}

		//鼠标点击了第七猴塔，猴塔随鼠标位置移动************************
		if (Houta_7_IsChose == 0)
		{
			if ((monkey7_x >= 155 && monkey7_x <= 629 && monkey7_y >= 144 && monkey7_y <= 452))
			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(190, 190, 190));
				circle(monkey7_x, monkey7_y, r7);
				putimage(monkey7_x - 25, monkey7_y - 24, &img_houta71, SRCAND);
				putimage(monkey7_x - 25, monkey7_y - 24, &img_houta72, SRCPAINT);
			}
			//当塔处于不可放置区域时
			else

			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(255, 0, 0));		//红色 
				circle(monkey7_x, monkey7_y, r7);
				putimage(monkey7_x - 25, monkey7_y - 24, &img_houta71, SRCAND);
				putimage(monkey7_x - 25, monkey7_y - 24, &img_houta72, SRCPAINT);
			}
		}

		//点击右键放下第七个猴塔

		if (Houta_7_IsPutdown == 0)

		{
			putimage(monkey7_x - 25, monkey7_y - 24, &img_houta71, SRCAND);
			putimage(monkey7_x - 25, monkey7_y - 24, &img_houta72, SRCPAINT);

		}

		//鼠标点击了第八猴塔，猴塔随鼠标位置移动************************

		if (Houta_8_IsChose == 0)
		{
			if ((monkey8_x >= 155 && monkey8_x <= 629 && monkey8_y >= 144 && monkey8_y <= 452))
			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(190, 190, 190));
				circle(monkey8_x, monkey8_y, r8);
				putimage(monkey8_x - 25, monkey8_y - 24, &img_houta81, SRCAND);
				putimage(monkey8_x - 25, monkey8_y - 24, &img_houta82, SRCPAINT);
			}
			//当塔处于不可放置区域时
			else

			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(255, 0, 0));		//红色 
				circle(monkey8_x, monkey8_y, r8);
				putimage(monkey8_x - 25, monkey8_y - 24, &img_houta81, SRCAND);
				putimage(monkey8_x - 25, monkey8_y - 24, &img_houta82, SRCPAINT);
			}
		}
		//点击右键放下第八个猴塔

		if (Houta_8_IsPutdown == 0)

		{
			putimage(monkey8_x - 25, monkey8_y - 24, &img_houta81, SRCAND);
			putimage(monkey8_x - 25, monkey8_y - 24, &img_houta82, SRCPAINT);

		}

	}
	FlushBatchDraw();
	// 执行指定区域内未完成的绘制任务
}

//与输入无关*****************
void updateWithoutInput()
{
	//判定输出成功失败的函数*****************
	if (life == 0)
	{
		gameover_control = 0;
	}
	else if (HP8 <= 0 && HP8 != -1)
	{
		success_control = 0;
	}


	//当气球的生命值且总的生命值大于零时才进行气球的坐标运算************************

	else if (life > 0 && HPup4[7] != 0 || HPdown4[7] != 0)
	{
		//以下时各波气球的移动轨迹判定，共8波**********************
		int i;
		//第一波气球的移动
		if (Begin == 0 && HP[0]>0)

		{
			if (redup_x[0] <= 120 && redup_y[0] == 255)
				redup_x[0] = redup_x[0] + speed;
			if (redup_x[0] == 120 && redup_y[0] >= 70)
				redup_y[0] = redup_y[0] - speed;
			if (redup_y[0] == 70 && redup_x[0] <= 675)
				redup_x[0] = redup_x[0] + speed;
			if (redup_x[0] == 675 && redup_y[0] <= 255)
				redup_y[0] = redup_y[0] + speed;

		}
		for (i = 1; i < 8; i++)
		{
			if (redup_x[i - 1] >= 50 && HP[i]>0)
			{
				if (redup_x[i] <= 120 && redup_y[i] == 255)
					redup_x[i] = redup_x[i] + speed;
				if (redup_x[i] == 120 && redup_y[i] >= 70)
					redup_y[i] = redup_y[i] - speed;
				if (redup_y[i] == 70 && redup_x[i] <= 675)
					redup_x[i] = redup_x[i] + speed;
				if (redup_x[i] == 675 && redup_y[i] <= 255)
					redup_y[i] = redup_y[i] + speed;
			}
		}
		if (Begin == 0 && HPdown1[0]>0)
		{
			if (reddown_x[0] <= 120 && reddown_y[0] == 280)
				reddown_x[0] = reddown_x[0] + speed;
			if (reddown_x[0] == 120 && reddown_y[0] <= 465)
				reddown_y[0] = reddown_y[0] + speed;
			if (reddown_y[0] == 465 && reddown_x[0] <= 675)
				reddown_x[0] = reddown_x[0] + speed;
			if (reddown_x[0] == 675 && reddown_y[0] >= 280)
				reddown_y[0] = reddown_y[0] - speed;
		}
		for (i = 1; i < 8; i++)
		{
			if (reddown_x[i - 1] >= 50 && HPdown1[i]>0)
			{
				if (reddown_x[i] <= 120 && reddown_y[i] == 280)
					reddown_x[i] = reddown_x[i] + speed;
				if (reddown_x[i] == 120 && reddown_y[i] <= 465)
					reddown_y[i] = reddown_y[i] + speed;
				if (reddown_y[i] == 465 && reddown_x[i] <= 675)
					reddown_x[i] = reddown_x[i] + speed;
				if (reddown_x[i] == 675 && reddown_y[i] >= 280)
					reddown_y[i] = reddown_y[i] - speed;
			}
		}
		//第二波气球的移动
		if (HP[7] <= 0 && HPup2[0]>0)

		{
			if (redup2_x[0] <= 120 && redup2_y[0] == 255)
				redup2_x[0] = redup2_x[0] + speed;
			if (redup2_x[0] == 120 && redup2_y[0] >= 70)
				redup2_y[0] = redup2_y[0] - speed;
			if (redup2_y[0] == 70 && redup2_x[0] <= 675)
				redup2_x[0] = redup2_x[0] + speed;
			if (redup2_x[0] == 675 && redup2_y[0] <= 255)
				redup2_y[0] = redup2_y[0] + speed;

		}

		for (i = 1; i < 8; i++)
		{
			if (redup2_x[i - 1] >= 50 && HPup2[i]>0)
			{
				if (redup2_x[i] <= 120 && redup2_y[i] == 255)
					redup2_x[i] = redup2_x[i] + speed;
				if (redup2_x[i] == 120 && redup2_y[i] >= 70)
					redup2_y[i] = redup2_y[i] - speed;
				if (redup2_y[i] == 70 && redup2_x[i] <= 675)
					redup2_x[i] = redup2_x[i] + speed;
				if (redup2_x[i] == 675 && redup2_y[i] <= 255)
					redup2_y[i] = redup2_y[i] + speed;
			}
		}
		if (HPdown1[7] <= 0 && HPdown2[0]>0)
		{
			if (reddown2_x[0] <= 120 && reddown2_y[0] == 280)
				reddown2_x[0] = reddown2_x[0] + speed;
			if (reddown2_x[0] == 120 && reddown2_y[0] <= 465)
				reddown2_y[0] = reddown2_y[0] + speed;
			if (reddown2_y[0] == 465 && reddown2_x[0] <= 675)
				reddown2_x[0] = reddown2_x[0] + speed;
			if (reddown2_x[0] == 675 && reddown2_y[0] >= 280)
				reddown2_y[0] = reddown2_y[0] - speed;
		}
		for (i = 1; i < 8; i++)
		{
			if (reddown2_x[i - 1] >= 50 && HPdown2[i]>0)
			{
				if (reddown2_x[i] <= 120 && reddown2_y[i] == 280)
					reddown2_x[i] = reddown2_x[i] + speed;
				if (reddown2_x[i] == 120 && reddown2_y[i] <= 465)
					reddown2_y[i] = reddown2_y[i] + speed;
				if (reddown2_y[i] == 465 && reddown2_x[i] <= 675)
					reddown2_x[i] = reddown2_x[i] + speed;
				if (reddown2_x[i] == 675 && reddown2_y[i] >= 280)
					reddown2_y[i] = reddown2_y[i] - speed;
			}
		}
		//第三波气球的移动
		if (HPup2[7] <= 0 && HPup3[0]>0)

		{
			if (blueup_x[0] <= 120 && blueup_y[0] == 255)
				blueup_x[0] = blueup_x[0] + speed;
			if (blueup_x[0] == 120 && blueup_y[0] >= 70)
				blueup_y[0] = blueup_y[0] - speed;
			if (blueup_y[0] == 70 && blueup_x[0] <= 675)
				blueup_x[0] = blueup_x[0] + speed;
			if (blueup_x[0] == 675 && blueup_y[0] <= 255)
				blueup_y[0] = blueup_y[0] + speed;

		}
		for (i = 1; i < 8; i++)
		{
			if (blueup_x[i - 1] >= 50 && HPup3[i]>0)
			{
				if (blueup_x[i] <= 120 && blueup_y[i] == 255)
					blueup_x[i] = blueup_x[i] + speed;
				if (blueup_x[i] == 120 && blueup_y[i] >= 70)
					blueup_y[i] = blueup_y[i] - speed;
				if (blueup_y[i] == 70 && blueup_x[i] <= 675)
					blueup_x[i] = blueup_x[i] + speed;
				if (blueup_x[i] == 675 && blueup_y[i] <= 255)
					blueup_y[i] = blueup_y[i] + speed;
			}
		}
		if (HPdown2[7] <= 0 && HPdown3[0]>0)
		{
			if (bluedown_x[0] <= 120 && bluedown_y[0] == 280)
				bluedown_x[0] = bluedown_x[0] + speed;
			if (bluedown_x[0] == 120 && bluedown_y[0] <= 465)
				bluedown_y[0] = bluedown_y[0] + speed;
			if (bluedown_y[0] == 465 && bluedown_x[0] <= 675)
				bluedown_x[0] = bluedown_x[0] + speed;
			if (bluedown_x[0] == 675 && bluedown_y[0] >= 280)
				bluedown_y[0] = bluedown_y[0] - speed;
		}
		for (i = 1; i < 8; i++)
		{
			if (bluedown_x[i - 1] >= 50 && HPdown3[i]>0)
			{
				if (bluedown_x[i] <= 120 && bluedown_y[i] == 280)
					bluedown_x[i] = bluedown_x[i] + speed;
				if (bluedown_x[i] == 120 && bluedown_y[i] <= 465)
					bluedown_y[i] = bluedown_y[i] + speed;
				if (bluedown_y[i] == 465 && bluedown_x[i] <= 675)
					bluedown_x[i] = bluedown_x[i] + speed;
				if (bluedown_x[i] == 675 && bluedown_y[i] >= 280)
					bluedown_y[i] = bluedown_y[i] - speed;
			}
		}
		//第四波气球的移动
		if (HPup3[7] <= 0 && HPup4[0]>0)

		{
			if (greenup_x[0] <= 120 && greenup_y[0] == 255)
				greenup_x[0] = greenup_x[0] + speed;
			if (greenup_x[0] == 120 && greenup_y[0] >= 70)
				greenup_y[0] = greenup_y[0] - speed;
			if (greenup_y[0] == 70 && greenup_x[0] <= 675)
				greenup_x[0] = greenup_x[0] + speed;
			if (greenup_x[0] == 675 && greenup_y[0] <= 255)
				greenup_y[0] = greenup_y[0] + speed;

		}
		for (i = 1; i < 8; i++)
		{
			if (greenup_x[i - 1] >= 50 && HPup4[i]>0)
			{
				if (greenup_x[i] <= 120 && greenup_y[i] == 255)
					greenup_x[i] = greenup_x[i] + speed;
				if (greenup_x[i] == 120 && greenup_y[i] >= 70)
					greenup_y[i] = greenup_y[i] - speed;
				if (greenup_y[i] == 70 && greenup_x[i] <= 675)
					greenup_x[i] = greenup_x[i] + speed;
				if (greenup_x[i] == 675 && greenup_y[i] <= 255)
					greenup_y[i] = greenup_y[i] + speed;
			}
		}
		if (HPdown3[7] <= 0 && HPdown4[0]>0)
		{
			if (greendown_x[0] <= 120 && greendown_y[0] == 280)
				greendown_x[0] = greendown_x[0] + speed;
			if (greendown_x[0] == 120 && greendown_y[0] <= 465)
				greendown_y[0] = greendown_y[0] + speed;
			if (greendown_y[0] == 465 && greendown_x[0] <= 675)
				greendown_x[0] = greendown_x[0] + speed;
			if (greendown_x[0] == 675 && greendown_y[0] >= 280)
				greendown_y[0] = greendown_y[0] - speed;
		}
		for (i = 1; i < 8; i++)
		{
			if (greendown_x[i - 1] >= 50 && HPdown4[i]>0)
			{
				if (greendown_x[i] <= 120 && greendown_y[i] == 280)
					greendown_x[i] = greendown_x[i] + speed;
				if (greendown_x[i] == 120 && greendown_y[i] <= 465)
					greendown_y[i] = greendown_y[i] + speed;
				if (greendown_y[i] == 465 && greendown_x[i] <= 675)
					greendown_x[i] = greendown_x[i] + speed;
				if (greendown_x[i] == 675 && greendown_y[i] >= 280)
					greendown_y[i] = greendown_y[i] - speed;
			}
		}

		//第五波气球的移动
		if (HPup4[7] <= 0 && HPup5[0]>0)

		{
			if (micaiup_x[0] <= 120 && micaiup_y[0] == 255)
				micaiup_x[0] = micaiup_x[0] + speed;
			if (micaiup_x[0] == 120 && micaiup_y[0] >= 70)
				micaiup_y[0] = micaiup_y[0] - speed;
			if (micaiup_y[0] == 70 && micaiup_x[0] <= 675)
				micaiup_x[0] = micaiup_x[0] + speed;
			if (micaiup_x[0] == 675 && micaiup_y[0] <= 255)
				micaiup_y[0] = micaiup_y[0] + speed;

		}
		for (i = 1; i < 8; i++)
		{
			if (micaiup_x[i - 1] >= 50 && HPup5[i]>0)
			{
				if (micaiup_x[i] <= 120 && micaiup_y[i] == 255)
					micaiup_x[i] = micaiup_x[i] + speed;
				if (micaiup_x[i] == 120 && micaiup_y[i] >= 70)
					micaiup_y[i] = micaiup_y[i] - speed;
				if (micaiup_y[i] == 70 && micaiup_x[i] <= 675)
					micaiup_x[i] = micaiup_x[i] + speed;
				if (micaiup_x[i] == 675 && micaiup_y[i] <= 255)
					micaiup_y[i] = micaiup_y[i] + speed;
			}
		}
		if (HPdown4[7] <= 0 && HPdown5[0]>0)
		{
			if (micaidown_x[0] <= 120 && micaidown_y[0] == 280)
				micaidown_x[0] = micaidown_x[0] + speed;
			if (micaidown_x[0] == 120 && micaidown_y[0] <= 465)
				micaidown_y[0] = micaidown_y[0] + speed;
			if (micaidown_y[0] == 465 && micaidown_x[0] <= 675)
				micaidown_x[0] = micaidown_x[0] + speed;
			if (micaidown_x[0] == 675 && micaidown_y[0] >= 280)
				micaidown_y[0] = micaidown_y[0] - speed;
		}
		for (i = 1; i < 8; i++)
		{
			if (micaidown_x[i - 1] >= 50 && HPdown5[i]>0)
			{
				if (micaidown_x[i] <= 120 && micaidown_y[i] == 280)
					micaidown_x[i] = micaidown_x[i] + speed;
				if (micaidown_x[i] == 120 && micaidown_y[i] <= 465)
					micaidown_y[i] = micaidown_y[i] + speed;
				if (micaidown_y[i] == 465 && micaidown_x[i] <= 675)
					micaidown_x[i] = micaidown_x[i] + speed;
				if (micaidown_x[i] == 675 && micaidown_y[i] >= 280)
					micaidown_y[i] = micaidown_y[i] - speed;
			}
		}

		//第六波气球的移动
		if (HPup5[7] <= 0 && HPup6[0]>0)

		{
			if (gangup_x[0] <= 120 && gangup_y[0] == 255)
				gangup_x[0] = gangup_x[0] + speed;
			if (gangup_x[0] == 120 && gangup_y[0] >= 70)
				gangup_y[0] = gangup_y[0] - speed;
			if (gangup_y[0] == 70 && gangup_x[0] <= 675)
				gangup_x[0] = gangup_x[0] + speed;
			if (gangup_x[0] == 675 && gangup_y[0] <= 255)
				gangup_y[0] = gangup_y[0] + speed;

		}
		for (i = 1; i < 8; i++)
		{
			if (gangup_x[i - 1] >= 50 && HPup6[i]>0)
			{
				if (gangup_x[i] <= 120 && gangup_y[i] == 255)
					gangup_x[i] = gangup_x[i] + speed;
				if (gangup_x[i] == 120 && gangup_y[i] >= 70)
					gangup_y[i] = gangup_y[i] - speed;
				if (gangup_y[i] == 70 && gangup_x[i] <= 675)
					gangup_x[i] = gangup_x[i] + speed;
				if (gangup_x[i] == 675 && gangup_y[i] <= 255)
					gangup_y[i] = gangup_y[i] + speed;
			}
		}
		if (HPdown5[7] <= 0 && HPdown6[0]>0)
		{
			if (gangdown_x[0] <= 120 && gangdown_y[0] == 280)
				gangdown_x[0] = gangdown_x[0] + speed;
			if (gangdown_x[0] == 120 && gangdown_y[0] <= 465)
				gangdown_y[0] = gangdown_y[0] + speed;
			if (gangdown_y[0] == 465 && gangdown_x[0] <= 675)
				gangdown_x[0] = gangdown_x[0] + speed;
			if (gangdown_x[0] == 675 && gangdown_y[0] >= 280)
				gangdown_y[0] = gangdown_y[0] - speed;
		}
		for (i = 1; i < 8; i++)
		{
			if (gangdown_x[i - 1] >= 50 && HPdown6[i]>0)
			{
				if (gangdown_x[i] <= 120 && gangdown_y[i] == 280)
					gangdown_x[i] = gangdown_x[i] + speed;
				if (gangdown_x[i] == 120 && gangdown_y[i] <= 465)
					gangdown_y[i] = gangdown_y[i] + speed;
				if (gangdown_y[i] == 465 && gangdown_x[i] <= 675)
					gangdown_x[i] = gangdown_x[i] + speed;
				if (gangdown_x[i] == 675 && gangdown_y[i] >= 280)
					gangdown_y[i] = gangdown_y[i] - speed;
			}
		}

		//第七波气球的移动
		if (HPup6[7] <= 0 && HPup7[0]>0)

		{
			if (xinup_x[0] <= 120 && xinup_y[0] == 255)
				xinup_x[0] = xinup_x[0] + speed;
			if (xinup_x[0] == 120 && xinup_y[0] >= 70)
				xinup_y[0] = xinup_y[0] - speed;
			if (xinup_y[0] == 70 && xinup_x[0] <= 675)
				xinup_x[0] = xinup_x[0] + speed;
			if (xinup_x[0] == 675 && xinup_y[0] <= 255)
				xinup_y[0] = xinup_y[0] + speed;

		}
		for (i = 1; i < 8; i++)
		{
			if (xinup_x[i - 1] >= 50 && HPup7[i]>0)
			{
				if (xinup_x[i] <= 120 && xinup_y[i] == 255)
					xinup_x[i] = xinup_x[i] + speed;
				if (xinup_x[i] == 120 && xinup_y[i] >= 70)
					xinup_y[i] = xinup_y[i] - speed;
				if (xinup_y[i] == 70 && xinup_x[i] <= 675)
					xinup_x[i] = xinup_x[i] + speed;
				if (xinup_x[i] == 675 && xinup_y[i] <= 255)
					xinup_y[i] = xinup_y[i] + speed;
			}
		}
		if (HPdown6[7] <= 0 && HPdown7[0]>0)
		{
			if (xindown_x[0] <= 120 && xindown_y[0] == 280)
				xindown_x[0] = xindown_x[0] + speed;
			if (xindown_x[0] == 120 && xindown_y[0] <= 465)
				xindown_y[0] = xindown_y[0] + speed;
			if (xindown_y[0] == 465 && xindown_x[0] <= 675)
				xindown_x[0] = xindown_x[0] + speed;
			if (xindown_x[0] == 675 && xindown_y[0] >= 280)
				xindown_y[0] = xindown_y[0] - speed;
		}
		for (i = 1; i < 8; i++)
		{
			if (xindown_x[i - 1] >= 50 && HPdown7[i]>0)
			{
				if (xindown_x[i] <= 120 && xindown_y[i] == 280)
					xindown_x[i] = xindown_x[i] + speed;
				if (xindown_x[i] == 120 && xindown_y[i] <= 465)
					xindown_y[i] = xindown_y[i] + speed;
				if (xindown_y[i] == 465 && xindown_x[i] <= 675)
					xindown_x[i] = xindown_x[i] + speed;
				if (xindown_x[i] == 675 && xindown_y[i] >= 280)
					xindown_y[i] = xindown_y[i] - speed;
			}
		}

		//BOSS的单独移动路径
		if (HPup7[7] <= 0 && HPdown7[7] <= 0 && HP8>0)
		{
			moya_x = moya_x + speed2;
		}
		//i的重新赋值
		i = 0;
		while (i<8)
		{
			//判断生命**************************************************
			//生命值的减少
			//当气球到达终点线时，life--
			if (life != 0 && redup_x[i] <= 725 && redup_x[i] >= 675 && redup_y[i] == 240)

			{
				life--;
			}
			else if (life != 0 && redup2_x[i] <= 725 && redup2_x[i] >= 675 && redup2_y[i] == 240)
			{
				life--;
			}
			else if (life != 0 && blueup_x[i] <= 725 && blueup_x[i] >= 675 && blueup_y[i] == 240)
			{
				life--;
			}
			else if (life != 0 && greenup_x[i] <= 725 && greenup_x[i] >= 675 && greenup_y[i] == 240)
			{
				life--;
			}
			else if (life != 0 && micaiup_x[i] <= 725 && micaiup_x[i] >= 675 && micaiup_y[i] == 240)
			{
				life--;
			}
			else if (life != 0 && gangup_x[i] <= 725 && gangup_x[i] >= 675 && gangup_y[i] == 240)
			{
				life--;
			}
			else if (life != 0 && xinup_x[i] <= 725 && xinup_x[i] >= 675 && xinup_y[i] == 240)
			{
				life--;
			}
			else if (life != 0 && moya_x == 724 && moya_y == 195)
			{
				life = 0;
			}

			//下方气球到达终点
			else if (life != 0 && reddown_x[i] <= 725 && reddown_x[i] >= 675 && reddown_y[i] == 330)
			{
				life--;
			}
			else if (life != 0 && reddown2_x[i] <= 725 && reddown2_x[i] >= 675 && reddown2_y[i] == 330)
			{
				life--;
			}
			else if (life != 0 && bluedown_x[i] <= 725 && bluedown_x[i] >= 675 && bluedown_y[i] == 330)
			{
				life--;
			}
			else if (life != 0 && greendown_x[i] <= 725 && greendown_x[i] >= 675 && greendown_y[i] == 330)
			{
				life--;
			}
			else if (life != 0 && micaidown_x[i] <= 725 && micaidown_x[i] >= 675 && micaidown_y[i] == 330)
			{
				life--;
			}
			else if (life != 0 && gangdown_x[i] <= 725 && gangdown_x[i] >= 675 && gangdown_y[i] == 330)
			{
				life--;
			}
			else if (life != 0 && xindown_x[i] <= 725 && xindown_x[i] >= 675 && xindown_y[i] == 330)
			{
				life--;
			}


			//气球到达终点时，气球的生命值归-1，避免与其他逻辑判断冲突*********************************************
			//上方气球
			if (redup_x[i] <= 725 && redup_x[i] >= 675 && redup_y[i] == 255)

			{
				HP[i] = -1;
			}
			if (redup2_x[i] <= 725 && redup2_x[i] >= 675 && redup2_y[i] == 255)
			{
				HPup2[i] = -1;
			}
			if (blueup_x[i] <= 725 && blueup_x[i] >= 675 && blueup_y[i] == 255)
			{
				HPup3[i] = -1;
			}
			if (greenup_x[i] <= 725 && greenup_x[i] >= 675 && greenup_y[i] == 255)
			{
				HPup4[i] = -1;
			}
			if (micaiup_x[i] <= 725 && micaiup_x[i] >= 675 && micaiup_y[i] == 255)
			{
				HPup5[i] = -1;
			}
			if (gangup_x[i] <= 725 && gangup_x[i] >= 675 && gangup_y[i] == 255)
			{
				HPup6[i] = -1;
			}
			if (xinup_x[i] <= 725 && xinup_x[i] >= 675 && xinup_y[i] == 255)
			{
				HPup7[i] = -1;
			}
			//下方气球
			if (reddown_x[i] <= 725 && reddown_x[i] >= 675 && reddown_y[i] == 280)
			{
				HPdown1[i] = -1;
			}
			if (reddown2_x[i] <= 725 && reddown2_x[i] >= 675 && reddown2_y[i] == 280)
			{
				HPdown2[i] = -1;
			}
			if (bluedown_x[i] <= 725 && bluedown_x[i] >= 675 && bluedown_y[i] == 280)
			{
				HPdown3[i] = -1;
			}
			if (greendown_x[i] <= 725 && greendown_x[i] >= 675 && greendown_y[i] == 280)
			{
				HPdown4[i] = -1;
			}
			if (micaidown_x[i] <= 725 && micaidown_x[i] >= 675 && micaidown_y[i] == 280)
			{
				HPdown5[i] = -1;
			}
			if (gangdown_x[i] <= 725 && gangdown_x[i] >= 675 && gangdown_y[i] == 280)
			{
				HPdown6[i] = -1;
			}
			if (xindown_x[i] <= 725 && xindown_x[i] >= 675 && xindown_y[i] == 280)
			{
				HPdown7[i] = -1;
			}

			//BOSS
			if (moya_x == 724 && moya_y == 195)
			{
				HP8 = -1;
			}
			//气球到达终点时，气球的生命值归-1，避免与其他逻辑判断冲突*********************************************

			//击杀气球加钱******************************
			if (HP[i] == 0)
			{
				money += 5;
			}
			if (HPdown1[i] == 0)
			{
				money += 5;
			}
			if (HPup2[i] == 0)
			{
				money += 8;
			}
			if (HPdown2[i] == 0)
			{
				money += 8;
			}
			if (HPup3[i] == 0)
			{
				money += 12;
			}
			if (HPdown3[i] == 0)
			{
				money += 12;
			}
			if (HPup4[i] == 0)
			{
				money += 15;
			}
			if (HPdown4[i] == 0)
			{
				money += 15;
			}
			if (HPup5[i] == 0)
			{
				money += 8;
			}
			if (HPdown5[i] == 0)
			{
				money += 8;
			}
			if (HPup6[i] == 0)
			{
				money += 10;
			}
			if (HPdown6[i] == 0)
			{
				money += 18;
			}
			if (HPup7[i] == 0)
			{
				money += 22;
			}
			if (HPdown7[i] == 0)
			{
				money += 22;
			}
			//击杀气球加钱******************************

			//猴塔-1攻击气球的判定条件**************************************
			//当猴塔-1放下之后执行下列操作--------------------------------//
			if (Houta_1_IsPutdown == 0)

			{
				//攻击第一波气球**************
				//当一波的第一个气球进入攻击半径时
				if (i == 0 && (monkey1_x - redup_x[i])*(monkey1_x - redup_x[i]) + (monkey1_y - redup_y[i])*(monkey1_y - redup_y[i]) < r1*r1)
				{
					HP[i] = HP[i] - 1;
				}
				//后面的气球进入攻击半径时
				else if (i != 0 && (monkey1_x - redup_x[i])*(monkey1_x - redup_x[i]) + (monkey1_y - redup_y[i])*(monkey1_y - redup_y[i]) < r1*r1 && HP[i - 1] < 0)
				{
					HP[i] = HP[i] - 1;
				}
				//当前一个气球没死时，优先攻击离猴塔最远及里终点最近的气球*****************************************
				else if (i != 0 && (monkey1_x - redup_x[i])*(monkey1_x - redup_x[i]) + (monkey1_y - redup_y[i])*(monkey1_y - redup_y[i]) < r1*r1 && (monkey1_x - redup_x[i - 1])*(monkey1_x - redup_x[i - 1]) + (monkey1_y - redup_y[i - 1])*(monkey1_y - redup_y[i - 1]) > r1*r1)
				{
					HP[i]--;
				}
				//当有气球走出攻击半径且其生命刚好为0时，让其生命值减1，以此来避免气球爆炸图黏在背景图上的特殊情况 (没加之前时常发生这种情况)


				//下面依次是所有猴塔对所有气球的攻击判定（较长）----------------------------------------------------------------//

				else if (HP[i] == 0 && (monkey1_x - redup_x[i])*(monkey1_x - redup_x[i]) + (monkey1_y - redup_y[i])*(monkey1_y - redup_y[i]) > r1*r1)
				{
					HP[i] = HP[i] - 1;
				}
				else if (i == 0 && (monkey1_x - reddown_x[i])*(monkey1_x - reddown_x[i]) + (monkey1_y - reddown_y[i])*(monkey1_y - reddown_y[i]) < r1*r1)
				{
					HPdown1[i]--;
				}
				else if (i != 0 && (monkey1_x - reddown_x[i])*(monkey1_x - reddown_x[i]) + (monkey1_y - reddown_y[i])*(monkey1_y - reddown_y[i]) < r1*r1 && HPdown1[i - 1] < 0)
				{
					HPdown1[i]--;
				}
				else if (i != 0 && (monkey1_x - reddown_x[i])*(monkey1_x - reddown_x[i]) + (monkey1_y - reddown_y[i])*(monkey1_y - reddown_y[i]) < r1*r1 && (monkey1_x - reddown_x[i - 1])*(monkey1_x - reddown_x[i - 1]) + (monkey1_y - reddown_y[i - 1])*(monkey1_y - reddown_y[i - 1]) > r1*r1)
				{
					HPdown1[i]--;
				}
				else if (HPdown1[i] == 0 && (monkey1_x - reddown_x[i])*(monkey1_x - reddown_x[i]) + (monkey1_y - reddown_y[i])*(monkey1_y - reddown_y[i]) > r1*r1)
				{
					HPdown1[i] = HPdown1[i] - 1;
				}

				//攻击第二波气球**************

				if (i == 0 && (monkey1_x - redup2_x[i])*(monkey1_x - redup2_x[i]) + (monkey1_y - redup2_y[i])*(monkey1_y - redup2_y[i]) < r1*r1)

				{
					HPup2[i]--;
				}
				else if (i != 0 && (monkey1_x - redup2_x[i])*(monkey1_x - redup2_x[i]) + (monkey1_y - redup2_y[i])*(monkey1_y - redup2_y[i]) <r1*r1 && HPup2[i - 1] < 1)
				{
					HPup2[i]--;
				}
				else if (i != 0 && (monkey1_x - redup2_x[i])*(monkey1_x - redup2_x[i]) + (monkey1_y - redup2_y[i])*(monkey1_y - redup2_y[i]) < r1*r1 && (monkey1_x - redup2_x[i - 1])*(monkey1_x - redup2_x[i - 1]) + (monkey1_y - redup2_y[i - 1])*(monkey1_y - redup2_y[i - 1]) > r1*r1)
				{
					HPup2[i]--;
				}
				else if (HPup2[i] == 0 && (monkey1_x - redup2_x[i])*(monkey1_x - redup2_x[i]) + (monkey1_y - redup2_y[i])*(monkey1_y - redup2_y[i]) == r1*r1)
				{
					HPup2[i] = HPup2[i] - 1;
				}

				else if (i == 0 && (monkey1_x - reddown2_x[i])*(monkey1_x - reddown2_x[i]) + (monkey1_y - reddown2_y[i])*(monkey1_y - reddown2_y[i]) < r1*r1)
				{
					HPdown2[i]--;
				}
				else if (i != 0 && (monkey1_x - reddown2_x[i])*(monkey1_x - reddown2_x[i]) + (monkey1_y - reddown2_y[i])*(monkey1_y - reddown2_y[i]) < r1*r1 && HPdown2[i - 1] < 1)
				{
					HPdown2[i]--;
				}
				else if (i != 0 && (monkey1_x - reddown2_x[i])*(monkey1_x - reddown2_x[i]) + (monkey1_y - reddown2_y[i])*(monkey1_y - reddown2_y[i]) < r1*r1 && (monkey1_x - reddown2_x[i - 1])*(monkey1_x - reddown2_x[i - 1]) + (monkey1_y - reddown2_y[i - 1])*(monkey1_y - reddown2_y[i - 1]) > r1*r1)
				{
					HPdown2[i]--;
				}
				else if (HPdown2[i] == 0 && (monkey1_x - reddown2_x[i])*(monkey1_x - reddown2_x[i]) + (monkey1_y - reddown2_y[i])*(monkey1_y - reddown2_y[i]) == r1*r1)
				{
					HPdown2[i] = HPdown2[i] - 1;
				}

				//攻击第三波气球**************

				if (i == 0 && (monkey1_x - blueup_x[i])*(monkey1_x - blueup_x[i]) + (monkey1_y - blueup_y[i])*(monkey1_y - blueup_y[i]) < r1*r1)

				{
					HPup3[i]--;
				}
				else if (i != 0 && (monkey1_x - blueup_x[i])*(monkey1_x - blueup_x[i]) + (monkey1_y - blueup_y[i])*(monkey1_y - blueup_y[i]) < r1*r1 && HPup3[i - 1] < 1)
				{
					HPup3[i]--;
				}
				else if (i != 0 && (monkey1_x - blueup_x[i])*(monkey1_x - blueup_x[i]) + (monkey1_y - blueup_y[i])*(monkey1_y - blueup_y[i]) < r1*r1 && (monkey1_x - blueup_x[i - 1])*(monkey1_x - blueup_x[i - 1]) + (monkey1_y - blueup_y[i - 1])*(monkey1_y - blueup_y[i - 1]) > r1*r1)
				{
					HPup3[i]--;
				}
				else if (HPup3[i] == 0 && (monkey1_x - blueup_x[i])*(monkey1_x - blueup_x[i]) + (monkey1_y - blueup_y[i])*(monkey1_y - blueup_y[i]) == r1*r1)
				{
					HPup3[i] = HPup3[i] - 1;
				}

				else if (i == 0 && (monkey1_x - bluedown_x[i])*(monkey1_x - bluedown_x[i]) + (monkey1_y - bluedown_y[i])*(monkey1_y - bluedown_y[i]) < r1*r1)
				{
					HPdown3[i]--;
				}
				else if (i != 0 && (monkey1_x - bluedown_x[i])*(monkey1_x - bluedown_x[i]) + (monkey1_y - bluedown_y[i])*(monkey1_y - bluedown_y[i]) < r1*r1 && HPdown3[i - 1] < 1)
				{
					HPdown3[i]--;
				}
				else if (i != 0 && (monkey1_x - bluedown_x[i])*(monkey1_x - bluedown_x[i]) + (monkey1_y - bluedown_y[i])*(monkey1_y - bluedown_y[i]) < r1*r1 && (monkey1_x - bluedown_x[i - 1])*(monkey1_x - bluedown_x[i - 1]) + (monkey1_y - bluedown_y[i - 1])*(monkey1_y - bluedown_y[i - 1]) > r1*r1)
				{
					HPdown3[i]--;
				}
				else if (HPdown3[i] == 0 && (monkey1_x - bluedown_x[i])*(monkey1_x - bluedown_x[i]) + (monkey1_y - bluedown_y[i])*(monkey1_y - bluedown_y[i]) == r1*r1)
				{
					HPdown3[i] = HPdown3[i] - 1;
				}

				//攻击第四波气球**************

				if (i == 0 && (monkey1_x - greenup_x[i])*(monkey1_x - greenup_x[i]) + (monkey1_y - greenup_y[i])*(monkey1_y - greenup_y[i]) < r1*r1)

				{
					HPup4[i]--;
				}
				else if (i != 0 && (monkey1_x - greenup_x[i])*(monkey1_x - greenup_x[i]) + (monkey1_y - greenup_y[i])*(monkey1_y - greenup_y[i]) < r1*r1 && HPup3[i - 1] < 1)
				{
					HPup4[i]--;
				}
				else if (i != 0 && (monkey1_x - greenup_x[i])*(monkey1_x - greenup_x[i]) + (monkey1_y - greenup_y[i])*(monkey1_y - greenup_y[i]) < r1*r1 && (monkey1_x - greenup_x[i - 1])*(monkey1_x - greenup_x[i - 1]) + (monkey1_y - greenup_y[i - 1])*(monkey1_y - greenup_y[i - 1]) > r1*r1)
				{
					HPup4[i]--;
				}
				else if (HPup4[i] == 0 && (monkey1_x - greenup_x[i])*(monkey1_x - greenup_x[i]) + (monkey1_y - greenup_y[i])*(monkey1_y - greenup_y[i]) == r1*r1)
				{
					HPup4[i] = HPup4[i] - 1;
				}

				else if (i == 0 && (monkey1_x - greendown_x[i])*(monkey1_x - greendown_x[i]) + (monkey1_y - greendown_y[i])*(monkey1_y - greendown_y[i]) < r1*r1)
				{
					HPdown4[i]--;
				}
				else if (i != 0 && (monkey1_x - greendown_x[i])*(monkey1_x - greendown_x[i]) + (monkey1_y - greendown_y[i])*(monkey1_y - greendown_y[i]) < r1*r1 && HPdown3[i - 1] < 1)
				{
					HPdown4[i]--;
				}
				else if (i != 0 && (monkey1_x - greendown_x[i])*(monkey1_x - greendown_x[i]) + (monkey1_y - greendown_y[i])*(monkey1_y - greendown_y[i]) < r1*r1 && (monkey1_x - greendown_x[i - 1])*(monkey1_x - greendown_x[i - 1]) + (monkey1_y - greendown_y[i - 1])*(monkey1_y - greendown_y[i - 1]) > r1*r1)
				{
					HPdown4[i]--;
				}
				else if (HPdown4[i] == 0 && (monkey1_x - greendown_x[i])*(monkey1_x - greendown_x[i]) + (monkey1_y - greendown_y[i])*(monkey1_y - greendown_y[i]) == r1*r1)
				{
					HPdown4[i] = HPdown4[i] - 1;
				}

				//攻击第六波气球**************

				if (i == 0 && (monkey1_x - gangup_x[i])*(monkey1_x - gangup_x[i]) + (monkey1_y - gangup_y[i])*(monkey1_y - gangup_y[i]) < r1*r1)

				{
					HPup6[i]--;
				}
				else if (i != 0 && (monkey1_x - gangup_x[i])*(monkey1_x - gangup_x[i]) + (monkey1_y - gangup_y[i])*(monkey1_y - gangup_y[i]) < r1*r1 && HPup5[i - 1] < 1)
				{
					HPup6[i]--;
				}
				else if (i != 0 && (monkey1_x - gangup_x[i])*(monkey1_x - gangup_x[i]) + (monkey1_y - gangup_y[i])*(monkey1_y - gangup_y[i]) < r1*r1 && (monkey1_x - gangup_x[i - 1])*(monkey1_x - gangup_x[i - 1]) + (monkey1_y - gangup_y[i - 1])*(monkey1_y - gangup_y[i - 1]) > r1*r1)
				{
					HPup6[i]--;
				}
				else if (HPup4[i] == 0 && (monkey1_x - gangup_x[i])*(monkey1_x - gangup_x[i]) + (monkey1_y - gangup_y[i])*(monkey1_y - gangup_y[i]) == r1*r1)
				{
					HPup6[i] = HPup6[i] - 1;
				}

				else if (i == 0 && (monkey1_x - gangdown_x[i])*(monkey1_x - gangdown_x[i]) + (monkey1_y - gangdown_y[i])*(monkey1_y - gangdown_y[i]) < r1*r1)
				{
					HPdown6[i]--;
				}
				else if (i != 0 && (monkey1_x - gangdown_x[i])*(monkey1_x - gangdown_x[i]) + (monkey1_y - gangdown_y[i])*(monkey1_y - gangdown_y[i]) < r1*r1 && HPdown5[i - 1] < 1)
				{
					HPdown6[i]--;
				}
				else if (i != 0 && (monkey1_x - gangdown_x[i])*(monkey1_x - gangdown_x[i]) + (monkey1_y - gangdown_y[i])*(monkey1_y - gangdown_y[i]) < r1*r1 && (monkey1_x - gangdown_x[i - 1])*(monkey1_x - gangdown_x[i - 1]) + (monkey1_y - gangdown_y[i - 1])*(monkey1_y - gangdown_y[i - 1]) > r1*r1)
				{
					HPdown6[i]--;
				}
				else if (HPdown4[i] == 0 && (monkey1_x - gangdown_x[i])*(monkey1_x - gangdown_x[i]) + (monkey1_y - gangdown_y[i])*(monkey1_y - gangdown_y[i]) == r1*r1)
				{
					HPdown6[i] = HPdown6[i] - 1;
				}

				//攻击第七波气球**************

				if (i == 0 && (monkey1_x - xinup_x[i])*(monkey1_x - xinup_x[i]) + (monkey1_y - xinup_y[i])*(monkey1_y - xinup_y[i]) < r1*r1)

				{
					HPup7[i]--;
				}
				else if (i != 0 && (monkey1_x - xinup_x[i])*(monkey1_x - xinup_x[i]) + (monkey1_y - xinup_y[i])*(monkey1_y - xinup_y[i]) < r1*r1 && HPup6[i - 1] < 1)
				{
					HPup7[i]--;
				}
				else if (i != 0 && (monkey1_x - xinup_x[i])*(monkey1_x - xinup_x[i]) + (monkey1_y - xinup_y[i])*(monkey1_y - xinup_y[i]) < r1*r1 && (monkey1_x - xinup_x[i - 1])*(monkey1_x - xinup_x[i - 1]) + (monkey1_y - xinup_y[i - 1])*(monkey1_y - xinup_y[i - 1]) > r1*r1)
				{
					HPup7[i]--;
				}
				else if (HPup4[i] == 0 && (monkey1_x - xinup_x[i])*(monkey1_x - xinup_x[i]) + (monkey1_y - xinup_y[i])*(monkey1_y - xinup_y[i]) == r1*r1)
				{
					HPup7[i] = HPup7[i] - 1;
				}

				else if (i == 0 && (monkey1_x - xindown_x[i])*(monkey1_x - xindown_x[i]) + (monkey1_y - xindown_y[i])*(monkey1_y - xindown_y[i]) < r1*r1)
				{
					HPdown7[i]--;
				}
				else if (i != 0 && (monkey1_x - xindown_x[i])*(monkey1_x - xindown_x[i]) + (monkey1_y - xindown_y[i])*(monkey1_y - xindown_y[i]) < r1*r1 && HPdown6[i - 1] < 1)
				{
					HPdown7[i]--;
				}
				else if (i != 0 && (monkey1_x - xindown_x[i])*(monkey1_x - xindown_x[i]) + (monkey1_y - xindown_y[i])*(monkey1_y - xindown_y[i]) < r1*r1 && (monkey1_x - xindown_x[i - 1])*(monkey1_x - xindown_x[i - 1]) + (monkey1_y - xindown_y[i - 1])*(monkey1_y - xindown_y[i - 1]) > r1*r1)
				{
					HPdown7[i]--;
				}
				else if (HPdown4[i] == 0 && (monkey1_x - xindown_x[i])*(monkey1_x - xindown_x[i]) + (monkey1_y - xindown_y[i])*(monkey1_y - xindown_y[i]) == r1*r1)
				{
					HPdown7[i] = HPdown7[i] - 1;
				}

				//攻击BOSS
				if ((monkey1_x - moya_x)*(monkey1_x - moya_x) + (monkey1_y - moya_y)*(monkey1_y - moya_y) < r1*r1)
				{
					HP8 = HP8 - 1;
				}

			}

			//猴塔-2攻击气球的判定条件**************************************
			//猴塔-2是范围性攻击与猴塔-1略又不同-------------------------//

			//当猴塔-2被放下之后的操作
			if (Houta_2_IsPutdown == 0)
			{
				//攻击第一波气球
				if (i == 0 && (monkey2_x - redup_x[i])*(monkey2_x - redup_x[i]) + (monkey2_y - redup_y[i])*(monkey2_y - redup_y[i]) < r2*r2)

				{
					HP[i]--;
				}
				else if (i != 0 && (monkey2_x - redup_x[i])*(monkey2_x - redup_x[i]) + (monkey2_y - redup_y[i])*(monkey2_y - redup_y[i]) < r2*r2)
				{
					HP[i]--;
				}
				else if (HP[i] == 0 && (monkey2_x - redup_x[i])*(monkey2_x - redup_x[i]) + (monkey2_y - redup_y[i])*(monkey2_y - redup_y[i]) == r2*r2)
				{
					HP[i] = HP[i] - 1;
				}

				else if (i == 0 && (monkey2_x - reddown_x[i])*(monkey2_x - reddown_x[i]) + (monkey2_y - reddown_y[i])*(monkey2_y - reddown_y[i]) < r2*r2)
				{
					HPdown1[i]--;
				}
				else if (i != 0 && (monkey2_x - reddown_x[i])*(monkey2_x - reddown_x[i]) + (monkey2_y - reddown_y[i])*(monkey2_y - reddown_y[i]) < r2*r2)
				{
					HPdown1[i]--;
				}
				else if (HPdown1[i] == 0 && (monkey2_x - reddown_x[i])*(monkey2_x - reddown_x[i]) + (monkey2_y - reddown_y[i])*(monkey2_y - reddown_y[i]) == r2*r2)
				{
					HPdown1[i] = HPdown1[i] - 1;
				}

				//攻击第二波气球**************

				if (i == 0 && (monkey2_x - redup2_x[i])*(monkey2_x - redup2_x[i]) + (monkey2_y - redup2_y[i])*(monkey2_y - redup2_y[i]) < r2*r2)

				{
					HPup2[i]--;
				}
				else if (i != 0 && (monkey2_x - redup2_x[i])*(monkey2_x - redup2_x[i]) + (monkey2_y - redup2_y[i])*(monkey2_y - redup2_y[i]) <r2*r2)
				{
					HPup2[i]--;
				}
				else if (HPup2[i] == 0 && (monkey2_x - redup2_x[i])*(monkey2_x - redup2_x[i]) + (monkey2_y - redup2_y[i])*(monkey2_y - redup2_y[i]) == r2*r2)
				{
					HPup2[i] = HPup2[i] - 1;
				}

				else if (i == 0 && (monkey2_x - reddown2_x[i])*(monkey2_x - reddown2_x[i]) + (monkey2_y - reddown2_y[i])*(monkey2_y - reddown2_y[i]) < r2*r2)
				{
					HPdown2[i]--;
				}
				else if (i != 0 && (monkey2_x - reddown2_x[i])*(monkey2_x - reddown2_x[i]) + (monkey2_y - reddown2_y[i])*(monkey2_y - reddown2_y[i]) < r2*r2)
				{
					HPdown2[i]--;
				}
				else if (HPdown2[i] == 0 && (monkey2_x - reddown2_x[i])*(monkey2_x - reddown2_x[i]) + (monkey2_y - reddown2_y[i])*(monkey2_y - reddown2_y[i]) == r2*r2)
				{
					HPdown2[i] = HPdown2[i] - 1;
				}

				//攻击第三波气球**************

				if (i == 0 && (monkey2_x - blueup_x[i])*(monkey2_x - blueup_x[i]) + (monkey2_y - blueup_y[i])*(monkey2_y - blueup_y[i]) < r2*r2)

				{
					HPup3[i]--;
				}
				else if (i != 0 && (monkey2_x - blueup_x[i])*(monkey2_x - blueup_x[i]) + (monkey2_y - blueup_y[i])*(monkey2_y - blueup_y[i]) < r2*r2)
				{
					HPup3[i]--;
				}
				else if (HPup3[i] == 0 && (monkey2_x - blueup_x[i])*(monkey2_x - blueup_x[i]) + (monkey2_y - blueup_y[i])*(monkey2_y - blueup_y[i]) == r2*r2)
				{
					HPup3[i] = HPup3[i] - 1;
				}

				else if (i == 0 && (monkey2_x - bluedown_x[i])*(monkey2_x - bluedown_x[i]) + (monkey2_y - bluedown_y[i])*(monkey2_y - bluedown_y[i]) < r2*r2)
				{
					HPdown3[i]--;
				}
				else if (i != 0 && (monkey2_x - bluedown_x[i])*(monkey2_x - bluedown_x[i]) + (monkey2_y - bluedown_y[i])*(monkey2_y - bluedown_y[i]) < r2*r2)
				{
					HPdown3[i]--;
				}
				else if (HPdown3[i] == 0 && (monkey2_x - bluedown_x[i])*(monkey2_x - bluedown_x[i]) + (monkey2_y - bluedown_y[i])*(monkey2_y - bluedown_y[i]) == r2*r2)
				{
					HPdown3[i] = HPdown3[i] - 1;
				}

				//攻击第四波气球**************

				if (i == 0 && (monkey2_x - greenup_x[i])*(monkey2_x - greenup_x[i]) + (monkey2_y - greenup_y[i])*(monkey2_y - greenup_y[i]) < r2*r2)

				{
					HPup4[i]--;
				}
				else if (i != 0 && (monkey2_x - greenup_x[i])*(monkey2_x - greenup_x[i]) + (monkey2_y - greenup_y[i])*(monkey2_y - greenup_y[i]) < r2*r2)
				{
					HPup4[i]--;
				}
				else if (HPup4 == 0 && (monkey2_x - greenup_x[i])*(monkey2_x - greenup_x[i]) + (monkey2_y - greenup_y[i])*(monkey2_y - greenup_y[i]) == r2*r2)
				{
					HPup4[i] = HPup4[i] - 1;
				}

				else if (i == 0 && (monkey2_x - greendown_x[i])*(monkey2_x - greendown_x[i]) + (monkey2_y - greendown_y[i])*(monkey2_y - greendown_y[i]) < r2*r2)
				{
					HPdown4[i]--;
				}
				else if (i != 0 && (monkey2_x - greendown_x[i])*(monkey2_x - greendown_x[i]) + (monkey2_y - greendown_y[i])*(monkey2_y - greendown_y[i]) < r2*r2)
				{
					HPdown4[i]--;
				}
				else if (HPdown4[i] == 0 && (monkey2_x - greendown_x[i])*(monkey2_x - greendown_x[i]) + (monkey2_y - greendown_y[i])*(monkey2_y - greendown_y[i]) == r2*r2)
				{
					HPdown4[i] = HPdown4[i] - 1;
				}

				//攻击第六波气球**************


				if (i == 0 && (monkey2_x - gangup_x[i])*(monkey2_x - gangup_x[i]) + (monkey2_y - gangup_y[i])*(monkey2_y - gangup_y[i]) < r2*r2)

				{
					HPup6[i]--;
				}
				else if (i != 0 && (monkey2_x - gangup_x[i])*(monkey2_x - gangup_x[i]) + (monkey2_y - gangup_y[i])*(monkey2_y - gangup_y[i]) < r2*r2)
				{
					HPup6[i]--;
				}
				else if (HPup6 == 0 && (monkey2_x - gangup_x[i])*(monkey2_x - gangup_x[i]) + (monkey2_y - gangup_y[i])*(monkey2_y - gangup_y[i]) == r2*r2)
				{
					HPup6[i] = HPup6[i] - 1;
				}

				else if (i == 0 && (monkey2_x - gangdown_x[i])*(monkey2_x - gangdown_x[i]) + (monkey2_y - gangdown_y[i])*(monkey2_y - gangdown_y[i]) < r2*r2)
				{
					HPdown6[i]--;
				}
				else if (i != 0 && (monkey2_x - gangdown_x[i])*(monkey2_x - gangdown_x[i]) + (monkey2_y - gangdown_y[i])*(monkey2_y - gangdown_y[i]) < r2*r2)
				{
					HPdown6[i]--;
				}
				else if (HPdown6[i] == 0 && (monkey2_x - gangdown_x[i])*(monkey2_x - gangdown_x[i]) + (monkey2_y - gangdown_y[i])*(monkey2_y - gangdown_y[i]) == r2*r2)
				{
					HPdown6[i] = HPdown6[i] - 1;
				}


				//攻击第七波气球**************

				if (i == 0 && (monkey2_x - xinup_x[i])*(monkey2_x - xinup_x[i]) + (monkey2_y - xinup_y[i])*(monkey2_y - xinup_y[i]) < r2*r2)

				{
					HPup7[i]--;
				}
				else if (i != 0 && (monkey2_x - xinup_x[i])*(monkey2_x - xinup_x[i]) + (monkey2_y - xinup_y[i])*(monkey2_y - xinup_y[i]) < r2*r2)
				{
					HPup7[i]--;
				}
				else if (HPup7 == 0 && (monkey2_x - xinup_x[i])*(monkey2_x - xinup_x[i]) + (monkey2_y - xinup_y[i])*(monkey2_y - xinup_y[i]) == r2*r2)
				{
					HPup7[i] = HPup7[i] - 1;
				}

				else if (i == 0 && (monkey2_x - xindown_x[i])*(monkey2_x - xindown_x[i]) + (monkey2_y - xindown_y[i])*(monkey2_y - xindown_y[i]) < r2*r2)
				{
					HPdown7[i]--;
				}
				else if (i != 0 && (monkey2_x - xindown_x[i])*(monkey2_x - xindown_x[i]) + (monkey2_y - xindown_y[i])*(monkey2_y - xindown_y[i]) < r2*r2)
				{
					HPdown7[i]--;
				}
				else if (HPdown7[i] == 0 && (monkey2_x - xindown_x[i])*(monkey2_x - xindown_x[i]) + (monkey2_y - xindown_y[i])*(monkey2_y - xindown_y[i]) == r2*r2)
				{
					HPdown7[i] = HPdown7[i] - 1;
				}

				//攻击BOSS
				if ((monkey2_x - moya_x)*(monkey2_x - moya_x) + (monkey2_y - moya_y)*(monkey2_y - moya_y) < r2*r2)
				{
					HP8 = HP8 - 1;
				}

			}

			//猴塔-3攻击气球的判定条件**************************************

			//猴塔-3的攻击范围是全图，所以攻击判定论有不同，且猴塔-3优先攻击下路（不为什么）
			//当猴塔-3放下之后的任意操作

			if (Houta_3_IsPutdown == 0)
			{
				//攻击第一波下方气球

				if (i == 0)

				{
					HPdown1[i]--;
				}
				else if (i != 0 && HPdown1[i - 1] <= 0)
				{
					HPdown1[i]--;
				}

				//第一波上方
				if (i == 0 && HPdown1[7] <= 0)
				{
					HP[i]--;
				}
				else if (i != 0 && HP[i - 1] <= 0)
				{
					HP[i]--;
				}

				//第二波下方
				if (i == 0 && HP[7] <= 0 && HPdown1[7] <= 0)
				{
					HPdown2[i]--;
				}
				else if (i != 0 && HPdown2[i - 1] <= 0 && HPdown1[7] <= 0)
				{
					HPdown2[i]--;
				}

				//第二波上方
				if (i == 0 && HPdown2[7] <= 0 && HP[7] <= 0)
				{
					HPup2[i]--;
				}
				else if (i != 0 && HPup2[i - 1] <= 0 && HP[7] <= 0)
				{
					HPup2[i]--;
				}

				//第三波下方
				if (i == 0 && HPup2[7] <= 0 && HPdown2[7] <= 0)
				{
					HPdown3[i]--;
				}
				else if (i != 0 && HPdown3[i - 1] <= 0 && HPdown2[7] <= 0)
				{
					HPdown3[i]--;
				}

				//第三波上方
				if (i == 0 && HPdown3[7] <= 0 && HPup2[7] <= 0)
				{
					HPup3[i]--;
				}
				else if (i != 0 && HPup3[i - 1] <= 0 && HPup2[7] <= 0)
				{
					HPup3[i]--;
				}

				//第四波下方
				if (i == 0 && HPup3[7] <= 0 && HPdown3[7] <= 0)
				{
					HPdown4[i]--;
				}
				else if (i != 0 && HPdown4[i - 1] <= 0 && HPdown3[7] <= 0)
				{
					HPdown4[i]--;
				}

				//第四波上方
				if (i == 0 && HPdown4[7] <= 0 && HPup3[7] <= 0)
				{
					HPup4[i]--;
				}
				else if (i != 0 && HPup4[i - 1] <= 0 && HPup3[7] <= 0)
				{
					HPup4[i]--;
				}

				//第六波下方
				if (i == 0 && HPup5[7] <= 0 && HPdown5[7] <= 0)
				{
					HPdown6[i]--;
				}
				else if (i != 0 && HPdown6[i - 1] <= 0 && HPdown5[7] <= 0)
				{
					HPdown6[i]--;
				}

				//第六波上方
				if (i == 0 && HPdown6[7] <= 0 && HPup5[7] <= 0)
				{
					HPup6[i]--;
				}
				else if (i != 0 && HPup6[i - 1] <= 0 && HPup5[7] <= 0)
				{
					HPup6[i]--;
				}

				//第七波下方
				if (i == 0 && HPup6[7] <= 0 && HPdown6[7] <= 0)
				{
					HPdown7[i]--;
				}
				else if (i != 0 && HPdown7[i - 1] <= 0 && HPdown6[7] <= 0)
				{
					HPdown7[i]--;
				}

				//第七波上方
				if (i == 0 && HPdown7[7] <= 0 && HPup6[7] <= 0)
				{
					HPup7[i]--;
				}
				else if (i != 0 && HPup7[i - 1] <= 0 && HPup6[7] <= 0)
				{
					HPup7[i]--;
				}
			}

			//猴塔-4攻击气球的判定条件**************************************


			//猴塔-4会伴随输出回旋镖，其实就是小球的弹跳代码
			if (Houta_4_IsPutdown == 0)

			{
				huixuan_x += vx;
				if (huixuan_x == monkey4_x + 70 || huixuan_x == monkey4_x - 90)
				{
					vx = -vx;
				}

				//猴塔-4的攻击判定----------------------------------//
				//攻击第一波气球
				if (i == 0 && (monkey4_x - redup_x[i])*(monkey4_x - redup_x[i]) + (monkey4_y - redup_y[i])*(monkey4_y - redup_y[i]) < r4*r4)

				{
					HP[i]--;
				}
				else if (i != 0 && (monkey4_x - redup_x[i])*(monkey4_x - redup_x[i]) + (monkey4_y - redup_y[i])*(monkey4_y - redup_y[i]) < r4*r4)
				{
					HP[i]--;
				}
				else if (i != 0 && (monkey4_x - redup_x[i])*(monkey4_x - redup_x[i]) + (monkey4_y - redup_y[i])*(monkey4_y - redup_y[i]) < r4*r4 && (monkey4_x - redup_x[i - 1])*(monkey4_x - redup_x[i - 1]) + (monkey4_y - redup_y[i - 1])*(monkey4_y - redup_y[i - 1]) > r4*r4)
				{
					HP[i]--;
				}


				else if (i == 0 && (monkey4_x - reddown_x[i])*(monkey4_x - reddown_x[i]) + (monkey4_y - reddown_y[i])*(monkey4_y - reddown_y[i]) < r4*r4)
				{
					HPdown1[i]--;
				}
				else if (i != 0 && (monkey4_x - reddown_x[i])*(monkey4_x - reddown_x[i]) + (monkey4_y - reddown_y[i])*(monkey4_y - reddown_y[i]) < r4*r4 && HPdown1[i - 1]<1)
				{
					HPdown1[i]--;
				}
				else if (i != 0 && (monkey4_x - reddown_x[i])*(monkey4_x - reddown_x[i]) + (monkey4_y - reddown_y[i])*(monkey4_y - reddown_y[i]) < r4*r4 && (monkey4_x - reddown_x[i - 1])*(monkey4_x - reddown_x[i - 1]) + (monkey4_y - reddown_y[i - 1])*(monkey4_y - reddown_y[i - 1]) > r4*r4)
				{
					HPdown1[i]--;
				}

				//攻击第二波气球

				if (i == 0 && (monkey4_x - redup2_x[i])*(monkey4_x - redup2_x[i]) + (monkey4_y - redup2_y[i])*(monkey4_y - redup2_y[i]) < r4*r4)

				{
					HPup2[i]--;
				}
				else if (i != 0 && (monkey4_x - redup2_x[i])*(monkey4_x - redup2_x[i]) + (monkey4_y - redup2_y[i])*(monkey4_y - redup2_y[i]) < r4*r4 && HPup2[i - 1] < 1)
				{
					HPup2[i]--;
				}
				else if (i != 0 && (monkey4_x - redup2_x[i])*(monkey4_x - redup2_x[i]) + (monkey4_y - redup2_y[i])*(monkey4_y - redup2_y[i]) < r4*r4 && (monkey4_x - redup2_x[i - 1])*(monkey4_x - redup2_x[i - 1]) + (monkey4_y - redup2_y[i - 1])*(monkey4_y - redup2_y[i - 1]) > r4*r4)
				{
					HPup2[i]--;
				}

				else if (i == 0 && (monkey4_x - reddown2_x[i])*(monkey4_x - reddown2_x[i]) + (monkey4_y - reddown2_y[i])*(monkey4_y - reddown2_y[i]) < r4*r4)
				{
					HPdown2[i]--;
				}
				else if (i != 0 && (monkey4_x - reddown2_x[i])*(monkey4_x - reddown2_x[i]) + (monkey4_y - reddown2_y[i])*(monkey4_y - reddown2_y[i]) < r4*r4 && HPdown2[i - 1] < 1)
				{
					HPdown2[i]--;
				}
				else if (i != 0 && (monkey4_x - reddown2_x[i])*(monkey4_x - reddown2_x[i]) + (monkey4_y - reddown2_y[i])*(monkey4_y - reddown2_y[i]) < r4*r4 && (monkey4_x - reddown2_x[i - 1])*(monkey4_x - reddown2_x[i - 1]) + (monkey4_y - reddown2_y[i - 1])*(monkey4_y - reddown2_y[i - 1]) > r4*r4)
				{
					HPdown2[i]--;
				}
				//攻击第三波气球

				if (i == 0 && (monkey4_x - blueup_x[i])*(monkey4_x - blueup_x[i]) + (monkey4_y - blueup_y[i])*(monkey4_y - blueup_y[i]) < r4*r4)

				{
					HPup3[i]--;
				}
				else if (i != 0 && (monkey4_x - blueup_x[i])*(monkey4_x - blueup_x[i]) + (monkey4_y - blueup_y[i])*(monkey4_y - blueup_y[i]) < r4*r4 && HPup3[i - 1] < 1)
				{
					HPup3[i]--;
				}
				else if (i != 0 && (monkey4_x - blueup_x[i])*(monkey4_x - blueup_x[i]) + (monkey4_y - blueup_y[i])*(monkey4_y - blueup_y[i]) < r4*r4 && (monkey4_x - blueup_x[i - 1])*(monkey4_x - blueup_x[i - 1]) + (monkey4_y - blueup_y[i - 1])*(monkey4_y - blueup_y[i - 1]) > r4*r4)
				{
					HPup3[i]--;
				}

				else if (i == 0 && (monkey4_x - bluedown_x[i])*(monkey4_x - bluedown_x[i]) + (monkey4_y - bluedown_y[i])*(monkey4_y - bluedown_y[i]) < r4*r4)
				{
					HPdown3[i]--;
				}
				else if (i != 0 && (monkey4_x - bluedown_x[i])*(monkey4_x - bluedown_x[i]) + (monkey4_y - bluedown_y[i])*(monkey4_y - bluedown_y[i]) < r4*r4 && HPdown3[i - 1] < 1)
				{
					HPdown3[i]--;
				}
				else if (i != 0 && (monkey4_x - bluedown_x[i])*(monkey4_x - bluedown_x[i]) + (monkey4_y - bluedown_y[i])*(monkey4_y - bluedown_y[i]) < r4*r4 && (monkey4_x - bluedown_x[i - 1])*(monkey4_x - bluedown_x[i - 1]) + (monkey4_y - bluedown_y[i - 1])*(monkey4_y - bluedown_y[i - 1]) > r4*r4)
				{
					HPdown3[i]--;
				}

				//攻击第四波气球

				if (i == 0 && (monkey4_x - greenup_x[i])*(monkey4_x - greenup_x[i]) + (monkey4_y - greenup_y[i])*(monkey4_y - greenup_y[i]) < r4*r4)

				{
					HPup4[i]--;
				}
				else if (i != 0 && (monkey4_x - greenup_x[i])*(monkey4_x - greenup_x[i]) + (monkey4_y - greenup_y[i])*(monkey4_y - greenup_y[i]) < r4*r4 && HPup4[i - 1] < 1)
				{
					HPup4[i]--;
				}
				else if (i != 0 && (monkey4_x - greenup_x[i])*(monkey4_x - greenup_x[i]) + (monkey4_y - greenup_y[i])*(monkey4_y - greenup_y[i]) < r4*r4 && (monkey4_x - greenup_x[i - 1])*(monkey4_x - greenup_x[i - 1]) + (monkey4_y - greenup_y[i - 1])*(monkey4_y - greenup_y[i - 1]) > r4*r4)
				{
					HPup4[i]--;
				}

				else if (i == 0 && (monkey4_x - greendown_x[i])*(monkey4_x - greendown_x[i]) + (monkey4_y - greendown_y[i])*(monkey4_y - greendown_y[i]) < r4*r4)
				{
					HPdown4[i]--;
				}
				else if (i != 0 && (monkey4_x - greendown_x[i])*(monkey4_x - greendown_x[i]) + (monkey4_y - greendown_y[i])*(monkey4_y - greendown_y[i]) < r4*r4 && HPdown4[i - 1] < 1)
				{
					HPdown4[i]--;
				}
				else if (i != 0 && (monkey4_x - greendown_x[i])*(monkey4_x - greendown_x[i]) + (monkey4_y - greendown_y[i])*(monkey4_y - greendown_y[i]) < r4*r4 && (monkey4_x - greendown_x[i - 1])*(monkey4_x - greendown_x[i - 1]) + (monkey4_y - greendown_y[i - 1])*(monkey4_y - greendown_y[i - 1]) > r4*r4)
				{
					HPdown4[i]--;
				}

				//攻击第六波气球

				if (i == 0 && (monkey4_x - gangup_x[i])*(monkey4_x - gangup_x[i]) + (monkey4_y - gangup_y[i])*(monkey4_y - gangup_y[i]) < r4*r4)

				{
					HPup6[i]--;
				}
				else if (i != 0 && (monkey4_x - gangup_x[i])*(monkey4_x - gangup_x[i]) + (monkey4_y - gangup_y[i])*(monkey4_y - gangup_y[i]) < r4*r4 && HPup6[i - 1] < 1)
				{
					HPup6[i]--;
				}
				else if (i != 0 && (monkey4_x - gangup_x[i])*(monkey4_x - gangup_x[i]) + (monkey4_y - gangup_y[i])*(monkey4_y - gangup_y[i]) < r4*r4 && (monkey4_x - gangup_x[i - 1])*(monkey4_x - gangup_x[i - 1]) + (monkey4_y - gangup_y[i - 1])*(monkey4_y - gangup_y[i - 1]) > r4*r4)
				{
					HPup6[i]--;
				}

				else if (i == 0 && (monkey4_x - gangdown_x[i])*(monkey4_x - gangdown_x[i]) + (monkey4_y - gangdown_y[i])*(monkey4_y - gangdown_y[i]) < r4*r4)
				{
					HPdown6[i]--;
				}
				else if (i != 0 && (monkey4_x - gangdown_x[i])*(monkey4_x - gangdown_x[i]) + (monkey4_y - gangdown_y[i])*(monkey4_y - gangdown_y[i]) < r4*r4 && HPdown6[i - 1] < 1)
				{
					HPdown6[i]--;
				}
				else if (i != 0 && (monkey4_x - gangdown_x[i])*(monkey4_x - gangdown_x[i]) + (monkey4_y - gangdown_y[i])*(monkey4_y - gangdown_y[i]) < r4*r4 && (monkey4_x - gangdown_x[i - 1])*(monkey4_x - gangdown_x[i - 1]) + (monkey4_y - gangdown_y[i - 1])*(monkey4_y - gangdown_y[i - 1]) > r4*r4)
				{
					HPdown6[i]--;
				}

				//攻击第七波气球

				if (i == 0 && (monkey4_x - xinup_x[i])*(monkey4_x - xinup_x[i]) + (monkey4_y - xinup_y[i])*(monkey4_y - xinup_y[i]) < r4*r4)

				{
					HPup7[i]--;
				}
				else if (i != 0 && (monkey4_x - xinup_x[i])*(monkey4_x - xinup_x[i]) + (monkey4_y - xinup_y[i])*(monkey4_y - xinup_y[i]) < r4*r4 && HPup7[i - 1] < 1)
				{
					HPup7[i]--;
				}
				else if (i != 0 && (monkey4_x - xinup_x[i])*(monkey4_x - xinup_x[i]) + (monkey4_y - xinup_y[i])*(monkey4_y - xinup_y[i]) < r4*r4 && (monkey4_x - xinup_x[i - 1])*(monkey4_x - xinup_x[i - 1]) + (monkey4_y - xinup_y[i - 1])*(monkey4_y - xinup_y[i - 1]) > r4*r4)
				{
					HPup7[i]--;
				}

				else if (i == 0 && (monkey4_x - xindown_x[i])*(monkey4_x - xindown_x[i]) + (monkey4_y - xindown_y[i])*(monkey4_y - xindown_y[i]) < r4*r4)
				{
					HPdown7[i]--;
				}
				else if (i != 0 && (monkey4_x - xindown_x[i])*(monkey4_x - xindown_x[i]) + (monkey4_y - xindown_y[i])*(monkey4_y - xindown_y[i]) < r4*r4 && HPdown7[i - 1] < 1)
				{
					HPdown7[i]--;
				}
				else if (i != 0 && (monkey4_x - xindown_x[i])*(monkey4_x - xindown_x[i]) + (monkey4_y - xindown_y[i])*(monkey4_y - xindown_y[i]) < r4*r4 && (monkey4_x - xindown_x[i - 1])*(monkey4_x - xindown_x[i - 1]) + (monkey4_y - xindown_y[i - 1])*(monkey4_y - xindown_y[i - 1]) > r4*r4)
				{
					HPdown7[i]--;
				}

				//攻击BOSS
				if ((monkey4_x - moya_x)*(monkey4_x - moya_x) + (monkey4_y - moya_y)*(monkey4_y - moya_y) < r4*r4)
				{
					HP8 = HP8 - 1;
				}


			}

			//忍者的尊严-----------------------------------------------------------//
			//忍者猴只能攻击迷彩气球
			//当猴塔-5被放下之后的任意操作
			if (Houta_5_IsPutdown == 0)
			{
				//只攻击第五波迷彩气球**************

				if (i == 0 && (monkey5_x - micaiup_x[i])*(monkey5_x - micaiup_x[i]) + (monkey5_y - micaiup_y[i])*(monkey5_y - micaiup_y[i]) < r1*r1)

				{
					HPup5[i]--;
				}
				else if (i != 0 && (monkey5_x - micaiup_x[i])*(monkey5_x - micaiup_x[i]) + (monkey5_y - micaiup_y[i])*(monkey5_y - micaiup_y[i]) < r1*r1 && HPup4[i - 1] < 1)
				{
					HPup5[i]--;
				}
				else if (i != 0 && (monkey5_x - micaiup_x[i])*(monkey5_x - micaiup_x[i]) + (monkey5_y - micaiup_y[i])*(monkey5_y - micaiup_y[i]) < r1*r1 && (monkey5_x - micaiup_x[i - 1])*(monkey5_x - micaiup_x[i - 1]) + (monkey5_y - micaiup_y[i - 1])*(monkey5_y - micaiup_y[i - 1]) > r1*r1)
				{
					HPup5[i]--;
				}
				else if (HPup5[i] == 0 && (monkey5_x - micaiup_x[i])*(monkey5_x - micaiup_x[i]) + (monkey5_y - micaiup_y[i])*(monkey5_y - micaiup_y[i]) == r1*r1)
				{
					HPup5[i] = HPup5[i] - 1;
				}

				else if (i == 0 && (monkey5_x - micaidown_x[i])*(monkey5_x - micaidown_x[i]) + (monkey5_y - micaidown_y[i])*(monkey5_y - micaidown_y[i]) < r1*r1)
				{
					HPdown5[i]--;
				}
				else if (i != 0 && (monkey5_x - micaidown_x[i])*(monkey5_x - micaidown_x[i]) + (monkey5_y - micaidown_y[i])*(monkey5_y - micaidown_y[i]) < r1*r1 && HPdown4[i - 1] < 1)
				{
					HPdown5[i]--;
				}
				else if (i != 0 && (monkey5_x - micaidown_x[i])*(monkey5_x - micaidown_x[i]) + (monkey5_y - micaidown_y[i])*(monkey5_y - micaidown_y[i]) < r1*r1 && (monkey5_x - micaidown_x[i - 1])*(monkey5_x - micaidown_x[i - 1]) + (monkey5_y - micaidown_y[i - 1])*(monkey5_y - micaidown_y[i - 1]) > r1*r1)
				{
					HPdown5[i]--;
				}
				else if (HPdown5[i] == 0 && (monkey5_x - micaidown_x[i])*(monkey5_x - micaidown_x[i]) + (monkey5_y - micaidown_y[i])*(monkey5_y - micaidown_y[i]) == r1*r1)
				{
					HPdown5[i] = HPdown5[i] - 1;
				}
			}


			//炮塔攻击
			//和普通猴相似的攻击判定
			//当猴塔-7被放下之后的任意操作
			if (Houta_7_IsPutdown == 0)

			{
				//攻击第一波气球**************
				if (i == 0 && (monkey7_x - redup_x[i])*(monkey7_x - redup_x[i]) + (monkey7_y - redup_y[i])*(monkey7_y - redup_y[i]) < r7*r7)

				{
					HP[i] = HP[i] - 2;
				}
				else if (i != 0 && (monkey7_x - redup_x[i])*(monkey7_x - redup_x[i]) + (monkey7_y - redup_y[i])*(monkey7_y - redup_y[i]) < r7*r7 && HP[i - 1] < 0)
				{
					HP[i] = HP[i] - 2;
				}
				else if (i != 0 && (monkey7_x - redup_x[i])*(monkey7_x - redup_x[i]) + (monkey7_y - redup_y[i])*(monkey7_y - redup_y[i]) < r7*r7 && (monkey7_x - redup_x[i - 1])*(monkey7_x - redup_x[i - 1]) + (monkey7_y - redup_y[i - 1])*(monkey7_y - redup_y[i - 1]) > r7*r7)
				{
					HP[i]--;
				}
				else if (HP[i] == 0 && (monkey7_x - redup_x[i])*(monkey7_x - redup_x[i]) + (monkey7_y - redup_y[i])*(monkey7_y - redup_y[i]) > r7*r7)
				{
					HP[i] = HP[i] - 1;
				}

				else if (i == 0 && (monkey7_x - reddown_x[i])*(monkey7_x - reddown_x[i]) + (monkey7_y - reddown_y[i])*(monkey7_y - reddown_y[i]) < r7*r7)

				{
					HPdown1[i]--;
				}
				else if (i != 0 && (monkey7_x - reddown_x[i])*(monkey7_x - reddown_x[i]) + (monkey7_y - reddown_y[i])*(monkey7_y - reddown_y[i]) < r7*r7 && HPdown1[i - 1] < 0)
				{
					HPdown1[i]--;
				}
				else if (i != 0 && (monkey7_x - reddown_x[i])*(monkey7_x - reddown_x[i]) + (monkey7_y - reddown_y[i])*(monkey7_y - reddown_y[i]) < r7*r7 && (monkey7_x - reddown_x[i - 1])*(monkey7_x - reddown_x[i - 1]) + (monkey7_y - reddown_y[i - 1])*(monkey7_y - reddown_y[i - 1]) > r7*r7)
				{
					HPdown1[i]--;
				}
				else if (HPdown1[i] == 0 && (monkey7_x - reddown_x[i])*(monkey7_x - reddown_x[i]) + (monkey7_y - reddown_y[i])*(monkey7_y - reddown_y[i]) > r7*r7)
				{
					HPdown1[i] = HPdown1[i] - 1;
				}

				//攻击第二波气球**************

				if (i == 0 && (monkey7_x - redup2_x[i])*(monkey7_x - redup2_x[i]) + (monkey7_y - redup2_y[i])*(monkey7_y - redup2_y[i]) < r7*r7)

				{
					HPup2[i]--;
				}
				else if (i != 0 && (monkey7_x - redup2_x[i])*(monkey7_x - redup2_x[i]) + (monkey7_y - redup2_y[i])*(monkey7_y - redup2_y[i]) < r7*r7 && (monkey7_x - redup2_x[i - 1])*(monkey7_x - redup2_x[i - 1]) + (monkey7_y - redup2_y[i - 1])*(monkey7_y - redup2_y[i - 1]) > r7*r7)
				{
					HPup2[i]--;
				}
				else if (HPup2[i] == 0 && (monkey7_x - redup2_x[i])*(monkey7_x - redup2_x[i]) + (monkey7_y - redup2_y[i])*(monkey7_y - redup2_y[i]) == r7*r7)
				{
					HPup2[i] = HPup2[i] - 1;
				}

				else if (i == 0 && (monkey7_x - reddown2_x[i])*(monkey7_x - reddown2_x[i]) + (monkey7_y - reddown2_y[i])*(monkey7_y - reddown2_y[i]) < r7*r7)
				{
					HPdown2[i]--;
				}
				else if (i != 0 && (monkey7_x - reddown2_x[i])*(monkey7_x - reddown2_x[i]) + (monkey7_y - reddown2_y[i])*(monkey7_y - reddown2_y[i]) < r7*r7 && (monkey7_x - reddown2_x[i - 1])*(monkey7_x - reddown2_x[i - 1]) + (monkey7_y - reddown2_y[i - 1])*(monkey7_y - reddown2_y[i - 1]) > r7*r7)
				{
					HPdown2[i]--;
				}
				else if (HPdown2[i] == 0 && (monkey7_x - reddown2_x[i])*(monkey7_x - reddown2_x[i]) + (monkey7_y - reddown2_y[i])*(monkey7_y - reddown2_y[i]) == r7*r7)
				{
					HPdown2[i] = HPdown2[i] - 1;
				}

				//攻击第三波气球**************

				if (i == 0 && (monkey7_x - blueup_x[i])*(monkey7_x - blueup_x[i]) + (monkey7_y - blueup_y[i])*(monkey7_y - blueup_y[i]) < r7*r7)

				{
					HPup3[i]--;
				}
				else if (i != 0 && (monkey7_x - blueup_x[i])*(monkey7_x - blueup_x[i]) + (monkey7_y - blueup_y[i])*(monkey7_y - blueup_y[i]) < r7*r7 && (monkey7_x - blueup_x[i - 1])*(monkey7_x - blueup_x[i - 1]) + (monkey7_y - blueup_y[i - 1])*(monkey7_y - blueup_y[i - 1]) > r7*r7)
				{
					HPup3[i]--;
				}
				else if (HPup3[i] == 0 && (monkey7_x - blueup_x[i])*(monkey7_x - blueup_x[i]) + (monkey7_y - blueup_y[i])*(monkey7_y - blueup_y[i]) == r7*r7)
				{
					HPup3[i] = HPup3[i] - 1;
				}
				else if (i == 0 && (monkey7_x - bluedown_x[i])*(monkey7_x - bluedown_x[i]) + (monkey7_y - bluedown_y[i])*(monkey7_y - bluedown_y[i]) < r7*r7)
				{
					HPdown3[i]--;
				}
				else if (i != 0 && (monkey7_x - bluedown_x[i])*(monkey7_x - bluedown_x[i]) + (monkey7_y - bluedown_y[i])*(monkey7_y - bluedown_y[i]) < r7*r7 && (monkey7_x - bluedown_x[i - 1])*(monkey7_x - bluedown_x[i - 1]) + (monkey7_y - bluedown_y[i - 1])*(monkey7_y - bluedown_y[i - 1]) > r7*r7)
				{
					HPdown3[i]--;
				}
				else if (HPdown3[i] == 0 && (monkey7_x - bluedown_x[i])*(monkey7_x - bluedown_x[i]) + (monkey7_y - bluedown_y[i])*(monkey7_y - bluedown_y[i]) == r7*r7)
				{
					HPdown3[i] = HPdown3[i] - 1;
				}

				//攻击第四波气球**************

				if (i == 0 && (monkey7_x - greenup_x[i])*(monkey7_x - greenup_x[i]) + (monkey7_y - greenup_y[i])*(monkey7_y - greenup_y[i]) < r7*r7)

				{
					HPup4[i]--;
				}
				else if (i != 0 && (monkey7_x - greenup_x[i])*(monkey7_x - greenup_x[i]) + (monkey7_y - greenup_y[i])*(monkey7_y - greenup_y[i]) < r7*r7 && (monkey7_x - greenup_x[i - 1])*(monkey7_x - greenup_x[i - 1]) + (monkey7_y - greenup_y[i - 1])*(monkey7_y - greenup_y[i - 1]) > r7*r7)
				{
					HPup4[i]--;
				}
				else if (HPup4[i] && (monkey7_x - greenup_x[i])*(monkey7_x - greenup_x[i]) + (monkey7_y - greenup_y[i])*(monkey7_y - greenup_y[i]) == r7*r7)
				{
					HPup4[i] = HPup4[i] - 1;
				}

				else if (i == 0 && (monkey7_x - greendown_x[i])*(monkey7_x - greendown_x[i]) + (monkey7_y - greendown_y[i])*(monkey7_y - greendown_y[i]) < r7*r7)
				{
					HPdown4[i]--;
				}
				else if (i != 0 && (monkey7_x - greendown_x[i])*(monkey7_x - greendown_x[i]) + (monkey7_y - greendown_y[i])*(monkey7_y - greendown_y[i]) < r7*r7 && (monkey7_x - greendown_x[i - 1])*(monkey7_x - greendown_x[i - 1]) + (monkey7_y - greendown_y[i - 1])*(monkey7_y - greendown_y[i - 1]) > r7*r7)
				{
					HPdown4[i]--;
				}
				else if (HPdown4[i] == 0 && (monkey7_x - greendown_x[i])*(monkey7_x - greendown_x[i]) + (monkey7_y - greendown_y[i])*(monkey7_y - greendown_y[i]) == r7*r7)
				{
					HPdown4[i] = HPdown4[i] - 1;
				}

				//攻击第六波气球**************

				if (i == 0 && (monkey7_x - gangup_x[i])*(monkey7_x - gangup_x[i]) + (monkey7_y - gangup_y[i])*(monkey7_y - gangup_y[i]) < r7*r7)

				{
					HPup6[i]--;
				}
				else if (i != 0 && (monkey7_x - gangup_x[i])*(monkey7_x - gangup_x[i]) + (monkey7_y - gangup_y[i])*(monkey7_y - gangup_y[i]) < r7*r7 && (monkey7_x - gangup_x[i - 1])*(monkey7_x - gangup_x[i - 1]) + (monkey7_y - gangup_y[i - 1])*(monkey7_y - gangup_y[i - 1]) > r7*r7)
				{
					HPup6[i]--;
				}
				else if (HPup6[i] && (monkey7_x - gangup_x[i])*(monkey7_x - gangup_x[i]) + (monkey7_y - gangup_y[i])*(monkey7_y - gangup_y[i]) == r7*r7)
				{
					HPup6[i] = HPup6[i] - 1;
				}

				else if (i == 0 && (monkey7_x - gangdown_x[i])*(monkey7_x - gangdown_x[i]) + (monkey7_y - gangdown_y[i])*(monkey7_y - gangdown_y[i]) < r7*r7)
				{
					HPdown6[i]--;
				}
				else if (i != 0 && (monkey7_x - gangdown_x[i])*(monkey7_x - gangdown_x[i]) + (monkey7_y - gangdown_y[i])*(monkey7_y - gangdown_y[i]) < r7*r7 && (monkey7_x - gangdown_x[i - 1])*(monkey7_x - gangdown_x[i - 1]) + (monkey7_y - gangdown_y[i - 1])*(monkey7_y - gangdown_y[i - 1]) > r7*r7)
				{
					HPdown6[i]--;
				}
				else if (HPdown6[i] == 0 && (monkey7_x - gangdown_x[i])*(monkey7_x - gangdown_x[i]) + (monkey7_y - gangdown_y[i])*(monkey7_y - gangdown_y[i]) == r7*r7)
				{
					HPdown6[i] = HPdown6[i] - 1;
				}

				//攻击第七波气球**************

				if (i == 0 && (monkey7_x - xinup_x[i])*(monkey7_x - xinup_x[i]) + (monkey7_y - xinup_y[i])*(monkey7_y - xinup_y[i]) < r7*r7)

				{
					HPup7[i]--;
				}
				else if (i != 0 && (monkey7_x - xinup_x[i])*(monkey7_x - xinup_x[i]) + (monkey7_y - xinup_y[i])*(monkey7_y - xinup_y[i]) < r7*r7 && (monkey7_x - xinup_x[i - 1])*(monkey7_x - xinup_x[i - 1]) + (monkey7_y - xinup_y[i - 1])*(monkey7_y - xinup_y[i - 1]) > r7*r7)
				{
					HPup7[i]--;
				}
				else if (HPup7[i] && (monkey7_x - xinup_x[i])*(monkey7_x - xinup_x[i]) + (monkey7_y - xinup_y[i])*(monkey7_y - xinup_y[i]) == r7*r7)
				{
					HPup7[i] = HPup7[i] - 1;
				}

				else if (i == 0 && (monkey7_x - xindown_x[i])*(monkey7_x - xindown_x[i]) + (monkey7_y - xindown_y[i])*(monkey7_y - xindown_y[i]) < r7*r7)
				{
					HPdown7[i]--;
				}
				else if (i != 0 && (monkey7_x - xindown_x[i])*(monkey7_x - xindown_x[i]) + (monkey7_y - xindown_y[i])*(monkey7_y - xindown_y[i]) < r7*r7 && (monkey7_x - xindown_x[i - 1])*(monkey7_x - xindown_x[i - 1]) + (monkey7_y - xindown_y[i - 1])*(monkey7_y - xindown_y[i - 1]) > r7*r7)
				{
					HPdown7[i]--;
				}
				else if (HPdown7[i] == 0 && (monkey7_x - xindown_x[i])*(monkey7_x - xindown_x[i]) + (monkey7_y - xindown_y[i])*(monkey7_y - xindown_y[i]) == r7*r7)
				{
					HPdown7[i] = HPdown7[i] - 1;
				}

				//攻击BOSS
				if ((monkey7_x - moya_x)*(monkey7_x - moya_x) + (monkey7_y - moya_y)*(monkey7_y - moya_y) < r7*r7)
				{
					HP8 = HP8 - 1;
				}

			}

			//超级猴攻击
			//伤害是普通猴的两倍
			if (Houta_8_IsPutdown == 0)

			{
				//攻击第一波气球**************

				if (i == 0 && (monkey8_x - redup_x[i])*(monkey8_x - redup_x[i]) + (monkey8_y - redup_y[i])*(monkey8_y - redup_y[i]) < r8*r8)

				{
					HP[i] = HP[i] - 2;
				}
				else if (i != 0 && (monkey8_x - redup_x[i])*(monkey8_x - redup_x[i]) + (monkey8_y - redup_y[i])*(monkey8_y - redup_y[i]) < r8*r8 && HP[i - 1] < 0)
				{
					HP[i] = HP[i] - 2;
				}
				else if (i != 0 && (monkey8_x - redup_x[i])*(monkey8_x - redup_x[i]) + (monkey8_y - redup_y[i])*(monkey8_y - redup_y[i]) < r8*r8 && (monkey8_x - redup_x[i - 1])*(monkey8_x - redup_x[i - 1]) + (monkey8_y - redup_y[i - 1])*(monkey8_y - redup_y[i - 1]) > r8*r8)
				{
					HP[i] = HP[i] - 2;
				}
				else if (HP[i] == 0 && (monkey8_x - redup_x[i])*(monkey8_x - redup_x[i]) + (monkey8_y - redup_y[i])*(monkey8_y - redup_y[i]) > r8*r8)
				{
					HP[i] = HP[i] - 2;
				}

				else if (i == 0 && (monkey8_x - reddown_x[i])*(monkey8_x - reddown_x[i]) + (monkey8_y - reddown_y[i])*(monkey8_y - reddown_y[i]) < r8*r8)

				{
					HPdown1[i] -= 2;
				}
				else if (i != 0 && (monkey8_x - reddown_x[i])*(monkey8_x - reddown_x[i]) + (monkey8_y - reddown_y[i])*(monkey8_y - reddown_y[i]) < r8*r8 && HPdown1[i - 1] < 0)
				{
					HPdown1[i] -= 2;
				}
				else if (i != 0 && (monkey8_x - reddown_x[i])*(monkey8_x - reddown_x[i]) + (monkey8_y - reddown_y[i])*(monkey8_y - reddown_y[i]) < r8*r8 && (monkey8_x - reddown_x[i - 1])*(monkey8_x - reddown_x[i - 1]) + (monkey8_y - reddown_y[i - 1])*(monkey8_y - reddown_y[i - 1]) > r8*r8)
				{
					HPdown1[i] -= 2;
				}
				else if (HPdown1[i] == 0 && (monkey8_x - reddown_x[i])*(monkey8_x - reddown_x[i]) + (monkey8_y - reddown_y[i])*(monkey8_y - reddown_y[i]) > r8*r8)
				{
					HPdown1[i] = HPdown1[i] - 1;
				}

				//攻击第二波气球**************

				if (i == 0 && (monkey8_x - redup2_x[i])*(monkey8_x - redup2_x[i]) + (monkey8_y - redup2_y[i])*(monkey8_y - redup2_y[i]) < r8*r8)

				{
					HPup2[i] -= 2;
				}
				else if (i != 0 && (monkey8_x - redup2_x[i])*(monkey8_x - redup2_x[i]) + (monkey8_y - redup2_y[i])*(monkey8_y - redup2_y[i]) <r8*r8 && HPup2[i - 1] < 1)
				{
					HPup2[i] -= 2;
				}
				else if (i != 0 && (monkey8_x - redup2_x[i])*(monkey8_x - redup2_x[i]) + (monkey8_y - redup2_y[i])*(monkey8_y - redup2_y[i]) < r8*r8 && (monkey8_x - redup2_x[i - 1])*(monkey8_x - redup2_x[i - 1]) + (monkey8_y - redup2_y[i - 1])*(monkey8_y - redup2_y[i - 1]) > r8*r8)
				{
					HPup2[i] -= 2;
				}
				else if (HPup2[i] == 0 && (monkey8_x - redup2_x[i])*(monkey8_x - redup2_x[i]) + (monkey8_y - redup2_y[i])*(monkey8_y - redup2_y[i]) == r8*r8)
				{
					HPup2[i] = HPup2[i] - 1;
				}

				else if (i == 0 && (monkey8_x - reddown2_x[i])*(monkey8_x - reddown2_x[i]) + (monkey8_y - reddown2_y[i])*(monkey8_y - reddown2_y[i]) < r8*r8)
				{
					HPdown2[i] -= 2;
				}
				else if (i != 0 && (monkey8_x - reddown2_x[i])*(monkey8_x - reddown2_x[i]) + (monkey8_y - reddown2_y[i])*(monkey8_y - reddown2_y[i]) < r8*r8 && HPdown2[i - 1] < 1)
				{
					HPdown2[i] -= 2;
				}
				else if (i != 0 && (monkey8_x - reddown2_x[i])*(monkey8_x - reddown2_x[i]) + (monkey8_y - reddown2_y[i])*(monkey8_y - reddown2_y[i]) < r8*r8 && (monkey8_x - reddown2_x[i - 1])*(monkey8_x - reddown2_x[i - 1]) + (monkey8_y - reddown2_y[i - 1])*(monkey8_y - reddown2_y[i - 1]) > r8*r8)
				{
					HPdown2[i] -= 2;
				}
				else if (HPdown2[i] == 0 && (monkey8_x - reddown2_x[i])*(monkey8_x - reddown2_x[i]) + (monkey8_y - reddown2_y[i])*(monkey8_y - reddown2_y[i]) == r8*r8)
				{
					HPdown2[i] = HPdown2[i] - 1;
				}

				//攻击第三波气球**************

				if (i == 0 && (monkey8_x - blueup_x[i])*(monkey8_x - blueup_x[i]) + (monkey8_y - blueup_y[i])*(monkey8_y - blueup_y[i]) < r8*r8)

				{
					HPup3[i] -= 2;
				}
				else if (i != 0 && (monkey8_x - blueup_x[i])*(monkey8_x - blueup_x[i]) + (monkey8_y - blueup_y[i])*(monkey8_y - blueup_y[i]) < r8*r8 && HPup3[i - 1] < 1)
				{
					HPup3[i] -= 2;
				}
				else if (i != 0 && (monkey8_x - blueup_x[i])*(monkey8_x - blueup_x[i]) + (monkey8_y - blueup_y[i])*(monkey8_y - blueup_y[i]) < r8*r8 && (monkey8_x - blueup_x[i - 1])*(monkey8_x - blueup_x[i - 1]) + (monkey8_y - blueup_y[i - 1])*(monkey8_y - blueup_y[i - 1]) > r8*r8)
				{
					HPup3[i] -= 2;
				}
				else if (HPup3[i] == 0 && (monkey8_x - blueup_x[i])*(monkey8_x - blueup_x[i]) + (monkey8_y - blueup_y[i])*(monkey8_y - blueup_y[i]) == r8*r8)
				{
					HPup3[i] = HPup3[i] - 1;
				}

				else if (i == 0 && (monkey8_x - bluedown_x[i])*(monkey8_x - bluedown_x[i]) + (monkey8_y - bluedown_y[i])*(monkey8_y - bluedown_y[i]) < r8*r8)
				{
					HPdown3[i] -= 2;
				}
				else if (i != 0 && (monkey8_x - bluedown_x[i])*(monkey8_x - bluedown_x[i]) + (monkey8_y - bluedown_y[i])*(monkey8_y - bluedown_y[i]) < r8*r8 && HPdown3[i - 1] < 1)
				{
					HPdown3[i] -= 2;
				}
				else if (i != 0 && (monkey8_x - bluedown_x[i])*(monkey8_x - bluedown_x[i]) + (monkey8_y - bluedown_y[i])*(monkey8_y - bluedown_y[i]) < r8*r8 && (monkey8_x - bluedown_x[i - 1])*(monkey8_x - bluedown_x[i - 1]) + (monkey8_y - bluedown_y[i - 1])*(monkey8_y - bluedown_y[i - 1]) > r8*r8)
				{
					HPdown3[i] -= 2;
				}
				else if (HPdown3[i] == 0 && (monkey8_x - bluedown_x[i])*(monkey8_x - bluedown_x[i]) + (monkey8_y - bluedown_y[i])*(monkey8_y - bluedown_y[i]) == r8*r8)
				{
					HPdown3[i] = HPdown3[i] - 1;
				}

				//攻击第四波气球**************

				if (i == 0 && (monkey8_x - greenup_x[i])*(monkey8_x - greenup_x[i]) + (monkey8_y - greenup_y[i])*(monkey8_y - greenup_y[i]) < r8*r8)

				{
					HPup4[i] -= 2;
				}
				else if (i != 0 && (monkey8_x - greenup_x[i])*(monkey8_x - greenup_x[i]) + (monkey8_y - greenup_y[i])*(monkey8_y - greenup_y[i]) < r8*r8 && HPup4[i - 1] < 1)
				{
					HPup4[i] -= 2;
				}
				else if (i != 0 && (monkey8_x - greenup_x[i])*(monkey8_x - greenup_x[i]) + (monkey8_y - greenup_y[i])*(monkey8_y - greenup_y[i]) < r8*r8 && (monkey8_x - greenup_x[i - 1])*(monkey8_x - greenup_x[i - 1]) + (monkey8_y - greenup_y[i - 1])*(monkey8_y - greenup_y[i - 1]) > r8*r8)
				{
					HPup4[i] -= 2;
				}
				else if (HPup4[i] && (monkey8_x - greenup_x[i])*(monkey8_x - greenup_x[i]) + (monkey8_y - greenup_y[i])*(monkey8_y - greenup_y[i]) == r8*r8)
				{
					HPup4[i] = HPup4[i] - 1;
				}

				else if (i == 0 && (monkey8_x - greendown_x[i])*(monkey8_x - greendown_x[i]) + (monkey8_y - greendown_y[i])*(monkey8_y - greendown_y[i]) < r8*r8)
				{
					HPdown4[i] -= 2;
				}
				else if (i != 0 && (monkey8_x - greendown_x[i])*(monkey8_x - greendown_x[i]) + (monkey8_y - greendown_y[i])*(monkey8_y - greendown_y[i]) < r8*r8 && HPdown4[i - 1] < 1)
				{
					HPdown4[i] -= 2;
				}
				else if (i != 0 && (monkey8_x - greendown_x[i])*(monkey8_x - greendown_x[i]) + (monkey8_y - greendown_y[i])*(monkey8_y - greendown_y[i]) < r8*r8 && (monkey8_x - greendown_x[i - 1])*(monkey8_x - greendown_x[i - 1]) + (monkey8_y - greendown_y[i - 1])*(monkey8_y - greendown_y[i - 1]) > r8*r8)
				{
					HPdown4[i] -= 2;
				}
				else if (HPdown4[i] == 0 && (monkey8_x - greendown_x[i])*(monkey8_x - greendown_x[i]) + (monkey8_y - greendown_y[i])*(monkey8_y - greendown_y[i]) == r8*r8)
				{
					HPdown4[i] = HPdown4[i] - 1;
				}

				//攻击第六波气球**************

				if (i == 0 && (monkey8_x - gangup_x[i])*(monkey8_x - gangup_x[i]) + (monkey8_y - gangup_y[i])*(monkey8_y - gangup_y[i]) < r8*r8)

				{
					HPup6[i] -= 2;
				}
				else if (i != 0 && (monkey8_x - gangup_x[i])*(monkey8_x - gangup_x[i]) + (monkey8_y - gangup_y[i])*(monkey8_y - gangup_y[i]) < r8*r8 && HPup6[i - 1] < 1)
				{
					HPup6[i] -= 2;
				}
				else if (i != 0 && (monkey8_x - gangup_x[i])*(monkey8_x - gangup_x[i]) + (monkey8_y - gangup_y[i])*(monkey8_y - gangup_y[i]) < r8*r8 && (monkey8_x - gangup_x[i - 1])*(monkey8_x - gangup_x[i - 1]) + (monkey8_y - gangup_y[i - 1])*(monkey8_y - gangup_y[i - 1]) > r8*r8)
				{
					HPup6[i] -= 2;
				}
				else if (HPup6[i] && (monkey8_x - gangup_x[i])*(monkey8_x - gangup_x[i]) + (monkey8_y - gangup_y[i])*(monkey8_y - gangup_y[i]) == r8*r8)
				{
					HPup6[i] = HPup6[i] - 1;
				}

				else if (i == 0 && (monkey8_x - gangdown_x[i])*(monkey8_x - gangdown_x[i]) + (monkey8_y - gangdown_y[i])*(monkey8_y - gangdown_y[i]) < r8*r8)
				{
					HPdown6[i] -= 2;
				}
				else if (i != 0 && (monkey8_x - gangdown_x[i])*(monkey8_x - gangdown_x[i]) + (monkey8_y - gangdown_y[i])*(monkey8_y - gangdown_y[i]) < r8*r8 && HPdown6[i - 1] < 1)
				{
					HPdown6[i] -= 2;
				}
				else if (i != 0 && (monkey8_x - gangdown_x[i])*(monkey8_x - gangdown_x[i]) + (monkey8_y - gangdown_y[i])*(monkey8_y - gangdown_y[i]) < r8*r8 && (monkey8_x - gangdown_x[i - 1])*(monkey8_x - gangdown_x[i - 1]) + (monkey8_y - gangdown_y[i - 1])*(monkey8_y - gangdown_y[i - 1]) > r8*r8)
				{
					HPdown6[i] -= 2;
				}
				else if (HPdown6[i] == 0 && (monkey8_x - gangdown_x[i])*(monkey8_x - gangdown_x[i]) + (monkey8_y - gangdown_y[i])*(monkey8_y - gangdown_y[i]) == r8*r8)
				{
					HPdown6[i] = HPdown6[i] - 1;
				}

				//攻击第七波气球**************

				if (i == 0 && (monkey8_x - xinup_x[i])*(monkey8_x - xinup_x[i]) + (monkey8_y - xinup_y[i])*(monkey8_y - xinup_y[i]) < r8*r8)

				{
					HPup7[i] -= 2;
				}
				else if (i != 0 && (monkey8_x - xinup_x[i])*(monkey8_x - xinup_x[i]) + (monkey8_y - xinup_y[i])*(monkey8_y - xinup_y[i]) < r8*r8 && HPup7[i - 1] < 1)
				{
					HPup7[i] -= 2;
				}
				else if (i != 0 && (monkey8_x - xinup_x[i])*(monkey8_x - xinup_x[i]) + (monkey8_y - xinup_y[i])*(monkey8_y - xinup_y[i]) < r8*r8 && (monkey8_x - xinup_x[i - 1])*(monkey8_x - xinup_x[i - 1]) + (monkey8_y - xinup_y[i - 1])*(monkey8_y - xinup_y[i - 1]) > r8*r8)
				{
					HPup7[i] -= 2;
				}
				else if (HPup7[i] && (monkey8_x - xinup_x[i])*(monkey8_x - xinup_x[i]) + (monkey8_y - xinup_y[i])*(monkey8_y - xinup_y[i]) == r8*r8)
				{
					HPup7[i] = HPup7[i] - 1;
				}

				else if (i == 0 && (monkey8_x - xindown_x[i])*(monkey8_x - xindown_x[i]) + (monkey8_y - xindown_y[i])*(monkey8_y - xindown_y[i]) < r8*r8)
				{
					HPdown7[i] -= 2;
				}
				else if (i != 0 && (monkey8_x - xindown_x[i])*(monkey8_x - xindown_x[i]) + (monkey8_y - xindown_y[i])*(monkey8_y - xindown_y[i]) < r8*r8 && HPdown7[i - 1] < 1)
				{
					HPdown7[i] -= 2;
				}
				else if (i != 0 && (monkey8_x - xindown_x[i])*(monkey8_x - xindown_x[i]) + (monkey8_y - xindown_y[i])*(monkey8_y - xindown_y[i]) < r8*r8 && (monkey8_x - xindown_x[i - 1])*(monkey8_x - xindown_x[i - 1]) + (monkey8_y - xindown_y[i - 1])*(monkey8_y - xindown_y[i - 1]) > r8*r8)
				{
					HPdown7[i] -= 2;
				}
				else if (HPdown7[i] == 0 && (monkey8_x - xindown_x[i])*(monkey8_x - xindown_x[i]) + (monkey8_y - xindown_y[i])*(monkey8_y - xindown_y[i]) == r8*r8)
				{
					HPdown7[i] = HPdown7[i] - 1;
				}

				//攻击BOSS
				if ((monkey8_x - moya_x)*(monkey8_x - moya_x) + (monkey8_y - moya_y)*(monkey8_y - moya_y) < r8*r8)
				{
					HP8 = HP8 - 2;
				}

			}

			i++;

		}
	}

	Sleep(40);
}

//与输入有关的操作******************
void updateWithInput()
{
	if (GetAsyncKeyState(VK_RBUTTON) & 0x0001 && Houta_6_IsChose == 0)
	{
		while (!(GetAsyncKeyState(VK_RBUTTON) & 0x0001));
	}//暂停游戏进程

	MOUSEMSG m;	// 定义鼠标消息
	while (MouseHit())  //这个函数用于检测当前是否有鼠标消息
	{
		m = GetMouseMsg();
		if (m.x >= 320 && m.x <= 450 && m.y >= 250 && m.y <= 360)	//点击开始
		{
			BeginChange = 0;
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				Begin = 0;		//开始之后
			}
		}
		else
		{
			BeginChange = 1;
		}
		if (Begin == 0)	//开始之后的任意操作
		{

			//猴塔-1的放置***********************************************************

			//当鼠标位置等于第一个猴塔位置

			if (m.x >= 800 && m.x <= 840 && m.y >= 100 && m.y <= 135 && money >= buildhouta1)

			{

				if (m.uMsg == WM_LBUTTONDOWN)	//按下左键
				{
					Houta_1_IsChose = 0;		//显示猴塔阴影
					Houta_1_IsPutdown = 1;
				}
			}
			if (Houta_1_IsChose == 0 && m.uMsg == WM_MOUSEMOVE)
			{
				// 第一个猴塔的位置等于鼠标所在的位置

				monkey1_x = m.x;

				monkey1_y = m.y;

			}
			if (Houta_1_IsChose == 0)
			{
				if (m.uMsg == WM_RBUTTONDOWN && (m.x >= 155 && m.x <= 629 && m.y >= 144 && m.y <= 452))
				{
					money = money - buildhouta1;
					Houta_1_IsChose = 1;
					Houta_1_IsPutdown = 0;

				}
			}


			//猴塔-2的放置********************************************************

			//当鼠标位置等于第二个猴塔位置



			if (m.x >= 855 && m.x <= 890 && m.y >= 100 && m.y <= 135 && money >= buildhouta2)



			{
				if (m.uMsg == WM_LBUTTONDOWN)	//按下左键
				{
					Houta_2_IsChose = 0;		//显示猴塔阴影
					Houta_2_IsPutdown = 1;
				}
			}

			if (Houta_2_IsChose == 0 && m.uMsg == WM_MOUSEMOVE)
			{
				// 第二个猴塔的位置等于鼠标所在的位置

				monkey2_x = m.x;

				monkey2_y = m.y;
			}
			if (Houta_2_IsChose == 0)
			{
				if (m.uMsg == WM_RBUTTONDOWN && (m.x >= 155 && m.x <= 629 && m.y >= 144 && m.y <= 452))
				{
					money = money - buildhouta2;
					Houta_2_IsChose = 1;
					Houta_2_IsPutdown = 0;

				}
			}


			//猴塔-3的放置***********************************************************

			//当鼠标位置等于第三个猴塔位置



			if (m.x >= 800 && m.x <= 840 && m.y >= 150 && m.y <= 190 && money >= buildhouta3)

			{
				if (m.uMsg == WM_LBUTTONDOWN)	//按下左键
				{
					Houta_3_IsChose = 0;
					Houta_3_IsPutdown = 1;
				}
			}
			if (Houta_3_IsChose == 0 && m.uMsg == WM_MOUSEMOVE)
			{
				// 第三个猴塔的位置等于鼠标所在的位置



				monkey3_x = m.x;



				monkey3_y = m.y;
			}
			if (Houta_3_IsChose == 0)
			{
				if (m.uMsg == WM_RBUTTONDOWN && (m.x >= 155 && m.x <= 629 && m.y >= 144 && m.y <= 452))
				{
					money = money - buildhouta3;
					Houta_3_IsChose = 1;
					Houta_3_IsPutdown = 0;

				}
			}

			//猴塔-4的放置***********************************************************

			if (m.x >= 855 && m.x <= 890 && m.y >= 150 && m.y <= 190 && money >= buildhouta4)
			{
				if (m.uMsg == WM_LBUTTONDOWN)	//按下左键
				{
					Houta_4_IsChose = 0;
					Houta_4_IsPutdown = 1;
				}
			}
			if (Houta_4_IsChose == 0 && m.uMsg == WM_MOUSEMOVE)
			{
				// 第四个猴塔的位置等于鼠标所在的位置
				monkey4_x = m.x;

				monkey4_y = m.y;
			}
			if (Houta_4_IsChose == 0)
			{
				if (m.uMsg == WM_RBUTTONDOWN && ((m.x >= 105 && m.x <= 754 && m.y >= 100 && m.y <= 150) || (m.x >= 105 && m.x <= 754 && m.y >= 280 && m.y <= 330) || (m.x >= 105 && m.x <= 754 && m.y >= 480 && m.y <= 530)))
				{
					money = money - buildhouta4;
					Houta_4_IsChose = 1;
					Houta_4_IsPutdown = 0;
					huixuan_x = monkey4_x;
					huixuan_y = monkey4_y - 20;
				}
			}

			//猴塔-5的放置***********************************************************
			//当鼠标位置等于第五个猴塔位置
			if (m.x >= 800 && m.x <= 840 && m.y >= 205 && m.y <= 245 && money >= buildhouta5)

			{
				if (m.uMsg == WM_LBUTTONDOWN)	//按下左键
				{
					Houta_5_IsChose = 0;
					Houta_5_IsPutdown = 1;
				}
			}
			if (Houta_5_IsChose == 0 && m.uMsg == WM_MOUSEMOVE)
			{
				// 第五个猴塔的位置等于鼠标所在的位置
				monkey5_x = m.x;
				monkey5_y = m.y;
			}
			if (Houta_5_IsChose == 0)
			{
				if (m.uMsg == WM_RBUTTONDOWN && (m.x >= 155 && m.x <= 629 && m.y >= 144 && m.y <= 452))
				{
					money = money - buildhouta5;
					Houta_5_IsChose = 1;
					Houta_5_IsPutdown = 0;

				}
			}

			//猴塔-6的放置***********************************************************
			//当鼠标位置等于第六个猴塔位置
			if (m.x >= 855 && m.x <= 890 && m.y >= 205 && m.y <= 245 && money >= buildhouta6)

			{
				if (m.uMsg == WM_LBUTTONDOWN)	//按下左键
				{
					Houta_6_IsChose = 0;
					Houta_6_IsPutdown = 1;
				}
			}
			if (Houta_6_IsChose == 0 && m.uMsg == WM_MOUSEMOVE)
			{
				// 第六个猴塔的位置等于鼠标所在的位置
				monkey6_x = m.x;
				monkey6_y = m.y;
			}
			if (Houta_6_IsChose == 0)
			{
			if (m.uMsg == WM_RBUTTONDOWN && (m.x >= 155 && m.x <= 629 && m.y >= 144 && m.y <= 452))
				{
					money = money - buildhouta6;
					Houta_6_IsChose = 1;
					Houta_6_IsPutdown = 0;

				}
			}

			//猴塔-7的放置***********************************************************
			//当鼠标位置等于第七个猴塔位置

			if (m.x >= 800 && m.x <= 840 && m.y >= 240 && m.y <= 280 && money >= buildhouta7)

			{
				if (m.uMsg == WM_LBUTTONDOWN)	//按下左键
				{
					Houta_7_IsChose = 0;
					Houta_7_IsPutdown = 1;
				}
			}
			if (Houta_7_IsChose == 0 && m.uMsg == WM_MOUSEMOVE)
			{
				// 第七个猴塔的位置等于鼠标所在的位置

				monkey7_x = m.x;
				monkey7_y = m.y;
			}
			if (Houta_7_IsChose == 0)
			{
				if (m.uMsg == WM_RBUTTONDOWN && (m.x >= 155 && m.x <= 629 && m.y >= 144 && m.y <= 452))
				{
					money = money - buildhouta7;
					Houta_7_IsChose = 1;
					Houta_7_IsPutdown = 0;

				}
			}

			//猴塔-8的放置***********************************************************

			//当鼠标位置等于第八个猴塔位置

			if (m.x >= 855 && m.x <= 890 && m.y >= 240 && m.y <= 280 && money >= buildhouta8)

			{
				if (m.uMsg == WM_LBUTTONDOWN)	//按下左键
				{
					Houta_8_IsChose = 0;
					Houta_8_IsPutdown = 1;
				}
			}
			if (Houta_8_IsChose == 0 && m.uMsg == WM_MOUSEMOVE)
			{
				// 第八个猴塔的位置等于鼠标所在的位置



				monkey8_x = m.x;
				monkey8_y = m.y;
			}
			if (Houta_8_IsChose == 0)
			{
				if (m.uMsg == WM_RBUTTONDOWN && (m.x >= 155 && m.x <= 629 && m.y >= 144 && m.y <= 452))
				{
					money = money - buildhouta8;
					Houta_8_IsChose = 1;
					Houta_8_IsPutdown = 0;

				}
			}

			//鼠标点击+号加钱

			if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 890 && m.x <= 914 && m.y >= 0 && m.y <= 20)//鼠标点击加钱

			{

				money = money + 1000;
			}
		}



		char input;
		if (_kbhit())  // 判断是否有输入
		{

		}
	}
}

//游戏结束**********************
void gameover()
{
	EndBatchDraw();
	_getch();
	closegraph();
}

//主函数**********************
int main()
{
	startup();  // 数据初始化	
	while (1)  //  游戏循环执行
	{
		show();  // 显示画面
		updateWithoutInput();  // 与用户输入无关的更新
		updateWithInput();     // 与用户输入有关的更新
	}
	gameover();     // 游戏结束、后续处理
	return 0;
}
