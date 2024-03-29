#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>


#define mx 16  // 미로의 맵의 크기를 결정 
#define my 16  // 미로의 맵의 크기를 결정
#define wall '@'//미로의 벽 
#define way ' '	// 미로의 길 
#define find '.'


typedef struct link{
 
struct link *next;
struct link *prev;

char check;
int miro_x;
int miro_y;

}link;
//-----------------------------------------------------------------//-----------------------------------

link* Calc_Proper_Angle_make();							// 원형 연결 링크드 리스트를 만든다.

link* Ctrl_Steering_Angle_Correction_add(link *tail,int num);	// tail을 주소값을 넘겨받아서 num의 수만큼 링크를 생성한다.

link* Ctrl_Steering_Angle_completion_fQ(link *tail,int num);	// num 의 수만큼의 주소를 반환한다.Q

link* Ctrl_Proportional_value_f(link *head,int num); // num 의 수만큼의 주소를 반환한다.스택.

link* Recog_Assistance_Zone_Short(link* head);         // 가장 단거리를 찾는다.

void Recog_Assistance_Zone_remove(link *head); // head와 tail을 제외한 리스트를 모두 지운다.



//----------------------------------------------------------------// 옴길것.


void Ctrl_Wsd_Mounted_Cam_out(char (*map)[mx]); // 맵을 출력한다.

void Ctrl_Wsd_Mounted_Cam(char (*map)[mx],link *tail);// 시작 시점을 찾는다.

void Ctrl_Proportional_value(link *tail, char (*move)[mx],int x, int y);// 언제든 원하는 위치에서 길을 찾을수 있도록 4가지 인수를 입력받음

int Ctrl_Steering_Power_A(char (*check)[mx],link *addr_check,int cx,int cy); //함수안의 함수로 쓰인다.

void Ctrl_Steering_Power_B(char (*a)[mx],char (*b)[mx]);// 2차원 배열을 복사해준다.

void Ctrl_Steering_Angle_completion(link *tail,char (*moving)[mx]);//완성된 길 (최단거리를 찾아서 다시 맵에 뿌려준다.)

link* Calc_Proper_Angle(link *tail);// 길을 역으로 다시 찾아 더욱 짧은길을 찾는다.
