#include "App_Commons.h"
		

int main()  
{

	char miro_map[my][mx]={				// �̷��� ���� �����.
		{wall,way,wall,'s',wall,wall,wall,wall,wall,wall,way,wall,wall,wall,wall,wall},
		{wall,way,wall,way,way,way,way,way,wall,wall,wall,way,way,wall,wall,wall},
		{wall,way,way,way,wall,wall,way,wall,way,wall,way,wall,way,way,way,way},
		{wall,wall,way,wall,way,way,wall,way,wall,way,wall,wall,way,way,wall,wall},
		{wall,way,way,way,wall,wall,way,way,wall,way,wall,way,wall,way,wall,wall},
		{wall,wall,wall,way,way,wall,way,way,wall,way,wall,way,wall,wall,way,wall},
		{wall,wall,wall,way,wall,wall,way,wall,way,wall,way,way,way,wall,wall,wall},
		{way,wall,way,wall,wall,way,wall,way,way,wall,wall,way,wall,way,wall,wall},
		{wall,wall,wall,wall,wall,wall,way,wall,way,wall,way,way,wall,way,wall,wall},
		{way,wall,way,wall,wall,wall,way,wall,wall,wall,wall,way,wall,way,way,wall},
		{wall,wall,way,wall,wall,way,wall,wall,wall,wall,wall,way,way,wall,way,wall},
		{wall,wall,way,way,way,wall,wall,wall,wall,wall,wall,wall,way,wall,wall,way},
		{wall,way,wall,wall,wall,way,wall,wall,wall,way,wall,way,way,way,wall,way},
		{way,wall,wall,wall,wall,wall,way,wall,wall,way,way,way,way,way,'e',way},
		{way,wall,wall,wall,wall,wall,wall,wall,way,way,wall,wall,wall,way,wall,way},

	};




char miro_map2[my][mx];//  ���� ������ ���´�.
int count = (mx*my);

char (*move)[mx]=miro_map;  // ���� ù �ּ� ���� move �����Ϳ� �ٰ� �����Ѵ�.
link *addr;
//-------------------------------------------------���������� �� -----------------------------------------------//


Ctrl_Steering_Power_B(miro_map,miro_map2);// 2���� �迭�� �������ش�.
	
addr=Calc_Proper_Angle_make();

addr=Ctrl_Steering_Angle_Correction_add(addr,count); // ���� x*Y��ŭ�� ���� ���� ����Ʈ�� �����.

Ctrl_Wsd_Mounted_Cam_out(miro_map); // �̷��� ���� ����Ѵ�.

Ctrl_Wsd_Mounted_Cam(miro_map,addr);// ���� ��ǥ�� ã�´�.

printf("\n�����: x = %d  y = %d  Enter�� ������ ��ã�⸦ �����մϴ�...\n",addr->prev->miro_x,addr->prev->miro_y);

getchar();  //-test

Ctrl_Proportional_value(addr,move,addr->prev->miro_x,addr->prev->miro_y);//���� ���� ����� ��ũ����Ʈ�� ���� ������ �ش�.

addr=Recog_Assistance_Zone_Short(addr); //  �ִ� �Ÿ��� ���Ѵ�.


//--------------------------------------------------ù��° ��ã���� �� --------------------------------//



//-----------------------------------------------������ ��ã�� ����-------------------------------------//
getchar();

system("cls");

Ctrl_Steering_Power_B(miro_map2,miro_map);//���� �ʱ�ȭ

Ctrl_Wsd_Mounted_Cam_out(miro_map); // �̷��� ���� ����Ѵ�.(���� �ʱ���·� �����Ѱ��� Ȯ��);

Ctrl_Steering_Angle_completion(addr,move);//�ϼ���Ų �̷��� ���� ����Ȱ���, ������ ���� �Ѱ��ָ� ���� ª���� ���� ����ش�.

Ctrl_Wsd_Mounted_Cam_out(miro_map); // �̷��� ���� ����Ѵ�.

getchar();

addr=Calc_Proper_Angle(addr);// ã�� ���� ���� �ٿ��ش�.  ù��°--

Ctrl_Steering_Power_B(miro_map2,miro_map);//�̷��� ���� �ʱ�ȭ

Ctrl_Wsd_Mounted_Cam_out(miro_map); //(���� �ʱ���·� �����Ѱ��� Ȯ��);

getchar(); // ù��°�� ��

addr=Calc_Proper_Angle(addr);// ã�� ���� ���� �ٿ��ش�.  �ι���--

//--------------------------------------------------------�ι�° ��ã���� �� --------------------------//



//----------------------------------------������ ã������ ����..--------------------------------------//

Ctrl_Steering_Power_B(miro_map2,miro_map);// 2���� �迭�� �������ش�.

Ctrl_Wsd_Mounted_Cam_out(miro_map); // �̷��� ���� ����Ѵ�.

Ctrl_Steering_Angle_completion(addr,move);//���� �ϼ��� ���� ����ش�.

Ctrl_Wsd_Mounted_Cam_out(miro_map); //���� ���� �����ش�

printf("---------------��ã�⸦ �Ϸ��Ͽ����ϴ�------------------\n");

getchar();
return 0;

}

//---------------------------------------------------------------
































/*  ��������� ���� ..// ���̺귯�� ������ ���ؼ� �����غ���.
{

//-------------------------------------------------------------------------------------
	link *addr;
	link *addr1;
	int number =10;
	int i;

	addr=Calc_Proper_Angle_make(); // tail�� ������ �ּҸ� �Ҵ�



	addr=Ctrl_Steering_Angle_Correction_add(addr,number); //tail�� �ּҸ� �Ѱ��ָ� �� ����ŭ �����ȴ�.

//-----------------------------------------------------------------------------------

	for(i=1; i<=number; i++)	// ��ũ�� �������� 1���� 10 ���� �־��.
	{
		addr1=Ctrl_Steering_Angle_completion_fQ(addr,i);
		
		addr1->miro_x=i;
		addr1->miro_y=i;
	}

//-----------------------------------------------------------------------------------

	addr1=Ctrl_Steering_Angle_completion_fQ(addr,6);
	addr1->miro_x=2;
	addr1->miro_y=2;

//------------------------------------------------------------------------------------

	for(i=1; i<=number; i++)	// ��ũ�� ť��  1���� 10 ���� ����Ѵ�.
	{
	
		
		addr1=Ctrl_Steering_Angle_completion_fQ(addr,i);

		printf("x ���: %d \n",addr1->miro_x);
			
	}

	getchar();
//------------------------------------------------------------------------------------



	addr=Recog_Assistance_Zone_Short(addr); //  �ִ� �Ÿ��� ���Ѵ�.


//------------------------------------------------------------------------------------



	for(i=1; i<=number; i++)	// ��ũ����Ʈ�� �������� ����Ѵ�.
	{
		addr1=Ctrl_Proportional_value_f(addr,i);
		
		printf("��ȯ�� �� = %d    ",addr1->miro_x);
		printf("��ȯ�� �� = %d\n",addr1->miro_y);
	}

//---------------------------------------------------------------------------------------------------
*/