/*
������ͨ������������ʵ������Ķ����ƶ���Ȼ��ͨ������flagʵ�ֺ�����ѡ������ã�
��������ж�ʵ�ֺ����Ĺ�����Χ��ͨ�������߼��ж�ʵ�ֺ�����������ж���ɱ�������ͨ
��Ѫ��ʵ������ı�ըͼ����Ч�������������ݵ���Ч����playsound�������ţ��Ų�����ֿ���
*/
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib,"Winmm.lib")

#define N 50		//��������
#define r1 120		//����-1�뾶
#define r2 90		//����-2�뾶
#define r3 800      //����-3�뾶 ȫͼ
#define r4 100      //����-4�뾶
#define r5 120		//����-5�뾶
#define r6 90		//����-6�뾶
#define r7 150		//����-7�뾶
#define r8 170		//����-8�뾶
#define buildhouta1	150		//����-1����Ľ�Ǯ
#define buildhouta2 200		//����-2����Ľ�Ǯ
#define buildhouta3 500		//����-3����Ľ�Ǯ
#define buildhouta4 200		//����-4����Ľ�Ǯ
#define buildhouta5 150		//����-5����Ľ�Ǯ
#define buildhouta6 250		//����-6����Ľ�Ǯ
#define buildhouta7 400		//����-7����Ľ�Ǯ
#define buildhouta8 1000	//����-8����Ľ�Ǯ


IMAGE img_bk;		//����ͼ
IMAGE img_jt1;		//��ͷ����ͼ
IMAGE img_jt2;		//��ͷԭͼ
IMAGE img_start11;	//��ʼ��ť����ͼ
IMAGE img_start12;	//��ʼ��ťԭͼ
IMAGE img_start21;	//��ʼ��ť����ͼ
IMAGE img_start22;	//��ʼ��ťԭͼ


IMAGE img_blockMask[N];			//����ըͼ
IMAGE img_block[N];
IMAGE img_blockMask1;			//BOSS��ըͼ
IMAGE img_block1;


IMAGE img_redup[N];				//��һ������ͼ
IMAGE img_redupMask[N];
IMAGE img_reddown[N];
IMAGE img_reddownMask[N];

IMAGE img_redup2[N];			//�ڶ�������ͼ
IMAGE img_redup2Mask[N];
IMAGE img_reddown2[N];
IMAGE img_reddown2Mask[N];

IMAGE img_blueup[N];			//����������ͼ
IMAGE img_blueupMask[N];
IMAGE img_bluedown[N];
IMAGE img_bluedownMask[N];

IMAGE img_greenup[N];			//���Ĳ�����ͼ
IMAGE img_greenupMask[N];
IMAGE img_greendown[N];
IMAGE img_greendownMask[N];

IMAGE img_micaiup[N];			//���岨����ͼ
IMAGE img_micaiupMask[N];
IMAGE img_micaidown[N];
IMAGE img_micaidownMask[N];

IMAGE img_gangup[N];			//����������ͼ
IMAGE img_gangupMask[N];
IMAGE img_gangdown[N];
IMAGE img_gangdownMask[N];

IMAGE img_xinup[N];				//���߲�����ͼ
IMAGE img_xinupMask[N];
IMAGE img_xindown[N];
IMAGE img_xindownMask[N];

IMAGE img_moya;					//�ڰ˲�����ͼ
IMAGE img_moyaMask;


//����ͼ---------------//
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

IMAGE img_huixuan;		//������ͼ
IMAGE img_huixuanMask;


IMAGE img_bian;			//�߿�ͼ
IMAGE img_houta11;		//����-1����ͼ
IMAGE img_houta12;		//����-1ԭͼ
IMAGE img_houta1red1;	//����-1�ĺ�ɫͼ
IMAGE img_houta1red2;	//����-1�ĺ�ɫ����ͼ


IMAGE img_houta21;		//����-2����ͼ
IMAGE img_houta22;		//����-2ԭͼ
IMAGE img_houta2red1;	//����-2�ĺ�ɫͼ
IMAGE img_houta2red2;	//����-2�ĺ�ɫ����ͼ


IMAGE img_houta31;		//����-3����ͼ
IMAGE img_houta32;		//����-3ԭͼ
IMAGE img_houta33;		//����-3����ͼ
IMAGE img_houta34;		//����-3ԭͼ
IMAGE img_houta3red1;	//����-3�ĺ�ɫͼ
IMAGE img_houta3red2;	//����-3�ĺ�ɫ����ͼ

IMAGE img_houta41;		//����-4����ͼ
IMAGE img_houta42;		//����-4ԭͼ
IMAGE img_houta4red1;   //����-4��ɫ����ͼ
IMAGE img_houta4red2;	//����-4��ɫԭͼ

IMAGE img_houta51;		//����-5����ͼ
IMAGE img_houta52;		//����-5ԭͼ
IMAGE img_houta5red1;	//����-5��ɫ����ͼ
IMAGE img_houta5red2;	//����-5��ɫԭͼ

IMAGE img_houta61;		//����-6����ͼ
IMAGE img_houta62;		//����-6ԭͼ
IMAGE img_houta6red1;   //����-6��ɫ����ͼ
IMAGE img_houta6red2;	//����-6��ɫԭͼ

IMAGE img_houta71;		//����-7����ͼ
IMAGE img_houta72;		//����-7ԭͼ
IMAGE img_houta7red1;	//����-7��ɫ����ͼ
IMAGE img_houta7red2;	//����-7��ɫԭͼ

IMAGE img_houta81;		//����-8����ͼ
IMAGE img_houta82;		//����-8ԭͼ
IMAGE img_houta8red1;	//����-8��ɫ����ͼ
IMAGE img_houta8red2;	//����-8��ɫԭͼ

						//��������������

int redup_x[N];		//��·��һ�����������
int redup_y[N];		//��·��һ������������
int reddown_x[N];	//��·��һ�����������
int reddown_y[N];	//��·��һ������������

int redup2_x[N];	//��·�ڶ������������
int redup2_y[N];	//��·�ڶ�������������
int reddown2_x[N];	//��·�ڶ������������
int reddown2_y[N];	//��·�ڶ�������������

int blueup_x[N];	//��·���������������
int blueup_y[N];	//��·����������������
int bluedown_x[N];	//��·���������������
int bluedown_y[N];	//��·����������������

int greenup_x[N];	 //��·���Ĳ����������
int greenup_y[N];	 //��·���Ĳ�����������
int greendown_x[N];	 //��·���Ĳ����������
int greendown_y[N];	 //��·���Ĳ�����������

int micaiup_x[N];	//��·���岨���������
int micaiup_y[N];	//��·���岨����������
int micaidown_x[N]; //��·���岨���������
int micaidown_y[N]; //��·���岨����������

int gangup_x[N];	 //��·���������������
int gangup_y[N];	 //��·����������������
int gangdown_x[N];	 //��·���������������
int gangdown_y[N];	 //��·����������������

int xinup_x[N];		//��·���߲����������
int xinup_y[N];		//��·���߲�����������
int xindown_x[N];	//��·���߲����������
int xindown_y[N];   //��·���߲�����������

int moya_x;			//Ħѹ������
int moya_y;			//Ħѹ������

float huixuan_x;	//�����ڵĺ�����
float huixuan_y;	//�����ڵ�������
float vx = -1;		//�����ڵ��ٶ�

					//������������-------------------------------------------//

float HP[8] = { 10,10,10,10,10,10,10,10 };		//�����һ�����������

float HPdown1[8] = { 10,10,10,10,10,10,10,10 };	//�����һ�����������

float HPup2[8] = { 20,20,20,20,20,20,20,20 };   //����ڶ������������

float HPdown2[8] = { 20,20,20,20,20,20,20,20 };	//����ڶ������������

float HPup3[8] = { 20,20,20,20,20,20,20,20 };  //������������������

float HPdown3[8] = { 20,20,20,20,20,20,20,20 };//������������������

float HPup4[8] = { 30,30,30,30,30,30,30,30 };  //������Ĳ����������

float HPdown4[8] = { 30,30,30,30,30,30,30,30 };//������Ĳ����������

float HPup5[8] = { 10,10,10,10,10,10,10,10 };  //������岨���������

float HPdown5[8] = { 10,10,10,10,10,10,10,10 };//������岨���������

float HPup6[8] = { 40,40,40,40,40,40,40,40 };  //������������������

float HPdown6[8] = { 40,40,40,40,40,40,40,40 };//������������������

float HPup7[8] = { 50,50,50,50,50,50,50,50 };  //������߲����������

float HPdown7[8] = { 50,50,50,50,50,50,50,50 };//������߲����������

int HP8 = 800;//Ħѹ������

int money;		//�ܽ�Ǯ
int life;   //������
int count1;
int count2;

int monkey1_x;		//����-1����
int monkey1_y;

int monkey2_x;		//����-2����
int monkey2_y;

int monkey3_x;		//����-3����
int monkey3_y;

int monkey4_x;		//����-4����
int monkey4_y;

int monkey5_x;		//����-5����
int monkey5_y;

int monkey6_x;		//����-6����
int monkey6_y;

int monkey7_x;		//����-7����
int monkey7_y;

int monkey8_x;		//����-8����
int monkey8_y;

int speed;			//���������ٶ�
int speed2;         //BOSS�ٶ�
int Begin = 1;	//�����ʼ֮��
int BeginChange = 1;	//���ƿ�ʼ��ť�ı仯

int gamestart = 1;			//��ʼ����
int menu_start = 1;			//��ʼ��Ϸ
int menu_instruction = 1;	//��Ϸ˵��
int menu_person = 1;		//������Ա
int menu_exit = 1;			//�˳���Ϸ
int menu_tower = 1;

int gameover_control = 1;   //��Ϸʧ��
int success_control = 1;
int over_exit = 1;

int Houta_1_IsPutdown = 1;	//�һ�֮����º���-1
int Houta_1_IsChose = 1;	//ѡ��߿����-1֮��

int Houta_2_IsPutdown = 1;	//�һ�֮����º���-2
int Houta_2_IsChose = 1;	//ѡ��߿����-2֮��


int Houta_3_IsChose = 1;	//�һ�֮����º���-3
int Houta_3_IsPutdown = 1;	//ѡ��߿����-3֮��


int Houta_4_IsChose = 1;	//�һ�֮����º���-4
int Houta_4_IsPutdown = 1;	//ѡ��߿����-4֮��


int Houta_5_IsChose = 1;	//�һ�֮����º���-5
int Houta_5_IsPutdown = 1;	//ѡ��߿����-5֮��


int Houta_6_IsChose = 1;	//�һ�֮����º���-6
int Houta_6_IsPutdown = 1;	//ѡ��߿����-6֮��

int Houta_7_IsChose = 1;	//�һ�֮����º���-7
int Houta_7_IsPutdown = 1;	//ѡ��߿����-7֮��

int Houta_8_IsChose = 1;	//�һ�֮����º���-8
int Houta_8_IsPutdown = 1;	//ѡ��߿����-8֮��

							//��Ϸ˵��*******************
void instruction()
{
	IMAGE img_j;
	loadimage(&img_j, L"˵������.jpg");
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
	loadimage(&img_qiqiu41, L"�Բ�����_mask.jpg");
	loadimage(&img_qiqiu42, L"�Բ�����.jpg");
	loadimage(&img_qiqiu51, L"��������_mask.jpg");
	loadimage(&img_qiqiu52, L"��������.jpg");
	loadimage(&img_qiqiu61, L"������_mask.jpg");
	loadimage(&img_qiqiu62, L"������.jpg");
	loadimage(&img_qiqiu71, L"Ħѹ_mask.bmp");
	loadimage(&img_qiqiu72, L"Ħѹ.bmp");
	putimage(65, 50, &img_red1, SRCAND);	//��ʾ������
	putimage(65, 50, &img_red2, SRCPAINT);
	putimage(60, 100, &img_blue1, SRCAND);	//��ʾ������
	putimage(60, 100, &img_blue2, SRCPAINT);
	putimage(60, 150, &img_green1, SRCAND);	//��ʾ������
	putimage(60, 150, &img_green2, SRCPAINT);
	putimage(305, 40, &img_qiqiu41, SRCAND);	//��ʾ�Բ�����
	putimage(305, 40, &img_qiqiu42, SRCPAINT);
	putimage(300, 90, &img_qiqiu51, SRCAND);	//��ʾ��������
	putimage(300, 90, &img_qiqiu52, SRCPAINT);
	putimage(300, 150, &img_qiqiu61, SRCAND);	//��ʾ������
	putimage(300, 150, &img_qiqiu62, SRCPAINT);
	putimage(450, 20, &img_qiqiu71, SRCAND);	//��ʾĦѹ
	putimage(450, 20, &img_qiqiu72, SRCPAINT);

	//�����Ϸ˵��************************************

	setcolor(YELLOW);

	settextstyle(25, 0, L"����");

	setbkmode(TRANSPARENT);

	outtextxy(100, 60, L"���ʼ�Ĺ���");

	outtextxy(100, 110, L"������Ĺ���");

	outtextxy(100, 160, L"���򵥵Ĺ���");

	outtextxy(350, 60, L"ֻ��������ѩ����ֹ");
	outtextxy(350, 110, L"С�ĵ�");
	outtextxy(350, 160, L"Σ��");
	setcolor(RED);
	settextstyle(45, 0, L"����");
	outtextxy(550, 120, L"BOSS");
	setcolor(YELLOW);
	settextstyle(25, 0, L"����");
	outtextxy(60, 220, L"ÿ��ѩ��ֻ�ܴ���һ�֣������ٴε����λ�ã���ԭ���Ļ���ʧ");
	outtextxy(60, 270, L"���ù����ܵ���������������");
	outtextxy(60, 320, L"����ƶ�ѩ�˵�λ�ã������Ҽ�����");
	outtextxy(60, 370, L"ÿ��ѩ���в�ͬ�Ĺ��ܣ�����������ֹ����");
	setcolor(RED);
	outtextxy(60, 320, L"����ƶ�ѩ�˵�λ�ã������Ҽ�����");
	setcolor(YELLOW);
	outtextxy(60, 320, L"����ƶ�ѩ�˵�λ�ã�����    ����");
	settextstyle(35, 0, L"������κ");
	outtextxy(310, 420, L"ף�����");
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, L"����");
	setcolor(RGB(255, 20, 25));//��ɫ
	outtextxy(300, 500, L"�����������");
	if (_getch() == ' ')
	{
		gamestart = 1;
	}
	setcolor(RGB(255, 255, 255));//��ɫ



}

//������˵��******************
void tower()
{
	cleardevice();
	IMAGE img_j;
	loadimage(&img_j, L"��ͼ����.jpg");
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
	loadimage(&img_hou_11, L"��ͨ��1_mask.jpg");
	loadimage(&img_hou_12, L"��ͨ��1.jpg");
	loadimage(&img_hou_21, L"����1_mask.jpg");
	loadimage(&img_hou_22, L"����1.jpg");
	loadimage(&img_hou_31, L"�ѻ���1_mask.jpg");
	loadimage(&img_hou_32, L"�ѻ���1.jpg");
	loadimage(&img_hou_41, L"���ں�1_mask.jpg");
	loadimage(&img_hou_42, L"���ں�1.jpg");
	loadimage(&img_hou_51, L"���ߺ�1_mask.jpg");
	loadimage(&img_hou_52, L"���ߺ�1.jpg");
	loadimage(&img_hou_61, L"����1_mask.jpg");
	loadimage(&img_hou_62, L"����1.jpg");
	loadimage(&img_hou_71, L"����1_mask.jpg");
	loadimage(&img_hou_72, L"����1.jpg");
	loadimage(&img_hou_81, L"���˺�1_mask.jpg");
	loadimage(&img_hou_82, L"���˺�1.jpg");
	putimage(60, 100, &img_hou_11, SRCAND);	//��ʾ����1
	putimage(60, 100, &img_hou_12, SRCPAINT);
	putimage(60, 200, &img_hou_21, SRCAND);	//��ʾ����2
	putimage(60, 200, &img_hou_22, SRCPAINT);
	putimage(60, 300, &img_hou_31, SRCAND);	//��ʾ����3
	putimage(60, 300, &img_hou_32, SRCPAINT);
	putimage(60, 400, &img_hou_41, SRCAND);	//��ʾ����4
	putimage(60, 400, &img_hou_42, SRCPAINT);
	putimage(460, 200, &img_hou_51, SRCAND);	//��ʾ����5
	putimage(460, 200, &img_hou_52, SRCPAINT);
	putimage(460, 100, &img_hou_61, SRCAND);	//��ʾ����6
	putimage(460, 100, &img_hou_62, SRCPAINT);
	putimage(460, 300, &img_hou_71, SRCAND);	//��ʾ����7
	putimage(460, 300, &img_hou_72, SRCPAINT);
	putimage(460, 400, &img_hou_81, SRCAND);	//��ʾ����8
	putimage(460, 400, &img_hou_82, SRCPAINT);

	setbkmode(TRANSPARENT);
	setcolor(YELLOW);
	settextstyle(25, 0, L"����");
	outtextxy(110, 120, L"��ͨѩ��(120)������һ����");
	outtextxy(110, 220, L"����ѩ��(200)���ܺ��õ�һ����");
	outtextxy(110, 320, L"�ѻ�ѩ��(500)������ȫͼ����");
	outtextxy(110, 420, L"����ѩ��(130)��ֻ�ܷ���·��");
	outtextxy(510, 220, L"����ѩ��(130)�����Դ����Բ�����");
	outtextxy(510, 120, L"��ѩ��(100)��������Ĺ���");
	outtextxy(510, 320, L"����ѩ��(400)����������");
	outtextxy(510, 420, L"����ѩ��(800)������bug�������");

	setbkmode(TRANSPARENT);
	settextstyle(30, 0, L"����");
	setcolor(RGB(255, 20, 25));//��ɫ
	outtextxy(300, 500, L"�����������");
	if (_getch() == ' ')
	{
		gamestart = 1;
	}

}

//��Ϸ������Ա****************
void person()
{
	cleardevice();
	IMAGE img_person;
	loadimage(&img_person, L"��Ա����.jpg");
	putimage(0, 0, &img_person);
	setbkmode(TRANSPARENT);
	settextstyle(30, 0, L"����");
	setcolor(RED);//��ɫ
	outtextxy(730, 550, L"�����������");

	settextstyle(33, 0, L"����");
	setcolor(BLACK);//��ɫ
	outtextxy(250, 30, L"19070707��");
	outtextxy(431, 450, L"1907040735���ͳ�");
	
	if (_getch() == ' ')
	{
		gamestart = 1;
	}
}


//�˵�����*********************
void  menu()
{
	//-----------------------------�˵�����------------------------------//
	mciSendString(L"close bkmusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�
	mciSendString(L"open ��������.mp3 alias menumusic", NULL, 0, NULL);//�򿪱�������

	mciSendString(L"play menumusic repeat", NULL, 0, NULL);  // ѭ������
	IMAGE img_Start;
	loadimage(&img_Start, L"��ʼ����.jpg");
	putimage(0, 0, &img_Start);
	setbkmode(TRANSPARENT);
	setcolor(WHITE);
	settextstyle(25, 0, L"����");
	outtextxy(750, 414, L"��  ʼ");
	outtextxy(410, 290, L"������");
	outtextxy(459, 334, L"��Ϸ˵��");
	outtextxy(745, 150, L"������Ա");
	outtextxy(74, 275, L"��  ��");
	if (menu_start == 0)
	{
		setcolor(YELLOW);
		outtextxy(750, 414, L"��  ʼ");
	}
	if (menu_tower == 0)
	{
		setcolor(YELLOW);
		outtextxy(410, 290, L"������");
	}
	if (menu_instruction == 0)
	{
		setcolor(YELLOW);
		outtextxy(459, 334, L"��Ϸ˵��");
	}
	if (menu_person == 0)
	{
		setcolor(YELLOW);
		outtextxy(745, 150, L"������Ա");
	}
	if (menu_exit == 0)
	{
		setcolor(YELLOW);
		outtextxy(74, 275, L"��  ��");
	}

	FlushBatchDraw();
	Sleep(20);
	MOUSEMSG m;		// ���������Ϣ
	while (MouseHit())  //����������ڼ�⵱ǰ�Ƿ��������Ϣ
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



		if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 750 && m.x <= 850 && m.y >= 400 && m.y <= 480)//�������ʼ��Ϸ
		{
			gamestart = 0;
		}
		else if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 420 && m.x <= 520 && m.y >= 330 && m.y <= 380)//�����������Ϸ˵������
		{
			instruction();
		}
		else if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 360 && m.x <= 460 && m.y >= 280 && m.y <= 345)//������������������
		{
			tower();
		}
		else if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 760 && m.x <= 860 && m.y >= 150 && m.y <= 205)//������������������
		{
			person();
		}
		else if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 70 && m.x <= 180 && m.y >= 240 && m.y <= 300)
		{
			exit(0);
		}
	}
}

//�ɹ�����*********************
void success()
{
	cleardevice();
	IMAGE img_success;
	loadimage(&img_success, L"��Ϸ�ɹ�.jpg");

	putimage(0, 0, &img_success);
	mciSendString(L"close bkmusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�

	mciSendString(L"open �ɹ�����.mp3 alias successmusic", NULL, 0, NULL);//��ʧ������

	mciSendString(L"play successmusic ", NULL, 0, NULL);  // ����һ��
	settextcolor(BLUE);//������ɫ
	settextstyle(30, 0, L"����");//��������
	outtextxy(410, 400, L"�˳���Ϸ");
	if (over_exit == 0)
	{
		setcolor(YELLOW);
		outtextxy(410, 400, L"�˳���Ϸ");
	}
	//��ʾ��Ϸ��������
	FlushBatchDraw();
	Sleep(2);
	MOUSEMSG m;		// ���������Ϣ
	while (MouseHit())  //����������ڼ�⵱ǰ�Ƿ��������Ϣ
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


		if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 335 && m.x <= 485 && m.y >= 375 && m.y <= 425)//������˳���Ϸ
		{
			exit(0);
		}
	}
}

//��������**********************
void die()
{
	cleardevice();
	IMAGE img_over;
	loadimage(&img_over, L"��Ϸʧ��.jpg");

	putimage(0, 0, &img_over);
	mciSendString(L"close bkmusic", NULL, 0, NULL); // �Ȱ�ǰ��һ�ε����ֹر�

	mciSendString(L"open ʧ������.mp3 alias overmusic", NULL, 0, NULL);//��ʧ������

	mciSendString(L"play overmusic ", NULL, 0, NULL);  // ����һ��
	settextcolor(RED);//������ɫ
	settextstyle(30, 0, L"����");//��������
	outtextxy(350, 400, L"�˳���Ϸ");
	if (over_exit == 0)
	{
		setcolor(YELLOW);
		outtextxy(350, 400, L"�˳���Ϸ");
	}
	//��ʾ��Ϸ��������
	FlushBatchDraw();
	Sleep(2);
	MOUSEMSG m;		// ���������Ϣ
	while (MouseHit())  //����������ڼ�⵱ǰ�Ƿ��������Ϣ
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


		if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 275 && m.x <= 425 && m.y >= 375 && m.y <= 425)//������˳���Ϸ
		{
			exit(0);
		}
	}
}

//��ʼ����******************
void startup()
{
	int i;
	//��ʼ����Ǯ�������������ٶȣ�boss���ٶ�
	money = 1000;
	life = 20;
	speed = 5;
	speed2 = 2;

	//���������ʼ����
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

	initgraph(914, 580);		//��ʼ����

	loadimage(&img_bk, L"bk.jpg");
	loadimage(&img_jt1, L"1.jpg");
	loadimage(&img_jt2, L"2.jpg");
	loadimage(&img_start11, L"start11.bmp");
	loadimage(&img_start12, L"start12.bmp");
	loadimage(&img_start21, L"start21.bmp");
	loadimage(&img_start22, L"start22.bmp");



	//��һ������

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

	//�ڶ�������

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

	//����������

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

	//���Ĳ�����


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

	//���岨����


	for (i = 0; i < 8; i++)

	{
		loadimage(&img_micaiupMask[i], L"�Բ�����_mask.jpg");
		loadimage(&img_micaiup[i], L"�Բ�����.jpg");
	}
	for (i = 0; i < 8; i++)
	{
		loadimage(&img_micaidownMask[i], L"�Բ�����_mask.jpg");
		loadimage(&img_micaidown[i], L"�Բ�����.jpg");
	}

	//����������


	for (i = 0; i < 8; i++)

	{
		loadimage(&img_gangupMask[i], L"������_mask.jpg");
		loadimage(&img_gangup[i], L"������.jpg");
	}
	for (i = 0; i < 8; i++)
	{
		loadimage(&img_gangdownMask[i], L"����_mask.jpg");
		loadimage(&img_gangdown[i], L"����.jpg");
	}

	//���߲�����


	for (i = 0; i < 8; i++)

	{
		loadimage(&img_xinupMask[i], L"��������_mask.jpg");
		loadimage(&img_xinup[i], L"��������.jpg");
	}
	for (i = 0; i < 8; i++)
	{
		loadimage(&img_xindownMask[i], L"��������_mask.jpg");
		loadimage(&img_xindown[i], L"��������.jpg");
	}

	//�ڰ˲�Ħѹ

	loadimage(&img_moyaMask, L"Ħѹ_mask.bmp");
	loadimage(&img_moya, L"Ħѹ.bmp");

	//����ը

	for (i = 0; i < 8; i++)

	{
		loadimage(&img_blockMask[i], L"��ը_mask.bmp");
		loadimage(&img_block[i], L"��ը.bmp");
	}

	//��ըͼ

	for (i = 0; i < 8; i++)

	{
		loadimage(&img_blockMask[i], L"��ը_mask.bmp");
		loadimage(&img_block[i], L"��ը.bmp");
	}

	loadimage(&img_blockMask1, L"��ը_mask.bmp");
	loadimage(&img_block1, L"��ը.bmp");

	//����

	for (i = 0; i < 8; i++)

	{
		loadimage(&img_bart1Mask[i], L"��ͨ������_mask.bmp");
		loadimage(&img_bart1[i], L"��ͨ������.bmp");
	}
	for (i = 0; i < 8; i++)
	{
		loadimage(&img_bart2Mask[i], L"��ͨ������2_mask.bmp");
		loadimage(&img_bart2[i], L"��ͨ������2.bmp");
	}
	for (i = 0; i < 8; i++)
	{
		loadimage(&img_bart3Mask[i], L"��ͨ������3_mask.bmp");
		loadimage(&img_bart3[i], L"��ͨ������3.bmp");
	}
	for (i = 0; i < 8; i++)
	{
		loadimage(&img_bart4Mask[i], L"��ͨ������4_mask.bmp");
		loadimage(&img_bart4[i], L"��ͨ������4.bmp");
	}
	//BOSS
	loadimage(&img_bart11Mask, L"��ͨ������_mask.bmp");
	loadimage(&img_bart11, L"��ͨ������.bmp");
	loadimage(&img_bart22Mask, L"��ͨ������_mask.bmp");
	loadimage(&img_bart22, L"��ͨ������.bmp");
	loadimage(&img_bart33Mask, L"��ͨ������_mask.bmp");
	loadimage(&img_bart33, L"��ͨ������.bmp");
	loadimage(&img_bart44Mask, L"��ͨ������_mask.bmp");
	loadimage(&img_bart44, L"��ͨ������.bmp");
	loadimage(&img_huixuanMask, L"����_mask.bmp");
	loadimage(&img_huixuan, L"����.bmp");


	//�߿�
	loadimage(&img_bian, L"bian.jpg");


	//���غ�����ͼƬ�ͻ�ɫͼƬ*************************************

	loadimage(&img_houta11, L"��ͨ��1_mask.jpg");
	loadimage(&img_houta12, L"��ͨ��1.jpg");
	loadimage(&img_houta1red1, L"��ͨ��2_mask.jpg");
	loadimage(&img_houta1red2, L"��ͨ��2.jpg");


	loadimage(&img_houta21, L"����1_mask.jpg");
	loadimage(&img_houta22, L"����1.jpg");
	loadimage(&img_houta2red1, L"����2_mask.jpg");
	loadimage(&img_houta2red2, L"����2.jpg");


	loadimage(&img_houta31, L"�ѻ���1_mask.jpg");
	loadimage(&img_houta32, L"�ѻ���1.jpg");
	loadimage(&img_houta3red1, L"�ѻ���2_mask.jpg");
	loadimage(&img_houta3red2, L"�ѻ���2.jpg");


	loadimage(&img_houta41, L"���ں�1_mask.jpg");
	loadimage(&img_houta42, L"���ں�1.jpg");
	loadimage(&img_houta4red1, L"���ں�2_mask.jpg");
	loadimage(&img_houta4red2, L"���ں�2.jpg");


	loadimage(&img_houta51, L"���ߺ�1_mask.jpg");
	loadimage(&img_houta52, L"���ߺ�1.jpg");
	loadimage(&img_houta5red1, L"���ߺ�2_mask.jpg");
	loadimage(&img_houta5red2, L"���ߺ�2.jpg");


	loadimage(&img_houta61, L"����1_mask.jpg");
	loadimage(&img_houta62, L"����1.jpg");
	loadimage(&img_houta6red1, L"����2_mask.jpg");
	loadimage(&img_houta6red2, L"����2.jpg");

	loadimage(&img_houta71, L"����1_mask.jpg");
	loadimage(&img_houta72, L"����1.bmp");
	loadimage(&img_houta7red1, L"����2_mask.jpg");
	loadimage(&img_houta7red2, L"����2.jpg");

	loadimage(&img_houta81, L"���˺�1_mask.jpg");
	loadimage(&img_houta82, L"���˺�1.jpg");
	loadimage(&img_houta8red1, L"���˺�2_mask.jpg");
	loadimage(&img_houta8red2, L"���˺�2.jpg");


	//��һ����������

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

	//�ڶ�����������

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

	//��������������

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

	//���Ĳ���������

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

	//���岨��������

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

	//��������������

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

	//���߲���������

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

	//Ħѹ��ʼ����
	moya_x = 0;
	moya_y = 180;
}

//���ͼƬ*****************
void show()
{

	while (gamestart == 1)//��ʾ�˵�
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

	BeginBatchDraw();//����������ڿ�ʼ������ͼ��ִ�к��κλ�ͼ����������ʱ���������Ļ�ϣ�ֱ��ִ�� FlushBatchDraw �� EndBatchDraw �Ž�֮ǰ�Ļ�ͼ�����
	int i;
	//--------------------------------ս������---------------------------------------//
	mciSendString(L"close menumusic", NULL, 0, NULL);// �Ȱ�ǰ������ֹر�  
	mciSendString(L"open ս������.mp3 alias bkmusic", NULL, 0, NULL);//�򿪱�������
	mciSendString(L"play bkmusic repeat", NULL, 0, NULL); // ѭ������

														  //-------------------------------------------��ʾ��̬��ͷ-------------------------------------//


	if (Begin != 0 && BeginChange == 1)
	{
		putimage(0, 0, &img_bk);	// ��ʾ����
		putimage(340, 240, &img_start11, SRCAND); //��ʾ��ʼ
		putimage(340, 240, &img_start12, SRCPAINT);
		putimage(800, 0, &img_bian);
		if (Begin % 2 == 1)
		{
			putimage(50, 245, &img_jt1, SRCAND);	// ��ʾ��ͷ
			putimage(50, 245, &img_jt2, SRCPAINT);
			Begin++;
		}
		else if (Begin % 2 == 0)
		{
			putimage(45, 245, &img_jt1, SRCAND);	// ��ʾ��ͷ
			putimage(45, 245, &img_jt2, SRCPAINT);
			Begin++;
		}
		Sleep(20);
	}
	//�����ͣ�ڿ�ʼ��ť�ϼ�����ʾ��̬��ͷ
	else if (BeginChange == 0 && Begin != 0)

	{
		putimage(0, 0, &img_bk);	// ��ʾ����
		putimage(340, 240, &img_start21, SRCAND); //��ʾ��ʼ
		putimage(340, 240, &img_start22, SRCPAINT);
		putimage(800, 0, &img_bian);
		if (Begin % 2 == 1)
		{
			putimage(50, 245, &img_jt1, SRCAND);	// ��ʾ��ͷ
			putimage(50, 245, &img_jt2, SRCPAINT);
			Begin++;
		}
		else if (Begin % 2 == 0)
		{
			putimage(45, 245, &img_jt1, SRCAND);	// ��ʾ��ͷ
			putimage(45, 245, &img_jt2, SRCPAINT);
			Begin++;
		}
		Sleep(20);
		//---------------------------------------------��ʾ��̬��ͷ-------------------------------------//

	}



	else if (Begin == 0)

	{
		putimage(0, 0, &img_bk);	// ��ʾ����
		putimage(800, 0, &img_bian);	//���ñ߽��


										//�����Ǯ-----------------------------------------------------//

		LOGFONT f1;
		gettextstyle(&f1);                     // ��ȡ��ǰ��������
		f1.lfHeight = 20;                      // ��������߶�Ϊ 48
		_tcscpy(f1.lfFaceName, _T("����"));    // ��������Ϊ�����塱
		f1.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
		settextstyle(&f1);                     // ����������ʽ
		settextcolor(YELLOW);
		wchar_t s1[20];
		_stprintf(s1, L"   %d", money);
		outtextxy(800, 5, s1);
		setbkmode(TRANSPARENT);

		//�������---------------------------------------------------//

		LOGFONT f2;
		gettextstyle(&f2);                     // ��ȡ��ǰ��������
		f2.lfHeight = 20;                      // ��������߶�Ϊ 48
		_tcscpy(f2.lfFaceName, _T("����"));    // ��������Ϊ�����塱
		f2.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
		settextstyle(&f2);                     // ����������ʽ
		settextcolor(YELLOW);
		wchar_t s2[20];
		_stprintf(s2, L"   %d", life);
		outtextxy(800, 33, s2);
		setbkmode(TRANSPARENT);

		//��ʾ��·�ڼ���---------------------------------------------------//

		LOGFONT f3;
		gettextstyle(&f3);                     // ��ȡ��ǰ��������
		f3.lfHeight = 20;                      // ��������߶�Ϊ 48
		_tcscpy(f3.lfFaceName, _T("����"));    // ��������Ϊ�����塱
		f2.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
		settextstyle(&f3);                     // ����������ʽ
		settextcolor(YELLOW);
		wchar_t s3[20];
		_stprintf(s3, L"��·��%d��", count1);
		setcolor(RED);
		outtextxy(50, 30, s3);
		setbkmode(TRANSPARENT);

		//��ʾ��·�ڼ���---------------------------------------------------//

		LOGFONT f4;
		gettextstyle(&f4);                     // ��ȡ��ǰ��������
		f4.lfHeight = 20;                      // ��������߶�Ϊ 48
		_tcscpy(f4.lfFaceName, _T("����"));    // ��������Ϊ�����塱
		f4.lfQuality = ANTIALIASED_QUALITY;    // �������Ч��Ϊ�����  
		settextstyle(&f4);                     // ����������ʽ
		settextcolor(YELLOW);
		wchar_t s4[20];
		_stprintf(s4, L"��·��%d��", count2);
		setcolor(RED);
		outtextxy(50, 530, s4);
		setbkmode(TRANSPARENT);

		//�ж���·�ڼ���
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

		//�ж���·�ڼ���
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


		//���������--------------------------------------------//
		if (Houta_4_IsPutdown == 0)
		{
			putimage(huixuan_x, huixuan_y, &img_huixuanMask, SRCAND);	//������
			putimage(huixuan_x, huixuan_y, &img_huixuan, SRCPAINT);
		}

		//�������ͼƬ-----------------------------------------//

		if (HP[0]>0)
		{
			putimage(redup_x[0], redup_y[0], &img_redupMask[0], SRCAND);	//��ʾ��һ��������
			putimage(redup_x[0], redup_y[0], &img_redup[0], SRCPAINT);
		}
		if (HPdown1[0]>0)
		{
			putimage(reddown_x[0], reddown_y[0], &img_reddownMask[0], SRCAND);	//��ʾ��һ��������
			putimage(reddown_x[0], reddown_y[0], &img_reddown[0], SRCPAINT);
		}

		for (i = 1; i < 8; i++)
		{
			if (HP[i] > 0)
			{
				if (redup_x[i - 1] >= 50)
				{
					putimage(redup_x[i], redup_y[i], &img_redupMask[i], SRCAND);	//��ʾ��һ��������
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
					putimage(reddown_x[i], reddown_y[i], &img_reddownMask[i], SRCAND);	//��ʾ��һ��������
					putimage(reddown_x[i], reddown_y[i], &img_reddown[i], SRCPAINT);
				}
			}

		}

		if (HPup2[0]>0 && HP[7] <= 0)
		{
			putimage(redup2_x[0], redup2_y[0], &img_redup2Mask[0], SRCAND);	//��ʾ�ڶ���������
			putimage(redup2_x[0], redup2_y[0], &img_redup2[0], SRCPAINT);
		}

		if (HPdown2[0]>0 && HPdown1[7] <= 0)
		{
			putimage(reddown2_x[0], reddown2_y[0], &img_reddown2Mask[0], SRCAND);	//��ʾ�ڶ���������
			putimage(reddown2_x[0], reddown2_y[0], &img_reddown2[0], SRCPAINT);
		}

		for (i = 1; i < 8; i++)
		{
			if (HPup2[i] > 0 && HP[7] <= 0)
			{
				if (redup2_x[i - 1] >= 50)
				{
					putimage(redup2_x[i], redup2_y[i], &img_redup2Mask[i], SRCAND);	//��ʾ�ڶ���������
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
					putimage(reddown2_x[i], reddown2_y[i], &img_reddown2Mask[i], SRCAND);	//��ʾ�ڶ���������
					putimage(reddown2_x[i], reddown2_y[i], &img_reddown2[i], SRCPAINT);
				}
			}

		}

		//��ʾ����������
		if (HPup3[0]>0 && HPup2[7] <= 0)

		{
			putimage(blueup_x[0], blueup_y[0], &img_blueupMask[0], SRCAND);	//��ʾ��������һ��������
			putimage(blueup_x[0], blueup_y[0], &img_blueup[0], SRCPAINT);
		}

		if (HPdown3[0]>0 && HPdown2[7] <= 0)
		{
			putimage(bluedown_x[0], bluedown_y[0], &img_bluedownMask[0], SRCAND);	//��ʾ��������һ��������
			putimage(bluedown_x[0], bluedown_y[0], &img_bluedown[0], SRCPAINT);
		}

		for (i = 1; i < 8; i++)
		{
			if (HPup3[i] > 0 && HPup2[7] <= 0)
			{
				if (blueup_x[i - 1] >= 50)
				{
					putimage(blueup_x[i], blueup_y[i], &img_blueupMask[i], SRCAND);	//��ʾ������������
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
					putimage(bluedown_x[i], bluedown_y[i], &img_bluedownMask[i], SRCAND);	//��ʾ������������
					putimage(bluedown_x[i], bluedown_y[i], &img_bluedown[i], SRCPAINT);
				}
			}

		}
		//��ʾ���Ĳ�����
		if (HPup4[0]>0 && HPup3[7] <= 0)

		{
			putimage(greenup_x[0], greenup_y[0], &img_greenupMask[0], SRCAND);	//��ʾ���Ĳ���һ��������
			putimage(greenup_x[0], greenup_y[0], &img_greenup[0], SRCPAINT);
		}

		if (HPdown4[0]>0 && HPdown3[7] <= 0)
		{
			putimage(greendown_x[0], greendown_y[0], &img_greendownMask[0], SRCAND);	//��ʾ���Ĳ���һ��������
			putimage(greendown_x[0], greendown_y[0], &img_greendown[0], SRCPAINT);
		}

		for (i = 1; i < 8; i++)
		{
			if (HPup4[i] > 0 && HPup3[7] <= 0)
			{
				if (greenup_x[i - 1] >= 50)
				{
					putimage(greenup_x[i], greenup_y[i], &img_greenupMask[i], SRCAND);	//��ʾ���Ĳ�������
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
					putimage(greendown_x[i], greendown_y[i], &img_greendownMask[i], SRCAND);	//��ʾ���Ĳ�������
					putimage(greendown_x[i], greendown_y[i], &img_greendown[i], SRCPAINT);
				}
			}

		}

		//��ʾ���岨����

		if (HPup5[0]>0 && HPup4[7] <= 0)

		{
			putimage(micaiup_x[0], micaiup_y[0], &img_micaiupMask[0], SRCAND);	//��ʾ���岨��һ��������
			putimage(micaiup_x[0], micaiup_y[0], &img_micaiup[0], SRCPAINT);
		}

		if (HPdown5[0]>0 && HPdown4[7] <= 0)
		{
			putimage(micaidown_x[0], micaidown_y[0], &img_micaidownMask[0], SRCAND);	//��ʾ���岨��һ��������
			putimage(micaidown_x[0], micaidown_y[0], &img_micaidown[0], SRCPAINT);
		}

		for (i = 1; i < 8; i++)
		{
			if (HPup5[i] > 0 && HPup4[7] <= 0)
			{
				if (micaiup_x[i - 1] >= 50)
				{
					putimage(micaiup_x[i], micaiup_y[i], &img_micaiupMask[i], SRCAND);	//��ʾ���岨������
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
					putimage(micaidown_x[i], micaidown_y[i], &img_micaidownMask[i], SRCAND);	//��ʾ���岨������
					putimage(micaidown_x[i], micaidown_y[i], &img_micaidown[i], SRCPAINT);
				}
			}

		}

		//��ʾ����������
		if (HPup6[0]>0 && HPup5[7] <= 0)

		{
			putimage(gangup_x[0], gangup_y[0], &img_gangupMask[0], SRCAND);	//��ʾ��������һ��������
			putimage(gangup_x[0], gangup_y[0], &img_gangup[0], SRCPAINT);
		}

		if (HPdown6[0]>0 && HPdown5[7] <= 0)
		{
			putimage(gangdown_x[0], gangdown_y[0], &img_gangdownMask[0], SRCAND);	//��ʾ��������һ��������
			putimage(gangdown_x[0], gangdown_y[0], &img_gangdown[0], SRCPAINT);
		}

		for (i = 1; i < 8; i++)
		{
			if (HPup6[i] > 0 && HPup5[7] <= 0)
			{
				if (gangup_x[i - 1] >= 50)
				{
					putimage(gangup_x[i], gangup_y[i], &img_gangupMask[i], SRCAND);	//��ʾ������������
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
					putimage(gangdown_x[i], gangdown_y[i], &img_gangdownMask[i], SRCAND);	//��ʾ������������
					putimage(gangdown_x[i], gangdown_y[i], &img_gangdown[i], SRCPAINT);
				}
			}

		}

		//��ʾ���߲�����

		if (HPup7[0]>0 && HPup6[7] <= 0)

		{
			putimage(xinup_x[0], xinup_y[0], &img_xinupMask[0], SRCAND);	//��ʾ���߲���һ��������
			putimage(xinup_x[0], xinup_y[0], &img_xinup[0], SRCPAINT);
		}

		if (HPdown7[0]>0 && HPdown6[7] <= 0)
		{
			putimage(xindown_x[0], xindown_y[0], &img_xindownMask[0], SRCAND);	//��ʾ���߲���һ��������
			putimage(xindown_x[0], xindown_y[0], &img_xindown[0], SRCPAINT);
		}

		for (i = 1; i < 8; i++)
		{
			if (HPup7[i] > 0 && HPup6[7] <= 0)
			{
				if (xinup_x[i - 1] >= 50)
				{
					putimage(xinup_x[i], xinup_y[i], &img_xinupMask[i], SRCAND);	//��ʾ���߲�������
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
					putimage(xindown_x[i], xindown_y[i], &img_xindownMask[i], SRCAND);	//��ʾ���߲�������
					putimage(xindown_x[i], xindown_y[i], &img_xindown[i], SRCPAINT);
				}
			}

		}

		//��ʾBOSS

		if (HPup7[7] <= 0 && HPdown7[7] <= 0 && HP8 >0)
		{
			putimage(moya_x, moya_y, &img_moyaMask, SRCAND);	//��ʾBOSS
			putimage(moya_x, moya_y, &img_moya, SRCPAINT);
		}

		//��һ���Ϸ�����ı�ը--------------------------------//
		for (i = 0; i < 8; i++)

		{
			if (HP[i] == 0)
			{

				putimage(redup_x[i], redup_y[i], &img_blockMask[i], SRCAND);	//����ըͼ
				putimage(redup_x[i], redup_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"����ը.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);		//����ը��
			}

			if ((HP[i] == 0 || HP[i] == 2 || HP[i] == 4) && (monkey1_x - redup_x[i])*(monkey1_x - redup_x[i]) + (monkey1_y - redup_y[i])*(monkey1_y - redup_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				//����������ظ������жϷ����������************************************

				if (redup_x[i] <= monkey1_x && redup_y[i] <= monkey1_y)

				{
					putimage((redup_x[i] + monkey1_x) / 2, (redup_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//����ͼ
					putimage((redup_x[i] + monkey1_x) / 2, (redup_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (redup_x[i] > monkey1_x && redup_y[i] <= monkey1_y)
				{
					putimage((redup_x[i] + monkey1_x) / 2, (redup_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//����ͼ
					putimage((redup_x[i] + monkey1_x) / 2, (redup_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (redup_x[i] <= monkey1_x && redup_y[i] > monkey1_y)
				{
					putimage((redup_x[i] + monkey1_x) / 2, (redup_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//����ͼ
					putimage((redup_x[i] + monkey1_x) / 2, (redup_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (redup_x[i] > monkey1_x && redup_y[i] > monkey1_y)
				{
					putimage((redup_x[i] + monkey1_x) / 2, (redup_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//����ͼ
					putimage((redup_x[i] + monkey1_x) / 2, (redup_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}

			}
			
		}
		//��һ���·�����ı�ը
		for (i = 0; i < 8; i++)

		{
			if (HPdown1[i] == 0)
			{

				putimage(reddown_x[i], reddown_y[i], &img_blockMask[i], SRCAND);	//����ըͼ
				putimage(reddown_x[i], reddown_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"����ը.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}
			if ((HP[i] == 0 || HP[i] == 2 || HP[i] == 4) && (monkey1_x - reddown_x[i])*(monkey1_x - reddown_x[i]) + (monkey1_y - reddown_y[i])*(monkey1_y - reddown_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (reddown_x[i] <= monkey1_x && reddown_y[i] <= monkey1_y)

				{
					putimage((reddown_x[i] + monkey1_x) / 2, (reddown_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//����ͼ
					putimage((reddown_x[i] + monkey1_x) / 2, (reddown_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (reddown_x[i] > monkey1_x && reddown_y[i] <= monkey1_y)
				{
					putimage((reddown_x[i] + monkey1_x) / 2, (reddown_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//����ͼ
					putimage((reddown_x[i] + monkey1_x) / 2, (reddown_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (reddown_x[i] < monkey1_x && reddown_y[i] >= monkey1_y)
				{
					putimage((reddown_x[i] + monkey1_x) / 2, (reddown_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//����ͼ
					putimage((reddown_x[i] + monkey1_x) / 2, (reddown_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (reddown_x[i] > monkey1_x && reddown_y[i] > monkey1_y)
				{
					putimage((reddown_x[i] + monkey1_x) / 2, (reddown_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//����ͼ
					putimage((reddown_x[i] + monkey1_x) / 2, (reddown_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}
			}
		}
		//�ڶ����Ϸ�����ı�ը
		for (i = 0; i < 8; i++)

		{
			if (HPup2[i] == 0)
			{

				putimage(redup2_x[i], redup2_y[i], &img_blockMask[i], SRCAND);	//����ըͼ
				putimage(redup2_x[i], redup2_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"����ը.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}

			if (HPup2[i] == 0 && (monkey1_x - redup2_x[i])*(monkey1_x - redup2_x[i]) + (monkey1_y - redup2_y[i])*(monkey1_y - redup2_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (redup2_x[i] <= monkey1_x && redup2_y[i] <= monkey1_y)

				{
					putimage((redup2_x[i] + monkey1_x) / 2, (redup2_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//����ͼ
					putimage((redup2_x[i] + monkey1_x) / 2, (redup2_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (redup2_x[i] > monkey1_x && redup2_y[i] <= monkey1_y)
				{
					putimage((redup2_x[i] + monkey1_x) / 2, (redup2_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//����ͼ
					putimage((redup2_x[i] + monkey1_x) / 2, (redup2_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (redup2_x[i] <= monkey1_x && redup2_y[i] > monkey1_y)
				{
					putimage((redup2_x[i] + monkey1_x) / 2, (redup2_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//����ͼ
					putimage((redup2_x[i] + monkey1_x) / 2, (redup2_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (redup2_x[i] > monkey1_x && redup2_y[i] > monkey1_y)
				{
					putimage((redup2_x[i] + monkey1_x) / 2, (redup2_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//����ͼ
					putimage((redup2_x[i] + monkey1_x) / 2, (redup2_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}
			}
		}
		//�ڶ����·�����ı�ը
		for (i = 0; i < 8; i++)

		{
			if (HPdown2[i] == 0)
			{

				putimage(reddown2_x[i], reddown2_y[i], &img_blockMask[i], SRCAND);	//����ըͼ
				putimage(reddown2_x[i], reddown2_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"����ը.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}
			if (HPdown2[i] == 0 && (monkey1_x - reddown2_x[i])*(monkey1_x - reddown2_x[i]) + (monkey1_y - reddown2_y[i])*(monkey1_y - reddown2_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (reddown2_x[i] <= monkey1_x && reddown2_y[i] <= monkey1_y)

				{
					putimage((reddown2_x[i] + monkey1_x) / 2, (reddown2_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//����ͼ
					putimage((reddown2_x[i] + monkey1_x) / 2, (reddown2_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (reddown2_x[i] > monkey1_x && reddown2_y[i] <= monkey1_y)
				{
					putimage((reddown2_x[i] + monkey1_x) / 2, (reddown2_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//����ͼ
					putimage((reddown2_x[i] + monkey1_x) / 2, (reddown2_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (reddown2_x[i] < monkey1_x && reddown2_y[i] > monkey1_y)
				{
					putimage((reddown2_x[i] + monkey1_x) / 2, (reddown2_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//����ͼ
					putimage((reddown2_x[i] + monkey1_x) / 2, (reddown2_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (reddown2_x[i] > monkey1_x && reddown2_y[i] > monkey1_y)
				{
					putimage((reddown2_x[i] + monkey1_x) / 2, (reddown2_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//����ͼ
					putimage((reddown2_x[i] + monkey1_x) / 2, (reddown2_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}

			}
		}

		//�������Ϸ�����ı�ը
		for (i = 0; i < 8; i++)

		{
			if (HPup3[i] == 0)
			{

				putimage(blueup_x[i], blueup_y[i], &img_blockMask[i], SRCAND);	//����ըͼ
				putimage(blueup_x[i], blueup_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"����ը.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}

			if (HPup3[i] == 0 && (monkey1_x - blueup_x[i])*(monkey1_x - blueup_x[i]) + (monkey1_y - blueup_y[i])*(monkey1_y - blueup_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (blueup_x[i] <= monkey1_x && blueup_y[i] <= monkey1_y)

				{
					putimage((blueup_x[i] + monkey1_x) / 2, (blueup_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//����ͼ
					putimage((blueup_x[i] + monkey1_x) / 2, (blueup_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (blueup_x[i] > monkey1_x && blueup_y[i] <= monkey1_y)
				{
					putimage((blueup_x[i] + monkey1_x) / 2, (blueup_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//����ͼ
					putimage((blueup_x[i] + monkey1_x) / 2, (blueup_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (blueup_x[i] < monkey1_x && blueup_y[i] > monkey1_y)
				{
					putimage((blueup_x[i] + monkey1_x) / 2, (blueup_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//����ͼ
					putimage((blueup_x[i] + monkey1_x) / 2, (blueup_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (blueup_x[i] > monkey1_x && blueup_y[i] > monkey1_y)
				{
					putimage((blueup_x[i] + monkey1_x) / 2, (blueup_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//����ͼ
					putimage((blueup_x[i] + monkey1_x) / 2, (blueup_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}

			}
		}
		//�������·�����ı�ը
		for (i = 0; i < 8; i++)

		{
			if (HPdown3[i] == 0)
			{

				putimage(bluedown_x[i], bluedown_y[i], &img_blockMask[i], SRCAND);	//����ըͼ
				putimage(bluedown_x[i], bluedown_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"����ը.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}
			if (HPdown3[i] == 0 && (monkey1_x - bluedown_x[i])*(monkey1_x - bluedown_x[i]) + (monkey1_y - bluedown_y[i])*(monkey1_y - bluedown_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (bluedown_x[i] <= monkey1_x && bluedown_y[i] <= monkey1_y)

				{
					putimage((bluedown_x[i] + monkey1_x) / 2, (bluedown_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//����ͼ
					putimage((bluedown_x[i] + monkey1_x) / 2, (bluedown_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (bluedown_x[i] > monkey1_x && bluedown_y[i] <= monkey1_y)
				{
					putimage((bluedown_x[i] + monkey1_x) / 2, (bluedown_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//����ͼ
					putimage((bluedown_x[i] + monkey1_x) / 2, (bluedown_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (bluedown_x[i] < monkey1_x && bluedown_y[i] > monkey1_y)
				{
					putimage((bluedown_x[i] + monkey1_x) / 2, (bluedown_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//����ͼ
					putimage((bluedown_x[i] + monkey1_x) / 2, (bluedown_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (bluedown_x[i] > monkey1_x && bluedown_y[i] > monkey1_y)
				{
					putimage((bluedown_x[i] + monkey1_x) / 2, (bluedown_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//����ͼ
					putimage((bluedown_x[i] + monkey1_x) / 2, (bluedown_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}

			}
		}

		//���Ĳ��Ϸ�����ı�ը
		for (i = 0; i < 8; i++)

		{
			if (HPup4[i] == 0)
			{

				putimage(greenup_x[i], greenup_y[i], &img_blockMask[i], SRCAND);	//����ըͼ
				putimage(greenup_x[i], greenup_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"����ը.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}

			if (HPup4[i] == 0 && (monkey1_x - greenup_x[i])*(monkey1_x - greenup_x[i]) + (monkey1_y - greenup_y[i])*(monkey1_y - greenup_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (greenup_x[i] <= monkey1_x && greenup_y[i] <= monkey1_y)

				{
					putimage((greenup_x[i] + monkey1_x) / 2, (greenup_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//����ͼ
					putimage((greenup_x[i] + monkey1_x) / 2, (greenup_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (greenup_x[i] > monkey1_x && greenup_y[i] <= monkey1_y)
				{
					putimage((greenup_x[i] + monkey1_x) / 2, (greenup_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//����ͼ
					putimage((greenup_x[i] + monkey1_x) / 2, (greenup_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (greenup_x[i] < monkey1_x && greenup_y[i] > monkey1_y)
				{
					putimage((greenup_x[i] + monkey1_x) / 2, (greenup_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//����ͼ
					putimage((greenup_x[i] + monkey1_x) / 2, (greenup_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (greenup_x[i] > monkey1_x && greenup_y[i] > monkey1_y)
				{
					putimage((greenup_x[i] + monkey1_x) / 2, (greenup_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//����ͼ
					putimage((greenup_x[i] + monkey1_x) / 2, (greenup_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}

			}
		}
		//���Ĳ��·�����ı�ը
		for (i = 0; i < 8; i++)

		{
			if (HPdown4[i] == 0)
			{

				putimage(greendown_x[i], greendown_y[i], &img_blockMask[i], SRCAND);	//����ըͼ
				putimage(greendown_x[i], greendown_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"����ը.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}
			if (HPdown4[i] == 0 && (monkey1_x - greendown_x[i])*(monkey1_x - greendown_x[i]) + (monkey1_y - greendown_y[i])*(monkey1_y - greendown_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (greendown_x[i] <= monkey1_x && greendown_y[i] <= monkey1_y)

				{
					putimage((greendown_x[i] + monkey1_x) / 2, (greendown_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//����ͼ
					putimage((greendown_x[i] + monkey1_x) / 2, (greendown_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (greendown_x[i] > monkey1_x && greendown_y[i] <= monkey1_y)
				{
					putimage((greendown_x[i] + monkey1_x) / 2, (greendown_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//����ͼ
					putimage((greendown_x[i] + monkey1_x) / 2, (greendown_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (greendown_x[i] < monkey1_x && greendown_y[i] > monkey1_y)
				{
					putimage((greendown_x[i] + monkey1_x) / 2, (greendown_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//����ͼ
					putimage((greendown_x[i] + monkey1_x) / 2, (greendown_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (greendown_x[i] > monkey1_x && greendown_y[i] > monkey1_y)
				{
					putimage((greendown_x[i] + monkey1_x) / 2, (greendown_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//����ͼ
					putimage((greendown_x[i] + monkey1_x) / 2, (greendown_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}


			}
		}

		//���岨�Ϸ�����ı�ը

		for (i = 0; i < 8; i++)

		{
			if (HPup5[i] == 0)
			{

				putimage(micaiup_x[i], micaiup_y[i], &img_blockMask[i], SRCAND);	//����ըͼ
				putimage(micaiup_x[i], micaiup_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"����ը.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}

			if (HPup5[i] == 0 && (monkey1_x - micaiup_x[i])*(monkey1_x - micaiup_x[i]) + (monkey1_y - micaiup_y[i])*(monkey1_y - micaiup_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (micaiup_x[i] <= monkey1_x && micaiup_y[i] <= monkey1_y)

				{
					putimage((micaiup_x[i] + monkey1_x) / 2, (micaiup_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//����ͼ
					putimage((micaiup_x[i] + monkey1_x) / 2, (micaiup_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (micaiup_x[i] > monkey1_x && micaiup_y[i] <= monkey1_y)
				{
					putimage((micaiup_x[i] + monkey1_x) / 2, (micaiup_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//����ͼ
					putimage((micaiup_x[i] + monkey1_x) / 2, (micaiup_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (micaiup_x[i] < monkey1_x && micaiup_y[i] > monkey1_y)
				{
					putimage((micaiup_x[i] + monkey1_x) / 2, (micaiup_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//����ͼ
					putimage((micaiup_x[i] + monkey1_x) / 2, (micaiup_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (micaiup_x[i] > monkey1_x && micaiup_y[i] > monkey1_y)
				{
					putimage((micaiup_x[i] + monkey1_x) / 2, (micaiup_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//����ͼ
					putimage((micaiup_x[i] + monkey1_x) / 2, (micaiup_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}

			}
		}
		//���岨�·�����ı�ը

		for (i = 0; i < 8; i++)

		{
			if (HPdown5[i] == 0)
			{

				putimage(micaidown_x[i], micaidown_y[i], &img_blockMask[i], SRCAND);	//����ըͼ
				putimage(micaidown_x[i], micaidown_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"����ը.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}
			if (HPdown5[i] == 0 && (monkey1_x - micaidown_x[i])*(monkey1_x - micaidown_x[i]) + (monkey1_y - micaidown_y[i])*(monkey1_y - micaidown_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (micaidown_x[i] <= monkey1_x && micaidown_y[i] <= monkey1_y)

				{
					putimage((micaidown_x[i] + monkey1_x) / 2, (micaidown_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//����ͼ
					putimage((micaidown_x[i] + monkey1_x) / 2, (micaidown_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (micaidown_x[i] > monkey1_x && micaidown_y[i] <= monkey1_y)
				{
					putimage((micaidown_x[i] + monkey1_x) / 2, (micaidown_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//����ͼ
					putimage((micaidown_x[i] + monkey1_x) / 2, (micaidown_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (micaidown_x[i] < monkey1_x && micaidown_y[i] > monkey1_y)
				{
					putimage((micaidown_x[i] + monkey1_x) / 2, (micaidown_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//����ͼ
					putimage((micaidown_x[i] + monkey1_x) / 2, (micaidown_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (micaidown_x[i] > monkey1_x && micaidown_y[i] > monkey1_y)
				{
					putimage((micaidown_x[i] + monkey1_x) / 2, (micaidown_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//����ͼ
					putimage((micaidown_x[i] + monkey1_x) / 2, (micaidown_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}


			}
		}

		//�������Ϸ�����ı�ը

		for (i = 0; i < 8; i++)

		{
			if (HPup6[i] == 0)
			{

				putimage(gangup_x[i], gangup_y[i], &img_blockMask[i], SRCAND);	//����ըͼ
				putimage(gangup_x[i], gangup_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"����ը.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}

			if (HPup6[i] == 0 && (monkey1_x - gangup_x[i])*(monkey1_x - gangup_x[i]) + (monkey1_y - gangup_y[i])*(monkey1_y - gangup_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (gangup_x[i] <= monkey1_x && gangup_y[i] <= monkey1_y)

				{
					putimage((gangup_x[i] + monkey1_x) / 2, (gangup_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//����ͼ
					putimage((gangup_x[i] + monkey1_x) / 2, (gangup_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (gangup_x[i] > monkey1_x && gangup_y[i] <= monkey1_y)
				{
					putimage((gangup_x[i] + monkey1_x) / 2, (gangup_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//����ͼ
					putimage((gangup_x[i] + monkey1_x) / 2, (gangup_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (gangup_x[i] < monkey1_x && gangup_y[i] > monkey1_y)
				{
					putimage((gangup_x[i] + monkey1_x) / 2, (gangup_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//����ͼ
					putimage((gangup_x[i] + monkey1_x) / 2, (gangup_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (gangup_x[i] > monkey1_x && gangup_y[i] > monkey1_y)
				{
					putimage((gangup_x[i] + monkey1_x) / 2, (gangup_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//����ͼ
					putimage((gangup_x[i] + monkey1_x) / 2, (gangup_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}

			}
		}

		//�������·�����ı�ը

		for (i = 0; i < 8; i++)

		{
			if (HPdown6[i] == 0)
			{

				putimage(gangdown_x[i], gangdown_y[i], &img_blockMask[i], SRCAND);	//����ըͼ
				putimage(gangdown_x[i], gangdown_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"����ը.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}
			if (HPdown6[i] == 0 && (monkey1_x - gangdown_x[i])*(monkey1_x - gangdown_x[i]) + (monkey1_y - gangdown_y[i])*(monkey1_y - gangdown_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (gangdown_x[i] <= monkey1_x && gangdown_y[i] <= monkey1_y)

				{
					putimage((gangdown_x[i] + monkey1_x) / 2, (gangdown_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//����ͼ
					putimage((gangdown_x[i] + monkey1_x) / 2, (gangdown_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (gangdown_x[i] > monkey1_x && gangdown_y[i] <= monkey1_y)
				{
					putimage((gangdown_x[i] + monkey1_x) / 2, (gangdown_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//����ͼ
					putimage((gangdown_x[i] + monkey1_x) / 2, (gangdown_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (gangdown_x[i] < monkey1_x && gangdown_y[i] > monkey1_y)
				{
					putimage((gangdown_x[i] + monkey1_x) / 2, (gangdown_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//����ͼ
					putimage((gangdown_x[i] + monkey1_x) / 2, (gangdown_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (gangdown_x[i] > monkey1_x && gangdown_y[i] > monkey1_y)
				{
					putimage((gangdown_x[i] + monkey1_x) / 2, (gangdown_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//����ͼ
					putimage((gangdown_x[i] + monkey1_x) / 2, (gangdown_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}

			}
		}
		//���߲��Ϸ�����ı�ը

		for (i = 0; i < 8; i++)

		{
			if (HPup7[i] == 0)
			{
				putimage(xinup_x[i], xinup_y[i], &img_blockMask[i], SRCAND);	//����ըͼ
				putimage(xinup_x[i], xinup_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"����ը.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}

			if (HPup7[i] == 0 && (monkey1_x - xinup_x[i])*(monkey1_x - xinup_x[i]) + (monkey1_y - xinup_y[i])*(monkey1_y - xinup_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (xinup_x[i] <= monkey1_x && xinup_y[i] <= monkey1_y)

				{
					putimage((xinup_x[i] + monkey1_x) / 2, (xinup_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//����ͼ
					putimage((xinup_x[i] + monkey1_x) / 2, (xinup_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (xinup_x[i] > monkey1_x && xinup_y[i] <= monkey1_y)
				{
					putimage((xinup_x[i] + monkey1_x) / 2, (xinup_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//����ͼ
					putimage((xinup_x[i] + monkey1_x) / 2, (xinup_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (xinup_x[i] < monkey1_x && xinup_y[i] > monkey1_y)
				{
					putimage((xinup_x[i] + monkey1_x) / 2, (xinup_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//����ͼ
					putimage((xinup_x[i] + monkey1_x) / 2, (xinup_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (xinup_x[i] > monkey1_x && xinup_y[i] > monkey1_y)
				{
					putimage((xinup_x[i] + monkey1_x) / 2, (xinup_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//����ͼ
					putimage((xinup_x[i] + monkey1_x) / 2, (xinup_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}

			}
		}
		//���߲��·�����ı�ը

		for (i = 0; i < 8; i++)

		{
			if (HPdown7[i] == 0)
			{
				putimage(xindown_x[i], xindown_y[i], &img_blockMask[i], SRCAND);	//����ըͼ
				putimage(xindown_x[i], xindown_y[i], &img_block[i], SRCPAINT);
				PlaySound(L"����ը.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);
			}
			if (HPdown7[i] == 0 && (monkey1_x - xindown_x[i])*(monkey1_x - xindown_x[i]) + (monkey1_y - xindown_y[i])*(monkey1_y - xindown_y[i]) <= r1*r1&&Houta_1_IsPutdown == 0)
			{

				if (xindown_x[i] <= monkey1_x && xindown_y[i] <= monkey1_y)

				{
					putimage((xindown_x[i] + monkey1_x) / 2, (xindown_y[i] + monkey1_y) / 2, &img_bart1Mask[i], SRCAND);	//����ͼ
					putimage((xindown_x[i] + monkey1_x) / 2, (xindown_y[i] + monkey1_y) / 2, &img_bart1[i], SRCPAINT);
				}
				else if (xindown_x[i] > monkey1_x && xindown_y[i] <= monkey1_y)
				{
					putimage((xindown_x[i] + monkey1_x) / 2, (xindown_y[i] + monkey1_y) / 2, &img_bart2Mask[i], SRCAND);	//����ͼ
					putimage((xindown_x[i] + monkey1_x) / 2, (xindown_y[i] + monkey1_y) / 2, &img_bart2[i], SRCPAINT);
				}
				else if (xindown_x[i] < monkey1_x && xindown_y[i] > monkey1_y)
				{
					putimage((xindown_x[i] + monkey1_x) / 2, (xindown_y[i] + monkey1_y) / 2, &img_bart3Mask[i], SRCAND);	//����ͼ
					putimage((xindown_x[i] + monkey1_x) / 2, (xindown_y[i] + monkey1_y) / 2, &img_bart3[i], SRCPAINT);
				}
				else if (xindown_x[i] > monkey1_x && xindown_y[i] > monkey1_y)
				{
					putimage((xindown_x[i] + monkey1_x) / 2, (xindown_y[i] + monkey1_y) / 2, &img_bart4Mask[i], SRCAND);	//����ͼ
					putimage((xindown_x[i] + monkey1_x) / 2, (xindown_y[i] + monkey1_y) / 2, &img_bart4[i], SRCPAINT);
				}
			}
		}

		//BOSS��ը
		if (HP8 == 0 || HP8 == 50 || HP8 == 100 || HP8 == 150 || HP8 == 200 || HP8 == 250 || HP8 == 300 || HP8 == 350 || HP8 == 400 || HP8 == 450 || HP8 == 500)
		{
			putimage(moya_x + 10, moya_y + 20, &img_blockMask1, SRCAND);	//����ըͼ
			putimage(moya_x + 10, moya_y + 20, &img_block1, SRCPAINT);
			PlaySound(L"����ը.wav ", NULL, SND_FILENAME | SND_ASYNC | SND_SYNC);

		}
		if ((HP8 == 0 || HP8 == 50 || HP8 == 100 || HP8 == 150 || HP8 == 200 || HP8 == 250 || HP8 == 300 || HP8 == 350 || HP8 == 400 || HP8 == 450 || HP8 == 500) && (monkey1_x - moya_x)*(monkey1_x - moya_x) + (monkey1_y - moya_y)*(monkey1_y - moya_y) <= r1*r1&&Houta_1_IsPutdown == 0)
		{
			if (moya_x <= monkey1_x && moya_y <= monkey1_y)

			{
				putimage((moya_x + monkey1_x) / 2, (moya_y + monkey1_y) / 2, &img_bart11Mask, SRCAND);	//����ͼ
				putimage((moya_x + monkey1_x) / 2, (moya_y + monkey1_y) / 2, &img_bart11, SRCPAINT);
			}
			else if (moya_x > monkey1_x && moya_y <= monkey1_y)
			{
				putimage((moya_x + monkey1_x) / 2, (moya_y + monkey1_y) / 2, &img_bart22Mask, SRCAND);	//����ͼ
				putimage((moya_x + monkey1_x) / 2, (moya_y + monkey1_y) / 2, &img_bart22, SRCPAINT);
			}
			else if (moya_x < monkey1_x && moya_y > monkey1_y)
			{
				putimage((moya_x + monkey1_x) / 2, (moya_y + monkey1_y) / 2, &img_bart33Mask, SRCAND);	//����ͼ
				putimage((moya_x + monkey1_x) / 2, (moya_y + monkey1_y) / 2, &img_bart33, SRCPAINT);
			}
			else if (moya_x > monkey1_x && moya_y > monkey1_y)
			{
				putimage((moya_x + monkey1_x) / 2, (moya_y + monkey1_y) / 2, &img_bart44Mask, SRCAND);	//����ͼ
				putimage((moya_x + monkey1_x) / 2, (moya_y + monkey1_y) / 2, &img_bart44, SRCPAINT);
			}
		}
		//����Ǯ����ʱ�����ɫͼ****************************************
		//����Ǯ�ȵ�һ�������������Ǯ��ʱ
		if (money<buildhouta1)
		{
			putimage(804, 95, &img_houta1red1, SRCAND);
			putimage(804, 95, &img_houta1red2, SRCPAINT);
		}
		//����Ǯ�ȵڶ��������������Ǯ��ʱ
		if (money < buildhouta2)
		{
			putimage(860, 93, &img_houta2red1, SRCAND);
			putimage(860, 93, &img_houta2red2, SRCPAINT);
		}
		//����Ǯ�ȵ����������������Ǯ��ʱ
		if (money<buildhouta3)
		{
			putimage(804, 140, &img_houta3red1, SRCAND);
			putimage(804, 140, &img_houta3red2, SRCPAINT);
		}
		//����Ǯ�ȵ��ĸ������������Ǯ��ʱ
		if (money<buildhouta4)

		{
			putimage(862, 148, &img_houta4red1, SRCAND);
			putimage(862, 148, &img_houta4red2, SRCPAINT);
		}
		//����Ǯ�ȵ���������������Ǯ��ʱ
		if (money<buildhouta5)

		{
			putimage(804, 200, &img_houta5red1, SRCAND);
			putimage(804, 200, &img_houta5red2, SRCPAINT);
		}
		//����Ǯ�ȵ����������������Ǯ��ʱ
		if (money<buildhouta6)

		{
			putimage(860, 204, &img_houta6red1, SRCAND);
			putimage(860, 204, &img_houta6red2, SRCPAINT);
		}
		//����Ǯ�ȵ��߸������������Ǯ��ʱ
		if (money<buildhouta7)

		{
			putimage(805, 255, &img_houta7red1, SRCAND);
			putimage(805, 255, &img_houta7red2, SRCPAINT);
		}
		//����Ǯ�ȵڰ˸������������Ǯ��ʱ
		if (money<buildhouta8)

		{
			putimage(860, 255, &img_houta8red1, SRCAND);
			putimage(860, 255, &img_houta8red2, SRCPAINT);
		}

		//������˵�һ��������������������λ���ƶ�*********************

		if (Houta_1_IsChose == 0)
		{
			//ֻ�е���������ָ����λ��ʱ�Ż������ɫ������Χ�����������ɫ������Χ
			if ((monkey1_x >= 155 && monkey1_x <= 629 && monkey1_y >= 144 && monkey1_y <= 452))
			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(190, 190, 190));
				circle(monkey1_x, monkey1_y, r1);
				putimage(monkey1_x - 25, monkey1_y - 24, &img_houta11, SRCAND);
				putimage(monkey1_x - 25, monkey1_y - 24, &img_houta12, SRCPAINT);
			}
			//�������ڲ��ɷ�������ʱ�����ɫ�뾶
			else
			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(255, 0, 0));		//��ɫ 
				circle(monkey1_x, monkey1_y, r1);
				putimage(monkey1_x - 25, monkey1_y - 24, &img_houta11, SRCAND);
				putimage(monkey1_x - 25, monkey1_y - 24, &img_houta12, SRCPAINT);
			}
		}
		//����Ҽ����µ�һ������
		if (Houta_1_IsPutdown == 0)

		{
			putimage(monkey1_x - 25, monkey1_y - 24, &img_houta11, SRCAND);
			putimage(monkey1_x - 25, monkey1_y - 24, &img_houta12, SRCPAINT);

		}


		//������˵ڶ������������������λ���ƶ�******************

		if (Houta_2_IsChose == 0)

		{
			//ͬ����1
			if ((monkey2_x >= 155 && monkey2_x <= 629 && monkey2_y >= 144 && monkey2_y <= 452))
			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(190, 190, 190));
				circle(monkey2_x, monkey2_y, r2);
				putimage(monkey2_x - 25, monkey2_y - 24, &img_houta21, SRCAND);
				putimage(monkey2_x - 25, monkey2_y - 24, &img_houta22, SRCPAINT);
			}
			//�������ڲ��ɷ�������ʱ
			else

			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(255, 0, 0));
				circle(monkey2_x, monkey2_y, r2);
				putimage(monkey2_x - 25, monkey2_y - 24, &img_houta21, SRCAND);
				putimage(monkey2_x - 25, monkey2_y - 24, &img_houta22, SRCPAINT);
			}
		}

		//����Ҽ����µڶ�������
		if (Houta_2_IsPutdown == 0)

		{
			putimage(monkey2_x - 25, monkey2_y - 24, &img_houta21, SRCAND);
			putimage(monkey2_x - 25, monkey2_y - 24, &img_houta22, SRCPAINT);
		}


		//�������������**************************
		if (Houta_3_IsChose == 0)

		{
			//ͬ����1
			if ((monkey3_x >= 155 && monkey3_x <= 629 && monkey3_y >= 144 && monkey3_y <= 452))
			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(190, 190, 190));
				circle(monkey3_x, monkey3_y, r3);
				putimage(monkey3_x - 25, monkey3_y - 24, &img_houta31, SRCAND);
				putimage(monkey3_x - 25, monkey3_y - 24, &img_houta32, SRCPAINT);
			}
			//�������ڲ��ɷ�������ʱ
			else

			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(255, 0, 0));
				circle(monkey3_x, monkey3_y, r3);
				putimage(monkey3_x - 25, monkey3_y - 24, &img_houta31, SRCAND);
				putimage(monkey3_x - 25, monkey3_y - 24, &img_houta32, SRCPAINT);
			}
		}

		//����Ҽ����µ���������
		if (Houta_3_IsPutdown == 0)

		{
			putimage(monkey3_x - 25, monkey3_y - 24, &img_houta31, SRCAND);
			putimage(monkey3_x - 25, monkey3_y - 24, &img_houta32, SRCPAINT);
		}

		//������ĸ����������������λ���ƶ�*******************
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

			//�������ڲ��ɷ�������ʱ
			else
			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(255, 0, 0));
				circle(monkey4_x, monkey4_y, r4);
				putimage(monkey4_x - 25, monkey4_y - 24, &img_houta41, SRCAND);
				putimage(monkey4_x - 25, monkey4_y - 24, &img_houta42, SRCPAINT);
			}
		}
		//����Ҽ����µ��ĸ�����
		if (Houta_4_IsPutdown == 0)
		{
			putimage(monkey4_x - 25, monkey4_y - 24, &img_houta41, SRCAND);
			putimage(monkey4_x - 25, monkey4_y - 24, &img_houta42, SRCPAINT);
		}

		//������˵�������������������λ���ƶ�************************
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
			//�������ڲ��ɷ�������ʱ
			else

			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(255, 0, 0));		//��ɫ 
				circle(monkey5_x, monkey5_y, r1);
				putimage(monkey5_x - 25, monkey5_y - 24, &img_houta51, SRCAND);
				putimage(monkey5_x - 25, monkey5_y - 24, &img_houta52, SRCPAINT);
			}
		}
		//����Ҽ����µ��������
		if (Houta_5_IsPutdown == 0)

		{
			putimage(monkey5_x - 25, monkey5_y - 24, &img_houta51, SRCAND);
			putimage(monkey5_x - 25, monkey5_y - 24, &img_houta52, SRCPAINT);

		}


		//������˵������������������λ���ƶ�************************
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
			//�������ڲ��ɷ�������ʱ
			else

			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(255, 0, 0));		//��ɫ 
				circle(monkey6_x, monkey6_y, r6);
				putimage(monkey6_x - 25, monkey6_y - 24, &img_houta61, SRCAND);
				putimage(monkey6_x - 25, monkey6_y - 24, &img_houta62, SRCPAINT);
			}
		}

		//����Ҽ����µ�������
		if (Houta_6_IsPutdown == 0)

		{
			putimage(monkey6_x - 25, monkey6_y - 24, &img_houta61, SRCAND);
			putimage(monkey6_x - 25, monkey6_y - 24, &img_houta62, SRCPAINT);

		}

		//������˵��ߺ��������������λ���ƶ�************************
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
			//�������ڲ��ɷ�������ʱ
			else

			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(255, 0, 0));		//��ɫ 
				circle(monkey7_x, monkey7_y, r7);
				putimage(monkey7_x - 25, monkey7_y - 24, &img_houta71, SRCAND);
				putimage(monkey7_x - 25, monkey7_y - 24, &img_houta72, SRCPAINT);
			}
		}

		//����Ҽ����µ��߸�����

		if (Houta_7_IsPutdown == 0)

		{
			putimage(monkey7_x - 25, monkey7_y - 24, &img_houta71, SRCAND);
			putimage(monkey7_x - 25, monkey7_y - 24, &img_houta72, SRCPAINT);

		}

		//������˵ڰ˺��������������λ���ƶ�************************

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
			//�������ڲ��ɷ�������ʱ
			else

			{
				setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 3);
				setcolor(RGB(255, 0, 0));		//��ɫ 
				circle(monkey8_x, monkey8_y, r8);
				putimage(monkey8_x - 25, monkey8_y - 24, &img_houta81, SRCAND);
				putimage(monkey8_x - 25, monkey8_y - 24, &img_houta82, SRCPAINT);
			}
		}
		//����Ҽ����µڰ˸�����

		if (Houta_8_IsPutdown == 0)

		{
			putimage(monkey8_x - 25, monkey8_y - 24, &img_houta81, SRCAND);
			putimage(monkey8_x - 25, monkey8_y - 24, &img_houta82, SRCPAINT);

		}

	}
	FlushBatchDraw();
	// ִ��ָ��������δ��ɵĻ�������
}

//�������޹�*****************
void updateWithoutInput()
{
	//�ж�����ɹ�ʧ�ܵĺ���*****************
	if (life == 0)
	{
		gameover_control = 0;
	}
	else if (HP8 <= 0 && HP8 != -1)
	{
		success_control = 0;
	}


	//�����������ֵ���ܵ�����ֵ������ʱ�Ž����������������************************

	else if (life > 0 && HPup4[7] != 0 || HPdown4[7] != 0)
	{
		//����ʱ����������ƶ��켣�ж�����8��**********************
		int i;
		//��һ��������ƶ�
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
		//�ڶ���������ƶ�
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
		//������������ƶ�
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
		//���Ĳ�������ƶ�
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

		//���岨������ƶ�
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

		//������������ƶ�
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

		//���߲�������ƶ�
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

		//BOSS�ĵ����ƶ�·��
		if (HPup7[7] <= 0 && HPdown7[7] <= 0 && HP8>0)
		{
			moya_x = moya_x + speed2;
		}
		//i�����¸�ֵ
		i = 0;
		while (i<8)
		{
			//�ж�����**************************************************
			//����ֵ�ļ���
			//�����򵽴��յ���ʱ��life--
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

			//�·����򵽴��յ�
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


			//���򵽴��յ�ʱ�����������ֵ��-1�������������߼��жϳ�ͻ*********************************************
			//�Ϸ�����
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
			//�·�����
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
			//���򵽴��յ�ʱ�����������ֵ��-1�������������߼��жϳ�ͻ*********************************************

			//��ɱ�����Ǯ******************************
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
			//��ɱ�����Ǯ******************************

			//����-1����������ж�����**************************************
			//������-1����֮��ִ�����в���--------------------------------//
			if (Houta_1_IsPutdown == 0)

			{
				//������һ������**************
				//��һ���ĵ�һ��������빥���뾶ʱ
				if (i == 0 && (monkey1_x - redup_x[i])*(monkey1_x - redup_x[i]) + (monkey1_y - redup_y[i])*(monkey1_y - redup_y[i]) < r1*r1)
				{
					HP[i] = HP[i] - 1;
				}
				//�����������빥���뾶ʱ
				else if (i != 0 && (monkey1_x - redup_x[i])*(monkey1_x - redup_x[i]) + (monkey1_y - redup_y[i])*(monkey1_y - redup_y[i]) < r1*r1 && HP[i - 1] < 0)
				{
					HP[i] = HP[i] - 1;
				}
				//��ǰһ������û��ʱ�����ȹ����������Զ�����յ����������*****************************************
				else if (i != 0 && (monkey1_x - redup_x[i])*(monkey1_x - redup_x[i]) + (monkey1_y - redup_y[i])*(monkey1_y - redup_y[i]) < r1*r1 && (monkey1_x - redup_x[i - 1])*(monkey1_x - redup_x[i - 1]) + (monkey1_y - redup_y[i - 1])*(monkey1_y - redup_y[i - 1]) > r1*r1)
				{
					HP[i]--;
				}
				//���������߳������뾶���������պ�Ϊ0ʱ����������ֵ��1���Դ�����������ըͼ��ڱ���ͼ�ϵ�������� (û��֮ǰʱ�������������)


				//�������������к�������������Ĺ����ж����ϳ���----------------------------------------------------------------//

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

				//�����ڶ�������**************

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

				//��������������**************

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

				//�������Ĳ�����**************

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

				//��������������**************

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

				//�������߲�����**************

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

				//����BOSS
				if ((monkey1_x - moya_x)*(monkey1_x - moya_x) + (monkey1_y - moya_y)*(monkey1_y - moya_y) < r1*r1)
				{
					HP8 = HP8 - 1;
				}

			}

			//����-2����������ж�����**************************************
			//����-2�Ƿ�Χ�Թ��������-1���ֲ�ͬ-------------------------//

			//������-2������֮��Ĳ���
			if (Houta_2_IsPutdown == 0)
			{
				//������һ������
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

				//�����ڶ�������**************

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

				//��������������**************

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

				//�������Ĳ�����**************

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

				//��������������**************


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


				//�������߲�����**************

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

				//����BOSS
				if ((monkey2_x - moya_x)*(monkey2_x - moya_x) + (monkey2_y - moya_y)*(monkey2_y - moya_y) < r2*r2)
				{
					HP8 = HP8 - 1;
				}

			}

			//����-3����������ж�����**************************************

			//����-3�Ĺ�����Χ��ȫͼ�����Թ����ж����в�ͬ���Һ���-3���ȹ�����·����Ϊʲô��
			//������-3����֮����������

			if (Houta_3_IsPutdown == 0)
			{
				//������һ���·�����

				if (i == 0)

				{
					HPdown1[i]--;
				}
				else if (i != 0 && HPdown1[i - 1] <= 0)
				{
					HPdown1[i]--;
				}

				//��һ���Ϸ�
				if (i == 0 && HPdown1[7] <= 0)
				{
					HP[i]--;
				}
				else if (i != 0 && HP[i - 1] <= 0)
				{
					HP[i]--;
				}

				//�ڶ����·�
				if (i == 0 && HP[7] <= 0 && HPdown1[7] <= 0)
				{
					HPdown2[i]--;
				}
				else if (i != 0 && HPdown2[i - 1] <= 0 && HPdown1[7] <= 0)
				{
					HPdown2[i]--;
				}

				//�ڶ����Ϸ�
				if (i == 0 && HPdown2[7] <= 0 && HP[7] <= 0)
				{
					HPup2[i]--;
				}
				else if (i != 0 && HPup2[i - 1] <= 0 && HP[7] <= 0)
				{
					HPup2[i]--;
				}

				//�������·�
				if (i == 0 && HPup2[7] <= 0 && HPdown2[7] <= 0)
				{
					HPdown3[i]--;
				}
				else if (i != 0 && HPdown3[i - 1] <= 0 && HPdown2[7] <= 0)
				{
					HPdown3[i]--;
				}

				//�������Ϸ�
				if (i == 0 && HPdown3[7] <= 0 && HPup2[7] <= 0)
				{
					HPup3[i]--;
				}
				else if (i != 0 && HPup3[i - 1] <= 0 && HPup2[7] <= 0)
				{
					HPup3[i]--;
				}

				//���Ĳ��·�
				if (i == 0 && HPup3[7] <= 0 && HPdown3[7] <= 0)
				{
					HPdown4[i]--;
				}
				else if (i != 0 && HPdown4[i - 1] <= 0 && HPdown3[7] <= 0)
				{
					HPdown4[i]--;
				}

				//���Ĳ��Ϸ�
				if (i == 0 && HPdown4[7] <= 0 && HPup3[7] <= 0)
				{
					HPup4[i]--;
				}
				else if (i != 0 && HPup4[i - 1] <= 0 && HPup3[7] <= 0)
				{
					HPup4[i]--;
				}

				//�������·�
				if (i == 0 && HPup5[7] <= 0 && HPdown5[7] <= 0)
				{
					HPdown6[i]--;
				}
				else if (i != 0 && HPdown6[i - 1] <= 0 && HPdown5[7] <= 0)
				{
					HPdown6[i]--;
				}

				//�������Ϸ�
				if (i == 0 && HPdown6[7] <= 0 && HPup5[7] <= 0)
				{
					HPup6[i]--;
				}
				else if (i != 0 && HPup6[i - 1] <= 0 && HPup5[7] <= 0)
				{
					HPup6[i]--;
				}

				//���߲��·�
				if (i == 0 && HPup6[7] <= 0 && HPdown6[7] <= 0)
				{
					HPdown7[i]--;
				}
				else if (i != 0 && HPdown7[i - 1] <= 0 && HPdown6[7] <= 0)
				{
					HPdown7[i]--;
				}

				//���߲��Ϸ�
				if (i == 0 && HPdown7[7] <= 0 && HPup6[7] <= 0)
				{
					HPup7[i]--;
				}
				else if (i != 0 && HPup7[i - 1] <= 0 && HPup6[7] <= 0)
				{
					HPup7[i]--;
				}
			}

			//����-4����������ж�����**************************************


			//����-4�������������ڣ���ʵ����С��ĵ�������
			if (Houta_4_IsPutdown == 0)

			{
				huixuan_x += vx;
				if (huixuan_x == monkey4_x + 70 || huixuan_x == monkey4_x - 90)
				{
					vx = -vx;
				}

				//����-4�Ĺ����ж�----------------------------------//
				//������һ������
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

				//�����ڶ�������

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
				//��������������

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

				//�������Ĳ�����

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

				//��������������

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

				//�������߲�����

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

				//����BOSS
				if ((monkey4_x - moya_x)*(monkey4_x - moya_x) + (monkey4_y - moya_y)*(monkey4_y - moya_y) < r4*r4)
				{
					HP8 = HP8 - 1;
				}


			}

			//���ߵ�����-----------------------------------------------------------//
			//���ߺ�ֻ�ܹ����Բ�����
			//������-5������֮����������
			if (Houta_5_IsPutdown == 0)
			{
				//ֻ�������岨�Բ�����**************

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


			//��������
			//����ͨ�����ƵĹ����ж�
			//������-7������֮����������
			if (Houta_7_IsPutdown == 0)

			{
				//������һ������**************
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

				//�����ڶ�������**************

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

				//��������������**************

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

				//�������Ĳ�����**************

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

				//��������������**************

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

				//�������߲�����**************

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

				//����BOSS
				if ((monkey7_x - moya_x)*(monkey7_x - moya_x) + (monkey7_y - moya_y)*(monkey7_y - moya_y) < r7*r7)
				{
					HP8 = HP8 - 1;
				}

			}

			//�����﹥��
			//�˺�����ͨ�������
			if (Houta_8_IsPutdown == 0)

			{
				//������һ������**************

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

				//�����ڶ�������**************

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

				//��������������**************

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

				//�������Ĳ�����**************

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

				//��������������**************

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

				//�������߲�����**************

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

				//����BOSS
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

//�������йصĲ���******************
void updateWithInput()
{
	if (GetAsyncKeyState(VK_RBUTTON) & 0x0001 && Houta_6_IsChose == 0)
	{
		while (!(GetAsyncKeyState(VK_RBUTTON) & 0x0001));
	}//��ͣ��Ϸ����

	MOUSEMSG m;	// ���������Ϣ
	while (MouseHit())  //����������ڼ�⵱ǰ�Ƿ��������Ϣ
	{
		m = GetMouseMsg();
		if (m.x >= 320 && m.x <= 450 && m.y >= 250 && m.y <= 360)	//�����ʼ
		{
			BeginChange = 0;
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				Begin = 0;		//��ʼ֮��
			}
		}
		else
		{
			BeginChange = 1;
		}
		if (Begin == 0)	//��ʼ֮����������
		{

			//����-1�ķ���***********************************************************

			//�����λ�õ��ڵ�һ������λ��

			if (m.x >= 800 && m.x <= 840 && m.y >= 100 && m.y <= 135 && money >= buildhouta1)

			{

				if (m.uMsg == WM_LBUTTONDOWN)	//�������
				{
					Houta_1_IsChose = 0;		//��ʾ������Ӱ
					Houta_1_IsPutdown = 1;
				}
			}
			if (Houta_1_IsChose == 0 && m.uMsg == WM_MOUSEMOVE)
			{
				// ��һ��������λ�õ���������ڵ�λ��

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


			//����-2�ķ���********************************************************

			//�����λ�õ��ڵڶ�������λ��



			if (m.x >= 855 && m.x <= 890 && m.y >= 100 && m.y <= 135 && money >= buildhouta2)



			{
				if (m.uMsg == WM_LBUTTONDOWN)	//�������
				{
					Houta_2_IsChose = 0;		//��ʾ������Ӱ
					Houta_2_IsPutdown = 1;
				}
			}

			if (Houta_2_IsChose == 0 && m.uMsg == WM_MOUSEMOVE)
			{
				// �ڶ���������λ�õ���������ڵ�λ��

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


			//����-3�ķ���***********************************************************

			//�����λ�õ��ڵ���������λ��



			if (m.x >= 800 && m.x <= 840 && m.y >= 150 && m.y <= 190 && money >= buildhouta3)

			{
				if (m.uMsg == WM_LBUTTONDOWN)	//�������
				{
					Houta_3_IsChose = 0;
					Houta_3_IsPutdown = 1;
				}
			}
			if (Houta_3_IsChose == 0 && m.uMsg == WM_MOUSEMOVE)
			{
				// ������������λ�õ���������ڵ�λ��



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

			//����-4�ķ���***********************************************************

			if (m.x >= 855 && m.x <= 890 && m.y >= 150 && m.y <= 190 && money >= buildhouta4)
			{
				if (m.uMsg == WM_LBUTTONDOWN)	//�������
				{
					Houta_4_IsChose = 0;
					Houta_4_IsPutdown = 1;
				}
			}
			if (Houta_4_IsChose == 0 && m.uMsg == WM_MOUSEMOVE)
			{
				// ���ĸ�������λ�õ���������ڵ�λ��
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

			//����-5�ķ���***********************************************************
			//�����λ�õ��ڵ��������λ��
			if (m.x >= 800 && m.x <= 840 && m.y >= 205 && m.y <= 245 && money >= buildhouta5)

			{
				if (m.uMsg == WM_LBUTTONDOWN)	//�������
				{
					Houta_5_IsChose = 0;
					Houta_5_IsPutdown = 1;
				}
			}
			if (Houta_5_IsChose == 0 && m.uMsg == WM_MOUSEMOVE)
			{
				// �����������λ�õ���������ڵ�λ��
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

			//����-6�ķ���***********************************************************
			//�����λ�õ��ڵ���������λ��
			if (m.x >= 855 && m.x <= 890 && m.y >= 205 && m.y <= 245 && money >= buildhouta6)

			{
				if (m.uMsg == WM_LBUTTONDOWN)	//�������
				{
					Houta_6_IsChose = 0;
					Houta_6_IsPutdown = 1;
				}
			}
			if (Houta_6_IsChose == 0 && m.uMsg == WM_MOUSEMOVE)
			{
				// ������������λ�õ���������ڵ�λ��
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

			//����-7�ķ���***********************************************************
			//�����λ�õ��ڵ��߸�����λ��

			if (m.x >= 800 && m.x <= 840 && m.y >= 240 && m.y <= 280 && money >= buildhouta7)

			{
				if (m.uMsg == WM_LBUTTONDOWN)	//�������
				{
					Houta_7_IsChose = 0;
					Houta_7_IsPutdown = 1;
				}
			}
			if (Houta_7_IsChose == 0 && m.uMsg == WM_MOUSEMOVE)
			{
				// ���߸�������λ�õ���������ڵ�λ��

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

			//����-8�ķ���***********************************************************

			//�����λ�õ��ڵڰ˸�����λ��

			if (m.x >= 855 && m.x <= 890 && m.y >= 240 && m.y <= 280 && money >= buildhouta8)

			{
				if (m.uMsg == WM_LBUTTONDOWN)	//�������
				{
					Houta_8_IsChose = 0;
					Houta_8_IsPutdown = 1;
				}
			}
			if (Houta_8_IsChose == 0 && m.uMsg == WM_MOUSEMOVE)
			{
				// �ڰ˸�������λ�õ���������ڵ�λ��



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

			//�����+�ż�Ǯ

			if (m.uMsg == WM_LBUTTONDOWN&&m.x >= 890 && m.x <= 914 && m.y >= 0 && m.y <= 20)//�������Ǯ

			{

				money = money + 1000;
			}
		}



		char input;
		if (_kbhit())  // �ж��Ƿ�������
		{

		}
	}
}

//��Ϸ����**********************
void gameover()
{
	EndBatchDraw();
	_getch();
	closegraph();
}

//������**********************
int main()
{
	startup();  // ���ݳ�ʼ��	
	while (1)  //  ��Ϸѭ��ִ��
	{
		show();  // ��ʾ����
		updateWithoutInput();  // ���û������޹صĸ���
		updateWithInput();     // ���û������йصĸ���
	}
	gameover();     // ��Ϸ��������������
	return 0;
}
