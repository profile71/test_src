#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


#define mx 16  // �̷��� ���� ũ�⸦ ���� 
#define my 16  // �̷��� ���� ũ�⸦ ����
#define wall '@'//�̷��� �� 
#define way ' '	// �̷��� �� 
#define find '.'


typedef struct link{
 
struct link *next;
struct link *prev;

char check;
int miro_x;
int miro_y;

}link;
//-----------------------------------------------------------------//-----------------------------------

link* Calc_Proper_Angle_make();							// ���� ���� ��ũ�� ����Ʈ�� �����.

link* Ctrl_Steering_Angle_Correction_add(link *tail,int num);	// tail�� �ּҰ��� �Ѱܹ޾Ƽ� num�� ����ŭ ��ũ�� �����Ѵ�.

link* Ctrl_Steering_Angle_completion_fQ(link *tail,int num);	// num �� ����ŭ�� �ּҸ� ��ȯ�Ѵ�.Q

link* Ctrl_Proportional_value_f(link *head,int num); // num �� ����ŭ�� �ּҸ� ��ȯ�Ѵ�.����.

link* Recog_Assistance_Zone_Short(link* head);         // ���� �ܰŸ��� ã�´�.

void Recog_Assistance_Zone_remove(link *head); // head�� tail�� ������ ����Ʈ�� ��� �����.



//----------------------------------------------------------------// �ȱ��.


void Ctrl_Wsd_Mounted_Cam_out(char (*map)[mx]); // ���� ����Ѵ�.

void Ctrl_Wsd_Mounted_Cam(char (*map)[mx],link *tail);// ���� ������ ã�´�.

void Ctrl_Proportional_value(link *tail, char (*move)[mx],int x, int y);// ������ ���ϴ� ��ġ���� ���� ã���� �ֵ��� 4���� �μ��� �Է¹���

int Ctrl_Steering_Power_A(char (*check)[mx],link *addr_check,int cx,int cy); //�Լ����� �Լ��� ���δ�.

void Ctrl_Steering_Power_B(char (*a)[mx],char (*b)[mx]);// 2���� �迭�� �������ش�.

void Ctrl_Steering_Angle_completion(link *tail,char (*moving)[mx]);//�ϼ��� �� (�ִܰŸ��� ã�Ƽ� �ٽ� �ʿ� �ѷ��ش�.)

link* Calc_Proper_Angle(link *tail);// ���� ������ �ٽ� ã�� ���� ª������ ã�´�.
