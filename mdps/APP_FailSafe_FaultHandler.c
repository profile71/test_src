#include "App_Commons.h"

void Ctrl_Steering_Power_B(char (*a)[mx],char (*b)[mx])
{
	int x,y;

	for(y=0; y<my; y++)
	{
		for(x=0; x<my; x++)
		{
			*(*(b+y)+x)=*(*(a+y)+x);
		}
	}



}

//----------------------------------------------------------------------------------------------//

void Ctrl_Steering_Angle_completion(link *tail,char (*moving)[mx])
{
	link *node;

	for(node=tail->prev; node->prev!=0; node=node->prev)
	{
		*(*(moving+node->miro_y)+node->miro_x)=find;
		Ctrl_Wsd_Mounted_Cam_out(moving);
	}


}


void Calc_Proper_Angle_makeS(link *tail,char (*moving)[mx])
{
	link *node;

	for(node=tail->prev; node->prev!=0; node=node->prev)
	{
		*(*(moving+node->miro_y)+node->miro_x)=find;

	}


}
//---------------------------------------------------------------------------------------------------
link* Calc_Proper_Angle(link *tail)// ã������ ���� ���� �����ֵ��� �Ѵ�.
{
	char re_map[my][mx]={0};
	
	char (*move)[mx]=re_map;
	int x, y;
	link *node;
	link *save = tail;
	
	for(y =0; y<my; y++)
	{
		for(x =0; x<mx; x++)
		{
			re_map[y][x]=wall;
		}	
	}
	
	
	
	node=tail->prev;
	if(node->check==0)
	{
		printf("------------------ ���̻� ª����11111�� �����ϴ�.----------------------\n");
		return tail;	
	}
	
	*(*(move+node->miro_y)+node->miro_x)='e';
	
	// ���ٷ� ������ ���� �ش�.	(��ŸƮ�� e ��)
	
	for(node=node->prev; node->prev!=0; node= node->prev)
	{
		*(*(move+node->miro_y)+node->miro_x)=way;
	}
	node=node->next;
	*(*(move+node->miro_y)+node->miro_x)='s';
	node=node->prev;// ���ٷ� ������ ���� �ش�.	(��ŸƮ�� e ��)
	
	Ctrl_Wsd_Mounted_Cam_out(re_map);
	getchar();
	
	Recog_Assistance_Zone_remove(save);

	save=Calc_Proper_Angle_make();

	save=Ctrl_Steering_Angle_Correction_add(save,(mx*my)/2); // ���� x*Y��ŭ�� ���� ���� ����Ʈ�� �����.
	
	Ctrl_Wsd_Mounted_Cam(re_map,save);// ���� ��ǥ�� ã�´�. �Ŀ� ���ϴ� ��ġ���� ���� ã������ s�� �־��ָ� �ű⼭���� ���۵ȴ�.
	
	printf("\n����� : x = %d  y = %d  Enter�� ������ ��ã2123��2�� ��2222�� �մϴ�...\n ",save->prev->miro_x,save->prev->miro_y,save->prev->check);

	getchar();  //-test
	
	Ctrl_Proportional_value(save,move,save->prev->miro_x,save->prev->miro_y);//���� ���� ����� ��ũ����Ʈ�� ���� ������ �ش�.

	save=Recog_Assistance_Zone_Short(save); //  �ִ� �Ÿ��� ���Ѵ�.

	Ctrl_Wsd_Mounted_Cam_out(re_map);

	tail=save;
	
	return tail;
	
	
}