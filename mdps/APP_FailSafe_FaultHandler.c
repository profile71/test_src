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
link* Calc_Proper_Angle(link *tail)// 찾은길을 더욱 단축 시켜주도록 한다.
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
		printf("------------------ 더이상 짧은길11111이 없습니다.----------------------\n");
		return tail;	
	}
	
	*(*(move+node->miro_y)+node->miro_x)='e';
	
	// 꺼꾸로 마지막 값을 준다.	(스타트에 e 값)
	
	for(node=node->prev; node->prev!=0; node= node->prev)
	{
		*(*(move+node->miro_y)+node->miro_x)=way;
	}
	node=node->next;
	*(*(move+node->miro_y)+node->miro_x)='s';
	node=node->prev;// 꺼꾸로 마지막 값을 준다.	(스타트에 e 값)
	
	Ctrl_Wsd_Mounted_Cam_out(re_map);
	getchar();
	
	Recog_Assistance_Zone_remove(save);

	save=Calc_Proper_Angle_make();

	save=Ctrl_Steering_Angle_Correction_add(save,(mx*my)/2); // 맵의 x*Y만큼의 원형 연결 리스트를 만든다.
	
	Ctrl_Wsd_Mounted_Cam(re_map,save);// 시작 좌표을 찾는다. 후에 원하는 위치에서 길을 찾을려면 s만 넣어주면 거기서부터 시작된다.
	
	printf("\n출발점 : x = %d  y = %d  Enter을 누르면 길찾2123기2를 시2222작 합니다...\n ",save->prev->miro_x,save->prev->miro_y,save->prev->check);

	getchar();  //-test
	
	Ctrl_Proportional_value(save,move,save->prev->miro_x,save->prev->miro_y);//시작 값과 저장될 링크리스트만 값을 보내어 준다.

	save=Recog_Assistance_Zone_Short(save); //  최단 거리를 구한다.

	Ctrl_Wsd_Mounted_Cam_out(re_map);

	tail=save;
	
	return tail;
	
	
}