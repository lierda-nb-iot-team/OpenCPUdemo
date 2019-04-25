/******************************************************************************
 * @����	�û�������
 * @���	Lierda NB-IoT ��������Ŷ�@2018
******************************************************************************/
#include "app.h"


osThreadAttr_t App_task_attr = { "lierda_App_task"/*��������*/, 0, NULL, 0, NULL,
		(256) /*�����ջ��С*/, 11/*�������ȼ�*/, 0, 0 };//�������Խṹ��
uint32 * App_task_handle = NULL;

/******************************************************************************
* @������	app�����߳�
* @����	    param : �ղ�������Ч
* @����ֵ  ��
******************************************************************************/
void lierda_App_task(void *param)
{
	UNUSED(param);
	osDelay(500);//�ȴ�ģ���ʼ�����
	lierdaLog("ADC��ѹ�ɼ�");
	AdcSampInit();//ADC������ʼ��
	for (;;)
	{
		AdcSampTest();//ADC��ѹ����
		osDelay(5000);//5s����һ��
	}
}

/******************************************************************************
* @������ �����û��߳�
* @����	param : �ղ���
* @����ֵ  ��
******************************************************************************/
void lierda_App_main(void)
{
	App_task_handle = osThreadNew(lierda_App_task, NULL, &App_task_attr); //������������
	if (App_task_handle == NULL)
	{
		lierdaLog("	lierda_App_task���񴴽�ʧ��");
	}
}